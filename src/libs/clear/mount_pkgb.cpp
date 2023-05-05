/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaCorporation. 
 *    Project: Speed Run To Clean Your System And Gain More Performance
 
 * This software is licensed as described in the file COPYING, which                    
 * you should have received as part of this distribution. The terms                     
 * are also available at https://BarcaCorporation.github.io/docs/copyright.html.           
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell             
 * copies of the Software, and permit persons to whom the Software is                   
 * furnished to do so, under the terms of the COPYING file.                             
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY            
 * KIND, either express or implied.                                                      
 *
 **************************************************************************************/
#include <regex>
#include <string>
#include <vector>

#if defined(unix) || defined(__unix) || defined(__unix__)
  #include "utils/subprocess.h"
#elif defined(__APPLE__)
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
  #include "WMIwrapper.h"
  #pragma comment(lib, "wbemuuid.lib")
#endif

#ifndef SPEED_RUN_MOUNT_PKGB_CXX
#define SPEED_RUN_MOUNT_PKGB_CXX

#include <filesystem>
#include <direct.h>
#include <config.h>
using namespace std;
namespace fs = std::filesystem;

#include "mount/mount_pkgb.h"

static const std::filesystem::path subdirectories_speed_run2bwc[] = {
  "data/Log",
  "data/History",
  "config/Preferences",
  "config/Support"
};

static const std::filesystem::path subdirectories_program_files[] = {
  "docs/assets",
  "docs/src",
  "docs/assets/css",
  "docs/assets/img",
  "docs/assets/img/icon",
  "docs/assets/img/logo",
  "bin/cmd",
  "client/public",
  "client/libs",
  "client/src",
  "data/log",
  "data/tmp",
  "installer/server",
  "libs/server",
  "locales/pt_BR",
  "locales/en",
  "locales/et",
  "locales/fr",
  "locales/pt",
  "locales/el",
  "locales/eu",
  "locales/de",
  "locales/da",
  "locales/is",
  "locales/ka",
  "locales/ko",
  "locales/rs",
  "locales/it",
  "locales/ca"
};


namespace speedrun {

	namespace MOUNT {

		bool GenPKSpeedRunCLI_BWC(void) {
		  char speed_run_bwc_mount[256];
		  GetEnvironmentVariable("USERPROFILE", speed_run_bwc_mount, sizeof(speed_run_bwc_mount));
		  strcat(speed_run_bwc_mount,"\\.bwc\\pkgb\\.store\\");
		  strcat(speed_run_bwc_mount, "barca.cloud.");
		  strcat(speed_run_bwc_mount, PROJECT_NAME);
		  strcat(speed_run_bwc_mount, ".cli.");
		  strcat(speed_run_bwc_mount, PROJECT_VERSION);
		  mkdir(speed_run_bwc_mount);
		  // mount speedrun package for bwc
		  fs::path folder_bwc = speed_run_bwc_mount;
		  for (auto &subdirectory: subdirectories_speed_run2bwc) {
		    std::filesystem::create_directories(folder_bwc / PROJECT_VERSION / subdirectory);
		  }

			return true;
		}

		bool GenPKSpeedRunProgramFiles_x64(void) {
		  fs::path folder_Documents = "C:\\Program Files\\Barca\\pkgb";
		  for (auto &subdirectory: subdirectories_program_files) {
		    std::filesystem::create_directories(folder_Documents / PROJECT_NAME / subdirectory);
		  }

			return true;
		}

		bool GenPKSpeedRunProgramFiles_x86(void) {
		  fs::path folder_Documents = "C:\\Program Files(x86)\\Barca\\pkgb";
		  for (auto &subdirectory: subdirectories_program_files) {
		    std::filesystem::create_directories(folder_Documents / PROJECT_NAME / subdirectory);
		  }

			return true;
		}

		bool GenPKSpeedRunAppData_LOCAL() {
		  char speed_run_mount[256];
		  GetEnvironmentVariable("USERPROFILE", speed_run_mount, sizeof(speed_run_mount));
		  strcat(speed_run_mount,"\\AppData\\Local\\Barca\\pkgb\\");
		  strcat(speed_run_mount, PROJECT_NAME);
		  strcat(speed_run_mount, "-v");
		  strcat(speed_run_mount, PROJECT_VERSION);
		  mkdir(speed_run_mount);

		  return true;
		}
		bool GenPKSpeedRunAppData_ROAMING() {
		  char speed_run_mount_2[256];
		  GetEnvironmentVariable("USERPROFILE", speed_run_mount_2, sizeof(speed_run_mount_2));
		  strcat(speed_run_mount_2,"\\AppData\\Roaming\\Barca\\pkgb\\");
		  strcat(speed_run_mount_2, PROJECT_NAME);
		  strcat(speed_run_mount_2, "-v");
		  strcat(speed_run_mount_2, PROJECT_VERSION);
		  mkdir(speed_run_mount_2);

		  return true;
		}
	}
}
#endif