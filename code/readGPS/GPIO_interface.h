/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 5 Jan 2021
Version     : V01
Description : file to contain the prototypes of the common files.

*****************************************************************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*************************************************************************************************
 *
 *                                    Common Macros
 *
 *************************************************************************************************/

#define PORTA            0x00
#define PORTB            0x01
#define PORTC            0x02
#define PORTD            0x03
#define PORTE            0x04
#define PORTF            0x05

#define GPIO_HIGH        0x01
#define GPIO_LOW         0x00

#define PIN0             0x00
#define PIN1             0x01
#define PIN2             0x02
#define PIN3             0x03
#define PIN4             0x04
#define PIN5             0x05
#define PIN6             0x06
#define PIN7             0x07

#define INPUT_PORT       0x00
#define OUTPUT_PORT      0xFF
#define INPUT_PIN        0x0
#define OUTPUT_PIN       0x1

#define Alternative     0xFF
#define GPIO_PORT       0x00

#define TIMER0_ALTERNATE_FUNCTION 7

/*************************************************************************************************
 *
 *                                    Functions Prototype
 *
 *************************************************************************************************/
/*to initialize the port clock*/
void Port_Init (u8 port_number);
/*to set the port direction (input , output)*/
void Set_PORT_direction(u8 port_number,u8 port_direction);
/*to set the pin direction (input , output)*/
void Set_Pin_direction(u8 port_number,u8 pin_number,u8 pin_direction);
/*to set a certain value to the port*/
void Set_PORT_Value(u8 port_number,u32 port_data);
/*to set the pin value (high , low)*/
void Set_pin_value (u8 port_number,u8 pin_number,u8 pin_value);
/*to read the pin value*/
//u8 Get_pin_value (u8 port_number,u8 pin_number);
/*to enable the alternative function for a specific pin*/
void Set_Pin_alternative(u8 port_number,u8 pin_number,u8 Alternaative_function);

#endif /* GPIO_INTERFACE_H_ */
