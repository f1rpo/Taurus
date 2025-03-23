# trs.lod: Allow accessing the level-of-detail settings at runtime. Based on BugHelp.py.

from CvPythonExtensions import *
import BugUtil
import BugPath
import Popup
import os

def editLODSettings():
	subdir = os.path.join("XML", "Misc")
	fileName = "CIV4DetailManager.xml"
	detailMgr = BugPath.findAssetFile(fileName, subdir)
	if not detailMgr:
		failPopup = Popup.PyPopup()
		failPopup.setHeaderString(BugUtil.getPlainText("TXT_KEY_LOD_MISSING_TITLE"))
		failPopup.setBodyString(BugUtil.getText("TXT_KEY_BUG_HELP_MISSING_BODY",
				(str(os.path.join(subdir, fileName)),)))
		failPopup.launch()
		return False
	CyInterface().addImmediateMessage(BugUtil.getText("TXT_KEY_LOD_OPENING", (str(fileName),)), "")
	os.startfile(detailMgr)
	return True
