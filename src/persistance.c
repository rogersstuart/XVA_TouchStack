/*
 * persistance.c
 *
 *  Created on: Aug 17, 2021
 *      Author: Stuart
 */

#include "main.h"
#include "persistance.h"
#include "utility.h"
#include "EEPROM/eeprom_config.h"
#include "EEPROM/eeprom.h"

SYS_CONFIG active_config;

/*
SYS_CONFIG* getConfig(){
  return &active_config;
}
*/

void write_cfg(){

  uint8_t size = sizeof(SYS_CONFIG), i = 0;

  eeprom_init();

  eeprom_write_byte(0, BRINGUP_CODE);
  for(; i < size; i++)
    {
      petDog();
      eeprom_write_byte(i+1, *(((uint8_t*)&active_config)+i));
    }
}

bool read_cfg(){
  uint8_t size = sizeof(SYS_CONFIG), i = 0;

  eeprom_init();
  eeprom_read_byte(0,&i);

  if(i != BRINGUP_CODE)
    return false;
  else
      for(i = 0; i < size; i++)
        {
          petDog();
        eeprom_read_byte(i+1, (((uint8_t*)&active_config)+i));
        }

  return true;
}

//void testEEPROM()
//{

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
//}
