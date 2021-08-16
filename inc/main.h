/*
 * main.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#ifndef MAIN_H_
#define MAIN_H_

#define LED_LOW 0xFF
#define LED_HIGH 0xF2

#define PRESET_BANK_LENGTH 3

#define ON 1
#define OFF 0

#define PER_COUNT_HOLD_TIME 250
#define RESET_HOLD_COUNT 10
#define SHORT_PRESS_MAX_HOLD_COUNT 4

#define PAGE_1 0
#define PAGE_2 1
#define PAGE_3 2
#define PAGE_4 3

#define BUTTON_1 0
#define BUTTON_2 1
#define BUTTON_3 2
#define BUTTON_4 3

#define SHORT_PRESS 1

#define XVA_MODE 0
#define XFM_MODE 1

#define BRINGUP_CODE 0xF2

extern unsigned char last_result[4];
extern unsigned short touch_timer[4];
extern unsigned char hold_ctr[4];

#endif /* MAIN_H_ */
