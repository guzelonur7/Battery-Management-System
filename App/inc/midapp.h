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

// SEND ALL DATA

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
void getTemperatures(uint8_t *temperatures);
void getTemperaturesExtended(uint8_t *temperatureExtended);

// error check function
void checkErrors(bool *errors);

// OPERATION MODE LAUNCHER
// check system disable flag
bool getFlagSystemDisable(void);
// read system restart message
bool readSystemRestartMessage(void);
// get operation mode
uint8_t getOperationMode(void);
// operation modes
void modeCharge(bool flagModeChange);
void modeBalancing(bool flagModeChange);
void modeDischarge(bool flagModeChange);

// READ SENSOR FUNCTIONS
uint8_t readAuxContacPosition(uint8_t CHANNEL);

// Arac bilgisayarina gonderilecek hatalarin kontrolu
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

// Fonksiyonlarin gerekliliklerinde kullanilacak olan kontroller
bool checkPreCharge(void);
bool checkBalancingConditions(void);

void calculateCapacity(void);
void contactorOn(void);
void contactorOff(void);

// flashta yer alan seri hucre sayisini verir.
uint8_t getSeriesCellCount(void);

// yeni bir config mesaji var mi sonucu dondurur.
bool getNewConfigMessageFlag(void);

// flashtan okuyup diziye yazacak.
void getAuxContacPositions(bool *auxContacPosition);

// kontaktorleri kontrol edecek fonksiyon.
void contactorControl(bool status, uint8_t contactor);

// vc ile baglanti hatasini verecek fonksiyon
bool checkHostConneciton(void);

// timer fonksiyonu
uint64_t getTimer0Count();

// kapasite fonksiyonu
float64_t calculateCapacity();

/////////////////////////////app to midapp///////////////////////////////////////////////
void readSensors(bool *auxContacPositions, float *cellVoltages,
                 float *temperatures, float *instantCurrentAndTime);

uint8_t readOperationModeMessage(void);

#endif /* APP_INC_MIDAPP_H_ */
