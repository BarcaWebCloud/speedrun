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

#include "clean/cache.h"

namespace speedrun {

  CACHE::CACHE(const std::string& cacheSystem) : _cacheSystem(cacheSystem){}

  std::string& CACHE::cacheSystem() {
    if (_cacheSystem.empty()) {
      _cacheSystem = cleanCacheSystem();
    }
    return _cacheSystem;
  }

};