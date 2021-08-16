/**
 * @file eeprom.h
 * @brief Header file of EEPROM emulator interface.
 *
 * @date 2 Sep 2013
 * @version 1.0
 * @author Mark Ding
 *
 ******************************************************************************
 * @section License
 * <b>Copyright (c) 2013 by Silicon Laboratories. http://www.silabs.com</b>
 ******************************************************************************
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Silicon Laboratories End User
 * License Agreement which accompanies this distribution, and is available at
 * http://developer.silabs.com/legal/version/v10/License_Agreement_v10.htm
 * Original content and implementation provided by Silicon Laboratories.
 */
#ifndef __EEPROM_H__
#define __EEPROM_H__
/**
 * @fn uint8_t eeprom_init()
 * @brief
 *   It restores the pages to good state in case of page status corruption
 * after a power loss or unwanted system reset.And also it will create bit map
 * for those address which has valid value inside. With the bit map, eeprom read
 * function can check the bit map instead of checking contents in eeprom. Which
 * will definitely save time cost.
 *
 * @return 0: success; 1: error
 */
extern uint8_t eeprom_init();

/**
 * @fn uint8_t eeprom_write_byte(uint8_t log_addr, uint8_t byte)
 * @brief eeprom byte write interface
 *
 * It writes a byte to eeprom
 *
 * @param log_addr address in eeprom for data write in.
 * @param byte byte data write into eeprom.
 *
 * @return 0: success; 1: error
 */
extern uint8_t eeprom_write_byte(uint8_t log_addr, uint8_t byte);

/**
 * @fn uint8_t eeprom_read_byte(uint8_t log_addr, uint8_t *byte)
 * @brief eeprom byte read interface
 *
 * It read a byte from eeprom
 *
 * @param log_addr address in eeprom for data read out.
 * @param *byte pointer to byte data read from eeprom.
 *
 * @return 0: success; 1: error
 */
extern uint8_t eeprom_read_byte(uint8_t log_addr, uint8_t *byte);

#endif

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
