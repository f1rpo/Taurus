/*	trs.modname: Class for accessing and modifying(!) strings stored in the DLL
	and in the EXE(!) that contain the name of the folder where the mod is
	installed and its path. Regarding the path, our class only stores what
	CvDLLUtilityIFaceBase::getModName provides, and, regardless of the bFullPath
	parameter, that always seems to be a path relative to the parent folder of
	the "Mods" folder. Let's refer to that parent folder as the "root" folder.
	So the paths stored will be e.g. "Mods/Taurus". We'll still use separate
	variables for the paths returned by getModName b/c we can't be sure that the
	"full path" can't be longer under some circumstances, or the "mod name"
	just the name of the mod's folder. */
#pragma once
#ifndef MOD_NAME_H
#define MOD_NAME_H

class ModName
{
public:
	ModName(char const* szFullPath, char const* szPathInRoot);
	/*	These first three getters always return the (true) names as set
		by the ctor */
	char const* getFullPath() const { return m_sFullPath.c_str(); }
	char const* getPathInRoot() const { return m_sPathInRoot.c_str(); }
	// Just the name of the mod's folder, e.g. "Taurus".
	char const* getName() const { return m_sName.c_str(); }
	/*	These three getters return the names currently stored in the EXE.
		These can temporarily, while reading or writing a savegame, differ
		from the true names. */
	char const* getExtFullPath() const { return m_pExtFullPath->GetCString(); }
	char const* getExtPathInRoot() const { return m_pExtPathInRoot->GetCString(); }
	char const* getExtName() const { return m_sExtName.c_str(); }
	int getExtNameLengthLimit() const;
	// Replaces the name of the mod folder in the paths stored by the EXE
	void setExtModName(const char* szName,
			/*	Whether the name change should apply only until exportDone is called.
				Also, until then, setExtModName and resetExt calls will be ignored. */
			bool bExporting = false);
	void exportDone();
	// Restore the true paths in the EXE (if they've been changed)
	void resetExt();

private:
	bool m_bExporting;
	std::string m_sFullPath;
	std::string m_sPathInRoot;
	std::string m_sName;
	std::string m_sExtName; // Not stored separately by the EXE; handy to have.

	/*	I'm guessing that the string structure used by the EXE for storing
		the mod name is the mysterious FString class (F for "Firaxis Game Engine")
		mentioned in comments in CvString.h. */
	class FString
	{
	public:
		char const* GetCString() const { return &m_cFirstChar; }
		int getCapacity() const { return m_iCapacity; }
		// The EXE will provide a C string, like in the function above.
		static FString* create(char const* szExternal);
		bool assign(char const* szChars);
	private:
		FString(); // W/o implementation; will get our instances only from the EXE.
		int const m_iCapacity; // Can't grow the char array
		int m_iSize;
		/*	MSVC's std::string uses
			union { Elem _Buf[_BUF_SIZE]; _Elem *_Ptr; }
			however, a test with a really long mod name has confirmed that this
			local char array has a dynamic size. I guess through allocation of
			raw memory and a reinterpret_cast. */
		char m_cFirstChar;
		char const& at(int i) const { return *(&m_cFirstChar + i); }
		char& at(int i) { return *(&m_cFirstChar + i); }
		bool isValid() const;
	};
	FString* m_pExtFullPath;
	FString* m_pExtPathInRoot;
};

#endif
