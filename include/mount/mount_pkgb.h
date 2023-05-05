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
#ifndef SPEED_RUN_MOUNT_PKGB
#define SPEED_RUN_MOUNT_PKGB

namespace speedrun {

	namespace MOUNT {
		// generator pkgb speed run cli bwc
		bool GenPKSpeedRunCLI_BWC(void);
		// generator pkgb speed run program files
		bool GenPKSpeedRunProgramFiles_x64(void);
		bool GenPKSpeedRunProgramFiles_x86(void);
		// generator pkgb speed run appdata local & roaming
		bool GenPKSpeedRunAppData_ROAMING(void);
		bool GenPKSpeedRunAppData_LOCAL(void);
	}
} 
#endif