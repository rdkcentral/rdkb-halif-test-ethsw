/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2023 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <ut.h>
#include <ut_log.h>
#include <stdlib.h>
#include "ccsp_hal_ethsw.h"

extern int MaxEthPort;
extern int register_hal_tests( void );

int init_ethsw_hal_init(void)
{
    int ret = 0;
    ret = CcspHalEthSwInit();
    if (ret == 0)
    {
        UT_LOG("ethsw_hal_Init returned success");
    }
    else
    {
        UT_LOG("ethsw_hal_Init returned failure");
        UT_FAIL("ethsw_hal_Init initialization failed");
    }
    return 0;
}

int main(int argc, char** argv)
{
     /* Register tests as required, then call the UT-main to support switches and triggering */
    UT_init( argc, argv );
    /* Check if tests are registered successfully */
    int registerReturn = register_hal_tests();
    if (registerReturn == 0)
    {
        printf("register_hal_tests() returned success \n");
    }
    else
    {
        printf("register_hal_tests() returned failure");
        return 1;
    }
    UT_run_tests();
    
    return 0;
}
