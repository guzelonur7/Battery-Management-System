/*
 * MW_BTS712204ESAXUMA1.h
 *
 *  Created on: Dec 25, 2023
 *      Author: User
 */

#ifndef MIDDLEWARE_INC_MW_BTS712204ESAXUMA1_H_
#define MIDDLEWARE_INC_MW_BTS712204ESAXUMA1_H_

#include"C:\Users\User\Desktop\BMS\Prototips\3\Code\drivers\inc\HW_BTS712204ESAXUMA1.h"

//*****************************************************************************
//
//! BTS CHANNEL 0: Load Positive Contactor
//! BTS CHANNEL 1: Pre Charge Contactor
//
//*****************************************************************************


//*****************************************************************************
//
//! This function
//!
//! \param
//!
//! \return Error status
//
//*****************************************************************************
uint32_t allContactorDisable(void);

//*****************************************************************************
//
//! This function
//!
//! \param
//!
//! \return Error status
//
//*****************************************************************************
uint32_t preChargeContactorEnable(void);

//*****************************************************************************
//
//! This function
//!
//! \param
//!
//! \return Error status
//
//*****************************************************************************
uint32_t preChargeContactorDisable(void);

//*****************************************************************************
//
//! This function
//!
//! \param
//!
//! \return Error status
//
//*****************************************************************************
uint32_t loadPositiveContactorEnable(void);
//*****************************************************************************
//
//! This function
//!
//! \param
//!
//! \return Error status
//
//*****************************************************************************
uint32_t loadPositiveContactorDisable(void);

//*****************************************************************************
//
//! This function
//!
//! \param
//!
//! \return
//
//*****************************************************************************
uint32_t BTS71220_loadCurrentCheck(uint8_t channel, uint8_t channelStatus);

//*****************************************************************************
//
//! This function
//!
//! \param
//!
//! \return
//
//*****************************************************************************
float32_t BTS71220_readChannelCurrent(uint8_t channel);


#endif /* MIDDLEWARE_INC_MW_BTS712204ESAXUMA1_H_ */
