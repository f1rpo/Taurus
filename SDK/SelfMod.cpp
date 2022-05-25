// trs.smc: New implementation file; see comment in header.
#include "CvGameCoreDLL.h"
#include "SelfMod.h"
#include "CvDLLInterfaceIFaceBase.h"
#include "CvBugOptions.h"
#include "ModName.h"

Civ4BeyondSwordPatches smc::BtS_EXE;

typedef int RetIntHook(); // trs.modname

namespace
{
/*	This class seems like an elegant way of ensuring that virtual memory protections
	are restored at the end */
class SelfMod : boost::noncopyable
{
public:
	virtual ~SelfMod() { restorePageProtections(); }
	// Return false on unexpected failure
	bool applyIfEnabled()
	{
		if (!GC.getDefineBOOL("DISABLE_EXE_RUNTIME_MODS"))
			return apply();
		return true;
	}
	/*	Derived classes can override this to be exempt from the
		DISABLE_EXE_RUNTIME_MODS check */
	virtual bool isOptionalThroughXML() const { return true; }

protected:
	virtual bool apply()=0; // See applyIfEnabled about the return value
	bool unprotectPage(LPVOID pAddress, SIZE_T uiSize,
		DWORD ulNewProtect = PAGE_EXECUTE_READWRITE)
	{
		/*	Getting a segmentation fault when writing to the text segment under
			Win 8.1. Probably the same on all Windows versions that anyone still uses.
			Need to unprotect the virtual memory page first. Let's hope that this
			long outdated version of VirtualProtect from WinBase.h (nowadays located
			in Memoryapi.h) will still do the trick on recent Win versions. */
		DWORD uiOldProtect; // I get PAGE_EXECUTE_READ here
		if (VirtualProtect(pAddress,
			/*	Will affect an entire page, not just the few bytes we need. Through
				SYSTEM_INFO sysInfo; GetSystemInfo(&sysInfo); sysInfo.dwPageSize;
				I see a page size of 4 KB. */
			uiSize, ulNewProtect, &uiOldProtect) == 0)
		{
			FErrorMsg("Failed to unprotect memory for runtime patch");
			return false;
		}
		/*	A check at VirusTotal.com makes me hopeful that merely calling
			VirtualProtect in some capacity won't make our DLL suspicious to
			static virus scans. To make issues with analyses of runtime memory
			less likely - and to restore protections against accidental memory
			accesses by other parts of the DLL - let's remember what protections
			we've changed and revert them asap. */
		m_aPageProtections.push_back(PageProtection(pAddress, uiSize, uiOldProtect));
		return true;
	}
	/*	This should return 0 when dealing with the exact same build of the EXE
		that has been reverse-engineered to write this class. I don't think a
		compatibility layer should make a difference. Large address awareness
		has been tested both ways. It's unclear whether different builds exist
		apart from the incompatible Steam version. Localized editions perhaps. 
		So this hasn't really been tested; it's a better-than-nothing effort to
		align a starting address at which a certain sequence of code bytes is
		expected with the address, if any, at which the sequence is actually found.
		Returns the difference between expected and actual address as a byte offset
		or MIN_INT if no such offset has been found. */
	int findAddressOffset(
		// Sequence that we search for and address at which we expect it to start
		byte* pNeedleBytes, int iNeedleBytes, uint uiExpectedStart,
		/*	Shorter sequence to check for upfront, to save time.
			If found at uiQuckTestStart, then an offset of 0 is returned
			w/o checking pNeeldeBytes. */
		byte* pQuickTestBytes = NULL, int iQuickTestBytes = 0, uint uiQuickTestStart = 0,
		/*	How big an offset we contemplate. Not going to search the
			entire virtual memory*/
		int iMaxAbsOffset = 256 * 1024) const
	{
		if (pQuickTestBytes != NULL &&
			testCodeLayout(pQuickTestBytes, iQuickTestBytes, uiQuickTestStart))
		{
			return 0;
		}
		/*	Would be safer to be aware of the few different builds that (may) exist
			and to hardcode offsets for them. So this is a problem worth reporting,
			even if we can recover. */
		FErrorMsg("Trying to compensate through address offset");
		int iAddressOffset = 0;
		// Reading such low addresses doesn't seem to be safe
		int const iLowAddressBound = 0x00403500;
		// Tbd.: Find a similar bound for high addresses
		if (((int)uiExpectedStart) >= iLowAddressBound &&
			((int)uiExpectedStart) <= MAX_INT - iMaxAbsOffset)
		{
			int const iMaxSubtrahend = std::min(iMaxAbsOffset, static_cast<int>(
					uiExpectedStart - iLowAddressBound));
			int const iMaxAddend = iMaxAbsOffset;
			int const iHaystackBytes = iMaxSubtrahend + iMaxAddend;
			byte* pHaystackBytes = new byte[iHaystackBytes];
			for (int iOffset = -iMaxSubtrahend; iOffset < iMaxAddend; iOffset++)
			{
				pHaystackBytes[iOffset + iMaxSubtrahend] =
						reinterpret_cast<byte*>(uiExpectedStart)[iOffset];
			}
			// No std::begin, std::end until C++11
			byte* const pHaystackEnd = pHaystackBytes + iHaystackBytes;
			byte* pos = std::search(
					pHaystackBytes, pHaystackEnd,
					pNeedleBytes, pNeedleBytes + iNeedleBytes);
			if (pos == pHaystackEnd)
			{
				FErrorMsg("Failed to locate expected code bytes in EXE");
				return MIN_INT;
			}
			iAddressOffset = ((int)std::distance(pHaystackBytes, pos))
					- iMaxSubtrahend;
		}
		else
		{
			FErrorMsg("uiExpectedStart doesn't look like a code address");
			return MIN_INT;
		}
		// Run our initial test again to be on the safe side
		if (pQuickTestBytes != NULL &&
			!testCodeLayout(pQuickTestBytes, iQuickTestBytes,
			uiQuickTestStart + iAddressOffset))
		{
			FErrorMsg("Address offset discarded; likely incorrect.");
			return MIN_INT;
		}
		return iAddressOffset;
	}
	bool testCodeLayout(byte* pBytes, int iBytes, uint uiStart) const
	{
		for (int i = 0; i < iBytes; i++)
		{
			if (pBytes[i] != reinterpret_cast<byte*>(uiStart)[i])
			{
				FErrorMsg("Unexpected memory layout of EXE");
				return false;
			}
		}
		return true;
	}

private:
	struct PageProtection
	{
		PageProtection(LPVOID pAddress, SIZE_T uiSize, DWORD uiProtect)
			:	m_pAddress(pAddress), m_uiSize(uiSize), m_uiProtect(uiProtect) {}
		LPVOID m_pAddress;
		SIZE_T m_uiSize;
		DWORD m_uiProtect;
	};
	std::vector<PageProtection> m_aPageProtections;
	void restorePageProtections()
	{
		for (size_t i = 0; i < m_aPageProtections.size(); i++)
		{
			DWORD uiDummy;
		#ifdef FASSERT_ENABLE
			int iSuccess =
		#endif
			 VirtualProtect(m_aPageProtections[i].m_pAddress, m_aPageProtections[i].m_uiSize,
					m_aPageProtections[i].m_uiProtect, &uiDummy);
			FAssertMsg(iSuccess != 0, "Failed to restore memory protection");
		}
	}
};

// trs.balloon:
class PlotIndicatorSizeMod : public SelfMod
{
public:
	PlotIndicatorSizeMod(int iScreenHeight) : m_iScreenHeight(iScreenHeight) {}
protected:
	bool apply() // override
	{
		// Cache for performance (though probably not a concern)
		static PlotIndicatorSize ffMostRecentBaseSize;

		/*	Size values for plot indicators shown onscreen and offscreen that are
			hardcoded in the EXE. These go through a bunch of calculations,
			only part of which I've located in the debugger. Essentially,
			there appears to be an adjustment proportional to the screen height. */
		PlotIndicatorSize ffBaseSize(42, 68);
		bool bAdjustToFoV = true;
		bool bAdjustToRes = false;
		{
			int iUserChoice = getBugOptionINT("Taurus__PlotIndicatorSize");
			switch (iUserChoice)
			{
				/* "Automatic" behavior: Subtract a little b/c the BtS size
					is a bit too big overall, i.e. even on the lowest resolution. */
			case 0: ffBaseSize.onScreen -= 2; break;
			case 1: std::swap(bAdjustToFoV, bAdjustToRes); break; // BtS behavior
			/*	Note that this formula ignores how the choices are labeled.
				That menu text needs to be kept consistent with our code here. */
			default: ffBaseSize.onScreen = 15 + 5 * static_cast<float>(iUserChoice);
			}
		}
		/*	The EXE will adjust to height. Rather than try to change that in the EXE,
			we'll proactively cancel out the adjustment. */
		if (!bAdjustToRes)
		{
			/*	Current screen height relative to the height that the UI was
				most optimized for */
			float fHeightRatio = m_iScreenHeight / 768.f;
			ffBaseSize.onScreen = ffBaseSize.onScreen / fHeightRatio;
					/*	Could use this divisor to not cancel it out entirely -
						but the adjustment really just seems to be a bad idea. */
					// std::pow(fHeightRatio, 0.85f)
		}
		/*	FoV correlates with screen size, (typical) camera distance and
			the player's distance from the screen. And BtS seems to make a small
			adjustment based on FoV and camera distance too (probably
			not explicitly). So it's hard to reason about this adjustment.
			In my tests, it has had the desired result of making the diameters
			about one quarter of a plot's side length. */
		if (bAdjustToFoV)
		{
			float fTypicalFoV = 42;
			ffBaseSize.onScreen *= std::min(2.f, std::max(0.5f,
					std::sqrt(fTypicalFoV / GC.getFIELD_OF_VIEW())));
		}
		/*	(I'm not going to dirty the globe layer in response to a FoV change - that
			would probably cause stuttering while the player adjusts the FoV slider.) */
		{
			int iUserChoice = getBugOptionINT("Taurus__OffScreenUnitSizeMult");
			if (iUserChoice == 7)
			{	// Meaning "disable". 0 size seems to accomplish that.
				ffBaseSize.offScreen = 0;
			}
			else ffBaseSize.offScreen = ffBaseSize.onScreen * (0.8f + 0.2f * iUserChoice);
		}

		if (ffBaseSize.equals(ffMostRecentBaseSize))
			return true;
		ffMostRecentBaseSize = ffBaseSize;

		/*	The onscreen size is hardcoded as an immediate operand (in FP32 format)
			in three places and the offscreen size in one place.
			|Code addr.| Disassembly						| Code bytes
			------------------------------------------------------------------------------
			 00464A08	push 42280000h						 68 00 00 28 42
			 004B76F4		(same as above)
			 00496DEB	mov dword ptr [esi+17Ch],42280000h	 C7 86 7C 01 00 00 00 00 28 42
			 0049905F	push 42880000h						 68 00 00 88 42
			------------------------------------------------------------------------------
			One can get the debugger close to the first location by setting a breakpoint
			at the end of CvPlayer::getGlobeLayerColors. The second is triggered by
			interface messages that show a plot indicator; a breakpoint in
			CvTalkingHeadMessage::getOnScreenArrows should help. The third one seems
			to be reached in all cases, look for a call to 00496DB0.
			The fourth one is triggered by selecting any unit. */
		uint aCodeAdresses[] = {
			0x00464A08, 0x004B76F4, 0x00496DEB, 0x0049905F
		};
		// The data we need to change is not right at the start
		uint aOperandOffsets[ARRAYSIZE(aCodeAdresses)] = {
					1,			1,			6,			1
		};

		/*	Before applying our patch, let's confirm that the code is layed out
			in memory as we expect it to be. */
		/*	This is the call to CvPlayer::getGlobeLayerColors,
			for a quick test upfront.
			 004649A9	call dword ptr ds:[0BC1E64h] */
		byte aQuickTestBytes[] = { 0xFF, 0x15, 0x64, 0x1E, 0xBC, 0x00 };
		/*	Longer sequence to search for if we have to find an address offset.
			The first 27 instructions at the start of the function that calls
			CvPlayer::getGlobeLayerColors. This is a fairly long sequence w/o any
			absolute addresses in operands. After this sequence, there are a bunch
			of DLL calls, the last one being CvPlayer::getGlobeLayerColors. */
		byte aNeedleBytes[] = {
			0x6A, 0xFF, 0x68, 0x15, 0xB9, 0xA3, 0x00, 0x64, 0xA1, 0x00, 0x00, 0x00,
			0x00, 0x50, 0x64, 0x89, 0x25, 0x00, 0x00, 0x00, 0x00, 0x83, 0xEC, 0x68,
			0x53, 0x55, 0x56, 0x57, 0x33, 0xFF, 0x89, 0x7C, 0x24, 0x54, 0x89, 0x7C,
			0x24, 0x58, 0x89, 0x7C, 0x24, 0x5C, 0x89, 0xBC, 0x24, 0x80, 0x00, 0x00,
			0x00, 0x89, 0x7C, 0x24, 0x44, 0x89, 0x7C, 0x24, 0x48, 0x89, 0x7C, 0x24,
			0x4C, 0x8D, 0x54, 0x24, 0x40, 0x52, 0xC6, 0x84, 0x24, 0x84, 0x00, 0x00,
			0x00, 0x01, 0x8B, 0x41, 0x04, 0x8D, 0x54, 0x24, 0x54, 0x52, 0x50, 0x8B,
			0x41, 0x08, 0x50 
		};
		int iAddressOffset = findAddressOffset(
				aNeedleBytes, ARRAYSIZE(aNeedleBytes), 0x00464930,
				aQuickTestBytes, ARRAYSIZE(aQuickTestBytes), 0x004649A9);
		if (iAddressOffset == MIN_INT)
			return false;

		// Finally apply the actual patch
		for (int i = 0; i < ARRAYSIZE(aCodeAdresses); i++)
		{
			float fSize = (i >= 3 ? ffBaseSize.offScreen : ffBaseSize.onScreen);
			uint uiCodeAddress = aCodeAdresses[i] + aOperandOffsets[i];
			FAssert(((int)uiCodeAddress) > -iAddressOffset);
			uiCodeAddress += iAddressOffset;
			if (!unprotectPage(reinterpret_cast<LPVOID>(uiCodeAddress), sizeof(float)))
				return false;
			*reinterpret_cast<float*>(uiCodeAddress) = fSize;
		}
		return true;
	}
	
private:
	int const m_iScreenHeight;
	struct PlotIndicatorSize
	{
		PlotIndicatorSize(float fOnScreen = 0, float fOffScreen = 0)
		:	onScreen(fOnScreen), offScreen(fOffScreen) {}
		// Overriding operator== for this nested thing would be a PITA
		bool equals(PlotIndicatorSizeMod::PlotIndicatorSize const& kOther)
		{	// Exact floating point comparison
			return (onScreen == kOther.onScreen &&
					offScreen == kOther.offScreen);
		}
		float onScreen, offScreen;
	};
};

// trs.modname:
class ModNameCheckHookPatch : public SelfMod
{
public:
	ModNameCheckHookPatch(RetIntHook* pHook) : m_pHook(pHook) {}
protected:
	bool apply() // override
	{
		/*	Verify that the EXE looks as expected (see comments below about
			the meaning of these instructions). The jumps all use relative
			operands, so I don't think it's unrealistic to expect them to
			be the same in a slightly different build of the EXE. */
		byte aExpectedCodeBytes[] = {
			0x8D, 0x7C, 0x24, 0x14,
			0xE8, 0x46, 0x90, 0xF6, 0xFF,
			0x84, 0xC0,
			0x8B, 0x5C, 0x24, 0x20
		};
		byte aMoreExpectedCodeBytes[] = {
			 0xE8, 0x8A, 0xA7, 0xFF, 0xFF,
			 0x8B, 0x80, 0xCC, 0x00, 0x00, 0x00,
			 0x83, 0x78, 0xFC, 0x00,
			 0x74, 0x1A,
			 0x85, 0xC0,
			 0x74, 0x16
		};
		int iAddressOffset = findAddressOffset(
				aMoreExpectedCodeBytes, ARRAYSIZE(aMoreExpectedCodeBytes),
				0x004175C1,
				aExpectedCodeBytes, ARRAYSIZE(aExpectedCodeBytes),
				0x004AE571);
		if (iAddressOffset == MIN_INT)
			return false;
		uint uiStartAddress = static_cast<uint>(0x004175CC + iAddressOffset);
		/*	The function in the EXE that performs the SAVE_VERSION check
			(can get a debugger breakpoint through CvGlobals::getDefineINTExternal)
			is also (via a subroutine) responsible for the mod name check:
			|Code addr.| Disassembly						| Code bytes
			------------------------------------------------------------------------------
			 004AE571	lea edi,[esp+14h]					 8D 7C 24 14
			 004AE575	call 004175C0  						 E8 46 90 F6 FF
			 004AE57A	test al,al							 84 C0
			 004AE57C	mov ebx,dword ptr [esp+20h]			 8B 5C 24 20
			 004AE580	je 004AE6D7							 0F 84 51 01 00 00
			------------------------------------------------------------------------------
			The first instruction puts a pointer to the saved mod name in EDI,
			and the subroutine called by the second instruction performs the check.
			I don't know what is being stored in EBX; the other two instructions
			branch on the result of the subroutine. The subroutine, let's name it
			checkName, is more complex than just a string comparison; I don't know
			what all it does. Doesn't seem prudent, on this basis, to replace it
			entirely. Let's instead find a nice place for our hook within checkName:
			 (This approach necessitates another small code manipulation to actually
			 accept or reject a savegame; that's handled by SelfMod::patchModNameCheck.)
			------------------------------------------------------------------------------
			 004175C0	push ecx							 51
			 004175C1	call 00411D50						 E8 8A A7 FF FF
			 004175C6	mov eax,dword ptr [eax+0CCh]		 8B 80 CC 00 00 00
			 004175CC	cmp dword ptr [eax-4],0				 83 78 FC 00
			 004175D0	je 004175EC							 74 1A
			 004175D2	test eax,eax						 85 C0
			 004175D4	je 004175EC							 74 16
			------------------------------------------------------------------------------
			I think the first instruction just preserves a register; n/m that.
			The call obtains a struct, probably CvUtility, that holds our mod name
			(as opposed to the saved mod name) in an FString. That string is then
			tested for having size 0 and for being NULL (in the wrong order it seems?).
			So these tests are unnecessary - the mod name has size 0 only when
			no mod is loaded. Our ModName::setExtModName may also set the name
			to size 0, but that should never be the case when a savegame is being
			loaded. Plenty of room for our hook. I'll only replace the CMP/ JE. */
		//						CALL-rel32	signed displacement			NOP
		byte aCodeBytes[] = {	0xE8,		0x00, 0x00, 0x00, 0x00,		0x90 };
		uint const uiCodeBytes = ARRAYSIZE(aCodeBytes);
		uint uiCallInstrBytes = uiCodeBytes - 1;
		// Instruction pointer is already at the NOP
		uint uiEIP = uiStartAddress + uiCallInstrBytes;
		int iDisplacement = static_cast<int>(reinterpret_cast<uint>(m_pHook));
		iDisplacement -= static_cast<int>(uiEIP);
		*reinterpret_cast<int*>(&aCodeBytes[1]) = iDisplacement;
		if (!unprotectPage(reinterpret_cast<LPVOID>(uiStartAddress), uiCodeBytes))
			return false;
		for (uint i = 0; i < uiCodeBytes; i++)
			reinterpret_cast<byte*>(uiStartAddress)[i] = aCodeBytes[i];
		return true;
	}
private:
	RetIntHook* m_pHook;
};

// trs.modname:
class ModNameCheckBypassPatch : public SelfMod
{
public:
	ModNameCheckBypassPatch(bool bRestore) : m_bRestore(bRestore) {}
protected:
	bool apply() // override
	{
		/*	Here we only deal with a single branch instruction,
			see ModNameCheckHookPatch::apply for context.
			 004AE580	je 004AE6D7				0F 84 51 01 00 00
			We wouldn't be here if ModNameCheckHookPatch hadn't already succeeded,
			so there's no need for verifying that the EXE indeed looks like this.
			That's a relative jump by 343 byte (0x00000157). We either want to
			change this to a relative jump by 0 byte (to the very next instruction,
			thus causing that branch to be taken always; instruction counter is
			already incremented) - or we want to restore the original offset. */
		byte* pStartAddress = reinterpret_cast<byte*>(0x004AE580);
		pStartAddress += 2; // first two byte (and last two) are fine
		byte aCodeBytes[][2] = {
			//  replacement| original
			{	0x00,		 0x51 },
			{	0x00,		 0x01 }
		};
		if (!unprotectPage(pStartAddress, ARRAYSIZE(aCodeBytes)))
			return false;
		for (int i = 0; i < ARRAYSIZE(aCodeBytes); i++)
			pStartAddress[i] = aCodeBytes[i][m_bRestore ? 1 : 0];
		return true;
	}
private:
	bool const m_bRestore;
};

} // (end of unnamed namespace)


void Civ4BeyondSwordPatches::showErrorMsgToPlayer(CvWString szMsg)
{
	// Don't need more error messages if assertions are enabled
#ifndef FASSERT_ENABLE
	if (GC.IsGraphicsInitialized() && GC.getGame().getActivePlayer() != NO_PLAYER)
	{
		gDLL->getInterfaceIFace()->addMessage(GC.getGame().getActivePlayer(), true,
				GC.getEVENT_MESSAGE_TIME(), szMsg, NULL, MESSAGE_TYPE_INFO, NULL,
				(ColorTypes)GC.getInfoTypeForString("COLOR_RED"));
	}
#endif
}

// trs.balloon:
void Civ4BeyondSwordPatches::patchPlotIndicatorSize()
{
	int const iScreenHeight = GC.getGame().getScreenHeight();
	if (iScreenHeight <= 0)
	{
		FErrorMsg("Caller should've ensured that screen dims are set");
		return;
	}
	// (If we fail past here, there won't be a point in trying again.)
	m_bPlotIndicatorSizePatched = true;
	if (!PlotIndicatorSizeMod(iScreenHeight).applyIfEnabled())
	{
		showErrorMsgToPlayer(
				"Failed to change balloon icon size. To avoid seeing "
				"this error message, set the size to \"BtS\" on the Map tab "
				"of the Mod Options screen");
	}
}

// <trs.modname>
void Civ4BeyondSwordPatches::patchModNameCheck(ModNameChecker const* pChecker)
{
	/*	No point in trying again, and shouldn't attempt to disable the
		mod name check if we don't have a hook. */
	if (m_bHookingFailed)
		return;
	bool const bHooked = isModNameCheckHooked();
	m_pModNameChecker = pChecker;
	if (!bHooked)
		patchModNameCheckHook();
	patchModNameCheck(false);
}


void Civ4BeyondSwordPatches::patchModNameCheckHook()
{
	if (!ModNameCheckHookPatch(&modNameCheckHook).applyIfEnabled())
	{
		/*	(This not going to help on the opening menu, but gDLL->MessageBox
			is no good either, at least not in fullscreen mode.) */
		showErrorMsgToPlayer(
				"Failed to insert hook for bypassing mod name check. "
				"To avoid seeing this error message, clear the list of "
				"compatible mods and set LOAD_BTS_SAVEGAMES to 0, "
				"both in GlobalDefinesAlt.xml");
		m_bHookingFailed = true;
		m_pModNameChecker = NULL; // Cleaner to unregister it I guess
	}
}


void Civ4BeyondSwordPatches::patchModNameCheck(bool bEnableCheck)
{
	if (isModNameCheckEnabled() == bEnableCheck)
		return;
	if (!ModNameCheckBypassPatch(bEnableCheck).applyIfEnabled())
	{
		showErrorMsgToPlayer(
				"Failed to bypass mod name check. "
				"To avoid seeing this error message, clear the list of "
				"compatible mods and set LOAD_BTS_SAVEGAMES to 0, "
				"both in GlobalDefinesAlt.xml");
	}
	m_bModNameCheckDisabled = !m_bModNameCheckDisabled;
}


int Civ4BeyondSwordPatches::modNameCheckHook()
{
	char const** pszSavedModName;
	/*	In a first try, the value of EDI had become changed somehow;
		don't quite know why that problem isn't occurring anymore.
		String instructions like MOVS or STOS have a side-effect on EDI,
		but those shouldn't be generated for setting a pointer.
		Could try to move EDI to EBX first and then from EBX to pszSavedModName
		if the problem reoccurs. ESI, EDI, EBX, and EBP should get preserved
		by prolog code, whereas ECX, EDX and EAX are not call-preserved.
		I don't think the first two are relevant in the calling context,
		except that EAX mustn't be 0. We'll return 1 to ensure that. */
	__asm { mov pszSavedModName, edi }
	/*	Hooking a non-static member function could be quite a bit more challenging.
		So we have to work with the global instance instead of *this. */
	Civ4BeyondSwordPatches& kInst = smc::BtS_EXE;
	if (kInst.isModNameCheckHooked())
	{
		kInst.patchModNameCheck(
				!kInst.m_pModNameChecker->isCompatible(*pszSavedModName));
	}
	return 1;
}
// </trs.modname>
