 /******************************************************************************
 *
 * Module: Common - Platform
 *
 * File Name: Std_Types.h
 *
 * Description: General type definitions
 *
 * Author: Mohamed Osama
 *
 *******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"

/* Ports Number */
#define A 0
#define B 1
#define C 2
#define D 3


#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

#define E_OK            ((uint8)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((uint8)0x01U)      /* Function Return NOT OK */


#define INPUT  0x00U
#define OUTPUT 0x01U

#endif /* STD_TYPES_H */
