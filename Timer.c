/*

 * Timer.c

 *
 *  Created on: 31/1/2020
 *      Author: Mohamed Osama
 */

#include "Platform_Types.h"
#include "Macros.h"
#include "Registers.h"
#include "Timer.h"



volatile uint32 Number_Of_Counts = 0;
uint32 Timer1_Get_Time_In_Ticks()
{
	uint32 total_ticks = 0x0;
	/* calculate total number of ticks*/
	total_ticks = (OVER_FLOW_TICKS * Number_Of_Counts) + TIMER_REGISTER;

	/* clear variables for new usage*/
	Number_Of_Counts = 0x0;
	TIMER_REGISTER = 0x0;


	return total_ticks;
}

float32 Timer1_Calculate_Time_ms(uint32 total_ticks)
{
	/* calculate time in milliseconds */
	float32 time_ms =  (float32)total_ticks / CPU_CLK_IN_KHZ;
	return time_ms;
}
void Timer1_Counter_Init(void)
{
	/* Set TCNT1 Register = 0 */

	TCNT1 = 0x0;

	/* Normal port operation, OC1A/OC1B disconnected Normal Waveform Generation Mode */
	TCCR1A = 0x00;
	TCCR1B = 0x00;

	/* Clear interrupt flag */
	SET_BIT(TIFR,TOV1);

	/*  Enable TOIE1 Interrupt */
	SET_BIT(TIMSK,TOIE1);

	/* Enable Global Interrupt */
	SET_BIT(SREG,7);
}

#define __INTR_ATTRS used,externally_visible
void __vector_9(void)__attribute__((signal,__INTR_ATTRS));
void __vector_9(void)
{
	Number_Of_Counts ++;
}

