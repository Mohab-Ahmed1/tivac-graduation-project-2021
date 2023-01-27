/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 5 Jan 2021
Version     : V01
Description : Code to calculate the Distance.

 *****************************************************************************************************************/
#define   UART5       0x40011000
#define   UARTICR          0x044                   // UART Interrupt Clear
typedef unsigned long int u32;

#define  UART5_UARTICR        (*((volatile u32 *)(UART5  +  UARTICR      )))


#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "driverlib/pwm.h"

#include "Data_Type.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "timer_interface.h"
#include "Ultrasonic_interface.h"
#include "GPIO_private.h"
#include "LCD_interface.h"
//#include "UART_interface.h
int inval;
int oldval;
int inval3;
 volatile uint32_t ui32Loop;
void raspeyRecieve(void)
{
oldval=UARTIntStatus(UART5_BASE,true);
    UARTIntClear(UART5_BASE,  UART_INT_RT);
    inval= UARTIntStatus(UART5_BASE,true);
	 GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
	        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
	        {
	        }
	        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);
	        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
	        	        {
	        	        }
	        volatile int i;

}




int main(void)

{SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);//Set the clock
	volatile uint32_t ui32Loop;

	    //
	    // Enable the GPIO port that is used for the on-board LED.
	    //
	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	    //
	    // Check if the peripheral access is enabled.
	    //
	    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
	    {
	    }

	    //
	    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
	    // enable the GPIO pin for digital function.
	    //
	    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
	    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

	    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	        GPIOPinConfigure(GPIO_PE4_U5RX);
	        GPIOPinConfigure(GPIO_PE5_U5TX);
	        GPIOPinTypeUART(GPIO_PORTE_BASE,GPIO_PIN_4|GPIO_PIN_5);
	        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
	        UARTConfigSetExpClk(UART5_BASE,SysCtlClockGet(),9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE));

	//u32 distance;                                      /*variable to hold the measured distance from the UltraSonic sensor*/
IntMasterEnable();
	        UARTIntEnable(UART5_BASE, UART_INT_RT);
	        UARTEnable(UART5_BASE);

	UARTIntRegister(UART5_BASE,raspeyRecieve );

	while(1)

	{
		inval3= UARTIntStatus(UART5_BASE,true);
		while(1);
	}
}

//#include "Data_Type.h"
//#include "BIT_MATH.h"
//#include "GPIO_interface.h"
//#include "timer_interface.h"
//#include "Ultrasonic_interface.h"
//#include "GPIO_private.h"
//#include "LCD_interface.h"
//#include "UART_interface.h"
//#include"motor.h"
//
////#define Thrshold xxxx
//
///*************************************************************************************
// *
// *                           function Prototypes
// *
// ************************************************************************************/
//
//int main(void)
//{
//	u8 Ras_Rec ;
//    Port_Init(PORTA);                                  /*initialize Port A for Trigger pin and the control pins in LCD*/
//    Set_PORT_direction(PORTA,OUTPUT_PORT);             /*make portA as output port for trigger and LCD */
//    Port_Init(PORTB);                                  /*initialize port B for timer 0 and ECHO pin*/
//    Set_Pin_direction(PORTB,ECHO,INPUT_PIN);           /*make the ECHO pin as input pin */
//    Set_Pin_alternative(PORTB,ECHO,TIMER0_ALTERNATE_FUNCTION);  /*activate alternative function for timer0*/
//    Port_Init(PORTF);                                  /*initialize port C for the data pins in the LCD*/
//    Set_Pin_direction(PORTF,PIN0,OUTPUT_PIN);           /*make the ECHO pin as input pin */
//    Set_Pin_direction(PORTF,PIN1,OUTPUT_PIN);           /*make the ECHO pin as input pin */
//    Set_Pin_direction(PORTF,PIN2,OUTPUT_PIN);           /*make the ECHO pin as input pin */
//    Set_Pin_direction(PORTF,PIN3,OUTPUT_PIN);           /*make the ECHO pin as input pin */
//    Port_Init(PORTE);                                  /*initialize port C for the data pins in the LCD*/
//    UART_Init(UART_5);
//    Set_Pin_direction(PORTE,PIN4,PIN5);           /*make the ECHO pin as input pin */
//
//    LCD_init();
//
//    //u32 distance;                                      /*variable to hold the measured distance from the UltraSonic sensor*/
//    UARTIntEnable(UART5_BASE, UART_INT_RX);
//    UARTIntRegister(UART5_BASE,raspeyRecieve );
//    UARTIntClear(ART5_BASE,  UART_INT_RX);
//
//
//    while(1)
//
//    {
//    	move_car();
//    	Ras_Rec = UART_ReadData(UART_5);
//        //+Timer0_Init();                              /*initialize timer0 in capture mode and let timer start counting */
//        //distance = Measure_Distance();              /* measure the distance between sensor and object */
//        LCD_displayStringRowColumn(0,0,"the data is = ");
//        LCD_displayCharacter(Ras_Rec);               /*Display the distance*/
//        //LCD_displayString("cm");
//        delay_Microsecond(1000000);                 /*make a delay until the second measurement */
//        LCD_clearScreen();
//
//        if (Ras_Rec == 'S')
//        {
//        	/*there where an bump dedected*/
//            Timer0_Init();                              /*initialize timer0 in capture mode and let timer start counting */
//            //distance = Measure_Distance();              /* measure the distance between sensor and object */
//            LCD_displayStringRowColumn(0,0,"the bump is at  = ");
//            //LCD_intgerToString(distance);
//            delay_Microsecond(1000000);                 /*make a delay until the second measurement */
//            LCD_clearScreen();
//           //Current_speed = decrease_speed();
//            stop ();
//           /*if(Current_speed<=Thrshold)
//           {
//        	   Emergency_break();
//           }*/
//        }
//    }
//}
//
