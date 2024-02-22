/*
 * PCA85073ADP.h
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

// *****************************************************************************
//! --> PCA85073ADP Automotive tiny Real-Time Clock/calendar with alarm function
//! and I2C-bus
//!
//!
//!
//!
//!
//!
// *****************************************************************************

#ifndef DRIVERS_INC_HW_PCA85073ADP_H_
#define DRIVERS_INC_HW_PCA85073ADP_H_

#include"C:\Users\User\Desktop\BMS\Prototips\3\Code\drivers\inc\HW_librarys.h"

// Control and Status Registers
#define CONTROL_1       0x00
#define CONTROL_2       0x01
#define OFFSET          0x02
#define RAM_BYTE        0x03
// Time and Date Registers
#define SECONDS         0x04
#define MINUTES         0x05
#define HOURS           0x06
#define DAYS            0x07
#define WEEKDAYS        0x08
#define MONTHS          0x09
#define YEARS           0x0A
// Alarm Registers
#define SECOND_ALARM    0x0B
#define MINUTE_ALARM    0x0C
#define HOUR_ALARM      0x0D
#define DAY_ALARM       0x0E
#define WEEKDAY_ALARM   0x0F
// Timer Registers
#define TIMER_VALUE     0x10
#define TIMER_MODE      0x11

//I2C MCU STATUS BITS
#define NACK_MASK 0x0002
#define XRDY_MASK 0x0010
#define SCD_MASK  0x0020

// CONTROL CYCLES
#define STATUS_CONTROL_CYCLE  99


// Hour Modes
enum{

    HOUR_24,
    HOUR_12
};

// Oscillator Capacitor Selection
enum{

    PF_7,
    PF_12_5
};

// ClockOut Pin Frequancy Divider
enum{

    DIVIDER_1,
    DIVIDER_2,
    DIVIDER_4,
    DIVIDER_8,
    DIVIDER_16,
    DIVIDER_32,
    DIVIDER_OWN,
    DIVIDER_ZERO,
};

// I2C Errors
enum{

    I2C_NO_ERROR,

    //ACK WAS NOT RECEIVED.
    I2C_ACK_ERROR,

    // TRANSMIT NOT READY.
    I2C_XRDY_ERROR,
};


// *****************************************************************************
//! Write data to PCA85073
//!
//! \param address: register address to write
//! \param data
//!
//! Only one address and one data can be write.
//!
//! return none.
//!
// *****************************************************************************
void PCA85073_writeData(uint8_t address, uint8_t data);


// *****************************************************************************
//! Read data to PCA85073
//!
//! \param address: register address to write
//! \param data_count
//!
//! return data.
//!
// *****************************************************************************
uint8_t PCA85073_readData(uint8_t address);



#endif /* DRIVERS_INC_HW_PCA85073ADP_H_ */
