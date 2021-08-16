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

uint16_t b_touch_timer[4];

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
  delayMS(1);

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
    b_touch_timer[i] = touchTimer(i);

}

void calibrateTouch()
{
  int i = 0, k = 0;

  petDog();

  for (i = 0; i < 4; i++)
  {
    active_config.touch_cal[i] = touchTimer(i);

    for (k = 1; k < 10; k++)
      active_config.touch_cal[i] += touchTimer(i);

    active_config.touch_cal[i] /= 10;

    //touch_cal[i] += touch_cal[i];

    petDog();
  }

  k= 0;
  for(i = 0; i < 4; i++)
    if(active_config.touch_cal[i] > k)
      k = active_config.touch_cal[i];

  k+=k/2;

  for(i = 0; i < 4; i++)
    active_config.touch_cal[i] = k;

  petDog();

  //needs to write the config to flash
}


