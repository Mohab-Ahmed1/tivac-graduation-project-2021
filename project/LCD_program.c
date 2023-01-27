/******************************************************************************
 *Author      : Graduation project 2021
 *Date        : 10 Jan 2021
 *Version     : V01
 *Description : Source file for the LCD driver
 *******************************************************************************/
#include "Data_Type.h"
#include "BIT_MATH.h"
#include <string.h>               /*for the special function strlen*/

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

#define N 1000                      /*the delay value of the LCD send commands*/

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void LCD_init(void)
{
    LCD_CTRL_PORT_DIR |= (1<<E) | (1<<RS) | (1<<RW); /* Configure the control pins(E,RS,RW) as output pins */

#if (DATA_BITS_MODE == 4)
#ifdef UPPER_PORT_PINS
    LCD_DATA_PORT_DIR |= 0xF0; /* Configure the highest 4 bits of the data port as output pins */
#else
    LCD_DATA_PORT_DIR |= 0x0F; /* Configure the lowest 4 bits of the data port as output pins */
#endif
    LCD_sendCommand(FOUR_BITS_DATA_MODE); /* initialize LCD in 4-bit mode */
    LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
#elif (DATA_BITS_MODE == 8)
    LCD_DATA_PORT_DIR = 0xFF; /* Configure the data port as output port */
    LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
#endif

    LCD_sendCommand(CURSOR_ON); /* cursor off */
    LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_sendCommand(u8 command)
{
    CLEAR_BIT(LCD_CTRL_PORT,RS); /* Instruction Mode RS=0 */
    CLEAR_BIT(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
    delay_Microsecond(N); /* delay for processing Tas = 50ns */
    SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
    delay_Microsecond(N); /* delay for processing Tpw - Tdws = 190ns */
#if (DATA_BITS_MODE == 4)
    /* out the highest 4 bits of the required command to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
#else
    LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((command & 0xF0) >> 4);
#endif

    delay_Microsecond(N); /* delay for processing Tdsw = 100ns */
    CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
    delay_Microsecond(N); /* delay for processing Th = 13ns */
    SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
    delay_Microsecond(N); /* delay for processing Tpw - Tdws = 190ns */

    /* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((command & 0x0F) << 4);
#else
    LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (command & 0x0F);
#endif

    delay_Microsecond(N); /* delay for processing Tdsw = 100ns */
    CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
    delay_Microsecond(N); /* delay for processing Th = 13ns */
#elif (DATA_BITS_MODE == 8)
    LCD_DATA_PORT = command; /* out the required command to the data bus D0 --> D7 */
    delay_Microsecond(N); /* delay for processing Tdsw = 100ns */
    CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
    delay_Microsecond(N); /* delay for processing Th = 13ns */
#endif
}

void LCD_displayCharacter(u8 data)
{
    SET_BIT(LCD_CTRL_PORT,RS); /* Data Mode RS=1 */
    CLEAR_BIT(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
    delay_Microsecond(N); /* delay for processing Tas = 50ns */
    SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
    delay_Microsecond(N); /* delay for processing Tpw - Tdws = 190ns */
#if (DATA_BITS_MODE == 4)
    /* out the highest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0);
#else
    LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((data & 0xF0) >> 4);
#endif

    delay_Microsecond(N); /* delay for processing Tdsw = 100ns */
    CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
    delay_Microsecond(N); /* delay for processing Th = 13ns */
    SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
    delay_Microsecond(N);/* delay for processing Tpw - Tdws = 190ns */

    /* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
#ifdef UPPER_PORT_PINS
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F) << 4);
#else
    LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (data & 0x0F);
#endif

    delay_Microsecond(N); /* delay for processing Tdsw = 100ns */
    CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
    delay_Microsecond(N); /* delay for processing Th = 13ns */
#elif (DATA_BITS_MODE == 8)
    LCD_DATA_PORT = command; /* out the required command to the data bus D0 --> D7 */
    delay_Microsecond(N);/* delay for processing Tdsw = 100ns */
    CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
    delay_Microsecond(N); /* delay for processing Th = 13ns */
#endif
}


void LCD_displayString(const char *Str)
{
    u8 i = 0;
    while(Str[i] != '\0')
    {
        LCD_displayCharacter(Str[i]);
        i++;
    }
}

void LCD_goToRowColumn(u8 row,u8 col)
{
    u8 Address;

    /* first of all calculate the required address */
    switch(row)
    {
    case 0:
        Address=col;
        break;
    case 1:
        Address=col+0x40;
        break;
    case 2:
        Address=col+0x10;
        break;
    case 3:
        Address=col+0x50;
        break;
    }
    /* to write to a specific address in the LCD
     * we need to apply the corresponding command 0b10000000+Address */
    LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str)
{
    LCD_goToRowColumn(row,col); /* go to to the required LCD position */
    LCD_displayString(Str);     /* display the string */
}

void LCD_intgerToString(int data)
{
    char buff[16];   /* String to hold the ascii result */
    itoa(data,buff); /* 10 for decimal */
    LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
    LCD_sendCommand(CLEAR_COMMAND);            //clear display
}

void reverse_string(char string[])
{
    int i = 0, j;
    char temp;
    j = strlen(string) - 1;

    /* null will remained in the same place just start swapping the array element */
    while (i < j)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
}


void itoa(int number, char string[])
{
    int  i=0 ,sign;
    if ((sign = number) < 0)               /* record sign */
        number = -number;                  /* make n positive */
    do {                                   /* generate digits in reverse order */
        string[i++] = number % 10 + '0';   /* get next digit */
    } while ((number /= 10) > 0);          /* delete it */
    if (sign < 0)
        string[i++] = '-';
    string[i] = '\0';
    reverse_string(string);
}
