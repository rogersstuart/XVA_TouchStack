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

#define XVA_MODE 0
#define XFM_MODE 1

#define POWER_OFF 0
#define POWER_ON 1

#define DISABLED 0
#define ENABLED 1

typedef struct {
  uint8_t base;
  uint8_t extended;
} PRESET ;

typedef struct {
  volatile uint16_t cv0[2];
  volatile uint16_t cv1[2];
  volatile float scalar[2];
  } CV_CAL;

typedef struct{

  volatile uint16_t touch_cal[4];
  volatile PRESET presets[6];
  volatile CV_CAL cv_cal;

} CORE_CONFIG;

typedef struct{

  CORE_CONFIG persistant_cfg;

  volatile PRESET active_preset;

  volatile uint8_t function_page;

  volatile uint8_t system_mode;

  volatile uint8_t unit_number;


  //};
} SYS_CONFIG;

extern volatile SYS_CONFIG active_config;
extern bool power_state;

//void testEEPROM();

void write_cfg();
bool read_cfg();

#endif /* PERSISTANCE_H_ */
