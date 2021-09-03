#include "Std_Types.h"
#include "Registers.h"
#include "PWM.h"
#include "PWM_cfg.h"
#include "DIO.h"

void PWM2_Init ()
{
	/*set fast PWM mode with non-inverted output with clock / 1024  and Clear OC2 on compare match, set OC2 at TOP */
	TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21)  | (1<<CS22)| (1<<CS21);
	/*set OC2 pin as output*/
	DIO_Vid_Set_Pin_Direcition(PWM2_PORT,PWM2_PIN,OUTPUT);
}

void PWM2_Set_DC_Volt(float32 out_volt)
{
	float32 duty_cycle;
	/* Calculate duty cycle from maximum duty value, output volt and VDD +1 for casting error */
	duty_cycle = ((float32)Max_DUTY * out_volt / VDD)+1;
	/* Set OCR0 with duty cycle value */
	OCR2 = (uint8)(duty_cycle);
}


