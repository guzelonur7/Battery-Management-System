/*
 * PCA85073ADP.c
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\drivers\inc\HW_PCA85073ADP.h"


// *****************************************************************************
//
//! Write data to PCA85073.
//! NACK: 0 ACK RECEIVED
//! XRDY: 0 NOT READY, 1: READY
//
// *****************************************************************************
void PCA85073_writeData(uint8_t address, uint8_t data){

    I2C_setDataCount(I2CA_BASE, 2);
    I2C_setConfig(I2CA_BASE, I2C_CONTROLLER_SEND_MODE);
    DEVICE_DELAY_US(100);

    I2C_sendStartCondition(I2CA_BASE);
    DEVICE_DELAY_US(100);

    I2C_putData(I2CA_BASE, address);
    DEVICE_DELAY_US(100);

    I2C_putData(I2CA_BASE, data);
    DEVICE_DELAY_US(100);

    I2C_sendStopCondition(I2CA_BASE);
    DEVICE_DELAY_US(100);

}

// *****************************************************************************
//
//! Read data to PCA85073.
//
// *****************************************************************************
uint8_t PCA85073_readData(uint8_t address){

    uint8_t value = 0;

    //
    // Register address sending section.
    //
    I2C_setDataCount(I2CA_BASE, 1);
    I2C_setConfig(I2CA_BASE, I2C_CONTROLLER_SEND_MODE);
    DEVICE_DELAY_US(150);

    I2C_sendStartCondition(I2CA_BASE);
    DEVICE_DELAY_US(150);

    I2C_putData(I2CA_BASE, address);
    DEVICE_DELAY_US(150);

    I2C_sendStopCondition(I2CA_BASE);
    DEVICE_DELAY_US(50);

    //
    // Data reading section.
    //
    I2C_setDataCount(I2CA_BASE, 1);
    I2C_setConfig(I2CA_BASE, I2C_CONTROLLER_RECEIVE_MODE);
    DEVICE_DELAY_US(150);

    I2C_sendStartCondition(I2CA_BASE);
    DEVICE_DELAY_US(200);

    I2C_sendStopCondition(I2CA_BASE);
    DEVICE_DELAY_US(50);

    value = I2C_getData(I2CA_BASE);
    DEVICE_DELAY_US(50);

    return value;

}
