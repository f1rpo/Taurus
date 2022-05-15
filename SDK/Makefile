## BUG DLL MAKEFILE
##
## Based on Refar's makefile


### Tool Paths

TOOLKIT = C:\Coding\Microsoft Visual C++ Toolkit 2003
PSDK = C:\Program Files\Microsoft Platform SDK


### Civ4 SDK Paths

CIV = C:\Games\Civ4\Beyond the Sword
SDK = $(CIV)\CvGameCoreDLL
BOOST = $(SDK)\Boost-1.32.0
PYTHON = $(SDK)\Python24


### Tool Executables

RM = del
CPP = "$(TOOLKIT)/bin/cl.exe"
LINK = "$(TOOLKIT)/bin/link.exe"


### Compiler Options

# Optional BULL Components (Mods)
#   _BUFFY
#   _MOD_FRACTRADE
#   _MOD_SENTRY				has extra assets
#   _MOD_GOVWORKERS			has extra assets
#   _MOD_AIAUTOPLAY
#   _MOD_GWARM				has extra assets; effectively eliminates global warming
#   _MOD_SHAM_SPOILER		enables AG modifiers in mod

MODFLAGS = /D_MOD_AIAUTOPLAY

# /EHsc		catch C++ exceptions only; assume that extern C functions never throw a C++ exception
# /Gd		Use the __cdecl calling convention (x86 only). 
# /GR		enable run-time type information (RTTI)
# /G7		optimize for Pentium 4 and above
# /MD		multithreaded normal DLL with MSVCRT.dll
# /MDd		multithreaded debug DLL with MSVCRTD.dll
# /O2		optimize for speed (equal to /Og /Oi /Ot /Oy /Ob2 /Gs /GF /Gy)
# /W3		warning level 3

CFLAGS = /EHsc /Gd /GR /G7 /W3 /DWIN32 /D_WINDOWS /D_USRDLL /DCVGAMECOREDLL_EXPORTS  $(MODFLAGS)
DEBUG_CFLAGS = $(CFLAGS) /MDd /D_DEBUG
RELEASE_CFLAGS = $(CFLAGS) /MD /O2 /DNDEBUG /DFINAL_RELEASE


### Linker Options

# /debug	create debugging information
# /INC:NO	results in small DLL
# /OPT:REF	remove unreferenced data/functions
# /OPT:ICF	identical COMDAT folding (trimming identical read-only data)
# /SUB:WIN	EXE doesn't need a console; shouldn't need this

LDFLAGS = 
DEBUG_LDFLAGS = $(LDFLAGS) /debug /pdb:Debug\CvGameCoreDLL_DEBUG.pdb /NODEFAULTLIB:msvcprtd.lib
RELEASE_LDFLAGS = $(LDFLAGS) /INCREMENTAL:NO /OPT:REF /OPT:ICF


### Include and Library Paths

INCS = /I"CxImage/general" /I"CxImage/jpeg" /I"$(BOOST)/include" /I"$(PYTHON)/include" /I"$(TOOLKIT)/include" /I"$(PSDK)/Include"
LIBDIRS = /LIBPATH:"$(PYTHON)/libs" /LIBPATH:"$(BOOST)/libs/" /LIBPATH:"$(PSDK)/Lib" /LIBPATH:"$(TOOLKIT)/lib"


### Libraries

LIBS = boost_python-vc71-mt-1_32.lib winmm.lib user32.lib gdi32.lib Ole32.lib
DEBUG_LIBS = $(LIBS) msvcprt.lib
RELEASE_LIBS = $(LIBS)


### Target-Specific Options

Debug_CFLAGS = $(DEBUG_CFLAGS)
Debug_LDFLAGS = $(DEBUG_LDFLAGS)
Debug_INCS = $(INCS)
Debug_LIBDIRS = $(LIBDIRS)
Debug_LIBS = $(DEBUG_LIBS)

Final_Release_CFLAGS = $(RELEASE_CFLAGS)
Final_Release_LDFLAGS = $(RELEASE_LDFLAGS)
Final_Release_INCS = $(INCS)
Final_Release_LIBDIRS = $(LIBDIRS)
Final_Release_LIBS = $(RELEASE_LIBS)


### TARGETS AND COMMANDS ###


### Objects used in this Makefile

Debug_OBJS = Debug/_precompile.obj Debug/CvArea.obj Debug/CvArtFileMgr.obj Debug/CvBugOptions.obj Debug/CvCity.obj Debug/CvCityAI.obj Debug/CvDLLButtonPopup.obj Debug/CvDLLEntity.obj Debug/CvDLLPython.obj Debug/CvDLLWidgetData.obj Debug/CvDeal.obj Debug/CvDiploParameters.obj Debug/CvDllPythonEvents.obj Debug/CvDllTranslator.obj Debug/CvEventReporter.obj Debug/CvFractal.obj Debug/CvGame.obj Debug/CvGameAI.obj Debug/CvGameCoreDLL.obj Debug/CvGameCoreUtils.obj Debug/CvGameInterface.obj Debug/CvGameTextMgr.obj Debug/CvGlobals.obj Debug/CvHallOfFameInfo.obj Debug/CvInfoWater.obj Debug/CvInfos.obj Debug/CvInitCore.obj Debug/CvMap.obj Debug/CvMapGenerator.obj Debug/CvMessageControl.obj Debug/CvMessageData.obj Debug/CvPlayer.obj Debug/CvPlayerAI.obj Debug/CvPlot.obj Debug/CvPlotGroup.obj Debug/CvPopupInfo.obj Debug/CvPopupReturn.obj Debug/CvRandom.obj Debug/CvReplayInfo.obj Debug/CvReplayMessage.obj Debug/CvSelectionGroup.obj Debug/CvSelectionGroupAI.obj Debug/CvStatistics.obj Debug/CvStructs.obj Debug/CvTalkingHeadMessage.obj Debug/CvTeam.obj Debug/CvTeamAI.obj Debug/CvUnit.obj Debug/CvUnitAI.obj Debug/CvXMLLoadUtility.obj Debug/CvXMLLoadUtilityGet.obj Debug/CvXMLLoadUtilityInit.obj Debug/CvXMLLoadUtilitySet.obj Debug/CyArea.obj Debug/CyAreaInterface.obj Debug/CyArgsList.obj Debug/CyArtFileMgr.obj Debug/CyArtFileMgrInterface.obj Debug/CyCity.obj Debug/CyCityInterface1.obj Debug/CyDeal.obj Debug/CyEnumsInterface.obj Debug/CyGame.obj Debug/CyGameCoreUtils.obj Debug/CyGameCoreUtilsInterface.obj Debug/CyGameInterface.obj Debug/CyGameTextMgr.obj Debug/CyGameTextMgrInterface.obj Debug/CyGlobalContext.obj Debug/CyGlobalContextInterface1.obj Debug/CyGlobalContextInterface2.obj Debug/CyGlobalContextInterface3.obj Debug/CyGlobalContextInterface4.obj Debug/CyHallOfFameInfo.obj Debug/CyHallOfFameInterface.obj Debug/CyInfoInterface1.obj Debug/CyInfoInterface2.obj Debug/CyInfoInterface3.obj Debug/CyMap.obj Debug/CyMapGenerator.obj Debug/CyMapGeneratorInterface.obj Debug/CyMapInterface.obj Debug/CyMessageControl.obj Debug/CyMessageControlInterface.obj Debug/CyPlayer.obj Debug/CyPlayerInterface1.obj Debug/CyPlayerInterface2.obj Debug/CyPlot.obj Debug/CyPlotInterface1.obj Debug/CyRandomInterface.obj Debug/CyReplayInfo.obj Debug/CySelectionGroup.obj Debug/CySelectionGroupInterface.obj Debug/CyStructsInterface1.obj Debug/CyTeam.obj Debug/CyTeamInterface.obj Debug/CyUnit.obj Debug/CyUnitInterface1.obj Debug/FAssert.obj Debug/FDialogTemplate.obj Debug/CxImage/general/tif_xfile.obj Debug/CxImage/general/ximabmp.obj Debug/CxImage/general/ximadsp.obj Debug/CxImage/general/ximaenc.obj Debug/CxImage/general/ximaexif.obj Debug/CxImage/general/ximage.obj Debug/CxImage/general/ximagif.obj Debug/CxImage/general/ximahist.obj Debug/CxImage/general/ximaico.obj Debug/CxImage/general/ximainfo.obj Debug/CxImage/general/ximaint.obj Debug/CxImage/general/ximaj2k.obj Debug/CxImage/general/ximajas.obj Debug/CxImage/general/ximajbg.obj Debug/CxImage/general/ximajpg.obj Debug/CxImage/general/ximalpha.obj Debug/CxImage/general/ximalyr.obj Debug/CxImage/general/ximamng.obj Debug/CxImage/general/ximapal.obj Debug/CxImage/general/ximapcx.obj Debug/CxImage/general/ximapng.obj Debug/CxImage/general/ximasel.obj Debug/CxImage/general/ximatga.obj Debug/CxImage/general/ximath.obj Debug/CxImage/general/ximatif.obj Debug/CxImage/general/ximatran.obj Debug/CxImage/general/ximawbmp.obj Debug/CxImage/general/ximawmf.obj Debug/CxImage/general/ximawnd.obj Debug/CxImage/general/xmemfile.obj Debug/CxImage/jpeg/jcapimin.obj Debug/CxImage/jpeg/jcapistd.obj Debug/CxImage/jpeg/jccoefct.obj Debug/CxImage/jpeg/jccolor.obj Debug/CxImage/jpeg/jcdctmgr.obj Debug/CxImage/jpeg/jchuff.obj Debug/CxImage/jpeg/jcinit.obj Debug/CxImage/jpeg/jcmainct.obj Debug/CxImage/jpeg/jcmarker.obj Debug/CxImage/jpeg/jcmaster.obj Debug/CxImage/jpeg/jcomapi.obj Debug/CxImage/jpeg/jcparam.obj Debug/CxImage/jpeg/jcphuff.obj Debug/CxImage/jpeg/jcprepct.obj Debug/CxImage/jpeg/jcsample.obj Debug/CxImage/jpeg/jctrans.obj Debug/CxImage/jpeg/jdapimin.obj Debug/CxImage/jpeg/jdapistd.obj Debug/CxImage/jpeg/jdatadst.obj Debug/CxImage/jpeg/jdatasrc.obj Debug/CxImage/jpeg/jdcoefct.obj Debug/CxImage/jpeg/jdcolor.obj Debug/CxImage/jpeg/jddctmgr.obj Debug/CxImage/jpeg/jdhuff.obj Debug/CxImage/jpeg/jdinput.obj Debug/CxImage/jpeg/jdmainct.obj Debug/CxImage/jpeg/jdmarker.obj Debug/CxImage/jpeg/jdmaster.obj Debug/CxImage/jpeg/jdmerge.obj Debug/CxImage/jpeg/jdphuff.obj Debug/CxImage/jpeg/jdpostct.obj Debug/CxImage/jpeg/jdsample.obj Debug/CxImage/jpeg/jdtrans.obj Debug/CxImage/jpeg/jerror.obj Debug/CxImage/jpeg/jfdctflt.obj Debug/CxImage/jpeg/jfdctfst.obj Debug/CxImage/jpeg/jfdctint.obj Debug/CxImage/jpeg/jidctflt.obj Debug/CxImage/jpeg/jidctfst.obj Debug/CxImage/jpeg/jidctint.obj Debug/CxImage/jpeg/jidctred.obj Debug/CxImage/jpeg/jmemmgr.obj Debug/CxImage/jpeg/jmemnobs.obj Debug/CxImage/jpeg/jquant1.obj Debug/CxImage/jpeg/jquant2.obj Debug/CxImage/jpeg/jutils.obj
Debug_LINKOBJS = $(Debug_OBJS)

Final_Release_OBJS = Final_Release/_precompile.obj Final_Release/CvArea.obj Final_Release/CvArtFileMgr.obj Final_Release/CvBugOptions.obj Final_Release/CvCity.obj Final_Release/CvCityAI.obj Final_Release/CvDLLButtonPopup.obj Final_Release/CvDLLEntity.obj Final_Release/CvDLLPython.obj Final_Release/CvDLLWidgetData.obj Final_Release/CvDeal.obj Final_Release/CvDiploParameters.obj Final_Release/CvDllPythonEvents.obj Final_Release/CvDllTranslator.obj Final_Release/CvEventReporter.obj Final_Release/CvFractal.obj Final_Release/CvGame.obj Final_Release/CvGameAI.obj Final_Release/CvGameCoreDLL.obj Final_Release/CvGameCoreUtils.obj Final_Release/CvGameInterface.obj Final_Release/CvGameTextMgr.obj Final_Release/CvGlobals.obj Final_Release/CvHallOfFameInfo.obj Final_Release/CvInfoWater.obj Final_Release/CvInfos.obj Final_Release/CvInitCore.obj Final_Release/CvMap.obj Final_Release/CvMapGenerator.obj Final_Release/CvMessageControl.obj Final_Release/CvMessageData.obj Final_Release/CvPlayer.obj Final_Release/CvPlayerAI.obj Final_Release/CvPlot.obj Final_Release/CvPlotGroup.obj Final_Release/CvPopupInfo.obj Final_Release/CvPopupReturn.obj Final_Release/CvRandom.obj Final_Release/CvReplayInfo.obj Final_Release/CvReplayMessage.obj Final_Release/CvSelectionGroup.obj Final_Release/CvSelectionGroupAI.obj Final_Release/CvStatistics.obj Final_Release/CvStructs.obj Final_Release/CvTalkingHeadMessage.obj Final_Release/CvTeam.obj Final_Release/CvTeamAI.obj Final_Release/CvUnit.obj Final_Release/CvUnitAI.obj Final_Release/CvXMLLoadUtility.obj Final_Release/CvXMLLoadUtilityGet.obj Final_Release/CvXMLLoadUtilityInit.obj Final_Release/CvXMLLoadUtilitySet.obj Final_Release/CyArea.obj Final_Release/CyAreaInterface.obj Final_Release/CyArgsList.obj Final_Release/CyArtFileMgr.obj Final_Release/CyArtFileMgrInterface.obj Final_Release/CyCity.obj Final_Release/CyCityInterface1.obj Final_Release/CyDeal.obj Final_Release/CyEnumsInterface.obj Final_Release/CyGame.obj Final_Release/CyGameCoreUtils.obj Final_Release/CyGameCoreUtilsInterface.obj Final_Release/CyGameInterface.obj Final_Release/CyGameTextMgr.obj Final_Release/CyGameTextMgrInterface.obj Final_Release/CyGlobalContext.obj Final_Release/CyGlobalContextInterface1.obj Final_Release/CyGlobalContextInterface2.obj Final_Release/CyGlobalContextInterface3.obj Final_Release/CyGlobalContextInterface4.obj Final_Release/CyHallOfFameInfo.obj Final_Release/CyHallOfFameInterface.obj Final_Release/CyInfoInterface1.obj Final_Release/CyInfoInterface2.obj Final_Release/CyInfoInterface3.obj Final_Release/CyMap.obj Final_Release/CyMapGenerator.obj Final_Release/CyMapGeneratorInterface.obj Final_Release/CyMapInterface.obj Final_Release/CyMessageControl.obj Final_Release/CyMessageControlInterface.obj Final_Release/CyPlayer.obj Final_Release/CyPlayerInterface1.obj Final_Release/CyPlayerInterface2.obj Final_Release/CyPlot.obj Final_Release/CyPlotInterface1.obj Final_Release/CyRandomInterface.obj Final_Release/CyReplayInfo.obj Final_Release/CySelectionGroup.obj Final_Release/CySelectionGroupInterface.obj Final_Release/CyStructsInterface1.obj Final_Release/CyTeam.obj Final_Release/CyTeamInterface.obj Final_Release/CyUnit.obj Final_Release/CyUnitInterface1.obj Final_Release/FAssert.obj Final_Release/FDialogTemplate.obj Final_Release/CxImage/general/tif_xfile.obj Final_Release/CxImage/general/ximabmp.obj Final_Release/CxImage/general/ximadsp.obj Final_Release/CxImage/general/ximaenc.obj Final_Release/CxImage/general/ximaexif.obj Final_Release/CxImage/general/ximage.obj Final_Release/CxImage/general/ximagif.obj Final_Release/CxImage/general/ximahist.obj Final_Release/CxImage/general/ximaico.obj Final_Release/CxImage/general/ximainfo.obj Final_Release/CxImage/general/ximaint.obj Final_Release/CxImage/general/ximaj2k.obj Final_Release/CxImage/general/ximajas.obj Final_Release/CxImage/general/ximajbg.obj Final_Release/CxImage/general/ximajpg.obj Final_Release/CxImage/general/ximalpha.obj Final_Release/CxImage/general/ximalyr.obj Final_Release/CxImage/general/ximamng.obj Final_Release/CxImage/general/ximapal.obj Final_Release/CxImage/general/ximapcx.obj Final_Release/CxImage/general/ximapng.obj Final_Release/CxImage/general/ximasel.obj Final_Release/CxImage/general/ximatga.obj Final_Release/CxImage/general/ximath.obj Final_Release/CxImage/general/ximatif.obj Final_Release/CxImage/general/ximatran.obj Final_Release/CxImage/general/ximawbmp.obj Final_Release/CxImage/general/ximawmf.obj Final_Release/CxImage/general/ximawnd.obj Final_Release/CxImage/general/xmemfile.obj Final_Release/CxImage/jpeg/jcapimin.obj Final_Release/CxImage/jpeg/jcapistd.obj Final_Release/CxImage/jpeg/jccoefct.obj Final_Release/CxImage/jpeg/jccolor.obj Final_Release/CxImage/jpeg/jcdctmgr.obj Final_Release/CxImage/jpeg/jchuff.obj Final_Release/CxImage/jpeg/jcinit.obj Final_Release/CxImage/jpeg/jcmainct.obj Final_Release/CxImage/jpeg/jcmarker.obj Final_Release/CxImage/jpeg/jcmaster.obj Final_Release/CxImage/jpeg/jcomapi.obj Final_Release/CxImage/jpeg/jcparam.obj Final_Release/CxImage/jpeg/jcphuff.obj Final_Release/CxImage/jpeg/jcprepct.obj Final_Release/CxImage/jpeg/jcsample.obj Final_Release/CxImage/jpeg/jctrans.obj Final_Release/CxImage/jpeg/jdapimin.obj Final_Release/CxImage/jpeg/jdapistd.obj Final_Release/CxImage/jpeg/jdatadst.obj Final_Release/CxImage/jpeg/jdatasrc.obj Final_Release/CxImage/jpeg/jdcoefct.obj Final_Release/CxImage/jpeg/jdcolor.obj Final_Release/CxImage/jpeg/jddctmgr.obj Final_Release/CxImage/jpeg/jdhuff.obj Final_Release/CxImage/jpeg/jdinput.obj Final_Release/CxImage/jpeg/jdmainct.obj Final_Release/CxImage/jpeg/jdmarker.obj Final_Release/CxImage/jpeg/jdmaster.obj Final_Release/CxImage/jpeg/jdmerge.obj Final_Release/CxImage/jpeg/jdphuff.obj Final_Release/CxImage/jpeg/jdpostct.obj Final_Release/CxImage/jpeg/jdsample.obj Final_Release/CxImage/jpeg/jdtrans.obj Final_Release/CxImage/jpeg/jerror.obj Final_Release/CxImage/jpeg/jfdctflt.obj Final_Release/CxImage/jpeg/jfdctfst.obj Final_Release/CxImage/jpeg/jfdctint.obj Final_Release/CxImage/jpeg/jidctflt.obj Final_Release/CxImage/jpeg/jidctfst.obj Final_Release/CxImage/jpeg/jidctint.obj Final_Release/CxImage/jpeg/jidctred.obj Final_Release/CxImage/jpeg/jmemmgr.obj Final_Release/CxImage/jpeg/jmemnobs.obj Final_Release/CxImage/jpeg/jquant1.obj Final_Release/CxImage/jpeg/jquant2.obj Final_Release/CxImage/jpeg/jutils.obj
Final_Release_LINKOBJS = $(Final_Release_OBJS)


### The targets of this project

Debug_BIN = Debug/CvGameCoreDLL.dll
Debug_STATIC_LIB = Debug/CvGameCoreDLL.lib
Debug_LIB_DEF = Debug/CvGameCoreDLL.def

Final_Release_BIN = Final_Release/CvGameCoreDLL.dll
Final_Release_STATIC_LIB = Final_Release/CvGameCoreDLL.lib
Final_Release_LIB_DEF = Final_Release/CvGameCoreDLL.def

.PHONY: all all-before all-custom all-after clean clean-custom distclean distclean-custom depend_Debug Debug-before Debug-after depend_Final_Release Final_Release-before Final_Release-after 

all-before:
all-custom:
all-after:
clean-custom:
distclean-custom:

depend_Debug:
Debug-before:
Debug-after:
	-@if exist "$(@:-after=)\CvGameCoreDLL.dll" copy "$(@:-after=)\CvGameCoreDLL.dll" "$(CIV)\Assets"

depend_Final_Release:
Final_Release-before:
Final_Release-after:
	-@if exist "$(@:-after=)\CvGameCoreDLL.dll" copy "$(@:-after=)\CvGameCoreDLL.dll" "$(CIV)\Assets"

all: all-before Debug Final_Release all-after


dist:
	@zip CvBugOptions.cpp CvBugOptions.h CvGameCoreDLL.cbp.zip CvGameCoreDLL.cbp Makefile CvArea.cpp CvArea.h CvArtFileMgr.cpp CvArtFileMgr.h CvCity.cpp CvCity.h CvCityAI.cpp CvCityAI.h CvDLLButtonPopup.cpp CvDLLButtonPopup.h CvDLLDataStreamIFaceBase.h CvDLLEngineIFaceBase.h CvDLLEntity.cpp CvDLLEntity.h CvDLLEntityIFaceBase.h CvDLLEventReporterIFaceBase.h CvDLLFAStarIFaceBase.h CvDLLFlagEntityIFaceBase.h CvDLLIniParserIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLPlotBuilderIFaceBase.h CvDLLPython.cpp CvDLLPythonIFaceBase.h CvDLLSymbolIFaceBase.h CvDLLUtilityIFaceBase.h CvDLLWidgetData.cpp CvDLLWidgetData.h CvDLLXMLIFaceBase.h CvDeal.cpp CvDeal.h CvDefines.h CvDiploParameters.cpp CvDiploParameters.h CvEnums.h CvFractal.cpp CvFractal.h CvGame.cpp CvGame.h CvGameAI.cpp CvGameAI.h CvGameCoreDLL.cpp CvGameCoreDLL.h CvGameCoreDLLDefNew.h CvGameCoreDLLUndefNew.h CvGameCoreUtils.cpp CvGameCoreUtils.h CvGameInterface.cpp CvGameTextMgr.cpp CvGameTextMgr.h CvGlobals.cpp CvGlobals.h CvHallOfFameInfo.cpp CvHallOfFameInfo.h CvInfoWater.cpp CvInfoWater.h CvInfos.cpp CvInfos.h CvInitCore.cpp CvInitCore.h CvMap.cpp CvMap.h CvMapGenerator.cpp CvMapGenerator.h CvPlayer.cpp CvPlayer.h CvPlayerAI.cpp CvPlayerAI.h CvPlot.cpp CvPlot.h CvPlotGroup.cpp CvPlotGroup.h CvPopupInfo.cpp CvPopupInfo.h CvPopupReturn.cpp CvPopupReturn.h CvRandom.cpp CvRandom.h CvReplayInfo.cpp CvReplayInfo.h CvReplayMessage.cpp CvReplayMessage.h CvSelectionGroup.cpp CvSelectionGroup.h CvSelectionGroupAI.cpp CvSelectionGroupAI.h CvString.h CvStructs.cpp CvStructs.h CvTalkingHeadMessage.cpp CvTalkingHeadMessage.h CvTeam.cpp CvTeam.h CvTeamAI.cpp CvTeamAI.h CvUnit.cpp CvUnit.h CvUnitAI.cpp CvUnitAI.h CvXMLLoadUtility.cpp CvXMLLoadUtility.h CvXMLLoadUtilityGet.cpp CvXMLLoadUtilityInit.cpp CvXMLLoadUtilitySet.cpp CyArea.cpp CyArea.h CyAreaInterface.cpp CyArgsList.cpp CyArgsList.h CyArtFileMgr.cpp CyArtFileMgr.h CyArtFileMgrInterface.cpp CyCity.cpp CyCity.h CyCityInterface1.cpp CyDeal.cpp CyDeal.h CyEnumsInterface.cpp CyGame.cpp CyGame.h CyGameCoreUtils.cpp CyGameCoreUtils.h CyGameCoreUtilsInterface.cpp CyGameInterface.cpp CyGameTextMgr.cpp CyGameTextMgr.h CyGameTextMgrInterface.cpp CyGlobalContext.cpp CyGlobalContext.h CyGlobalContextInterface1.cpp CyGlobalContextInterface2.cpp CyGlobalContextInterface3.cpp CyGlobalContextInterface4.cpp CyHallOfFameInfo.cpp CyHallOfFameInfo.h CyHallOfFameInterface.cpp CyInfoInterface1.cpp CyInfoInterface2.cpp CyInfoInterface3.cpp CyMap.cpp CyMap.h CyMapGenerator.cpp CyMapGenerator.h CyMapGeneratorInterface.cpp CyMapInterface.cpp CyPlayer.cpp CyPlayer.h CyPlayerInterface1.cpp CyPlayerInterface2.cpp CyPlot.cpp CyPlot.h CyPlotInterface1.cpp CyRandomInterface.cpp CyReplayInfo.cpp CyReplayInfo.h CySelectionGroup.cpp CySelectionGroup.h CySelectionGroupInterface.cpp CyStructsInterface1.cpp CyTeam.cpp CyTeam.h CyTeamInterface.cpp CyUnit.cpp CyUnit.h CyUnitInterface1.cpp FAssert.cpp FAssert.h FDialogTemplate.cpp FDialogTemplate.h FProfiler.h LinkedList.h _precompile.cpp 

clean_Debug:
	$(RM) $(Debug_BIN) $(Debug_OBJS) $(Debug_STATIC_LIB) $(Debug_LIB_DEF) 

distclean_Debug:
	$(RM) $(Debug_BIN) $(Debug_OBJS) $(Debug_DEPS) $(Debug_STATIC_LIB) $(Debug_LIB_DEF) 

clean_Final_Release:
	$(RM) $(Final_Release_BIN) $(Final_Release_OBJS) $(Final_Release_STATIC_LIB) $(Final_Release_LIB_DEF) 

distclean_Final_Release:
	$(RM) $(Final_Release_BIN) $(Final_Release_OBJS) $(Final_Release_DEPS) $(Final_Release_STATIC_LIB) $(Final_Release_LIB_DEF) 

clean: clean_Debug clean_Final_Release

distclean: distclean_Debug distclean_Final_Release

depend:

Debug_DIRS:
	-@if not exist "Debug\." mkdir "Debug"
	-@if not exist "Debug\CxImage\general\." mkdir "Debug\CxImage\general"
	-@if not exist "Debug\CxImage\jpeg\." mkdir "Debug\CxImage\jpeg"

$(Debug_BIN): $(Debug_LINKOBJS)
	$(LINK) /dll /nologo $(Debug_LIBDIRS) /out:$(Debug_BIN) $(Debug_LIBS) $(Debug_LINKOBJS) $(Debug_LDFLAGS)

Debug: depend_Debug Debug_DIRS Debug-before $(Debug_BIN) Debug-after


Final_Release_DIRS:
	-@if not exist "Final_Release\." mkdir "Final_Release"
	-@if not exist "Final_Release\CxImage\general\." mkdir "Final_Release\CxImage\general"
	-@if not exist "Final_Release\CxImage\jpeg\." mkdir "Final_Release\CxImage\jpeg"

$(Final_Release_BIN): $(Final_Release_LINKOBJS)
	$(LINK) /dll /nologo $(Final_Release_LIBDIRS) /out:$(Final_Release_BIN) $(Final_Release_LIBS) $(Final_Release_LINKOBJS) $(Final_Release_LDFLAGS)

Final_Release: depend_Final_Release Final_Release_DIRS Final_Release-before $(Final_Release_BIN) Final_Release-after


## Target: Debug

Debug/CvArea.obj: CvArea.cpp CvGameCoreDLL.h CvArea.h CvMap.h CvPlot.h CvGlobals.h CvGameAI.h CvPlayerAI.h CvTeamAI.h CvGameCoreUtils.h CvInfos.h CvDLLInterfaceIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvArea.cpp /FoDebug/CvArea.obj

Debug/CvArtFileMgr.obj: CvArtFileMgr.cpp CvGameCoreDLL.h CvArtFileMgr.h CvXMLLoadUtility.h CvGlobals.h CvInfos.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvArtFileMgr.cpp /FoDebug/CvArtFileMgr.obj

Debug/CvBugOptions.obj: CvBugOptions.cpp CvGameCoreDLL.h CyArgsList.h CvDLLPythonIFaceBase.h FVariableSystem.h CvBugOptions.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvBugOptions.cpp /FoDebug/CvBugOptions.obj

Debug/CvCity.obj: CvCity.cpp CvGameCoreDLL.h CvGlobals.h CvCity.h CvArea.h CvGameAI.h CvMap.h CvPlot.h CvTeamAI.h CvGameCoreUtils.h CvPlayerAI.h CvUnit.h CvInfos.h CvRandom.h CvArtFileMgr.h CvPopupInfo.h CyCity.h CyArgsList.h FProfiler.h CvGameTextMgr.h CvDLLEngineIFaceBase.h CvDLLPythonIFaceBase.h CvDLLEntityIFaceBase.h CvDLLInterfaceIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvCity.cpp /FoDebug/CvCity.obj

Debug/CvCityAI.obj: CvCityAI.cpp CvGameCoreDLL.h CvGlobals.h CvGameCoreUtils.h CvCityAI.h CvGameAI.h CvPlot.h CvArea.h CvPlayerAI.h CvTeamAI.h CyCity.h CyArgsList.h CvInfos.h FProfiler.h CvDLLPythonIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLFAStarIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvCityAI.cpp /FoDebug/CvCityAI.obj

Debug/CvDLLButtonPopup.obj: CvDLLButtonPopup.cpp CvGameCoreDLL.h CvDLLButtonPopup.h CvGlobals.h CvPlayerAI.h CvGameAI.h CvTeamAI.h CvMap.h CvPlot.h CvArtFileMgr.h CyCity.h CyArgsList.h CvPopupReturn.h CvInfos.h CvInitCore.h CvGameTextMgr.h CvDLLPythonIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvGameCoreUtils.h CvDLLEngineIFaceBase.h CvEventReporter.h CvMessageControl.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDLLButtonPopup.cpp /FoDebug/CvDLLButtonPopup.obj

Debug/CvDLLEntity.obj: CvDLLEntity.cpp CvGameCoreDLL.h CvDLLEntity.h CvDLLEntityIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDLLEntity.cpp /FoDebug/CvDLLEntity.obj

Debug/CvDLLPython.obj: CvDLLPython.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyPlot.h CyGame.h CyUnit.h CyGlobalContext.h CyCity.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDLLPython.cpp /FoDebug/CvDLLPython.obj

Debug/CvDLLWidgetData.obj: CvDLLWidgetData.cpp CvGameCoreDLL.h CvGameCoreUtils.h CvCity.h CvUnit.h CvGlobals.h CvGameAI.h CvMap.h CvPlot.h CvTeamAI.h CvPlayerAI.h CvGameCoreUtils.h CyArgsList.h CvGameTextMgr.h CvDLLInterfaceIFaceBase.h CvDLLPythonIFaceBase.h CvDLLEngineIFaceBase.h CvEventReporter.h CvDLLWidgetData.h CvPopupInfo.h FProfiler.h CvMessageControl.h BugMod.h CvBugOptions.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDLLWidgetData.cpp /FoDebug/CvDLLWidgetData.obj

Debug/CvDeal.obj: CvDeal.cpp CvGameCoreDLL.h CvGlobals.h CvGameAI.h CvTeamAI.h CvPlayerAI.h CvMap.h CvPlot.h CvGameCoreUtils.h CvGameTextMgr.h CvDLLInterfaceIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDeal.cpp /FoDebug/CvDeal.obj

Debug/CvDiploParameters.obj: CvDiploParameters.cpp CvGameCoreDLL.h CvDiploParameters.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDiploParameters.cpp /FoDebug/CvDiploParameters.obj

Debug/CvDllPythonEvents.obj: CvDllPythonEvents.cpp CvGameCoreDLL.h CvDllPythonEvents.h CvDLLEngineIFaceBase.h CvDLLInterfaceIFaceBase.h CyArgsList.h CyUnit.h CyPlot.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDllPythonEvents.cpp /FoDebug/CvDllPythonEvents.obj

Debug/CvDllTranslator.obj: CvDllTranslator.cpp CvGameCoreDLL.h CvDllTranslator.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvDllTranslator.cpp /FoDebug/CvDllTranslator.obj

Debug/CvEventReporter.obj: CvEventReporter.cpp CvGameCoreDLL.h CvEventReporter.h CvDllPythonEvents.h CvInitCore.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvEventReporter.cpp /FoDebug/CvEventReporter.obj

Debug/CvFractal.obj: CvFractal.cpp CvGameCoreDLL.h CvFractal.h CvRandom.h CvGameCoreUtils.h CvGameCoreUtils.h FProfiler.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvFractal.cpp /FoDebug/CvFractal.obj

Debug/CvGame.obj: CvGame.cpp CvGameCoreDLL.h CvGameCoreUtils.h CvGame.h CvGameAI.h CvMap.h CvPlot.h CvPlayerAI.h CvRandom.h CvTeamAI.h CvGlobals.h CvInitCore.h CvMapGenerator.h CvArtFileMgr.h CvDiploParameters.h CvReplayMessage.h CyArgsList.h CvInfos.h CvPopupInfo.h FProfiler.h CvReplayInfo.h CvGameTextMgr.h CvEventReporter.h CvMessageControl.h CvDLLInterfaceIFaceBase.h CvDLLEngineIFaceBase.h CvDLLPythonIFaceBase.h CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvGame.cpp /FoDebug/CvGame.obj

Debug/CvGameAI.obj: CvGameAI.cpp CvGameCoreDLL.h CvGameAI.h CvPlayerAI.h CvTeamAI.h CvGlobals.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvGameAI.cpp /FoDebug/CvGameAI.obj

Debug/CvGameCoreDLL.obj: CvGameCoreDLL.cpp CvGameCoreDLL.h CvGameCoreDLLUndefNew.h CvGlobals.h FProfiler.h CvDLLInterfaceIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvGameCoreDLL.cpp /FoDebug/CvGameCoreDLL.obj

Debug/CvGameCoreUtils.obj: CvGameCoreUtils.cpp CvGameCoreDLL.h CvGameCoreUtils.h CvUnit.h CvGameAI.h CvPlayerAI.h CvMap.h CvPlot.h CvRandom.h FAStarNode.h CvCity.h CvTeamAI.h CvInfos.h CvGlobals.h FProfiler.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvDLLFAStarIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvGameCoreUtils.cpp /FoDebug/CvGameCoreUtils.obj

Debug/CvGameInterface.obj: CvGameInterface.cpp CvGameCoreDLL.h CvGame.h CvInitCore.h CyPlot.h CyArgsList.h CvPopupInfo.h CvDLLInterfaceIFaceBase.h CvDLLEngineIFaceBase.h CvDLLFAStarIFaceBase.h FAStarNode.h CvGameTextMgr.h CvMessageControl.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvGameInterface.cpp /FoDebug/CvGameInterface.obj

Debug/CvGameTextMgr.obj: CvGameTextMgr.cpp CvGameCoreDLL.h CvGameTextMgr.h CvGameCoreUtils.h CvDLLUtilityIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLSymbolIFaceBase.h CvInfos.h CvXMLLoadUtility.h CvCity.h CvPlayerAI.h CvTeamAI.h CvGameAI.h CvSelectionGroup.h CvMap.h CvArea.h CvPlot.h CvPopupInfo.h FProfiler.h CyArgsList.h CvDLLPythonIFaceBase.h CvBugOptions.h AdvancedCombatOdds.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvGameTextMgr.cpp /FoDebug/CvGameTextMgr.obj

Debug/CvGlobals.obj: CvGlobals.cpp CvGameCoreDLL.h CvGlobals.h CvRandom.h CvGameAI.h CvDLLInterfaceIFaceBase.h CvMap.h CvPlayerAI.h CvTeamAI.h CvInfos.h CvDLLUtilityIFaceBase.h CvArtFileMgr.h CvDLLXMLIFaceBase.h CvPlayerAI.h CvInfoWater.h CvGameTextMgr.h FProfiler.h FVariableSystem.h CvInitCore.h BugMod.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvGlobals.cpp /FoDebug/CvGlobals.obj

Debug/CvHallOfFameInfo.obj: CvHallOfFameInfo.cpp CvGameCoreDLL.h CvHallOfFameInfo.h CvGlobals.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvHallOfFameInfo.cpp /FoDebug/CvHallOfFameInfo.obj

Debug/CvInfoWater.obj: CvInfoWater.cpp CvGameCoreDLL.h CvInfoWater.h CvXMLLoadUtility.h CvDLLXMLIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvInfoWater.cpp /FoDebug/CvInfoWater.obj

Debug/CvInfos.obj: CvInfos.cpp CvGameCoreDLL.h CvInfos.h CvGlobals.h CvArtFileMgr.h CvXMLLoadUtility.h CvDLLXMLIFaceBase.h CvGameTextMgr.h CvGameCoreUtils.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvInfos.cpp /FoDebug/CvInfos.obj

Debug/CvInitCore.obj: CvInitCore.cpp CvGameCoreDLL.h CvInitCore.h CvDLLPythonIFaceBase.h CyArgsList.h CvInfos.h CvGlobals.h CvDLLUtilityIFaceBase.h CvGameAI.h CvGameCoreUtils.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvInitCore.cpp /FoDebug/CvInitCore.obj

Debug/CvMap.obj: CvMap.cpp CvGameCoreDLL.h CvMap.h CvCity.h CvPlotGroup.h CvGlobals.h CvGameAI.h CvPlayerAI.h CvRandom.h CvGameCoreUtils.h CvFractal.h CvPlot.h CvGameCoreUtils.h CvMap.h CvMapGenerator.h FAStarNode.h CvInitCore.h CvInfos.h FProfiler.h CyArgsList.h CvDLLEngineIFaceBase.h CvDLLIniParserIFaceBase.h CvDLLFAStarIFaceBase.h CvDLLFAStarIFaceBase.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvMap.cpp /FoDebug/CvMap.obj

Debug/CvMapGenerator.obj: CvMapGenerator.cpp CvGameCoreDLL.h CvMapGenerator.h CvMap.h CvFractal.h CvPlot.h CvGlobals.h CvRandom.h CvGameCoreUtils.h CvGameAI.h CvEnums.h CvInfos.h CvDLLPythonIFaceBase.h FProfiler.h CyPlot.h CyArgsList.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvMapGenerator.cpp /FoDebug/CvMapGenerator.obj

Debug/CvMessageControl.obj: CvMessageControl.cpp CvGameCoreDLL.h CvMessageControl.h CvMessageData.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvMessageControl.cpp /FoDebug/CvMessageControl.obj

Debug/CvMessageData.obj: CvMessageData.cpp CvGameCoreDLL.h CvMessageData.h FDataStreamBase.h CvDLLUtilityIFaceBase.h CvDLLInterfaceIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvMessageData.cpp /FoDebug/CvMessageData.obj

Debug/CvPlayer.obj: CvPlayer.cpp CvGameCoreDLL.h CvGlobals.h CvArea.h CvGameAI.h CvMap.h CvPlot.h CvRandom.h CvTeamAI.h CvGameCoreUtils.h CvPlayerAI.h CvPlayer.h CvGameCoreUtils.h CvArtFileMgr.h CvDiploParameters.h CvInitCore.h CyArgsList.h CvInfos.h CvPopupInfo.h CvDiploParameters.h FProfiler.h CvGameTextMgr.h CyCity.h CyPlot.h CyUnit.h CvEventReporter.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvDLLEngineIFaceBase.h CvDLLFAStarIFaceBase.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvPlayer.cpp /FoDebug/CvPlayer.obj

Debug/CvPlayerAI.obj: CvPlayerAI.cpp CvGameCoreDLL.h CvPlayerAI.h CvRandom.h CvGlobals.h CvGameCoreUtils.h CvMap.h CvArea.h CvPlot.h CvGameAI.h CvTeamAI.h CvGameCoreUtils.h CvDiploParameters.h CvInitCore.h CyArgsList.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvDLLPythonIFaceBase.h CvDLLEngineIFaceBase.h CvInfos.h CvPopupInfo.h FProfiler.h CvDLLFAStarIFaceBase.h FAStarNode.h CvEventReporter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvPlayerAI.cpp /FoDebug/CvPlayerAI.obj

Debug/CvPlot.obj: CvPlot.cpp CvGameCoreDLL.h CvPlot.h CvCity.h CvUnit.h CvGlobals.h CvArea.h CvGameAI.h CvDLLInterfaceIFaceBase.h CvDLLSymbolIFaceBase.h CvDLLEntityIFaceBase.h CvDLLPlotBuilderIFaceBase.h CvDLLEngineIFaceBase.h CvDLLFlagEntityIFaceBase.h CvMap.h CvPlayerAI.h CvTeamAI.h CvGameCoreUtils.h CvRandom.h CvDLLFAStarIFaceBase.h CvInfos.h FProfiler.h CvArtFileMgr.h CyArgsList.h CvDLLPythonIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvPlot.cpp /FoDebug/CvPlot.obj

Debug/CvPlotGroup.obj: CvPlotGroup.cpp CvGameCoreDLL.h CvPlotGroup.h CvPlot.h CvGlobals.h CvPlayerAI.h CvMap.h CvCity.h CvDLLFAStarIFaceBase.h FProfiler.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvPlotGroup.cpp /FoDebug/CvPlotGroup.obj

Debug/CvPopupInfo.obj: CvPopupInfo.cpp CvGameCoreDLL.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvPopupInfo.cpp /FoDebug/CvPopupInfo.obj

Debug/CvPopupReturn.obj: CvPopupReturn.cpp CvGameCoreDLL.h CvPopupReturn.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvPopupReturn.cpp /FoDebug/CvPopupReturn.obj

Debug/CvRandom.obj: CvRandom.cpp CvGameCoreDLL.h CvRandom.h CvGlobals.h CyArgsList.h CvGameAI.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvRandom.cpp /FoDebug/CvRandom.obj

Debug/CvReplayInfo.obj: CvReplayInfo.cpp CvGameCoreDLL.h CvReplayInfo.h CvInfos.h CvGlobals.h CvGameAI.h CvPlayerAI.h CvMap.h CvReplayMessage.h CvGameTextMgr.h CvDLLInterfaceIFaceBase.h CvInitCore.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvReplayInfo.cpp /FoDebug/CvReplayInfo.obj

Debug/CvReplayMessage.obj: CvReplayMessage.cpp CvGameCoreDLL.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvReplayMessage.cpp /FoDebug/CvReplayMessage.obj

Debug/CvSelectionGroup.obj: CvSelectionGroup.cpp CvGameCoreDLL.h CvGlobals.h CvSelectionGroup.h CvGameAI.h CvPlayerAI.h CvTeamAI.h CvUnit.h CvGameCoreUtils.h CvMap.h CvPlot.h CvDLLEntityIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLFAStarIFaceBase.h FAStarNode.h CvInfos.h FProfiler.h CyPlot.h CySelectionGroup.h CyArgsList.h CvDLLPythonIFaceBase.h CvEventReporter.h CvBugOptions.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvSelectionGroup.cpp /FoDebug/CvSelectionGroup.obj

Debug/CvSelectionGroupAI.obj: CvSelectionGroupAI.cpp CvGameCoreDLL.h CvSelectionGroupAI.h CvPlayerAI.h CvMap.h CvPlot.h CvTeamAI.h CvDLLEntityIFaceBase.h CvGameCoreUtils.h FProfiler.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvSelectionGroupAI.cpp /FoDebug/CvSelectionGroupAI.obj

Debug/CvStatistics.obj: CvStatistics.cpp CvGameCoreDLL.h CvStatistics.h CvUnit.h CvCity.h CvGlobals.h CvGameAI.h CvPlayerAI.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvStatistics.cpp /FoDebug/CvStatistics.obj

Debug/CvStructs.obj: CvStructs.cpp CvGameCoreDLL.h CvUnit.h CvStructs.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvStructs.cpp /FoDebug/CvStructs.obj

Debug/CvTalkingHeadMessage.obj: CvTalkingHeadMessage.cpp CvGameCoreDLL.h CvTalkingHeadMessage.h CvGameAI.h CvGlobals.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvTalkingHeadMessage.cpp /FoDebug/CvTalkingHeadMessage.obj

Debug/CvTeam.obj: CvTeam.cpp CvGameCoreDLL.h CvPlayerAI.h CvDefines.h CvGameCoreUtils.h CvGlobals.h CvTeamAI.h CvPlayerAI.h CvGameAI.h CvMap.h CvPlot.h CvTeam.h CvDLLInterfaceIFaceBase.h CvEventReporter.h CvDLLEngineIFaceBase.h CvArtFileMgr.h CvDiploParameters.h CvInfos.h CvPopupInfo.h CvDLLPythonIFaceBase.h CyArgsList.h FProfiler.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvTeam.cpp /FoDebug/CvTeam.obj

Debug/CvTeamAI.obj: CvTeamAI.cpp CvGameCoreDLL.h CvTeamAI.h CvPlayerAI.h CvRandom.h CvGlobals.h CvGameCoreUtils.h CvMap.h CvPlot.h CvDLLInterfaceIFaceBase.h CvGameAI.h CvInfos.h FProfiler.h CyArgsList.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvTeamAI.cpp /FoDebug/CvTeamAI.obj

Debug/CvUnit.obj: CvUnit.cpp CvGameCoreDLL.h CvUnit.h CvArea.h CvPlot.h CvCity.h CvGlobals.h CvGameCoreUtils.h CvGameAI.h CvMap.h CvPlayerAI.h CvRandom.h CvTeamAI.h CvGameCoreUtils.h CyUnit.h CyArgsList.h CyPlot.h CvDLLEntityIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLEngineIFaceBase.h CvEventReporter.h CvDLLPythonIFaceBase.h CvDLLFAStarIFaceBase.h CvInfos.h FProfiler.h CvPopupInfo.h CvArtFileMgr.h CvBugOptions.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvUnit.cpp /FoDebug/CvUnit.obj

Debug/CvUnitAI.obj: CvUnitAI.cpp CvGameCoreDLL.h CvUnitAI.h CvMap.h CvArea.h CvPlot.h CvGlobals.h CvGameAI.h CvTeamAI.h CvPlayerAI.h CvGameCoreUtils.h CvRandom.h CyUnit.h CyArgsList.h CvDLLPythonIFaceBase.h CvInfos.h FProfiler.h FAStarNode.h CvDLLInterfaceIFaceBase.h CvDLLFAStarIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvUnitAI.cpp /FoDebug/CvUnitAI.obj

Debug/CvXMLLoadUtility.obj: CvXMLLoadUtility.cpp CvGameCoreDLL.h CvDLLXMLIFaceBase.h CvXMLLoadUtility.h CvGlobals.h FProfiler.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvXMLLoadUtility.cpp /FoDebug/CvXMLLoadUtility.obj

Debug/CvXMLLoadUtilityGet.obj: CvXMLLoadUtilityGet.cpp CvGameCoreDLL.h CvDLLXMLIFaceBase.h CvXMLLoadUtility.h CvGlobals.h CvArtFileMgr.h FInputDevice.h FProfiler.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvXMLLoadUtilityGet.cpp /FoDebug/CvXMLLoadUtilityGet.obj

Debug/CvXMLLoadUtilityInit.obj: CvXMLLoadUtilityInit.cpp CvGameCoreDLL.h CvXMLLoadUtility.h CvGlobals.h CvArtFileMgr.h CvGameTextMgr.h CvInfoWater.h FProfiler.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvXMLLoadUtilityInit.cpp /FoDebug/CvXMLLoadUtilityInit.obj

Debug/CvXMLLoadUtilitySet.obj: CvXMLLoadUtilitySet.cpp CvGameCoreDLL.h CvDLLXMLIFaceBase.h CvXMLLoadUtility.h CvGlobals.h CvArtFileMgr.h CvGameTextMgr.h CvInfoWater.h FProfiler.h FVariableSystem.h CvGameCoreUtils.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CvXMLLoadUtilitySet.cpp /FoDebug/CvXMLLoadUtilitySet.obj

Debug/CyArea.obj: CyArea.cpp CvGameCoreDLL.h CyCity.h CyArea.h CvArea.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyArea.cpp /FoDebug/CyArea.obj

Debug/CyAreaInterface.obj: CyAreaInterface.cpp CvGameCoreDLL.h CyArea.h CyCity.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyAreaInterface.cpp /FoDebug/CyAreaInterface.obj

Debug/CyArgsList.obj: CyArgsList.cpp CvGameCoreDLL.h CyArgsList.h CyGlobalContext.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyArgsList.cpp /FoDebug/CyArgsList.obj

Debug/CyArtFileMgr.obj: CyArtFileMgr.cpp CvGameCoreDLL.h CyArtFileMgr.h CvArtFileMgr.h CyGlobalContext.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyArtFileMgr.cpp /FoDebug/CyArtFileMgr.obj

Debug/CyArtFileMgrInterface.obj: CyArtFileMgrInterface.cpp CvGameCoreDLL.h CyArtFileMgr.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyArtFileMgrInterface.cpp /FoDebug/CyArtFileMgrInterface.obj

Debug/CyCity.obj: CyCity.cpp CvGameCoreDLL.h CyCity.h CvCity.h CyPlot.h CyArea.h CyUnit.h CvDLLPythonIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyCity.cpp /FoDebug/CyCity.obj

Debug/CyCityInterface1.obj: CyCityInterface1.cpp CvGameCoreDLL.h CyCity.h CyPlot.h CyArea.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyCityInterface1.cpp /FoDebug/CyCityInterface1.obj

Debug/CyDeal.obj: CyDeal.cpp CvGameCoreDLL.h CyDeal.h CvDeal.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyDeal.cpp /FoDebug/CyDeal.obj

Debug/CyEnumsInterface.obj: CyEnumsInterface.cpp CvGameCoreDLL.h CvGameCoreDLLDefNew.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyEnumsInterface.cpp /FoDebug/CyEnumsInterface.obj

Debug/CyGame.obj: CyGame.cpp CvGameCoreDLL.h CyGame.h CvGameAI.h CyGlobalContext.h CyPlayer.h CvEnums.h CyCity.h CyDeal.h CyReplayInfo.h CvReplayInfo.h CyPlot.h CvDLLEngineIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGame.cpp /FoDebug/CyGame.obj

Debug/CyGameCoreUtils.obj: CyGameCoreUtils.cpp CvGameCoreDLL.h CyGameCoreUtils.h CvGameCoreUtils.h CyPlot.h CyCity.h CyUnit.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGameCoreUtils.cpp /FoDebug/CyGameCoreUtils.obj

Debug/CyGameCoreUtilsInterface.obj: CyGameCoreUtilsInterface.cpp CvGameCoreDLL.h CyGameCoreUtils.h CyPlot.h CyCity.h CyUnit.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGameCoreUtilsInterface.cpp /FoDebug/CyGameCoreUtilsInterface.obj

Debug/CyGameInterface.obj: CyGameInterface.cpp CvGameCoreDLL.h CyGame.h CvRandom.h CyCity.h CyDeal.h CyReplayInfo.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGameInterface.cpp /FoDebug/CyGameInterface.obj

Debug/CyGameTextMgr.obj: CyGameTextMgr.cpp CvGameCoreDLL.h CvGameTextMgr.h CyGameTextMgr.h CyCity.h CyDeal.h CyUnit.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGameTextMgr.cpp /FoDebug/CyGameTextMgr.obj

Debug/CyGameTextMgrInterface.obj: CyGameTextMgrInterface.cpp CvGameCoreDLL.h CyGameTextMgr.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGameTextMgrInterface.cpp /FoDebug/CyGameTextMgrInterface.obj

Debug/CyGlobalContext.obj: CyGlobalContext.cpp CvGameCoreDLL.h CyGlobalContext.h CyGame.h CyPlayer.h CyMap.h CvGlobals.h CvPlayerAI.h CvGameAI.h CvStructs.h CvInfos.h CyTeam.h CvTeamAI.h CyArtFileMgr.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGlobalContext.cpp /FoDebug/CyGlobalContext.obj

Debug/CyGlobalContextInterface1.obj: CyGlobalContextInterface1.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGlobalContextInterface1.cpp /FoDebug/CyGlobalContextInterface1.obj

Debug/CyGlobalContextInterface2.obj: CyGlobalContextInterface2.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGlobalContextInterface2.cpp /FoDebug/CyGlobalContextInterface2.obj

Debug/CyGlobalContextInterface3.obj: CyGlobalContextInterface3.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGlobalContextInterface3.cpp /FoDebug/CyGlobalContextInterface3.obj

Debug/CyGlobalContextInterface4.obj: CyGlobalContextInterface4.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyGlobalContextInterface4.cpp /FoDebug/CyGlobalContextInterface4.obj

Debug/CyHallOfFameInfo.obj: CyHallOfFameInfo.cpp CvGameCoreDLL.h CyHallOfFameInfo.h CyReplayInfo.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyHallOfFameInfo.cpp /FoDebug/CyHallOfFameInfo.obj

Debug/CyHallOfFameInterface.obj: CyHallOfFameInterface.cpp CvGameCoreDLL.h CyReplayInfo.h CyHallOfFameInfo.h CyMap.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyHallOfFameInterface.cpp /FoDebug/CyHallOfFameInterface.obj

Debug/CyInfoInterface1.obj: CyInfoInterface1.cpp CvGameCoreDLL.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyInfoInterface1.cpp /FoDebug/CyInfoInterface1.obj

Debug/CyInfoInterface2.obj: CyInfoInterface2.cpp CvGameCoreDLL.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyInfoInterface2.cpp /FoDebug/CyInfoInterface2.obj

Debug/CyInfoInterface3.obj: CyInfoInterface3.cpp CvGameCoreDLL.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyInfoInterface3.cpp /FoDebug/CyInfoInterface3.obj

Debug/CyMap.obj: CyMap.cpp CvGameCoreDLL.h CyPlot.h CvMap.h CyCity.h CySelectionGroup.h CyUnit.h CyArea.h CvGlobals.h CvMapGenerator.h CvInitCore.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyMap.cpp /FoDebug/CyMap.obj

Debug/CyMapGenerator.obj: CyMapGenerator.cpp CvGameCoreDLL.h CyMapGenerator.h CvGlobals.h CvDLLPythonIFaceBase.h CvMapGenerator.h CyPlot.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyMapGenerator.cpp /FoDebug/CyMapGenerator.obj

Debug/CyMapGeneratorInterface.obj: CyMapGeneratorInterface.cpp CvGameCoreDLL.h CyMapGenerator.h CvStructs.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyMapGeneratorInterface.cpp /FoDebug/CyMapGeneratorInterface.obj

Debug/CyMapInterface.obj: CyMapInterface.cpp CvGameCoreDLL.h CyMap.h CyArea.h CyCity.h CySelectionGroup.h CyUnit.h CyPlot.h CvStructs.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyMapInterface.cpp /FoDebug/CyMapInterface.obj

Debug/CyMessageControl.obj: CyMessageControl.cpp CvGameCoreDLL.h CyMessageControl.h CvMessageControl.h CvDLLPythonIFaceBase.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyMessageControl.cpp /FoDebug/CyMessageControl.obj

Debug/CyMessageControlInterface.obj: CyMessageControlInterface.cpp CvGameCoreDLL.h CyMessageControl.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyMessageControlInterface.cpp /FoDebug/CyMessageControlInterface.obj

Debug/CyPlayer.obj: CyPlayer.cpp CvGameCoreDLL.h CyPlayer.h CyUnit.h CyCity.h CyArea.h CyPlot.h CvPlayerAI.h CvEnums.h CvCity.h CvMap.h CvPlot.h CySelectionGroup.h CvDLLPythonIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyPlayer.cpp /FoDebug/CyPlayer.obj

Debug/CyPlayerInterface1.obj: CyPlayerInterface1.cpp CvGameCoreDLL.h CyPlayer.h CyUnit.h CyCity.h CyPlot.h CySelectionGroup.h CyArea.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyPlayerInterface1.cpp /FoDebug/CyPlayerInterface1.obj

Debug/CyPlayerInterface2.obj: CyPlayerInterface2.cpp CvGameCoreDLL.h CyPlayer.h CyUnit.h CyCity.h CyPlot.h CySelectionGroup.h CyArea.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyPlayerInterface2.cpp /FoDebug/CyPlayerInterface2.obj

Debug/CyPlot.obj: CyPlot.cpp CvGameCoreDLL.h CyPlot.h CyCity.h CyArea.h CyUnit.h CvPlot.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyPlot.cpp /FoDebug/CyPlot.obj

Debug/CyPlotInterface1.obj: CyPlotInterface1.cpp CvGameCoreDLL.h CyPlot.h CyCity.h CyArea.h CyUnit.h CvPlot.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyPlotInterface1.cpp /FoDebug/CyPlotInterface1.obj

Debug/CyRandomInterface.obj: CyRandomInterface.cpp CvGameCoreDLL.h CvRandom.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyRandomInterface.cpp /FoDebug/CyRandomInterface.obj

Debug/CyReplayInfo.obj: CyReplayInfo.cpp CvGameCoreDLL.h CyReplayInfo.h CyMap.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyReplayInfo.cpp /FoDebug/CyReplayInfo.obj

Debug/CySelectionGroup.obj: CySelectionGroup.cpp CvGameCoreDLL.h CySelectionGroup.h CvSelectionGroup.h CvPlot.h CyPlot.h CvArea.h CyArea.h CyUnit.h CvStructs.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CySelectionGroup.cpp /FoDebug/CySelectionGroup.obj

Debug/CySelectionGroupInterface.obj: CySelectionGroupInterface.cpp CvGameCoreDLL.h CySelectionGroup.h CyPlot.h CyArea.h CyUnit.h CvStructs.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CySelectionGroupInterface.cpp /FoDebug/CySelectionGroupInterface.obj

Debug/CyStructsInterface1.obj: CyStructsInterface1.cpp CvGameCoreDLL.h CvUnit.h CvStructs.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyStructsInterface1.cpp /FoDebug/CyStructsInterface1.obj

Debug/CyTeam.obj: CyTeam.cpp CvGameCoreDLL.h CyTeam.h CyArea.h CvTeam.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyTeam.cpp /FoDebug/CyTeam.obj

Debug/CyTeamInterface.obj: CyTeamInterface.cpp CvGameCoreDLL.h CyArea.h CyTeam.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyTeamInterface.cpp /FoDebug/CyTeamInterface.obj

Debug/CyUnit.obj: CyUnit.cpp CvGameCoreDLL.h CyUnit.h CyCity.h CvArea.h CvPlot.h CvUnit.h CyPlot.h CyArea.h CvArtFileMgr.h CySelectionGroup.h CvDLLInterfaceIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyUnit.cpp /FoDebug/CyUnit.obj

Debug/CyUnitInterface1.obj: CyUnitInterface1.cpp CvGameCoreDLL.h CyUnit.h CyCity.h CyPlot.h CyArea.h CySelectionGroup.h CyArtFileMgr.h CvInfos.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CyUnitInterface1.cpp /FoDebug/CyUnitInterface1.obj

Debug/FAssert.obj: FAssert.cpp FDialogTemplate.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c FAssert.cpp /FoDebug/FAssert.obj

Debug/FDialogTemplate.obj: FDialogTemplate.cpp FDialogTemplate.h CvGameCoreDLLUndefNew.h CvGameCoreDLLUndefNew.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c FDialogTemplate.cpp /FoDebug/FDialogTemplate.obj

Debug/_precompile.obj: _precompile.cpp CvGameCoreDLL.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c _precompile.cpp /FoDebug/_precompile.obj

Debug/CxImage/general/tif_xfile.obj: CxImage/general/tif_xfile.cpp CxImage/general/ximage.h CxImage/general/xfile.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/tif_xfile.cpp /FoDebug/CxImage/general/tif_xfile.obj

Debug/CxImage/general/ximabmp.obj: CxImage/general/ximabmp.cpp CxImage/general/ximabmp.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximabmp.cpp /FoDebug/CxImage/general/ximabmp.obj

Debug/CxImage/general/ximadsp.obj: CxImage/general/ximadsp.cpp CxImage/general/ximage.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximadsp.cpp /FoDebug/CxImage/general/ximadsp.obj

Debug/CxImage/general/ximaenc.obj: CxImage/general/ximaenc.cpp CxImage/general/ximage.h CxImage/general/ximajpg.h CxImage/general/ximagif.h CxImage/general/ximapng.h CxImage/general/ximamng.h CxImage/general/ximabmp.h CxImage/general/ximaico.h CxImage/general/ximatif.h CxImage/general/ximatga.h CxImage/general/ximapcx.h CxImage/general/ximawbmp.h CxImage/general/ximawmf.h CxImage/general/ximaj2k.h CxImage/general/ximajbg.h CxImage/general/ximajas.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximaenc.cpp /FoDebug/CxImage/general/ximaenc.obj

Debug/CxImage/general/ximaexif.obj: CxImage/general/ximaexif.cpp CxImage/general/ximajpg.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximaexif.cpp /FoDebug/CxImage/general/ximaexif.obj

Debug/CxImage/general/ximage.obj: CxImage/general/ximage.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximage.cpp /FoDebug/CxImage/general/ximage.obj

Debug/CxImage/general/ximagif.obj: CxImage/general/ximagif.cpp CxImage/general/ximagif.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximagif.cpp /FoDebug/CxImage/general/ximagif.obj

Debug/CxImage/general/ximahist.obj: CxImage/general/ximahist.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximahist.cpp /FoDebug/CxImage/general/ximahist.obj

Debug/CxImage/general/ximaico.obj: CxImage/general/ximaico.cpp CxImage/general/ximaico.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximaico.cpp /FoDebug/CxImage/general/ximaico.obj

Debug/CxImage/general/ximainfo.obj: CxImage/general/ximainfo.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximainfo.cpp /FoDebug/CxImage/general/ximainfo.obj

Debug/CxImage/general/ximaint.obj: CxImage/general/ximaint.cpp CxImage/general/ximage.h CxImage/general/ximath.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximaint.cpp /FoDebug/CxImage/general/ximaint.obj

Debug/CxImage/general/ximaj2k.obj: CxImage/general/ximaj2k.cpp CxImage/general/ximaj2k.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximaj2k.cpp /FoDebug/CxImage/general/ximaj2k.obj

Debug/CxImage/general/ximajas.obj: CxImage/general/ximajas.cpp CxImage/general/ximajas.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximajas.cpp /FoDebug/CxImage/general/ximajas.obj

Debug/CxImage/general/ximajbg.obj: CxImage/general/ximajbg.cpp CxImage/general/ximajbg.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximajbg.cpp /FoDebug/CxImage/general/ximajbg.obj

Debug/CxImage/general/ximajpg.obj: CxImage/general/ximajpg.cpp CxImage/general/ximajpg.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximajpg.cpp /FoDebug/CxImage/general/ximajpg.obj

Debug/CxImage/general/ximalpha.obj: CxImage/general/ximalpha.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximalpha.cpp /FoDebug/CxImage/general/ximalpha.obj

Debug/CxImage/general/ximalyr.obj: CxImage/general/ximalyr.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximalyr.cpp /FoDebug/CxImage/general/ximalyr.obj

Debug/CxImage/general/ximamng.obj: CxImage/general/ximamng.cpp CxImage/general/ximamng.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximamng.cpp /FoDebug/CxImage/general/ximamng.obj

Debug/CxImage/general/ximapal.obj: CxImage/general/ximapal.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximapal.cpp /FoDebug/CxImage/general/ximapal.obj

Debug/CxImage/general/ximapcx.obj: CxImage/general/ximapcx.cpp CxImage/general/ximapcx.h CxImage/general/xmemfile.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximapcx.cpp /FoDebug/CxImage/general/ximapcx.obj

Debug/CxImage/general/ximapng.obj: CxImage/general/ximapng.cpp CxImage/general/ximapng.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximapng.cpp /FoDebug/CxImage/general/ximapng.obj

Debug/CxImage/general/ximasel.obj: CxImage/general/ximasel.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximasel.cpp /FoDebug/CxImage/general/ximasel.obj

Debug/CxImage/general/ximatga.obj: CxImage/general/ximatga.cpp CxImage/general/ximatga.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximatga.cpp /FoDebug/CxImage/general/ximatga.obj

Debug/CxImage/general/ximath.obj: CxImage/general/ximath.cpp CxImage/general/ximage.h CxImage/general/ximath.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximath.cpp /FoDebug/CxImage/general/ximath.obj

Debug/CxImage/general/ximatif.obj: CxImage/general/ximatif.cpp CxImage/general/ximatif.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximatif.cpp /FoDebug/CxImage/general/ximatif.obj

Debug/CxImage/general/ximatran.obj: CxImage/general/ximatran.cpp CxImage/general/ximage.h CxImage/general/ximath.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximatran.cpp /FoDebug/CxImage/general/ximatran.obj

Debug/CxImage/general/ximawbmp.obj: CxImage/general/ximawbmp.cpp CxImage/general/ximawbmp.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximawbmp.cpp /FoDebug/CxImage/general/ximawbmp.obj

Debug/CxImage/general/ximawmf.obj: CxImage/general/ximawmf.cpp CxImage/general/ximawmf.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximawmf.cpp /FoDebug/CxImage/general/ximawmf.obj

Debug/CxImage/general/ximawnd.obj: CxImage/general/ximawnd.cpp CxImage/general/ximage.h CxImage/general/ximaiter.h CxImage/general/ximabmp.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/ximawnd.cpp /FoDebug/CxImage/general/ximawnd.obj

Debug/CxImage/general/xmemfile.obj: CxImage/general/xmemfile.cpp CxImage/general/xmemfile.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/general/xmemfile.cpp /FoDebug/CxImage/general/xmemfile.obj

Debug/CxImage/jpeg/jcapimin.obj: CxImage/jpeg/jcapimin.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcapimin.c /FoDebug/CxImage/jpeg/jcapimin.obj

Debug/CxImage/jpeg/jcapistd.obj: CxImage/jpeg/jcapistd.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcapistd.c /FoDebug/CxImage/jpeg/jcapistd.obj

Debug/CxImage/jpeg/jccoefct.obj: CxImage/jpeg/jccoefct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jccoefct.c /FoDebug/CxImage/jpeg/jccoefct.obj

Debug/CxImage/jpeg/jccolor.obj: CxImage/jpeg/jccolor.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jccolor.c /FoDebug/CxImage/jpeg/jccolor.obj

Debug/CxImage/jpeg/jcdctmgr.obj: CxImage/jpeg/jcdctmgr.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcdctmgr.c /FoDebug/CxImage/jpeg/jcdctmgr.obj

Debug/CxImage/jpeg/jchuff.obj: CxImage/jpeg/jchuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jchuff.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jchuff.c /FoDebug/CxImage/jpeg/jchuff.obj

Debug/CxImage/jpeg/jcinit.obj: CxImage/jpeg/jcinit.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcinit.c /FoDebug/CxImage/jpeg/jcinit.obj

Debug/CxImage/jpeg/jcmainct.obj: CxImage/jpeg/jcmainct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcmainct.c /FoDebug/CxImage/jpeg/jcmainct.obj

Debug/CxImage/jpeg/jcmarker.obj: CxImage/jpeg/jcmarker.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcmarker.c /FoDebug/CxImage/jpeg/jcmarker.obj

Debug/CxImage/jpeg/jcmaster.obj: CxImage/jpeg/jcmaster.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcmaster.c /FoDebug/CxImage/jpeg/jcmaster.obj

Debug/CxImage/jpeg/jcomapi.obj: CxImage/jpeg/jcomapi.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcomapi.c /FoDebug/CxImage/jpeg/jcomapi.obj

Debug/CxImage/jpeg/jcparam.obj: CxImage/jpeg/jcparam.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcparam.c /FoDebug/CxImage/jpeg/jcparam.obj

Debug/CxImage/jpeg/jcphuff.obj: CxImage/jpeg/jcphuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jchuff.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcphuff.c /FoDebug/CxImage/jpeg/jcphuff.obj

Debug/CxImage/jpeg/jcprepct.obj: CxImage/jpeg/jcprepct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcprepct.c /FoDebug/CxImage/jpeg/jcprepct.obj

Debug/CxImage/jpeg/jcsample.obj: CxImage/jpeg/jcsample.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jcsample.c /FoDebug/CxImage/jpeg/jcsample.obj

Debug/CxImage/jpeg/jctrans.obj: CxImage/jpeg/jctrans.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jctrans.c /FoDebug/CxImage/jpeg/jctrans.obj

Debug/CxImage/jpeg/jdapimin.obj: CxImage/jpeg/jdapimin.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdapimin.c /FoDebug/CxImage/jpeg/jdapimin.obj

Debug/CxImage/jpeg/jdapistd.obj: CxImage/jpeg/jdapistd.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdapistd.c /FoDebug/CxImage/jpeg/jdapistd.obj

Debug/CxImage/jpeg/jdatadst.obj: CxImage/jpeg/jdatadst.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jerror.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdatadst.c /FoDebug/CxImage/jpeg/jdatadst.obj

Debug/CxImage/jpeg/jdatasrc.obj: CxImage/jpeg/jdatasrc.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jerror.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdatasrc.c /FoDebug/CxImage/jpeg/jdatasrc.obj

Debug/CxImage/jpeg/jdcoefct.obj: CxImage/jpeg/jdcoefct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdcoefct.c /FoDebug/CxImage/jpeg/jdcoefct.obj

Debug/CxImage/jpeg/jdcolor.obj: CxImage/jpeg/jdcolor.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdcolor.c /FoDebug/CxImage/jpeg/jdcolor.obj

Debug/CxImage/jpeg/jddctmgr.obj: CxImage/jpeg/jddctmgr.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jddctmgr.c /FoDebug/CxImage/jpeg/jddctmgr.obj

Debug/CxImage/jpeg/jdhuff.obj: CxImage/jpeg/jdhuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdhuff.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdhuff.c /FoDebug/CxImage/jpeg/jdhuff.obj

Debug/CxImage/jpeg/jdinput.obj: CxImage/jpeg/jdinput.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdinput.c /FoDebug/CxImage/jpeg/jdinput.obj

Debug/CxImage/jpeg/jdmainct.obj: CxImage/jpeg/jdmainct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdmainct.c /FoDebug/CxImage/jpeg/jdmainct.obj

Debug/CxImage/jpeg/jdmarker.obj: CxImage/jpeg/jdmarker.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdmarker.c /FoDebug/CxImage/jpeg/jdmarker.obj

Debug/CxImage/jpeg/jdmaster.obj: CxImage/jpeg/jdmaster.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdmaster.c /FoDebug/CxImage/jpeg/jdmaster.obj

Debug/CxImage/jpeg/jdmerge.obj: CxImage/jpeg/jdmerge.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdmerge.c /FoDebug/CxImage/jpeg/jdmerge.obj

Debug/CxImage/jpeg/jdphuff.obj: CxImage/jpeg/jdphuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdhuff.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdphuff.c /FoDebug/CxImage/jpeg/jdphuff.obj

Debug/CxImage/jpeg/jdpostct.obj: CxImage/jpeg/jdpostct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdpostct.c /FoDebug/CxImage/jpeg/jdpostct.obj

Debug/CxImage/jpeg/jdsample.obj: CxImage/jpeg/jdsample.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdsample.c /FoDebug/CxImage/jpeg/jdsample.obj

Debug/CxImage/jpeg/jdtrans.obj: CxImage/jpeg/jdtrans.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jdtrans.c /FoDebug/CxImage/jpeg/jdtrans.obj

Debug/CxImage/jpeg/jerror.obj: CxImage/jpeg/jerror.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jversion.h CxImage/jpeg/jerror.h CxImage/jpeg/jerror.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jerror.c /FoDebug/CxImage/jpeg/jerror.obj

Debug/CxImage/jpeg/jfdctflt.obj: CxImage/jpeg/jfdctflt.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jfdctflt.c /FoDebug/CxImage/jpeg/jfdctflt.obj

Debug/CxImage/jpeg/jfdctfst.obj: CxImage/jpeg/jfdctfst.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jfdctfst.c /FoDebug/CxImage/jpeg/jfdctfst.obj

Debug/CxImage/jpeg/jfdctint.obj: CxImage/jpeg/jfdctint.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jfdctint.c /FoDebug/CxImage/jpeg/jfdctint.obj

Debug/CxImage/jpeg/jidctflt.obj: CxImage/jpeg/jidctflt.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jidctflt.c /FoDebug/CxImage/jpeg/jidctflt.obj

Debug/CxImage/jpeg/jidctfst.obj: CxImage/jpeg/jidctfst.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jidctfst.c /FoDebug/CxImage/jpeg/jidctfst.obj

Debug/CxImage/jpeg/jidctint.obj: CxImage/jpeg/jidctint.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jidctint.c /FoDebug/CxImage/jpeg/jidctint.obj

Debug/CxImage/jpeg/jidctred.obj: CxImage/jpeg/jidctred.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jidctred.c /FoDebug/CxImage/jpeg/jidctred.obj

Debug/CxImage/jpeg/jmemmgr.obj: CxImage/jpeg/jmemmgr.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jmemsys.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jmemmgr.c /FoDebug/CxImage/jpeg/jmemmgr.obj

Debug/CxImage/jpeg/jmemnobs.obj: CxImage/jpeg/jmemnobs.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jmemsys.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jmemnobs.c /FoDebug/CxImage/jpeg/jmemnobs.obj

Debug/CxImage/jpeg/jquant1.obj: CxImage/jpeg/jquant1.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jquant1.c /FoDebug/CxImage/jpeg/jquant1.obj

Debug/CxImage/jpeg/jquant2.obj: CxImage/jpeg/jquant2.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jquant2.c /FoDebug/CxImage/jpeg/jquant2.obj

Debug/CxImage/jpeg/jutils.obj: CxImage/jpeg/jutils.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Debug_CFLAGS) $(Debug_INCS) /c CxImage/jpeg/jutils.c /FoDebug/CxImage/jpeg/jutils.obj


## Target: Final_Release

Final_Release/CvArea.obj: CvArea.cpp CvGameCoreDLL.h CvArea.h CvMap.h CvPlot.h CvGlobals.h CvGameAI.h CvPlayerAI.h CvTeamAI.h CvGameCoreUtils.h CvInfos.h CvDLLInterfaceIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvArea.cpp /FoFinal_Release/CvArea.obj

Final_Release/CvArtFileMgr.obj: CvArtFileMgr.cpp CvGameCoreDLL.h CvArtFileMgr.h CvXMLLoadUtility.h CvGlobals.h CvInfos.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvArtFileMgr.cpp /FoFinal_Release/CvArtFileMgr.obj

Final_Release/CvBugOptions.obj: CvBugOptions.cpp CvGameCoreDLL.h CyArgsList.h CvDLLPythonIFaceBase.h FVariableSystem.h CvBugOptions.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvBugOptions.cpp /FoFinal_Release/CvBugOptions.obj

Final_Release/CvCity.obj: CvCity.cpp CvGameCoreDLL.h CvGlobals.h CvCity.h CvArea.h CvGameAI.h CvMap.h CvPlot.h CvTeamAI.h CvGameCoreUtils.h CvPlayerAI.h CvUnit.h CvInfos.h CvRandom.h CvArtFileMgr.h CvPopupInfo.h CyCity.h CyArgsList.h FProfiler.h CvGameTextMgr.h CvDLLEngineIFaceBase.h CvDLLPythonIFaceBase.h CvDLLEntityIFaceBase.h CvDLLInterfaceIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvCity.cpp /FoFinal_Release/CvCity.obj

Final_Release/CvCityAI.obj: CvCityAI.cpp CvGameCoreDLL.h CvGlobals.h CvGameCoreUtils.h CvCityAI.h CvGameAI.h CvPlot.h CvArea.h CvPlayerAI.h CvTeamAI.h CyCity.h CyArgsList.h CvInfos.h FProfiler.h CvDLLPythonIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLFAStarIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvCityAI.cpp /FoFinal_Release/CvCityAI.obj

Final_Release/CvDLLButtonPopup.obj: CvDLLButtonPopup.cpp CvGameCoreDLL.h CvDLLButtonPopup.h CvGlobals.h CvPlayerAI.h CvGameAI.h CvTeamAI.h CvMap.h CvPlot.h CvArtFileMgr.h CyCity.h CyArgsList.h CvPopupReturn.h CvInfos.h CvInitCore.h CvGameTextMgr.h CvDLLPythonIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvGameCoreUtils.h CvDLLEngineIFaceBase.h CvEventReporter.h CvMessageControl.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDLLButtonPopup.cpp /FoFinal_Release/CvDLLButtonPopup.obj

Final_Release/CvDLLEntity.obj: CvDLLEntity.cpp CvGameCoreDLL.h CvDLLEntity.h CvDLLEntityIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDLLEntity.cpp /FoFinal_Release/CvDLLEntity.obj

Final_Release/CvDLLPython.obj: CvDLLPython.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyPlot.h CyGame.h CyUnit.h CyGlobalContext.h CyCity.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDLLPython.cpp /FoFinal_Release/CvDLLPython.obj

Final_Release/CvDLLWidgetData.obj: CvDLLWidgetData.cpp CvGameCoreDLL.h CvGameCoreUtils.h CvCity.h CvUnit.h CvGlobals.h CvGameAI.h CvMap.h CvPlot.h CvTeamAI.h CvPlayerAI.h CvGameCoreUtils.h CyArgsList.h CvGameTextMgr.h CvDLLInterfaceIFaceBase.h CvDLLPythonIFaceBase.h CvDLLEngineIFaceBase.h CvEventReporter.h CvDLLWidgetData.h CvPopupInfo.h FProfiler.h CvMessageControl.h BugMod.h CvBugOptions.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDLLWidgetData.cpp /FoFinal_Release/CvDLLWidgetData.obj

Final_Release/CvDeal.obj: CvDeal.cpp CvGameCoreDLL.h CvGlobals.h CvGameAI.h CvTeamAI.h CvPlayerAI.h CvMap.h CvPlot.h CvGameCoreUtils.h CvGameTextMgr.h CvDLLInterfaceIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDeal.cpp /FoFinal_Release/CvDeal.obj

Final_Release/CvDiploParameters.obj: CvDiploParameters.cpp CvGameCoreDLL.h CvDiploParameters.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDiploParameters.cpp /FoFinal_Release/CvDiploParameters.obj

Final_Release/CvDllPythonEvents.obj: CvDllPythonEvents.cpp CvGameCoreDLL.h CvDllPythonEvents.h CvDLLEngineIFaceBase.h CvDLLInterfaceIFaceBase.h CyArgsList.h CyUnit.h CyPlot.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDllPythonEvents.cpp /FoFinal_Release/CvDllPythonEvents.obj

Final_Release/CvDllTranslator.obj: CvDllTranslator.cpp CvGameCoreDLL.h CvDllTranslator.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvDllTranslator.cpp /FoFinal_Release/CvDllTranslator.obj

Final_Release/CvEventReporter.obj: CvEventReporter.cpp CvGameCoreDLL.h CvEventReporter.h CvDllPythonEvents.h CvInitCore.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvEventReporter.cpp /FoFinal_Release/CvEventReporter.obj

Final_Release/CvFractal.obj: CvFractal.cpp CvGameCoreDLL.h CvFractal.h CvRandom.h CvGameCoreUtils.h CvGameCoreUtils.h FProfiler.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvFractal.cpp /FoFinal_Release/CvFractal.obj

Final_Release/CvGame.obj: CvGame.cpp CvGameCoreDLL.h CvGameCoreUtils.h CvGame.h CvGameAI.h CvMap.h CvPlot.h CvPlayerAI.h CvRandom.h CvTeamAI.h CvGlobals.h CvInitCore.h CvMapGenerator.h CvArtFileMgr.h CvDiploParameters.h CvReplayMessage.h CyArgsList.h CvInfos.h CvPopupInfo.h FProfiler.h CvReplayInfo.h CvGameTextMgr.h CvEventReporter.h CvMessageControl.h CvDLLInterfaceIFaceBase.h CvDLLEngineIFaceBase.h CvDLLPythonIFaceBase.h CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvGame.cpp /FoFinal_Release/CvGame.obj

Final_Release/CvGameAI.obj: CvGameAI.cpp CvGameCoreDLL.h CvGameAI.h CvPlayerAI.h CvTeamAI.h CvGlobals.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvGameAI.cpp /FoFinal_Release/CvGameAI.obj

Final_Release/CvGameCoreDLL.obj: CvGameCoreDLL.cpp CvGameCoreDLL.h CvGameCoreDLLUndefNew.h CvGlobals.h FProfiler.h CvDLLInterfaceIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvGameCoreDLL.cpp /FoFinal_Release/CvGameCoreDLL.obj

Final_Release/CvGameCoreUtils.obj: CvGameCoreUtils.cpp CvGameCoreDLL.h CvGameCoreUtils.h CvUnit.h CvGameAI.h CvPlayerAI.h CvMap.h CvPlot.h CvRandom.h FAStarNode.h CvCity.h CvTeamAI.h CvInfos.h CvGlobals.h FProfiler.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvDLLFAStarIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvGameCoreUtils.cpp /FoFinal_Release/CvGameCoreUtils.obj

Final_Release/CvGameInterface.obj: CvGameInterface.cpp CvGameCoreDLL.h CvGame.h CvInitCore.h CyPlot.h CyArgsList.h CvPopupInfo.h CvDLLInterfaceIFaceBase.h CvDLLEngineIFaceBase.h CvDLLFAStarIFaceBase.h FAStarNode.h CvGameTextMgr.h CvMessageControl.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvGameInterface.cpp /FoFinal_Release/CvGameInterface.obj

Final_Release/CvGameTextMgr.obj: CvGameTextMgr.cpp CvGameCoreDLL.h CvGameTextMgr.h CvGameCoreUtils.h CvDLLUtilityIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLSymbolIFaceBase.h CvInfos.h CvXMLLoadUtility.h CvCity.h CvPlayerAI.h CvTeamAI.h CvGameAI.h CvSelectionGroup.h CvMap.h CvArea.h CvPlot.h CvPopupInfo.h FProfiler.h CyArgsList.h CvDLLPythonIFaceBase.h CvBugOptions.h AdvancedCombatOdds.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvGameTextMgr.cpp /FoFinal_Release/CvGameTextMgr.obj

Final_Release/CvGlobals.obj: CvGlobals.cpp CvGameCoreDLL.h CvGlobals.h CvRandom.h CvGameAI.h CvDLLInterfaceIFaceBase.h CvMap.h CvPlayerAI.h CvTeamAI.h CvInfos.h CvDLLUtilityIFaceBase.h CvArtFileMgr.h CvDLLXMLIFaceBase.h CvPlayerAI.h CvInfoWater.h CvGameTextMgr.h FProfiler.h FVariableSystem.h CvInitCore.h BugMod.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvGlobals.cpp /FoFinal_Release/CvGlobals.obj

Final_Release/CvHallOfFameInfo.obj: CvHallOfFameInfo.cpp CvGameCoreDLL.h CvHallOfFameInfo.h CvGlobals.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvHallOfFameInfo.cpp /FoFinal_Release/CvHallOfFameInfo.obj

Final_Release/CvInfoWater.obj: CvInfoWater.cpp CvGameCoreDLL.h CvInfoWater.h CvXMLLoadUtility.h CvDLLXMLIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvInfoWater.cpp /FoFinal_Release/CvInfoWater.obj

Final_Release/CvInfos.obj: CvInfos.cpp CvGameCoreDLL.h CvInfos.h CvGlobals.h CvArtFileMgr.h CvXMLLoadUtility.h CvDLLXMLIFaceBase.h CvGameTextMgr.h CvGameCoreUtils.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvInfos.cpp /FoFinal_Release/CvInfos.obj

Final_Release/CvInitCore.obj: CvInitCore.cpp CvGameCoreDLL.h CvInitCore.h CvDLLPythonIFaceBase.h CyArgsList.h CvInfos.h CvGlobals.h CvDLLUtilityIFaceBase.h CvGameAI.h CvGameCoreUtils.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvInitCore.cpp /FoFinal_Release/CvInitCore.obj

Final_Release/CvMap.obj: CvMap.cpp CvGameCoreDLL.h CvMap.h CvCity.h CvPlotGroup.h CvGlobals.h CvGameAI.h CvPlayerAI.h CvRandom.h CvGameCoreUtils.h CvFractal.h CvPlot.h CvGameCoreUtils.h CvMap.h CvMapGenerator.h FAStarNode.h CvInitCore.h CvInfos.h FProfiler.h CyArgsList.h CvDLLEngineIFaceBase.h CvDLLIniParserIFaceBase.h CvDLLFAStarIFaceBase.h CvDLLFAStarIFaceBase.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvMap.cpp /FoFinal_Release/CvMap.obj

Final_Release/CvMapGenerator.obj: CvMapGenerator.cpp CvGameCoreDLL.h CvMapGenerator.h CvMap.h CvFractal.h CvPlot.h CvGlobals.h CvRandom.h CvGameCoreUtils.h CvGameAI.h CvEnums.h CvInfos.h CvDLLPythonIFaceBase.h FProfiler.h CyPlot.h CyArgsList.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvMapGenerator.cpp /FoFinal_Release/CvMapGenerator.obj

Final_Release/CvMessageControl.obj: CvMessageControl.cpp CvGameCoreDLL.h CvMessageControl.h CvMessageData.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvMessageControl.cpp /FoFinal_Release/CvMessageControl.obj

Final_Release/CvMessageData.obj: CvMessageData.cpp CvGameCoreDLL.h CvMessageData.h FDataStreamBase.h CvDLLUtilityIFaceBase.h CvDLLInterfaceIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvMessageData.cpp /FoFinal_Release/CvMessageData.obj

Final_Release/CvPlayer.obj: CvPlayer.cpp CvGameCoreDLL.h CvGlobals.h CvArea.h CvGameAI.h CvMap.h CvPlot.h CvRandom.h CvTeamAI.h CvGameCoreUtils.h CvPlayerAI.h CvPlayer.h CvGameCoreUtils.h CvArtFileMgr.h CvDiploParameters.h CvInitCore.h CyArgsList.h CvInfos.h CvPopupInfo.h CvDiploParameters.h FProfiler.h CvGameTextMgr.h CyCity.h CyPlot.h CyUnit.h CvEventReporter.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvDLLEngineIFaceBase.h CvDLLFAStarIFaceBase.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvPlayer.cpp /FoFinal_Release/CvPlayer.obj

Final_Release/CvPlayerAI.obj: CvPlayerAI.cpp CvGameCoreDLL.h CvPlayerAI.h CvRandom.h CvGlobals.h CvGameCoreUtils.h CvMap.h CvArea.h CvPlot.h CvGameAI.h CvTeamAI.h CvGameCoreUtils.h CvDiploParameters.h CvInitCore.h CyArgsList.h CvDLLInterfaceIFaceBase.h CvDLLEntityIFaceBase.h CvDLLPythonIFaceBase.h CvDLLEngineIFaceBase.h CvInfos.h CvPopupInfo.h FProfiler.h CvDLLFAStarIFaceBase.h FAStarNode.h CvEventReporter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvPlayerAI.cpp /FoFinal_Release/CvPlayerAI.obj

Final_Release/CvPlot.obj: CvPlot.cpp CvGameCoreDLL.h CvPlot.h CvCity.h CvUnit.h CvGlobals.h CvArea.h CvGameAI.h CvDLLInterfaceIFaceBase.h CvDLLSymbolIFaceBase.h CvDLLEntityIFaceBase.h CvDLLPlotBuilderIFaceBase.h CvDLLEngineIFaceBase.h CvDLLFlagEntityIFaceBase.h CvMap.h CvPlayerAI.h CvTeamAI.h CvGameCoreUtils.h CvRandom.h CvDLLFAStarIFaceBase.h CvInfos.h FProfiler.h CvArtFileMgr.h CyArgsList.h CvDLLPythonIFaceBase.h CvEventReporter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvPlot.cpp /FoFinal_Release/CvPlot.obj

Final_Release/CvPlotGroup.obj: CvPlotGroup.cpp CvGameCoreDLL.h CvPlotGroup.h CvPlot.h CvGlobals.h CvPlayerAI.h CvMap.h CvCity.h CvDLLFAStarIFaceBase.h FProfiler.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvPlotGroup.cpp /FoFinal_Release/CvPlotGroup.obj

Final_Release/CvPopupInfo.obj: CvPopupInfo.cpp CvGameCoreDLL.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvPopupInfo.cpp /FoFinal_Release/CvPopupInfo.obj

Final_Release/CvPopupReturn.obj: CvPopupReturn.cpp CvGameCoreDLL.h CvPopupReturn.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvPopupReturn.cpp /FoFinal_Release/CvPopupReturn.obj

Final_Release/CvRandom.obj: CvRandom.cpp CvGameCoreDLL.h CvRandom.h CvGlobals.h CyArgsList.h CvGameAI.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvRandom.cpp /FoFinal_Release/CvRandom.obj

Final_Release/CvReplayInfo.obj: CvReplayInfo.cpp CvGameCoreDLL.h CvReplayInfo.h CvInfos.h CvGlobals.h CvGameAI.h CvPlayerAI.h CvMap.h CvReplayMessage.h CvGameTextMgr.h CvDLLInterfaceIFaceBase.h CvInitCore.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvReplayInfo.cpp /FoFinal_Release/CvReplayInfo.obj

Final_Release/CvReplayMessage.obj: CvReplayMessage.cpp CvGameCoreDLL.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvReplayMessage.cpp /FoFinal_Release/CvReplayMessage.obj

Final_Release/CvSelectionGroup.obj: CvSelectionGroup.cpp CvGameCoreDLL.h CvGlobals.h CvSelectionGroup.h CvGameAI.h CvPlayerAI.h CvTeamAI.h CvUnit.h CvGameCoreUtils.h CvMap.h CvPlot.h CvDLLEntityIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLFAStarIFaceBase.h FAStarNode.h CvInfos.h FProfiler.h CyPlot.h CySelectionGroup.h CyArgsList.h CvDLLPythonIFaceBase.h CvEventReporter.h CvBugOptions.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvSelectionGroup.cpp /FoFinal_Release/CvSelectionGroup.obj

Final_Release/CvSelectionGroupAI.obj: CvSelectionGroupAI.cpp CvGameCoreDLL.h CvSelectionGroupAI.h CvPlayerAI.h CvMap.h CvPlot.h CvTeamAI.h CvDLLEntityIFaceBase.h CvGameCoreUtils.h FProfiler.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvSelectionGroupAI.cpp /FoFinal_Release/CvSelectionGroupAI.obj

Final_Release/CvStatistics.obj: CvStatistics.cpp CvGameCoreDLL.h CvStatistics.h CvUnit.h CvCity.h CvGlobals.h CvGameAI.h CvPlayerAI.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvStatistics.cpp /FoFinal_Release/CvStatistics.obj

Final_Release/CvStructs.obj: CvStructs.cpp CvGameCoreDLL.h CvUnit.h CvStructs.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvStructs.cpp /FoFinal_Release/CvStructs.obj

Final_Release/CvTalkingHeadMessage.obj: CvTalkingHeadMessage.cpp CvGameCoreDLL.h CvTalkingHeadMessage.h CvGameAI.h CvGlobals.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvTalkingHeadMessage.cpp /FoFinal_Release/CvTalkingHeadMessage.obj

Final_Release/CvTeam.obj: CvTeam.cpp CvGameCoreDLL.h CvPlayerAI.h CvDefines.h CvGameCoreUtils.h CvGlobals.h CvTeamAI.h CvPlayerAI.h CvGameAI.h CvMap.h CvPlot.h CvTeam.h CvDLLInterfaceIFaceBase.h CvEventReporter.h CvDLLEngineIFaceBase.h CvArtFileMgr.h CvDiploParameters.h CvInfos.h CvPopupInfo.h CvDLLPythonIFaceBase.h CyArgsList.h FProfiler.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvTeam.cpp /FoFinal_Release/CvTeam.obj

Final_Release/CvTeamAI.obj: CvTeamAI.cpp CvGameCoreDLL.h CvTeamAI.h CvPlayerAI.h CvRandom.h CvGlobals.h CvGameCoreUtils.h CvMap.h CvPlot.h CvDLLInterfaceIFaceBase.h CvGameAI.h CvInfos.h FProfiler.h CyArgsList.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvTeamAI.cpp /FoFinal_Release/CvTeamAI.obj

Final_Release/CvUnit.obj: CvUnit.cpp CvGameCoreDLL.h CvUnit.h CvArea.h CvPlot.h CvCity.h CvGlobals.h CvGameCoreUtils.h CvGameAI.h CvMap.h CvPlayerAI.h CvRandom.h CvTeamAI.h CvGameCoreUtils.h CyUnit.h CyArgsList.h CyPlot.h CvDLLEntityIFaceBase.h CvDLLInterfaceIFaceBase.h CvDLLEngineIFaceBase.h CvEventReporter.h CvDLLPythonIFaceBase.h CvDLLFAStarIFaceBase.h CvInfos.h FProfiler.h CvPopupInfo.h CvArtFileMgr.h CvBugOptions.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvUnit.cpp /FoFinal_Release/CvUnit.obj

Final_Release/CvUnitAI.obj: CvUnitAI.cpp CvGameCoreDLL.h CvUnitAI.h CvMap.h CvArea.h CvPlot.h CvGlobals.h CvGameAI.h CvTeamAI.h CvPlayerAI.h CvGameCoreUtils.h CvRandom.h CyUnit.h CyArgsList.h CvDLLPythonIFaceBase.h CvInfos.h FProfiler.h FAStarNode.h CvDLLInterfaceIFaceBase.h CvDLLFAStarIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvUnitAI.cpp /FoFinal_Release/CvUnitAI.obj

Final_Release/CvXMLLoadUtility.obj: CvXMLLoadUtility.cpp CvGameCoreDLL.h CvDLLXMLIFaceBase.h CvXMLLoadUtility.h CvGlobals.h FProfiler.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvXMLLoadUtility.cpp /FoFinal_Release/CvXMLLoadUtility.obj

Final_Release/CvXMLLoadUtilityGet.obj: CvXMLLoadUtilityGet.cpp CvGameCoreDLL.h CvDLLXMLIFaceBase.h CvXMLLoadUtility.h CvGlobals.h CvArtFileMgr.h FInputDevice.h FProfiler.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvXMLLoadUtilityGet.cpp /FoFinal_Release/CvXMLLoadUtilityGet.obj

Final_Release/CvXMLLoadUtilityInit.obj: CvXMLLoadUtilityInit.cpp CvGameCoreDLL.h CvXMLLoadUtility.h CvGlobals.h CvArtFileMgr.h CvGameTextMgr.h CvInfoWater.h FProfiler.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvXMLLoadUtilityInit.cpp /FoFinal_Release/CvXMLLoadUtilityInit.obj

Final_Release/CvXMLLoadUtilitySet.obj: CvXMLLoadUtilitySet.cpp CvGameCoreDLL.h CvDLLXMLIFaceBase.h CvXMLLoadUtility.h CvGlobals.h CvArtFileMgr.h CvGameTextMgr.h CvInfoWater.h FProfiler.h FVariableSystem.h CvGameCoreUtils.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CvXMLLoadUtilitySet.cpp /FoFinal_Release/CvXMLLoadUtilitySet.obj

Final_Release/CyArea.obj: CyArea.cpp CvGameCoreDLL.h CyCity.h CyArea.h CvArea.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyArea.cpp /FoFinal_Release/CyArea.obj

Final_Release/CyAreaInterface.obj: CyAreaInterface.cpp CvGameCoreDLL.h CyArea.h CyCity.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyAreaInterface.cpp /FoFinal_Release/CyAreaInterface.obj

Final_Release/CyArgsList.obj: CyArgsList.cpp CvGameCoreDLL.h CyArgsList.h CyGlobalContext.h CvDLLPythonIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyArgsList.cpp /FoFinal_Release/CyArgsList.obj

Final_Release/CyArtFileMgr.obj: CyArtFileMgr.cpp CvGameCoreDLL.h CyArtFileMgr.h CvArtFileMgr.h CyGlobalContext.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyArtFileMgr.cpp /FoFinal_Release/CyArtFileMgr.obj

Final_Release/CyArtFileMgrInterface.obj: CyArtFileMgrInterface.cpp CvGameCoreDLL.h CyArtFileMgr.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyArtFileMgrInterface.cpp /FoFinal_Release/CyArtFileMgrInterface.obj

Final_Release/CyCity.obj: CyCity.cpp CvGameCoreDLL.h CyCity.h CvCity.h CyPlot.h CyArea.h CyUnit.h CvDLLPythonIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyCity.cpp /FoFinal_Release/CyCity.obj

Final_Release/CyCityInterface1.obj: CyCityInterface1.cpp CvGameCoreDLL.h CyCity.h CyPlot.h CyArea.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyCityInterface1.cpp /FoFinal_Release/CyCityInterface1.obj

Final_Release/CyDeal.obj: CyDeal.cpp CvGameCoreDLL.h CyDeal.h CvDeal.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyDeal.cpp /FoFinal_Release/CyDeal.obj

Final_Release/CyEnumsInterface.obj: CyEnumsInterface.cpp CvGameCoreDLL.h CvGameCoreDLLDefNew.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyEnumsInterface.cpp /FoFinal_Release/CyEnumsInterface.obj

Final_Release/CyGame.obj: CyGame.cpp CvGameCoreDLL.h CyGame.h CvGameAI.h CyGlobalContext.h CyPlayer.h CvEnums.h CyCity.h CyDeal.h CyReplayInfo.h CvReplayInfo.h CyPlot.h CvDLLEngineIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGame.cpp /FoFinal_Release/CyGame.obj

Final_Release/CyGameCoreUtils.obj: CyGameCoreUtils.cpp CvGameCoreDLL.h CyGameCoreUtils.h CvGameCoreUtils.h CyPlot.h CyCity.h CyUnit.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGameCoreUtils.cpp /FoFinal_Release/CyGameCoreUtils.obj

Final_Release/CyGameCoreUtilsInterface.obj: CyGameCoreUtilsInterface.cpp CvGameCoreDLL.h CyGameCoreUtils.h CyPlot.h CyCity.h CyUnit.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGameCoreUtilsInterface.cpp /FoFinal_Release/CyGameCoreUtilsInterface.obj

Final_Release/CyGameInterface.obj: CyGameInterface.cpp CvGameCoreDLL.h CyGame.h CvRandom.h CyCity.h CyDeal.h CyReplayInfo.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGameInterface.cpp /FoFinal_Release/CyGameInterface.obj

Final_Release/CyGameTextMgr.obj: CyGameTextMgr.cpp CvGameCoreDLL.h CvGameTextMgr.h CyGameTextMgr.h CyCity.h CyDeal.h CyUnit.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGameTextMgr.cpp /FoFinal_Release/CyGameTextMgr.obj

Final_Release/CyGameTextMgrInterface.obj: CyGameTextMgrInterface.cpp CvGameCoreDLL.h CyGameTextMgr.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGameTextMgrInterface.cpp /FoFinal_Release/CyGameTextMgrInterface.obj

Final_Release/CyGlobalContext.obj: CyGlobalContext.cpp CvGameCoreDLL.h CyGlobalContext.h CyGame.h CyPlayer.h CyMap.h CvGlobals.h CvPlayerAI.h CvGameAI.h CvStructs.h CvInfos.h CyTeam.h CvTeamAI.h CyArtFileMgr.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGlobalContext.cpp /FoFinal_Release/CyGlobalContext.obj

Final_Release/CyGlobalContextInterface1.obj: CyGlobalContextInterface1.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGlobalContextInterface1.cpp /FoFinal_Release/CyGlobalContextInterface1.obj

Final_Release/CyGlobalContextInterface2.obj: CyGlobalContextInterface2.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGlobalContextInterface2.cpp /FoFinal_Release/CyGlobalContextInterface2.obj

Final_Release/CyGlobalContextInterface3.obj: CyGlobalContextInterface3.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGlobalContextInterface3.cpp /FoFinal_Release/CyGlobalContextInterface3.obj

Final_Release/CyGlobalContextInterface4.obj: CyGlobalContextInterface4.cpp CvGameCoreDLL.h CyMap.h CyPlayer.h CyGame.h CyGlobalContext.h CvRandom.h CvStructs.h CvInfos.h CyTeam.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyGlobalContextInterface4.cpp /FoFinal_Release/CyGlobalContextInterface4.obj

Final_Release/CyHallOfFameInfo.obj: CyHallOfFameInfo.cpp CvGameCoreDLL.h CyHallOfFameInfo.h CyReplayInfo.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyHallOfFameInfo.cpp /FoFinal_Release/CyHallOfFameInfo.obj

Final_Release/CyHallOfFameInterface.obj: CyHallOfFameInterface.cpp CvGameCoreDLL.h CyReplayInfo.h CyHallOfFameInfo.h CyMap.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyHallOfFameInterface.cpp /FoFinal_Release/CyHallOfFameInterface.obj

Final_Release/CyInfoInterface1.obj: CyInfoInterface1.cpp CvGameCoreDLL.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyInfoInterface1.cpp /FoFinal_Release/CyInfoInterface1.obj

Final_Release/CyInfoInterface2.obj: CyInfoInterface2.cpp CvGameCoreDLL.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyInfoInterface2.cpp /FoFinal_Release/CyInfoInterface2.obj

Final_Release/CyInfoInterface3.obj: CyInfoInterface3.cpp CvGameCoreDLL.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyInfoInterface3.cpp /FoFinal_Release/CyInfoInterface3.obj

Final_Release/CyMap.obj: CyMap.cpp CvGameCoreDLL.h CyPlot.h CvMap.h CyCity.h CySelectionGroup.h CyUnit.h CyArea.h CvGlobals.h CvMapGenerator.h CvInitCore.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyMap.cpp /FoFinal_Release/CyMap.obj

Final_Release/CyMapGenerator.obj: CyMapGenerator.cpp CvGameCoreDLL.h CyMapGenerator.h CvGlobals.h CvDLLPythonIFaceBase.h CvMapGenerator.h CyPlot.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyMapGenerator.cpp /FoFinal_Release/CyMapGenerator.obj

Final_Release/CyMapGeneratorInterface.obj: CyMapGeneratorInterface.cpp CvGameCoreDLL.h CyMapGenerator.h CvStructs.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyMapGeneratorInterface.cpp /FoFinal_Release/CyMapGeneratorInterface.obj

Final_Release/CyMapInterface.obj: CyMapInterface.cpp CvGameCoreDLL.h CyMap.h CyArea.h CyCity.h CySelectionGroup.h CyUnit.h CyPlot.h CvStructs.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyMapInterface.cpp /FoFinal_Release/CyMapInterface.obj

Final_Release/CyMessageControl.obj: CyMessageControl.cpp CvGameCoreDLL.h CyMessageControl.h CvMessageControl.h CvDLLPythonIFaceBase.h CvDLLUtilityIFaceBase.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyMessageControl.cpp /FoFinal_Release/CyMessageControl.obj

Final_Release/CyMessageControlInterface.obj: CyMessageControlInterface.cpp CvGameCoreDLL.h CyMessageControl.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyMessageControlInterface.cpp /FoFinal_Release/CyMessageControlInterface.obj

Final_Release/CyPlayer.obj: CyPlayer.cpp CvGameCoreDLL.h CyPlayer.h CyUnit.h CyCity.h CyArea.h CyPlot.h CvPlayerAI.h CvEnums.h CvCity.h CvMap.h CvPlot.h CySelectionGroup.h CvDLLPythonIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyPlayer.cpp /FoFinal_Release/CyPlayer.obj

Final_Release/CyPlayerInterface1.obj: CyPlayerInterface1.cpp CvGameCoreDLL.h CyPlayer.h CyUnit.h CyCity.h CyPlot.h CySelectionGroup.h CyArea.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyPlayerInterface1.cpp /FoFinal_Release/CyPlayerInterface1.obj

Final_Release/CyPlayerInterface2.obj: CyPlayerInterface2.cpp CvGameCoreDLL.h CyPlayer.h CyUnit.h CyCity.h CyPlot.h CySelectionGroup.h CyArea.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyPlayerInterface2.cpp /FoFinal_Release/CyPlayerInterface2.obj

Final_Release/CyPlot.obj: CyPlot.cpp CvGameCoreDLL.h CyPlot.h CyCity.h CyArea.h CyUnit.h CvPlot.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyPlot.cpp /FoFinal_Release/CyPlot.obj

Final_Release/CyPlotInterface1.obj: CyPlotInterface1.cpp CvGameCoreDLL.h CyPlot.h CyCity.h CyArea.h CyUnit.h CvPlot.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyPlotInterface1.cpp /FoFinal_Release/CyPlotInterface1.obj

Final_Release/CyRandomInterface.obj: CyRandomInterface.cpp CvGameCoreDLL.h CvRandom.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyRandomInterface.cpp /FoFinal_Release/CyRandomInterface.obj

Final_Release/CyReplayInfo.obj: CyReplayInfo.cpp CvGameCoreDLL.h CyReplayInfo.h CyMap.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyReplayInfo.cpp /FoFinal_Release/CyReplayInfo.obj

Final_Release/CySelectionGroup.obj: CySelectionGroup.cpp CvGameCoreDLL.h CySelectionGroup.h CvSelectionGroup.h CvPlot.h CyPlot.h CvArea.h CyArea.h CyUnit.h CvStructs.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CySelectionGroup.cpp /FoFinal_Release/CySelectionGroup.obj

Final_Release/CySelectionGroupInterface.obj: CySelectionGroupInterface.cpp CvGameCoreDLL.h CySelectionGroup.h CyPlot.h CyArea.h CyUnit.h CvStructs.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CySelectionGroupInterface.cpp /FoFinal_Release/CySelectionGroupInterface.obj

Final_Release/CyStructsInterface1.obj: CyStructsInterface1.cpp CvGameCoreDLL.h CvUnit.h CvStructs.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyStructsInterface1.cpp /FoFinal_Release/CyStructsInterface1.obj

Final_Release/CyTeam.obj: CyTeam.cpp CvGameCoreDLL.h CyTeam.h CyArea.h CvTeam.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyTeam.cpp /FoFinal_Release/CyTeam.obj

Final_Release/CyTeamInterface.obj: CyTeamInterface.cpp CvGameCoreDLL.h CyArea.h CyTeam.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyTeamInterface.cpp /FoFinal_Release/CyTeamInterface.obj

Final_Release/CyUnit.obj: CyUnit.cpp CvGameCoreDLL.h CyUnit.h CyCity.h CvArea.h CvPlot.h CvUnit.h CyPlot.h CyArea.h CvArtFileMgr.h CySelectionGroup.h CvDLLInterfaceIFaceBase.h CvGlobals.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyUnit.cpp /FoFinal_Release/CyUnit.obj

Final_Release/CyUnitInterface1.obj: CyUnitInterface1.cpp CvGameCoreDLL.h CyUnit.h CyCity.h CyPlot.h CyArea.h CySelectionGroup.h CyArtFileMgr.h CvInfos.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CyUnitInterface1.cpp /FoFinal_Release/CyUnitInterface1.obj

Final_Release/FAssert.obj: FAssert.cpp FDialogTemplate.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c FAssert.cpp /FoFinal_Release/FAssert.obj

Final_Release/FDialogTemplate.obj: FDialogTemplate.cpp FDialogTemplate.h CvGameCoreDLLUndefNew.h CvGameCoreDLLUndefNew.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c FDialogTemplate.cpp /FoFinal_Release/FDialogTemplate.obj

Final_Release/_precompile.obj: _precompile.cpp CvGameCoreDLL.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c _precompile.cpp /FoFinal_Release/_precompile.obj

Final_Release/CxImage/general/tif_xfile.obj: CxImage/general/tif_xfile.cpp CxImage/general/ximage.h CxImage/general/xfile.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/tif_xfile.cpp /FoFinal_Release/CxImage/general/tif_xfile.obj

Final_Release/CxImage/general/ximabmp.obj: CxImage/general/ximabmp.cpp CxImage/general/ximabmp.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximabmp.cpp /FoFinal_Release/CxImage/general/ximabmp.obj

Final_Release/CxImage/general/ximadsp.obj: CxImage/general/ximadsp.cpp CxImage/general/ximage.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximadsp.cpp /FoFinal_Release/CxImage/general/ximadsp.obj

Final_Release/CxImage/general/ximaenc.obj: CxImage/general/ximaenc.cpp CxImage/general/ximage.h CxImage/general/ximajpg.h CxImage/general/ximagif.h CxImage/general/ximapng.h CxImage/general/ximamng.h CxImage/general/ximabmp.h CxImage/general/ximaico.h CxImage/general/ximatif.h CxImage/general/ximatga.h CxImage/general/ximapcx.h CxImage/general/ximawbmp.h CxImage/general/ximawmf.h CxImage/general/ximaj2k.h CxImage/general/ximajbg.h CxImage/general/ximajas.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximaenc.cpp /FoFinal_Release/CxImage/general/ximaenc.obj

Final_Release/CxImage/general/ximaexif.obj: CxImage/general/ximaexif.cpp CxImage/general/ximajpg.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximaexif.cpp /FoFinal_Release/CxImage/general/ximaexif.obj

Final_Release/CxImage/general/ximage.obj: CxImage/general/ximage.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximage.cpp /FoFinal_Release/CxImage/general/ximage.obj

Final_Release/CxImage/general/ximagif.obj: CxImage/general/ximagif.cpp CxImage/general/ximagif.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximagif.cpp /FoFinal_Release/CxImage/general/ximagif.obj

Final_Release/CxImage/general/ximahist.obj: CxImage/general/ximahist.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximahist.cpp /FoFinal_Release/CxImage/general/ximahist.obj

Final_Release/CxImage/general/ximaico.obj: CxImage/general/ximaico.cpp CxImage/general/ximaico.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximaico.cpp /FoFinal_Release/CxImage/general/ximaico.obj

Final_Release/CxImage/general/ximainfo.obj: CxImage/general/ximainfo.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximainfo.cpp /FoFinal_Release/CxImage/general/ximainfo.obj

Final_Release/CxImage/general/ximaint.obj: CxImage/general/ximaint.cpp CxImage/general/ximage.h CxImage/general/ximath.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximaint.cpp /FoFinal_Release/CxImage/general/ximaint.obj

Final_Release/CxImage/general/ximaj2k.obj: CxImage/general/ximaj2k.cpp CxImage/general/ximaj2k.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximaj2k.cpp /FoFinal_Release/CxImage/general/ximaj2k.obj

Final_Release/CxImage/general/ximajas.obj: CxImage/general/ximajas.cpp CxImage/general/ximajas.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximajas.cpp /FoFinal_Release/CxImage/general/ximajas.obj

Final_Release/CxImage/general/ximajbg.obj: CxImage/general/ximajbg.cpp CxImage/general/ximajbg.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximajbg.cpp /FoFinal_Release/CxImage/general/ximajbg.obj

Final_Release/CxImage/general/ximajpg.obj: CxImage/general/ximajpg.cpp CxImage/general/ximajpg.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximajpg.cpp /FoFinal_Release/CxImage/general/ximajpg.obj

Final_Release/CxImage/general/ximalpha.obj: CxImage/general/ximalpha.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximalpha.cpp /FoFinal_Release/CxImage/general/ximalpha.obj

Final_Release/CxImage/general/ximalyr.obj: CxImage/general/ximalyr.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximalyr.cpp /FoFinal_Release/CxImage/general/ximalyr.obj

Final_Release/CxImage/general/ximamng.obj: CxImage/general/ximamng.cpp CxImage/general/ximamng.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximamng.cpp /FoFinal_Release/CxImage/general/ximamng.obj

Final_Release/CxImage/general/ximapal.obj: CxImage/general/ximapal.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximapal.cpp /FoFinal_Release/CxImage/general/ximapal.obj

Final_Release/CxImage/general/ximapcx.obj: CxImage/general/ximapcx.cpp CxImage/general/ximapcx.h CxImage/general/xmemfile.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximapcx.cpp /FoFinal_Release/CxImage/general/ximapcx.obj

Final_Release/CxImage/general/ximapng.obj: CxImage/general/ximapng.cpp CxImage/general/ximapng.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximapng.cpp /FoFinal_Release/CxImage/general/ximapng.obj

Final_Release/CxImage/general/ximasel.obj: CxImage/general/ximasel.cpp CxImage/general/ximage.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximasel.cpp /FoFinal_Release/CxImage/general/ximasel.obj

Final_Release/CxImage/general/ximatga.obj: CxImage/general/ximatga.cpp CxImage/general/ximatga.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximatga.cpp /FoFinal_Release/CxImage/general/ximatga.obj

Final_Release/CxImage/general/ximath.obj: CxImage/general/ximath.cpp CxImage/general/ximage.h CxImage/general/ximath.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximath.cpp /FoFinal_Release/CxImage/general/ximath.obj

Final_Release/CxImage/general/ximatif.obj: CxImage/general/ximatif.cpp CxImage/general/ximatif.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximatif.cpp /FoFinal_Release/CxImage/general/ximatif.obj

Final_Release/CxImage/general/ximatran.obj: CxImage/general/ximatran.cpp CxImage/general/ximage.h CxImage/general/ximath.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximatran.cpp /FoFinal_Release/CxImage/general/ximatran.obj

Final_Release/CxImage/general/ximawbmp.obj: CxImage/general/ximawbmp.cpp CxImage/general/ximawbmp.h CxImage/general/ximaiter.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximawbmp.cpp /FoFinal_Release/CxImage/general/ximawbmp.obj

Final_Release/CxImage/general/ximawmf.obj: CxImage/general/ximawmf.cpp CxImage/general/ximawmf.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximawmf.cpp /FoFinal_Release/CxImage/general/ximawmf.obj

Final_Release/CxImage/general/ximawnd.obj: CxImage/general/ximawnd.cpp CxImage/general/ximage.h CxImage/general/ximaiter.h CxImage/general/ximabmp.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/ximawnd.cpp /FoFinal_Release/CxImage/general/ximawnd.obj

Final_Release/CxImage/general/xmemfile.obj: CxImage/general/xmemfile.cpp CxImage/general/xmemfile.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/general/xmemfile.cpp /FoFinal_Release/CxImage/general/xmemfile.obj

Final_Release/CxImage/jpeg/jcapimin.obj: CxImage/jpeg/jcapimin.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcapimin.c /FoFinal_Release/CxImage/jpeg/jcapimin.obj

Final_Release/CxImage/jpeg/jcapistd.obj: CxImage/jpeg/jcapistd.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcapistd.c /FoFinal_Release/CxImage/jpeg/jcapistd.obj

Final_Release/CxImage/jpeg/jccoefct.obj: CxImage/jpeg/jccoefct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jccoefct.c /FoFinal_Release/CxImage/jpeg/jccoefct.obj

Final_Release/CxImage/jpeg/jccolor.obj: CxImage/jpeg/jccolor.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jccolor.c /FoFinal_Release/CxImage/jpeg/jccolor.obj

Final_Release/CxImage/jpeg/jcdctmgr.obj: CxImage/jpeg/jcdctmgr.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcdctmgr.c /FoFinal_Release/CxImage/jpeg/jcdctmgr.obj

Final_Release/CxImage/jpeg/jchuff.obj: CxImage/jpeg/jchuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jchuff.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jchuff.c /FoFinal_Release/CxImage/jpeg/jchuff.obj

Final_Release/CxImage/jpeg/jcinit.obj: CxImage/jpeg/jcinit.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcinit.c /FoFinal_Release/CxImage/jpeg/jcinit.obj

Final_Release/CxImage/jpeg/jcmainct.obj: CxImage/jpeg/jcmainct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcmainct.c /FoFinal_Release/CxImage/jpeg/jcmainct.obj

Final_Release/CxImage/jpeg/jcmarker.obj: CxImage/jpeg/jcmarker.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcmarker.c /FoFinal_Release/CxImage/jpeg/jcmarker.obj

Final_Release/CxImage/jpeg/jcmaster.obj: CxImage/jpeg/jcmaster.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcmaster.c /FoFinal_Release/CxImage/jpeg/jcmaster.obj

Final_Release/CxImage/jpeg/jcomapi.obj: CxImage/jpeg/jcomapi.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcomapi.c /FoFinal_Release/CxImage/jpeg/jcomapi.obj

Final_Release/CxImage/jpeg/jcparam.obj: CxImage/jpeg/jcparam.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcparam.c /FoFinal_Release/CxImage/jpeg/jcparam.obj

Final_Release/CxImage/jpeg/jcphuff.obj: CxImage/jpeg/jcphuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jchuff.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcphuff.c /FoFinal_Release/CxImage/jpeg/jcphuff.obj

Final_Release/CxImage/jpeg/jcprepct.obj: CxImage/jpeg/jcprepct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcprepct.c /FoFinal_Release/CxImage/jpeg/jcprepct.obj

Final_Release/CxImage/jpeg/jcsample.obj: CxImage/jpeg/jcsample.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jcsample.c /FoFinal_Release/CxImage/jpeg/jcsample.obj

Final_Release/CxImage/jpeg/jctrans.obj: CxImage/jpeg/jctrans.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jctrans.c /FoFinal_Release/CxImage/jpeg/jctrans.obj

Final_Release/CxImage/jpeg/jdapimin.obj: CxImage/jpeg/jdapimin.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdapimin.c /FoFinal_Release/CxImage/jpeg/jdapimin.obj

Final_Release/CxImage/jpeg/jdapistd.obj: CxImage/jpeg/jdapistd.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdapistd.c /FoFinal_Release/CxImage/jpeg/jdapistd.obj

Final_Release/CxImage/jpeg/jdatadst.obj: CxImage/jpeg/jdatadst.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jerror.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdatadst.c /FoFinal_Release/CxImage/jpeg/jdatadst.obj

Final_Release/CxImage/jpeg/jdatasrc.obj: CxImage/jpeg/jdatasrc.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jerror.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdatasrc.c /FoFinal_Release/CxImage/jpeg/jdatasrc.obj

Final_Release/CxImage/jpeg/jdcoefct.obj: CxImage/jpeg/jdcoefct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdcoefct.c /FoFinal_Release/CxImage/jpeg/jdcoefct.obj

Final_Release/CxImage/jpeg/jdcolor.obj: CxImage/jpeg/jdcolor.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdcolor.c /FoFinal_Release/CxImage/jpeg/jdcolor.obj

Final_Release/CxImage/jpeg/jddctmgr.obj: CxImage/jpeg/jddctmgr.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jddctmgr.c /FoFinal_Release/CxImage/jpeg/jddctmgr.obj

Final_Release/CxImage/jpeg/jdhuff.obj: CxImage/jpeg/jdhuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdhuff.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdhuff.c /FoFinal_Release/CxImage/jpeg/jdhuff.obj

Final_Release/CxImage/jpeg/jdinput.obj: CxImage/jpeg/jdinput.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdinput.c /FoFinal_Release/CxImage/jpeg/jdinput.obj

Final_Release/CxImage/jpeg/jdmainct.obj: CxImage/jpeg/jdmainct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdmainct.c /FoFinal_Release/CxImage/jpeg/jdmainct.obj

Final_Release/CxImage/jpeg/jdmarker.obj: CxImage/jpeg/jdmarker.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdmarker.c /FoFinal_Release/CxImage/jpeg/jdmarker.obj

Final_Release/CxImage/jpeg/jdmaster.obj: CxImage/jpeg/jdmaster.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdmaster.c /FoFinal_Release/CxImage/jpeg/jdmaster.obj

Final_Release/CxImage/jpeg/jdmerge.obj: CxImage/jpeg/jdmerge.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdmerge.c /FoFinal_Release/CxImage/jpeg/jdmerge.obj

Final_Release/CxImage/jpeg/jdphuff.obj: CxImage/jpeg/jdphuff.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdhuff.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdphuff.c /FoFinal_Release/CxImage/jpeg/jdphuff.obj

Final_Release/CxImage/jpeg/jdpostct.obj: CxImage/jpeg/jdpostct.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdpostct.c /FoFinal_Release/CxImage/jpeg/jdpostct.obj

Final_Release/CxImage/jpeg/jdsample.obj: CxImage/jpeg/jdsample.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdsample.c /FoFinal_Release/CxImage/jpeg/jdsample.obj

Final_Release/CxImage/jpeg/jdtrans.obj: CxImage/jpeg/jdtrans.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jdtrans.c /FoFinal_Release/CxImage/jpeg/jdtrans.obj

Final_Release/CxImage/jpeg/jerror.obj: CxImage/jpeg/jerror.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jversion.h CxImage/jpeg/jerror.h CxImage/jpeg/jerror.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jerror.c /FoFinal_Release/CxImage/jpeg/jerror.obj

Final_Release/CxImage/jpeg/jfdctflt.obj: CxImage/jpeg/jfdctflt.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jfdctflt.c /FoFinal_Release/CxImage/jpeg/jfdctflt.obj

Final_Release/CxImage/jpeg/jfdctfst.obj: CxImage/jpeg/jfdctfst.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jfdctfst.c /FoFinal_Release/CxImage/jpeg/jfdctfst.obj

Final_Release/CxImage/jpeg/jfdctint.obj: CxImage/jpeg/jfdctint.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jfdctint.c /FoFinal_Release/CxImage/jpeg/jfdctint.obj

Final_Release/CxImage/jpeg/jidctflt.obj: CxImage/jpeg/jidctflt.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jidctflt.c /FoFinal_Release/CxImage/jpeg/jidctflt.obj

Final_Release/CxImage/jpeg/jidctfst.obj: CxImage/jpeg/jidctfst.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jidctfst.c /FoFinal_Release/CxImage/jpeg/jidctfst.obj

Final_Release/CxImage/jpeg/jidctint.obj: CxImage/jpeg/jidctint.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jidctint.c /FoFinal_Release/CxImage/jpeg/jidctint.obj

Final_Release/CxImage/jpeg/jidctred.obj: CxImage/jpeg/jidctred.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jdct.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jidctred.c /FoFinal_Release/CxImage/jpeg/jidctred.obj

Final_Release/CxImage/jpeg/jmemmgr.obj: CxImage/jpeg/jmemmgr.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jmemsys.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jmemmgr.c /FoFinal_Release/CxImage/jpeg/jmemmgr.obj

Final_Release/CxImage/jpeg/jmemnobs.obj: CxImage/jpeg/jmemnobs.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h CxImage/jpeg/jmemsys.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jmemnobs.c /FoFinal_Release/CxImage/jpeg/jmemnobs.obj

Final_Release/CxImage/jpeg/jquant1.obj: CxImage/jpeg/jquant1.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jquant1.c /FoFinal_Release/CxImage/jpeg/jquant1.obj

Final_Release/CxImage/jpeg/jquant2.obj: CxImage/jpeg/jquant2.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jquant2.c /FoFinal_Release/CxImage/jpeg/jquant2.obj

Final_Release/CxImage/jpeg/jutils.obj: CxImage/jpeg/jutils.c CxImage/jpeg/jinclude.h CxImage/jpeg/jpeglib.h
	$(CPP) /nologo $(Final_Release_CFLAGS) $(Final_Release_INCS) /c CxImage/jpeg/jutils.c /FoFinal_Release/CxImage/jpeg/jutils.obj
