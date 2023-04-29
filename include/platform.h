/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
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

#if defined(unix) || defined(__unix) || defined(__unix__)
#define SPEED_RUN_UNIX
#endif
#if defined(__APPLE__)
#define SPEED_RUN_APPLE
#endif
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define SPEED_RUN_WINDOWS
#endif

#if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(_M_X64)
#define SPEED_RUN_X86_64
#elif defined(__i386__) || defined(_M_IX86)
#define SPEED_RUN_X86_32
#endif
#if defined(SPEED_RUN_X86_64) || defined(SPEED_RUN_X86_32)
#define SPEED_RUN_X86
#endif
