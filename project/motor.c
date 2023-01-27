
#include "motor.h"

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
char v_string [10];
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

void Timer2IntHandler(void) //timer interupt handler
{
time=1;
// Clear the timer interrupt.

TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
}

void PortFIntHandler(void)  //gpio innterupt handler
{
	count++;
     GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_4);// clear interrupt
}

//#############################################################################################################################################################//

void move_car(void)
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
//speed sensor initalization
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);// Enable the GPIO port that is used for the on-board LED.
     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
         {
         }
     GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);//pin pf4 input
     GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_RISING_EDGE); //pinf4 input rising edge
     GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);//Enable the pin interrupts
     GPIOIntRegister(GPIO_PORTF_BASE, PortFIntHandler);
     //Timer2
     SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);// enable timer 2
     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER2))// Wait for the Timer2 module to be ready.
     {
     }
     TimerConfigure(TIMER2_BASE,  TIMER_CFG_PERIODIC);
     TimerLoadSet(TIMER2_BASE, TIMER_A, period-1);
     // Setup the interrupts for the timer timeouts.
     TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
     // Enable the timers.
     TimerEnable(TIMER2_BASE, TIMER_A);
     TimerIntRegister(TIMER2_BASE,TIMER_A,Timer2IntHandler);
     //#############################################################################################################################################################




//while (1){

while(!UARTCharsAvail(UART3_BASE));
data=UARTCharGetNonBlocking(UART3_BASE);
if (data!=olddata){
	 pwmNow=0;
	 olddata=data;
 }
if (data=='F'){
	forword ();

}
else if (data=='B'){
	backword();
}
else if (data=='L'){
	Turnleft ();
}
else if (data=='R'){
	TurnRight();
}
else {
	stop();
}


if (time==1)
{
GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);

v = (int )pi*d*count*T/pulsesperturn/Ts;
sprintf(v_string , "%d", v);

count = 0;

time = 0;

GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);

}


//}
}



