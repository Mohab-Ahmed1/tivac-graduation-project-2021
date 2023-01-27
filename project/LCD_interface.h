 /******************************************************************************
 *Author      : Graduation project 2021
 *Date        : 10 Jan 2021
 *Version     : V01
 *******************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LCD_sendCommand(u8 command);
void LCD_displayCharacter(u8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str);
void LCD_goToRowColumn(u8 row,u8 col);
void LCD_intgerToString(int data);
void delay_Microsecond(u32 time);



#endif /* LCD_INTERFACE_H_ */
