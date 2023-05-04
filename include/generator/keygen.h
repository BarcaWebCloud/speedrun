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
#ifndef SPEED_RUN_KEYGEN
#define SPEED_RUN_KEYGEN

namespace speedrun {

	namespace KeyGen {
		#define GKNUMBERS       0x1
		#define GKUPPER_AZ      0x2
		#define GKLOWER_AZ      0x4
		#define GKBROADKEY      0x8
		#define GKNONREPETITION 0x16

		unsigned long GenerateSeed(void);
		
		bool GenerateKey(int iNewKeyLen, unsigned long lSeed, int iAttribs, char *sOutKey);
	}
	 
} 
#endif