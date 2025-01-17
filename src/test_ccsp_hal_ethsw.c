/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2016 RDK Management
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

/**
* @file test_ccsp_hal_ethsw.c
* @page ccsp_hal_ethsw Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios).
* This is to ensure that the ccsp_hal_ethsw APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "ccsp_hal_ethsw.h"

#define MAX_SIZE 256

char *mac;

extern int init_ethsw_hal_init(void);

/**
* @brief Test case to verify the functionality of CcspHalEthSwInit API.
*
* This test case checks if the CcspHalEthSwInit API initializes the Ethernet Switch module correctly.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 001
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Invoke CcspHalEthSwInit API | No input data | The API should initialize the Ethernet Switch module | The return value should be RETURN_OK |
*/
void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwInit(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwInit...");

    UT_LOG("Invoking CcspHalEthSwInit.");
    // Invoke the API
    INT result = CcspHalEthSwInit();
    UT_LOG("Return Value: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Log the test description and result
    UT_LOG("Invoking CcspHalEthSwInit produces RETURN_OK");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwInit...");
}

/**
* @brief This test case is used to verify the functionality of the CcspHalEthSwGetPortStatus API in the ccsp_hal_ethsw_positive1 test suite.
*
* The test checks if the CcspHalEthSwGetPortStatus API returns the expected value and sets the corresponding output parameters correctly.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 002
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
*
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Invoke CcspHalEthSwGetPortStatus with valid parameters | PortId = CCSP_HAL_ETHSW_EthPort1, pLinkRate = valid, pDuplexMode = valid, pStatus = valid | The API should return RETURN_OK and set the pLinkRate, pDuplexMode, and pStatus values correctly | Should be successful |
*/

void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_STATUS));

    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = CCSP_HAL_ETHSW_EthPort1, pLinkRate = valid, pDuplexMode = valid, pStatus = valid...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);
    UT_LOG("pLinkRate: %d", *pLinkRate);
    UT_LOG("pDuplexMode: %d", *pDuplexMode);
    UT_LOG("pStatus: %d", *pStatus);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    free(pLinkRate);
    free(pDuplexMode);
    free(pStatus);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortStatus...");
}

/**
 * @brief This test case verifies the functionality of the CcspHalEthSwGetPortStatus API.
 *
 * This test case checks the behavior of the CcspHalEthSwGetPortStatus API when invoked with valid inputs for PortId,
 * pLinkRate, pDuplexMode, and pStatus.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 003
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 *  | Variation / Step | Description                                                  | Test Data                                                                             | Expected Result                         | Notes               |
 *  | :--------------: | ------------------------------------------------------------ | ------------------------------------------------------------------------------------- | --------------------------------------- | ------------------- |
 *  |       01         | Invoking CcspHalEthSwGetPortStatus with valid inputs.        | PortId = CCSP_HAL_ETHSW_EthPort4, pLinkRate = valid, pDuplexMode = valid, pStatus = valid | The function returns RETURN_OK.         | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort4;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_STATUS));

    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = CCSP_HAL_ETHSW_EthPort4, pLinkRate = valid, pDuplexMode = valid, pStatus = valid...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);
    UT_LOG("pLinkRate: %d", *pLinkRate);
    UT_LOG("pDuplexMode: %d", *pDuplexMode);
    UT_LOG("pStatus: %d", *pStatus);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    free(pLinkRate);
    free(pDuplexMode);
    free(pStatus);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortStatus...");
}

/**
 * @brief This test verifies the functionality of CcspHalEthSwGetPortStatus API.
 *
 * The purpose of this test is to check whether the CcspHalEthSwGetPortStatus API is working correctly
 * by invoking it with valid parameters and verifying the result and output values.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 004
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via the console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description                                                     | Test Data                                                                                                        | Expected Result | Notes             |
 * | :---------------: | --------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- | --------------- | ----------------- |
 * |       01       | The API is invoked with valid parameters                 | PortId = CCSP_HAL_ETHSW_EthPort4, pLinkRate = valid, pDuplexMode = valid, pStatus = valid | The API returns RETURN_OK and the output values are valid      | Should be successful |
 *
 */
void test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort4;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_STATUS));

    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = CCSP_HAL_ETHSW_EthPort4, pLinkRate = valid, pDuplexMode = valid, pStatus = valid...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);
    UT_LOG("pLinkRate: %d", *pLinkRate);
    UT_LOG("pDuplexMode: %d", *pDuplexMode);
    UT_LOG("pStatus: %d", *pStatus);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    free(pLinkRate);
    free(pDuplexMode);
    free(pStatus);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortStatus...");
}

/**
 * @brief Unit test for CcspHalEthSwGetPortStatus function when PortId is beyond CCSP_HAL_ETHSW_PortMax.
 *
 * This test verifies the behavior of CcspHalEthSwGetPortStatus function when the PortId provided is beyond the maximum limit defined by CCSP_HAL_ETHSW_PortMax constant.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 005
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | --------------- | ----- |
 * | 01 | Invoke CcspHalEthSwGetPortStatus with PortId beyond CCSP_HAL_ETHSW_PortMax | PortId = 21 | RETURN_ERR | Should return RETURN_ERR |
 */
void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = 21;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_STATUS));

    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = 21 (Beyond CCSP_HAL_ETHSW_PortMax), pLinkRate = valid, pDuplexMode = valid, pStatus = valid...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    free(pLinkRate);
    free(pDuplexMode);
    free(pStatus);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortStatus...");
}

/**
* @brief This test validates the behavior of CcspHalEthSwGetPortStatus function with a Port Id below the valid range.
*
* This test verifies the behavior of CcspHalEthSwGetPortStatus function when called with a Port Id value below the valid range.
* The function should return an error code to indicate the invalid Port Id.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 006
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
*  | Variation / Step | Description | Test Data | Expected Result | Notes |
*  | :----: | --------- | ---------- | -------------- | ----- |
*  | 01 | Invoking CcspHalEthSwGetPortStatus with PortId below the valid range | PortId = 0, pLinkRate = valid, pDuplexMode = valid, pStatus = valid | RETURN_ERR | Should return an error code |
*/

void test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = 0;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = NULL;
    
    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = 0 (Below range), pLinkRate = valid, pDuplexMode = valid, pStatus = valid...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    free(pLinkRate);
    free(pDuplexMode);
    free(pStatus);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortStatus...");
}


/**
* @brief Test the CcspHalEthSwGetPortStatus function with invalid inputs
*
* This test checks if the CcspHalEthSwGetPortStatus function returns the expected error when invalid input parameters are provided.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 008
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
*  | Variation / Step | Description | Test Data | Expected Result | Notes |
*  | :----: | --------- | ---------- |-------------- | ----- |
*  | 01 | Invoking CcspHalEthSwGetPortStatus with invalid parameters | PortId = CCSP_HAL_ETHSW_EthPort1, pLinkRate = NULL, pDuplexMode = valid, pStatus = valid | RETURN_ERR | Should return the expected error value |
*/

void test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = NULL;
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_STATUS));

    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = CCSP_HAL_ETHSW_EthPort1, pLinkRate = NULL, pDuplexMode = valid, pStatus = valid...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    free(pDuplexMode);
    free(pStatus);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortStatus...");
}

/**
* @brief This test case is designed to test the CcspHalEthSwGetPortStatus function in a negative scenario.
*
* This test case verifies the behavior of the CcspHalEthSwGetPortStatus function when invoked with invalid input parameters.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 009
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Invoking CcspHalEthSwGetPortStatus with PortId = CCSP_HAL_ETHSW_EthPort2, pLinkRate = valid, pDuplexMode = NULL, pStatus = valid | PortId = CCSP_HAL_ETHSW_EthPort2, pLinkRate = valid, pDuplexMode = NULL, pStatus = valid | RETURN_ERR | Should be unsuccessful |
*/
void test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort2;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = NULL;
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_STATUS));

    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = CCSP_HAL_ETHSW_EthPort2, pLinkRate = valid, pDuplexMode = NULL, pStatus = valid...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    free(pLinkRate);
    free(pStatus);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwGetPortStatus...");
}

/**
* @brief Test the CcspHalEthSwGetPortStatus function with NULL pointers for link rate, duplex mode, and link status.
*
* This test case is to verify the behavior of the CcspHalEthSwGetPortStatus function when NULL pointers are passed as arguments for link rate, duplex mode, and link status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 011
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step   | Description   | Test Data   | Expected Result   | Notes   |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Verify behavior with NULL pointers | PortId: CCSP_HAL_ETHSW_EthPort4, pLinkRate: NULL, pDuplexMode: NULL, pStatus: NULL | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_ccsp_hal_ethsw_negative5_CcspHalEthSwGetPortStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative5_CcspHalEthSwGetPortStatus...");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort4;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = NULL;
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = NULL;
    PCCSP_HAL_ETHSW_LINK_STATUS pStatus = NULL;

    UT_LOG("Invoking CcspHalEthSwGetPortStatus with PortId = CCSP_HAL_ETHSW_EthPort4, pLinkRate = NULL, pDuplexMode = NULL, pStatus = NULL...");
    INT result = CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
    UT_LOG("Result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative5_CcspHalEthSwGetPortStatus...");
}

/**
* @brief This test is to validate the functionality of the CcspHalEthSwGetPortCfg API with valid port ID and Ethernet port
*
* The purpose of this test is to verify that the CcspHalEthSwGetPortCfg API correctly retrieves the configuration for a given port ID, specifically for Ethernet ports.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 012
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Retrieve configuration for valid Ethernet port | PortId = CCSP_HAL_ETHSW_EthPort1 | The API should return RETURN_OK | Should be successful |
*/

void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortCfg()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortCfg...");

    // Set up test inputs
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwGetPortCfg with PortId = CCSP_HAL_ETHSW_EthPort1");
    INT result = CcspHalEthSwGetPortCfg(PortId, pLinkRate, pDuplexMode);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Verify the output values (if any)
    UT_LOG("LinkRate: %d, DuplexMode: %d", *pLinkRate, *pDuplexMode);

    // Clean up
    free(pLinkRate);
    free(pDuplexMode);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortCfg...");
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 013@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set up test inputs | PortId = CCSP_HAL_ETHSW_EthPort2, pLinkRate = address of allocated memory, pDuplexMode = address of allocated memory | - | - |
* | 02 | Invoke the API | PortId, pLinkRate, pDuplexMode | RETURN_OK | Should return without any error |
* | 03 | Verify the output values | PortId, pLinkRate, pDuplexMode | LinkRate and DuplexMode values | Should match the expected values |
* | 04 | Clean up | pLinkRate, pDuplexMode | - | - |
*/
void test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortCfg()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortCfg...");

    // Set up test inputs
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort2;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwGetPortCfg with PortId = CCSP_HAL_ETHSW_EthPort2");
    INT result = CcspHalEthSwGetPortCfg(PortId, pLinkRate, pDuplexMode);
    UT_LOG("Result: %d", result);


    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Verify the output values (if any)
    UT_LOG("LinkRate: %d, DuplexMode: %d", *pLinkRate, *pDuplexMode);

    // Clean up
    free(pLinkRate);
    free(pDuplexMode);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortCfg...");
}

/**
* @brief Test case to verify the behavior of CcspHalEthSwGetPortCfg when an invalid port ID below the range is provided as input.
*
* This test case checks if the CcspHalEthSwGetPortCfg function handles the scenario where an invalid port ID below the range is provided as input parameter. The function should return an error value to indicate the invalid input.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 018
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Test with invalid port ID below the range | PortId = 0 | Return value should be RETURN_ERR | Should return an error |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortCfg()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortCfg...");

    // Set up test inputs
    CCSP_HAL_ETHSW_PORT PortId = 0; // Invalid port ID below range
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwGetPortCfg_InvalidPortIdBelowRange.");
    INT result = CcspHalEthSwGetPortCfg(PortId, pLinkRate, pDuplexMode);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortCfg...");
}

/**
* @brief Test the scenario where a null pointer is passed for pLinkRate parameter in CcspHalEthSwGetPortCfg function.
*
* This test verifies the behavior of the CcspHalEthSwGetPortCfg function when a null pointer is passed for the pLinkRate parameter. The expected result is that the function returns RETURN_ERR.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 020
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Test with a null pointer for pLinkRate | PortId = CCSP_HAL_ETHSW_EthPort1, pLinkRate = NULL, pDuplexMode = valid pointer | Function should return RETURN_ERR | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortCfg()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortCfg...");

    // Set up test inputs
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = NULL; // Null pointer for pLinkRate
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = malloc(sizeof(PCCSP_HAL_ETHSW_DUPLEX_MODE));

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwGetPortCfg_NullPointerForLinkRate.");
    INT result = CcspHalEthSwGetPortCfg(PortId, pLinkRate, pDuplexMode);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortCfg...");
}

/**
 * @brief Test objective: Test for handling null pointer for duplex mode in CcspHalEthSwGetPortCfg function.
 *
 * This test is performed to verify the behavior of the CcspHalEthSwGetPortCfg function when a null pointer is passed for the duplex mode parameter.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 021
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Invoke CcspHalEthSwGetPortCfg with null pointer for duplex mode | PortId = CCSP_HAL_ETHSW_EthPort1 | Returns RETURN_ERR | Should return RETURN_ERR |
 */
void test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortCfg()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortCfg...");

    // Set up test inputs
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    PCCSP_HAL_ETHSW_LINK_RATE pLinkRate = malloc(sizeof(PCCSP_HAL_ETHSW_LINK_RATE));
    PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode = NULL; // Null pointer for pDuplexMode

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwGetPortCfg_NullPointerForDuplexMode.");
    INT result = CcspHalEthSwGetPortCfg(PortId, pLinkRate, pDuplexMode);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortCfg...");
}

/**
 * @brief Unit test for CcspHalEthSwSetPortCfg function.
 *
 * This test verifies the behavior of CcspHalEthSwSetPortCfg function by setting the port configuration and checking the return value.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 022
 * **Priority:** High
 *
 * **Pre-Conditions:**
 * - None
 *
 * **Dependencies:**
 * - None
 *
 * **User Interaction:**
 * - If the user chooses to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * - | Variation / Step | Description | Test Data | Expected Result | Notes |
 *   | :----: | --------- | ---------- | -------------- | ----- |
 *   | 01 | Set port configuration | PortId = CCSP_HAL_ETHSW_EthPort1, LinkRate = CCSP_HAL_ETHSW_LINK_10Mbps, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Half | RETURN_OK | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortCfg(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortCfg...\n");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    CCSP_HAL_ETHSW_LINK_RATE LinkRate = CCSP_HAL_ETHSW_LINK_10Mbps;
    CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Half;

    UT_LOG("Invoking CcspHalEthSwSetPortCfg with PortId = CCSP_HAL_ETHSW_EthPort1, LinkRate = CCSP_HAL_ETHSW_LINK_10Mbps, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Half\n");
    INT ret = CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
    UT_LOG("Return value: %d\n", ret);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortCfg...\n");
}

/**
 * @brief This test case checks the positive scenario for CcspHalEthSwSetPortCfg function.
 *
 * This test case verifies if the CcspHalEthSwSetPortCfg function correctly sets the port configuration for the given PortId, LinkRate, and DuplexMode.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 023
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Setting the port configuration | PortId = CCSP_HAL_ETHSW_EthPort2, LinkRate = CCSP_HAL_ETHSW_LINK_Auto, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto | Success | Should successfully set the port configuration |
 */
void test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortCfg(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortCfg...\n");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort2;
    CCSP_HAL_ETHSW_LINK_RATE LinkRate = CCSP_HAL_ETHSW_LINK_Auto;
    CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto;

    UT_LOG("Invoking CcspHalEthSwSetPortCfg with PortId = CCSP_HAL_ETHSW_EthPort2, LinkRate = CCSP_HAL_ETHSW_LINK_Auto, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto\n");
    INT ret = CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
    UT_LOG("Return value: %d\n", ret);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortCfg...\n");
}


/**
* @brief Test function to verify the functionality of CcspHalEthSwSetPortCfg
*
* This test case is designed to verify the functionality of CcspHalEthSwSetPortCfg API.
* The test sets the input parameters PortId, LinkRate, and DuplexMode with specific values and invokes the API.
* It then checks the return value of the API invocation against the expected value.
* The test aims to ensure that the API is working correctly with the given input parameters.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 025
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description                     | Test Data                                              | Expected Result                                   | Notes            |
* | :--------------: | ------------------------------  | ----------------------------------------------------- | ----------------------------------------------- | ---------------- |
* |        01        | Invoking CcspHalEthSwSetPortCfg  | PortId = CCSP_HAL_ETHSW_EthPort3, LinkRate = CCSP_HAL_ETHSW_LINK_1Gbps, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Full | RETURN_OK                           | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwSetPortCfg(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwSetPortCfg...\n");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort3;
    CCSP_HAL_ETHSW_LINK_RATE LinkRate = CCSP_HAL_ETHSW_LINK_1Gbps;
    CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Full;

    UT_LOG("Invoking CcspHalEthSwSetPortCfg with PortId = CCSP_HAL_ETHSW_EthPort4, LinkRate = CCSP_HAL_ETHSW_LINK_10Mbps, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Half\n");
    INT ret = CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
    UT_LOG("Return value: %d\n", ret);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwSetPortCfg...\n");
}

/**
 * @brief This test verifies the negative scenario where an invalid PortId is passed to the CcspHalEthSwSetPortCfg function.
 *
 * This test case verifies the behavior of the CcspHalEthSwSetPortCfg function when an invalid PortId is passed as an argument. The expected result is that the function should return an error code.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 026
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------------:  | ----------- | --------- | --------------- | ------ |
 * | 01              | Verifies the behavior of CcspHalEthSwSetPortCfg when an invalid PortId is passed as an argument. | PortId = 0, LinkRate = CCSP_HAL_ETHSW_LINK_1Gbps, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto | Error code should be returned | The function should fail due to an invalid PortId |
 */
void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortCfg(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortCfg...\n");

    CCSP_HAL_ETHSW_PORT PortId = 0; // Invalid PortId
    CCSP_HAL_ETHSW_LINK_RATE LinkRate = CCSP_HAL_ETHSW_LINK_1Gbps;
    CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto;

    UT_LOG("Invoking CcspHalEthSwSetPortCfg with PortId = 0, LinkRate = CCSP_HAL_ETHSW_LINK_1Gbps, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto\n");
    INT ret = CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
    UT_LOG("Return value: %d\n", ret);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortCfg...\n");
}

/**
* @brief This test case is used to test the negative scenario of the CcspHalEthSwSetPortCfg function.
*
* The objective of this test is to check if the function returns the expected error code when provided with invalid input.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 027
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | ---------- | --------- | -------------- | ------ |
* | 01     | Check invalid LinkRate | PortId = CCSP_HAL_ETHSW_EthPort2, LinkRate = 8, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Full | RETURN_ERR | Should return the expected error code |
*/

void test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortCfg(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortCfg...\n");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort2;
    CCSP_HAL_ETHSW_LINK_RATE LinkRate = 8; // Invalid LinkRate
    CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Full;

    UT_LOG("Invoking CcspHalEthSwSetPortCfg with PortId = CCSP_HAL_ETHSW_EthPort2, LinkRate = 8, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Full\n");
    INT ret = CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
    UT_LOG("Return value: %d\n", ret);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortCfg...\n");
}

/**
 * @brief This test case is used to verify the behavior of CcspHalEthSwSetPortCfg function when an invalid DuplexMode is provided.
 *
 * In this test case, CcspHalEthSwSetPortCfg function is invoked with an invalid DuplexMode. The objective of this test is to ensure that the function returns an expected error code in this scenario.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 028
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * 1. First, set the Port ID to CCSP_HAL_ETHSW_Moca2.
 * 2. Then, set the Link Rate to CCSP_HAL_ETHSW_LINK_100Mbps.
 * 3. Finally, set an invalid DuplexMode value (3).
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | --------------- | ----- |
 * | 01 | First set of conditions | PortId = CCSP_HAL_ETHSW_Moca2, LinkRate = CCSP_HAL_ETHSW_LINK_100Mbps, DuplexMode = 3 | RETURN_ERR | Should return an error |
 */
void test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortCfg(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortCfg...\n");

    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_Moca2;
    CCSP_HAL_ETHSW_LINK_RATE LinkRate = CCSP_HAL_ETHSW_LINK_100Mbps;
    CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode = 3; // Invalid DuplexMode

    UT_LOG("Invoking CcspHalEthSwSetPortCfg with PortId = CCSP_HAL_ETHSW_Moca2, LinkRate = CCSP_HAL_ETHSW_LINK_100Mbps, DuplexMode = 3\n");
    INT ret = CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
    UT_LOG("Return value: %d\n", ret);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortCfg...\n");
}

/**
* @brief This function tests the negative scenario of CcspHalEthSwSetPortCfg API.
*
* This test checks if the API returns the expected result when invalid values are used for PortId and LinkRate.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 029
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | First set of conditions | PortId = 21, LinkRate = 9, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto | RETURN_ERR | Should be unsuccessful |
*
* @param None
* @return None
*/
void test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwSetPortCfg(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwSetPortCfg...\n");

    CCSP_HAL_ETHSW_PORT PortId = 21; // Invalid PortId
    CCSP_HAL_ETHSW_LINK_RATE LinkRate = CCSP_HAL_ETHSW_LINK_10Gbps; // Invalid LinkRate
    CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto;

    UT_LOG("Invoking CcspHalEthSwSetPortCfg with PortId = 21, LinkRate = 9, DuplexMode = CCSP_HAL_ETHSW_DUPLEX_Auto\n");
    INT ret = CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
    UT_LOG("Return value: %d\n", ret);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwSetPortCfg...\n");
}

/**
* @brief This test case is used to verify the functionality of the CcspHalEthSwGetPortAdminStatus function.
*
* This test case checks if the CcspHalEthSwGetPortAdminStatus function returns the correct port administrative status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 030
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set input parameters and call the API | PortId = CCSP_HAL_ETHSW_EthPort1, pAdminStatus = ... | Verify that the API returns RETURN_OK and the administrative status is correct. | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortAdminStatus(void)
{
    // Log entering test function
   UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus;

    // Call the API
    UT_LOG("Invoking CcspHalEthSwGetPortAdminStatus with PortId= %d", PortId);
    INT retStatus = CcspHalEthSwGetPortAdminStatus(PortId, &AdminStatus);
    UT_LOG("Return status: retStatus=%d", retStatus);

    // Verify return value
    UT_ASSERT_EQUAL(retStatus, RETURN_OK);

    // Verify output values
    UT_ASSERT_EQUAL(AdminStatus, CCSP_HAL_ETHSW_AdminUp);

    // output values
    UT_LOG("Output values: AdminStatus=%d", AdminStatus);

    // Log exiting test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortAdminStatus...");
}

/**
* @brief Test case to verify the functionality of CcspHalEthSwGetPortAdminStatus function when the input parameters are valid.
*
* The purpose of this test case is to ensure that the CcspHalEthSwGetPortAdminStatus function returns the expected
* return status and output values when valid input parameters are provided.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 031
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking CcspHalEthSwGetPortAdminStatus function with valid input parameters | PortId = CCSP_HAL_ETHSW_EthPort2, pAdminStatus = ... | RETURN_OK | Output value should be successfully retrieved |
*/
void test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortAdminStatus(void)
{
    // Log entering test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort2;
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus;

    // Call the API
    UT_LOG("Invoking CcspHalEthSwGetPortAdminStatus with PortId= %d", PortId);
    INT retStatus = CcspHalEthSwGetPortAdminStatus(PortId, &AdminStatus);
    UT_LOG("Return status: retStatus=%d", retStatus);

    // Verify return value
    UT_ASSERT_EQUAL(retStatus, RETURN_OK);

    // Verify output values
    UT_ASSERT_EQUAL(AdminStatus, CCSP_HAL_ETHSW_AdminUp);

    // output values
    UT_LOG("Output values: AdminStatus=%d", AdminStatus);

    // Log exiting test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortAdminStatus...");
}

/**
* @brief Test case to verify CcspHalEthSwGetPortAdminStatus function.
*
* This test case is used to verify the functionality of the CcspHalEthSwGetPortAdminStatus API.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 032
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set input parameters and call the API | PortId=CCSP_HAL_ETHSW_EthPort3, pAdminStatus= ... | RETURN_OK | Verify that the API returns success |
*/
void test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortAdminStatus(void)
{
    // Log entering test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort3;
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus;

    // Call the API
    UT_LOG("Invoking CcspHalEthSwGetPortAdminStatus with PortId= %d", PortId);
    INT retStatus = CcspHalEthSwGetPortAdminStatus(PortId, &AdminStatus);
    UT_LOG("Return status: retStatus=%d", retStatus);

    // Verify return value
    UT_ASSERT_EQUAL(retStatus, RETURN_OK);

    // Verify output values
    //UT_ASSERT_EQUAL(AdminStatus, CCSP_HAL_ETHSW_AdminDown);

    // output values
    UT_LOG("Output values: AdminStatus=%d", AdminStatus);

    // Log exiting test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortAdminStatus...");
}

/**
* @brief Test for CcspHalEthSwGetPortAdminStatus function
*
* This test is designed to verify the functionality of the CcspHalEthSwGetPortAdminStatus function. It checks if the function returns the correct output values and handling of input parameters.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 033
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke CcspHalEthSwGetPortAdminStatus with valid PortId and pAdminStatus parameter | PortId = CCSP_HAL_ETHSW_EthPort4, pAdminStatus = ... | The function should return RETURN_OK and the value should be correctly assigned to pAdminStatus | Should be successful |
*/

void test_l1_ccsp_hal_ethsw_positive4_CcspHalEthSwGetPortAdminStatus(void)
{
    // Log entering test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive4_CcspHalEthSwGetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort4;
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus;

    // Call the API
    UT_LOG("Invoking CcspHalEthSwGetPortAdminStatus with PortId= %d", PortId);
    INT retStatus = CcspHalEthSwGetPortAdminStatus(PortId, &AdminStatus);
    UT_LOG("Return status: retStatus=%d", retStatus);

    // Verify return value
    UT_ASSERT_EQUAL(retStatus, RETURN_OK);

    // Verify output values
    //UT_ASSERT_EQUAL(AdminStatus, CCSP_HAL_ETHSW_AdminTest);

    //output values
    UT_LOG("Output values: AdminStatus=%d", AdminStatus);

    // Log exiting test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive4_CcspHalEthSwGetPortAdminStatus...");
}

/**
* @brief Test case to verify the behavior of CcspHalEthSwGetPortAdminStatus function with invalid input.
*
* This test case checks the behavior of the CcspHalEthSwGetPortAdminStatus function when called with invalid input values. It verifies if the function returns the expected error value and logs the input values and return status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 034
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | --------------- | ----- |
* | 01 | First set of conditions | PortId = 0, pAdminStatus = ... | RETURN_ERR | Should return an error value |
*/

void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortAdminStatus(void)
{
    // Log entering test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = 0; // Below range
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus;

    // Call the API
    UT_LOG("Invoking CcspHalEthSwGetPortAdminStatus with PortId= %d", PortId);
    INT retStatus = CcspHalEthSwGetPortAdminStatus(PortId, &AdminStatus);
    UT_LOG("Return status: retStatus=%d", retStatus);

    // Verify return value
    UT_ASSERT_EQUAL(retStatus, RETURN_ERR);

    // Log exiting test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortAdminStatus...");
}

/**
* @brief Test case to verify the behavior of CcspHalEthSwGetPortAdminStatus when an invalid PortId is provided.
*
* This test case checks the behavior of the CcspHalEthSwGetPortAdminStatus function when an invalid PortId, which is above the valid range, is provided. The test aims to ensure that the function handles invalid input correctly and returns an error status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 035
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking the function with an invalid PortId above the range | PortId = 21, pAdminStatus = ... | retStatus = RETURN_ERR | Should return an error status |
*/

void test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortAdminStatus(void)
{
    // Log entering test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = 21; // Above range
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus;

    // Call the API
    UT_LOG("Invoking CcspHalEthSwGetPortAdminStatus with PortId= %d", PortId);
    INT retStatus = CcspHalEthSwGetPortAdminStatus(PortId, &AdminStatus);
    UT_LOG("Return status: retStatus=%d", retStatus);

    // Verify return value
    UT_ASSERT_EQUAL(retStatus, RETURN_ERR);

    // Log exiting test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortAdminStatus...");
}

/**
* @brief Test case to validate the CcspHalEthSwGetPortAdminStatus API in negative scenario
*
* This test case is used to validate the functionality of CcspHalEthSwGetPortAdminStatus API in negative scenario. It verifies that the API returns an error when called with an invalid input.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 036
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Call API with invalid PortId | PortId = -1, pAdminStatus = NULL | Should return RETURN_ERR | - |
*/
void test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortAdminStatus(void)
{
    // Log entering test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = -1;
    PCCSP_HAL_ETHSW_ADMIN_STATUS pAdminStatus = NULL;

    // Call the API
    UT_LOG("Invoking CcspHalEthSwGetPortAdminStatus with PortId=%d, pAdminStatus=%p",PortId, pAdminStatus);
    INT retStatus = CcspHalEthSwGetPortAdminStatus(PortId, pAdminStatus);
    UT_LOG("Return status: retStatus=%d", retStatus);

    // Verify return value
    UT_ASSERT_EQUAL(retStatus, RETURN_ERR);

    // Log exiting test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortAdminStatus...");
}

/**
* @brief Test the functionality of CcspHalEthSwSetPortAdminStatus when valid Ethernet port ID is provided with AdminUp status.
*
* This test case verifies the behavior of CcspHalEthSwSetPortAdminStatus API when a valid Ethernet port ID is provided
* with AdminUp status. The objective of this test is to ensure that the API sets the admin status of the specified port
* to Up and returns the expected result.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 037
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set port admin status to Up with valid Ethernet port ID | PortId = CCSP_HAL_ETHSW_EthPort1, AdminStatus = CCSP_HAL_ETHSW_AdminUp | RETURN_OK | Should be successful |
*/

void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortAdminStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort1;
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus = CCSP_HAL_ETHSW_AdminUp;

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwSetPortAdminStatus with PortId = %d, AdminStatus = %d", PortId, AdminStatus);
    INT result = CcspHalEthSwSetPortAdminStatus(PortId, AdminStatus);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortAdminStatus...");
}

/**
* @brief Test the functionality of CcspHalEthSwSetPortAdminStatus when valid Ethernet port ID is provided with AdminUp status.
*
* This test case verifies the behavior of CcspHalEthSwSetPortAdminStatus API when a valid Ethernet port ID is provided
* with AdminUp status. The objective of this test is to ensure that the API sets the admin status of the specified port
* to Up and returns the expected result.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 037
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set port admin status to Up with valid Ethernet port ID | PortId = CCSP_HAL_ETHSW_EthPort2, AdminStatus = CCSP_HAL_ETHSW_AdminDown | RETURN_OK | Should be successful |
*/
 
void test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortAdminStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort2;
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus = CCSP_HAL_ETHSW_AdminDown;

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwSetPortAdminStatus with PortId = %d, AdminStatus = %d", PortId, AdminStatus);
    INT result = CcspHalEthSwSetPortAdminStatus(PortId, AdminStatus);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortAdminStatus...");
}

/**
* @brief This test case validates the behavior of the CcspHalEthSwSetPortAdminStatus function when an invalid port ID is provided (below the valid range).
*
* The objective of this test is to ensure that the function handles the invalid port ID correctly and returns the expected error code.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 041
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Provide an invalid port ID (below the valid range) | PortId = 0, AdminStatus = CCSP_HAL_ETHSW_AdminUp | RETURN_ERR | The function should return an error code |
*/

void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortAdminStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = 0; // Invalid port ID
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus = CCSP_HAL_ETHSW_AdminUp;

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwSetPortAdminStatus with PortId = %d, AdminStatus = %d", PortId, AdminStatus);
    INT result = CcspHalEthSwSetPortAdminStatus(PortId, AdminStatus);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortAdminStatus...");
}

/**
* @brief Test case to verify the behavior of SetPortAdminStatus API when an invalid port ID is provided
*
* This test case validates the behavior of the SetPortAdminStatus API when an invalid port ID is provided. The API should return an error in this scenario.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 042
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Verify the behavior when an invalid port ID is provided | PortID = 21, AdminStatus = CCSP_HAL_ETHSW_AdminDown | Error (RETURN_ERR) | Should return an error |
*/
void test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortAdminStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = 21; // Invalid port ID
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus = CCSP_HAL_ETHSW_AdminDown;

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwSetPortAdminStatus with PortId = %d, AdminStatus = %d", PortId, AdminStatus);
    INT result = CcspHalEthSwSetPortAdminStatus(PortId, AdminStatus);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortAdminStatus...");
}

/**
 * @brief Test the functionality of CcspHalEthSwSetPortAdminStatus with valid ProcessorPortID and AdminStatus set to AdminUp
 *
 * Tests the CcspHalEthSwSetPortAdminStatus function by setting valid ProcessorPortID and AdminStatus to AdminUp.
 * This test aims to verify that the function successfully sets the port admin status and returns RETURN_OK.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 040
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | --------------- | ----- |
 * | 01 | Set port admin status | PortId = CCSP_HAL_ETHSW_EthPort4, AdminStatus = CCSP_HAL_ETHSW_AdminTest | RETURN_ERR | Should be unsuccessful |
 */
void test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortAdminStatus(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortAdminStatus...");

    // Set input parameters
    CCSP_HAL_ETHSW_PORT PortId = CCSP_HAL_ETHSW_EthPort4;
    CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus = CCSP_HAL_ETHSW_AdminTest;

    // Invoke the API
    UT_LOG("Invoking CcspHalEthSwSetPortAdminStatus with PortId = %d, AdminStatus = %d", PortId, AdminStatus);
    INT result = CcspHalEthSwSetPortAdminStatus(PortId, AdminStatus);
    UT_LOG("Result: %d", result);

    // Verify the result
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortAdminStatus...");
}

/**
* @brief This function tests the CcspHalEthSwSetAgingSpeed API with minimum aging speed value for EthPort1.
*
* This test case checks if the CcspHalEthSwSetAgingSpeed API works correctly when the minimum aging speed value is passed for EthPort1.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 044
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set aging speed with minimum value for EthPort1 | portId = CCSP_HAL_ETHSW_EthPort1, agingSpeed = 0 | RETURN_OK | Should return success |
*/

void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetAgingSpeed(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetAgingSpeed...");

    CCSP_HAL_ETHSW_PORT portId = CCSP_HAL_ETHSW_EthPort1;
    INT agingSpeed = 0;

    UT_LOG("Invoking CcspHalEthSwSetAgingSpeed with PortId=%d, AgingSpeed=%d", portId, agingSpeed);
    INT result = CcspHalEthSwSetAgingSpeed(portId, agingSpeed);
    UT_LOG("Result: %d", result);

    UT_LOG("Expected Output: RETURN_OK");
    UT_LOG("Actual Output: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetAgingSpeed...");
}

/**
 * @brief Test the CcspHalEthSwSetAgingSpeed function with maximum aging speed for EthPort1.
 *
 * This test case checks if the CcspHalEthSwSetAgingSpeed function successfully sets the aging speed for EthPort1 to the maximum value.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 045
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Set aging speed for EthPort1 to maximum value | portId = CCSP_HAL_ETHSW_EthPort1, agingSpeed = 1000000 | RETURN_OK | Setting aging speed should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetAgingSpeed(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetAgingSpeed...");

    CCSP_HAL_ETHSW_PORT portId = CCSP_HAL_ETHSW_EthPort1;
    INT agingSpeed = 1000000;

    UT_LOG("Invoking CcspHalEthSwSetAgingSpeed with PortId=%d, AgingSpeed=%d", portId, agingSpeed);
    INT result = CcspHalEthSwSetAgingSpeed(portId, agingSpeed);
    UT_LOG("Result: %d", result);

    UT_LOG("Expected Output: RETURN_OK");
    UT_LOG("Actual Output: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetAgingSpeed...");
}

/**
* @brief This test case is used to validate the behavior of CcspHalEthSwSetAgingSpeed function when an invalid port ID, above the valid range, is provided.
*
* The purpose of this test is to ensure that the function correctly handles the case when an invalid port ID, above the valid range, is provided as input. The expected behavior of the function is to return an error code.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 049
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Setting aging speed for an invalid port ID | portId = 21, agingSpeed = 1000 | Should return RETURN_ERR | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetAgingSpeed(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetAgingSpeed...");

    CCSP_HAL_ETHSW_PORT portId = 21;
    INT agingSpeed = 1000;

    UT_LOG("Invoking CcspHalEthSwSetAgingSpeed with PortId=%d, AgingSpeed=%d", portId, agingSpeed);
    INT result = CcspHalEthSwSetAgingSpeed(portId, agingSpeed);
    UT_LOG("Result: %d", result);

    UT_LOG("Expected Output: RETURN_ERR");
    UT_LOG("Actual Output: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetAgingSpeed...");
}

/**
 * @brief Test for validating a valid MAC address with known port.
 *
 * This test verifies the functionality of the API that validates a valid MAC address with a known port.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 050
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Validate valid MAC address with known port | mac = \{0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF\} | Success | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwLocatePortByMacAddress()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_CcspHalEthSwLocatePortByMacAddress...");

    //unsigned char mac[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF}; //E0:DB:D1:36:C5:58
    //unsigned char mac[6] = {0xE0, 0xDB, 0xD1, 0x36, 0xC5, 0x58};
    INT port = 0;
    UT_LOG("Invoking CcspHalEthSwLocatePortByMacAddress with input parameters Port=%d, Mac address=%d", port, mac);
    INT result = CcspHalEthSwLocatePortByMacAddress(mac, &port);
    UT_LOG("Result: %d", result);

    UT_LOG("Verify the return status");
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Verify the value of the port");
    UT_ASSERT_EQUAL(port, 0);

    UT_LOG("Exiting test_l1_ccsp_ethsw_positive_1_CcspHalEthSwLocatePortByMacAddress...");
}

/**
* @brief Test case to verify the behavior when a valid MAC address is not present.
*
* This test case checks the behavior of the API when a valid MAC address is not present. It validates that the API handles the absence of a valid MAC address correctly.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 051
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Check behavior when a valid MAC address is not present | mac = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA} | - | The API should handle the absence of a valid MAC address correctly. |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwLocatePortByMacAddress()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_CcspHalEthSwLocatePortByMacAddress...");

   // unsigned char mac[] = {0};
    int port=-1;

    UT_LOG("Invoking CcspHalEthSwLocatePortByMacAddress with input parameters - mac: NULL");
    INT result = CcspHalEthSwLocatePortByMacAddress(NULL, NULL);
    UT_LOG("Result: %d", result);

    UT_LOG("Verify the return status");
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Verify the value of the port");
    UT_ASSERT_EQUAL(port, -1);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_CcspHalEthSwLocatePortByMacAddress...");
}

/**
* @brief This test case verifies the behavior when a null MAC address is provided as input to the CcspHalEthSwLocatePortByMacAddress function.
*
* In this test, a null MAC address is passed as input to the CcspHalEthSwLocatePortByMacAddress function. The objective is to check if the function correctly handles the null input and returns the expected result.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 052
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description                                                | Test Data              | Expected Result                | Notes                     |
* | :-------------: | ------------------------------------------------------- | ---------------------- | ------------------------------ | ------------------------- |
* |       01        | First set of conditions                                   | mac = NULL, port = -1  | result = RETURN_ERR, port = -1 | Should be successful      |
*/
void test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwLocatePortByMacAddress()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_2_CcspHalEthSwLocatePortByMacAddress...");

   // unsigned char mac[] = {0};
    INT port=-1;

    UT_LOG("Invoking CcspHalEthSwLocatePortByMacAddress with input parameters - mac: NULL");
    INT result = CcspHalEthSwLocatePortByMacAddress(NULL, &port);
    UT_LOG("Result: %d", result);

    UT_LOG("Verify the return status");
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Verify the value of the port");
    UT_ASSERT_EQUAL(port, -1);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_2_CcspHalEthSwLocatePortByMacAddress...");
}

/**
 * @brief Test for invalid MAC address format with less than 6 bytes
 *
 * This test checks the behavior of the API when an invalid MAC address format with less than 6 bytes is provided as input.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 053
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description                                                                                 | Test Data                               | Expected Result                                      | Notes                |
 * | :--------------: | ------------------------------------------------------------------------------------------- | -------------------------------------- | ---------------------------------------------------- | -------------------- |
 * |       01         | Provide invalid MAC address format with less than 6 bytes                                 | mac = {0xAA, 0xBB, 0xCC}               | Function should return with error code                 | Should be unsuccessful |
 */

void test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwLocatePortByMacAddress()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_3_CcspHalEthSwLocatePortByMacAddress...");

    unsigned char mac[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    int port=-1;

    UT_LOG("Invoking CcspHalEthSwLocatePortByMacAddress with input parameters - mac: NULL");
    INT result = CcspHalEthSwLocatePortByMacAddress(mac, NULL);
    UT_LOG("Result: %d", result);

    UT_LOG("Verify the return status");
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Verify the value of the port");
    UT_ASSERT_EQUAL(port, -1);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_3_CcspHalEthSwLocatePortByMacAddress...");
}

/**
* @brief This test case checks the API behavior when an empty array is passed as an argument.
*
* The objective of this test is to verify that the API handles the empty array correctly.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 054
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set up the environment for the test case | None | None | The test environment is set up successfully. |
* | 02 | Invoke the API with an empty array as an argument | input = empty array | Success | The API should handle the empty array correctly. |
*/

void test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetEthPortStats(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_CcspHalEthSwGetEthPortStats...");

    CCSP_HAL_ETH_STATS stats;

    UT_LOG("Invoking CcspHalEthSwGetEthPortStats to CheckWithEmptyArray.");
    INT result = CcspHalEthSwGetEthPortStats(CCSP_HAL_ETHSW_EthPort1, &stats);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_CcspHalEthSwGetEthPortStats...");
}

/**
 * @brief This test case checks the functionality of the CcspHalEthSwGetEthPortStats function with a single associated device.
 *
 * The objective of this test is to ensure that the CcspHalEthSwGetEthPortStats function works correctly when called with a single associated device. The test verifies the return value of the function call and the output struct.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 055
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :--------------: | ----------- | --------- | --------------- | ----- |
 * |       01         | Single device test with all valid input | EthPort1 = 1 | SUCCESS | N/A   |
 */

void test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetEthPortStats(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_CcspHalEthSwGetEthPortStats...");

    CCSP_HAL_ETH_STATS stats;

    UT_LOG("Invoking CcspHalEthSwGetEthPortStats to CheckWithSingleAssociatedDevice.");
    INT result = CcspHalEthSwGetEthPortStats(CCSP_HAL_ETHSW_EthPort1, &stats);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Check the output struct
    CU_ASSERT_NOT_EQUAL_FATAL(stats.BytesSent, 0);
    CU_ASSERT_NOT_EQUAL_FATAL(stats.BytesReceived, 0);
    // ... add assertions for other struct members

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_CcspHalEthSwGetEthPortStats...");
}

/**
* @brief This test checks the behavior of CcspHalEthSwGetEthPortStats function when the output structure is uninitialized.
*
* The objective of this test is to verify that the CcspHalEthSwGetEthPortStats function behaves correctly when the output structure is uninitialized.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 056
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Check the return value when the output structure is uninitialized | CCSP_HAL_ETHSW_EthPort1, uninitialized output structure | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetEthPortStats(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_CcspHalEthSwGetEthPortStats...");

    CCSP_HAL_ETH_STATS stats;

    UT_LOG("Invoking CcspHalEthSwGetEthPortStats for checking Uninitialized output.");
    INT result = CcspHalEthSwGetEthPortStats(CCSP_HAL_ETHSW_EthPort1, NULL);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_CcspHalEthSwGetEthPortStats...");
}

/**
 * @brief Test to check if the API returns an error when given an invalid MAC address.
 *
 * This test verifies if the function CcspHalEthSwGetEthPortStats correctly returns an error when an invalid MAC address is provided as input. It is important for the function to handle such invalid inputs and return an error code.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 057
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * 1. Check if the API returns an error when given an invalid MAC address.
 *    | Variation / Step | Description                               | Test Data                                      | Expected Result             | Notes             |
 *    | :--------------: | ----------------------------------------- | ---------------------------------------------- | ----------------------- | ----------------- |
 *    |       01         | First set of conditions                    | CCSP_HAL_ETHSW_EthPort1, stats                 | RETURN_ERR                | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetEthPortStats(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_2_CcspHalEthSwGetEthPortStats...");

    CCSP_HAL_ETH_STATS stats;

    UT_LOG("Invoking CcspHalEthSwGetEthPortStats for checking devices with Invalid MAC.");
    INT result = CcspHalEthSwGetEthPortStats(CCSP_HAL_ETHSW_EthPort8, &stats);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_2_CcspHalEthSwGetEthPortStats...");
}

/**
 * @brief Test to check if the API returns an error when given an invalid MAC address.
 *
 * This test verifies if the function CcspHalEthSwGetEthPortStats correctly returns an error when an invalid MAC address is provided as input. It is important for the function to handle such invalid inputs and return an error code.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 057
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * 1. Check if the API returns an error when given an invalid MAC address.
 *    | Variation / Step | Description                               | Test Data                                      | Expected Result             | Notes             |
 *    | :--------------: | ----------------------------------------- | ---------------------------------------------- | ----------------------- | ----------------- |
 *    |       01         | First set of conditions                    | CCSP_HAL_ETHSW_EthPort1, stats                 | RETURN_ERR                | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetEthPortStats(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetEthPortStats...");

    CCSP_HAL_ETH_STATS stats;

    UT_LOG("Invoking CcspHalEthSwGetEthPortStats for checking devices with Invalid MAC.");
    INT result = CcspHalEthSwGetEthPortStats(-1, &stats);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetEthPortStats...");
}

/**
 * @brief Tests the functionality of the CcspHalExtSw_getAssociatedDevice API with valid input parameters.
 *
 * This test case verifies whether the CcspHalExtSw_getAssociatedDevice API returns the expected result when provided with valid input parameters. It checks if the API can successfully retrieve the associated device information for a valid Ethernet client.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 058
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * 1. Test Case 1: Valid Ethernet Client Associated
 *    - Description: Verify if the API can retrieve the associated device information for a valid Ethernet client.
 *    - Test Data:
 *      - eth_device:
 *        - macAddress = "12:34:56:78:9A:BC"
 *        - ethPort = 1
 *        - vlanId = 10
 *        - txRate = 1000
 *        - rxRate = 500
 *        - active = TRUE
 *      - output_array_size = 1
 *      - output_struct = &eth_device
 *    - Expected Result: The API should return RETURN_OK.
 *    - Notes: N/A
 */
void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getAssociatedDevice(void)
{
    // Log entering the test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_getAssociatedDevice...");

    // Test Case 1: Valid Ethernet Client Associated
    eth_device_t eth_device;
    strncpy((char *)eth_device.eth_devMacAddress, "12:34:56:78:9A:BC", sizeof(eth_device.eth_devMacAddress) - 1);
    eth_device.eth_devMacAddress[sizeof(eth_device.eth_devMacAddress) - 1] = '\0';  // Ensure null termination

    eth_device.eth_port = 1;
    eth_device.eth_vlanid = 10;
    eth_device.eth_devTxRate = 1000;
    eth_device.eth_devRxRate = 500;
    eth_device.eth_Active = TRUE;

    ULONG output_array_size = 1;
    eth_device_t* output_struct = &eth_device;

    // Invoking CcspHalExtSw_getAssociatedDevice with valid input parameters
    UT_LOG("Invoking CcspHalExtSw_getAssociatedDevice with valid input parameters");
    INT result = CcspHalExtSw_getAssociatedDevice(&output_array_size, &output_struct);
    UT_LOG("Result: %d", result);

    // Test description and assertions
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Log exiting the test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_getAssociatedDevice...");
}

/**
* @brief Test case to verify the functionality of CcspHalExtSw_getAssociatedDevice function.
*
* This test case is used to verify the behavior of CcspHalExtSw_getAssociatedDevice function when valid input parameters are provided.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 059
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking CcspHalExtSw_getAssociatedDevice with valid input parameters | output_array_size = 1, output_struct = &eth_device | Should be successful | None |
*/

void test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getAssociatedDevice(void)
{
    // Log entering the test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_getAssociatedDevice...");

    // Test Case 2: Valid Ethernet Client Disassociated
    eth_device_t eth_device;
    strncpy((char *)eth_device.eth_devMacAddress, "12:34:56:78:9A:BC", sizeof(eth_device.eth_devMacAddress) - 1);
    eth_device.eth_devMacAddress[sizeof(eth_device.eth_devMacAddress) - 1] = '\0';  // Ensure null termination

    eth_device.eth_port = 1;
    eth_device.eth_vlanid = 10;
    eth_device.eth_devTxRate = 0;
    eth_device.eth_devRxRate = 0;
    eth_device.eth_Active = FALSE;

    ULONG output_array_size = 1;
    eth_device_t* output_struct = &eth_device;

    // Invoking CcspHalExtSw_getAssociatedDevice with valid input parameters
    UT_LOG("Invoking CcspHalExtSw_getAssociatedDevice with valid input parameters");
    INT result = CcspHalExtSw_getAssociatedDevice(&output_array_size, &output_struct);
    UT_LOG("Result: %d", result);

    // Test description and assertions
    UT_ASSERT_EQUAL(result, RETURN_OK);

    // Log exiting the test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_getAssociatedDevice...");
}

/**
* @brief Test case to verify the behavior of CcspHalExtSw_getAssociatedDevice with invalid MAC address format
*
* This test case checks the behavior of CcspHalExtSw_getAssociatedDevice when an invalid MAC address format is provided as input. The test aims to validate that the function returns the expected error code (RETURN_ERR).
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 060
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Provide an invalid MAC address format | eth_device.macAddress = "12:34:56:789A:BC" | Return error code (RETURN_ERR) | Should return an error |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getAssociatedDevice(void)
{
    // Log entering the test function
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_getAssociatedDevice...");

    // Test Case 3: Invalid MAC Address Format
    eth_device_t eth_device;
    strncpy((char *)eth_device.eth_devMacAddress, "12:34:56:78:9A:BC", sizeof(eth_device.eth_devMacAddress) - 1);
    eth_device.eth_devMacAddress[sizeof(eth_device.eth_devMacAddress) - 1] = '\0';  // Ensure null termination

    ULONG output_array_size = 1;
    eth_device_t* output_struct = &eth_device;

    // Invoking CcspHalExtSw_getAssociatedDevice with invalid MAC address format
    UT_LOG("Invoking CcspHalExtSw_getAssociatedDevice with invalid MAC address format");
    INT result = CcspHalExtSw_getAssociatedDevice(NULL, NULL);
    UT_LOG("Result: %d", result);

    // Test description and assertions
    UT_ASSERT_EQUAL(result, RETURN_ERR);

    // Log exiting the test function
    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_getAssociatedDevice...");
}

/**
* @brief Test the function registerValidCallback with a valid callback function
*
* This test case is used to verify the functionality of the registerValidCallback function by passing a valid callback function.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 061
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Pass a valid callback function | myCallback = valid callback function | Success | Should be successful |
*/

INT myCallback(eth_device_t *eth_dev)
    {
        // Implementation of the callback function
        // ...
        return RETURN_OK;
    }

void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_ethAssociatedDevice_callback_register(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_registerValidCallback...");

    UT_LOG("Invoking CcspHalExtSw_RegisterEthAssociatedDeviceCallback with register validcallback.");
    CcspHalExtSw_ethAssociatedDevice_callback_register(myCallback);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_registerValidCallback...");
}

/**
 * @brief This test verifies the behavior when registering a NULL callback in CcspHalExtSw_RegisterEthAssociatedDeviceCallback function.
 *
 * The purpose of this test is to ensure that the API handles the case of registering a NULL callback appropriately.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 062
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Register NULL as the callback | callback = NULL | RETURN_ERR | Should return error |
 */
void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_ethAssociatedDevice_callback_register(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_registerNullCallback...");

    // Register NULL as the callback
    UT_LOG("Invoking CcspHalExtSw_RegisterEthAssociatedDeviceCallback with NULL as the callback.");
    CcspHalExtSw_ethAssociatedDevice_callback_register(NULL);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_registerNullCallback...");
}

#ifdef FEATURE_RDKB_WAN_MANAGER
#ifdef FEATURE_RDKB_AUTO_PORT_SWITCH

/**
* @brief This test is to verify if the API CcspHalExtSw_ethPortConfigure correctly configures the WAN mode for a valid interface "eth0".
*
* The purpose of this test is to verify if the API correctly configures the WAN mode for a valid interface "eth0" and returns RETURN_OK.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 063
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke API CcspHalExtSw_ethPortConfigure with valid interface "eth0" and enable WAN mode | ifname = "eth0", WanMode = true | RETURN_OK | Should configure WAN mode successfully */

void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char ifname[] = "eth0";
    bool WanMode = true;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    int result = CcspHalExtSw_ethPortConfigure(ifname, WanMode);
    UT_LOG("Result: %d", result);

    UT_ASSERT_EQUAL(result, RETURN_OK);
    UT_LOG("Output: RETURN_OK");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_ethPortConfigure...");
}

/**
* @brief This test is to validate the behavior of CcspHalExtSw_ethPortConfigure() function when a valid interface "eth1" is provided and the WAN mode is disabled.
*
* The objective of this test is to ensure that the CcspHalExtSw_ethPortConfigure() function correctly configures the ethernet port when the interface "eth1" is provided and the WAN mode is disabled.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 064
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Configure eth1 interface with WAN mode disabled | ifname=eth1, WanMode=false | The CcspHalExtSw_ethPortConfigure() function should return RETURN_OK | Should be successful |
*/

void test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char ifname[] = "eth1";
    bool WanMode = false;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    UT_ASSERT_EQUAL(CcspHalExtSw_ethPortConfigure(ifname, WanMode), RETURN_OK);

    UT_LOG("Output: RETURN_OK");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_ethPortConfigure...");
}

/**
* @brief This unit test checks the behavior of the function CcspHalExtSw_ethPortConfigure when a valid interface (eth2) is provided and the WAN mode is enabled.
*
* The objective of this test is to ensure that the function correctly configures the Ethernet port with the provided interface name and enables the WAN mode.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 065
* **Priority:** High
*
* **Pre-Conditions:**
* None
*
* **Dependencies:**
* None
*
* **User Interaction:**
* If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Configuring Ethernet port with eth2 as the interface and enabling WAN mode | ifname = "eth2", WanMode = true | The Ethernet port should be configured with eth2 as the interface and WAN mode should be enabled | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_positive3_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_3_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char ifname[] = "eth2";
    bool WanMode = true;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    UT_ASSERT_EQUAL(CcspHalExtSw_ethPortConfigure(ifname, WanMode), RETURN_OK);

    UT_LOG("Output: RETURN_OK");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_3_CcspHalExtSw_ethPortConfigure...");
}

/**
 * @brief Test to verify the functionality of CcspHalExtSw_ethPortConfigure API when a valid interface (eth3) is provided and the WAN mode is disabled.
 *
 * This test case verifies whether the CcspHalExtSw_ethPortConfigure API is able to correctly configure the Ethernet port when a valid interface (eth3) is provided and the WAN mode is disabled.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 066
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chooses to run the test in interactive mode, this test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Configuring eth3 interface with WAN mode disabled | ifname = eth3, WanMode = false | RETURN_OK | The Ethernet port should be successfully configured |
 */
void test_l1_ccsp_hal_ethsw_positive4_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_4_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char ifname[] = "eth3";
    bool WanMode = false;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    UT_ASSERT_EQUAL(CcspHalExtSw_ethPortConfigure(ifname, WanMode), RETURN_OK);

    UT_LOG("Output: RETURN_OK");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_4_CcspHalExtSw_ethPortConfigure...");
}

/**
* @brief This test case is used to verify the behavior of the CcspHalExtSw_ethPortConfigure function when an invalid Ethernet interface (eth4) is provided and the WAN mode is enabled.
*
* The objective of this test is to ensure that the function returns the expected error code when an invalid interface and WAN mode enabled are provided as input.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 067
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Test with invalid interface and WAN mode enabled | ifname = "eth4", WanMode = true | RETURN_ERR | Should return an error code |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char ifname[] = "eth4";
    bool WanMode = true;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    UT_ASSERT_EQUAL(CcspHalExtSw_ethPortConfigure(ifname, WanMode), RETURN_ERR);

    UT_LOG("Output: RETURN_ERR");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_ethPortConfigure...");
}

/**
* @brief Test case to verify behavior for empty interface name and WAN mode disabled.
*
* This test case is used to verify the behavior of CcspHalExtSw_ethPortConfigure API when an empty string is provided as the interface name and WAN mode is disabled.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 068
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke API with empty interface name and WAN mode disabled | ifname = "", WanMode = false | RETURN_ERR | Should return an error |
*/

void test_l1_ccsp_hal_ethsw_negative2_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_2_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char ifname[] = "";
    bool WanMode = false;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    UT_ASSERT_EQUAL(CcspHalExtSw_ethPortConfigure(ifname, WanMode), RETURN_ERR);

    UT_LOG("Output: RETURN_ERR");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_2_CcspHalExtSw_ethPortConfigure...");
}

/**
* @brief This test is to validate the behavior of CcspHalExtSw_ethPortConfigure() API when an invalid interface is passed with a null pointer and WAN mode is enabled.
*
* Test Group ID: Basic: 01
* Test Case ID: 069
* Priority: High
*
* Pre-Conditions: None
* Dependencies: None
* User Interaction: If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* Test Procedure:
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Test with invalid interface and a null pointer | ifname = null, WanMode = true | RETURN_ERR | Should return an error |
*/
void test_l1_ccsp_hal_ethsw_negative3_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_3_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char* ifname = NULL;
    bool WanMode = true;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    UT_ASSERT_EQUAL(CcspHalExtSw_ethPortConfigure(ifname, WanMode), RETURN_ERR);

    UT_LOG("Output: RETURN_ERR");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_3_CcspHalExtSw_ethPortConfigure...");
}

/**
* @brief Test to verify the behavior of the CcspHalExtSw_ethPortConfigure() API when an invalid interface (random string) is provided and the WAN mode is disabled.
*
* This test is conducted to verify the behavior of the CcspHalExtSw_ethPortConfigure() API when an invalid interface (random string) is provided as input and the WAN mode is disabled. The API is expected to return an error code.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 070
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke CcspHalExtSw_ethPortConfigure() with an invalid interface (random string) and WAN mode disabled | ifname = "random", WanMode = false | RETURN_ERR | Should return an error code |
*/
void test_l1_ccsp_hal_ethsw_negative4_CcspHalExtSw_ethPortConfigure(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_4_CcspHalExtSw_ethPortConfigure...");

    // Test input values
    char ifname[] = "random";
    bool WanMode = false;

    // Invoke the API and check the return value
    UT_LOG("Invoking CcspHalExtSw_ethPortConfigure with ifname = %s, WanMode = %d", ifname, WanMode);
    UT_ASSERT_EQUAL(CcspHalExtSw_ethPortConfigure(ifname, WanMode), RETURN_ERR);

    UT_LOG("Output: RETURN_ERR");

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_4_CcspHalExtSw_ethPortConfigure...");
}
#endif
#endif

/**
 * @brief This test case verifies the functionality of the CcspHalExtSw_getEthWanEnable function when the EthernetWAN is enabled.
 *
 * The objective of this test is to ensure that the CcspHalExtSw_getEthWanEnable function returns the expected value and status when the EthernetWAN is enabled.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 071
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Invoking CcspHalExtSw_getEthWanEnable with enabled EthernetWAN | None | RETURN_OK | wanStatus: 1 (Enabled) |
 */
void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getEthWanEnable(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_getEthWanEnable...");

    BOOLEAN wanStatus = 0;
    system("echo \"enable\" > /nvram/ethwan_interface");

    UT_LOG("Invoking CcspHalExtSw_getEthWanEnable with enabled EthernetWAN.");
    int status = CcspHalExtSw_getEthWanEnable(&wanStatus);
    UT_LOG("Status: %d", status);
    UT_LOG("Wan status: %d",wanStatus);

    UT_LOG("Expected return status: RETURN_OK.");
    UT_LOG("Expected value of wanStatus: 1 (Enabled).");

    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_ASSERT_EQUAL(wanStatus, 1);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_getEthWanEnable...");
}

/**
 * @brief This function tests the functionality of CcspHalExtSw_getEthWanEnable() API when EthernetWAN is disabled.
 *
 * This test is a part of the Basic test group and has a high priority. The objective of this test is to verify the behavior of the CcspHalExtSw_getEthWanEnable() API when the EthernetWAN is disabled.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 072
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Invoking CcspHalExtSw_getEthWanEnable with disabled EthernetWAN | wanStatus = 1 | Expected return status: RETURN_OK, Expected value of wanStatus: 0 (Disabled) | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getEthWanEnable(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_getEthWanEnable...");

    BOOLEAN wanStatus = 1;
    system("echo \"disable\" > /nvram/ethwan_interface");

    UT_LOG("Invoking CcspHalExtSw_getEthWanEnable with disabled EthernetWAN.");
    int status = CcspHalExtSw_getEthWanEnable(&wanStatus);
    UT_LOG("Status: %d", status);
    UT_LOG("Wan status: %d",wanStatus);

    UT_LOG("Expected return status: RETURN_OK.");
    UT_LOG("Expected value of wanStatus: 0 (Disabled).");

    UT_ASSERT_EQUAL(status, RETURN_OK);
    UT_ASSERT_EQUAL(wanStatus, 0);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_getEthWanEnable...");
}

/**
 * @brief This test case verifies the behavior of the CcspHalExtSw_getEthWanEnable function when passed a NULL pointer argument.
 *
 * The objective of this test is to ensure that the function handles the NULL pointer argument correctly and returns the expected status.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 074
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 *   | Variation / Step | Description | Test Data | Expected Result | Notes |
 *   | :----: | --------- | ---------- |-------------- | ----- |
 *   | 01 | Invoking CcspHalExtSw_getEthWanEnable with NULL pointer argument | Pointer argument = NULL | RETURN_ERR | Should return RETURN_ERR |
 */
void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getEthWanEnable(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_getEthWanEnable...");

    UT_LOG("Invoking CcspHalExtSw_getEthWanEnable with NULL pointer argument.");
    int status = CcspHalExtSw_getEthWanEnable(NULL);
    UT_LOG("Status: %d", status);

    UT_LOG("Expected return status: RETURN_ERR.");

    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_getEthWanEnable...");
}

/**
 * @brief This test case is to verify the behavior of CcspHalExtSw_getEthWanEnable function when the pointer argument is not initialized.
 *
 * This test case is to verify the behavior of CcspHalExtSw_getEthWanEnable function when the pointer argument is not initialized.
 *
 * Test Group ID: Basic: 01
 * Test Case ID: 075
 * Priority: High
 *
 * Pre-Conditions: None
 * Dependencies: None
 * User Interaction: If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * Test Procedure:
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ------ |
 * | 01 | Invoking CcspHalExtSw_getEthWanEnable with uninitialized pointer argument | wanStatusPtr = (uninitialized) | RETURN_ERR | Should return error |
 */
void test_l1_ccsp_hal_ethsw_negative2_CcspHalExtSw_getEthWanEnable(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_2_CcspHalExtSw_getEthWanEnable...");

    BOOLEAN *wanStatusPtr = NULL;
    UT_LOG("Invoking CcspHalExtSw_getEthWanEnable with uninitialized pointer argument.");
    int status = CcspHalExtSw_getEthWanEnable(wanStatusPtr);
    UT_LOG("Status: %d", status);

    UT_LOG("Expected return status: RETURN_ERR or unpredictable behavior.");

    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_2_CcspHalExtSw_getEthWanEnable...");
}

/**
 * @brief Test the CcspHalExtSw_setEthWanEnable function with a positive input.
 *
 * This test case is used to verify the functionality of the CcspHalExtSw_setEthWanEnable function when the input flag is set to TRUE. The objective is to ensure that the function works as expected and returns RETURN_OK.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 076
 * **Priority:** High
 *
 * **Pre-Conditions:** None.
 * **Dependencies:** None.
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Invoke CcspHalExtSw_setEthWanEnable function with flag set to TRUE | flag = TRUE | The function should return RETURN_OK | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanEnable(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_setEthWanEnable...");

    // Invoke the API with the given input parameter
    UT_LOG("Invoking CcspHalExtSw_setEthWanEnable.");
    INT result = CcspHalExtSw_setEthWanEnable(TRUE);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_LOG("Invoking CcspHalExtSw_setEthWanEnable with Flag = TRUE. Result = %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_setEthWanEnable...");
}

/**
 * @brief TODO: Describe the objective of the test
 *
 * TODO: Add the description of what is tested and why in this test
 *
 * **Test Group ID:** Basic: 01 / Module: 02 / Stress: 03
 * **Test Case ID:** 077
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description                     | Test Data                             | Expected Result               | Notes                  |
 * | :--------------: | ------------------------------- | ------------------------------------- | ----------------------------- | ---------------------- |
 * |       01         | First set of conditions         | Flag = FALSE                          | Return value is RETURN_OK     | Should be successful   |
 */

void test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanEnable(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_setEthWanEnable...");

    // Invoke the API with the given input parameter
    UT_LOG("Invoking CcspHalExtSw_setEthWanEnable.");
    INT result = CcspHalExtSw_setEthWanEnable(FALSE);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_LOG("Invoking CcspHalExtSw_setEthWanEnable with Flag = FALSE. Result = %d", result);
    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_setEthWanEnable...");
}

/**
* @brief This test is designed to verify the behavior of the CcspHalExtSw_setEthWanEnable function when it is invoked with an unexpected value.
*
* The purpose of this test is to check if the API correctly handles and returns an error when an unexpected value is passed as the input argument. The API should not perform any unintended action or modify any state in the system.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 078
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the API with an unexpected value | Flag = 2 | Error return value | Test should fail with an error |
*/

void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanEnable(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_setEthWanEnable...");

    // Invoke the API with an unexpected value (e.g. 2)
    UT_LOG("Invoking CcspHalExtSw_setEthWanEnable.");
    INT result = CcspHalExtSw_setEthWanEnable(2);
    UT_LOG("Result: %d", result);

    // Check the return value
    UT_LOG("Invoking CcspHalExtSw_setEthWanEnable with Flag = 2. Result = %d", result);
    CU_ASSERT_NOT_EQUAL_FATAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_setEthWanEnable...");
}

#ifdef FEATURE_RDKB_AUTO_PORT_SWITCH

/**
* @brief Test case to verify the functionality of CcspHalExtSw_getCurrentWanHWConf()
*
* This test case is used to verify the functionality of the CcspHalExtSw_getCurrentWanHWConf() API.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 079
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ----------- | -------------- | ----- |
* | 01 | Invoke the API with valid parameters | None | TRUE | Should be successful |
*/

void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getCurrentWanHWConf()
{
    UT_LOG("Entering test_l1_ccsp_hal_ext_sw_positive1_CcspHalExtSw_getCurrentWanHWConf...");

    /* Test case-specific variables */
    BOOLEAN result;

    /* Invoke the API with valid parameters */
     UT_LOG("Invoking CcspHalExtSw_getCurrentWanHWConf.");
     result = CcspHalExtSw_getCurrentWanHWConf();
     UT_LOG("Result: %d", result);

    /* Determine the expected result */
    BOOLEAN expected = TRUE;

    /* Perform the assertion */
    UT_ASSERT_EQUAL(result, expected);

    UT_LOG("Exiting test_l1_ccsp_hal_ext_sw_positive1_CcspHalExtSw_getCurrentWanHWConf...");
}

/**
 * @brief Test case to verify the CcspHalExtSw_getCurrentWanHWConf function
 *
 * This test case verifies the functionality of the CcspHalExtSw_getCurrentWanHWConf function by calling it with valid parameters and checking the result against the expected value.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 080
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data                                               | Expected Result                       | Notes             |
 * | :--------------: | ----------- | ------------------------------------------------------- | ------------------------------------- | ----------------- |
 * |       01         |             |                                                         |                                       | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getCurrentWanHWConf()
{
    UT_LOG("Entering test_l1_ccsp_hal_ext_sw_positive2_CcspHalExtSw_getCurrentWanHWConf...");

    /* Test case-specific variables */
    BOOLEAN result;

    /* Invoke the API with valid parameters */
    UT_LOG("Invoking CcspHalExtSw_getCurrentWanHWConf.");
    result = CcspHalExtSw_getCurrentWanHWConf();
    UT_LOG("Result: %d", result);

    /* Determine the expected result */
    BOOLEAN expected = FALSE;

    /* Perform the assertion */
    UT_ASSERT_EQUAL(result, expected);

    UT_LOG("Exiting test_l1_ccsp_hal_ext_sw_positive2_CcspHalExtSw_getCurrentWanHWConf...");
}

/**
 * @brief This test case is used to test the functionality of the CcspHalExtSw_getCurrentWanHWConf() function in negative scenario.
 *
 * The objective of this test is to verify the behavior of the CcspHalExtSw_getCurrentWanHWConf() function when it is called with invalid parameters.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 081
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | --------------- | ----- |
 * | 01 | Invoke the API with invalid parameters | None | How to gauge success, is it a success variable? | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getCurrentWanHWConf()
{
    UT_LOG("Entering test_l1_ccsp_hal_ext_sw_negative1_CcspHalExtSw_getCurrentWanHWConf...");

    /* Test case-specific variables */
    BOOLEAN result;

    /* Invoke the API with invalid parameters */
    UT_LOG("Invoking CcspHalExtSw_getCurrentWanHWConf.");
    result = CcspHalExtSw_getCurrentWanHWConf();
    UT_LOG("Result: %d", result);

    /* Determine the expected result */
    BOOLEAN expected = TRUE; // This is just an example, the expected value should be set according to the negative test case

    /* Perform the assertion */
    CU_ASSERT_NOT_EQUAL_FATAL(result, expected);

    UT_LOG("Exiting test_l1_ccsp_hal_ext_sw_negative1_CcspHalExtSw_getCurrentWanHWConf...");
}
#endif

/**
* @brief Test to verify the CcspHalExtSw_getEthWanPort function with valid lower bound.
*
* This test case verifies the CcspHalExtSw_getEthWanPort function by passing a valid lower bound port value and checking the status of the function call.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 082
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Verify CcspHalExtSw_getEthWanPort function with valid lower bound port value | port=0 | RETURN_OK | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getEthWanPort(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_getEthWanPort...");
    
     system("echo \"ethwan\" > /nvram/ethwan_interface");
    
    UINT port = 1;

    UT_LOG("Invoking CcspHalExtSw_getEthWanPort with Port = %d (valid lower bound)", port);
    INT status = CcspHalExtSw_getEthWanPort(&port);
    UT_LOG("Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_CcspHalExtSw_getEthWanPort...");
}

/**
 * @brief This test verifies that the CcspHalExtSw_getEthWanPort function returns RETURN_OK
 *        when provided with the valid upper bound value for the port parameter.
 *
 * The function tests the CcspHalExtSw_getEthWanPort function by invoking it with the valid upper bound value
 * for the port parameter and checks if it returns RETURN_OK.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 083
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chooses to run the test in interactive mode,
 *                      they have to select the test case via console.
 *
 * **Test Procedure:**
 * 1. First, set the port variable to 65535 (valid upper bound value for the port parameter).
 * 2. Invoke the CcspHalExtSw_getEthWanPort function with Port = 65535.
 * 3. Check if the status returned by CcspHalExtSw_getEthWanPort is RETURN_OK.
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke CcspHalExtSw_getEthWanPort with valid upper bound value | port = 65535 | RETURN_OK | Should return RETURN_OK |
 */
void test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getEthWanPort(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_getEthWanPort...");
    
    UINT port;

    UT_LOG("Invoking CcspHalExtSw_getEthWanPort with Port = %d (valid upper bound)", port);
    INT status = CcspHalExtSw_getEthWanPort(&port);
    UT_LOG("Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_CcspHalExtSw_getEthWanPort...");
}

/**
* @brief This test is to verify the functionality of the CcspHalExtSw_getEthWanPort API for the valid middle range.
*
* This test verifies that the CcspHalExtSw_getEthWanPort API returns the expected status when invoked with a valid middle range port.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 084
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking CcspHalExtSw_getEthWanPort with Port = 32767 (valid middle range) | port = 32767 | Return status is RETURN_OK | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_positive3_CcspHalExtSw_getEthWanPort(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_3_CcspHalExtSw_getEthWanPort...");
    
    UINT port;

    UT_LOG("Invoking CcspHalExtSw_getEthWanPort with Port = %d (valid middle range)", port);
    INT status = CcspHalExtSw_getEthWanPort(&port);
    UT_LOG("Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_3_CcspHalExtSw_getEthWanPort...");
}

/**
* @brief Test case to check if the API CcspHalExtSw_getEthWanPort() handles the scenario when the input port value is above the upper bound.
*
* This test case will verify that the API CcspHalExtSw_getEthWanPort() returns the correct status code when the input port value is above the upper bound.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 085
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Invoking the API with a port value above the upper bound | port = 65536 | status = RETURN_ERR | Should return the status code RETURN_ERR |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getEthWanPort(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_getEthWanPort...");

    UINT port = NULL;

    UT_LOG("Invoking CcspHalExtSw_getEthWanPort with Port = %d (above upper bound)", port);
    INT status = CcspHalExtSw_getEthWanPort(port);
    UT_LOG("Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_CcspHalExtSw_getEthWanPort...");
}

/**
 * @brief Test case to validate setting EthernetWAN interface/port number with a valid port value.
 *
 * This test case checks the functionality of the CcspHalExtSw_setEthWanPort API when a valid port value is provided.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 086
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Set EthernetWAN interface/port number with a valid port value. | port = 1 | API should return RETURN_OK | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanPort(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanPort...");

    UINT port = 1;

    // Test description: Set EthernetWAN interface/port number with a valid port value.
    UT_LOG("Invoking CcspHalExtSw_setEthWanPort with Port = %u", port);
    INT status = CcspHalExtSw_setEthWanPort(port);
    UT_LOG("Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanPort...");
}

/**
* @brief Test the function CcspHalExtSw_setEthWanPort with maximum port value
*
* This test verifies the functionality of the CcspHalExtSw_setEthWanPort function by setting the EthernetWAN interface/port number with the maximum port value.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 087
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set EthernetWAN interface/port to maximum value | port = 65535 | The function should return RETURN_OK | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanPort(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanPort...");

    UINT port = 0;

    // Test description: Set EthernetWAN interface/port number with the maximum port value.
    UT_LOG("Invoking CcspHalExtSw_setEthWanPort with Port = %u", port);
    INT status = CcspHalExtSw_setEthWanPort(port);
    UT_LOG("Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanPort...");
}

/**
* @brief Test case to verify the behavior of CcspHalExtSw_setEthWanPort when the port value is outside the acceptable range
*
* This test case checks the behavior of the CcspHalExtSw_setEthWanPort function when the port value provided is outside the acceptable range. The objective is to ensure that the function returns the expected error status in this scenario.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 088
* **Priority:** High
* @n
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Set EthernetWAN interface/port number with a port value outside the acceptable range | port = 65536 | Error status | The function should return an error status |
*/
void test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanPort(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanPort...");

    UINT port = 65536;

    UT_LOG("Invoking CcspHalExtSw_setEthWanPort with Port = %u", port);
    INT status = CcspHalExtSw_setEthWanPort(port);
    UT_LOG("Status: %d", status);

    UT_ASSERT_EQUAL(status, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanPort...");
}

/**
 * @brief This test case verifies the registration of a valid callback object for the GWP_RegisterEthWan_Callback function.
 *
 * The objective of this test is to ensure that when a valid callback object is registered, the GWP_RegisterEthWan_Callback function returns RETURN_OK.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 091
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Register valid callback object | obj.pGWP_act_EthWanLinkUP = &GWP_act_EthWanLinkUP, obj.pGWP_act_EthWanLinkDown = &GWP_act_EthWanLinkDown | RETURN_OK | Should return success |
 */
// Definitions for GWP_act_EthWanLinkUP and GWP_act_EthWanLinkDown
void GWP_act_EthWanLinkUP(void)
{
    // Placeholder implementation
    printf("GWP_act_EthWanLinkUP called.\n");
}

void GWP_act_EthWanLinkDown(void)
{
    // Placeholder implementation
    printf("GWP_act_EthWanLinkDown called.\n");
}
void test_l1_ccsp_hal_ethsw_positive1_GWP_RegisterEthWan_Callback(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_GWP_RegisterEthWan_Callback...");

    // Create a valid appCallBack object
    appCallBack obj;
    obj.pGWP_act_EthWanLinkUP = &GWP_act_EthWanLinkUP;
    obj.pGWP_act_EthWanLinkDown = &GWP_act_EthWanLinkDown;

    // Invoke the API
    UT_LOG("Invoking GWP_RegisterEthWan_Callback.");
    GWP_RegisterEthWan_Callback(&obj);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_GWP_RegisterEthWan_Callback...");
}

/**
* @brief Tests the GWP_RegisterEthWan_Callback function when only the pGWP_act_EthWanLinkUP callback is set.
*
* This test is performed to verify the behavior of the GWP_RegisterEthWan_Callback function when only the pGWP_act_EthWanLinkUP callback is set in the appCallBack object.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 092
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Create a valid appCallBack object with only pGWP_act_EthWanLinkUP set | obj.pGWP_act_EthWanLinkUP = &GWP_act_EthWanLinkUP, obj.pGWP_act_EthWanLinkDown = NULL | N/A | N/A |
* | 02 | Invoke the GWP_RegisterEthWan_Callback function with the created appCallBack object | N/A | N/A | N/A |
* | 03 | Perform assertions on the return value | return_value = RETURN_OK | N/A | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_positive2_GWP_RegisterEthWan_Callback(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_GWP_RegisterEthWan_Callback...");

    // Create a valid appCallBack object with only pGWP_act_EthWanLinkUP set
    appCallBack obj;
    obj.pGWP_act_EthWanLinkUP = &GWP_act_EthWanLinkUP;
    obj.pGWP_act_EthWanLinkDown = NULL;

    // Invoke the API
    UT_LOG("Invoking GWP_RegisterEthWan_Callback.");
    GWP_RegisterEthWan_Callback(&obj);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_GWP_RegisterEthWan_Callback...");
}

/**
* @brief This test case verifies the functionality of the GWP_RegisterEthWan_Callback function when only the pGWP_act_EthWanLinkDown callback is set.
*
* The purpose of this test is to ensure that the GWP_RegisterEthWan_Callback function correctly registers the pGWP_act_EthWanLinkDown callback and returns RETURN_OK.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 093
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Create a valid appCallBack object with only pGWP_act_EthWanLinkDown set | obj.pGWP_act_EthWanLinkUP = NULL, obj.pGWP_act_EthWanLinkDown = &GWP_act_EthWanLinkDown | N/A | N/A |
* | 02 | Invoke the GWP_RegisterEthWan_Callback function with the obj parameter | obj | RETURN_OK | Should return RETURN_OK |
*/
void test_l1_ccsp_hal_ethsw_positive3_GWP_RegisterEthWan_Callback(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_3_GWP_RegisterEthWan_Callback...");

    // Create a valid appCallBack object with only pGWP_act_EthWanLinkDown set
    appCallBack obj;
    obj.pGWP_act_EthWanLinkUP = NULL;
    obj.pGWP_act_EthWanLinkDown = &GWP_act_EthWanLinkDown;

    // Invoke the API
    UT_LOG("Invoking GWP_RegisterEthWan_Callback.");
    GWP_RegisterEthWan_Callback(&obj);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_3_GWP_RegisterEthWan_Callback...");
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 094
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the API with NULL pointer | NULL | RETURN_ERR | Should be unsuccessful |
*/
void test_l1_ccsp_hal_ethsw_negative1_GWP_RegisterEthWan_Callback(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_GWP_RegisterEthWan_Callback...");

    // Invoke the API with NULL pointer
    UT_LOG("Invoking GWP_RegisterEthWan_Callback.");
    GWP_RegisterEthWan_Callback(NULL);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_GWP_RegisterEthWan_Callback...");
}

/**
* @brief Test case to verify the behavior when both callbacks are NULL in GWP_RegisterEthWan_Callback function.
*
* This test case verifies the behavior of GWP_RegisterEthWan_Callback function when both
* the pGWP_act_EthWanLinkUP and pGWP_act_EthWanLinkDown callbacks are NULL. The expected
* behavior of the function is that it should return RETURN_ERR.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 095
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
*
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :--------------: | ----------- | --------- | --------------- | ----- |
* |        01        | Both callbacks as NULL | pGWP_act_EthWanLinkUP = NULL, pGWP_act_EthWanLinkDown = NULL | RETURN_ERR | Should return RETURN_ERR |
*/
void test_l1_ccsp_hal_ethsw_negative2_GWP_RegisterEthWan_Callback(void)
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_2_GWP_RegisterEthWan_Callback...");

    // Create a valid appCallBack object with both callbacks set to NULL
    appCallBack obj;
    obj.pGWP_act_EthWanLinkUP = NULL;
    obj.pGWP_act_EthWanLinkDown = NULL;

    // Invoke the API
    UT_LOG("Invoking RegisterEthWan_Callback");
    GWP_RegisterEthWan_Callback(&obj);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_2_GWP_RegisterEthWan_Callback...");
}

/**
* @brief This test is to verify the functionality of the GWP_GetEthWanLinkStatus API
*
* This test case is used to verify the GWP_GetEthWanLinkStatus API. The objective of this test is to ensure that the API returns the expected status when the EthWAN Link is UP.
*
* **Test Group ID:** Basic: 01 / Module (L2): 02 / Stress (L2): 03)
* **Test Case ID:** 096
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking GWP_GetEthWanLinkStatus | - | - | EthWAN Link Status UP |
*/
void test_l1_ccsp_hal_ethsw_positive1_GWP_GetEthWanLinkStatus()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_GWP_GetEthWanLinkStatus...");
    
     system("echo \"erouter0\" > /nvram/ethwan_interface");

    // Invoking GWP_GetEthWanLinkStatus
    UT_LOG("Invoking GWP_GetEthWanLinkStatus, EthWAN Link Status UP");
    INT status = GWP_GetEthWanLinkStatus();
    UT_LOG("Status: %d", status);

    // Asserting the return value
    UT_ASSERT_EQUAL(status, 1);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_GWP_GetEthWanLinkStatus...");
}

/**
* @brief Test case to verify the functionality of GWP_GetEthWanLinkStatus API.
*
* This test case verifies the behavior of GWP_GetEthWanLinkStatus API by checking the return value when EthWAN Link is DOWN.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 097
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke GWP_GetEthWanLinkStatus API when EthWAN Link is DOWN | None | 0 | Success: EthWAN Link is DOWN |
*/
void test_l1_ccsp_hal_ethsw_positive2_GWP_GetEthWanLinkStatus()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_GWP_GetEthWanLinkStatus...");
    
     system("echo \"\" > /nvram/ethwan_interface");

    // Invoking GWP_GetEthWanLinkStatus
    UT_LOG("Invoking GWP_GetEthWanLinkStatus, EthWAN Link Status DOWN");
    INT status = GWP_GetEthWanLinkStatus();
    UT_LOG("Status: %d", status);

    // Asserting the return value
    UT_ASSERT_EQUAL(status, 0);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_GWP_GetEthWanLinkStatus...");
}

    /**
    * @brief Test case to validate the functionality of GWP_GetEthWanInterfaceName function when valid parameters are provided.
    *
    * This test case validates the GWP_GetEthWanInterfaceName function by passing a valid buffer and minimum allowed maxSize.
    *
    * **Test Group ID:** Basic: 01
    * **Test Case ID:** 098
    * **Priority:** High
    *
    * **Pre-Conditions:** None
    * **Dependencies:** None
    * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
    *
    * **Test Procedure:**
    * | Variation / Step | Description | Test Data | Expected Result | Notes |
    * | :----: | --------- | ---------- |-------------- | ----- |
    * | 01 | Invoking GWP_GetEthWanInterfaceName with Interface (valid buffer) and maxSize (minimum allowed value) | Interface = valid buffer, maxSize = 11 | Interface is a valid buffer with at least 64 bytes | Expected to be RETURN_OK |
    */
void test_l1_ccsp_hal_ethsw_positive1_GWP_GetEthWanInterfaceName()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_1_GWP_GetEthWanInterfaceName...");

    unsigned char Interface[64];
    ULONG maxSize = 11;

    UT_LOG("Invoking GWP_GetEthWanInterfaceName with Interface (valid buffer) and maxSize (minimum allowed value)...");
    INT result = GWP_GetEthWanInterfaceName(Interface, maxSize);
    UT_LOG("Result: %d", result);

    UT_LOG("Output: Interface is a valid buffer with at least 64 bytes");
    UT_LOG("Return status: Expected to be RETURN_OK");

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_1_GWP_GetEthWanInterfaceName...");
}

/**
 * @brief Test case to verify the functionality of GWP_GetEthWanInterfaceName function.
 *
 * This test case is used to verify the correctness of the GWP_GetEthWanInterfaceName function. It checks whether the function returns the correct interface name and the expected return status when valid buffer and maximum size are provided as input.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 099
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke GWP_GetEthWanInterfaceName with valid buffer and maximum size | Interface = valid buffer, maxSize = 262 | Return status = RETURN_OK | Should be successful |
 */
void test_l1_ccsp_hal_ethsw_positive2_GWP_GetEthWanInterfaceName()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_2_GWP_GetEthWanInterfaceName...");

    unsigned char Interface[64];
    ULONG maxSize = 62;

    UT_LOG("Invoking GWP_GetEthWanInterfaceName with Interface (valid buffer) and maxSize (maximum allowed value)...");
    INT result = GWP_GetEthWanInterfaceName(Interface, maxSize);
    UT_LOG("Result: %d", result);

    UT_LOG("Output: Interface is a valid buffer with at least 64 bytes");
    UT_LOG("Return status: Expected to be RETURN_OK");

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_2_GWP_GetEthWanInterfaceName...");
}

/**
* @brief Test the functionality of GWP_GetEthWanInterfaceName with a valid buffer and intermediate value for maxSize.
*
* This test case checks the functionality of GWP_GetEthWanInterfaceName by invoking the function with a valid buffer for Interface and an intermediate value for maxSize. The objective is to verify if the function returns RETURN_OK and updates the Interface buffer with the expected data.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 100
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* 1. Invoke GWP_GetEthWanInterfaceName with Interface (valid buffer) and maxSize (intermediate value).
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke GWP_GetEthWanInterfaceName | Interface = valid buffer, maxSize = intermediate value | Interface is a valid buffer with at least 64 bytes | Return status: Expected to be RETURN_OK |
*/
void test_l1_ccsp_hal_ethsw_positive3_GWP_GetEthWanInterfaceName()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_positive_3_GWP_GetEthWanInterfaceName...");

    unsigned char Interface[64];
    ULONG maxSize = 15;
    UT_LOG("Invoking GWP_GetEthWanInterfaceName with Interface (valid buffer) and maxSize (intermediate value)...");
    INT result = GWP_GetEthWanInterfaceName(Interface, maxSize);
    UT_LOG("Result: %d", result);

    UT_LOG("Output: Interface is a valid buffer with at least 64 bytes");
    UT_LOG("Return status: Expected to be RETURN_OK");

    UT_ASSERT_EQUAL(result, RETURN_OK);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_positive_3_GWP_GetEthWanInterfaceName...");
}

/**
* @brief This test is to verify the functionality of GWP_GetEthWanInterfaceName function when passed with valid buffer as the interface and maxSize greater than the maximum size allowed.
*
* The purpose of this test is to ensure that the GWP_GetEthWanInterfaceName function returns the expected result (RETURN_ERR) when invoked with a valid buffer as the interface (at least 64 bytes) and maxSize parameter higher than the maximum size allowed.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 101
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking GWP_GetEthWanInterfaceName with Interface (valid buffer) and maxSize (higher than maximum) | Interface = valid buffer with at least 64 bytes, maxSize = higher than maximum | RETURN_ERR | Should be successful |
*/
void test_l1_ccsp_hal_ethsw_negative1_GWP_GetEthWanInterfaceName()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_1_GWP_GetEthWanInterfaceName...");

    unsigned char Interface[64];
    ULONG maxSize = 2;
    UT_LOG("Invoking GWP_GetEthWanInterfaceName with Interface (valid buffer) and maxSize (higher than maximum)...");
    INT result = GWP_GetEthWanInterfaceName(Interface, maxSize);
    UT_LOG("Result: %d", result);

    UT_LOG("Output: Interface is a valid buffer with at least 64 bytes");
    UT_LOG("Return status: Expected to be RETURN_ERR");

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_1_GWP_GetEthWanInterfaceName...");
}

/**
 * @brief Test case to verify the behavior of GWP_GetEthWanInterfaceName API when Interface is a NULL pointer and maxSize is the minimum allowed value.
 *
 * This test case is to verify the behavior of the GWP_GetEthWanInterfaceName API when the Interface is a NULL pointer and maxSize is the minimum allowed value. The expected result is that the API should return RETURN_ERR.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 102
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If the user chooses to run the test in interactive mode, they need to select this test case via the console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description                                                      | Test Data                                                  | Expected Result | Notes             |
 * | :--------------: | --------------------------------------------------------------- | --------------------------------------------------------- | --------------- | ----------------- |
 * |       01         | Invoke GWP_GetEthWanInterfaceName with Interface (NULL pointer) | Interface = NULL, maxSize = 11                            | RETURN_ERR      | Should be failed. |
 */
void test_l1_ccsp_hal_ethsw_negative2_GWP_GetEthWanInterfaceName()
{
    UT_LOG("Entering test_l1_ccsp_hal_ethsw_negative_2_GWP_GetEthWanInterfaceName...");

    unsigned char* Interface = NULL;
    ULONG maxSize = 10;

    UT_LOG("Invoking GWP_GetEthWanInterfaceName with Interface (NULL pointer) and maxSize (minimum allowed value)...");
    INT result = GWP_GetEthWanInterfaceName(Interface, maxSize);
    UT_LOG("Result: %d", result);

    UT_LOG("Output: Interface is NULL");
    UT_LOG("Return status: Expected to be RETURN_ERR");

    UT_ASSERT_EQUAL(result, RETURN_ERR);

    UT_LOG("Exiting test_l1_ccsp_hal_ethsw_negative_2_GWP_GetEthWanInterfaceName...");
}


static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_ethsw_hal_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1 ccsp_hal_ethsw]", init_ethsw_hal_init, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }
    
    mac = (char *)malloc(MAX_SIZE * sizeof(char));
    char mac_input[1024];
    printf("Enter the valid MAC address (format: xx:xx:xx:xx:xx:xx): ");
    if (fgets(mac_input, 1024, stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(mac_input);
        if (len > 0 && mac_input[len - 1] == '\n') {
            mac_input[len - 1] = '\0';
        }

        // Parse the input into the unsigned char array
        if (sscanf(mac_input, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", 
                   &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]) == 6) {
            printf("MAC address parsed successfully: ");
            for (int i = 0; i < 6; i++) {
                printf("%02X", mac[i]);
                if (i < 5) {
                    printf(":");
                }
            }
            printf("\n");
        } else {
            printf("Invalid MAC address format.\n");
        }
    }
    // List of test function names and strings
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwInit", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwInit);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative4_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative5_CcspHalEthSwGetPortStatus", test_l1_ccsp_hal_ethsw_negative5_CcspHalEthSwGetPortStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortCfg", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortCfg", test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortCfg", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortCfg", test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortCfg", test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortCfg", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortCfg", test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive3_CcspHalEthSwSetPortCfg", test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwSetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortCfg", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortCfg", test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortCfg", test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative4_CcspHalEthSwSetPortCfg", test_l1_ccsp_hal_ethsw_negative4_CcspHalEthSwSetPortCfg);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortAdminStatus", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortAdminStatus", test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortAdminStatus", test_l1_ccsp_hal_ethsw_positive3_CcspHalEthSwGetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive4_CcspHalEthSwGetPortAdminStatus", test_l1_ccsp_hal_ethsw_positive4_CcspHalEthSwGetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortAdminStatus", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortAdminStatus", test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortAdminStatus", test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortAdminStatus", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortAdminStatus", test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortAdminStatus", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortAdminStatus", test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwSetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortAdminStatus", test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwSetPortAdminStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetAgingSpeed", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwSetAgingSpeed);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetAgingSpeed", test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwSetAgingSpeed);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetAgingSpeed", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwSetAgingSpeed);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwLocatePortByMacAddress", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwLocatePortByMacAddress);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwLocatePortByMacAddress", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwLocatePortByMacAddress);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalEthSwLocatePortByMacAddress", test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwLocatePortByMacAddress); 
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalEthSwLocatePortByMacAddress", test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwLocatePortByMacAddress);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetEthPortStats", test_l1_ccsp_hal_ethsw_positive1_CcspHalEthSwGetEthPortStats);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetEthPortStats", test_l1_ccsp_hal_ethsw_positive2_CcspHalEthSwGetEthPortStats);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetEthPortStats", test_l1_ccsp_hal_ethsw_negative1_CcspHalEthSwGetEthPortStats);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetEthPortStats", test_l1_ccsp_hal_ethsw_negative2_CcspHalEthSwGetEthPortStats);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetEthPortStats", test_l1_ccsp_hal_ethsw_negative3_CcspHalEthSwGetEthPortStats);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getAssociatedDevice", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getAssociatedDevice);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getAssociatedDevice", test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getAssociatedDevice);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getAssociatedDevice", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getAssociatedDevice);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_ethAssociatedDevice_callback_register", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_ethAssociatedDevice_callback_register);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_ethAssociatedDevice_callback_register", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_ethAssociatedDevice_callback_register);
#if defined(FEATURE_RDKB_WAN_MANAGER) && defined(FEATURE_RDKB_AUTO_PORT_SWITCH)
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_ethPortConfigure);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_ethPortConfigure);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive3_CcspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_positive3_CcspHalExtSw_ethPortConfigure);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive4_CcspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_positive4_CcspHalExtSw_ethPortConfigure);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_cspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_ethPortConfigure);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_negative2_CcspHalExtSw_ethPortConfigure);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative3_CcspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_negative3_CcspHalExtSw_ethPortConfigure);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative4_CcspHalExtSw_ethPortConfigure", test_l1_ccsp_hal_ethsw_negative4_CcspHalExtSw_ethPortConfigure);
#endif
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getEthWanEnable", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getEthWanEnable);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getEthWanEnable", test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getEthWanEnable);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getEthWanEnable", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getEthWanEnable);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_CcspHalExtSw_getEthWanEnable", test_l1_ccsp_hal_ethsw_negative2_CcspHalExtSw_getEthWanEnable);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanEnable", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanEnable);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanEnable", test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanEnable);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanEnable", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanEnable);
#ifdef FEATURE_RDKB_AUTO_PORT_SWITCH    
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getCurrentWanHWConf", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getCurrentWanHWConf);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getCurrentWanHWConf", test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getCurrentWanHWConf);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getCurrentWanHWConf", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getCurrentWanHWConf);
#endif
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getEthWanPort", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_getEthWanPort);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getEthWanPort", test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_getEthWanPort);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive3_CcspHalExtSw_getEthWanPort", test_l1_ccsp_hal_ethsw_positive3_CcspHalExtSw_getEthWanPort);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getEthWanPort", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_getEthWanPort);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanPort", test_l1_ccsp_hal_ethsw_positive1_CcspHalExtSw_setEthWanPort);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanPort", test_l1_ccsp_hal_ethsw_positive2_CcspHalExtSw_setEthWanPort);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanPort", test_l1_ccsp_hal_ethsw_negative1_CcspHalExtSw_setEthWanPort);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_GWP_RegisterEthWan_Callback", test_l1_ccsp_hal_ethsw_positive1_GWP_RegisterEthWan_Callback);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_GWP_RegisterEthWan_Callback", test_l1_ccsp_hal_ethsw_positive2_GWP_RegisterEthWan_Callback);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive3_GWP_RegisterEthWan_Callback", test_l1_ccsp_hal_ethsw_positive3_GWP_RegisterEthWan_Callback);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_GWP_RegisterEthWan_Callback", test_l1_ccsp_hal_ethsw_negative1_GWP_RegisterEthWan_Callback);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_GWP_RegisterEthWan_Callback", test_l1_ccsp_hal_ethsw_negative2_GWP_RegisterEthWan_Callback);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_GWP_GetEthWanLinkStatus", test_l1_ccsp_hal_ethsw_positive1_GWP_GetEthWanLinkStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_GWP_GetEthWanLinkStatus", test_l1_ccsp_hal_ethsw_positive2_GWP_GetEthWanLinkStatus);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive1_GWP_GetEthWanInterfaceName", test_l1_ccsp_hal_ethsw_positive1_GWP_GetEthWanInterfaceName);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive2_GWP_GetEthWanInterfaceName", test_l1_ccsp_hal_ethsw_positive2_GWP_GetEthWanInterfaceName);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_positive3_GWP_GetEthWanInterfaceName", test_l1_ccsp_hal_ethsw_positive3_GWP_GetEthWanInterfaceName);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative1_GWP_GetEthWanInterfaceName", test_l1_ccsp_hal_ethsw_negative1_GWP_GetEthWanInterfaceName);
    UT_add_test(pSuite, "l1_ccsp_hal_ethsw_negative2_GWP_GetEthWanInterfaceName", test_l1_ccsp_hal_ethsw_negative2_GWP_GetEthWanInterfaceName);

    return 0;
}


