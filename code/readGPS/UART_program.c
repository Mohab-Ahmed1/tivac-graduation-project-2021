/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 22 April 2021
Version     : V01
 *****************************************************************************************************************/

/********************************************************************************************
 *
 *                                    Includes
 *
 ********************************************************************************************/
#include "Data_Type.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
#include "GPIO_private.h"

/********************************************************************************************
 *
 *                                    Private Global Data
 *
 ********************************************************************************************/
#define ERROR  0x00
u16 BAUD_RATE_INTEGER = 0;                  //to hold the Integer value of the Baud rate
u8  BAUD_RATE_FRACTION = 0;                 //to hold the fractional value of the Baud rate
f32 TOTAL_BAUD_RATE = 0;                    //to hold both the fractional and integer parts of the Baud Rate

/********************************************************************************************
 *
 *                             functions Definitions
 *
 ******************************************************************************************/
/*function to initialize the UART module*/
void UART_Init(char UART_Number)
{
    u8 i;
    SCR_UART |= (1<<UART_Number) ;                                         /*Enable the Clock for the UART*/
    for(i=0; i< 1; i++);                                                   /*make a delay until the clock is set*/
    switch(UART_Number)
    {
    case UART_0:
        UART0_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART0_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART0_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART0_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART0_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART0_UARTCTL |= (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART0_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    case UART_1:
        UART1_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART1_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART1_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART1_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART1_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART1_UARTCTL |= (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART1_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    case UART_2:
        UART2_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART2_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART2_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART2_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART2_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART2_UARTCTL |= (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART2_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    case UART_3:
        UART3_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART3_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART3_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART3_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART3_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART3_UARTCTL |= (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART3_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    case UART_4:
        UART4_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART4_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART4_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART4_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART4_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART4_UARTCTL |= (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART4_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    case UART_5:
        UART5_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART5_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART5_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART5_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART5_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART5_UARTCTL  = (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART5_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    case UART_6:
        UART6_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART6_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART6_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART6_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART6_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART6_UARTCTL |= (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART6_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    case UART_7:
        UART7_UARTCTL  = 0;                                                /*01- disable the UART module*/
        UART7_UARTIBRD = (INTEGER_BAUD_RATE());                            /*02-Write the fractional portion of the baud rate*/
        UART7_UARTFBRD = (FRACTION_BAUD_RATE());                           /*03-Write the desired serial parameters to the UARTLCRH register*/
        UART7_UARTLCRH = 0x00000060;                                       /*04-configure : 8_bit mode & one Stop bit & no parity check*/
        UART7_UARTCC   = UART_CLOCK_TYPE;                                  /*05-Configure the UART Clock Source*/
        UART7_UARTCTL |= (CLOCK_SPEED<<5) ;                                /*06-configure the UART with the Speed mode*/
        UART7_UARTCTL |=  (1<<0) | (1<<8) | (1<<9);                        /*07-Enable the UART ,the Tx pin and the Rx pin*/
        break;
    default:
        /*report error*/
        break;
    }
}

/*function to Read Data*/
char   UART_ReadData(char UART_Number)
{
    switch(UART_Number)
    {
    case UART_0:
        while((UART0_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART0_UARTDR);                       /*return first 8 bits in the Data register*/
    case UART_1:
        while((UART1_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART1_UARTDR);                       /*return first 8 bits in the Data register*/
    case UART_2:
        while((UART2_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART2_UARTDR);                       /*return first 8 bits in the Data register*/
    case UART_3:
        while((UART3_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART3_UARTDR);                       /*return first 8 bits in the Data register*/
    case UART_4:
        while((UART4_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART4_UARTDR);                       /*return first 8 bits in the Data register*/
    case UART_5:
        while((UART5_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART5_UARTDR);                       /*return first 8 bits in the Data register*/
    case UART_6:
        while((UART6_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART6_UARTDR);                       /*return first 8 bits in the Data register*/
    case UART_7:
        while((UART7_UARTFR & 0x000010)!=0);         /*Wait until the Data is completely transmitted*/
        return (UART7_UARTDR);                       /*return first 8 bits in the Data register*/
    }
    return ERROR; /*error*/
}

/*function to send data */
void UART_SendData(char UART_Number , char DATA)
{
    switch(UART_Number)
    {
    case UART_0:
        while((UART0_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART0_UARTDR = DATA;                       /* before giving it another byte */
        break;
    case UART_1:
        while((UART1_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART1_UARTDR = DATA;                       /* before giving it another byte */
        break;
    case UART_2:
        while((UART2_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART2_UARTDR = DATA;                       /* before giving it another byte */
        break;
    case UART_3:
        while((UART3_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART3_UARTDR = DATA;                       /* before giving it another byte */
        break;
    case UART_4:
        while((UART4_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART4_UARTDR = DATA;                       /* before giving it another byte */
        break;
    case UART_5:
        while((UART5_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART5_UARTDR = DATA;                       /* before giving it another byte */
        break;
    case UART_6:
        while((UART6_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART6_UARTDR = DATA;                       /* before giving it another byte */
        break;
    case UART_7:
        while((UART7_UARTFR & 0x20) != 0);         /* wait until Tx buffer not full */
        UART7_UARTDR = DATA;                       /* before giving it another byte */
        break;
    }
}

void UART_sendString(char UART_Number ,char *Str)
{
    u8 i = 0;
    while(Str[i] != '\0')
    {
        UART_SendData(UART_Number,Str[i]);
        i++;
    }
    /************************* Another Method *************************
    while(*Str != '\0')
    {
        UART_sendByte(*Str);
        Str++;
    }
    *******************************************************************/
}


/*function to calculate the Integer baud rate*/
u16 INTEGER_BAUD_RATE(void)
{
    TOTAL_BAUD_RATE = (u16)(MCU_CLOCK / (CLK_DIV * BAUD_RATE));
    BAUD_RATE_INTEGER = (u16)TOTAL_BAUD_RATE;
    return BAUD_RATE_INTEGER;
}
/*function to calculate the Fractional baud rate*/
u8 FRACTION_BAUD_RATE(void)
{
    TOTAL_BAUD_RATE = TOTAL_BAUD_RATE - BAUD_RATE_INTEGER;
    BAUD_RATE_FRACTION = TOTAL_BAUD_RATE * 64 + 0.5;
    return (((u8)BAUD_RATE_FRACTION) & ~(0xE0));       /*return only five bits*/
}
