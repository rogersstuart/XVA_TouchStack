#include <SI_EFM8BB3_Register_Enums.h> // SFR declarations
#include "led_controls.h"
#include "utility.h"

void setLEDLevel(uint8_t idx, uint8_t level)
{
  switch (idx)
  {
  case 0:

    PCA0CPH3 = level;break;
  case 1:
    PCA0CPH2 = level;break;
  case 2:
    PCA0CPH1 = level;break;
  case 3:
    PCA0CPH0 = level;
  };
}

void setLED_EN(uint8_t idx, bool en)
{
  if (en)
  {
    switch (idx)
    {
    case 0:
      PCA0CPM3 |= (2);break;
    case 1:
      PCA0CPM2 |= (2);break;
    case 2:
      PCA0CPM1 |= (2);break;
    case 3:
      PCA0CPM0 |= (2);
    };
  }
  else
  {
    switch (idx)
    {
    case 0:
      PCA0CPM3 &= (~2);break;
    case 1:
      PCA0CPM2 &= (~2);break;
    case 2:
      PCA0CPM1 &= (~2);break;
    case 3:
      PCA0CPM0 &= (~2);
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
  uint8_t i;
  for (i = 0; i < 4; i++)
    resetLEDi(i, 0, LED_HIGH);
}

void funcPageLEDAni(uint8_t function_page)
{
  uint8_t i;

  resetLED();

  //delayMS(250);

  for (i = 0; i < 3; i++)
  {
    switch (function_page)
    {
    case 0:
      PCA0CPM3 ^= 2;
      break;
    case 1:
      PCA0CPM2 ^= 2;
      break;
    case 2:
      PCA0CPM1 ^= 2;
      break;
    case 3:
          PCA0CPM0 ^= 2;
          break;
    }

    delayMS(100);
  }

  resetLEDi(function_page, 0, LED_HIGH);
}

void LED_InitRoutine()
{
  uint8_t i = 0, k = 0;

  resetWDT();

  //set the initial led brightness
  for (i = 0; i < 4; i++)
    setLEDLevel(i, LED_LOW);

  //turn the PWM channels on
  for (i = 0; i < 4; i++)
    setLED_EN(i, 1);

  //do a little startup brightness thing
  for (i = 0xFF; i >= 0xE0; i--)
  {
      resetWDT();

      for (k = 0; k < 4; k++)
      setLEDLevel(k, i);

    delayMS(2000 / 32);
  }

  //set the led brightness
  for (i = 0; i < 4; i++)
    setLEDLevel(i, LED_HIGH);

  //turn the channels off
  for (i = 0; i < 4; i++)
    setLED_EN(i, 0);

  resetWDT();
}

