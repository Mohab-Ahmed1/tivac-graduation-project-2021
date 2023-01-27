/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 7 Jan 2021
Version     : V01
 *****************************************************************************************************************/

/********************************************************************************************
 *
 *                                    Includes
 *
 ********************************************************************************************/
#include "Data_Type.h"
#include "BIT_MATH.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_config.h"

/********************************************************************************************
 *
 *                             functions Definitions
 *
 ******************************************************************************************/


void Timer0_Init(void)
{
    SCR_RCGCTIMER |= (1 << 0) ;             /*initialize the clock for the timer 0*/
    /*Enable Timer */
    timer0_GPTMCTL &= ~ ( 1<< 0);           /*disable the timer for configuration*/
    timer0_GPTMCFG = 0x04;                  /*configure timer 0 to work with 16 bit data mode*/
    timer0_GPTMTAMR = 0x17 ;                /*SET the timer to work with : capture + Edge time + count up*/
    timer0_GPTMCTL |= 0x0c ;                /*SET the timer on both edge mode*/
    timer0_GPTMCTL |= 1 ;                   /*Let the timer start counting*/
}

/*make a delay using TIMERA 1*/
void delay_Microsecond (u32 time)
{
    int i;                          /*variable for counting */
    SCR_RCGCTIMER  |= (1U<<1);      /*enable clock for timer 1*/
    for(i=0;i<5;i++){}              /* wait until clock be enabled*/
    i=0;
    timer1_GPTMCTL=0;              /*disable the timer for configuration*/
    timer1_GPTMCFG=0x04;           /*configure timer 0 to work with 16 bit data mode*/
    timer1_GPTMTAMR=0x02;          /*SET the timer to work in periodic timer mode*/
    timer1_GPTMTAILR= 16-1;        /*configure timer to work with 16 HZ frequency*/
    timer1_GPTMICR =0x1;           /*Set the timer to be A Time-Out Raw Interrupt*/
    timer1_GPTMCTL |=0x01;         /*Let the timer start counting*/

    for(i=0;i<time;i++)
    {
        while((timer1_GPTMRIS & 0x1)==0);        /*wait until TimerA has time out*/
        timer1_GPTMICR= 0x1;                     /*Clear interrupt flag*/
    }
}
