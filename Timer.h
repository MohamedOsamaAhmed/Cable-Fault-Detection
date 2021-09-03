/*

 * Timer.h
 *
 *  Created on: 22/1/2020
 *      Author: Mohamed Osama
 */

#ifndef _TIMER_H_
#define _TIMER_H_

#define TIMER_REGISTER TCNT1
#define OVER_FLOW_TICKS 65536
#define CPU_CLK_IN_KHZ 8000
#define START_COUNTING (TCCR1B=(1<<CS10))
#define STOP_COUNTING (TCCR1B=0x0)

void Timer1_Counter_Init();
uint32 Timer1_Get_Time_In_Ticks();
float32 Timer1_Calculate_Time_ms(uint32 total_ticks);


#endif /* TIMER_H_ */
