/*
 * AD7171.c
 *
 *  Created on: Aug 15, 2023
 *      Author: User
 */

#include"C:\Users\User\Desktop\BMS\Prototips\3\Code\middleware\inc\MW_AD7171.h"

//*****************************************************************************
//
// AD7171_readVoltage
//
//*****************************************************************************
float32_t AD7171_readVoltage(uint32_t CS_PIN_NAME){

    //
    // Variables.
    //
    uint32_t data_result = 0;
    uint32_t check_result = 0;
    float32_t voltage_result = 0.0;

    //
    // AD7171 enable and first settling time delay.
    //
    GPIO_writePin(CS_PIN_NAME, 1);
    DEVICE_DELAY_US(AD7171_SETTLING_TIME);

    //
    // Get data.
    //
    data_result = AD7171_readData();

    //
    // Check any error.
    //
    check_result = AD7171_errorCheck(data_result);

    if(check_result == NO_ERROR){

        //
        // Calculate voltage.
        //
        voltage_result = AD7171_calculateVoltage(data_result);
    }

    else if(check_result == ERROR){

        //
        // Set result to Error.
        //
        voltage_result = ERROR;
    }

    //
    // AD7171 disable.
    //
    GPIO_writePin(CS_PIN_NAME, 0);

    //
    // Return the voltage result.
    //
    return voltage_result;
}

// End of the file.
