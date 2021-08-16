/*
 * Interrupts.h
 *
 *  Created on: Aug 19, 2021
 *      Author: Stuart
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "stdbool.h"
#include "stdint.h"

extern volatile bool int_flag;
extern volatile bool tx_int_flag;
extern volatile uint16_t ms_counter;
extern volatile bool rx_int_flag;

#endif /* INTERRUPTS_H_ */
