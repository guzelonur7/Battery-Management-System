/*
 * MW_PCA85073ADP.h
 *
 *  Created on: Sep 13, 2023
 *      Author: User
 */

#ifndef MIDDLEWARE_INC_MW_PCA85073ADP_H_
#define MIDDLEWARE_INC_MW_PCA85073ADP_H_

#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\drivers\inc\HW_PCA85073ADP.h"

struct dateStruct{

    uint8_t second;
    uint8_t minute;
    uint8_t hours;
    uint8_t days;
    uint8_t weekdays;
    uint8_t months;
    uint16_t years;
};


void PCA85073_getDate(uint16_t* dateArr);
void PCA85073_configDate(uint8_t* dateConfig);
uint8_t PCA85073_getSeconds(void);
uint8_t PCA85073_getMinutes(void);
uint8_t PCA85073_getHours(void);
uint8_t PCA85073_getDays(void);
uint8_t PCA85073_getWeekdays(void);
uint8_t PCA85073_getMonths(void);
uint8_t PCA85073_getYears(void);

#endif /* MIDDLEWARE_INC_MW_PCA85073ADP_H_ */
