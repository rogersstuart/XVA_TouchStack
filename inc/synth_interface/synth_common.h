/*
 * synth_common.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#ifndef _SYNTH_COMMON_H
#define _SYNTH_COMMON_H

#include "stdint.h"
#include "persistance.h"



extern uint8_t title_changed;

void activatePreset(PRESET * p);
void configurePreset(PRESET * p);
void set_active_program(uint8_t prog_num);
void getProgName();

#endif
