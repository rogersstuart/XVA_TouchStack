/*
 * synth_common.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#include "stdint.h"
#include "synth_interface/synth_common.h"
#include "persistance.h"
#include "utility.h"

#include "synth_interface/xfm.h"
#include "synth_interface/xva.h"

#define XFM_INIT_SEQ_LENGTH 12

PRESET code DEFAULT_PRESET = {0,1};
uint8_t code XFM_INIT_SEQ[] = {'*',10,2,0,'*',11,3,0,'*',12,1,0};

void activatePreset(PRESET * p){
  if(active_config.system_mode == XFM_MODE)
    xfm_recal_program(p);
  else
    xva_recal_program(p);
}

void configurePreset(PRESET * p){
  p->base= active_config.active_preset.base;
  p->extended= active_config.active_preset.extended;
}

void set_active_program(uint8_t prog_num)
{
  txByte('r');
  txByte(prog_num);
  rxByte(10);
}

void init_synth_mode()
{
  uint8_t i = 0;

  if(active_config.system_mode == XFM_MODE)
    {
      xfm_recal_program(&DEFAULT_PRESET);

      for(i = 0; i < 12; i++)
      {
          if(((i+1) % (uint8_t)4) == 0)
          rxByte(100);
        else
          {
          txByte(XFM_INIT_SEQ[i]);
          delayMS(100);
          }

      }
    }
    else
      {
        txByte('*');
        txByte(10);
        txByte(0);
        delayMS(100);
      xva_recal_program(&DEFAULT_PRESET);
      }
}
