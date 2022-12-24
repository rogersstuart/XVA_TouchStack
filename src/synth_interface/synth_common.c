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

#include <stdlib.h>

#include "interrupts.h"

#include <SI_EFM8BB3_Register_Enums.h>

#define XFM_INIT_SEQ_LENGTH 12

PRESET code DEFAULT_PRESET =
  { 0, 1 };
uint8_t code XFM_INIT_SEQ[] =
  { '*', 10, 2, 0, '*', 11, 3, 0, '*', 12, 1, 0 };

uint8_t title_changed = false;

//xfm for current unit

void
randomizeProgram ()
{
  uint16_t ctr;
  //uint8_t * tx_buf_ptr;
  uint8_t SFRPAGE_save = SFRPAGE;
  uint16_t seed;

  //U1_tx_int_flag

  req_adc_vals = true;
  while (req_adc_vals)
    ;

  seed = millis () & 0xF;
  for (ctr = 0; ctr < 4; ctr++)
    {
      seed *= adc_buffer[ctr] & 3;
    }

  srand (seed);

  for (ctr = 0; ctr < 512; ctr++)
    {
      tx_buffer[tx_buffer_count++] = 's';
      tx_buffer[tx_buffer_count++] = ((ctr > 255) ? 0xFF : ctr);
      if (ctr > 255)
        tx_buffer[tx_buffer_count++] = (ctr - 256);
      tx_buffer[tx_buffer_count++] = rand ();

      if (((uint16_t) tx_buffer_count + 10) > 255)
        {
          while (tx_from_buffer)
            ;
          tx_from_buffer = true;
          SFRPAGE = 0x20;

          tx_buffer_count--;
          SBUF1 = tx_buffer[tx_buffer_counter++];
          while (tx_from_buffer)
            ;
          SFRPAGE = SFRPAGE_save;
        }
    }

  if (tx_buffer_count > 0)
    {
      while (tx_from_buffer)
        ;
      tx_from_buffer = true;
      SFRPAGE = 0x20;

      tx_buffer_count--;
      SBUF1 = tx_buffer[tx_buffer_counter++];
      while (tx_from_buffer)
        ;
      SFRPAGE = SFRPAGE_save;
    }

  U1txByte ('w');
  U1txByte (active_config.active_preset.base);
  U1rxByte (100);
}

void
activatePreset (PRESET *p)
{
  if (active_config.system_mode == XFM_MODE)
    xfm_recal_program (p);
  else
    xva_recal_program (p);
}

void configurePreset (PRESET *p)
{
  p->base = active_config.active_preset.base;
  p->extended = active_config.active_preset.extended;
}

volatile char prog_name[24];
void getProgName ()
{
  //480+24
  uint8_t chi;
  uint8_t SFRPAGE_save = SFRPAGE;

  //seems to need to read to set up properly.
  //U1txByte ('g');
  //U1txByte (0xFF);
  //U1txByte ((480 - 256));
  //prog_name[chi] = U1rxByte (100);
  delayMS(100);
  U1flush();

  for (chi = 0; chi < 24; chi++)
    {
      tx_buffer[tx_buffer_count++] = 'g';
      tx_buffer[tx_buffer_count++] = 0xFF;
      tx_buffer[tx_buffer_count++] = (480 - 256) + chi;

      while (tx_from_buffer)
          ;
        tx_from_buffer = true;
        SFRPAGE = 0x20;

        //tx_buffer_count--;
        //SBUF1 = tx_buffer[tx_buffer_counter++];
        //SBUF1 = 0;
        SCON1_TI = 1;
        while(tx_from_buffer);
        SFRPAGE = SFRPAGE_save;

      prog_name[chi] = U1rxByte(100);
    }



  //memcpy(rx_buffer, prog_name,24);
  //for (chi = 0; chi < 24; chi++)
  //  prog_name[chi] = U1rxByte (100);

}

void set_active_program (uint8_t prog_num)
{
  U1txByte ('r');
  U1txByte (prog_num);
  U1rxByte (10);
  //delayMS(1);

  if(active_config.system_mode == XVA_MODE)
    {
  getProgName ();
  capitalizeString (prog_name);

    }
  else
    prog_name[0] = '\0';

  title_changed = true;

}

//detect if the synth is in XFM or XVA mode
//result is written to the system configuration
void detectMode()
{
  U1flush();
  U1txByte ('1');
    active_config.system_mode = U1rxByte (100) < 0 ? XVA_MODE : XFM_MODE;
}

void init_synth_mode ()
{
  uint8_t i = 0;

  active_config.active_preset = DEFAULT_PRESET;

  detectMode();

  if (active_config.system_mode == XFM_MODE)
    {
      //xfm_recal_program(&DEFAULT_PRESET);
      xfm_recal_program (&active_config.active_preset);

      for (i = 0; i < 12; i++){
          if (((i + 1) % (uint8_t) 4) == 0)
            U1rxByte (10);
          else{
              U1txByte (XFM_INIT_SEQ[i]);
              delayMS (100);
            }
        }
    }
  else{
      U1txByte ('*');
      U1txByte (10);
      U1txByte (0);
      U1rxByte (100);
      xva_recal_program (&active_config.active_preset);
    }
}
