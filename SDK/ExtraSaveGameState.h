/*	trs.xtrasav: Game state that gets written to the very end of a savegame.
	It seems that BtS (and mods that use the same save format) tolerate such data,
	i.e., so long as our mod doesn't _require_ certain data to be saved, we can
	maintain bidirectional compatibility with BtS. */
#pragma once
#ifndef EXTRA_SAVE_GAME_STATE_H
#define EXTRA_SAVE_GAME_STATE_H

class ExtraSaveGameState
{
public:
	// Tells us whether or not our read function should read any data
	void setReadEnabled(bool b) { m_bReadEnabled = b; }
	/*	High-ish bit to be set in a save version flag of some
		serializable BtS class to indicate that extra data is
		appended at the end. */
	static uint saveVersionFlag();
	void write(FDataStreamBase& kStream) const;
	void read(FDataStreamBase& kStream);
	// Will only have pointer members set from the outside (plus the one bool)
	ExtraSaveGameState() { SecureZeroMemory(this, sizeof(*this)); }
	/*	Not used for anything (yet), saved and loaded just as an example.
		Setters like this one should be called by the read and write functions
		of the classes that the data belongs to conceptually. */
	void setCurrentLayer(GlobeLayerTypes* peCurrentLayer)
	{
		m_peCurrentLayer = peCurrentLayer;
	}
	
private:
	GlobeLayerTypes* m_peCurrentLayer;
	bool m_bReadEnabled;
};

#endif
