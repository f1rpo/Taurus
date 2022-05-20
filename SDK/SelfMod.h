/*	trs.smc: Let's put all runtime patches for Civ4BeyondSword.exe (v3.19)
	in a single place. */
#pragma once
#ifndef SELF_MOD_H
#define SELF_MOD_H

class Civ4BeyondSwordMods
{
public:
	// <trs.balloon>
	bool isPlotIndicatorSizePatched() const { return m_bPlotIndicatorSizePatched; }
	void patchPlotIndicatorSize(); // (exposed to Python via CyGameCoreUtils) 
	// </trs.balloon>
private:
	bool m_bPlotIndicatorSizePatched; // trs.balloon
};

namespace smc
{
	extern Civ4BeyondSwordMods BtS_EXE;
};

#endif
