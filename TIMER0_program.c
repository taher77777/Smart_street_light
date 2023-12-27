#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "TIMER0_register.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*choose TIMER0 MODE*/ 
	switch (TIMER0_MODE)
	{
		/*choose normal mode*/
		case 1: CLR_BIT(TCCR0,TCCR0_WGW00); CLR_BIT(TCCR0,TCCR0_WGW01);

		/*output normal interrupt enable*/
				SET_BIT(TIMSK,TIMSK_TOIE0);break;

		/*choose pwm phase correct mode*/
		case 2: SET_BIT(TCCR0,TCCR0_WGW00); CLR_BIT(TCCR0,TCCR0_WGW01);
				/*set OC0 output*/
		switch (TIMER0_PWM_F_MODE_OC0)
		{
					/*oc0 disconected*/
					case 1 :CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
					/*Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.*/
					case 2 :CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
					/*Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting*/
					case 3 :SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
					/*oc0 disconected*/
					default:CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
		}
		
		break;
		
		
		/*choose ctc mode*/
		case 3: CLR_BIT(TCCR0,TCCR0_WGW00); SET_BIT(TCCR0,TCCR0_WGW01);
		/*output compare match interrupt enable*/
				SET_BIT(TIMSK,TIMSK_OCIE0);	

		/*set oc0 value */
		        switch(TIMER0_CTC_OC0)
				{
					/*oc0 disconected*/
					case 1 :CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
					/*oc0 toggle*/
					case 2 :SET_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
					/*oc0 clear*/
					case 3 :CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
					/*oc0 set*/
					case 4 :SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
					/*oc0 disconected*/
					default:CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
				} 
				break;
				
				
		/*choose pwm fast mode*/
		case 4: SET_BIT(TCCR0,TCCR0_WGW00); SET_BIT(TCCR0,TCCR0_WGW01);
		
		/*set OC0 output*/
		switch (TIMER0_PWM_F_MODE_OC0)
		{
					/*oc0 disconected*/
					case 1 :CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
					/*Clear OC0 on compare match, set OC0 at TOP*/
					case 2 :CLR_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
					/*Set OC0 on compare match, clear OC0 at TOP*/
					case 3 :SET_BIT(TCCR0,TCCR0_COM00);SET_BIT(TCCR0,TCCR0_COM01);break;
					/*oc0 disconected*/
					default:CLR_BIT(TCCR0,TCCR0_COM00);CLR_BIT(TCCR0,TCCR0_COM01);break;
		}
		
		break;
		/*choose normal mode*/
		default:CLR_BIT(TCCR0,TCCR0_WGW00); CLR_BIT(TCCR0,TCCR0_WGW01);break;
	}
	
	/*prescaler*/
	switch (TIMER0_CLK_PRE)
	{
		/*no source*/
		case 0:	CLR_BIT(TCCR0,TCCR0_CS00); CLR_BIT(TCCR0,TCCR0_CS01); CLR_BIT(TCCR0,TCCR0_CS02);break;
		/*df1*/
		case 1: SET_BIT(TCCR0,TCCR0_CS00); CLR_BIT(TCCR0,TCCR0_CS01); CLR_BIT(TCCR0,TCCR0_CS02);break;
		/*df8*/
		case 2: CLR_BIT(TCCR0,TCCR0_CS00); SET_BIT(TCCR0,TCCR0_CS01); CLR_BIT(TCCR0,TCCR0_CS02);break;
		/*df64*/
		case 3: SET_BIT(TCCR0,TCCR0_CS00); SET_BIT(TCCR0,TCCR0_CS01); CLR_BIT(TCCR0,TCCR0_CS02);break;
		/*df256*/
		case 4: CLR_BIT(TCCR0,TCCR0_CS00); CLR_BIT(TCCR0,TCCR0_CS01); SET_BIT(TCCR0,TCCR0_CS02);break;
		/*df1024*/
		case 5: SET_BIT(TCCR0,TCCR0_CS00); CLR_BIT(TCCR0,TCCR0_CS01); SET_BIT(TCCR0,TCCR0_CS02);break;
		/*External clock source on T0 pin. Clock on falling edge*/
		case 6: CLR_BIT(TCCR0,TCCR0_CS00); SET_BIT(TCCR0,TCCR0_CS01); SET_BIT(TCCR0,TCCR0_CS02);break;
		/*External clock source on T0 pin. Clock on raising edge*/
		case 7: SET_BIT(TCCR0,TCCR0_CS00); SET_BIT(TCCR0,TCCR0_CS01); SET_BIT(TCCR0,TCCR0_CS02);break;
		/*no source*/
		default:CLR_BIT(TCCR0,TCCR0_CS00); CLR_BIT(TCCR0,TCCR0_CS01); CLR_BIT(TCCR0,TCCR0_CS02);break;
	}

}

u8 TIMER0_u8SetCallback(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else 
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	
	return Local_u8ErrorStatus;
}

		/*set preload value*/
void TIMER0_voidSetPreLoadValue (u32 TIMER0_u32PreValue)
{
	TCNT0=TIMER0_u32PreValue;
}

		/*SET OCR0 Value*/
void TIMER0_voidSetOCR0Value(u32 TIMER0_u32OCR0Value)
{
		/*compare match value ocr0*/
	OCR0=TIMER0_u32OCR0Value;
}

/*delay with clk/8 with normal mode*/
void TIMER0_voidMS_Delay(u32 Timer0_u32Count)
{
	u8 mile_count=0;
	u32 reg_count=0;
	//for reguired mile second
	for(reg_count=0;reg_count<Timer0_u32Count;reg_count++)
	{
		//for one mile second
		for(mile_count=0;mile_count<4;mile_count++)
		{
		//set preload
			TIMER0_voidSetPreLoadValue(5);
			//start count
			TIMER0_voidInit();
			while ((TIFR&0x1)==0); //wait for TOVO to roll over
			SET_BIT(TIFR,0);//clear TOVO
			//stop_timer
			TCCR0&=0b11111000;
	}
}

}
		
/*ISR OVERflow MODE*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void) 
{
	if (TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}

}
/*ISR CTC MODE*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void) 
{
	if (TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}

}
