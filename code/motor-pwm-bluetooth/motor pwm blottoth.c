
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


 unsigned long pwmNow = 0;
 unsigned char data;
 unsigned char olddata='0';
//###########################################################################################################################
void forword  (void){
	while(pwmNow<400){
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0, GPIO_PIN_0); //left side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1, 0x0);
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_2, GPIO_PIN_2); //right side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_3, 0x0);
	SysCtlDelay( (SysCtlClockGet()/(3*1000))*20 ) ;
	pwmNow += 10;
     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,pwmNow);//PIN b4
     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,pwmNow);//PIN b5
}}
void backword  (void){
	while(pwmNow<400){
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0, 0x0); //left side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1, GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_2, 0x0); //right side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_3, GPIO_PIN_3);
	SysCtlDelay( (SysCtlClockGet()/(3*1000))*20 ) ;
		pwmNow += 10;
	     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,pwmNow);//PIN b4
	     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,pwmNow);//PIN b5
	}
}
void TurnRight  (void){
	while(pwmNow<400){
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0, GPIO_PIN_0);// left side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1, 0x0);
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_2, 0x0);//right side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_3, GPIO_PIN_3);
	SysCtlDelay( (SysCtlClockGet()/(3*1000))*20 ) ;
		pwmNow += 10;
	     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,pwmNow);//PIN b4
	     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,pwmNow);//PIN b5
	}
}
void Turnleft  (void){
	while(pwmNow<400){
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0, 0x0);//left side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1, GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_2, GPIO_PIN_2);//right side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_3, 0x0);
	SysCtlDelay( (SysCtlClockGet()/(3*1000))*20 ) ;
   pwmNow += 10;
   PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,pwmNow);//PIN b4
  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,pwmNow);//PIN b5
	}
}

void stop  (void){
	while(pwmNow<400){
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0, 0x0); //left side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_1, 0x0);
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_2, 0x0); //right side
	GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_3, 0x0);
	SysCtlDelay( (SysCtlClockGet()/(3*1000))*20 ) ;
	pwmNow += 10;
     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,pwmNow);//PIN b4
     PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,pwmNow);//PIN b5
}}





//#############################################################################################################################################################

int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);//Set the clock

//######################################################################################
	// Enable the GPIO port that is used
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB))
    {
    }
GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0);//pin B0 output
GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_1);//pin B1 output
GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2);//pin B2 output
GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_3);//pin B3 output

//#############################################################################################################################################################
//HC06 BLUETOOTH initalization
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    GPIOPinConfigure(GPIO_PC6_U3RX);
    GPIOPinConfigure(GPIO_PC7_U3TX);
    GPIOPinTypeUART(GPIO_PORTC_BASE,GPIO_PIN_6|GPIO_PIN_7);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
    UARTConfigSetExpClk(UART3_BASE,SysCtlClockGet(),9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE));
    UARTEnable(UART3_BASE);

  //#############################################################################################################################################################
//pwm initalization

  SysCtlPWMClockSet(SYSCTL_PWMDIV_1);//Configure PWM Clock to match system
SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);//The Tiva Launchpad has two modules (0 and 1). Module 0 covers the port b  pins
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0))
{
}
//Configure pB4,pB5 Pins as PWM
GPIOPinConfigure(GPIO_PB4_M0PWM2);
GPIOPinConfigure(GPIO_PB5_M0PWM3);
GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5 );

//Configure PWM Options Module 0 Generator 1
PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

//Set the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 400);

//Set PWM duty-50% (Period /2)
  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,200);//PIN b4
  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,200);//PIN b5
  // Enable the PWM generator
     PWMGenEnable(PWM0_BASE, PWM_GEN_1);

  // Turn on the Output pins
     PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT | PWM_OUT_3_BIT , true);
     //#############################################################################################################################################################




while (1){

while(!UARTCharsAvail(UART3_BASE)){
data=UARTCharGetNonBlocking(UART3_BASE);
if (data!=olddata){
	 pwmNow=0;
	 olddata=data;
 }
if (data=='w'){
	forword ();

}
else if (data=='b'){
	backword();
}
else if (data=='l'){
	Turnleft ();
}
else if (data=='R'){
	TurnRight();
}
else {
	stop();
}

}
UARTDisable(UART3_BASE);

}



