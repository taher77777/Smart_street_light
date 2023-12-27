/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit(void);
u8 TIMER0_u8SetCallBack(void (*copy_pvCallBackFunc)(void));
void TIMER0_voidSetPreLoadValue (u32 TIMER0_u32PreValue);
void TIMER0_voidSetOCR0Value(u32 TIMER0_u32OCR0Value);
void TIMER0_voidMS_Delay(u32 Timer0_u32Count);
#endif
