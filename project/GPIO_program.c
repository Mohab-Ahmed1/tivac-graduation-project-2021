/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 5 Jan 2021
Version     : V01
Description : file to initialize ports and pins.

 *****************************************************************************************************************/

/********************************************************************************************
 *
 *                                    Includes
 *
 ********************************************************************************************/
#include "Data_Type.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void Port_Init (u8 port_number)
{
    SCR_RCGCGPIO |= (1<<port_number);                /*enable clock for the port*/
    switch(port_number)
    {
    case PORTA :
        LOCKPORT_A  |= __Unlock_Register;            /*Unlock GPIO A to be able to write on it */
        CRPORT_A    = 0x0FF ;                        /* Commit register */
        AFSELPORT_A = 0x00 ;                         /*Disable alternative function*/
        DENPORT_A   = 0xFF ;                         /*GPIO Digital Enable*/
        break;
    case PORTB :
        LOCKPORT_B  |= __Unlock_Register;            /*Unlock GPIO A to be able to write on it */
        CRPORT_B    = 0x0FF ;                       /* Commit register */
        AFSELPORT_B = 0x00 ;                         /*Disable alternative function*/
        DENPORT_B   = 0xFF ;                        /*GPIO Digital Enable*/
        break;
    case PORTC :
        //        LOCKPORT_C |= __Unlock_Register;            /*Unlock GPIO A to be able to write on it */
        //        CRPORT_C    = 0x0FF ;                       /* Commit register */
        AFSELPORT_C &= ~(1<<4) & ~(1<<5) & ~(1<<6) & ~(1<<7);   /*Disable alternative function for only non reserved pins*/
        DENPORT_C  |= (1<<4) | (1<<5) | (1<<6) |(1<<7);         /*GPIO Digital Enable*/
        break;
    case PORTD :
        //LOCKPORT_D |= __Unlock_Register;            /*Unlock GPIO D to be able to write on it */
        //CRPORT_D   = 0x0FF ;                        /* Commit register */
        AFSELPORT_D &= ~(1<<6) & ~(1<<7) ;                        /*Disable alternative function*/
        DENPORT_D   |= (1<<6) | (1<<7) ;                        /*GPIO Digital Enable*/
        break;
    case PORTE :
        LOCKPORT_E |= __Unlock_Register;            /*Unlock GPIO A to be able to write on it */
        CRPORT_E    = 0x0FF ;                       /* Commit register */
        AFSELPORT_E = 0x00 ;                        /*Disable alternative function*/
        DENPORT_E   = 0xFF ;                        /*GPIO Digital Enable*/
        break;
    case PORTF :
        LOCKPORT_F |= __Unlock_Register;            /*Unlock GPIO A to be able to write on it */
        CRPORT_F    = 0x0FF ;                       /* Commit register */
        AFSELPORT_F = 0x00 ;                        /*Disable alternative function*/
        DENPORT_F   = 0xFF ;                        /*GPIO Digital Enable*/
        break;
    }
}


void Set_PORT_direction(u8 port_number,u8 port_direction)
{
    switch (port_number)
    {
    case PORTA :  DIRPORT_A = port_direction; break;
    case PORTB :  DIRPORT_B = port_direction; break;
    case PORTC :
        if(port_direction == OUTPUT_PORT)
        {
            DIRPORT_C= (1<<4) | (1<<5) | (1<<6) |(1<<7);    /*access only the non reserved pins*/
        }
        else
        {
            DIRPORT_C= (1<<4) | (1<<5) | (1<<6) |(1<<7);    /*access only the non reserved pins*/
        }
        break;
    case PORTD :  DIRPORT_D = port_direction; break;
    case PORTE :  DIRPORT_E = port_direction; break;
    case PORTF :  DIRPORT_F = port_direction; break;
    }
}

void Set_Pin_direction(u8 port_number,u8 pin_number,u8 pin_direction)
{
    switch (port_number)
    {
    case PORTA :
        if(pin_direction == INPUT_PIN)
            DIRPORT_A &= ~(1<<pin_number);
        else
            DIRPORT_A |= (1<<pin_number);
        break;
    case PORTB :
        if(pin_direction == INPUT_PIN)
            DIRPORT_B &= ~(1<<pin_number);
        else
            DIRPORT_B |= (1<<pin_number);
        break;
    case PORTC :
        if(pin_direction == INPUT_PIN)
            DIRPORT_C &= ~(1<<pin_number);
        else
            DIRPORT_C |= (1<<pin_number);
        break;
    case PORTD :
        if(pin_direction == INPUT_PIN)
            DIRPORT_D &= ~(1<<pin_number);
        else
            DIRPORT_D |= (1<<pin_number);
        break;
    case PORTE :
        if(pin_direction == INPUT_PIN)
            DIRPORT_E &= ~(1<<pin_number);
        else
            DIRPORT_E |= (1<<pin_number);
        break;
    case PORTF :
        if(pin_direction == INPUT_PIN)
            DIRPORT_F &= ~(1<<pin_number);
        else
            DIRPORT_F |= (1<<pin_number);
        break;
    }
}
void Set_pin_value (u8 port_number,u8 pin_number,u8 pin_value)
{
    switch (port_number)
    {
    case PORTA :
        if(pin_value == GPIO_LOW)
            DATAPORT_A &= ~(1<<pin_number);
        else
            DATAPORT_A |= (1<<pin_number);
        break;
    case PORTB :
        if(pin_value == GPIO_LOW)
            DATAPORT_B &= ~(1<<pin_number);
        else
            DATAPORT_B |= (1<<pin_number);
        break;
    case PORTC :
        if(pin_value == GPIO_LOW)
            DATAPORT_C &= ~(1<<pin_number);
        else
            DATAPORT_C |= (1<<pin_number);
        break;
    case PORTD :
        if(pin_value == GPIO_LOW)
            DATAPORT_D &= ~(1<<pin_number);
        else
            DATAPORT_D |= (1<<pin_number);
        break;
    case PORTE :
        if(pin_value == GPIO_LOW)
            DATAPORT_E &= ~(1<<pin_number);
        else
            DATAPORT_E |= (1<<pin_number);
        break;
    case PORTF :
        if(pin_value == GPIO_LOW)
            DATAPORT_F &= ~(1<<pin_number);
        else
            DATAPORT_F |= (1<<pin_number);
        break;
    }
}

/*u8 Get_pin_value (u8 port_number,u8 pin_number)
{

}*/
void Set_Pin_alternative(u8 port_number,u8 pin_number,u8 Alternative_function)
{
    switch(port_number)
    {
    case PORTA :
        AFSELPORT_A |=(1<<0) | (1<<1);      /*Enable the Alternative function for both pin 0 and pin 1 in port A for the UART*/
        PCTLPORT_A   =0x11;                 /*write 1 in PA0 for Tx and PA1 for Rx ..>from data sheet p.1351 */
        break;
    case PORTB :
        AFSELPORT_B |= (1<<pin_number) ;    /*configure PB6 to work with alternative function for timer 0*/
        PCTLPORT_B &= ~0x0F000000;          /*choose TCNT0 (enable timer in capture mode..>from data sheet P.1351 )*/
        PCTLPORT_B = 0x07000000;            /*put the value 7 for T0TCB0*/
        break;
    case PORTD :
        AFSELPORT_D |= (1<<PIN6) | (1<<PIN7) ;    /*Configure PD6 & PD7 to work with alternative function for UART*/
        PCTLPORT_D |= 0x01100000;      /*write 1 in PA0 for Tx and PA1 for Rx ..>from data sheet p.1351 */
        break;
    case PORTE :
        AFSELPORT_E =(1<<4) | (1<<5); /*Enable the Alternative function for both Rx pin 4 and Tx pin 5 in port E for the UART*/
        PCTLPORT_E = 0x00110000;      /*write 1 in PA0 for Tx and PA1 for Rx ..>from data sheet p.1351 */
        break;
    }
    /*Enable Timer */
}
