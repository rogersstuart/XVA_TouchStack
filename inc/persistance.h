/*
 * persistance.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#ifndef PERSISTANCE_H_
#define PERSISTANCE_H_

#include "stdint.h"
#include "stdbool.h"


typedef struct preset {
  uint8_t base;
  uint8_t extended;
} PRESET ;

typedef struct sys_config{
  uint16_t touch_cal[4];

  //uint16_t lowest_active[4];
  //uint16_t highest_active[4];

  PRESET presets[6];

  PRESET active_preset;

  uint8_t function_page;

  uint8_t system_mode;
} SYS_CONFIG;

extern SYS_CONFIG active_config;

//void testEEPROM();

void write_cfg();
bool read_cfg();
void init_synth_mode();

#endif /* PERSISTANCE_H_ */
