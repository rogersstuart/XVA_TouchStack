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
  txByte('1');
  rxByte(100);
  set_active_program(p->base);
  delayMS(100);
  txByte('2');
  rxByte(100);
  set_active_program(p->extended);
  delayMS(100);
}
