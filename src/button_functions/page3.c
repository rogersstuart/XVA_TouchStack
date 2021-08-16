/*
 * page3.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Stuart
 */

#include "button_functions/page_common.h"
#include "button_functions/page3.h"

#include "persistance.h"
#include "synth_interface/synth_common.h"
#include "main.h"
#include "utility.h"
#include "led_controls.h"

void b0F3(uint8_t sp) //switch mode
{

  presetHoldSequence(0);

  if (hold_ctr[0] == 4){
    active_config.system_mode = !active_config.system_mode;
    init_synth_mode();
    active_config.function_page = 0;
    write_cfg();
    funcPageLEDAni(0);
  }

  hold_ctr[0]++;
  touch_timer[0] = millis();
}

void b1F3(uint8_t sp) //switch unit number
{

  if(hold_ctr[BUTTON_2] == 0){
    resetLEDi(BUTTON_2, ON, LED_HIGH);
    hold_ctr[BUTTON_2]++;
  }

  if(sp)
  {
    unit_number = !unit_number;
    active_config.function_page = 0;
    funcPageLEDAni(0);
  }

  touch_timer[BUTTON_2] = millis();
}

void b2F3(uint8_t sp) //touch cal
{

}
