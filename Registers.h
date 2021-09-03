/*
 * Registers.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Mohamed Osama
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

/* Ports Registers */

#define DDRA *((volatile uint8 *)0x3A)
#define PORTA *((volatile uint8 *)0x3B)
#define PINA *((volatile uint8 *)0x39)


#define DDRB *((volatile uint8 *)0x37)
#define PORTB *((volatile uint8 *)0x38)
#define PINB *((volatile uint8 *)0x36)


#define DDRC *((volatile uint8 *)0x34)
#define PORTC *((volatile uint8 *)0x35)
#define PINC *((volatile uint8 *)0x33)


#define DDRD *((volatile uint8 *)0x31)
#define PORTD *((volatile uint8 *)0x32)
#define PIND *((volatile uint8 *)0x30)


/* Global interrupt register*/
#define SREG *((volatile uint8 *)0x5F)


/* Timer0 */
#define MCUCR *((volatile uint8 *)0x55)
#define GICR *((volatile uint8 *)0x5B)
#define TCNT0 *((volatile uint8 *)0x52)
#define OCR0 *((volatile uint8 *)0x5C)
#define TIMSK *((volatile uint8 *)0x59)
#define TCCR0 *((volatile uint8 *)0x53)
#define TIFR *((volatile uint8 *)0x58)

#define WGM00 6U
#define COM01 5U
#define COM00 5U
#define WGM01 3U
#define CS02  2U
#define CS01  1U
#define CS00  0U



/* Timer1 */
#define TCNT1 *((volatile uint16 *)0x4C)
#define TCCR1A *((volatile uint8 *)0x4F)
#define CS10 0U
#define TCCR1B *((volatile uint8 *)0x4E)

#define TCCR1B *((volatile uint8 *)0x4E)
#define ICR1 *((volatile u16 *)0x46)
#define OCR1A *((volatile u16 *)0x4A)

#define TOIE1 2U
#define TOV1  2U

// Timer2 Registers
#define TCNT2 *((volatile uint8 *)0x44)
#define TCCR2 *((volatile uint8 *)0x45)
#define OCR2 *((volatile uint8 *)0x43)

// TCCR2 Registers
#define FOC2 7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22 2
#define CS21 1
#define CS20 0

/* ADC */
#define ADMUX *((volatile uint8*) 0x27)
#define ADCSRA *((volatile uint8*) 0x26)
#define ADCREG *((volatile u16*) 0x24)


/* WATCH DOG */
#define WDTCR *((volatile uint8*) 0x41)

/* Analog Comparator */
#define SFIOR *((volatile uint8*) 0x50)
/* SFIOR Register Bits */
#define ACME  3U

#define ACSR *((volatile uint8*) 0x28)

/* ACSR Registers Bits */
#define ACD   7U
#define ACBG  6U
#define ACO   5U
#define ACI   4U
#define ACIE  3U
#define ACIC  2U
#define ACIS1 1U
#define ACIS0 0U

#endif /* REGISTERS_H_ */
