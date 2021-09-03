/*
 * App.c
 *
 *  Created on: Aug 20, 2021
 *      Author: MohamedOsamaAhmed
 */
#include "Platform_Types.h"
#include "App.h"
#include "Registers.h"
#include "Analog_Comparator.h"
#include "App_cfg.h"
#include "Button.h"
#include "DIO.h"
#include "Macros.h"
#include "LCD.h"
#include "Timer.h"
#include "PWM_cfg.h"
#include "PWM.h"
#include <util/delay.h>

void App_Discharge_Cable_Capacitance()
{
	/* Discharge Capacitor First */
	/* Set charge pin or the first terminal of the cable low */
		DIO_Vid_Set_Pin_Direcition(CHARGE_PORT,CHARGE_PIN,OUTPUT);
		DIO_Vid_Set_Pin_Value(CHARGE_PORT,CHARGE_PIN,STD_LOW);

	/* Set discharge pin or the other terminal of the cable low */
		DIO_Vid_Set_Pin_Direcition(DISCHARGE_PORT,DISCHARGE_PIN,OUTPUT);
		DIO_Vid_Set_Pin_Value(DISCHARGE_PORT,DISCHARGE_PIN,STD_LOW);

	/* Till all volt reach zero*/
	_delay_ms(1000);
}

void App_Charge_Cable_With_Capacitance()
{
	DIO_Vid_Set_Pin_Direcition(DISCHARGE_PORT,DISCHARGE_PIN,INPUT);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(CHARGE_PORT,CHARGE_PIN,STD_HIGH);
}

void App_Function()
{
	uint32 capacitance_value_sample1 = 0x0;
	uint32 capacitance_value_sample2 = 0x1;
	uint32 distance_integer_part = 0x0;
	uint32 distance_fraction_part = 0x0;

	/* Initialize All peripherals */
	App_Init();
	/* Set Voltage reference = 63.2% of 5 which is 3.16V */
	PWM2_Set_DC_Volt(RESNONACE_VOLT * VDD);


	while (1)
	{
		/* Ask user to press button to start measuring  */
		LCD_Vid_Select_Position(R0,C0);
		LCD_Write_String((uint8 *)("Press Button"));

		/* check if button is pressed */
		while (Button_Get_Status() == STD_HIGH)
		{
			/* Clear LCD and notify user that measuring process is running */
			LCD_Vid_Select_Position(R0,C0);

			LCD_Write_String((uint8 *)(".. Measuring .."));
			while (capacitance_value_sample1 != capacitance_value_sample2)
			{
				App_Measure_Capacitance();
				/* Calculate capacitance value */
				capacitance_value_sample1 = App_Calculate_Capacitance();

				App_Measure_Capacitance();
				/* Calculate capacitance value */
				capacitance_value_sample2 = App_Calculate_Capacitance();
			}

				/* Remove bread board capacitance */
				capacitance_value_sample1 -= BREAD_BOARD_CAPACITANCE;
				/* Calculate Distance */
				App_Calculate_Distance(capacitance_value_sample1,&distance_integer_part,&distance_fraction_part);

				/* Print Results */
				App_Print_Results(capacitance_value_sample1,distance_integer_part,distance_fraction_part);
				/* Initialize capacitance value with any different values to enter the above while */
				capacitance_value_sample1 = 0x0;
				capacitance_value_sample2 = 0x1;
		}

	}
}
void App_Print_Results(uint32 capacitance_value, uint32 distance_integer_part, uint32 distance_fraction_part)
{
	LCD_Clear();
	/* Write Distance at which there is a fault */
	LCD_Vid_Select_Position(R0,C0);
	LCD_Write_String((uint8 *)"C_pf: ");
	LCD_Vid_Write_Number(capacitance_value);

	/* Write Distance at which there is a fault */
	LCD_Vid_Select_Position(R1,C0);
	LCD_Write_String((uint8 *)"Fault At : ");
	LCD_Vid_Write_Number(distance_integer_part);
	LCD_Write_String((uint8 *)".");
	LCD_Vid_Write_Number(distance_fraction_part);

	_delay_ms(3000);
	LCD_Clear();

}

void App_Measure_Capacitance()
{
	/* First discharge all voltage on the cable to get correct readings */
	App_Discharge_Cable_Capacitance();

	/* Start Charging cable */
	App_Charge_Cable_With_Capacitance();

	/* Start Counting to calculate time */
	START_COUNTING;
	/* Wait till voltage value reach 63.2% */
	while (COMPARATOR_FLAG == 0)
	{
		/* Do nothing */
	}
	STOP_COUNTING;
}
uint32 App_Calculate_Capacitance()
{
	uint32 capacitance = 0x0;
	uint32 time_in_ticks = 0x0;
	float32 time_ms = 0.0;

	/* Get all time ticks  */
	time_in_ticks = Timer1_Get_Time_In_Ticks();

	/* calculate time in millisecond where clk freq 8MHz*/
	time_ms = Timer1_Calculate_Time_ms(time_in_ticks);

	/* Calculate capacitance in picoFarad where tau= RC : tau in seconds, R in Ohm and C in Farad  */
	capacitance = (time_ms * 1000000 /(RESISTOR_VALUE_IN_KILO));

	return (uint32)capacitance;

}
void App_Calculate_Distance(uint32 capacitance_value, uint32 *distance_integer_part, uint32 *distance_fraction_part)
{

	float32 distance_in_cm = 0.0;
	distance_in_cm = capacitance_value/((float32)CAPACITANCE_PER_CM);

	/* Store values in passed arguments */
	*distance_integer_part = (uint32 )distance_in_cm;
	*distance_fraction_part = ((uint32)(distance_in_cm * 100)%100);
}
void App_Init()
{
	LCD_Init_4bit();
	Analog_Compartor_Polling_Init();
	Button_Init();
	PWM2_Init ();
	Timer1_Counter_Init();
}




