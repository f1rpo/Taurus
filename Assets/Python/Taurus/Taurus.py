# trs. So far, used only as glue between Config/Taurus.xml and the DLL.

from CvPythonExtensions import *
import CvUtil
import BugPath

gc = CyGlobalContext()

# trs.balloon: (for Taurus__PlotIndicatorSize option)
def updatePlotIndicatorSize(option, value):
	cyUpdatePlotIndicatorSize()

def exportSaveGame(argsList):
	gc.getGame().exportSaveGame()
