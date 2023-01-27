/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 31 / 5 / 2021
Version     : V01
Description : Code to take the data from UART5(GPS) and sent it to Putty terminal (UART0).

 *****************************************************************************************************************/
/******************************WORK*****************************/
#include "Data_Type.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "GPIO_private.h"
#include "timer_interface.h"

int main(void)
{
    /*BUTTY terminal initializations*/
    Port_Init(PORTA);                                  /*Enable the clock for port A for UART0*/
    UART_Init(UART_0);                                 /*initialize UART0*/
    Set_Pin_alternative(PORTA,PIN0,PIN1);              /*configure Pin 0 (RX) and pin 1 (TX) to work with alternative function*/

    /*GPS initializations*/
    Port_Init(PORTE);                                  /*Enable the clock for port A for UART0*/
    UART_Init(UART_5);                                 /*initialize UART0*/
    Set_Pin_alternative(PORTE,PIN4,PIN5);              /*configure Pin 0 (RX) and pin 1 (TX) to work with alternative function*/

    delay_Microsecond(10);

    while(1)
    {
        readGPS();
    }
}
