/*
 * utility.c
 *
 *  Created on: Aug 15, 2021
 *      Author: Stuart
 */

#include <SI_EFM8BB3_Register_Enums.h> // SFR declarations
#include "utility.h"
#include "Interrupts.h"
#include "string.h"




//extern volatile bool U1_tx_int_flag;

void capitalizeString(char * string){
  int i;
  for(i = 0;; i++)
    {
      if(string[i] == '\0')
        break;
      if(string[i] >= 97 )
        string[i] -= 32;
    }

  //return string;
}

/**
 * converts an integer value into ascii chars and writes them out of UART1
 * @param val the value to print
 */
void get_dec_str (volatile uint16_t val)
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
      U1_tx_int_flag = false;
         SBUF1 = buf[i];
         while (!U1_tx_int_flag);
    }

  U1_tx_int_flag = false;
  SBUF1 = '\n';
  while (!U1_tx_int_flag);
}

/**
 * reset watchdog timer
 */
void resetWDT(){
  //WDTCN = 0xA5;
}

void setInterruptEN(bool en)
{
  //uint16_t i;

  //return;

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
void U1txByte(uint8_t byte)
{


  uint8_t SFRPAGE_save = SFRPAGE;

  tx_from_buffer = false;
    tx_buffer_count = 0;
    tx_buffer_counter = 0;


  U1_tx_int_flag = false;
  SFRPAGE = 0x20;
  SBUF1 = byte;
  SFRPAGE = SFRPAGE_save;
  while (!U1_tx_int_flag);
    //resetWDT();
  //delayMS(1);


}

/**
 * get the number of milliseconds that have elapsed since the program began execution
 * @return the number of milliseconds
 */
volatile uint32_t millis()
{
  volatile uint32_t tmr_val = 0;
  shadow_ms = true;
  int_flag = false;
  while(!int_flag);
  tmr_val = ms_counter;
  shadow_ms = false;
  int_flag = false;
  while(!int_flag);
  return tmr_val;
}


volatile char U1rxByte(volatile uint32_t timeout){


  volatile uint32_t timeout_timer;
  volatile char ret_val;
  //uint8_t SFRPAGE_save = SFRPAGE;

  //delayMS(timeout);
  //  return 0;

  timeout_timer = millis();

  //delayMS(10);



  //if a byte has been received last pos and buffer pos will not be equal.
  //if it appears that a byte has been received but the flag is not set, wait a moment.

  //if(U1_last_pos != U1_buffer_pos)


  //wait for a byte to be received. note that a byte may have already been received.
    while (   (uint32_t)((int32_t)millis()-timeout_timer) < timeout)
      {
        //resetWDT();
        //check to see if a timeout occurred. if so, return a flag value. #sus
        if(U1_rx_int_flag)
          break;
      }
    //SFRPAGE = 0x20;

    if(!U1_rx_int_flag)
      return -1;


    //a byte was received. return it
    //setInterruptEN(0);
    ret_val = U1_rx_buffer[U1_last_pos++];
    //setInterruptEN(1);
    //SFRPAGE = SFRPAGE_save;



    if(U1_last_pos > 30)
      U1_last_pos = 0;


    //indicate that the byte has been processed. if buffer position trackers are not the same, leave the flag untouched.
    if(U1_buffer_pos == U1_last_pos)
      U1_rx_int_flag = false;

    //U1_last_pos+=1;


    return ret_val;
}



void delayMS(volatile uint32_t to_delay)
{
  uint32_t timer = millis();
  while ((uint32_t)((int32_t)millis() - timer) < to_delay)
    {
      int_flag = false;
      while(!int_flag);
        //resetWDT();
    }
}

/**
 * reset the millisecond timer
 */
void resetMsTmr()
{
  //setInterruptEN(0); //disable interrupts
  ms_counter = 0;
  //setInterruptEN(1); //enable interrupts
}

void UlToStr (volatile char *s, uint16_t bin, volatile unsigned char n)
{
  s += n;
  *s = '\0';

  while (n--)
    {
      *--s = (bin % 10) + '0';
      bin /= 10;
    }
}

void U1flush(){
  U1_buffer_pos = 0;
  U1_last_pos = 0;
  U1_rx_int_flag = false;
}
