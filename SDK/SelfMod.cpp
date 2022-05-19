#include "CvGameCoreDLL.h"
#include "SelfMod.h"

// trs.smc: New implementation file; see comment in header.

Civ4BeyondSwordMods smc::BtS_EXE;

namespace
{
	bool unprotectPage(LPVOID pAddress, SIZE_T uiSize,
		DWORD ulNewProtect = PAGE_EXECUTE_READWRITE)
	{
		/*	Getting a segmentation fault when writing to the code section under
			Win 8.1. Probably the same on all Windows versions that anyone still uses.
			Need to unprotect the virtual memory page first. Let's hope that this
			long outdated version of VirtualProtect from WinBase.h (nowadays located
			in Memoryapi.h) will still do the trick on recent Win versions (and that
			it won't make our DLL look suspicious to virus scanners). */
		DWORD uiOldProtect; // I get PAGE_EXECUTE_READ here
		if (VirtualProtect(reinterpret_cast<LPVOID>(pAddress),
			/*	Will affect an entire page, not just the few bytes we need. Through
				SYSTEM_INFO sysInfo; GetSystemInfo(&sysInfo); sysInfo.dwPageSize;
				I see a page size of 4 KB. */
			uiSize, ulNewProtect, &uiOldProtect) == 0)
		{
			FAssertMsg(false, "Failed to unprotect memory for runtime patch "
					"(plot indicator size)");
			return false;
		}
		return true;
	}

	struct PlotIndicatorSize
	{
		PlotIndicatorSize(float fOnScreen = 0, float fOffScreen = 0)
		:	onScreen(fOnScreen), offScreen(fOffScreen) {}
		float onScreen, offScreen;
	};
	bool operator==(PlotIndicatorSize const& kFirst, PlotIndicatorSize const& kSecond)
	{	// Exact floating point comparison
		return (kFirst.onScreen == kSecond.onScreen &&
				kFirst.offScreen == kSecond.offScreen);
	}
}


void Civ4BeyondSwordMods::patchPlotIndicatorSize()
{
	int const iScreenHeight = GC.getGame().getScreenHeight();
	if (iScreenHeight <= 0)
	{
		FAssertMsg(false, "Caller should've ensured that screen dims are set");
		return;
	}
	// (If we fail, there won't be any point in trying again.)
	m_bPlotIndicatorSizePatched = true;
	// Cache for performance (though probably not a concern)
	static PlotIndicatorSize ffMostRecentBaseSize;

	/*	Size values for plot indicators shown onscreen and offscreen that are
		hardcoded in the EXE. These go through a bunch of calculations,
		only part of which I've located in the debugger. Essentially,
		there appears to be an adjustment proportional to the screen height. */
	PlotIndicatorSize ffBaseSize(42, 68);
	/*	The EXE will adjust to height. Rather than try to change that in the EXE,
		we'll proactively cancel out the adjustment. */
	{
		/*	Current screen height relative to the height that the UI was
			most optimized for */
		float fHeightRatio = iScreenHeight / 768.f;
		/*	Subtract a little b/c the BtS is a bit too big overall,
			i.e. even on the lowest resolution. */
		ffBaseSize.onScreen = (ffBaseSize.onScreen - 2) / fHeightRatio;
				/*	Could use this divisor to not cancel it out entirely -
					but the adjustment really just seems to be a bad idea. */
				// std::pow(fHeightRatio, 0.85f)
	}
	// Instead of the 68/42 (ca. 1.62) ratio used by BtS
	ffBaseSize.offScreen = ffBaseSize.onScreen * 1.4f;
	if (ffBaseSize == ffMostRecentBaseSize)
		return;
	ffMostRecentBaseSize = ffBaseSize;

	/*	The onscreen size is hardcoded as an immediate operand (in FP32 format)
		in three places and the offscreen size in one place.
		|Code addr.|Disassembly							|Machine code
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

	/*	Earlier attempt, kept for future reference. Since I hadn't been able
		to locate the offscreen size yet, I was instead overwriting a register
		that the size value passes through in any case. I.e. this was not going
		to use different sizes for the onscreen and offscreen case.
		 004973D5	mov edx,dword ptr [esp+84h]			 8B 94 24 84 00 00 00
		The suitable x86 move instruction is: B8+ rd id
		That's B8 + 2 = 0xBA combining the opcode and the EDX register and
		4 byte for the second operand. That leaves 2 byte to be filled with
		nops: 90 90 */
	/*	This data is actually still useful for confirming that the
		memory layout of the EXE is as expected */
	byte aOrigCode[] =		{ 0x8B, 0x94, 0x24, 0x84, 0x00, 0x00, 0x00 };
	byte* pCodeLoc = reinterpret_cast<byte*>(0x004973D5);
	/*byte aPatchedCode[] =	{ 0xBA, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90 };
	*reinterpret_cast<float*>(aPatchedCode + 1) = ffBaseSize.onScreen;
	for (int i = 0; i < ARRAYSIZE(aOrigCode); i++)
	{
		if (aOrigCode[i] == pCodeLoc[i])
			continue;
		// Re-applying our patch (fNewBaseSize having changed) is fine
		bool bAlreadyPatched = true;
		for (int j = 0; j < ARRAYSIZE(aPatchedCode); j++)
		{
			if ((j == 0 || j > 4) && aPatchedCode[j] != pCodeLoc[j])
			{
				bAlreadyPatched = false;
				break;
			}
		}
		if (bAlreadyPatched)
			break;
		FAssert(bAlreadyPatched);
		return;
	}
	unprotectPage(reinterpret_cast<LPVOID>(pCodeLoc), ARRAYSIZE(aOrigCode));
	for (int i = 0; i < ARRAYSIZE(aOrigCode); i++)
	{
		pCodeLoc[i] = aPatchedCode[i];
	}*/
	for (int i = 0; i < ARRAYSIZE(aOrigCode); i++)
	{
		if (aOrigCode[i] != pCodeLoc[i])
		{
			/*	NB: Large address awareness shouldn't be an issue, I've tested that
				both ways. Steam MP version isn't going to work with this DLL anyway.
				Wine should be tested, unusual languages also, especially Russian.
				Could still search the EXE for the proper code locations if those
				versions have slightly different virtual addresses. */
			FAssertMsg(false, "Unexpected memory layout; Wine? Non-MULTI5 version?");
			return;
		}
	}

	// Finally apply the actual patch
	for (int i = 0; i < ARRAYSIZE(aCodeAdresses); i++)
	{
		float fSize = (i >= 3 ? ffBaseSize.offScreen : ffBaseSize.onScreen);
		uint uiCodeAddress = aCodeAdresses[i] + aOperandOffsets[i];
		if (!unprotectPage(reinterpret_cast<LPVOID>(uiCodeAddress), sizeof(float)))
			return;
		*reinterpret_cast<float*>(uiCodeAddress) = fSize;
	}
}
