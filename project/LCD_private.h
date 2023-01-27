 /******************************************************************************
 *Author      : Graduation project 2021
 *Date        : 10 Jan 2021
 *Version     : V01
 *Description : this file contain the private functions prototype of the LCD and its commands
 *******************************************************************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

/*function to convert the integer to string*/
void itoa(int number, char string[]);
/*function to reverse the number out of the itoa function*/
void reverse_string(char string[]);

#endif /* LCD_PRIVATE_H_ */
