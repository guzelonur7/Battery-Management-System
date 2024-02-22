/*
 * AD7171.h
 *
 *  Created on: Aug 15, 2023
 *      Author: User
 */

#ifndef MIDDLEWARE_INC_MW_AD7171_H_
#define MIDDLEWARE_INC_MW_AD7171_H_

#define AD7171_SETTLING_TIME        30000

#include <drivers/inc/HW_AD7171.h>

//*****************************************************************************
//
//! This function reads from data AD7171.
//!
//! \param CS pin for choosing AD7171.
//!
//! \return float 32-bit voltage result.
//
//*****************************************************************************
float32_t AD7171_readVoltage(uint32_t CS_PIN_NAME);



#endif /* MIDDLEWARE_INC_MW_AD7171_H_ */
