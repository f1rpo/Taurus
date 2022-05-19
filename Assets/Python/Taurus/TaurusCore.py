# trs. So far, used only for handling changes to a Taurus option.

from CvPythonExtensions import *
import CvUtil
import BugPath

gc = CyGlobalContext()

# trs.balloon: (for Taurus__PlotIndicatorSize option)
def updatePlotIndicatorSize(option, value):
	cyUpdatePlotIndicatorSize()
