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
#pragma once
#include "platform.h"
#include <stdio.h>
#ifdef SPEED_RUN_WINDOWS
#include <direct.h>
#define getDir _getcwd
#else
#include <unistd.h>
#define getDir getcwd
#endif
#include<iostream>
#include<dirent.h>
using namespace std;
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <Windows.h>
#include <winternl.h>

namespace fs = std::filesystem;

static std::string getCurrentDir(void) {
  char buff[FILENAME_MAX];
  getDir( buff, FILENAME_MAX );
  std::string currentDir(buff);

  return currentDir;
};

static std::string listDir(char* path) {
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);
  
  DIR *dr;
  struct dirent *en;
  dr = opendir(path);
  std::string listFilesAndFolders;
  if (dr) {
    while ((en = readdir(dr)) != NULL) {
      listFilesAndFolders += std::string("\n") + std::string(en->d_name);
    }
    closedir(dr);
  }
  return std::string(listFilesAndFolders);
};

static bool isDir(string path) {
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);
  bool result;

  std::filesystem::path current_dir = std::string(path);
  result = std::filesystem::is_directory(current_dir.parent_path());

  return result;
};
