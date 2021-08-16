/*
 * utility.h
 *
 *  Created on: Aug 15, 2021
 *      Author: Stuart
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include "main.h"
#include "stdint.h"
#include "stdbool.h"

void get_dec_str (uint16_t val);
void petDog();
void resetMsTmr();
void delayMS(uint16_t to_delay);
void txByte(uint8_t byte);
short rxByte(uint16_t timeout);
void setInterruptEN(bool en);
uint16_t millis();

#endif /* UTILITY_H_ */
