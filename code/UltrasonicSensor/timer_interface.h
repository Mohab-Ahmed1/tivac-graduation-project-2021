/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 7 Jan 2021
Version     : V01
 *****************************************************************************************************************/

#ifndef  TIMER_INTERFACE_H
#define  TIMER_INTERFACE_H


#define TIMER_MODE_32BIT  0x0      /*for 32 bit timer configuration*/
#define TIMER_MODE_16BIT  0x4      /*for 16 bit timer configuration*/

#define TRIGGER   7
#define ECHO      6

/********************************************************************************************
 *
 *                             functions prototype
 *
 *******************************************************************************************/
void Timer0_Init(void);
void delay_Microsecond (u32 time);


#endif
