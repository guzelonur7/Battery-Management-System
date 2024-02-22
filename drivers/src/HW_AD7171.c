/*
 * AD7171.c
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

#include <drivers/inc/HW_AD7171.h>

//*****************************************************************************
//
// AD7171_readData
//
//*****************************************************************************
uint32_t AD7171_readData(void){

    //
    // Variables.
    //
    uint32_t data = 0;
    uint32_t spi_loop = 0;

    //
    // Take 8-bit data for 3 times from SPI and combine.
    //
    for (spi_loop = 3; spi_loop > 0; spi_loop--){

        data = data << 8;
        data |= SPI_receiveByte(mySPI0_BASE, 0);
    }

    return data;
}

//*****************************************************************************
//
// AD7171_errorCheck
//
//*****************************************************************************
uint32_t AD7171_errorCheck(uint32_t data){

    //
    // Variables.
    //
    uint32_t result = 0;

    //
    // Input parameter is masking for status byte.
    //
    result = data & 0x000000FF;

    //
    // Masked data is checking for error.
    //
    if (result == 0x0D)
        result = NO_ERROR;

    else
        result = ERROR;

    return result;
}

//*****************************************************************************
//
// AD7171_calculateVoltage
//
//*****************************************************************************
float32_t AD7171_calculateVoltage(uint32_t data){

    float32_t result = 0.0;

    //
    // For adc data only, the data is shifted 8 bits to the right.
    //
    data  = data >> 8;

    //
    // AD7171 reference point for positive data is 2^15.
    //
    data = data - 32768;

    //
    // Calculate the voltage.
    //
    result = (float) data * (AD7171_REFV / 32768.0);

    return result;
}

// End of the file.
