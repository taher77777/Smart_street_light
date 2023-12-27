/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER0				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0              *((volatile u8*)0x53)
#define TCCR0_WGW00         6						//Bit Waveform Generation Mode
#define TCCR0_WGW01         3						//Bit Waveform Generation Mode
#define TCCR0_CS02          2						//Bit Clock Select
#define TCCR0_CS01          1						//Bit Clock Select
#define TCCR0_CS00          0						//Bit Clock Select
#define TCCR0_COM00			4						//Bit comper match outbut
#define TCCR0_COM01			5						//Bit comper match outbut

//normal mode
#define TCNT0             *((volatile u8*)0x52)     //register value normal mode
#define TIMSK             *((volatile u8*)0x59)     //Timer/Counter Interrupt MaskRegister
#define TIMSK_TOIE0       0							//interrupt enable overflow mode

//ctc mode
#define OCR0                *((volatile u8*)0x5C) 	//Output Compare Register ctc
#define TIMSK_OCIE0         1						//interrupt enable ctc mode
#define TIFR                *((volatile u8*)0x58)

#endif
