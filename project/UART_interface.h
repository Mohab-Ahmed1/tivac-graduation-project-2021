/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 22 April 2021
Version     : V01
 *****************************************************************************************************************/

#ifndef  UART_INTERFACE_H
#define  UART_INTERFACE_H
#include <stdint.h>

#define  UART_0          0x00
#define  UART_1          0x01
#define  UART_2          0x02
#define  UART_3          0x03
#define  UART_4          0x04
#define  UART_5          0x05
#define  UART_6          0x06
#define  UART_7          0x07

#define PA0_Rx_UART0      17
#define PA1_Tx_UART0      18

#define PB0_Rx_UART1      45
#define PB1_Tx_UART1      46

#define PD6_Rx_UART2      53
#define PD7_Tx_UART2      10

#define PC6_Rx_UART3      14
#define PC7_Tx_UART3      13

#define PC4_Rx_UART4      16
#define PC5_Tx_UART4      15

#define PE4_Rx_UART5      59
#define PE5_Tx_UART5      60

#define PD4_Rx_UART6      43
#define PD5_Tx_UART6      44

#define PE0_Rx_UART7      9
#define PE1_Tx_UART7      8


/********************************************************************************************
 *
 *                             functions prototype
 *
 *******************************************************************************************/
void UART_Init(char UART_Number);
char   UART_ReadData(char UART_Number);
void UART_SendData(char UART_Number , char DATA);
void UART_sendString(char UART_Number ,char *Str);

#endif
