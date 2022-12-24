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
void resetWDT();
void resetMsTmr();
void delayMS(uint32_t to_delay);
void U1txByte(uint8_t byte);
volatile char U1rxByte(volatile uint32_t timeout);
void setInterruptEN(bool en);
volatile uint32_t millis();
void capitalizeString(char * string);
void UlToStr(volatile char *s, unsigned int bin, volatile unsigned char n);

void U1flush(void);

#endif /* UTILITY_H_ */
