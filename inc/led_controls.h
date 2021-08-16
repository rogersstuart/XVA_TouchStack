/*
 * led_controls.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#ifndef LED_CONTROLS_H_
#define LED_CONTROLS_H_

#include "stdint.h"
#include "stdbool.h"
#include "main.h"

void setLEDLevel(uint8_t idx, uint8_t level);
void setLED_EN(uint8_t idx, bool en);
void resetLEDi(uint8_t idx, bool state, uint8_t val);
void resetLED();
void funcPageLEDAni(uint8_t function_page);
void LED_InitRoutine();

#endif /* LED_CONTROLS_H_ */
