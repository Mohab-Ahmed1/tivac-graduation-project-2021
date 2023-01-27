 /******************************************************************************
 *Author      : Graduation project 2021
 *Date        : 10 Jan 2021
 *Version     : V01
 *Description : this file contains the configuration of the LCD Control and data pins
 *******************************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* LCD Data bits mode configuration */
#define DATA_BITS_MODE     4

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

#undef UPPER_PORT_PINS         /* Use the lower 4-bits in the data port */

#define PA2   2
#define PA3   3
#define PA4   4
/* LCD HW Pins */
#define RS PA2
#define RW PA3
#define E  PA4
#define LCD_CTRL_PORT          DATAPORT_A
#define LCD_CTRL_PORT_DIR      DIRPORT_A
#define LCD_DATA_PORT          DATAPORT_F
#define LCD_DATA_PORT_DIR      DIRPORT_F


#endif /* LCD_CONFIG_H_ */
