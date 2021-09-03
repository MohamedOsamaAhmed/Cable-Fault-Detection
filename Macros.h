/*
 * macros.h
 *
 *  Created on: Aug 3, 2019
 *      Author: Mohamed Osama
 */


#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg,bit) (reg |=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TOGGLE_BIT(reg,bit) (reg ^=(1<<bit))
#define GET_BIT(reg,bit) ((reg>>bit)&1)

#endif /* MACROS_H_ */
