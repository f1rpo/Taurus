// trs.smc: New implementation file; see comment in header.
#include "CvGameCoreDLL.h"
#include "SelfMod.h"
#include "CvBugOptions.h"

Civ4BeyondSwordMods smc::BtS_EXE;

namespace
{
/*	This class seems like an elegant way of ensuring that virtual memory protections
	are restored at the end */
class RuntimePatch : boost::noncopyable
{
public:
	virtual ~RuntimePatch() { restorePageProtections(); }
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
		/*	Getting a segmentation fault when writing to the code section under
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

class PlotIndicatorSizePatch : public RuntimePatch
{
public:
	PlotIndicatorSizePatch(int iScreenHeight) : m_iScreenHeight(iScreenHeight) {}
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

		int iAddressOffset = 0;
		/*	Before applying our patch, let's confirm that the code is layed out
			in memory as we expect it to be. */
		if (!testCodeLayout())
		{
			/*	We don't give up yet. If the mod is otherwise working, then the EXE is
				probably largely unchanged and the code bytes we're looking for do exist
				just as we expect - they're merely in a (slightly?) different place. */
			/*	The first 27 instructions at the start of the function that calls
				CvPlayer::getGlobeLayerColors. This is a fairly long sequence w/o any
				absolute addresses in operands. After this sequence, there are a bunch
				of DLL calls, the last one being CvPlayer::getGlobeLayerColors. It would
				be nice to search for those calls as well - since native code has fairly
				low entropy, meaning that my pattern of 27 instructions may not be as
				unique as I hope - but I'm not sure if the call addresses for external
				functions would be the same in a slightly abnormal EXE. */
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
			// Where we expect the needle at iAddressOffset=0
			uint const uiStartAddress = 0x00464930;
			// How big an iAddressOffset we contemplate
			int const iMaxAbsOffset = 256 * 1024;
			if (uiStartAddress >= iMaxAbsOffset &&
				uiStartAddress <= MAX_INT - iMaxAbsOffset)
			{
				byte aHaystackBytes[2 * iMaxAbsOffset];
				for (int iOffset = -iMaxAbsOffset; iOffset < iMaxAbsOffset; iOffset++)
				{
					aHaystackBytes[iOffset + iMaxAbsOffset] = *reinterpret_cast<byte*>(
							((int)uiStartAddress) + iOffset);
				}
				// No std::begin, std::end until C++11
				byte* const pHaystackEnd = aHaystackBytes + ARRAYSIZE(aHaystackBytes);
				byte* pos = std::search(
						aHaystackBytes, pHaystackEnd,
						aNeedleBytes, aNeedleBytes + ARRAYSIZE(aNeedleBytes));
				if (pos == pHaystackEnd)
				{
					FErrorMsg("Failed to locate plot indicator code bytes in EXE");
					return false;
				}
				iAddressOffset = ((int)std::distance(aHaystackBytes, pos))
						- iMaxAbsOffset;
			}
			else FErrorMsg("uiStartAddress doesn't look like a code address");
			// Run our initial test again to be on the safe side
			if (!testCodeLayout(iAddressOffset))
			{
				FErrorMsg("Address offset likely incorrect");
				return false;
			}
		}

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
	int m_iScreenHeight;
	struct PlotIndicatorSize
	{
		PlotIndicatorSize(float fOnScreen = 0, float fOffScreen = 0)
		:	onScreen(fOnScreen), offScreen(fOffScreen) {}
		// Overriding operator== for this nested thing would be a PITA
		bool equals(PlotIndicatorSizePatch::PlotIndicatorSize const& kOther)
		{	// Exact floating point comparison
			return (onScreen == kOther.onScreen &&
					offScreen == kOther.offScreen);
		}
		float onScreen, offScreen;
	};

	bool testCodeLayout(int iAddressOffset = 0)
	{
		/*	This is the call to CvPlayer::getGlobeLayerColors:
			 004649A9	call dword ptr ds:[0BC1E64h] */
		byte aCodeBytes[] = { 0xFF, 0x15, 0x64, 0x1E, 0xBC, 0x00 };
		byte* pCodeLoc = reinterpret_cast<byte*>(0x004649A9 + iAddressOffset);
		for (int i = 0; i < ARRAYSIZE(aCodeBytes); i++)
		{
			if (aCodeBytes[i] != pCodeLoc[i])
			{
				/*	NB: Large address awareness shouldn't be an issue, I've tested
					that both ways. Steam MP version isn't going to work with our
					DLL anyway. Wine should be tested, localized versions also. */
				FErrorMsg("Unexpected memory layout; EXE statically patched somehow?"
						" Wine? Non-MULTI5 version?");
				return false;
			}
		}
		return true; // Looks good, we don't worry.
	}
};

} // (end of unnamed namespace)


void Civ4BeyondSwordMods::patchPlotIndicatorSize()
{
	int const iScreenHeight = GC.getGame().getScreenHeight();
	if (iScreenHeight <= 0)
	{
		FErrorMsg("Caller should've ensured that screen dims are set");
		return;
	}
	// (If we fail past here, there won't be a point in trying again.)
	m_bPlotIndicatorSizePatched = true;
	PlotIndicatorSizePatch(iScreenHeight).applyIfEnabled();
}
