/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 22 April 2021
Version     : V01
 *****************************************************************************************************************/

#ifndef  UART_PRIVATE_H
#define  UART_PRIVATE_H

/*Register Definitions*/
#define   UART0       0x4000C000
#define   UART1       0x4000D000
#define   UART2       0x4000E000
#define   UART3       0x4000F000
#define   UART4       0x40010000
#define   UART5       0x40011000
#define   UART6       0x40012000
#define   UART7       0x40013000

#define   UARTDR           0x000                   // UART Data
#define   UARTRSR          0x004                   // UART Receive Status/Error Clear
#define   UARTFR           0x018                   // UART Flag
#define   UARTILPR         0x020                   // UART IrDA Low-Power Register
#define   UARTIBRD         0x024                   // UART Integer Baud-Rate Divisor
#define   UARTFBRD         0x028                   // UART Fractional Baud-Rate Divisor
#define   UARTLCRH         0x02C                   // UART Line Control
#define   UARTCTL          0x030                   // UART Control
#define   UARTIFLS         0x034                   // UART Interrupt FIFO Level Select
#define   UARTIM           0x038                   // UART Interrupt Mask
#define   UARTRIS          0x03C                   // UART Raw Interrupt Status
#define   UARTMIS          0x040                   // UART Masked Interrupt Status
#define   UARTICR          0x044                   // UART Interrupt Clear
#define   UARTDMACTL       0x048                   // UART DMA Control
#define   UART9BITADDR     0x0A4                   // UART 9-Bit Self Address
#define   UART9BITAMASK    0x0A8                   // UART 9-Bit Self Address Mask
#define   UARTPP           0xFC0                   // UART Peripheral Properties
#define   UARTCC           0xFC8                   // UART Clock Configuration
#define   UARTPeriphID4    0xFD0                   // UART Peripheral Identification 4
#define   UARTPeriphID5    0xFD4                   // UART Peripheral Identification 5
#define   UARTPeriphID6    0xFD8                   // UART Peripheral Identification 6
#define   UARTPeriphID7    0xFDC                   // UART Peripheral Identification 7
#define   UARTPeriphID0    0xFE0                   // UART Peripheral Identification 0
#define   UARTPeriphID1    0xFE4                   // UART Peripheral Identification 1
#define   UARTPeriphID2    0xFE8                   // UART Peripheral Identification 2
#define   UARTPeriphID3    0xFEC                   // UART Peripheral Identification 3
#define   UARTPCellID0     0xFF0                   // UART PrimeCell  Identification 0
#define   UARTPCellID1     0xFF4                   // UART PrimeCell  Identification 1
#define   UARTPCellID2     0xFF8                   // UART PrimeCell  Identification 2
#define   UARTPCellID3     0xFFC                   // UART PrimeCell  Identification 3



/*UART0 Registers*/
#define  UART0_UARTDR         (*((volatile u32 *)(UART0  +  UARTDR       )))
#define  UART0_UARTRSR        (*((volatile u32 *)(UART0  +  UARTRSR      )))
#define  UART0_UARTFR         (*((volatile u32 *)(UART0  +  UARTFR       )))
#define  UART0_UARTILPR       (*((volatile u32 *)(UART0  +  UARTILPR     )))
#define  UART0_UARTIBRD       (*((volatile u32 *)(UART0  +  UARTIBRD     )))
#define  UART0_UARTFBRD       (*((volatile u32 *)(UART0  +  UARTFBRD     )))
#define  UART0_UARTLCRH       (*((volatile u32 *)(UART0  +  UARTLCRH     )))
#define  UART0_UARTCTL        (*((volatile u32 *)(UART0  +  UARTCTL      )))
#define  UART0_UARTIFLS       (*((volatile u32 *)(UART0  +  UARTIFLS     )))
#define  UART0_UARTIM         (*((volatile u32 *)(UART0  +  UARTIM       )))
#define  UART0_UARTRIS        (*((volatile u32 *)(UART0  +  UARTRIS      )))
#define  UART0_UARTMIS        (*((volatile u32 *)(UART0  +  UARTMIS      )))
#define  UART0_UARTICR        (*((volatile u32 *)(UART0  +  UARTICR      )))
#define  UART0_UARTDMACTL     (*((volatile u32 *)(UART0  +  UARTDMACTL   )))
#define  UART0_UART9BITADDR   (*((volatile u32 *)(UART0  +  UART9BITADDR )))
#define  UART0_UART9BITAMASK  (*((volatile u32 *)(UART0  +  UART9BITAMASK)))
#define  UART0_UARTPP         (*((volatile u32 *)(UART0  +  UARTPP       )))
#define  UART0_UARTCC         (*((volatile u32 *)(UART0  +  UARTCC       )))
#define  UART0_UARTPeriphID4  (*((volatile u32 *)(UART0  +  UARTPeriphID4)))
#define  UART0_UARTPeriphID5  (*((volatile u32 *)(UART0  +  UARTPeriphID5)))
#define  UART0_UARTPeriphID6  (*((volatile u32 *)(UART0  +  UARTPeriphID6)))
#define  UART0_UARTPeriphID7  (*((volatile u32 *)(UART0  +  UARTPeriphID7)))
#define  UART0_UARTPeriphID0  (*((volatile u32 *)(UART0  +  UARTPeriphID0)))
#define  UART0_UARTPeriphID1  (*((volatile u32 *)(UART0  +  UARTPeriphID1)))
#define  UART0_UARTPeriphID2  (*((volatile u32 *)(UART0  +  UARTPeriphID2)))
#define  UART0_UARTPeriphID3  (*((volatile u32 *)(UART0  +  UARTPeriphID3)))
#define  UART0_UARTPCellID0   (*((volatile u32 *)(UART0  +  UARTPCellID0 )))
#define  UART0_UARTPCellID1   (*((volatile u32 *)(UART0  +  UARTPCellID1 )))
#define  UART0_UARTPCellID2   (*((volatile u32 *)(UART0  +  UARTPCellID2 )))
#define  UART0_UARTPCellID3   (*((volatile u32 *)(UART0  +  UARTPCellID3 )))


/*UART1 Registers*/
#define  UART1_UARTDR         (*((volatile u32 *)(UART1  +  UARTDR       )))
#define  UART1_UARTRSR        (*((volatile u32 *)(UART1  +  UARTRSR      )))
#define  UART1_UARTFR         (*((volatile u32 *)(UART1  +  UARTFR       )))
#define  UART1_UARTILPR       (*((volatile u32 *)(UART1  +  UARTILPR     )))
#define  UART1_UARTIBRD       (*((volatile u32 *)(UART1  +  UARTIBRD     )))
#define  UART1_UARTFBRD       (*((volatile u32 *)(UART1  +  UARTFBRD     )))
#define  UART1_UARTLCRH       (*((volatile u32 *)(UART1  +  UARTLCRH     )))
#define  UART1_UARTCTL        (*((volatile u32 *)(UART1  +  UARTCTL      )))
#define  UART1_UARTIFLS       (*((volatile u32 *)(UART1  +  UARTIFLS     )))
#define  UART1_UARTIM         (*((volatile u32 *)(UART1  +  UARTIM       )))
#define  UART1_UARTRIS        (*((volatile u32 *)(UART1  +  UARTRIS      )))
#define  UART1_UARTMIS        (*((volatile u32 *)(UART1  +  UARTMIS      )))
#define  UART1_UARTICR        (*((volatile u32 *)(UART1  +  UARTICR      )))
#define  UART1_UARTDMACTL     (*((volatile u32 *)(UART1  +  UARTDMACTL   )))
#define  UART1_UART9BITADDR   (*((volatile u32 *)(UART1  +  UART9BITADDR )))
#define  UART1_UART9BITAMASK  (*((volatile u32 *)(UART1  +  UART9BITAMASK)))
#define  UART1_UARTPP         (*((volatile u32 *)(UART1  +  UARTPP       )))
#define  UART1_UARTCC         (*((volatile u32 *)(UART1  +  UARTCC       )))
#define  UART1_UARTPeriphID4  (*((volatile u32 *)(UART1  +  UARTPeriphID4)))
#define  UART1_UARTPeriphID5  (*((volatile u32 *)(UART1  +  UARTPeriphID5)))
#define  UART1_UARTPeriphID6  (*((volatile u32 *)(UART1  +  UARTPeriphID6)))
#define  UART1_UARTPeriphID7  (*((volatile u32 *)(UART1  +  UARTPeriphID7)))
#define  UART1_UARTPeriphID0  (*((volatile u32 *)(UART1  +  UARTPeriphID0)))
#define  UART1_UARTPeriphID1  (*((volatile u32 *)(UART1  +  UARTPeriphID1)))
#define  UART1_UARTPeriphID2  (*((volatile u32 *)(UART1  +  UARTPeriphID2)))
#define  UART1_UARTPeriphID3  (*((volatile u32 *)(UART1  +  UARTPeriphID3)))
#define  UART1_UARTPCellID0   (*((volatile u32 *)(UART1  +  UARTPCellID0 )))
#define  UART1_UARTPCellID1   (*((volatile u32 *)(UART1  +  UARTPCellID1 )))
#define  UART1_UARTPCellID2   (*((volatile u32 *)(UART1  +  UARTPCellID2 )))
#define  UART1_UARTPCellID3   (*((volatile u32 *)(UART1  +  UARTPCellID3 )))

/*UART2 Registers*/
#define  UART2_UARTDR         (*((volatile u32 *)(UART2  +  UARTDR       )))
#define  UART2_UARTRSR        (*((volatile u32 *)(UART2  +  UARTRSR      )))
#define  UART2_UARTFR         (*((volatile u32 *)(UART2  +  UARTFR       )))
#define  UART2_UARTILPR       (*((volatile u32 *)(UART2  +  UARTILPR     )))
#define  UART2_UARTIBRD       (*((volatile u32 *)(UART2  +  UARTIBRD     )))
#define  UART2_UARTFBRD       (*((volatile u32 *)(UART2  +  UARTFBRD     )))
#define  UART2_UARTLCRH       (*((volatile u32 *)(UART2  +  UARTLCRH     )))
#define  UART2_UARTCTL        (*((volatile u32 *)(UART2  +  UARTCTL      )))
#define  UART2_UARTIFLS       (*((volatile u32 *)(UART2  +  UARTIFLS     )))
#define  UART2_UARTIM         (*((volatile u32 *)(UART2  +  UARTIM       )))
#define  UART2_UARTRIS        (*((volatile u32 *)(UART2  +  UARTRIS      )))
#define  UART2_UARTMIS        (*((volatile u32 *)(UART2  +  UARTMIS      )))
#define  UART2_UARTICR        (*((volatile u32 *)(UART2  +  UARTICR      )))
#define  UART2_UARTDMACTL     (*((volatile u32 *)(UART2  +  UARTDMACTL   )))
#define  UART2_UART9BITADDR   (*((volatile u32 *)(UART2  +  UART9BITADDR )))
#define  UART2_UART9BITAMASK  (*((volatile u32 *)(UART2  +  UART9BITAMASK)))
#define  UART2_UARTPP         (*((volatile u32 *)(UART2  +  UARTPP       )))
#define  UART2_UARTCC         (*((volatile u32 *)(UART2  +  UARTCC       )))
#define  UART2_UARTPeriphID4  (*((volatile u32 *)(UART2  +  UARTPeriphID4)))
#define  UART2_UARTPeriphID5  (*((volatile u32 *)(UART2  +  UARTPeriphID5)))
#define  UART2_UARTPeriphID6  (*((volatile u32 *)(UART2  +  UARTPeriphID6)))
#define  UART2_UARTPeriphID7  (*((volatile u32 *)(UART2  +  UARTPeriphID7)))
#define  UART2_UARTPeriphID0  (*((volatile u32 *)(UART2  +  UARTPeriphID0)))
#define  UART2_UARTPeriphID1  (*((volatile u32 *)(UART2  +  UARTPeriphID1)))
#define  UART2_UARTPeriphID2  (*((volatile u32 *)(UART2  +  UARTPeriphID2)))
#define  UART2_UARTPeriphID3  (*((volatile u32 *)(UART2  +  UARTPeriphID3)))
#define  UART2_UARTPCellID0   (*((volatile u32 *)(UART2  +  UARTPCellID0 )))
#define  UART2_UARTPCellID1   (*((volatile u32 *)(UART2  +  UARTPCellID1 )))
#define  UART2_UARTPCellID2   (*((volatile u32 *)(UART2  +  UARTPCellID2 )))
#define  UART2_UARTPCellID3   (*((volatile u32 *)(UART2  +  UARTPCellID3 )))

/*UART3 Registers*/
#define  UART3_UARTDR         (*((volatile u32 *)(UART3  +  UARTDR       )))
#define  UART3_UARTRSR        (*((volatile u32 *)(UART3  +  UARTRSR      )))
#define  UART3_UARTFR         (*((volatile u32 *)(UART3  +  UARTFR       )))
#define  UART3_UARTILPR       (*((volatile u32 *)(UART3  +  UARTILPR     )))
#define  UART3_UARTIBRD       (*((volatile u32 *)(UART3  +  UARTIBRD     )))
#define  UART3_UARTFBRD       (*((volatile u32 *)(UART3  +  UARTFBRD     )))
#define  UART3_UARTLCRH       (*((volatile u32 *)(UART3  +  UARTLCRH     )))
#define  UART3_UARTCTL        (*((volatile u32 *)(UART3  +  UARTCTL      )))
#define  UART3_UARTIFLS       (*((volatile u32 *)(UART3  +  UARTIFLS     )))
#define  UART3_UARTIM         (*((volatile u32 *)(UART3  +  UARTIM       )))
#define  UART3_UARTRIS        (*((volatile u32 *)(UART3  +  UARTRIS      )))
#define  UART3_UARTMIS        (*((volatile u32 *)(UART3  +  UARTMIS      )))
#define  UART3_UARTICR        (*((volatile u32 *)(UART3  +  UARTICR      )))
#define  UART3_UARTDMACTL     (*((volatile u32 *)(UART3  +  UARTDMACTL   )))
#define  UART3_UART9BITADDR   (*((volatile u32 *)(UART3  +  UART9BITADDR )))
#define  UART3_UART9BITAMASK  (*((volatile u32 *)(UART3  +  UART9BITAMASK)))
#define  UART3_UARTPP         (*((volatile u32 *)(UART3  +  UARTPP       )))
#define  UART3_UARTCC         (*((volatile u32 *)(UART3  +  UARTCC       )))
#define  UART3_UARTPeriphID4  (*((volatile u32 *)(UART3  +  UARTPeriphID4)))
#define  UART3_UARTPeriphID5  (*((volatile u32 *)(UART3  +  UARTPeriphID5)))
#define  UART3_UARTPeriphID6  (*((volatile u32 *)(UART3  +  UARTPeriphID6)))
#define  UART3_UARTPeriphID7  (*((volatile u32 *)(UART3  +  UARTPeriphID7)))
#define  UART3_UARTPeriphID0  (*((volatile u32 *)(UART3  +  UARTPeriphID0)))
#define  UART3_UARTPeriphID1  (*((volatile u32 *)(UART3  +  UARTPeriphID1)))
#define  UART3_UARTPeriphID2  (*((volatile u32 *)(UART3  +  UARTPeriphID2)))
#define  UART3_UARTPeriphID3  (*((volatile u32 *)(UART3  +  UARTPeriphID3)))
#define  UART3_UARTPCellID0   (*((volatile u32 *)(UART3  +  UARTPCellID0 )))
#define  UART3_UARTPCellID1   (*((volatile u32 *)(UART3  +  UARTPCellID1 )))
#define  UART3_UARTPCellID2   (*((volatile u32 *)(UART3  +  UARTPCellID2 )))
#define  UART3_UARTPCellID3   (*((volatile u32 *)(UART3  +  UARTPCellID3 )))

/*UART4 Registers*/
#define  UART4_UARTDR         (*((volatile u32 *)(UART4  +  UARTDR       )))
#define  UART4_UARTRSR        (*((volatile u32 *)(UART4  +  UARTRSR      )))
#define  UART4_UARTFR         (*((volatile u32 *)(UART4  +  UARTFR       )))
#define  UART4_UARTILPR       (*((volatile u32 *)(UART4  +  UARTILPR     )))
#define  UART4_UARTIBRD       (*((volatile u32 *)(UART4  +  UARTIBRD     )))
#define  UART4_UARTFBRD       (*((volatile u32 *)(UART4  +  UARTFBRD     )))
#define  UART4_UARTLCRH       (*((volatile u32 *)(UART4  +  UARTLCRH     )))
#define  UART4_UARTCTL        (*((volatile u32 *)(UART4  +  UARTCTL      )))
#define  UART4_UARTIFLS       (*((volatile u32 *)(UART4  +  UARTIFLS     )))
#define  UART4_UARTIM         (*((volatile u32 *)(UART4  +  UARTIM       )))
#define  UART4_UARTRIS        (*((volatile u32 *)(UART4  +  UARTRIS      )))
#define  UART4_UARTMIS        (*((volatile u32 *)(UART4  +  UARTMIS      )))
#define  UART4_UARTICR        (*((volatile u32 *)(UART4  +  UARTICR      )))
#define  UART4_UARTDMACTL     (*((volatile u32 *)(UART4  +  UARTDMACTL   )))
#define  UART4_UART9BITADDR   (*((volatile u32 *)(UART4  +  UART9BITADDR )))
#define  UART4_UART9BITAMASK  (*((volatile u32 *)(UART4  +  UART9BITAMASK)))
#define  UART4_UARTPP         (*((volatile u32 *)(UART4  +  UARTPP       )))
#define  UART4_UARTCC         (*((volatile u32 *)(UART4  +  UARTCC       )))
#define  UART4_UARTPeriphID4  (*((volatile u32 *)(UART4  +  UARTPeriphID4)))
#define  UART4_UARTPeriphID5  (*((volatile u32 *)(UART4  +  UARTPeriphID5)))
#define  UART4_UARTPeriphID6  (*((volatile u32 *)(UART4  +  UARTPeriphID6)))
#define  UART4_UARTPeriphID7  (*((volatile u32 *)(UART4  +  UARTPeriphID7)))
#define  UART4_UARTPeriphID0  (*((volatile u32 *)(UART4  +  UARTPeriphID0)))
#define  UART4_UARTPeriphID1  (*((volatile u32 *)(UART4  +  UARTPeriphID1)))
#define  UART4_UARTPeriphID2  (*((volatile u32 *)(UART4  +  UARTPeriphID2)))
#define  UART4_UARTPeriphID3  (*((volatile u32 *)(UART4  +  UARTPeriphID3)))
#define  UART4_UARTPCellID0   (*((volatile u32 *)(UART4  +  UARTPCellID0 )))
#define  UART4_UARTPCellID1   (*((volatile u32 *)(UART4  +  UARTPCellID1 )))
#define  UART4_UARTPCellID2   (*((volatile u32 *)(UART4  +  UARTPCellID2 )))
#define  UART4_UARTPCellID3   (*((volatile u32 *)(UART4  +  UARTPCellID3 )))

/*UART5 Registers*/
#define  UART5_UARTDR         (*((volatile u32 *)(UART5  +  UARTDR       )))
#define  UART5_UARTRSR        (*((volatile u32 *)(UART5  +  UARTRSR      )))
#define  UART5_UARTFR         (*((volatile u32 *)(UART5  +  UARTFR       )))
#define  UART5_UARTILPR       (*((volatile u32 *)(UART5  +  UARTILPR     )))
#define  UART5_UARTIBRD       (*((volatile u32 *)(UART5  +  UARTIBRD     )))
#define  UART5_UARTFBRD       (*((volatile u32 *)(UART5  +  UARTFBRD     )))
#define  UART5_UARTLCRH       (*((volatile u32 *)(UART5  +  UARTLCRH     )))
#define  UART5_UARTCTL        (*((volatile u32 *)(UART5  +  UARTCTL      )))
#define  UART5_UARTIFLS       (*((volatile u32 *)(UART5  +  UARTIFLS     )))
#define  UART5_UARTIM         (*((volatile u32 *)(UART5  +  UARTIM       )))
#define  UART5_UARTRIS        (*((volatile u32 *)(UART5  +  UARTRIS      )))
#define  UART5_UARTMIS        (*((volatile u32 *)(UART5  +  UARTMIS      )))
#define  UART5_UARTICR        (*((volatile u32 *)(UART5  +  UARTICR      )))
#define  UART5_UARTDMACTL     (*((volatile u32 *)(UART5  +  UARTDMACTL   )))
#define  UART5_UART9BITADDR   (*((volatile u32 *)(UART5  +  UART9BITADDR )))
#define  UART5_UART9BITAMASK  (*((volatile u32 *)(UART5  +  UART9BITAMASK)))
#define  UART5_UARTPP         (*((volatile u32 *)(UART5  +  UARTPP       )))
#define  UART5_UARTCC         (*((volatile u32 *)(UART5  +  UARTCC       )))
#define  UART5_UARTPeriphID4  (*((volatile u32 *)(UART5  +  UARTPeriphID4)))
#define  UART5_UARTPeriphID5  (*((volatile u32 *)(UART5  +  UARTPeriphID5)))
#define  UART5_UARTPeriphID6  (*((volatile u32 *)(UART5  +  UARTPeriphID6)))
#define  UART5_UARTPeriphID7  (*((volatile u32 *)(UART5  +  UARTPeriphID7)))
#define  UART5_UARTPeriphID0  (*((volatile u32 *)(UART5  +  UARTPeriphID0)))
#define  UART5_UARTPeriphID1  (*((volatile u32 *)(UART5  +  UARTPeriphID1)))
#define  UART5_UARTPeriphID2  (*((volatile u32 *)(UART5  +  UARTPeriphID2)))
#define  UART5_UARTPeriphID3  (*((volatile u32 *)(UART5  +  UARTPeriphID3)))
#define  UART5_UARTPCellID0   (*((volatile u32 *)(UART5  +  UARTPCellID0 )))
#define  UART5_UARTPCellID1   (*((volatile u32 *)(UART5  +  UARTPCellID1 )))
#define  UART5_UARTPCellID2   (*((volatile u32 *)(UART5  +  UARTPCellID2 )))
#define  UART5_UARTPCellID3   (*((volatile u32 *)(UART5  +  UARTPCellID3 )))

/*UART6 Registers*/
#define  UART6_UARTDR         (*((volatile u32 *)(UART6  +  UARTDR       )))
#define  UART6_UARTRSR        (*((volatile u32 *)(UART6  +  UARTRSR      )))
#define  UART6_UARTFR         (*((volatile u32 *)(UART6  +  UARTFR       )))
#define  UART6_UARTILPR       (*((volatile u32 *)(UART6  +  UARTILPR     )))
#define  UART6_UARTIBRD       (*((volatile u32 *)(UART6  +  UARTIBRD     )))
#define  UART6_UARTFBRD       (*((volatile u32 *)(UART6  +  UARTFBRD     )))
#define  UART6_UARTLCRH       (*((volatile u32 *)(UART6  +  UARTLCRH     )))
#define  UART6_UARTCTL        (*((volatile u32 *)(UART6  +  UARTCTL      )))
#define  UART6_UARTIFLS       (*((volatile u32 *)(UART6  +  UARTIFLS     )))
#define  UART6_UARTIM         (*((volatile u32 *)(UART6  +  UARTIM       )))
#define  UART6_UARTRIS        (*((volatile u32 *)(UART6  +  UARTRIS      )))
#define  UART6_UARTMIS        (*((volatile u32 *)(UART6  +  UARTMIS      )))
#define  UART6_UARTICR        (*((volatile u32 *)(UART6  +  UARTICR      )))
#define  UART6_UARTDMACTL     (*((volatile u32 *)(UART6  +  UARTDMACTL   )))
#define  UART6_UART9BITADDR   (*((volatile u32 *)(UART6  +  UART9BITADDR )))
#define  UART6_UART9BITAMASK  (*((volatile u32 *)(UART6  +  UART9BITAMASK)))
#define  UART6_UARTPP         (*((volatile u32 *)(UART6  +  UARTPP       )))
#define  UART6_UARTCC         (*((volatile u32 *)(UART6  +  UARTCC       )))
#define  UART6_UARTPeriphID4  (*((volatile u32 *)(UART6  +  UARTPeriphID4)))
#define  UART6_UARTPeriphID5  (*((volatile u32 *)(UART6  +  UARTPeriphID5)))
#define  UART6_UARTPeriphID6  (*((volatile u32 *)(UART6  +  UARTPeriphID6)))
#define  UART6_UARTPeriphID7  (*((volatile u32 *)(UART6  +  UARTPeriphID7)))
#define  UART6_UARTPeriphID0  (*((volatile u32 *)(UART6  +  UARTPeriphID0)))
#define  UART6_UARTPeriphID1  (*((volatile u32 *)(UART6  +  UARTPeriphID1)))
#define  UART6_UARTPeriphID2  (*((volatile u32 *)(UART6  +  UARTPeriphID2)))
#define  UART6_UARTPeriphID3  (*((volatile u32 *)(UART6  +  UARTPeriphID3)))
#define  UART6_UARTPCellID0   (*((volatile u32 *)(UART6  +  UARTPCellID0 )))
#define  UART6_UARTPCellID1   (*((volatile u32 *)(UART6  +  UARTPCellID1 )))
#define  UART6_UARTPCellID2   (*((volatile u32 *)(UART6  +  UARTPCellID2 )))
#define  UART6_UARTPCellID3   (*((volatile u32 *)(UART6  +  UARTPCellID3 )))

/*UART7 Registers*/
#define  UART7_UARTDR         (*((volatile u32 *)(UART7  +  UARTDR       )))
#define  UART7_UARTRSR        (*((volatile u32 *)(UART7  +  UARTRSR      )))
#define  UART7_UARTFR         (*((volatile u32 *)(UART7  +  UARTFR       )))
#define  UART7_UARTILPR       (*((volatile u32 *)(UART7  +  UARTILPR     )))
#define  UART7_UARTIBRD       (*((volatile u32 *)(UART7  +  UARTIBRD     )))
#define  UART7_UARTFBRD       (*((volatile u32 *)(UART7  +  UARTFBRD     )))
#define  UART7_UARTLCRH       (*((volatile u32 *)(UART7  +  UARTLCRH     )))
#define  UART7_UARTCTL        (*((volatile u32 *)(UART7  +  UARTCTL      )))
#define  UART7_UARTIFLS       (*((volatile u32 *)(UART7  +  UARTIFLS     )))
#define  UART7_UARTIM         (*((volatile u32 *)(UART7  +  UARTIM       )))
#define  UART7_UARTRIS        (*((volatile u32 *)(UART7  +  UARTRIS      )))
#define  UART7_UARTMIS        (*((volatile u32 *)(UART7  +  UARTMIS      )))
#define  UART7_UARTICR        (*((volatile u32 *)(UART7  +  UARTICR      )))
#define  UART7_UARTDMACTL     (*((volatile u32 *)(UART7  +  UARTDMACTL   )))
#define  UART7_UART9BITADDR   (*((volatile u32 *)(UART7  +  UART9BITADDR )))
#define  UART7_UART9BITAMASK  (*((volatile u32 *)(UART7  +  UART9BITAMASK)))
#define  UART7_UARTPP         (*((volatile u32 *)(UART7  +  UARTPP       )))
#define  UART7_UARTCC         (*((volatile u32 *)(UART7  +  UARTCC       )))
#define  UART7_UARTPeriphID4  (*((volatile u32 *)(UART7  +  UARTPeriphID4)))
#define  UART7_UARTPeriphID5  (*((volatile u32 *)(UART7  +  UARTPeriphID5)))
#define  UART7_UARTPeriphID6  (*((volatile u32 *)(UART7  +  UARTPeriphID6)))
#define  UART7_UARTPeriphID7  (*((volatile u32 *)(UART7  +  UARTPeriphID7)))
#define  UART7_UARTPeriphID0  (*((volatile u32 *)(UART7  +  UARTPeriphID0)))
#define  UART7_UARTPeriphID1  (*((volatile u32 *)(UART7  +  UARTPeriphID1)))
#define  UART7_UARTPeriphID2  (*((volatile u32 *)(UART7  +  UARTPeriphID2)))
#define  UART7_UARTPeriphID3  (*((volatile u32 *)(UART7  +  UARTPeriphID3)))
#define  UART7_UARTPCellID0   (*((volatile u32 *)(UART7  +  UARTPCellID0 )))
#define  UART7_UARTPCellID1   (*((volatile u32 *)(UART7  +  UARTPCellID1 )))
#define  UART7_UARTPCellID2   (*((volatile u32 *)(UART7  +  UARTPCellID2 )))
#define  UART7_UARTPCellID3   (*((volatile u32 *)(UART7  +  UARTPCellID3 )))


/*function to calculate the Integer baud rate*/
u16 INTEGER_BAUD_RATE(void);
/*function to calculate the Fractional baud rate*/
u8 FRACTION_BAUD_RATE(void);

#endif
