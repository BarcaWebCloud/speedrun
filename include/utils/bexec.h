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
#ifndef COMMAND_H
#define COMMAND_H
#include <array>
#include <cstdio>
#include <ostream>
#include <string>

namespace bexec {

struct CommandResult {
  std::string output;
  int exitstatus;
  friend std::ostream& operator<<(std::ostream& os, const CommandResult& result) {
    os << "command exitstatus: " << result.exitstatus << " output: " << result.output;
    return os;
  }
  bool operator==(const CommandResult& rhs) const { return output == rhs.output && exitstatus == rhs.exitstatus; }
  bool operator!=(const CommandResult& rhs) const { return !(rhs == *this); }
};

class Command {
 public:
  static CommandResult exec(const std::string& command) {
    int exitcode = 0;
    std::array<char, 8192> buffer{};
    std::string result;
#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#define WEXITSTATUS
#endif
    FILE* pipe = popen(command.c_str(), "r");
    if (pipe == nullptr) {
      throw std::runtime_error("popen() failed!");
    }
    try {
      std::size_t bytesread;
      while ((bytesread = std::fread(buffer.data(), sizeof(buffer.at(0)), sizeof(buffer), pipe)) != 0) {
        result += std::string(buffer.data(), bytesread);
      }
    } catch (...) {
      pclose(pipe);
      throw;
    }
    int res = pclose(pipe);
    exitcode = WEXITSTATUS(res);
    return CommandResult{result, exitcode};
  }

  static CommandResult execFgets(const std::string& command) {
    int exitcode = 0;
    std::array<char, 8192> buffer{};
    std::string result;
#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#define WEXITSTATUS
#endif
    FILE* pipe = popen(command.c_str(), "r");
    if (pipe == nullptr) {
      throw std::runtime_error("popen() failed!");
    }
    try {
      while (std::fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
      }
    } catch (...) {
      pclose(pipe);
      throw;
    }
    // todo: cannot take the address of an rvalue of type 'int'" on MacOS
    int res = pclose(pipe);
    exitcode = WEXITSTATUS(res);
    return CommandResult{result, exitcode};
  }
};
}
#endif  // COMMAND_H