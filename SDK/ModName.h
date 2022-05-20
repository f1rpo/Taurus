/*	trs.modname: Small class for storing the mod's install location
	as provided by CvDLLUtilityIFaceBase::getModName */
#pragma once
#ifndef MOD_NAME_H
#define MOD_NAME_H

class ModName
{
public:
	ModName() : m_uiExtAddrFullPath(0), m_uiExtAddrPathInRoot(0) {}
	void update(CvDLLUtilityIFaceBase const& kUtility);
	void replaceName(char const* szName);
	char const* getFullPath() const { return m_sFullPath.c_str(); }
	char const* getPathInRoot() const { return m_sPathInRoot.c_str(); }
	char const* getName() const { return m_sName.c_str(); } // name of the Taurus folder
	// See comment in update about these two
	char* getFullPathExt() const
	{
		return reinterpret_cast<char*>(m_uiExtAddrFullPath);
	}
	char* getPathInRootExt() const
	{
		return reinterpret_cast<char*>(m_uiExtAddrPathInRoot);
	}
	
private:
	CvString m_sFullPath;
	CvString m_sPathInRoot;
	CvString m_sName;
	uint m_uiExtAddrFullPath;
	uint m_uiExtAddrPathInRoot;
};

#endif
