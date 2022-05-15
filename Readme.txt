README for BUG
==============

1. Introduction
2. Installation
3. Configuration
4. Troubleshooting


____________________________________________________________________________________________________
1. INTRODUCTION

BUG is an unaltered-gameplay mod for Civ4:BTS. This readme covers how to install BUG manually, but we recommend that you use the installer when you can.


____________________________________________________________________________________________________
2. INSTALLATION

WARNING: You should never modify or replace the original BTS Assets files.

__________________________________________________
2.1. AS A MOD

To install BUG as a mod so that you must load it to play, place the folder that contains this README file into your BTS's Mods folder.

    C:\Program Files
      Sid Meier's Civilization 4
        Beyond the Sword
          Mods
            BUG Mod x.x
              Readme.txt
              ...

__________________________________________________
2.2. CUSTOM ASSETS

To install BUG so that it is always active with your games (this will allow you to use it with succession games and games you open from the CivFanatics forum), you must first copy the files and folders from the Assets folder into your CustomAssets folder. Next create a "BUG Mod" folder next to CustomAssets and copy the Info and UserSettings folders into it. Finally, copy the files inside PrivateMaps into BTS's PublicMaps folder.

At each step it is important that you tell it to overwrite files.

    C:\Documents and Settings
      <your user name>
        My Documents
          My Games
            Beyond the Sword
              CustomAssets        <-- folders in Assets go here
              BUG Mod             <-- create this folder
                GameSetUpCheck    <-- copy these three folders here
                Info
                UserSettings
              PublicMaps          <-- copy files from PrivateMaps here


____________________________________________________________________________________________________
3. CONFIGURATION

Once you start a game with BUG you can customize how BUG looks by hitting ALT + CTRL + O to get to the BUG Options screen. It has many tabs to organize the settings, and they are all written to INI files inside the UserSettings folder. You can also change them in these files, but this is only necessary for a handful of options.


____________________________________________________________________________________________________
4. TROUBLESHOOTING

If you are having any trouble getting BUG to work, start with our Troubleshooting wiki page:

    http://sourceforge.net/apps/mediawiki/civ4bug/index.php?title=Troubleshooting

Post the information that page asks for to the Questions thread at our forum:

    http://forums.civfanatics.com/showthread.php?t=242396

If you find a feature or option that doesn't work properly, please post to our Bug Reporting thread:

    http://forums.civfanatics.com/showthread.php?t=241796
