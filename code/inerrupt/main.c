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
#include "UART_private.h"
#include "GPIO_private.h"
#include "timer_interface.h"


void Delay(unsigned long counter);
char UART5_Receiver(void);
void UART5_Transmitter(unsigned char data);
void printstring(char *str);


void UART5_Handler( void )
{
    unsigned char i = 0;
    UART5_UARTICR &= ~(0x010); // Clear receive interrupt
    Set_pin_value(PORTF,PIN3,GPIO_LOW);
    for(i=0;i<10000;i++);
}


int main(void)
{
    /*GPS initializations*/
    Port_Init(PORTE);                                  /*Enable the clock for port A for UART0*/
    UART_Init(UART_5);                                 /*initialize UART0*/
    Set_Pin_alternative(PORTE,PIN4,PIN5);              /*configure Pin 0 (RX) and pin 1 (TX) to work with alternative function*/
    Port_Init(PORTF);
    /*make the LED pins are output pins*/
    //Set_Pin_direction(PORTF,PIN1,OUTPUT_PIN);
    //Set_Pin_direction(PORTF,PIN2,OUTPUT_PIN);
    Set_Pin_direction(PORTF,PIN3,OUTPUT_PIN);
    //Set_pin_value(PORTF,PIN1,GPIO_LOW);
    //Set_pin_value(PORTF,PIN2,GPIO_LOW);
    Set_pin_value(PORTF,PIN3,GPIO_LOW);
    delay_Microsecond(10);

    UART5_UARTICR &= ~(0x0780);; // Clear receive interrupt
    UART5_UARTIM  = 0x0010;

    while(1)
    {
        Set_pin_value(PORTF,PIN3,GPIO_HIGH);
    }
}
