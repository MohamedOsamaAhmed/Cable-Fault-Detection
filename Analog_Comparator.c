/*
 * Analog_Compartor.c
 *
 *
 *  Created on: 17/8/2021
 *      Author: Mohamed Osama
 */
#include "Analog_Comparator.h"

#include "Std_Types.h"
#include "Macros.h"
#include "Registers.h"
/******************************
* 	The Analog Comparator compares the input values on the positive pin AIN0 and negative pin AIN1.
* 	When the voltage on the positive pin AIN0 is higher than the voltage on
*	the negative pin AIN1, the Analog Comparator Output, ACO, is set. The comparator’s
*	output can be set to trigger the Timer/Counter1 Input Capture function. In addition, the
*	comparator can trigger a separate interrupt, exclusive to the Analog Comparator. The
*	user can select Interrupt triggering on comparator output rise, fall or toggle
*****************************/


/*	This function to initialize analog comparator in polling mode */
void Analog_Compartor_Polling_Init (void)
{
	/* Enable AIN1 for -ve input */
	CLEAR_BIT(SFIOR,ACME);
	/* Clear all flags and disable interrupt and Input Capture */
	ACSR = 0x10;
}

