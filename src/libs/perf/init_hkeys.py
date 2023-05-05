####################################################################################
#
#                 Copyright (C) 2021 - 2023, Barca, Inc. 
# 
#    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
#    Project: Speed Run To Clean Your System And Gain More Performance
# 
#   This software is licensed as described in the file COPYING, which                    
#   you should have received as part of this distribution. The terms                     
# 	are also available at https://BarcaCorporation.github.io/docs/copyright.html.           
#
# 	You may opt to use, copy, modify, merge, publish, distribute and/or sell             
# 	copies of the Software, and permit persons to whom the Software is                   
# 	furnished to do so, under the terms of the COPYING file.                             
#
# 	This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY            
# 	KIND, either express or implied.                                                      
#
####################################################################################
import winreg as wrg
import os
# defines envs
ENV_USER_PROFILE = os.getenv('USERPROFILE')
SYSTEM_DRIVE = os.getenv('SystemDrive')
PROGRAM_FILES = os.getenv('ProgramFiles')
# Store location of HKEY_CURRENT_USER
location = wrg.HKEY_CURRENT_USER
  
# SPEEDRUN DIR
soft_speed = wrg.OpenKeyEx(location, r"SOFTWARE\\")
key_1 = wrg.CreateKey(soft_speed, "SpeedRun")  
# creating values in Speed Run
wrg.SetValueEx(key_1, "Settings", 0, wrg.REG_SZ, "Default")
wrg.SetValueEx(key_1, "DisplayName", 0, wrg.REG_SZ, "SpeedRun Software Foundation")
wrg.SetValueEx(key_1, "Version", 0, wrg.REG_SZ, "0.1.0")
wrg.SetValueEx(key_1, "SupportUrl", 0, wrg.REG_SZ, "https://speedrun.barca.com/overview/")
wrg.SetValueEx(key_1, "Data", 0, wrg.REG_SZ, ENV_USER_PROFILE+"\\AppData\\Local\\Barca\\packages\\speedrun\\0.1.0\\storage\\")
wrg.SetValueEx(key_1, "Theme", 0, wrg.REG_SZ, "Default")
wrg.SetValueEx(key_1, "ProfileID", 0, wrg.REG_SZ, ENV_USER_PROFILE+"\\AppData\\Local\\Barca\\packages\\speedrun\\0.1.0\\storage\\Profile UUID")
wrg.SetValueEx(key_1, "StartMenuWin", 0, wrg.REG_SZ, PROGRAM_FILES + "\\SpeedRun\\bin\\wspeedrun.exe")
wrg.SetValueEx(key_1, "EnvSpeedRunPath", 0, wrg.REG_SZ, "SPEED_RUN")

# PATH DIR
soft_speed_path = wrg.OpenKeyEx(location, r"SOFTWARE\\SpeedRun")
key_2 = wrg.CreateKey(soft_speed_path, "Path")
# creating values in SpeedRun/Path
wrg.SetValueEx(key_2, "Default", 0, wrg.REG_SZ, PROGRAM_FILES+"\\SpeedRun\\")
wrg.SetValueEx(key_2, "ExecutablePath", 0, wrg.REG_SZ, PROGRAM_FILES+"\\SpeedRun\\speedrun.exe")
wrg.SetValueEx(key_2, "SysInit", 0, wrg.REG_SZ, PROGRAM_FILES + "\\SpeedRun\\bin\\speedr.init")

# SETTINGS DIR
soft_speed_settings = wrg.OpenKeyEx(location, r"SOFTWARE\\SpeedRun")
key_3 = wrg.CreateKey(soft_speed_path, "Settings")
# creating values in SpeedRun/Settings
wrg.SetValueEx(key_3, "Default", 0, wrg.REG_SZ, "Basic")
wrg.SetValueEx(key_3, "Language", 0, wrg.REG_SZ, "pt_BR")

# RECENT FEATURES DIR
soft_speed_recent_feat = wrg.OpenKeyEx(location, r"SOFTWARE\\SpeedRun")
key_4 = wrg.CreateKey(soft_speed_recent_feat, "RecentFeatures")
# creating values in SpeedRun/RecentFeatures
wrg.SetValueEx(key_4, "Default", 0, wrg.REG_SZ,"")
wrg.SetValueEx(key_4, "ListFiles", 0, wrg.REG_SZ,"")
wrg.SetValueEx(key_4, "ListFunctions", 0, wrg.REG_SZ,"sysInit(); ")


if key_1:
    wrg.CloseKey(key_1)
if key_2:
    wrg.CloseKey(key_2)
if key_3:
    wrg.CloseKey(key_3)
if key_4:
    wrg.CloseKey(key_4)