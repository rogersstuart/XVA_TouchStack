/*
 * touch_keys.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#ifndef TOUCH_KEYS_H_
#define TOUCH_KEYS_H_

#include "main.h"

extern uint16_t b_touch_timer[4];
extern float ttb[4];

void touchTimer();
void sampleTouchSensors();
uint16_t getTouchVal(uint8_t pos);
void calibrateTouch();

#endif /* TOUCH_KEYS_H_ */
