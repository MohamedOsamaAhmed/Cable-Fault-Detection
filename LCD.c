#include "STD_Types.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "Registers.h"
#include "DIO.h"
#include <util/delay.h>

/*
void LCD_DATA(unsigned char Data)
{


	if (Data & 1)
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D4, 1);
	}
	else
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D4, 0);
	}

	if (Data & 2)
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D5, 1);
	}
	else
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D5, 0);
	}
	if (Data & 4)
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D6, 1);
	}
	else
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D6, 0);
	}
	if (Data & 8)
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D7, 1);
	}
	else
	{
		DIO_Vid_Set_Pin_Value(LCD_DATA_PORT, D7, 0);
	}




}
*/
void LCD_Vid_Write_Data_4bit(uint8 data)
{

	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT,RS_PIN,STD_HIGH);
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT,RW_PIN,STD_LOW);


	DIO_Vid_Set_Port_Value(LCD_DATA_PORT,data);


	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT,EN_PIN,STD_HIGH);
	_delay_us(LCD_EN_Delay);
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT, EN_PIN, STD_LOW);

	DIO_Vid_Set_Port_Value(LCD_DATA_PORT,(( data << 4)& 0xF0));


	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT,EN_PIN,STD_HIGH);
	_delay_us(LCD_EN_Delay);
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT, EN_PIN, STD_LOW);


}
void LCD_CMD_4bit(uint8 CMD)
{
	// Select Command Register
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT, RS_PIN, 0);
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT, RW_PIN, 0);

	// Send The EN Clock Signal
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT, EN_PIN, 1);

	DIO_Vid_Set_Port_Value(LCD_DATA_PORT,CMD);

	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT,EN_PIN,STD_HIGH);
	_delay_us(LCD_EN_Delay);
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT, EN_PIN, STD_LOW);

	DIO_Vid_Set_Port_Value(LCD_DATA_PORT,((CMD << 4) & 0xF0));

	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT,EN_PIN,STD_HIGH);
	_delay_us(LCD_EN_Delay);
	DIO_Vid_Set_Pin_Value(LCD_CONTROL_PORT, EN_PIN, STD_LOW);

}



void LCD_Init_4bit()
{
	/* IO Pin Configurations */
	/* Data Pins */
	DIO_Vid_Set_Pin_Direcition(LCD_DATA_PORT, D4, OUTPUT);
	DIO_Vid_Set_Pin_Direcition(LCD_DATA_PORT, D5, OUTPUT);
	DIO_Vid_Set_Pin_Direcition(LCD_DATA_PORT, D6, OUTPUT);
	DIO_Vid_Set_Pin_Direcition(LCD_DATA_PORT, D7, OUTPUT);


	/* Control Pins */

	DIO_Vid_Set_Pin_Direcition(LCD_CONTROL_PORT, RS_PIN, OUTPUT);
	DIO_Vid_Set_Pin_Direcition(LCD_CONTROL_PORT, RW_PIN, OUTPUT);
	DIO_Vid_Set_Pin_Direcition(LCD_CONTROL_PORT, EN_PIN, OUTPUT);


	// The Init. Procedure As Described In The Datasheet;


	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);
	LCD_CMD_4bit(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_CMD_4bit(LCD_FunctionSet4bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_CMD_4bit(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_CMD_4bit(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_CMD_4bit(lcd_EntryMode);
	_delay_ms(2);

}



void LCD_Vid_Select_Position(uint8 row,uint8 column)
{
	if (row == 0)
	{
		LCD_CMD_4bit(128+column);
	}
	else if(row == 1)
	{
		LCD_CMD_4bit(128+64+column);
	}

}
void LCD_Vid_Write_Number(uint32 number)
{
	uint32 reversed_Number = 1;

	if (number == 0)
		{
			LCD_Vid_Write_Data_4bit('0');
		}
	else if (number > 0)
	{
		while (number != 0)
		{
			reversed_Number = ((reversed_Number * 10) + (number % 10));
			number /= 10;

		}
		while (reversed_Number != 1)
		{
			LCD_Vid_Write_Data_4bit((reversed_Number % 10) + '0');
			reversed_Number /= 10;

		}
	}

}
void LCD_Write_String(uint8 *str)
{
	uint8 i;
	for (i = 0; str[i] != '\0'; i++)
		LCD_Vid_Write_Data_4bit(str[i]);
}

void LCD_Clear(void)
{

	LCD_CMD_4bit(0x1);
	_delay_ms(2);

}




