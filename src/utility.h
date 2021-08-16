/*
 * utility.h
 *
 *  Created on: Aug 15, 2021
 *      Author: Stuart
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <SI_EFM8BB3_Register_Enums.h> // SFR declarations

extern bool tx_int_flag;

void get_dec_str (uint16_t val);
void petDog();

#endif /* UTILITY_H_ */
