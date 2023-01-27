/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 5 Jan 2021
Version     : V01
Description : this file contains the GPIO Register addresses and SRC of the GPIO
              this file is private means that it wont accessed by another peripheral except GPIO

*****************************************************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/**************************************************************************************************
 *                                     Common Macros
 *************************************************************************************************/


/*  APB GPIO port's base address */
#define GPIO_PortA_Base_Address       0x40004000
#define GPIO_PortB_Base_Address       0x40005000
#define GPIO_PortC_Base_Address       0x40006000
#define GPIO_PortD_Base_Address       0x40007000
#define GPIO_PortE_Base_Address       0x40024000
#define GPIO_PortF_Base_Address       0x40025000

/*  AHB GPIO port's base address */
#define GPIO_HPortA_Base_Address       0x40058000
#define GPIO_HPortB_Base_Address       0x40059000
#define GPIO_HPortC_Base_Address       0x4005A000
#define GPIO_HPortD_Base_Address       0x4005B000
#define GPIO_HPortE_Base_Address       0x4005C000
#define GPIO_HPortF_Base_Address       0x4005D000

/*  value to unlock ports       */
#define __Unlock_Register       0x4C4F434B

/* Offset Address For every Registers   */
#define GPIO_DATA                     0x3FC
#define GPIO_DIR                      0x400
#define GPIO_IS                       0x404
#define GPIO_IBE                      0x408
#define GPIO_IEV                      0x40C
#define GPIO_IM                       0x410
#define GPIO_RIS                      0x414
#define GPIO_MIS                      0x418
#define GPIO_ICR                      0x41C
#define GPIO_AFSEL                    0x420
#define GPIO_DR2R                     0x500
#define GPIO_DR4R                     0x504
#define GPIO_DR8R                     0x508
#define GPIO_ODR                      0x50C
#define GPIO_PUR                      0x510
#define GPIO_PDR                      0x514
#define GPIO_SLR                      0x518
#define GPIO_DEN                      0x51C
#define GPIO_LOCK                     0x520
#define GPIO_CR                       0x524
#define GPIO_AMSEL                    0x528
#define GPIO_PCTL                     0x52C
#define GPIO_ADCCTL                   0x530
#define GPIO_DMACTL                   0x534
#define GPIO_PeriphID4                0xFD0
#define GPIO_PeriphID5                0xFD4
#define GPIO_PeriphID6                0xFD8
#define GPIO_PeriphID7                0xFDC
#define GPIO_PeriphID0                0xFE0
#define GPIO_PeriphID1                0xFE4
#define GPIO_PeriphID2                0xFE8
#define GPIO_PeriphID3                0xFEC
#define GPIO_PCellID0                 0xFF0
#define GPIO_PCellID1                 0xFF4
#define GPIO_PCellID2                 0xFF8
#define GPIO_PCellID3                 0xFFC

/*****************************Registers definitions for APB *************************/

/* DATA DIRECTION Register      (GPIODIR) */
#define DIRPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_DIR)))
#define DIRPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_DIR)))
#define DIRPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_DIR)))
#define DIRPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_DIR)))
#define DIRPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_DIR)))
#define DIRPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_DIR)))

/* GPIO Data Register       (GPIODATA)  */
#define DATAPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_DATA)))
#define DATAPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_DATA)))
#define DATAPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_DATA)))
#define DATAPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_DATA)))
#define DATAPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_DATA)))
#define DATAPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_DATA)))

/* GPIO Interrupt Sense     (GPIOIS)  */
#define ISPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_IS)))
#define ISPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_IS)))
#define ISPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_IS)))
#define ISPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_IS)))
#define ISPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_IS)))
#define ISPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_IS)))

/* GPIO Interrupt Both Edges    (GPIOIBE) */
#define IBEPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_IBE)))
#define IBEPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_IBE)))
#define IBEPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_IBE)))
#define IBEPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_IBE)))
#define IBEPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_IBE)))
#define IBEPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_IBE)))

/* GPIO Interrupt Event      (GPIOIEV) */
#define IEVPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_IEV)))
#define IEVPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_IEV)))
#define IEVPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_IEV)))
#define IEVPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_IEV)))
#define IEVPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_IEV)))
#define IEVPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_IEV)))

/* GPIO Interrupt Mask     (GPIOIM)  */
#define IMPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_IM)))
#define IMPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_IM)))
#define IMPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_IM)))
#define IMPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_IM)))
#define IMPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_IM)))
#define IMPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_IM)))

/* GPIO Raw Interrupt Status  (GPIORIS)  */
#define RISPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_RIS)))
#define RISPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_RIS)))
#define RISPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_RIS)))
#define RISPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_RIS)))
#define RISPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_RIS)))
#define RISPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_RIS)))

/* GPIO Masked Interrupt Status  (GPIOMIS) */
#define MISPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_MIS)))
#define MISPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_MIS)))
#define MISPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_MIS)))
#define MISPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_MIS)))
#define MISPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_MIS)))
#define MISPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_MIS)))

/* GPIO Interrupt Clear   (GPIOICR)  */
#define ICRPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_ICR)))
#define ICRPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_ICR)))
#define ICRPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_ICR)))
#define ICRPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_ICR)))
#define ICRPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_ICR)))
#define ICRPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_ICR)))

/* GPIO Pull-Up Select   (GPIOPUR)  */
#define PURPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_PUR)))
#define PURPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_PUR)))
#define PURPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_PUR)))
#define PURPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_PUR)))
#define PURPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_PUR)))
#define PURPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_PUR)))

/* GPIO Pull-Down Select   (GPIOPDR)  */
#define PDRPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_PDR)))
#define PDRPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_PDR)))
#define PDRPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_PDR)))
#define PDRPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_PDR)))
#define PDRPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_PDR)))
#define PDRPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_PDR)))

/*  GPIO Lock    (GPIOLOCK)   */
#define LOCKPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_LOCK)))
#define LOCKPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_LOCK)))
#define LOCKPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_LOCK)))
#define LOCKPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_LOCK)))
#define LOCKPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_LOCK)))
#define LOCKPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_LOCK)))

/*  Commit Register     **0x524**   (GPIOCR)   */
#define CRPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_CR)))
#define CRPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_CR)))
#define CRPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_CR)))
#define CRPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_CR)))
#define CRPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_CR)))
#define CRPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_CR)))


/*   GPIO Alternate Function Select  (GPIOAFSEL)  */
#define AFSELPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_AFSEL)))
#define AFSELPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_AFSEL)))
#define AFSELPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_AFSEL)))
#define AFSELPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_AFSEL)))
#define AFSELPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_AFSEL)))
#define AFSELPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_AFSEL)))

/*  GPIO Digital Enable    (GPIODEN)   */
#define DENPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_DEN)))
#define DENPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_DEN)))
#define DENPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_DEN)))
#define DENPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_DEN)))
#define DENPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_DEN)))
#define DENPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_DEN)))

/*  GPIO PCTL   (GPIODEN)   */
#define PCTLPORT_A (*((volatile u32*)(GPIO_PortA_Base_Address + GPIO_PCTL)))
#define PCTLPORT_B (*((volatile u32*)(GPIO_PortB_Base_Address + GPIO_PCTL)))
#define PCTLPORT_C (*((volatile u32*)(GPIO_PortC_Base_Address + GPIO_PCTL)))
#define PCTLPORT_D (*((volatile u32*)(GPIO_PortD_Base_Address + GPIO_PCTL)))
#define PCTLPORT_E (*((volatile u32*)(GPIO_PortE_Base_Address + GPIO_PCTL)))
#define PCTLPORT_F (*((volatile u32*)(GPIO_PortF_Base_Address + GPIO_PCTL)))


/***************************** Registers definitions for AHB *************************/
/* DATA DIRECTION Register      (GPIODIR) */
#define HDIRPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_DIR)))
#define HDIRPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_DIR)))
#define HDIRPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_DIR)))
#define HDIRPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_DIR)))
#define HDIRPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_DIR)))
#define HDIRPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_DIR)))

/* GPIO Data Register       (GPIODATA)  */
#define HDATAPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_DATA)))
#define HDATAPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_DATA)))
#define HDATAPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_DATA)))
#define HDATAPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_DATA)))
#define HDATAPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_DATA)))
#define HDATAPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_DATA)))

/* GPIO Interrupt Sense     (GPIOIS)  */
#define HISPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_IS)))
#define HISPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_IS)))
#define HISPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_IS)))
#define HISPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_IS)))
#define HISPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_IS)))
#define HISPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_IS)))

/* GPIO Interrupt Both Edges    (GPIOIBE) */
#define HIBEPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_IBE)))
#define HIBEPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_IBE)))
#define HIBEPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_IBE)))
#define HIBEPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_IBE)))
#define HIBEPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_IBE)))
#define HIBEPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_IBE)))

/* GPIO Interrupt Event      (GPIOIEV) */
#define HIEVPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_IEV)))
#define HIEVPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_IEV)))
#define HIEVPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_IEV)))
#define HIEVPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_IEV)))
#define HIEVPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_IEV)))
#define HIEVPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_IEV)))

/* GPIO Interrupt Mask     (GPIOIM)  */
#define HIMPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_IM)))
#define HIMPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_IM)))
#define HIMPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_IM)))
#define HIMPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_IM)))
#define HIMPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_IM)))
#define HIMPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_IM)))

/* GPIO Raw Interrupt Status  (GPIORIS)  */
#define HRISPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_RIS)))
#define HRISPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_RIS)))
#define HRISPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_RIS)))
#define HRISPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_RIS)))
#define HRISPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_RIS)))
#define HRISPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_RIS)))

/* GPIO Masked Interrupt Status  (GPIOMIS) */
#define HMISPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_MIS)))
#define HMISPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_MIS)))
#define HMISPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_MIS)))
#define HMISPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_MIS)))
#define HMISPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_MIS)))
#define HMISPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_MIS)))

/* GPIO Interrupt Clear   (GPIOICR)  */
#define HICRPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_ICR)))
#define HICRPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_ICR)))
#define HICRPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_ICR)))
#define HICRPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_ICR)))
#define HICRPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_ICR)))
#define HICRPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_ICR)))

/* GPIO Pull-Up Select   (GPIOPUR)  */
#define HPURPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_PUR)))
#define HPURPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_PUR)))
#define HPURPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_PUR)))
#define HPURPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_PUR)))
#define HPURPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_PUR)))
#define HPURPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_PUR)))

/* GPIO Pull-Down Select   (GPIOPDR)  */
#define HPDRPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_PDR)))
#define HPDRPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_PDR)))
#define HPDRPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_PDR)))
#define HPDRPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_PDR)))
#define HPDRPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_PDR)))
#define HPDRPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_PDR)))

/*  GPIO Lock    (GPIOLOCK)   */
#define HLOCKPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_LOCK)))
#define HLOCKPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_LOCK)))
#define HLOCKPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_LOCK)))
#define HLOCKPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_LOCK)))
#define HLOCKPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_LOCK)))
#define HLOCKPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_LOCK)))

/*  Commit Register     **0x524**   (GPIOCR)   */
#define HCRPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_CR)))
#define HCRPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_CR)))
#define HCRPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_CR)))
#define HCRPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_CR)))
#define HCRPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_CR)))
#define HCRPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_CR)))


/*   GPIO Alternate Function Select  (GPIOAFSEL)  */
#define HAFSELPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_AFSEL)))
#define HAFSELPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_AFSEL)))
#define HAFSELPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_AFSEL)))
#define HAFSELPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_AFSEL)))
#define HAFSELPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_AFSEL)))
#define HAFSELPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_AFSEL)))

/*  GPIO Digital Enable    (GPIODEN)   */
#define HDENPORT_A (*((volatile u32*)(GPIO_HPortA_Base_Address + GPIO_DEN)))
#define HDENPORT_B (*((volatile u32*)(GPIO_HPortB_Base_Address + GPIO_DEN)))
#define HDENPORT_C (*((volatile u32*)(GPIO_HPortC_Base_Address + GPIO_DEN)))
#define HDENPORT_D (*((volatile u32*)(GPIO_HPortD_Base_Address + GPIO_DEN)))
#define HDENPORT_E (*((volatile u32*)(GPIO_HPortE_Base_Address + GPIO_DEN)))
#define HDENPORT_F (*((volatile u32*)(GPIO_HPortF_Base_Address + GPIO_DEN)))

/**************************************************************************************************
 *                                     Common Macros for SRC
 *************************************************************************************************/

#define SCR_IMC          *((u32 *)0x400FE054)  /*control row interrupt*/
#define SCR_RCC          *((u32 *)0x400FE060)  /*The bits in this register configure the system clock and oscillators.*/
#define SCR_GPIOHBCTL    *((u32 *)0x400FE06C)  /*GPIO High-Performance Bus Control*/
#define SCR_RCGCGPIO     *((u32 *)0x400FE608)  /*General-Purpose Input/Output Run Mode Clock Gating control*/
#define SCR_RCGC1        *((u32 *)0x400FE104)  /*enable the Alternative Function for the pins*/
#define SCR_RCGC2        *((u32 *)0x400FE108)  /*enable the IO pins*/


#endif /* GPIO_PRIVATE_H_ */
