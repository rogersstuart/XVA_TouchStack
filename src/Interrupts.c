//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB3_Register_Enums.h>
#include "Interrupts.h"

#include "adc_0.h"

#include "led_controls.h"

#include "stdio.h"
#include "string.h"

#include "persistance.h"

volatile bool int_flag = false;
volatile bool U1_tx_int_flag = false;
volatile bool U1_rx_int_flag = false;
volatile uint32_t ms_counter = 0;
volatile uint32_t shadow_ms_counter = 0;
volatile bool shadow_ms = false;

volatile bool adc_scan_active = false;

volatile char U1_rx_buffer[30];
volatile uint8_t U1_buffer_pos = 0;
volatile uint8_t U1_last_pos = 0;


volatile SI_UU16_t dac_val;
volatile uint8_t SFRPAGE_save;
//volatile uint16_t calc;

volatile uint16_t adc_buffer[4];
volatile bool req_adc_vals = false;

volatile uint8_t tx_buffer[30];
volatile bool tx_from_buffer = false;
volatile uint8_t tx_buffer_count = 0;

volatile float data calc = 0;

//-----------------------------------------------------------------------------
// Autoscan buffer initialization
//-----------------------------------------------------------------------------

// The starting address of autoscan buffer BUFFER1 in XDATA space.
// MUST END ON AN EVEN ADDRESS!

#define BUFFER1_START_ADDR (3000)

volatile ADC0_NEW_AUTOSCAN_BUFFER_ARRAY(BUFFER1, BUFFER_SIZE, BUFFER1_START_ADDR);

// The starting address of autoscan buffer BUFFER2 in XDATA space. This is placed
// immediately after BUFFER1
#define BUFFER2_START_ADDR (BUFFER1_START_ADDR + sizeof(BUFFER1))
volatile ADC0_NEW_AUTOSCAN_BUFFER_ARRAY(BUFFER2, BUFFER_SIZE, BUFFER2_START_ADDR);

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
volatile ADC0_AutoscanBuffer_t *CURRENT_BUFFER;   // A pointer to an autoscan buffer
volatile bool CONVERSION_COMPLETE = false;

volatile bool ready_new = true;

volatile bool u0_tx_done = true;

//-----------------------------------------------------------------------------
// UART0_ISR
//-----------------------------------------------------------------------------
//
// UART0 ISR Content goes here. Remember to clear flag bits:
// SCON0::RI (Receive Interrupt Flag)
// SCON0::TI (Transmit Interrupt Flag)
//
//-----------------------------------------------------------------------------
uint8_t u0rx;
SI_INTERRUPT (UART0_ISR, UART0_IRQn)
  {



      if(SCON0_RI)
        {
          //u0rx = SBUF0;
          SBUF1 = SBUF0;
        }

      if(SCON0_TI)
        u0_tx_done = true;

    SCON0_TI = 0;
    SCON0_RI = 0;
  }

//-----------------------------------------------------------------------------
// TIMER2_ISR
//-----------------------------------------------------------------------------
//
// TIMER2 ISR Content goes here. Remember to clear flag bits:
// TMR2CN0::TF2H (Timer # High Byte Overflow Flag)
// TMR2CN0::TF2L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
  {


    if(shadow_ms)
      shadow_ms_counter++;
    else
      {
        ms_counter += shadow_ms_counter;
        shadow_ms_counter = 0;
        ms_counter+=1;
      }

    int_flag = true;
    TMR2CN0_TF2H = 0; //Clear the interrupt flag for Timer 2.
  }

//-----------------------------------------------------------------------------
// ADC0EOC_ISR
//-----------------------------------------------------------------------------
//
// ADC0EOC ISR Content goes here. Remember to clear flag bits:

//
//-----------------------------------------------------------------------------

SI_INTERRUPT (ADC0EOC_ISR, ADC0EOC_IRQn)
{

    volatile CV_CAL * active_cal = &active_config.persistant_cfg.cv_cal;
    uint16_t buf1 = CURRENT_BUFFER[1];
    uint16_t buf2 = CURRENT_BUFFER[2];


    ADC0_clearIntFlags(ADC0_CONVERSION_COMPLETE_IF);

    if(req_adc_vals)
    {
      memcpy(adc_buffer,CURRENT_BUFFER,sizeof(uint16_t)*4);
      req_adc_vals = false;
    }



    if(active_cal->cv0[0] < active_cal->cv0[1])
    {
    //cv0 scaling active
      calc = active_cal->scalar[0];

      if(buf1 > active_cal->cv0[1])
        buf1 = active_cal->cv0[1];
      if(buf1 < active_cal->cv0[0])
        buf1 = active_cal->cv0[0];

      buf1 -= active_cal->cv0[0];

      calc = ((active_cal->scalar[0]) * (float)buf1) / 3.3;
    }
    else
    {
      calc = ((float)buf1/(float)3.3);
    }

    dac_val.u16 = calc;


    //SFRPAGE_save = SFRPAGE;
    //            SFRPAGE = PG4_PAGE;

    //counter.u16 = convt;
    DAC0L = dac_val.u8[LSB];
    DAC0H = dac_val.u8[MSB];

    //    SFRPAGE = SFRPAGE_save;


    if(active_cal->cv1[0] < active_cal->cv1[1])
    {
        //cv1 scaling active
        calc = active_cal->scalar[1];

        if(buf2 > active_cal->cv1[1])
            buf2 = active_cal->cv1[1];
        if(buf2 < active_cal->cv1[0])
            buf2 = active_cal->cv1[0];

        buf2 -= active_cal->cv1[0];

        calc = ((active_cal->scalar[1]) * (float)buf2) / 3.3;
    }
    else
    {
        calc = ((float)buf2/(float)3.3);

    }

    dac_val.u16 = calc;

    DAC2L = dac_val.u8[LSB];
          DAC2H = dac_val.u8[MSB];



    //if(ready_new)
     // {
        // Swap current buffers

           /*
        if (CURRENT_BUFFER == BUFFER1)
          {
            CURRENT_BUFFER = BUFFER2;
          }
        else
          {
            CURRENT_BUFFER = BUFFER1;
          }

        // Set the next autoscan buffer to be the newly filled buffer
        // This will be used after the current scan is complete,
        // which will already have started with the other buffer

        ready_new = false;


            CONVERSION_COMPLETE = true;
            */
      //}

    //ADC0_setNextAutoscanBuffer(CURRENT_BUFFER, BUFFER_SIZE);

    adc_scan_active = false;

    //ADC0_startConversion();

  }

//-----------------------------------------------------------------------------
// UART1_ISR
//-----------------------------------------------------------------------------
//
// UART1 ISR Content goes here. Remember to clear flag bits:
// SCON1::RI (Receive Interrupt Flag)
// SCON1::TI (Transmit Interrupt Flag)
// UART1FCN1::RFRQ (Receive FIFO Request)
// UART1FCN1::TFRQ (Transmit FIFO Request)
//
//-----------------------------------------------------------------------------


volatile uint8_t tx_buffer_counter = 0;
SI_INTERRUPT (UART1_ISR, UART1_IRQn)
  {
  if(SCON1_TI)
        {
      //U1_tx_int_flag = true;


          if(tx_from_buffer && tx_buffer_count-- > 0)
            {
              SBUF1 = tx_buffer[tx_buffer_counter++];
              SCON1_TI = 0;
              return;
            }
          else
            {
            U1_tx_int_flag = true;
            tx_buffer_count = 0;
            tx_buffer_counter = 0;
            tx_from_buffer = false;
            }

          SCON1_TI = 0;
        }

      if(SCON1_RI)
        {
          //a byte has been received through UART1

          //if the last interrupt has been acknowledged update the buffer position tracker
          //if(!U1_rx_int_flag)
          //  U1_last_pos = U1_buffer_pos;

          //store the byte in the buffer
          U1_rx_buffer[U1_buffer_pos] = SBUF1;
          SBUF0 = U1_rx_buffer[U1_buffer_pos];
          U1_buffer_pos++;


          //increment the buffer position in anticipation of the next byte
          //U1_buffer_pos+=1;

          //if the buffer position has overflowed, reset it to 0
          if(U1_buffer_pos > 30)
            U1_buffer_pos = 0;



          //set the flag and clear the interrupt bit
          U1_rx_int_flag = true;


          SCON1_RI = 0;

        }
  }

