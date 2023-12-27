#include"STD_TYPE.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"TIMER0_interface.h"
#include"LED_interface.h"



void main(void)
{
	PORT_voidInit();
	TIMER0_voidInit();
	u8 ir_1=0;
	u8 ir_2=0;
	u8 ir_3=0;
	while(1)
	{
		DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN0,&ir_1);
		DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN2,&ir_2);
		DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN4,&ir_3);
		if(ir_1!=1)
		{
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN0);
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN1);
		}
		else
		{
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN0);
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN1);
		}
		if(ir_2!=1)
		{
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN2);
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN3);
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN4);
		}
		else
		{
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN2);
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN3);
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN4);
		}
		if(ir_3!=1)
		{
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN5);
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN6);
			LED_voidTurnOn(DIO_u8PORTC,DIO_u8PIN7);
		}
		else
		{
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN5);
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN6);
			LED_voidTurnOff(DIO_u8PORTC,DIO_u8PIN7);
		}
		TIMER0_voidMS_Delay(3);
	}
}
