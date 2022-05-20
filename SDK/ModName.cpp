// trs.modname: New implementation file; see comment in header.
#include "CvGameCoreDLL.h"
#include "ModName.h"


void ModName::update(CvDLLUtilityIFaceBase const& kUtility)
{
	/*	Regardless of the bFullPath param, I'm always seeing the same result,
		namely a path relative to the parent folder of the Mods folder
		(I refer to that parent folder as "root"): "Mods\AdvCiv\"
		I don't know that bFullPath will never make a difference, so it seems
		safer to store both strings. Maybe the full path could be longer
		than what I've seen, maybe the non-full path could be just the
		actual mod name. We will, in any case, extract the actual mod name
		into m_sName.
		For another quirk, if we set the FString instances (see SelfMod.cpp)
		that store the paths inside the EXE to size 0, getModName will return
		NULL, not an empty string. So we also need to hold onto the addresses
		of the FStrings, or we won't be able to change them again. (Due to their
		peculiar memory layout, we can just as well hold onto the addresses of
		the char buffers.) */
	char const* szExtFullPath; char const* szExtPathInRoot;
	m_sFullPath = szExtFullPath = kUtility.getModName(true);
	m_sPathInRoot = szExtPathInRoot = kUtility.getModName(false);
	// Don't keep these as pointers, or we'll have to write our own (boring) copy ctor.
	m_uiExtAddrFullPath = reinterpret_cast<uint>(szExtFullPath);
	m_uiExtAddrPathInRoot = reinterpret_cast<uint>(szExtPathInRoot);
	m_sName = m_sPathInRoot;
	size_t posMods = m_sName.find("Mods");
	if (posMods != CvString::npos)
	{
		/*	Skip over "Mods" plus the path separator.
			And chop off the separator at the end. */
		m_sName = m_sName.substr(posMods + 5, m_sName.length() - posMods - 6);
	}
}

namespace
{
	bool replaceRightmost(CvString& s,
		char const* szPattern, char const* szReplacement)
	{
		size_t pos = s.rfind(szPattern);
		if (pos == CvString::npos)
			return false;
		s.replace(pos, std::strlen(szPattern), szReplacement);
		return true;
	}
}

void ModName::replaceName(char const* szName)
{
	if (szName[0] == '\0')
	{
		// Empty name implies empty paths (no Mods folder involved)
		m_sName = m_sPathInRoot = m_sFullPath = "";
		return;
	}
#ifdef FASSERT_ENABLE
	bool bSuccess =
#endif
	replaceRightmost(m_sPathInRoot, m_sName.c_str(), szName);
	FAssertMsg(bSuccess, "Mod name not found in mod path from root");
#ifdef FASSERT_ENABLE
	bSuccess =
#endif
	replaceRightmost(m_sFullPath, m_sName.c_str(), szName);
	FAssertMsg(bSuccess, "Mod name not found in full mod path");
	m_sName = szName;
	// (Leave the m_uiExtAddr... members alone; the addresses in the EXE don't change.)
}
