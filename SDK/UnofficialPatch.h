/*	trs.modname: New header, for function that decides whether gameplay changes
	from v1.6 of the Unofficial Patch should take effect. I'm disabling them in
	network games b/c UP 1.6 can lead to OOS errors when BULL players are in the
	game. BULL 1.2 (the last official release) only uses UP 1.5.
	(To check whether there actually are BULL players, we could send a net message
	and check if we receive one from every other human; but getting the timing
	right could be tricky, and BULL players might join later in the game.) */

#pragma once
#ifndef UNOFFICIAL_PATCH_H
#define UNOFFICIAL_PATCH_H

/*	trs.fix: Will use this guard for minor Taurus gameplay changes
	(probably exclusively bugfixes). Somewhat fits in this header as one could
	consider such bugfixes as part of a UP fork. */
inline bool isBULL12Rules() { return GC.getInitCore().getMultiplayer(); }
inline bool isEnableUP16() { return !isBULL12Rules(); }

#endif
