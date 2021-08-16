/*
 * utility.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Stuart
 */

#include "utility.h"

void get_dec_str (uint16_t val)
{
  uint8_t buf[5] = {0,0,0,0,0};
  int i =0;
  uint8_t bval = '0';

  while(val >= 10)
  {

      buf[i] = (uint8_t) (bval + (val % 10));
          val/=10;
          i++;


  }

  buf[i] = bval+(uint8_t)val;

  for(; i >= 0; i--)
    {
      tx_int_flag = false;
         SBUF0 = buf[i];
         while (!tx_int_flag);
    }

  tx_int_flag = false;
  SBUF0 = '\n';
  while (!tx_int_flag);
}
