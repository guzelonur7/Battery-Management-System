/*
 * MW_PCA85073ADP.c
 *
 *  Created on: Sep 13, 2023
 *      Author: User
 */


#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\middleware\inc\MW_PCA85073ADP.h"

struct dateStruct time;

void PCA85073_getDate(uint8_t* dateArr){

    time.second   = PCA85073_getSeconds();
    time.minute   = PCA85073_getMinutes();
    time.hours    = PCA85073_getHours();
    time.days     = PCA85073_getDays();
    time.weekdays = PCA85073_getWeekdays();
    time.months   = PCA85073_getMonths();
    time.years    = PCA85073_getYears();
    DEVICE_DELAY_US(1000);

    dateArr[3] = time.days;
    dateArr[2] = time.hours;
    dateArr[0] = time.second;
    dateArr[1] = time.minute;
    dateArr[5] = time.months;
    dateArr[4] = time.weekdays;
    dateArr[6] = time.years / 100;  // Years High Data
    dateArr[7] = time.years % 100;  // Years Low Data

}


uint8_t PCA85073_getSeconds(void){

    uint8_t result = 0;
    uint8_t unit_place = 0;
    uint8_t tens_place = 0;

    result = PCA85073_readData(SECONDS);

    unit_place = result & 0x0F;
    tens_place = result & 0x70;
    tens_place = (tens_place >> 4) * 10;
    result  = tens_place + unit_place;

    return result;
}

uint8_t PCA85073_getMinutes(void){

    uint8_t result = 0;
    uint8_t unit_place = 0;
    uint8_t tens_place = 0;

    result = PCA85073_readData(MINUTES);
    unit_place = result & 0x0F;
    tens_place = result & 0x70;
    tens_place = (tens_place >> 4) * 10;
    result  = tens_place + unit_place;

    return result;
}

uint8_t PCA85073_getHours(void){

    uint8_t result = 0;
    uint8_t unit_place = 0;
    uint8_t tens_place = 0;

    result = PCA85073_readData(HOURS);
    unit_place = result & 0x0F;
    tens_place = result & 0x30;
    tens_place = (tens_place >> 4) * 10;
    result  = tens_place + unit_place;

    return result;
}

uint8_t PCA85073_getDays(void){

    uint8_t result = 0;
    uint8_t unit_place = 0;
    uint8_t tens_place = 0;

    result = PCA85073_readData(DAYS);
    unit_place = result & 0x0F;
    tens_place = result & 0x30;
    tens_place = (tens_place >> 4) * 10;
    result  = tens_place + unit_place;

    return result;
}

uint8_t PCA85073_getWeekdays(void){

    uint8_t result = 0;

    result = PCA85073_readData(WEEKDAYS);
    result &= 0x07;

    return result;
}

uint8_t PCA85073_getMonths(void){

    uint8_t result = 0;
    uint8_t unit_place = 0;
    uint8_t tens_place = 0;

    result = PCA85073_readData(MONTHS);
    unit_place = result & 0x0F;
    tens_place = result & 0x10;
    tens_place = (tens_place >> 4) * 10;
    result  = tens_place + unit_place;

    return result;
}

uint16_t PCA85073_getYears(void){

    uint8_t result = 0;
    uint8_t unit_place = 0;
    uint8_t tens_place = 0;

    result = PCA85073_readData(YEARS);
    unit_place = result & 0x0F;
    tens_place = result & 0xF0;
    tens_place = (tens_place >> 4) * 10;
    result  = (tens_place + unit_place) + 2023;

    return result;
}


void PCA85073_configDate(uint8_t *dateCongif)
{

    CAN_readMessage(I2CA_BASE, 11, dateCongif);
    if (dateCongif[8] == true)
    {
        PCA85073_writeData(SECONDS, dateCongif[0]);     // Set Seconds.
        PCA85073_writeData(MINUTES, dateCongif[1]);     // Set Minutes.
        PCA85073_writeData(HOURS, dateCongif[2]);       // Set Hours.
        PCA85073_writeData(DAYS, dateCongif[3]);        // Set Days.
        PCA85073_writeData(WEEKDAYS, dateCongif[4]);    // Set Weekdays.
        PCA85073_writeData(MONTHS, dateCongif[5]);      // Set Month.
        PCA85073_writeData(YEARS, dateCongif[6]);       // Set Year.
    }

    else if(dateCongif[8] == false){

    }

}


