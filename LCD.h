
#ifndef _LCD_H_
#define _LCD_H_
#define LCD_EN_Delay 500

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_FunctionSet4bit 0x28
#define lcd_SetCursor       0x80          // set cursor position
#define R0					0x0
#define C0					0x0
#define R1					0x1

//==========================================
//-----[ Prototypes For All Functions ]-----

void LCD_Init_4bit();  // Initialize The LCD For 4-Bit Interface
void LCD_Clear(); // Clear The LCD Display

void LCD_Vid_Write_Data_4bit(uint8 data);
void LCD_CMD_4bit(uint8 CMD);
void LCD_Vid_Select_Position(uint8 row,uint8 column);
void LCD_Write_String(uint8 * );  // Write A String To LCD
void LCD_Vid_Write_Number(uint32 );
//------------------------------------------
#endif
