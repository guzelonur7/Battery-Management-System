/*
 * midapp.h
 *
 *  Created on: Feb 8, 2024
 *      Author: User
 */

#ifndef APP_INC_MIDAPP_H_
#define APP_INC_MIDAPP_H_

#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\middleware\inc\MW_AD7171.h"
#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\middleware\inc\MW_PCA85073ADP.h"
#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\middleware\inc\MW_BTS712204ESAXUMA1.h"

//***************************************************************
// SEND ALL DATA
//***************************************************************
// READ CELL VOLTAGES
void readCellVoltages(float *cellVoltages);
void getCellVotagesInteger(uint8_t *cellVoltagesInteger);
void getCellVotagesDecimalLow(uint8_t *cellVoltagesDecimalLow);
void getCellVotagesDecimalHigh(uint8_t *cellVoltagesDecimalHigh);
// READ INSTANT CURRENT
float readInstantCurrent(uint8_t SENSOR);
uint8_t getCurrentDecimal(float instantCurrentValue);
uint8_t getCurrentIntegerLow(float instantCurrentValue);
uint8_t getCurrentIntegerHigh(float instantCurrentValue);
// READ TEMPERATURE SENSOR SENSOR
float readTemperatureSensors(uint8_t SENSOR);
void getTemperatures(uint8_t *temperatures, uint8_t tempSensorCount);
// ERROR CHECK FUNCTION
void checkAllErrors(bool *errors);
void checkAuxContacPositions(bool *errorContacArray);
void checkCellVoltagesMin(bool *cellVoltageErrorMin);
void checkCellVoltagesMax(bool *cellVoltageErrorMax);
bool checkPackageVoltageMin(void);
bool checkPackageVoltageMax(void);
void checkTemperaturesMin(bool *errorTemperatureMin);
void checkTemperaturesMax(bool *errorTemperatureMax);
bool checkInstantCurrent(void);
bool checkPackageHealth(void);
bool checkPackageCapacityMin(void);
bool checkPackageCapacityMax(void);
bool checkPreCharge(void);
bool checkBalancingConditions(void);
bool checkHostConneciton(void);

//*****************************************************************
// OPERATION MODE LAUNCHER
//*****************************************************************
// OPERATION MODES
void modeCharge(bool flagModeChange);
void modeBalancing(bool flagModeChange);
void modeDischarge(bool flagModeChange);
// GET SYSTEM DISABLE FLAG
bool getFlagSystemDisable(void);
// READ SYSTEM START MESSAGE
bool readSystemRestartMessage(void);
// GET OPERATION MODE
uint8_t getOperationMode(void);

// READ AUX CONTAC POSITION
uint8_t readAuxContacPosition(uint8_t CHANNEL);
void calculateCapacity(void);
void contactorOn(void);
void contactorOff(void);
uint8_t getSeriesCellCount(void);
bool getNewConfigMessageFlag(void);
void getAuxContacPositions(bool *auxContacPosition);
void contactorControl(bool status, uint8_t contactor);
uint64_t getTimer0Count();
float64_t calculateCapacity();

void readSensors(bool *auxContacPositions, float *cellVoltages,
                 float *temperatures, float *instantCurrentAndTime);

uint8_t readOperationModeMessage(void);

#endif /* APP_INC_MIDAPP_H_ */
