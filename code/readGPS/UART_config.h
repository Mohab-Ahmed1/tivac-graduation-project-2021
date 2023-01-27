/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 22 April 2021
Version     : V01
 *****************************************************************************************************************/

#ifndef  UART_CONFIG_H
#define  UART_CONFIG_H


/*Definitions for the Clock type*/
#define SYSTEM_CLOCK      0x0
#define PIOSC_CLOCK       0x5
#define UART_CLOCK_TYPE   SYSTEM_CLOCK

/*Definitions for the clock speed*/
#define NORMAL_SPEED_CLOCK  0x0
#define HIGH_SPEED_CLOCK    0x1
#define CLOCK_SPEED         NORMAL_SPEED_CLOCK

/*configure the Data length*/
#define FIVE_BIT_DATA       0x1
#define SIX_BIT_DATA        0x1
#define SEVEN_BIT_DATA      0x2
#define EIGHT_BIT_DATA      0x3
#define DATA_LENGHT         EIGHT_BIT_DATA

/*configure the Baud rate*/
#define BAUD_RATE   9600

#define MCU_CLOCK 16000000.0         /*the clock of your microprocessor*/
#define CLK_DIV      16                  /*it take the values 16 or 8*/



#endif
