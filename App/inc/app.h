/*
 * app.h
 *
 *  Created on: Dec 5, 2023
 *      Author: User
 */

#ifndef APP_INC_APP_H_
#define APP_INC_APP_H_

#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\App\inc\midapp.h"

// Vshunt = (Ishunt * Rshunt * AMP RATIO) + 2.5V
// Ishunt = (Vshunt - 2.5V) / (Rshunt * Amplifier Ratio)
// Ishunt = (Vshunt - 2.5V) * CURRENTCONSTANT_SHUNT
// -----------------------------------------------------
// AMPLIFIER RATIO          : 47
// SHUNT RESISTOR VALUE     : 0.00005 Ohm
// CURRENTCONSTANT_SHUNT    : 0.00005 x 47 = 0.00235
// CURRENTCONSTANT_SHUNT    : 1 / 0.00235 = 425.5319149
// Converted to multiplication for compiler optimization.
#define CURRENTCONST_SHUNT 425.531919F

//
// SHUNT AMPLIFIER OFFSET VOLTAGE
//
#define OFFSETVOLTAGE_SHUNT 2.5F

// 1 hour = 3 600 000 milisecond
// CAPACITY_CONST: 1 / 3 600 000 = 0.00000027778
#define CAPACTY_CONST 0.00000027778F

//
// HALL SENSOR RESOLUTION
//
#define CURRENTCONST_HALL  0

//
// CAN MESSAGE DATA LENGHT
//
#define MSG_DATA_LENGHT  8

void BMSStartupConfiguration(void);

//*****************************************************************************
//
//! This function reads config message and writes to flash memmory.
//! param: None.
//! return: New config message status. 0: No new message,
//!                                            1: New message received.
//
//*****************************************************************************
bool readConfigMessagesWriteToFlash(void);
void sendAllData(void);
void operationModeLauncher(void);

#endif /* APP_INC_APP_H_ */
