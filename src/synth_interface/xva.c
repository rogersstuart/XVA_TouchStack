/*
 * xva.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#include "synth_interface/synth_common.h"
#include "utility.h"

#include "synth_interface/xva.h"

#include "persistance.h"

void xva_recal_program(PRESET * p){
  active_config.active_preset = *p;
  //write_cfg();
  set_active_program(p->base);

}
