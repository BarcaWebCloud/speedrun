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

#ifndef SPEED_RUN_KEYGEN_CXX
#define SPEED_RUN_KEYGEN_CXX

#include "generator/keygen.h"
#include <stdlib.h>
#include <sysinfoapi.h>

// #ifdef _USE_GLOBAL_MEMPOOL
// extern NSWFL::Memory::MemoryPool *pMem; //pMem must be defined and initalized elsewhere.
// #endif


namespace speedrun {

	namespace KeyGen {

		unsigned long GenerateSeed(void) {
			srand(GetTickCount());
			return rand();
		}

		bool GenerateKey(int iNewKeyLen, unsigned long lSeed, int iAttribs, char *sOutKey) {
			bool ValidValue = false;

			int iWPos = 0;
			unsigned char Random = 0;
			unsigned char LastValue = 0;

			if (!(iAttribs &GKNUMBERS) && !(iAttribs &GKUPPER_AZ)
				&& !(iAttribs &GKLOWER_AZ) && !(iAttribs &GKBROADKEY))
			{
				return false;
			}

			srand(lSeed);

			while (iWPos < iNewKeyLen) {
				Random = (unsigned char)rand() % 256;

				if (iAttribs &GKNUMBERS)  // 0 - 9
					if ((Random < 57) && (Random > 48))
						ValidValue = true;

				if (iAttribs &GKUPPER_AZ) // A - Z
					if ((Random < 90) && (Random > 65))
						ValidValue = true;

				if (iAttribs &GKLOWER_AZ) // a - z
					if ((Random < 122) && (Random > 97))
						ValidValue = true;

				if (iAttribs &GKBROADKEY) // Broad Key
					ValidValue = true;

				if (Random == 0)        ValidValue = false; // Null
				if (Random == 10)        ValidValue = false; // lf
				if (Random == 13)        ValidValue = false; // cr

				if (iAttribs &GKNONREPETITION) {
					if (Random == LastValue) {
						ValidValue = false;
					}
				}

				if (ValidValue) {
					sOutKey[iWPos] = Random;
					LastValue = Random;
					iWPos++;
				}
				ValidValue = false;
			}
			sOutKey[iWPos] = '\0';

			return true;
		}		
	}
}
#endif