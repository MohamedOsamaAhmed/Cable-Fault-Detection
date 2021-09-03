/*
 * App.h
 *
 *  Created on: Aug 20, 2021
 *      Author: MohamedOsamaAhmed
 */

#ifndef _APP_H_
#define _APP_H_

#include "Platform_Types.h"

void App_Calculate_Distance(uint32 capacitance_value, uint32 *integer_part, uint32 *fraction_part);
void App_Discharge_Cable_Capacitance ();
void App_Charge_Cable_With_Capacitance ();
void App_Function();
void App_Init();
void App_Measure_Capacitance();
void App_Print_Results(uint32 , uint32 , uint32 );
uint32 App_Calculate_Capacitance();
#endif /* APP_H_ */
