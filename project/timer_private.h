/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 7 Jan 2021
Version     : V01
 *****************************************************************************************************************/

#ifndef  _PRIVATE_H
#define  _PRIVATE_H

/*Register Definitions*/
#define   Timer_0       0x40030000
#define   Timer_1       0x40031000
#define   Timer_2       0x40032000
#define   Timer_3       0x40033000
#define   Timer_4       0x40034000
#define   Timer_5       0x40035000

#define   Wide_Timer_0  0x40036000
#define   Wide_Timer_1  0x40037000
#define   Wide_Timer_2  0x4004C000
#define   Wide_Timer_3  0x40040000
#define   Wide_Timer_4  0x4004E000
#define   Wide_Timer_5  0x4004F000

/*timer register map*/

#define  GPTMCFG             0x000          //GPTM Configuration
#define  GPTMTAMR            0x004          // GPTM Timer A Mode
#define  GPTMTBMR            0x008          // GPTM Timer B Mode
#define  GPTMCTL             0x00C          //GPTM Control
#define  GPTMSYNC            0x010          // GPTM Synchronize
#define  GPTMIMR             0x018          //GPTM Interrupt Mask
#define  GPTMRIS             0x01C          //GPTM Raw Interrupt Status
#define  GPTMMIS             0x020          //GPTM Masked Interrupt Status
#define  GPTMICR             0x024          // GPTM Interrupt Clear
#define  GPTMTAILR           0x028          // GPTM Timer A Interval Load
#define  GPTMTBILR           0x02C          // GPTM Timer B Interval Load
#define  GPTMTAMATCHR        0x030          //GPTM Timer A Match
#define  GPTMTBMATCHR        0x034          //GPTM Timer B Match
#define  GPTMTAPR            0x038          // GPTM Timer A Prescale
#define  GPTMTBPR            0x03C          // GPTM Timer B Prescale
#define  GPTMTAPMR           0x040          // GPTM TimerA Prescale Match
#define  GPTMTBPMR           0x044          // GPTM TimerB Prescale Match
#define  GPTMTAR             0x048          //GPTM Timer A
#define  GPTMTBR             0x04C          //GPTM Timer B
#define  GPTMTAV             0x050          //GPTM Timer A Value
#define  GPTMTBV             0x054          //GPTM Timer B Value
#define  GPTMRTCPD           0x058          // GPTM RTC Predivide
#define  GPTMTAPS            0x05C          // GPTM Timer A Prescale Snapshot
#define  GPTMTBPS            0x060          // GPTM Timer B Prescale Snapshot
#define  GPTMTAPV            0x064          // GPTM Timer A Prescale Value
#define  GPTMTBPV            0x068          // GPTM Timer B Prescale Value
#define  GPTMPP              0xFC0          // GPTM Peripheral Properties

/*timer0 Registers*/
#define  timer0_GPTMCFG       (*((volatile u32 *)(Timer_0  +  GPTMCFG     )))
#define  timer0_GPTMTAMR      (*((volatile u32 *)(Timer_0  +  GPTMTAMR    )))
#define  timer0_GPTMTBMR      (*((volatile u32 *)(Timer_0  +  GPTMTBMR    )))
#define  timer0_GPTMCTL       (*((volatile u32 *)(Timer_0  +  GPTMCTL     )))
#define  timer0_GPTMSYNC      (*((volatile u32 *)(Timer_0  +  GPTMSYNC    )))
#define  timer0_GPTMIMR       (*((volatile u32 *)(Timer_0  +  GPTMIMR     )))
#define  timer0_GPTMRIS       (*((volatile u32 *)(Timer_0  +  GPTMRIS     )))
#define  timer0_GPTMMIS       (*((volatile u32 *)(Timer_0  +  GPTMMIS     )))
#define  timer0_GPTMICR       (*((volatile u32 *)(Timer_0  +  GPTMICR     )))
#define  timer0_GPTMTAILR     (*((volatile u32 *)(Timer_0  +  GPTMTAILR   )))
#define  timer0_GPTMTBILR     (*((volatile u32 *)(Timer_0  +  GPTMTBILR   )))
#define  timer0_GPTMTAMATCHR  (*((volatile u32 *)(Timer_0  +  GPTMTAMATCHR)))
#define  timer0_GPTMTBMATCHR  (*((volatile u32 *)(Timer_0  +  GPTMTBMATCHR)))
#define  timer0_GPTMTAPR      (*((volatile u32 *)(Timer_0  +  GPTMTAPR    )))
#define  timer0_GPTMTBPR      (*((volatile u32 *)(Timer_0  +  GPTMTBPR    )))
#define  timer0_GPTMTAPMR     (*((volatile u32 *)(Timer_0  +  GPTMTAPMR   )))
#define  timer0_GPTMTBPMR     (*((volatile u32 *)(Timer_0  +  GPTMTBPMR   )))
#define  timer0_GPTMTAR       (*((volatile u32 *)(Timer_0  +  GPTMTAR     )))
#define  timer0_GPTMTBR       (*((volatile u32 *)(Timer_0  +  GPTMTBR     )))
#define  timer0_GPTMTAV       (*((volatile u32 *)(Timer_0  +  GPTMTAV     )))
#define  timer0_GPTMTBV       (*((volatile u32 *)(Timer_0  +  GPTMTBV     )))
#define  timer0_GPTMRTCPD     (*((volatile u32 *)(Timer_0  +  GPTMRTCPD   )))
#define  timer0_GPTMTAPS      (*((volatile u32 *)(Timer_0  +  GPTMTAPS    )))
#define  timer0_GPTMTBPS      (*((volatile u32 *)(Timer_0  +  GPTMTBPS    )))
#define  timer0_GPTMTAPV      (*((volatile u32 *)(Timer_0  +  GPTMTAPV    )))
#define  timer0_GPTMTBPV      (*((volatile u32 *)(Timer_0  +  GPTMTBPV    )))
#define  timer0_GPTMPP        (*((volatile u32 *)(Timer_0  +  GPTMPP      )))


/*timer1 Registers*/
#define  timer1_GPTMCFG       (*((volatile u32 *)(Timer_1  +  GPTMCFG     )))
#define  timer1_GPTMTAMR      (*((volatile u32 *)(Timer_1  +  GPTMTAMR    )))
#define  timer1_GPTMTBMR      (*((volatile u32 *)(Timer_1  +  GPTMTBMR    )))
#define  timer1_GPTMCTL       (*((volatile u32 *)(Timer_1  +  GPTMCTL     )))
#define  timer1_GPTMSYNC      (*((volatile u32 *)(Timer_1  +  GPTMSYNC    )))
#define  timer1_GPTMIMR       (*((volatile u32 *)(Timer_1  +  GPTMIMR     )))
#define  timer1_GPTMRIS       (*((volatile u32 *)(Timer_1  +  GPTMRIS     )))
#define  timer1_GPTMMIS       (*((volatile u32 *)(Timer_1  +  GPTMMIS     )))
#define  timer1_GPTMICR       (*((volatile u32 *)(Timer_1  +  GPTMICR     )))
#define  timer1_GPTMTAILR     (*((volatile u32 *)(Timer_1  +  GPTMTAILR   )))
#define  timer1_GPTMTBILR     (*((volatile u32 *)(Timer_1  +  GPTMTBILR   )))
#define  timer1_GPTMTAMATCHR  (*((volatile u32 *)(Timer_1  +  GPTMTAMATCHR)))
#define  timer1_GPTMTBMATCHR  (*((volatile u32 *)(Timer_1  +  GPTMTBMATCHR)))
#define  timer1_GPTMTAPR      (*((volatile u32 *)(Timer_1  +  GPTMTAPR    )))
#define  timer1_GPTMTBPR      (*((volatile u32 *)(Timer_1  +  GPTMTBPR    )))
#define  timer1_GPTMTAPMR     (*((volatile u32 *)(Timer_1  +  GPTMTAPMR   )))
#define  timer1_GPTMTBPMR     (*((volatile u32 *)(Timer_1  +  GPTMTBPMR   )))
#define  timer1_GPTMTAR       (*((volatile u32 *)(Timer_1  +  GPTMTAR     )))
#define  timer1_GPTMTBR       (*((volatile u32 *)(Timer_1  +  GPTMTBR     )))
#define  timer1_GPTMTAV       (*((volatile u32 *)(Timer_1  +  GPTMTAV     )))
#define  timer1_GPTMTBV       (*((volatile u32 *)(Timer_1  +  GPTMTBV     )))
#define  timer1_GPTMRTCPD     (*((volatile u32 *)(Timer_1  +  GPTMRTCPD   )))
#define  timer1_GPTMTAPS      (*((volatile u32 *)(Timer_1  +  GPTMTAPS    )))
#define  timer1_GPTMTBPS      (*((volatile u32 *)(Timer_1  +  GPTMTBPS    )))
#define  timer1_GPTMTAPV      (*((volatile u32 *)(Timer_1  +  GPTMTAPV    )))
#define  timer1_GPTMTBPV      (*((volatile u32 *)(Timer_1  +  GPTMTBPV    )))
#define  timer1_GPTMPP        (*((volatile u32 *)(Timer_1  +  GPTMPP      )))

/*timer2 Registers*/
#define  timer2_GPTMCFG       (*((volatile u32 *)(Timer_2  +  GPTMCFG     )))
#define  timer2_GPTMTAMR      (*((volatile u32 *)(Timer_2  +  GPTMTAMR    )))
#define  timer2_GPTMTBMR      (*((volatile u32 *)(Timer_2  +  GPTMTBMR    )))
#define  timer2_GPTMCTL       (*((volatile u32 *)(Timer_2  +  GPTMCTL     )))
#define  timer2_GPTMSYNC      (*((volatile u32 *)(Timer_2  +  GPTMSYNC    )))
#define  timer2_GPTMIMR       (*((volatile u32 *)(Timer_2  +  GPTMIMR     )))
#define  timer2_GPTMRIS       (*((volatile u32 *)(Timer_2  +  GPTMRIS     )))
#define  timer2_GPTMMIS       (*((volatile u32 *)(Timer_2  +  GPTMMIS     )))
#define  timer2_GPTMICR       (*((volatile u32 *)(Timer_2  +  GPTMICR     )))
#define  timer2_GPTMTAILR     (*((volatile u32 *)(Timer_2  +  GPTMTAILR   )))
#define  timer2_GPTMTBILR     (*((volatile u32 *)(Timer_2  +  GPTMTBILR   )))
#define  timer2_GPTMTAMATCHR  (*((volatile u32 *)(Timer_2  +  GPTMTAMATCHR)))
#define  timer2_GPTMTBMATCHR  (*((volatile u32 *)(Timer_2  +  GPTMTBMATCHR)))
#define  timer2_GPTMTAPR      (*((volatile u32 *)(Timer_2  +  GPTMTAPR    )))
#define  timer2_GPTMTBPR      (*((volatile u32 *)(Timer_2  +  GPTMTBPR    )))
#define  timer2_GPTMTAPMR     (*((volatile u32 *)(Timer_2  +  GPTMTAPMR   )))
#define  timer2_GPTMTBPMR     (*((volatile u32 *)(Timer_2  +  GPTMTBPMR   )))
#define  timer2_GPTMTAR       (*((volatile u32 *)(Timer_2  +  GPTMTAR     )))
#define  timer2_GPTMTBR       (*((volatile u32 *)(Timer_2  +  GPTMTBR     )))
#define  timer2_GPTMTAV       (*((volatile u32 *)(Timer_2  +  GPTMTAV     )))
#define  timer2_GPTMTBV       (*((volatile u32 *)(Timer_2  +  GPTMTBV     )))
#define  timer2_GPTMRTCPD     (*((volatile u32 *)(Timer_2  +  GPTMRTCPD   )))
#define  timer2_GPTMTAPS      (*((volatile u32 *)(Timer_2  +  GPTMTAPS    )))
#define  timer2_GPTMTBPS      (*((volatile u32 *)(Timer_2  +  GPTMTBPS    )))
#define  timer2_GPTMTAPV      (*((volatile u32 *)(Timer_2  +  GPTMTAPV    )))
#define  timer2_GPTMTBPV      (*((volatile u32 *)(Timer_2  +  GPTMTBPV    )))
#define  timer2_GPTMPP        (*((volatile u32 *)(Timer_2  +  GPTMPP      )))

/*timer3 Registers*/
#define  timer3_GPTMCFG       (*((volatile u32 *)(Timer_3  +  GPTMCFG     )))
#define  timer3_GPTMTAMR      (*((volatile u32 *)(Timer_3  +  GPTMTAMR    )))
#define  timer3_GPTMTBMR      (*((volatile u32 *)(Timer_3  +  GPTMTBMR    )))
#define  timer3_GPTMCTL       (*((volatile u32 *)(Timer_3  +  GPTMCTL     )))
#define  timer3_GPTMSYNC      (*((volatile u32 *)(Timer_3  +  GPTMSYNC    )))
#define  timer3_GPTMIMR       (*((volatile u32 *)(Timer_3  +  GPTMIMR     )))
#define  timer3_GPTMRIS       (*((volatile u32 *)(Timer_3  +  GPTMRIS     )))
#define  timer3_GPTMMIS       (*((volatile u32 *)(Timer_3  +  GPTMMIS     )))
#define  timer3_GPTMICR       (*((volatile u32 *)(Timer_3  +  GPTMICR     )))
#define  timer3_GPTMTAILR     (*((volatile u32 *)(Timer_3  +  GPTMTAILR   )))
#define  timer3_GPTMTBILR     (*((volatile u32 *)(Timer_3  +  GPTMTBILR   )))
#define  timer3_GPTMTAMATCHR  (*((volatile u32 *)(Timer_3  +  GPTMTAMATCHR)))
#define  timer3_GPTMTBMATCHR  (*((volatile u32 *)(Timer_3  +  GPTMTBMATCHR)))
#define  timer3_GPTMTAPR      (*((volatile u32 *)(Timer_3  +  GPTMTAPR    )))
#define  timer3_GPTMTBPR      (*((volatile u32 *)(Timer_3  +  GPTMTBPR    )))
#define  timer3_GPTMTAPMR     (*((volatile u32 *)(Timer_3  +  GPTMTAPMR   )))
#define  timer3_GPTMTBPMR     (*((volatile u32 *)(Timer_3  +  GPTMTBPMR   )))
#define  timer3_GPTMTAR       (*((volatile u32 *)(Timer_3  +  GPTMTAR     )))
#define  timer3_GPTMTBR       (*((volatile u32 *)(Timer_3  +  GPTMTBR     )))
#define  timer3_GPTMTAV       (*((volatile u32 *)(Timer_3  +  GPTMTAV     )))
#define  timer3_GPTMTBV       (*((volatile u32 *)(Timer_3  +  GPTMTBV     )))
#define  timer3_GPTMRTCPD     (*((volatile u32 *)(Timer_3  +  GPTMRTCPD   )))
#define  timer3_GPTMTAPS      (*((volatile u32 *)(Timer_3  +  GPTMTAPS    )))
#define  timer3_GPTMTBPS      (*((volatile u32 *)(Timer_3  +  GPTMTBPS    )))
#define  timer3_GPTMTAPV      (*((volatile u32 *)(Timer_3  +  GPTMTAPV    )))
#define  timer3_GPTMTBPV      (*((volatile u32 *)(Timer_3  +  GPTMTBPV    )))
#define  timer3_GPTMPP        (*((volatile u32 *)(Timer_3  +  GPTMPP      )))


/*timer4 Registers*/
#define  timer4_GPTMCFG       (*((volatile u32 *)(Timer_4  +  GPTMCFG     )))
#define  timer4_GPTMTAMR      (*((volatile u32 *)(Timer_4  +  GPTMTAMR    )))
#define  timer4_GPTMTBMR      (*((volatile u32 *)(Timer_4  +  GPTMTBMR    )))
#define  timer4_GPTMCTL       (*((volatile u32 *)(Timer_4  +  GPTMCTL     )))
#define  timer4_GPTMSYNC      (*((volatile u32 *)(Timer_4  +  GPTMSYNC    )))
#define  timer4_GPTMIMR       (*((volatile u32 *)(Timer_4  +  GPTMIMR     )))
#define  timer4_GPTMRIS       (*((volatile u32 *)(Timer_4  +  GPTMRIS     )))
#define  timer4_GPTMMIS       (*((volatile u32 *)(Timer_4  +  GPTMMIS     )))
#define  timer4_GPTMICR       (*((volatile u32 *)(Timer_4  +  GPTMICR     )))
#define  timer4_GPTMTAILR     (*((volatile u32 *)(Timer_4  +  GPTMTAILR   )))
#define  timer4_GPTMTBILR     (*((volatile u32 *)(Timer_4  +  GPTMTBILR   )))
#define  timer4_GPTMTAMATCHR  (*((volatile u32 *)(Timer_4  +  GPTMTAMATCHR)))
#define  timer4_GPTMTBMATCHR  (*((volatile u32 *)(Timer_4  +  GPTMTBMATCHR)))
#define  timer4_GPTMTAPR      (*((volatile u32 *)(Timer_4  +  GPTMTAPR    )))
#define  timer4_GPTMTBPR      (*((volatile u32 *)(Timer_4  +  GPTMTBPR    )))
#define  timer4_GPTMTAPMR     (*((volatile u32 *)(Timer_4  +  GPTMTAPMR   )))
#define  timer4_GPTMTBPMR     (*((volatile u32 *)(Timer_4  +  GPTMTBPMR   )))
#define  timer4_GPTMTAR       (*((volatile u32 *)(Timer_4  +  GPTMTAR     )))
#define  timer4_GPTMTBR       (*((volatile u32 *)(Timer_4  +  GPTMTBR     )))
#define  timer4_GPTMTAV       (*((volatile u32 *)(Timer_4  +  GPTMTAV     )))
#define  timer4_GPTMTBV       (*((volatile u32 *)(Timer_4  +  GPTMTBV     )))
#define  timer4_GPTMRTCPD     (*((volatile u32 *)(Timer_4  +  GPTMRTCPD   )))
#define  timer4_GPTMTAPS      (*((volatile u32 *)(Timer_4  +  GPTMTAPS    )))
#define  timer4_GPTMTBPS      (*((volatile u32 *)(Timer_4  +  GPTMTBPS    )))
#define  timer4_GPTMTAPV      (*((volatile u32 *)(Timer_4  +  GPTMTAPV    )))
#define  timer4_GPTMTBPV      (*((volatile u32 *)(Timer_4  +  GPTMTBPV    )))
#define  timer4_GPTMPP        (*((volatile u32 *)(Timer_4  +  GPTMPP      )))


/*timer5 Registers*/
#define  timer5_GPTMCFG       (*((volatile u32 *)(Timer_5  +  GPTMCFG     )))
#define  timer5_GPTMTAMR      (*((volatile u32 *)(Timer_5  +  GPTMTAMR    )))
#define  timer5_GPTMTBMR      (*((volatile u32 *)(Timer_5  +  GPTMTBMR    )))
#define  timer5_GPTMCTL       (*((volatile u32 *)(Timer_5  +  GPTMCTL     )))
#define  timer5_GPTMSYNC      (*((volatile u32 *)(Timer_5  +  GPTMSYNC    )))
#define  timer5_GPTMIMR       (*((volatile u32 *)(Timer_5  +  GPTMIMR     )))
#define  timer5_GPTMRIS       (*((volatile u32 *)(Timer_5  +  GPTMRIS     )))
#define  timer5_GPTMMIS       (*((volatile u32 *)(Timer_5  +  GPTMMIS     )))
#define  timer5_GPTMICR       (*((volatile u32 *)(Timer_5  +  GPTMICR     )))
#define  timer5_GPTMTAILR     (*((volatile u32 *)(Timer_5  +  GPTMTAILR   )))
#define  timer5_GPTMTBILR     (*((volatile u32 *)(Timer_5  +  GPTMTBILR   )))
#define  timer5_GPTMTAMATCHR  (*((volatile u32 *)(Timer_5  +  GPTMTAMATCHR)))
#define  timer5_GPTMTBMATCHR  (*((volatile u32 *)(Timer_5  +  GPTMTBMATCHR)))
#define  timer5_GPTMTAPR      (*((volatile u32 *)(Timer_5  +  GPTMTAPR    )))
#define  timer5_GPTMTBPR      (*((volatile u32 *)(Timer_5  +  GPTMTBPR    )))
#define  timer5_GPTMTAPMR     (*((volatile u32 *)(Timer_5  +  GPTMTAPMR   )))
#define  timer5_GPTMTBPMR     (*((volatile u32 *)(Timer_5  +  GPTMTBPMR   )))
#define  timer5_GPTMTAR       (*((volatile u32 *)(Timer_5  +  GPTMTAR     )))
#define  timer5_GPTMTBR       (*((volatile u32 *)(Timer_5  +  GPTMTBR     )))
#define  timer5_GPTMTAV       (*((volatile u32 *)(Timer_5  +  GPTMTAV     )))
#define  timer5_GPTMTBV       (*((volatile u32 *)(Timer_5  +  GPTMTBV     )))
#define  timer5_GPTMRTCPD     (*((volatile u32 *)(Timer_5  +  GPTMRTCPD   )))
#define  timer5_GPTMTAPS      (*((volatile u32 *)(Timer_5  +  GPTMTAPS    )))
#define  timer5_GPTMTBPS      (*((volatile u32 *)(Timer_5  +  GPTMTBPS    )))
#define  timer5_GPTMTAPV      (*((volatile u32 *)(Timer_5  +  GPTMTAPV    )))
#define  timer5_GPTMTBPV      (*((volatile u32 *)(Timer_5  +  GPTMTBPV    )))
#define  timer5_GPTMPP        (*((volatile u32 *)(Timer_5  +  GPTMPP      )))

/**************************************************************************************************
 *                                     Common Macros for SRC
 *************************************************************************************************/

#define SCR_RCGCTIMER    *((u32 *)0x400FE604)  /*16/32-BitGeneral-Purpose Timer RunMode ClockGating control*/



#endif
