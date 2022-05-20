// trs.xtrasav: New implementation file; see comment in header.
#include "CvGameCoreDLL.h"
#include "ExtraSaveGameState.h"
#include "BugMod.h"


uint ExtraSaveGameState::saveVersionFlag()
{
	/*	This constant is used for signaling that extra data is being written
		at all, so it should never be changed. Instead, the local version counter
		in ExtraSaveGameState::write should be incremented when additional data
		needs to be saved. */
	return (BUG_DLL_SAVE_FORMAT << 3);
}

namespace
{
	// Helpers to avoid typing NULL pointer checks over and over
	template<typename T>
	void writePrimitive(FDataStreamBase& kStream, T* ptValue)
	{
		if (ptValue == NULL)
		{
			FErrorMsg("Extra save data unavailable");
			kStream.Write(static_cast<T>(0));
			return;
		}
		kStream.Write(*ptValue);
	}

	template<typename T>
	void readPrimitive(FDataStreamBase& kStream, T* ptValue)
	{
		if (ptValue == NULL)
		{
			FErrorMsg("Pointer for storing extra data read from save not set");
			T tSkip;
			kStream.Read(&tSkip);
			return;
		}
		kStream.Read(ptValue);
	}
}

void ExtraSaveGameState::write(FDataStreamBase& kStream) const
{
	/*	When adding more data, increment uiVersion, append the new data
		at the very end of this function and read it at the end of the
		read function if the uiVersion read there is high enough. This way,
		compatibility with earlier versions of this mod is maintained both ways. */
	uint uiVersion = 1;
	kStream.Write(uiVersion);
	writePrimitive(kStream, m_peCurrentLayer);
}


void ExtraSaveGameState::read(FDataStreamBase& kStream)
{
	if (!m_bReadEnabled)
		return; // No extra data to be read (not even a version counter)
	uint uiVersion;
	kStream.Read(&uiVersion);
	readPrimitive(kStream, (int*)m_peCurrentLayer);
}
