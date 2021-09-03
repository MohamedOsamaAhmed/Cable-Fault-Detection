/*
 * DIO.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Mohamed Osama
 */

#ifndef DIO_H_
#define DIO_H_
#include "STD_Types.h"


void DIO_Vid_Set_Port_Direction(uint8 port_number,uint8 value);
void DIO_Vid_Set_Port_Value(uint8 port_number,uint8 value);
uint8 DIO_uint8_Read_Port_Value(uint8 port_number);
uint8 DIO_uint8_Read_Pin_Value(uint8 port_number,uint8 pin_number);
void DIO_Vid_Set_Pin_Value(uint8 port_number, uint8 pin_number,uint8 value);
void DIO_Vid_Set_Pin_Direcition(uint8 port_number, uint8 pin_number,uint8 value);

#endif /* DIO_H_ */
