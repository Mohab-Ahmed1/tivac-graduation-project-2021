/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 8 Jan 2020
Version     : V01
 *****************************************************************************************************************/
#include "Data_Type.h"
#include "BIT_MATH.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "GPIO_interface.h"
#include "Ultrasonic_interface.h"

u32 Measure_Distance(void)
{
    Set_pin_value (PORTA , TRIGGER ,GPIO_LOW);    /*Set Trigger pin value to zero*/
    delay_Microsecond(12);                        /*Make a delay for 12 micro second*/
    Set_pin_value (PORTA , TRIGGER ,GPIO_HIGH);   /*Set Trigger pin value to one*/
    delay_Microsecond(12);                        /*Make a delay for 12 micro second*/
    Set_pin_value (PORTA , TRIGGER ,GPIO_LOW);    /*Set Trigger pin value to zero*/

    // Capture firstEgde i.e. rising edge
    timer0_GPTMICR =4;                           /*clear the flag*/
    while((timer0_GPTMRIS & 4)==0){};            /* wait till the flag will be 1 --> it means that the edge has come*/
    First_edge = timer0_GPTMTAR;                 /*store the time of the rising edge*/

    // Capture secondEdge i.e. falling edge
    timer0_GPTMICR =4 ;                         /*clear timer capture flag*/
    while((timer0_GPTMRIS & 4) ==0){};          /*wait till the flag will be 1 --> it means that the edge has come*/
    Second_edge = timer0_GPTMTAR;               /*store the time of the Falling edge*/

    /*calculate the Distance*/
    TIME = Second_edge - First_edge;
    Distance = (_16MHz_1clock )*(double) (VOICE_SPEED_CM/2) *(double)TIME;
    return Distance;
}
