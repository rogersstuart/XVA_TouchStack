/*
 * page_common.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Stuart
 */

#include "button_functions/page_common.h"

#include "main.h"
#include "persistance.h"
#include "led_controls.h"
#include "synth_interface/synth_common.h"
#include "utility.h"

uint8_t unit_number = 0;

void presetHoldSequence(uint8_t idx){
  if (hold_ctr[idx] == 0)
      resetLEDi(idx, ON, LED_HIGH);
    else if (hold_ctr[idx] == 2)
      resetLEDi(idx, ON, LED_LOW);
    else if (hold_ctr[idx] == 4)
      resetLEDi(idx, ON, LED_HIGH);
    else if (hold_ctr[idx] > 4)
      resetLEDi(idx, OFF, LED_HIGH);
}

void presetControlFunc(uint8_t preset_bank, uint8_t idx, uint8_t sp){

  presetHoldSequence(idx);

    if (sp)
      activatePreset(&active_config.presets[preset_bank*idx]);
    else
      if (hold_ctr[idx] == 4)
        configurePreset(&active_config.presets[preset_bank*idx]);

    hold_ctr[idx]++;
    touch_timer[idx] = millis();
}
