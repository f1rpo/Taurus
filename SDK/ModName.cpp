// trs.modname: New implementation file; see comment in header.
#include "CvGameCoreDLL.h"
#include "ModName.h"


ModName::ModName(char const* szFullPath, char const* szPathInRoot)
:	m_pExtFullPath(NULL), m_pExtPathInRoot(NULL)
{
	m_sFullPath = szFullPath;
	m_sPathInRoot = szPathInRoot;
	m_pExtFullPath = FString::create(szFullPath);
	m_pExtPathInRoot = FString::create(szPathInRoot);
	FAssert(m_pExtFullPath != NULL && m_pExtPathInRoot != NULL);
	m_sName = m_sPathInRoot;
	size_t posMods = m_sName.find("Mods");
	if (posMods != std::string::npos)
	{
		/*	Skip over "Mods" plus the path separator.
			And chop off the separator at the end. */
		m_sName = m_sName.substr(posMods + 5, m_sName.length() - posMods - 6);
	}
	else FErrorMsg("Failed to parse mod's folder name");
	m_sExtName = m_sName;
}


namespace
{
	void replaceRightmost(std::string& s,
		char const* szPattern, char const* szReplacement)
	{
		size_t pos = s.rfind(szPattern);
		if (pos != std::string::npos)
			s.replace(pos, std::strlen(szPattern), szReplacement);
		else FErrorMsg("Pattern not found");
	}
}


void ModName::setExtModName(const char* szName)
{
	if (m_pExtFullPath == NULL || m_pExtPathInRoot == NULL)
	{
		FErrorMsg("Can't change external mod name b/c failed parsing it in ctor");
		return;
	}
	std::string sNewFullPath, sNewPathInRoot;
	// Empty name implies empty paths (no Mods folder involved)
	if (szName[0] != '\0')
	{
		sNewFullPath = getExtFullPath();
		sNewPathInRoot = getExtPathInRoot();
		replaceRightmost(sNewFullPath, getExtName(), szName);
		replaceRightmost(sNewPathInRoot, getExtName(), szName);
	}
	if (((int)sNewFullPath.length()) > m_pExtFullPath->getCapacity() ||
		((int)sNewPathInRoot.length()) > m_pExtPathInRoot->getCapacity())
	{
		FErrorMsg("Insufficient capacity for new mod name");
		return;
	}
	bool bSuccess = (m_pExtFullPath->assign(sNewFullPath.c_str()) &&
			m_pExtPathInRoot->assign(sNewPathInRoot.c_str()));
	if (!bSuccess ||
		/*	The EXE will return NULL instead of an empty string
			when the FString size is 0 */
		((gDLL->getModName(true) == NULL || gDLL->getModName(false) == NULL) ?
		szName[0] != '\0' :
		(std::strcmp(sNewFullPath.c_str(), gDLL->getModName(true)) != 0 ||
		std::strcmp(sNewPathInRoot.c_str(), gDLL->getModName(false)) != 0)))
	{
		/*	Our std::string members should all be good.
			Just need to make the FStrings consistent with them. */
		resetExt();
		/*	Result still won't be what our caller expects - szName has
			not been adopted. */
		FErrorMsg("Failed to change mod name in EXE");
	}
	// Don't update this until we're certain of having succeeded
	else m_sExtName = szName;
}


void ModName::resetExt()
{
	if (m_pExtFullPath->assign(m_sFullPath.c_str()) &&
		m_pExtPathInRoot->assign(m_sPathInRoot.c_str()))
	{
		m_sExtName = m_sName;
	}
	else FErrorMsg("Failed to reset external mod name");
}


bool ModName::FString::isValid() const
{
	// Verify that our instance is laid out as expected
	if (m_iCapacity >= 31 && // The smallest value I've seen in the debugger
		m_iCapacity <= 128 && // sanity test
		m_iSize >= 0 && m_iSize <= m_iCapacity)
	{
		if (m_iSize > 0)
		{
			if (at(m_iSize) != '\0')
				return false;
			for (int i = 0; i < m_iSize; i++)
			{
				if (at(i) == '\0')
					return false;
			}
		}
		return true;
	}
	return false;
}


ModName::FString* ModName::FString::create(char const* szExternal)
{
	if (szExternal == NULL)
		return NULL;
	FString& kInst = *reinterpret_cast<FString*>(
			const_cast<char*>(szExternal - sizeof(int) * 2));
	if (!kInst.isValid())
	{
		FErrorMsg("Invalid FString data");
		return NULL;
	}
	return &kInst;
}


bool ModName::FString::assign(char const* szChars)
{
	bool bSuccess = false;
	int iNewSize = 0;
	for (int i = 0; i < m_iCapacity; i++)
	{
		char c = szChars[i];
		at(i) = c;
		if (c == '\0')
		{
			bSuccess = true;
			break;
		}
		iNewSize++;
	}
	/*	Don't know if the string class in the EXE ensures that too;
		it looks like it in the debugger. */
	for (int i = iNewSize; i < m_iCapacity; i++)
		at(i) = '\0';
	m_iSize = iNewSize;
	return bSuccess;
}
