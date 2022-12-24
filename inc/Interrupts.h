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

#define BUFFER_SIZE 4          // The size, in 12-bit samples, of the autoscan
                                // buffers BUFFER1 and BUFFER2

extern volatile bool int_flag;
extern volatile bool U1_tx_int_flag;
extern volatile uint32_t ms_counter;
extern volatile bool U1_rx_int_flag;

extern volatile char U1_rx_buffer[];
extern volatile uint8_t U1_buffer_pos;
extern volatile uint8_t U1_last_pos;
extern volatile bool shadow_ms;

extern volatile uint16_t adc_buffer[];
extern volatile bool req_adc_vals;

extern volatile uint8_t tx_buffer[];
extern volatile bool tx_from_buffer;
extern volatile uint8_t tx_buffer_count;
extern volatile uint8_t tx_buffer_counter;

extern volatile bool u0_tx_done;

#endif /* INTERRUPTS_H_ */
