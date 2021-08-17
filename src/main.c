//=========================================================
// src/myProject_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h> // SFR declarations
#include "InitDevice.h"
#include "si_toolchain.h"
#include "EEPROM/eeprom_config.h"
#include "EEPROM/eeprom.h"
#include "utility.h"
// $[Generated Includes]
// [Generated Includes]$

extern bool int_flag;
extern bool tx_int_flag;
extern uint16_t ms_counter;

#define LED_LOW 0xFF
#define LED_HIGH 0xF2

uint16_t code CV_PARAMS[] = {221, 222, 224, 225, 227, 228, 230, 231};

uint16_t touch_cal[4];
uint8_t last_result[4];
uint16_t touch_timer[4];
uint16_t b_touch_timer[4];
uint16_t lowest_active[4] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
uint16_t highest_active[4];
uint8_t hold_ctr[4];

uint8_t presets[3];

uint8_t program_num = 0;
uint8_t function_page = 0;

uint8_t CV_polarity = 0;

float ttb[4];

/*
struct tt_avg{
  uint8_t idx;
  uint16_t s0_avg[5];
  uint16_t s1_avg[5];
  uint16_t s2_avg[5];
  uint16_t s3_avg[5];
} mv_avg;

*/

void testEEPROM()
{

  /*
  eeprom_init();
  eeprom_read_byte(0,&test_buf[0]);
  get_dec_str(test_buf[0]);
  eeprom_write_byte(0, 0xFD);
  eeprom_read_byte(0,&test_buf[0]);
    get_dec_str(test_buf[0]);
    */

  /*
  uint16_t i;
    uint8_t tmp;
      SFRPAGE_SWITCH()
      ENABLE_VDDMON()
      DISABLE_WDT()
      SFRPAGE_RESTORE()
      eeprom_init();
      for(i = 0;i< EE_SIZE ;i++) {
        if(eeprom_read_byte(i,&test_buf[i]) == ERROR)
          goto error;
      }
      for(i = 0;i < 2;i++) {
        test_buf[i] = i + 0x55;
        if(eeprom_write_byte(i, test_buf[i]) == ERROR)
          goto error;
      }
      tmp = 0;
      while(tmp < 50){
          for(i = 2;i< EE_SIZE; i++) {
            test_buf[i] = i + 1;
            if(eeprom_write_byte(i, test_buf[i] + tmp) == ERROR)
              goto error;
          }
          tmp++;
      }
      for(i = 0; i< EE_SIZE; i++) {
        if(eeprom_read_byte(i,&test_buf[i]) == ERROR)
          goto error;
        if((i == 0) || (i == 1)){
            if ((test_buf[0] != 0x55) || (test_buf[1] != 0x56))
              goto error;
        }else{
          if (test_buf[i] != (i + tmp))
            goto error;
        }
      }
      while(1);
  error:
    i = 0xDEAD;
    while(1);
    */
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

void txByte(uint8_t byte)
{
  tx_int_flag = false;
  SBUF0 = byte;
  while (!tx_int_flag)
    ;
}

/**
 *
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
    petDog();
}

/**
 *
 */
void resetMsTmr()
{
  setInterruptEN(0); //disable interrupts
  ms_counter = 0;
  setInterruptEN(1); //enable interrupts
}

void setLEDLevel(uint8_t idx, uint8_t level)
{
  switch (idx)
  {
  case 0:

    PCA0CPH2 = level;
    break;
  case 1:

    PCA0CPH3 = level;
    break;
  case 2:

    PCA0CPH5 = level;
    break;
  case 3:

    PCA0CPH4 = level;
  };
}

void setLED_EN(uint8_t idx, bool en)
{
  if (en)
  {

    switch (idx)
    {
    case 0:
      PCA0CPM2 |= ((1 << 1));
      break;
    case 1:
      PCA0CPM3 |= ((1 << 1));
      break;
    case 2:
      PCA0CPM5 |= ((1 << 1));
      break;
    case 3:
      PCA0CPM4 |= ((1 << 1));
    };
  }
  else
  {

    switch (idx)
    {
    case 0:
      PCA0CPM2 &= (~(1 << 1));
      break;
    case 1:
      PCA0CPM3 &= (~(1 << 1));
      break;
    case 2:
      PCA0CPM5 &= (~(1 << 1));
      break;
    case 3:
      PCA0CPM4 &= (~(1 << 1));
    };
  }
}

void resetLEDi(uint8_t idx, bool state, uint8_t val)
{
  setLED_EN(idx, state);
  setLEDLevel(idx, val);
}

void resetLED()
{
  int i;
  for (i = 0; i < 4; i++)
    resetLEDi(i, 0, LED_HIGH);
}

/**
 *
 */
uint16_t touchTimer(char sensor_index)
{
  uint16_t timer = 0;
  uint8_t result = 0;

  P0_B7 = 1;      //tx high
  P1 = 0xFF;      //set all rx port pin high
  P1MDOUT = 0xFF; //change rx port to push pull

  //wait at least one ms
  int_flag = false;
  while (!int_flag)
    ;
  int_flag = false;
  while (!int_flag)
    ;

  setInterruptEN(0); //disable interrupts
  P1MDOUT = 0;       //set rx port to open drain

  P0_B7 = 0; //set tx low

  /**
 * begin testing sensor
 */

  //wait until the rx pin is low
  result = true;
  while (result)
  {
    switch (sensor_index)
    {
    case 0:
      result = P1_B0;
      break;
    case 1:
      result = P1_B1;
      break;
    case 2:
      result = P1_B2;
      break;
    case 3:
      result = P1_B3;
    };

    timer++;
  }

  setInterruptEN(1); //enable interrupts

  return timer;
}

void sampleTouchSensors()
{
  uint8_t i;

  for (i = 0; i < 4; i++)
  {
    b_touch_timer[i] = touchTimer(i);

    ttb[i] = ttb[i] * 0.99 + b_touch_timer[i] * 0.01;

    if (ttb[i] > touch_cal[i] && ttb[i] < lowest_active[i])
      lowest_active[i] = ttb[i];
    else if (ttb[i] > highest_active[i])
      highest_active[i] = ttb[i];
  }
}

uint16_t getTouchVal(uint8_t pos)
{
  return ttb[pos];
}

float getAnalog(uint8_t s_idx)
{
  uint16_t s_range, tch_nrm;
  float t_val, tmp;

  t_val = ttb[s_idx];

  if (lowest_active[s_idx] >= highest_active[s_idx])
    return 0;

  if (t_val <= lowest_active[s_idx])
    return 0;

  s_range = highest_active[s_idx] - lowest_active[s_idx];

  tmp = s_range * 0.1;

  if(t_val > highest_active[s_idx]-tmp)
    t_val = highest_active[s_idx];
  else
    if(t_val < lowest_active[s_idx]+tmp)
      t_val = lowest_active[s_idx];

  tmp = t_val - lowest_active[s_idx];

  tmp /= s_range;

  if(tmp > 1)
    tmp = 1;
  else
    if(tmp < 0)
      tmp = 0;

  return tmp;
}

void calibrateTouch()
{
  int i = 0, k = 0;

  for (i = 0; i < 4; i++)
  {
    touch_cal[i] = touchTimer(i);

    for (k = 1; k < 10; k++)
      touch_cal[i] += touchTimer(i);

    touch_cal[i] /= 10;

    touch_cal[i] += touch_cal[i];
  }
}

void funcPageLEDAni()
{
  uint8_t i;

  //turn LEDs off
  PCA0CPH2 &= (0xFF ^ (1 << 1));
  PCA0CPH3 &= (0xFF ^ (1 << 1));
  PCA0CPH5 &= (0xFF ^ (1 << 1));

  //set the led brightness
  PCA0CPH2 = 0xF2;
  PCA0CPH3 = 0xF2;
  PCA0CPH5 = 0xF2;

  //delayMS(250);

  for (i = 0; i < 4; i++)
  {
    switch (function_page)
    {
    case 0:
      PCA0CPM2 ^= (1 << 1);
      break;
    case 1:
      PCA0CPM3 ^= (1 << 1);
      break;
    case 2:
      PCA0CPM5 ^= (1 << 1);
      break;
    }

    delayMS(100);
  }
}

uint8_t button4Functions()
{
  //short: change page, long: reset

  if (hold_ctr[3] > 10)
    P0_B3 = 1;
  else if (hold_ctr[3] > 8)
  {
    hold_ctr[3]++;
    touch_timer[3] = millis();
    PCA0CPH4 = 0xF2;
    PCA0CPM4 |= (1 << 1);
    return 1;
  }
  else if (hold_ctr[3] > 3)
  {
    hold_ctr[3]++;
    touch_timer[3] = millis();
    PCA0CPH4 = 0xFF;
    PCA0CPM4 |= (1 << 1);
    return 1;
  }
  else if (hold_ctr[3] > 0)
  {
    hold_ctr[3]++;
    touch_timer[3] = millis();
    return 1;
  }
  else
  {
    //short press

    //change page
    /*
      tx_int_flag = false;
      SBUF0 = '*';
      while (!tx_int_flag)
        ;
      tx_int_flag = false;
      SBUF0 = 10;
      while (!tx_int_flag)
        ;
      tx_int_flag = false;
      SBUF0 = 0;
      while (!tx_int_flag)
        ;
        */

    hold_ctr[3]++;
    touch_timer[3] = millis();
    PCA0CPH4 = 0xF2;
    PCA0CPM4 |= (1 << 1);
    return 1;
  }

  return 0;
}

void button4ShortPress()
{
  uint8_t i;

  function_page++;
  if (function_page > 2)
    function_page = 0;

  funcPageLEDAni();

  if (function_page == 2)
  {

    //turn off all the CV inputs
    for (i = 0; i < 8; i++)
    {
      txByte('s');
      if (CV_PARAMS[i] > 255)
      {
        txByte(0xFF);
        txByte(CV_PARAMS[i] - 0xFF);
      }
      else
      {
        txByte(CV_PARAMS[i]);
      }
      txByte((uint8_t)128);
    }

    PCA0CPM0 |= (1 << 1);
    PCA0CPH0 = 127;

    PCA0CPM1 |= (1 << 1);
    PCA0CPH1 = 127;

    //turn on two select CV options
    if (CV_polarity)
    {
      txByte('s');
      txByte(228);
      txByte((uint8_t)0xFF);

      txByte('s');
      txByte((uint8_t)221);
      txByte(0xFF);
    }
    else
    {
      txByte('s');
      txByte(228);
      txByte((uint8_t)0);

      txByte('s');
      txByte((uint8_t)221);
      txByte(0);
    }
  }
}

/**
 * Button 1 function page 0
 *
 * Program change down
 */
void b0F0()
{
  if (hold_ctr[0] == 0)
    resetLEDi(0, 1, LED_HIGH);

  if (hold_ctr[0] == 0 || hold_ctr[0] > 2)
  {

    if (program_num == 0)
      program_num = 127;
    else
      program_num--;

    txByte('r');
    txByte(program_num);
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
void b1F0()
{
  if (hold_ctr[1] == 0)
    resetLEDi(1, 1, LED_HIGH);

  if (hold_ctr[1] == 0 || hold_ctr[1] > 2)
  {

    if (program_num == 127)
      program_num = 0;
    else
      program_num++;

    txByte('r');
    txByte(program_num);
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
void b2F0()
{
  if (hold_ctr[2] == 0)
  {

    resetLEDi(2, 1, LED_HIGH);
    program_num = 0;
    txByte('r');
    txByte(program_num);
  }
  hold_ctr[2]++;
  touch_timer[2] = millis();
}

void b0F1(bool sp)
{

  uint8_t i = 0;

  if (hold_ctr[i] == 0)
    resetLEDi(i, 1, LED_HIGH);
  else if (hold_ctr[i] == 2)
    resetLEDi(i, 1, LED_LOW);
  else if (hold_ctr[i] == 4)
    resetLEDi(i, 1, LED_HIGH);
  else if (hold_ctr[i] > 4)
    resetLEDi(i, 0, LED_HIGH);

  if (sp)
  {
    txByte('r');
    txByte(presets[i]);
  }
  else
  {
    if (hold_ctr[i] == 4)
    {
      presets[i] = program_num;
    }
  }

  hold_ctr[i]++;
  touch_timer[i] = millis();
}
void b1F1(bool sp)
{

  uint8_t i = 1;

  if (hold_ctr[i] == 0)
    resetLEDi(i, 1, LED_HIGH);
  else if (hold_ctr[i] == 2)
    resetLEDi(i, 1, LED_LOW);
  else if (hold_ctr[i] == 4)
    resetLEDi(i, 1, LED_HIGH);
  else if (hold_ctr[i] > 4)
    resetLEDi(i, 0, LED_HIGH);

  if (sp)
  {
    txByte('r');
    txByte(presets[i]);
  }
  else
  {
    if (hold_ctr[i] == 4)
    {
      presets[i] = program_num;
    }
  }

  hold_ctr[i]++;
  touch_timer[i] = millis();
}
void b2F1(bool sp)
{

  uint8_t i = 2;

  if (hold_ctr[i] == 0)
    resetLEDi(i, 1, LED_HIGH);
  else if (hold_ctr[i] == 2)
    resetLEDi(i, 1, LED_LOW);
  else if (hold_ctr[i] == 4)
    resetLEDi(i, 1, LED_HIGH);
  else if (hold_ctr[i] > 4)
    resetLEDi(i, 0, LED_HIGH);

  if (sp)
  {
    txByte('r');
    txByte(presets[i]);
  }
  else
  {
    if (hold_ctr[i] == 4)
    {
      presets[i] = program_num;
    }
  }

  hold_ctr[i]++;
  touch_timer[i] = millis();
}

void b0F2(bool sp)
{ //set polarity

  if (hold_ctr[0] == 0)
  {
    CV_polarity = !CV_polarity;

    resetLEDi(0, 1, LED_HIGH);

    /*
  PCA0POL ^= (PCA0POL & (~(uint8_t)1));
  PCA0POL |= CV_polarity;

  PCA0POL ^= (PCA0POL & (~(uint8_t)2));
  PCA0POL |= (CV_polarity << 1);
  */

    if (CV_polarity)
    {
      txByte('s');
      txByte(228);
      txByte((uint8_t)0xFF);

      txByte('s');
      txByte((uint8_t)221);
      txByte(0xFF);
    }
    else
    {
      txByte('s');
      txByte(228);
      txByte((uint8_t)0);

      txByte('s');
      txByte((uint8_t)221);
      txByte(0);
    }
  }
  else
    resetLEDi(0, 0, LED_HIGH);

  hold_ctr[0]++;
  touch_timer[0] = millis();
}

void b1F2(bool sp)
{ //cv0
  uint8_t i = 1, scale_val;

  scale_val = getAnalog(i) * 0xFF;
  //get_dec_str(scale_val*100);

  if (i == 1)
    if (scale_val > 0)
    {
      if (!((PCA0CPM0 & 2) >> 1))
      {
        txByte('s');
        txByte(228);
        txByte(CV_polarity ? 0xFF : 0);

        /*
                       PCA0POL ^= (PCA0POL & (~(uint8_t)1));
                        PCA0POL |= CV_polarity;
                        */

        PCA0CPM0 |= (1 << 1);
      }

      PCA0CPH0 = scale_val;
      resetLEDi(1, 1, ~(uint8_t)scale_val);
    }
    else
    {

      PCA0CPH0 = 127;
      txByte('s');
      txByte(228);
      txByte((uint8_t)128);

      //PCA0CPM0 &= (0xFF ^ (1 << 1));
      //P0_B1 = CV_polarity;
      resetLEDi(1, 0, LED_HIGH);
    }

  hold_ctr[1]++;
  touch_timer[1] = millis();
}

void b2F2(bool sp)
{ //cv1
  uint8_t i = 2, scale_val;

  scale_val = getAnalog(i) * 0xFF;
  //get_dec_str(scale_val*100);

  if (i == 2)
    if (scale_val > 0)
    {
      if (!((PCA0CPM1 & 2) >> 1))
      {

        txByte('s');
        txByte(221);
        txByte(CV_polarity ? 0xFF : 0);

        /*
                                                         PCA0POL ^= (PCA0POL & (~(uint8_t)2));
                                          PCA0POL |= (CV_polarity << 1);
*/
        PCA0CPM1 |= (1 << 1);
      }

      PCA0CPH1 = scale_val;
      resetLEDi(2, 1, ~(uint8_t)scale_val);
    }
    else
    {

      PCA0CPH1 = 127;

      txByte('s');
      txByte(221);
      txByte(128);
      //PCA0CPM1 &= (0xFF ^ (1 << 1));
      //P0_B2 = CV_polarity;
      resetLEDi(2, 0, LED_HIGH);
    }

  hold_ctr[2]++;
  touch_timer[2] = millis();
}

void button1Fuctions(bool sp)
{

  if (function_page == 0)
  {
    b0F0(); //button 1 function page 0
  }
  else if (function_page == 1)
  {

    b0F1(sp);
  }
  else if (function_page == 2)
  {
    b0F2(sp);
  }
}

void button2Fuctions(bool sp)
{

  if (function_page == 0)
  {
    b1F0(); //button 2 function page 0
  }
  else if (function_page == 1)
  {
    b1F1(sp);
  }
  else if (function_page == 2)
  {
    b1F2(sp);
  }
}

void button3Fuctions(bool sp)
{

  if (function_page == 0)
  {
    b2F0(); //button 3 function page 0
  }
  else if (function_page == 1)
  {
    b2F1(sp);
  }
  else if (function_page == 2)
  {
    b2F2(sp);
  }
}

void buttonFunctions(uint8_t button, bool short_press)
{

  switch (button)
  {
  case 0:
    button1Fuctions(short_press);
    break;
  case 1:
    button2Fuctions(short_press);
    break;
  case 2:
    button3Fuctions(short_press);
    break;
  case 3:
    break;
  }
}

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup(void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

void LED_InitRoutine()
{
  int i = 0, k = 0;

  //set the initial led brightness
  for (i = 0; i < 4; i++)
    setLEDLevel(i, LED_LOW);

  //turn the PWM channels on
  for (i = 0; i < 4; i++)
    setLED_EN(i, 1);

  //do a little startup brightness thing
  for (i = 0xFF; i >= 0xE0; i--)
  {
    for (k = 0; k < 4; k++)
      setLEDLevel(k, i);

    delayMS(2000 / 32);
  }

  //set the led brightness
  for (i = 0; i < 4; i++)
    setLEDLevel(i, LED_HIGH);

  calibrateTouch();

  WDTCN = 0xA5;

  //turn the channels off
  for (i = 0; i < 4; i++)
    setLED_EN(i, 0);
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main(void)
{
  int i = 0, k = 0;
  char result[4] = {0, 0, 0, 0};
  char flags_tmp = 0;
  //uint16_t tmp_tmr = 0;
  //float scale_val = 0;

  petDog();

  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();

  LED_InitRoutine();

  delayMS(250);

  funcPageLEDAni();

  //set program to 0
  txByte('r');
  txByte(0);

  /*
  while(true)
      {

        sampleTouchSensors();


        for (i = 0; i < 4; i++)
          {

            //wait at least one ms
                int_flag = false;
                while (!int_flag)
                  ;
                int_flag = false;
                while (!int_flag)
                  ;

              tx_int_flag = false;
              SBUF0 = '0'+i;
              while (!tx_int_flag);

              tx_int_flag = false;
              SBUF0 = ' ';
              while (!tx_int_flag);

              scale_val = getAnalog(i);
            //get_dec_str(scale_val*100);

            if(i == 2)
              if(scale_val > 0)
                {
                  PCA0CPM1 |= (1 << 1);
                  PCA0CPH1 = scale_val*0xFF;
                }
              else
                {
                PCA0CPM1 &= (0xFF ^ (1 << 1));
                P0_B2 = 0;
                }

          }

        WDTCN = 0xA5;
      }
      */

  while (1)
  {

    petDog();

    //gather touch results
    sampleTouchSensors();
    for (i = 0; i < 4; i++)
      result[i] = (b_touch_timer[i] > touch_cal[i]); //1 touched, 0 no touch

    for (i = 0; i < 4; i++)
    {

      if (((result[i] == last_result[i]) && hold_ctr[i] == 0) || (millis() - touch_timer[i]) < 250)
        continue;
      else
      {
        touch_timer[i] = millis();

        if (result[i]) //button is touched
        {
          if (i == 0) //button 1
          {
            button1Fuctions(0);
            continue;
          }
          else if (i == 1) //button 2
          {

            button2Fuctions(0);
            continue;

            /*
              tx_int_flag = false;
            SBUF0 = 'r';
            while (!tx_int_flag)
              ;
            if (program_num == 126)
              program_num = 0;
            else
              program_num++;

            if (result[0])
            {
              program_num = 0;
              touch_timer[i] = millis();
              while ((millis() - touch_timer[i]) < 100)
                ;

            }

            tx_int_flag = false;
            SBUF0 = program_num;
            while (!tx_int_flag)
              ;
              */
          }
          else if (i == 2) //button 3
          {
            button3Fuctions(0);
            continue;

            /*
              tx_int_flag = false;
            SBUF0 = 'w';
            while (!tx_int_flag)
              ;
            tx_int_flag = false;
            SBUF0 = program_num;
            while (!tx_int_flag)
              ;
              */
          }
          else if (i == 3) //button 4
          {
            if (button4Functions())
              continue;
          } //
        }

        if (i == 3 && hold_ctr[3] < 3)
        {
          button4ShortPress();
        }

        if (function_page == 1 && hold_ctr[i] < 4)
        {
          buttonFunctions(i, 1);
        }

        hold_ctr[i] = 0;
        last_result[i] = result[i];
      }

      resetLED();
    }

    // $[Generated Run-time code]
    // [Generated Run-time code]$
  }
}
