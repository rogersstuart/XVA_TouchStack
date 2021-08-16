/*
 * page_common.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#ifndef BUTTON_FUNCTIONS_PAGE_COMMON_H_
#define BUTTON_FUNCTIONS_PAGE_COMMON_H_

#include "stdint.h"
#include "stdbool.h"

extern uint8_t unit_number;

void presetHoldSequence(uint8_t idx);
void presetControlFunc(uint8_t preset_bank, uint8_t idx, uint8_t sp);

#endif /* BUTTON_FUNCTIONS_PAGE_COMMON_H_ */
