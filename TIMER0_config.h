/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
//Waveform Generation Mode

#define NORMAL   			1
#define PWM_Phase_Correct	2
#define CTC					3
#define PWM_FAST_MODE		4
#define TIMER0_MODE         NORMAL

//clock select

	/*
		no_source :  0
		normal	  :  1
		clock/8   :  2
		clock/64  :  3
		clock/256 :  4
		clock/1024:  5
		E_S_T0_F_E:  6		External clock source on T0 pin. Clock on falling edge
		E_S_T0_R_E:  7		External clock source on T0 pin. Clock on raising edge
						*/
#define TIMER0_CLK_PRE      2

/*ctc outbut oc0*/

	/* 
		oc0 disconected  1
		oc0 toggle       2
		oc0 clear        3
		oc0 set          4
							*/

#define TIMER0_CTC_OC0   2

/*pwm FAST Mode*/

   /*
		oc0 disconected  								1
		Clear OC0 on compare match, set OC0 at TOP      2
		set OC0 on compare match, clear OC0 at TOP		3
															*/
#define TIMER0_PWM_F_MODE_OC0   2

/*Phase Correct PWM Mode*/

   /*
		oc0 disconected  																			1
		Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting     2
		Set OC0 on compare match when up-counting. Clear OC0 on comparematch when downcounting		3
															*/
#define TIMER0_PWM_PH_MODE_OC0   2				
											
 

#endif
