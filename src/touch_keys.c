/*
 * touch_keys.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#include <SI_EFM8BB3_Register_Enums.h> // SFR declarations
#include "persistance.h"
#include "touch_keys.h"
#include "utility.h"
#include "string.h"

volatile uint16_t b_touch_timer[4];

/**
 *
 */
void touchTimer()
{
  uint16_t timer[] = {0,0,0,0};
  uint8_t result = 0;

  P1_B7 = 1;      //tx high
  P2 |= 0x0F;      //set all rx port pin high
  P2MDOUT |= 0x0F; //change rx port to push pull

  //wait at least one ms
  delayMS(1);

  setInterruptEN(0); //disable interrupts

  memset(b_touch_timer, 0, sizeof(b_touch_timer));

  P2MDOUT &= 0xF0;       //set rx port to open drain

  P1_B7 = 0; //set tx low

  /**
 * begin testing sensor
 */

  //wait until the rx pin is low
  //result = true;
  while (P2_B3 || P2_B2 || P2_B1 || P2_B0)
  {
    //switch (sensor_index)
    //{
    //case 0:
      if(P2_B3)
        {
          b_touch_timer[0]+=1;
        }
      //result = P2_B3;
      //break;
    //case 1:
      if(P2_B2)
              {
          b_touch_timer[1]+=1;
              }
      //result = P2_B2;
      //break;
    //case 2:
      if(P2_B1)
      {
          b_touch_timer[2]+=1;
      }
      //result = P2_B1;
      //break;
    //case 3:
    //  result = P2_B0;
      if(P2_B0)
            {
          b_touch_timer[3]+=1;
            }
    //};

    //timer++;
  }

  setInterruptEN(1); //enable interrupts

  //return timer;
}

void sampleTouchSensors()
{

  touchTimer();

  //uint8_t i;

  //for (i = 0; i < 4; i++)
  //  b_touch_timer[i] = touchTimer(i);

}

void calibrateTouch()
{
  int i = 0, k = 0;

  resetWDT();

  //set init values
  touchTimer();
  for (i = 0; i < 4; i++)
    active_config.persistant_cfg.touch_cal[i] = b_touch_timer[i];

  //integrate 10 samples
  for (k = 1; k < 10; k++)
    {
      touchTimer();
  for (i = 0; i < 4; i++)
  {

      active_config.persistant_cfg.touch_cal[i] += b_touch_timer[i];

    //active_config.touch_cal[i] /= 10;

    //touch_cal[i] += touch_cal[i];

    resetWDT();
  }
    }

  for (i = 0; i < 4; i++)
    active_config.persistant_cfg.touch_cal[i] /= 10;

  k= 0;
  for(i = 0; i < 4; i++)
    if(active_config.persistant_cfg.touch_cal[i] > k)
      k = active_config.persistant_cfg.touch_cal[i];

  k+=k/2;

  for(i = 0; i < 4; i++)
    active_config.persistant_cfg.touch_cal[i] = k;

  //needs to write the config to flash
}


