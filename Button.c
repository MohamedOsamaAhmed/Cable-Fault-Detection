/*
 * Button.c
 *
 *  Created on: Aug 20, 2021
 *      Author: MohamedOsamaAhmed
 */
#include "Platform_Types.h"
#include "DIO.h"
#include "Button.h"
#include "Button_cfg.h"
#include <util/delay.h>
void Button_Init()
{
	/*  Pin of Tactile Button As A Pull Up Resistor */
	DIO_Vid_Set_Pin_Direcition(BUTTON_PORT,BUTTON_PIN,INPUT);
	DIO_Vid_Set_Pin_Value(BUTTON_PORT,BUTTON_PIN,STD_HIGH);



}
uint8 Button_Get_Status()
{
	/* Set initial status with zero*/
	uint8 button_status = 0;
	if (DIO_uint8_Read_Pin_Value(BUTTON_PORT,BUTTON_PIN) == 0)
		{
			/* delay to ensure that is a human press */
			_delay_ms(5);
			if (DIO_uint8_Read_Pin_Value(BUTTON_PORT,BUTTON_PIN) == 0)
			{
				button_status = 1;
			}
		}
	return button_status;
}


