/**
 * @file flash.c
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
#include "eeprom_config.h"
#include "flash.h"


/* Global variables*/
SI_SEGMENT_VARIABLE(flashKey1, uint8_t, SI_SEG_DATA) = 0x00;
SI_SEGMENT_VARIABLE(flashKey2, uint8_t, SI_SEG_DATA) = 0x00;
SI_SEGMENT_VARIABLE(flashAddress, uint16_t, SI_SEG_DATA) = FLASH_SAFE_ADDR;

/* Internal Constants */
#define FL_WRITE        0x01        // PSCTL mask for Flash Writes
#define FL_ERASE        0x03        // PSCTL mask for Flash Erase

/**
 * @fn static void flash_setup_key(uint8_t key1, uint8_t key2, uint16_t address)
 * @brief Setup flash key1, key2 and address
 *
 * @param key1 flash key code 1
 * @param key2 flash key code 2
 * @param address flash address to be operated
 *
 */
static void flash_setup_key(uint8_t key1, uint8_t key2, uint16_t address)
{
	flashAddress = address;
	flashKey2 = key2;
	flashKey1 = key1;
}

/**
 * @fn static void flash_write_erase(uint16_t address, uint8_t byte, uint8_t write_erase)
 * @brief This routine writes a byte or erases a page of Flash.
 *
 * @param address 16-bit address in code space to write/erase
 * @param byte data byte to write (value is don't care on erase)
 * @param write_erase 0x01 for writes, 0x03 to erase page
 *
 * @return none
 */
static void flash_write_erase(uint16_t address, uint8_t byte, uint8_t write_erase)
{
	bit EA_SAVE = IE_EA;
	SI_SEGMENT_VARIABLE_SEGMENT_POINTER(pwrite, uint8_t, SI_SEG_XDATA, SI_SEG_DATA);
	PSBANK_STORE()
	SFRPAGE_SWITCH()

	if ((address > EE_TOP_ADDR) || (address < EE_BASE_ADDR)){
		FL_PROTECT()
		SFRPAGE_RESTORE()
		return;
	}
	ENABLE_VDDMON()
	IE_EA = 0;

	flash_setup_key(0xA5, 0xF1, address);
	pwrite = (uint8_t SI_SEG_XDATA *) flashAddress;
	PSBANK_SWITCH()
	ENABLE_FL_MOD()
	/* setup PSEE, PSWE */
	PSCTL |= (write_erase & 0x03);
	*pwrite = byte;
	PSCTL &= ~0x03;
	DISABLE_FL_MOD()
	PSBANK_RESTORE()

	flash_setup_key(0x00,0x00,FLASH_SAFE_ADDR);
	IE_EA = EA_SAVE;
	SFRPAGE_RESTORE()
}

void flash_erase_page(uint16_t address)
{
	flash_write_erase(address,0, FL_ERASE);
}

void flash_write_byte(uint16_t address, uint8_t dat)
{
	flash_write_erase(address, dat, FL_WRITE);
}

uint8_t flash_read_byte(uint16_t address)
{
	uint8_t dat;
	PSBANK_STORE()
	PSBANK_SWITCH()
	dat = *((uint8_t SI_SEG_CODE *) address);
	PSBANK_RESTORE()
	return dat;
}

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
