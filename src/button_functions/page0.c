/*
 * page0.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#include "main.h"
#include "utility.h"
#include "persistance.h"
#include "led_controls.h"
#include "button_functions/page_common.h"
#include "button_functions/page0.h"
#include "synth_interface/synth_common.h"

void rotateVar(uint8_t * var, bool dir){
  if(dir)
    {
      //rotate down
      if ((*var) == 0)
        (*var) = 127;
                   else
                     (*var)--;
    }
  else
    {
      //rotate up

      if ((*var) == 127)
        (*var) = 0;
          else
            (*var)++;
    }
}

/**
 * Button 1 function page 0
 *
 * Program change down
 */
void b0F0(uint8_t sp)
{
  if (hold_ctr[0] == 0)
    resetLEDi(0, 1, LED_HIGH);

  if (hold_ctr[0] == 0 || hold_ctr[0] > 2)
  {

      if(active_config.system_mode == XVA_MODE)
        {
          //xva mode

          rotateVar(&active_config.active_preset.base, true);
          set_active_program(active_config.active_preset.base);
        }
      else
        {
          //xfm mode
          rotateVar(unit_number ? &active_config.active_preset.base : &active_config.active_preset.extended, true);
          activatePreset(&active_config.active_preset);
        }


  }

  if (hold_ctr[0] > 200)
    hold_ctr[0] = 3;

  hold_ctr[0]++;
  touch_timer[0] = millis();
}

/**
 * Button 2 function page 0
 *
 * Program change up
 */
void b1F0(uint8_t sp)
{
  if (hold_ctr[1] == 0)
    resetLEDi(1, 1, LED_HIGH);

  if (hold_ctr[1] == 0 || hold_ctr[1] > 2)
  {

      if(active_config.system_mode == XVA_MODE)
      {
        //xva mode

        rotateVar(&active_config.active_preset.base, false);
        set_active_program(active_config.active_preset.base);
      }
      else
      {
        //xfm mode
        rotateVar(unit_number ? &active_config.active_preset.base : &active_config.active_preset.extended, false);
        activatePreset(&active_config.active_preset);
      }
  }

  if (hold_ctr[1] > 200)
    hold_ctr[1] = 3;

  hold_ctr[1]++;
  touch_timer[1] = millis();
}

/**
 * Button 3 function page 0
 *
 * Program change to 0
 */
void b2F0(uint8_t sp)
{
  if (hold_ctr[BUTTON_3] == 0)
  {
    resetLEDi(2, 1, LED_HIGH);

    if(active_config.system_mode == XVA_MODE)
      active_config.active_preset.base = 0;

    if(active_config.system_mode == XFM_MODE)
    {
        if(unit_number)
          active_config.active_preset.base = 0;
        else
          active_config.active_preset.extended = 0;

        activatePreset(&active_config.active_preset);
    }
    else
      set_active_program(active_config.active_preset.base);

  }
  hold_ctr[BUTTON_3]++;
  touch_timer[BUTTON_3] = millis();
}
