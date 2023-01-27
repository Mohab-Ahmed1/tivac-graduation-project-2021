/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 5 Jan 2021
Version     : V01
Description : Code to calculate the Distance.

 *****************************************************************************************************************/

#include "Data_Type.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "timer_interface.h"
#include "Ultrasonic_interface.h"
#include "GPIO_private.h"
#include "LCD_interface.h"

/*************************************************************************************
 *
 *                           function Prototypes
 *
 ************************************************************************************/

int main(void)
{
    Port_Init(PORTA);                                  /*initialize Port A for Trigger pin and the control pins in LCD*/
    Set_PORT_direction(PORTA,OUTPUT_PORT);             /*make portA as output port for trigger and LCD */
    Port_Init(PORTB);                                  /*initialize port B for timer 0 and ECHO pin*/
    Set_Pin_direction(PORTB,ECHO,INPUT_PIN);           /*make the ECHO pin as input pin */
    Set_Pin_alternative(PORTB,ECHO,TIMER0_ALTERNATE_FUNCTION);  /*activate alternative function for timer0*/
    Port_Init(PORTF);                                  /*initialize port C for the data pins in the LCD*/
    Set_Pin_direction(PORTF,PIN0,OUTPUT_PIN);           /*make the ECHO pin as input pin */
    Set_Pin_direction(PORTF,PIN1,OUTPUT_PIN);           /*make the ECHO pin as input pin */
    Set_Pin_direction(PORTF,PIN2,OUTPUT_PIN);           /*make the ECHO pin as input pin */
    Set_Pin_direction(PORTF,PIN3,OUTPUT_PIN);           /*make the ECHO pin as input pin */

    LCD_init();

    u32 distance;                                      /*variable to hold the measured distance from the UltraSonic sensor*/

    while(1)
    {
        Timer0_Init();                              /*initialize timer0 in capture mode and let timer start counting */
        distance = Measure_Distance();              /* measure the distance between sensor and object */
        LCD_displayStringRowColumn(0,0,"the distance = ");
        LCD_intgerToString(distance);               /*Display the distance*/
        LCD_displayString("cm");
        delay_Microsecond(1000000);                 /*make a delay until the second measurement */
        LCD_clearScreen();
    }
}
