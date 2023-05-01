/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaCorporation. 
 *    Project: BSCAN to scanner MotherBoards. CPU, Memory Ram, SO and more
 
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
#include "platform.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#ifdef SPEED_RUN_WINDOWS
  #include <Windows.h>
  #include "utils/bexec.h"
  #include <winternl.h>
  #include <filesystem>
  #include "WMIwrapper.h"
  #pragma comment(lib, "wbemuuid.lib")
  #include "clean/cache.h"
  #include "utils/directory.h"
  #include "utils/subprocess.h"

  using namespace std;
  using namespace bexec;

  namespace speedrun {

    std::string CACHE::cleanCacheSystem() { 
      SetConsoleCP(1252);
      SetConsoleOutputCP(1252);
      // shell:RecycleBinFolder
      std::string directories[2] = {
        "C:\\Windows\\Temp",
        "C:\\Windows\\Downloaded Program Files"  
      };
      // delete all files download software distribution
      system("del /q /f /s C:\\Windows\\SoftwareDistribution\\Download\\*");
      // delete all files prefetch
      system("del /q /f /s C:\\Windows\\Prefetch\\*");
      // delete all files %temp%
      system("del /q /f /s %temp%\\*");
      
      for (int i = 0; i < 3; i++) {
        if (isDir(directories[i])) {
          for (const auto& entry : std::filesystem::directory_iterator(directories[i])) {
            std::filesystem::remove_all(entry.path());
          }
        }
      }

      return "limpando arquivos..";
    }

  };

#endif  // END SPEED_RUN_WINDOWS