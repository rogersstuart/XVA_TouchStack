/*
 * utility.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Stuart
 */

#include <SI_EFM8BB3_Register_Enums.h> // SFR declarations
#include "utility.h"
#include "Interrupts.h"


/**
 * converts an integer value into ascii chars and writes them out of UART0
 * @param val the value to print
 */
void get_dec_str (uint16_t val)
{
  uint8_t buf[5] = {0,0,0,0,0};
  int i =0;

  while(val >= 10){

      buf[i] = (uint8_t) ('0' + (val % 10));
          val/=10;
          i++;
  }

  buf[i] = '0'+(uint8_t)val;

  for(; i >= 0; i--){
      tx_int_flag = false;
         SBUF0 = buf[i];
         while (!tx_int_flag);
    }

  tx_int_flag = false;
  SBUF0 = '\n';
  while (!tx_int_flag);
}

/**
 * reset watchdog timer
 */
void petDog(){
  WDTCN = 0xA5;
}

void setInterruptEN(bool en)
{
  if (en)
    IE_EA = 1; //enable interrupts
  else
    IE_EA = 0; //disable interrupts

  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
}

/**
 * send one byte out of UART0
 * @param byte
 */
void txByte(uint8_t byte)
{
  tx_int_flag = false;
  SBUF0 = byte;
  while (!tx_int_flag)
    petDog();
  delayMS(1);
}

short rxByte(uint16_t timeout){

  uint8_t ret;
  uint16_t timer;

  delayMS(timeout);
    return 0;

  timer = millis();
    while (!rx_int_flag)
      {
        petDog();
        if(millis()-timer > timeout)
          return -1;
      }
    ret = SBUF0;
    rx_int_flag = false;
    return ret;
}

/**
 * get the number of milliseconds that have elapsed since the program began execution
 * @return the number of milliseconds
 */
uint16_t millis()
{
  uint16_t tmr_val = 0;
  setInterruptEN(0);
  tmr_val = ms_counter;
  setInterruptEN(1);
  return tmr_val;
}

void delayMS(uint16_t to_delay)
{
  uint16_t timer = millis();
  while (millis() - timer < to_delay)
    {
      int_flag = false;
      while(!int_flag)
        petDog();
    }
}

/**
 * reset the millisecond timer
 */
void resetMsTmr()
{
  setInterruptEN(0); //disable interrupts
  ms_counter = 0;
  setInterruptEN(1); //enable interrupts
}

