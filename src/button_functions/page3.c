/*
 * page3.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Stuart
 */

#include "button_functions/page_common.h"
#include "button_functions/page3.h"

#include "persistance.h"
#include "synth_interface/synth_common.h"
#include "main.h"
#include "utility.h"
#include "led_controls.h"
#include "display.h"
#include "interrupts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "touch_keys.h"
#include "value_lookup.h"


void b0F3(uint8_t sp) //upload default tuning and bank data after long press
{
  float calc2;

  presetHoldSequence(0);

  if (hold_ctr[0] == 4){

      setAmpEN(DISABLED);
      setSynthEN(POWER_OFF);
      delayMS(1000);

      //this need to be broken down and put into a method. there are way too many occurrences
      req_adc_vals = true;
      while (req_adc_vals);
      calc2 = adc_buffer[0];
      calc2 /= 4096.0;
      calc2 *= 3.3;
      calc2 *= 2.0;
      if ((int)calc2 >= 3)
        {
          //the synth is probably receiving extrernal power. display message. reset.
          fillScreen(ST7735_BLACK);
          drawtext(0, 0, "CMODA EXT POWER", ST7735_WHITE, ST7735_BLACK, 2);
          drawtext(0, 1, "FAILED TEST", ST7735_BLUE, ST7735_BLACK, 2);
          drawtext(0, 2, "RESETTING...", ST7735_WHITE, ST7735_BLACK, 2);
          delayMS(5000);
          softPowerCycle();
          delayMS(2000);
          softPowerCycle();
          fillScreen(ST7735_BLACK);
          drawtext(0, 0, "FAILED TO RESET. MANUALLY POWER CYCLE THE DEVICE.", ST7735_WHITE, ST7735_BLACK, 2);
          delayMS(5000);
          return;
        }

      //
      softPowerCycle();
      delayMS(2000);
      softPowerCycle();


      tuning_test();

      softPowerCycle();
      delayMS(2000);
      softPowerCycle();

      decompress_test();

      softPowerCycle();
      delayMS(2000);
      softPowerCycle();



    //init_synth_mode();
    active_config.function_page = 0;
    funcPageLEDAni(0);
  }

  hold_ctr[0]++;
  touch_timer[0] = millis();
}

void b1F3(uint8_t sp) //edit program menu
{
   uint8_t  last_resulti[4];
     uint32_t  touch_timeri[4];
     uint8_t  hold_ctri[4] = {0,0,0,0};
    uint8_t  resulti[4] = {0, 0, 0, 0};
    uint16_t data i = 0;

    uint8_t data digits[3] = {0,0,0};
    uint16_t data param_number = 0;
    uint8_t * text_pointer;
    uint8_t text_buf[24];

    float data calc;
    uint8_t data calc_res;

    CV_CAL * data active_cal = &active_config.persistant_cfg.cv_cal;

    bool data locki = true;
    bool data modei = true;

    uint32_t data lcd_refresh_timer = millis();

  presetHoldSequence(BUTTON_2);

  if (hold_ctr[BUTTON_2] == 4)
    {
      //calibration submenu
      fillScreen(ST7735_BLACK);
      drawtext(0, 0, "LIVE PARAM", ST7735_WHITE, ST7735_BLACK, 2);


      //buttons 3,2,1 edit the digit. button 4 short press enables and disables editing. button 4 long press exits.
      for(i = 0; i < 4; i++)
        touch_timeri[i] = millis();
      sampleTouchSensors();
      while(1)
      {
          req_adc_vals = true;

          drawtext(0, 1, locki ? "LOCK  " : "UNLOCK", locki ? ST7735_BLUE : ST7735_RED, ST7735_BLACK, 2);

          //drawtext(0, 4, active_config.system_mode == XVA_MODE ? xva_lookup[param_number].name : xfm_lookup[param_number].name, ST7735_WHITE, ST7735_BLACK, 1);
          text_pointer = active_config.system_mode == XVA_MODE ? xva_lookup[param_number].name : xfm_lookup[param_number].name;
          memset(text_buf, ' ', 24);
          strcpy(text_buf, text_pointer);
          for(i = 0; i < 24; i++)
            if(text_buf[i] == '\0')
              text_buf[i] = ' ';
          text_buf[23] = '\0';
          drawtext(0, 4,text_buf ,ST7735_WHITE, ST7735_BLACK, 1);

          sampleTouchSensors();

                    for (i = 0; i < 4; i++)
                                  resulti[i] = (b_touch_timer[i] > active_config.persistant_cfg.touch_cal[i]); //1 touched, 0 no touch

                                for (i = 0; i < 4; i++)
                                {
                                  if (((resulti[i] == last_resulti[i]) && hold_ctri[i] == 0) || (uint32_t)((int32_t)millis() - touch_timeri[i]) < 250)
                                    continue;
                                  else
                                  {
                                    touch_timeri[i] = millis();

                                    if (resulti[i]) //button is touched
                                    {
                                      //if(i < BUTTON_4)
                                      //  B_FUNC_PAGES[i][active_config.function_page](0);
                                      //else
                                      //  button4Functions();

                                        if(i == BUTTON_4)
                                          {

                                            if (hold_ctri[BUTTON_4]++ == 4)
                                              {
                                                forceLCDRefresh();
                                                button4ShortPress ();
                                              return;
                                              }
                                          }
                                        else
                                          if(i == BUTTON_3)
                                            {
                                              digits[0]++;
                                              if(digits[0] > 5)
                                                digits[0] = 0;

                                              locki = true;
                                            }
                                          else
                                            if(i == BUTTON_2)
                                              {
                                                digits[1]++;
                                                if(digits[1] > 9)
                                                  digits[1] = 0;

                                                locki = true;
                                              }
                                            else
                                              if(i == BUTTON_1)
                                                {
                                                  if (hold_ctri[BUTTON_1] == 4)
                                                    {
                                                        modei = !modei;
                                                  continue;
                                                    }

                                                  digits[2]++;
                                                  if(digits[2] > 9)
                                                    digits[2] = 0;

                                                  locki = true;
                                                }

                                      continue;
                                    }

                                    //button has been released
                                    if (i == BUTTON_4 && hold_ctri[BUTTON_4] > 0)
                                      {
                                      locki = !locki;
                                      //continue;
                                      }



                                    //  if (i < BUTTON_4 && hold_ctr[i] < SHORT_PRESS_MAX_HOLD_COUNT)
                                    //    B_FUNC_PAGES[i][active_config.function_page](SHORT_PRESS);

                                    hold_ctri[i] = 0;
                                    last_resulti[i] = resulti[i];
                                  }

                                  resetLED();
                                }


                                #define MAX_LCD_REFRESH 1/20
                                if ((uint32_t) ((int32_t) millis () - lcd_refresh_timer) >= MAX_LCD_REFRESH)
                                  {



                                param_number = digits[0] * 100 + digits[1] * 10 + digits[2];

                                text_buf[1] = '\0';
                                text_buf[0] = digits[0]+0x30;
                                drawtext(140, 0, text_buf, ST7735_WHITE, ST7735_BLACK, 3);
                                text_buf[0] = digits[1]+0x30;
                                drawtext(140, 1, text_buf, ST7735_WHITE, ST7735_BLACK, 3);
                                text_buf[0] = digits[2]+0x30;
                                drawtext(140, 2, text_buf, ST7735_WHITE, ST7735_BLACK, 3);

                                while(req_adc_vals);

                                if(active_cal->cv0[0] < active_cal->cv0[1])
                                    {
                                    //cv0 scaling active
                                      calc = active_cal->scalar[0];

                                      if(adc_buffer[1] > active_cal->cv0[1])
                                        adc_buffer[1] = active_cal->cv0[1];
                                      if(adc_buffer[1] < active_cal->cv0[0])
                                        adc_buffer[1] = active_cal->cv0[0];

                                      adc_buffer[1] -= active_cal->cv0[0];

                                      calc = ((active_cal->scalar[0]) * (float)adc_buffer[1]);
                                    }
                                    else
                                    {
                                      calc = ((float)adc_buffer[1]);
                                    }

                                calc /= 4096.0;

                                sprintf(text_buf,"CV:%.1f%%  ", calc*100);
                                drawtext(0, 3, text_buf, ST7735_WHITE, ST7735_BLACK, 2);

                                calc *= active_config.system_mode == XVA_MODE ? xva_lookup[param_number].maximum : xfm_lookup[param_number].maximum;
                                calc_res = (calc+0.5);

                                if(!locki)
                                {
                                  U1txByte('s');
                                  U1txByte(param_number >= 255 ? 255 : param_number);
                                  if(param_number >= 255)
                                    U1txByte(param_number-256);
                                  U1txByte(calc_res);
                                }
                                else
                                  {
                                    uint8_t sample_a, sample_b;

                                    do
                                      {
                                    U1rxByte(0);
                                    U1rxByte(0);
                                    U1txByte('g');
                                    U1txByte(param_number >= 255 ? 255 : param_number);
                                    if(param_number >= 255)
                                      U1txByte(param_number-256);
                                    sample_a = U1rxByte(1000);

                                    U1txByte('g');
                                                                        U1txByte(param_number >= 255 ? 255 : param_number);
                                                                        if(param_number >= 255)
                                                                          U1txByte(param_number-256);
                                                                        sample_b = (uint8_t)U1rxByte(1000);
                                      }
                                    while(sample_a != sample_b);

                                    calc_res = sample_a;


                                  }


                                sprintf(text_buf,"val:%u    ", (int)calc_res);
                                drawtext(0, 4, text_buf, ST7735_WHITE, ST7735_BLACK, 2);



                                lcd_refresh_timer = millis();
                                  }
      } //// while end
    }

  hold_ctr[BUTTON_2]++;
  touch_timer[BUTTON_2] = millis();

}

void b2F3(uint8_t sp) //touch cal
{
  char print_buf[20];
  volatile uint8_t last_result[4];
  volatile uint32_t touch_timer[4];
  volatile uint8_t hold_ctr[4];
  uint8_t result[4] = {0, 0, 0, 0};
  uint16_t i = 0;
  uint8_t cal_target = 0;

  while(1)
    {
      //calibration submenu
      fillScreen(ST7735_BLACK);
      drawtext(0, 0, "CALIBRATION", ST7735_WHITE, ST7735_BLACK, 2);

      while(1)
        {
          //display vars, unit select
          req_adc_vals = true;

          sprintf(print_buf,"CV0: %.2f", ((float)adc_buffer[1]/4096.0)*3.3);
          drawtext(0, 1, print_buf, ST7735_WHITE, ST7735_BLACK, 2);

          //cv0 low
          sprintf(print_buf,"LOW: %.2f", ((float)active_config.persistant_cfg.cv_cal.cv0[0]/4096.0)*3.3);
          drawtext(0, 4, print_buf, cal_target == 0 ? ST7735_RED : ST7735_WHITE, ST7735_BLACK, 1);

          //cv0 high
          sprintf(print_buf,"HIGH: %.2f", ((float)active_config.persistant_cfg.cv_cal.cv0[1]/4096.0)*3.3);
          drawtext(80, 4, print_buf, cal_target == 1 ? ST7735_RED : ST7735_WHITE, ST7735_BLACK, 1);

          sprintf(print_buf,"CV1: %.2f", ((float)adc_buffer[2]/4096.0)*3.3);
          drawtext(0, 3, print_buf, ST7735_WHITE, ST7735_BLACK, 2);

          //cv1 low
                    sprintf(print_buf,"LOW: %.2f", ((float)active_config.persistant_cfg.cv_cal.cv1[0]/4096.0)*3.3);
                    drawtext(0, 8, print_buf, cal_target == 2 ? ST7735_RED : ST7735_WHITE, ST7735_BLACK, 1);

                    //cv2 high
                    sprintf(print_buf,"HIGH: %.2f", ((float)active_config.persistant_cfg.cv_cal.cv1[1]/4096.0)*3.3);
                    drawtext(80, 8, print_buf, cal_target == 3 ? ST7735_RED : ST7735_WHITE, ST7735_BLACK, 1);

          sampleTouchSensors();

          for (i = 0; i < 4; i++)
                        result[i] = (b_touch_timer[i] > active_config.persistant_cfg.touch_cal[i]); //1 touched, 0 no touch

                      for (i = 0; i < 4; i++)
                      {
                        if (((result[i] == last_result[i]) && hold_ctr[i] == 0) || (uint32_t)((int32_t)millis() - touch_timer[i]) < 250)
                          continue;
                        else
                        {
                          touch_timer[i] = millis();

                          if (result[i]) //button is touched
                          {
                            //if(i < BUTTON_4)
                            //  B_FUNC_PAGES[i][active_config.function_page](0);
                            //else
                            //  button4Functions();

                              if(i == BUTTON_4)
                                {

                                  //calc scalar
                                  active_config.persistant_cfg.cv_cal.scalar[0] = 4096.0/(active_config.persistant_cfg.cv_cal.cv0[1]-active_config.persistant_cfg.cv_cal.cv0[0]);
                                  active_config.persistant_cfg.cv_cal.scalar[1] = 4096.0/(active_config.persistant_cfg.cv_cal.cv1[1]-active_config.persistant_cfg.cv_cal.cv1[0]);

                                  write_cfg();

                                  button4ShortPress();
                                  init_synth_mode();


                                return;
                                }
                              else
                                if(i == BUTTON_1)
                                  {
                                    cal_target+=1;
                                    if(cal_target > 3)
                                      cal_target = 0;
                                  }
                                else
                                  if(i == BUTTON_2)
                                    {
                                      switch(cal_target)
                                      {
                                        case 0: active_config.persistant_cfg.cv_cal.cv0[0] = adc_buffer[1]; break;
                                        case 1: active_config.persistant_cfg.cv_cal.cv0[1] = adc_buffer[1]; break;
                                        case 2: active_config.persistant_cfg.cv_cal.cv1[0] = adc_buffer[2]; break;
                                        case 3: active_config.persistant_cfg.cv_cal.cv1[1] = adc_buffer[2]; break;
                                      }
                                    }
                                  else
                                    if(i == BUTTON_3)
                                      {
                                        switch(cal_target)
                                        {
                                          case 0: active_config.persistant_cfg.cv_cal.cv0[0] = 0; break;
                                          case 1: active_config.persistant_cfg.cv_cal.cv0[1] = 4096; break;
                                          case 2: active_config.persistant_cfg.cv_cal.cv1[0] = 0; break;
                                          case 3: active_config.persistant_cfg.cv_cal.cv1[1] = 4096; break;
                                        }
                                      }

                            continue;
                          }

                          //if (i == BUTTON_4 && hold_ctr[BUTTON_4] < 3)
                          //  button4ShortPress();

                          //  if (i < BUTTON_4 && hold_ctr[i] < SHORT_PRESS_MAX_HOLD_COUNT)
                          //    B_FUNC_PAGES[i][active_config.function_page](SHORT_PRESS);

                          hold_ctr[i] = 0;
                          last_result[i] = result[i];
                        }

                        resetLED();
                      }
        }

    }
}
