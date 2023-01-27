
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
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

//! RPM = count/Ts/20(20 stripes)*60(s/min)
//! speed v (mm/s) = pi*d(unit: mm)*RPM/60
//! so v (mm/s) = pi*d*count*1000/Ts/20

int count = 0;
int time=0;
int v; // the speed; unit: mm/s; = pi*d*count/Ts(20ms)/20*1000
float pi = 3.14; // 3.14
int d = 65; // unit: mm
int T = 1000; // unit: ms; corresponds to 1/s
int pulsesperturn = 20;
uint32_t period = 16000000;
int Ts = 1000; // unit: ms
volatile uint32_t ui32Loop;

void Timer0IntHandler(void) //timer interupt handler
{

time=1;
// Clear the timer interrupt.

TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

}
void PortFIntHandler(void)  //gpio innterupt handler
{
	count++;

     GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_3);// clear interrupt
}


int main(void)
{


//Set the clock to 16Mhz
SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

//*****************************************************************************
// GPIO: pf3 - rising edge; pf1 - display for timer
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);// Enable the GPIO port that is used for the on-board LED.
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }
GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_3);//pin pf3 input
GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_RISING_EDGE); //pinf3 input rising edge
GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);//pin f2 output
GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_3);//Enable the pin interrupts
GPIOIntRegister(GPIO_PORTF_BASE, PortFIntHandler); //hand innterupt for portf

//Timer0
SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);// enable timer 0
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0))// Wait for the Timer0 module to be ready.
{
}
TimerConfigure(TIMER0_BASE,  TIMER_CFG_PERIODIC);
TimerLoadSet(TIMER0_BASE, TIMER_A, period-1);
// Setup the interrupts for the timer timeouts.
TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

// Enable the timers.
TimerEnable(TIMER0_BASE, TIMER_A);

TimerIntRegister(TIMER0_BASE,TIMER_A,Timer0IntHandler);


while(1){
	if (time==1)
	{
	GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_3);

	v = (int )pi*d*count*T/pulsesperturn/Ts;

	count = 0;

	time = 0;

	GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_3);

	}
	}

}




