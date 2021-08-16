/**
 * @file flash.h
 * @brief Flash read/write/erase interface of EEPROM emulation.
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
#ifndef __FLASH_H__
#define __FLASH_H__

/**
 * @fn void flash_erase_page(uint16_t address)
 * @brief erase a flash page.
 *
 * @param address flash page address to be erased
 *
 */
extern void flash_erase_page(uint16_t address);

/**
 * @fn void flash_write_byte(uint16_t address, uint8_t dat)
 * @brief Write a byte into flash.
 *
 * @param address physical address in flash
 * @param dat data byte to write
 */
extern void flash_write_byte(uint16_t address, uint8_t dat);

/**
 * @fn uint8_t flash_read_byte(uint16_t address)
 * @brief Read a byte from flash
 *
 * @param address physical address in flash
 *
 * @return dat data byte read from flash
 */
extern uint8_t flash_read_byte(uint16_t address);

#endif

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
