README for BULL
===============

1. Introduction
2. Installation
3. Configuration
4. Known Issues
5. Troubleshooting
6. Modding


____________________________________________________________________________________________________
1. INTRODUCTION

BULL is an unaltered-gameplay mod for Civ4:BTS. It can be used by itself or with any other mod that doesn't have its own CvGameCoreDLL.dll (DLL) file. For those that do have a DLL, you can ask the mod's creator if they would be kind enough to merge BULL into their mod or do it yourself (see MODDING below).

If BULL is installed along with BUG, they will complement each other. BULL's options will appear in the BUG Options screen (ALT + CTRL + O), and some BUG features will become available (e.g. MapFinder and AutoSave). Most of BULL's features add information to existing hover text such as the City Bar, Building, and Unit hovers. For a comprehensive list of changes, see the Changelog.txt file.


____________________________________________________________________________________________________
2. INSTALLATION

WARNING: You should never modify or replace the original BTS Assets files. The one exception is the CvGameCoreDLL.dll file, and you should always backup the original file first so you can revert.

Note: The Optional and SDK folders are only needed for modders. You can safely ignore them.

__________________________________________________
AS A MOD

To install BULL as a mod so that you must load it to play, place the folder that contains this README file into your BTS's Mods folder.

    C:\Program Files
      Sid Meier's Civilization 4
        Beyond the Sword
          Mods
            BULL Mod

__________________________________________________
CUSTOM ASSETS

To install BULL so that it is always active with your games (this will allow you to use it with succession games and games you open from the CivFanatics forum), you must copy the files and folders from BULL's Assets folder into your CustomAssets folder.

    C:\Documents and Settings
      <your user name>
        My Documents
          My Games
            Beyond the Sword
              CustomAssets

Next copy the file Assets/CvGameCoreDLL.dll to BTS's Assets folder, renaming the original first. It's okay to leave a copy of it in the CustomAssets folder; it will be ignored by BTS.

    C:\Program Files
      Sid Meier's Civilization 4
        Beyond the Sword
          Assets
            CvGameCoreDLL.dll.original    <-- rename original by adding something onto the end
            CvGameCoreDLL.dll             <-- then copy BULL's here

__________________________________________________
INSTALLING WITH BUG

BULL has been designed to have no files in common with BUG. If you installed BUG using the default Single-Player method, follow the CUSTOM ASSETS instructions above. If you installed BUG using the Multi-Player method, copy all of the files in BULL to the "BUG Mod x.x" folder, saying "Yes to All" to replace files (it will not actually replace any files).


____________________________________________________________________________________________________
3. CONFIGURATION

If you are using BULL with BUG, the BULL settings will become active on the BUG Options screen (ALT + CTRL + O). Changes you make will take effect immediately.

If you are using BULL alone, you can change BULL settings in the file Assets/XML/GlobalDefinesAlt.xml. Most are on/off settings for which you can use 1 for on and 0 for off. You must restart BTS to see your changes in the game.


____________________________________________________________________________________________________
4. KNOWN ISSUES

BULL can cause Out of Sync (OOS) errors in multiplayer games if a few options are set to different values for the different players. Make sure that every player in the game has the same setting for these options:

	Pre-Chop
	- Forests
	- Improvements
	
	Sentry Healing
	- Enabled
	- Only in Neutral Territory


____________________________________________________________________________________________________
5. TROUBLESHOOTING

If you are having any trouble getting BULL to work, start with our Troubleshooting wiki page:

    http://sourceforge.net/apps/mediawiki/civ4bug/index.php?title=Troubleshooting

Post the information that page asks for to the Questions thread at our forum:

    http://forums.civfanatics.com/showthread.php?t=242396

If you find a feature or option that doesn't work properly, please post to our Bug Reporting thread:

    http://forums.civfanatics.com/showthread.php?t=241796


____________________________________________________________________________________________________
6. MODDING

See the separate document Modding.txt for information helpful to modders.
