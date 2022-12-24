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

void b0F3(uint8_t sp) //switch mode
{
  float calc2;

  presetHoldSequence(0);

  if (hold_ctr[0] == 4){

      setAmpEN(DISABLED);
      setSynthEN(POWER_OFF);
      delayMS(1000);

      //this need to be broken down and put into a method. there are way too many occurances
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

void b1F3(uint8_t sp) //switch unit number
{
  presetHoldSequence(BUTTON_2);
  //if(hold_ctr[BUTTON_2] == 0){
  //  resetLEDi(BUTTON_2, ON, LED_HIGH);
  //  hold_ctr[BUTTON_2]++;
  //}
/*
  if(0)//if(sp)
  {

      active_config.unit_number = !active_config.unit_number;
    active_config.function_page = 0;
    write_cfg();
    funcPageLEDAni(0);
    init_synth_mode();
  }
*/
  if (hold_ctr[BUTTON_2] == 4)
    {
      //randomize
      randomizeProgram();
      //activatePreset(&active_config.active_preset);
      init_synth_mode();
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
          while(req_adc_vals);
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
