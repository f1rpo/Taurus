#pragma once
#ifndef SELF_MOD_H
#define SELF_MOD_H

/*	trs.smc: Let's put all runtime patches for Civ4BeyondSword.exe (v3.19)
	in a single place. (But, so far, there's only one.) For the time being,
	functions are exposed to Python through CyGameCoreUtils. */

class Civ4BeyondSwordMods
{
public:
	bool isPlotIndicatorSizePatched() const { return m_bPlotIndicatorSizePatched; }
	void patchPlotIndicatorSize(); // (exposed to Python)
private:
	bool m_bPlotIndicatorSizePatched;
};

namespace smc
{
	extern Civ4BeyondSwordMods BtS_EXE;
};

#endif
