/*
 * xfm.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */
#include "synth_interface/synth_common.h"
#include "utility.h"

#include "synth_interface/xfm.h"

void xfm_recal_program(PRESET * p){

  active_config.active_preset = *p;
    //write_cfg();


  //reselect unit
    if(active_config.unit_number == 0)
      {
        U1txByte('2');
          U1rxByte(100);
          set_active_program(p->extended);
          delayMS(10);
          U1txByte('1');
            U1rxByte(100);
            set_active_program(p->base);
            delayMS(10);
      }
    else
      {
        U1txByte('1');
                    U1rxByte(100);
                    set_active_program(p->base);
                    delayMS(10);
                    U1txByte('2');
                              U1rxByte(100);
                              set_active_program(p->extended);
                              delayMS(10);
      }





}
