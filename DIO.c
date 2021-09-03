#include "Std_Types.h"
#include "Macros.h"
#include "DIO.h"
#include "Registers.h"

void DIO_Vid_Set_Port_Direction(uint8 port_number,uint8 value)
{
	switch(port_number)
		{
		case A:
			DDRA = value;
			break;
		case B:
			DDRB = value;
			break;
		case C:
			DDRC = value;
			break;
		case D:
			DDRD = value;
			break;
		}

}

void DIO_Vid_Set_Port_Value(uint8 port_number,uint8 value)
{
	switch(port_number)
		{
		case A:
			PORTA = value;
			break;
		case B:
			PORTB = value;
			break;
		case C:
			PORTC = value;
			break;
		case D:
			PORTD = value;
			break;
		}

}



uint8 DIO_uint8_Read_Port_Value(uint8 port_number)
{
	uint8 value ;
	switch (port_number)
	{
	case A:
		value = PINA;
		break;
	case B:
		value = PINB;
		break;
	case C:
		value = PINC;
		break;
	case D:
		value = PIND;
		break;
	}
	return value;

}
void DIO_Vid_Set_Pin_Direcition(uint8 port_number, uint8 pin_number,uint8 value)
{
	switch(port_number)
		{
		case A:
			if (value == 1)
				SET_BIT(DDRA, pin_number);
			else if ( value == 0)
				CLEAR_BIT(DDRA , pin_number);
			break;
		case B:
			if (value == 1)
				SET_BIT(DDRB, pin_number);
			else if ( value == 0)
				CLEAR_BIT(DDRB , pin_number);
			break;
		case C:
			if (value == 1)
				SET_BIT(DDRC, pin_number);
			else if ( value == 0)
				CLEAR_BIT(DDRC , pin_number);
			break;
		case D:
			if (value == 1)
				SET_BIT(DDRD, pin_number);
			else if ( value == 0)
				CLEAR_BIT(DDRD , pin_number);
			break;
		}

}

void DIO_Vid_Set_Pin_Value(uint8 port_number, uint8 pin_number,uint8 value)
{

	switch(port_number)
		{
		case A:
			if (value == 1)
				SET_BIT(PORTA, pin_number);
			else if ( value == 0)
				CLEAR_BIT(PORTA , pin_number);
			break;
		case B:
			if (value == 1)
				SET_BIT(PORTB, pin_number);
			else if ( value == 0)
				CLEAR_BIT(PORTB , pin_number);
			break;
		case C:
			if (value == 1)
				SET_BIT(PORTC, pin_number);
			else if ( value == 0)
				CLEAR_BIT(PORTC , pin_number);
			break;
		case D:
			if (value == 1)
				SET_BIT(PORTD, pin_number);
			else if ( value == 0)
				CLEAR_BIT(PORTD , pin_number);
			break;
		}

}

uint8 DIO_uint8_Read_Pin_Value(uint8 port_number,uint8 pin_number)
{
	uint8 value;
	switch(port_number)
		{
		case A:
			value = GET_BIT(PINA,pin_number);
			break;
		case B:
			value = GET_BIT(PINB,pin_number);
			break;
		case C:
			value = GET_BIT(PINC,pin_number);
			break;
		case D:
			value = GET_BIT(PIND,pin_number);
			break;
		}
	return value;

}



