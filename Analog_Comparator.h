/*
 * Analog_Compartor.h
 *
 *  Created on: 17/8/2021
 *      Author: Mohamed Osama
 */

#ifndef _ANALOG_COMPARTOR_H_
#define _ANALOG_COMPARTOR_H_

void Analog_Compartor_Polling_Init (void);
#define COMPARATOR_FLAG GET_BIT(ACSR,ACO)

#endif /* ANALOG_COMPARTOR_H_ */
