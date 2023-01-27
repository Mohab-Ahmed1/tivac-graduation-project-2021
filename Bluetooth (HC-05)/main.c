#include "C:\Keil\EE319Kware\inc\tm4c123gh6pm.h"
#include "TM4C123.h"
#include <stdint.h>
#include <stdlib.h>

#define GPIO_LOCK_KEY    0x4C4F434B  // Unlocks the GPIO_CR register
#define Forward 0x14
#define Backward 0x0A
#define Right 0x0C
#define Left 0x12

void SystemInit(){};  //System Initialization function (inside the tm4c123gh6pm.h)

void Delay(unsigned long counter); // used to add delay
void HC05_init(void); // Initialize UART5 module for HC-05  .. pins PE4, PE5
char Bluetooth_Read(void); //Read data from Rx5 pin of TM4C123
void Bluetooth_Write(unsigned char data); // Transmit a character to HC-05 over Tx5 pin 
void Bluetooth_Write_String(char *str); // Transmit a string to HC-05 over Tx5 pin 

void init(void)   //my initialization function 
{
	uint32_t delay;  //dummy variable to waste time
	SYSCTL_RCGCGPIO_R |= 0x00000020;  //system clock control fpr portF
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   //lock register
	GPIO_PORTF_CR_R = 0x1F;           //commit register
	GPIO_PORTF_AFSEL_R = 0x00;        //Alternative function select register
	GPIO_PORTF_PCTL_R = 0x00000000;   //port control (alternative function select)
  GPIO_PORTF_DIR_R = 0x1E;          // 5) PF0 in, PF4-1 out
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_PUR_R = 0x01;          // enable pull-up on PF0 only
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital I/O on PF4-0
}	



int main(void)
{ 
  HC05_init();  // call HC05_init() to initialze UART5 of TM4C123GH6PM
	init();       //call the initialization function that you just wrote above
	
	GPIO_PORTF_DATA_R = 0;  //starting with stop all 

	while(1)
	{
		char c = Bluetooth_Read();  //read the received character from bluetooth 
		
		if(c == 'F') //Forward 
		{
				GPIO_PORTF_DATA_R = Forward;
			 // send return message to check .. (not yet implemented)
		}	
		else if(c == 'B') //Backward
		{
				GPIO_PORTF_DATA_R = Backward;
		}				
		else if(c == 'R') //Right
		{
				GPIO_PORTF_DATA_R = Right;
		}				
				else if(c == 'L') //Left
		{
				GPIO_PORTF_DATA_R = Left;
		}		
		else
		{
				GPIO_PORTF_DATA_R = 0;  //all stop
		}	
		
	}
}

	







void HC05_init(void)
{
	SYSCTL->RCGCUART |= 0x20;    /* enable clock to UART5 */
    SYSCTL->RCGCGPIO |= 0x10;  /* enable clock to PORTE for PE4/Rx and RE5/Tx */
    Delay(1);
    /* UART0 initialization */
    UART5->CTL = 0;         /* UART5 module disbable */
    UART5->IBRD = 104;      /* for 9600 baud rate, integer = 104 */
    UART5->FBRD = 11;       /* for 9600 baud rate, fractional = 11*/
    UART5->CC = 0;          /* select system clock*/
    UART5->LCRH = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART5->CTL = 0x301;     /* Enable UART5 module, Rx and Tx */

    /* UART5 TX5 = PE4 and RX5 = PE5 .. Configure them digital and enable alternate function */
    GPIOE->DEN = 0x30;      /* set PE4 and PE5 as digital */
    GPIOE->AFSEL = 0x30;    /* Use PE4,PE5 alternate function */
    GPIOE->AMSEL = 0;       /* Turn off analg function*/
    GPIOE->PCTL = 0x00110000;     /* configure PE4 and PE5 for UART */
}


char Bluetooth_Read(void)  
{
    char data;
	  while((UART5->FR & (1<<4)) != 0){}; /* wait until Rx buffer is not full */
    data = UART5->DR ;  	/* before giving it another byte */
    return (unsigned char) data; 
}


void Bluetooth_Write(unsigned char data)   // .. not used yet 
{
    while((UART5->FR & (1<<5)) != 0);  /* wait until Tx buffer not full */
    UART5->DR = data;                  /* before giving it another byte */
}


void Bluetooth_Write_String(char *str)   //as a response for verivication .. not used yet 
{
  while(*str)
	{
		Bluetooth_Write(*(str++));
	}
}


void Delay(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter; i++);
}