/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 9 May 2021
Version     : V01
 *****************************************************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Data_Type.h"
#include "BIT_MATH.h"

#include "GPS_interface.h"
#include "UART_interface.h"

//$GPRMC,200751.00,A,2758.612,N,08210.515,E,9.879,105.80,230394,,,A*6C
void readGPS(void)
{
    u8 i=0,index;
    char array[100],GPS_Parts[10][20],*token,latitudeResult[10],longitudeResult[10];
    const char comma[2] = ",";
    char c0;
    float latitude=0.0,longitude=0.0,seconds=0.0,result=0.0,minutes=0.0;
    u8 degrees;

    UART_sendString(UART_0,"\r\n");
    c0=UART_ReadData(UART_5);
    if(c0=='$')
    {
        //UART_SendData(UART_0,c0);
        u8 c1=UART_ReadData(UART_5);                    /*read the data from the GPS*/
        //UART_SendData(UART_0,c1);
        if(c1=='G')
        {
            u8 c2=UART_ReadData(UART_5);                    /*read the data from the GPS*/
            //UART_SendData(UART_0,c2);
            if(c2=='P')
            {
                u8 c3=UART_ReadData(UART_5);                    /*read the data from the GPS*/
                //UART_SendData(UART_0,c3);
                if(c3=='R')
                {
                    u8 c4 =UART_ReadData(UART_5);                    /*read the data from the GPS*/
                    //UART_SendData(UART_0,c4);
                    if(c4=='M')
                    {
                        u8 c5=UART_ReadData(UART_5);                    /*read the data from the GPS*/
                        //UART_SendData(UART_0,c5);
                        if(c5=='C')
                        {
                            u8 c6=UART_ReadData(UART_5);                    /*read the data from the GPS*/
                            //UART_SendData(UART_0,c6);
                            if(c6==',')
                            {
                                UART_sendString(UART_0,"&GPRMC,");
                                u8 c7=UART_ReadData(UART_5);                    /*read the data from the GPS*/
                                // Assign data to the GPSValues Array
                                while(c7!='*')
                                {
                                    UART_SendData(UART_0,c7);
                                    array[i]=c7;
                                    c7=UART_ReadData(UART_5);
                                    i++;
                                }
                                /*function to divide the NEMA code into parts*/
                                index=0;
                                token = strtok(array, comma);
                                while( token != NULL )
                                {
                                    strcpy(GPS_Parts[index], token);
                                    token = strtok(NULL, comma);
                                    index++;
                                }

                                //check if the NEMA code is valid or not
                                if(strcmp(GPS_Parts[1],"A")==0)
                                {
                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"Valid");

                                    /*convert string into double*/
                                    latitude=string_to_double(GPS_Parts[4]);                       //good function

                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"pass");

                                    degrees=latitude/100;
                                    minutes=latitude-(double)(degrees*100);
                                    seconds=minutes/60.00;
                                    result=degrees+seconds;

                                    float_to_string(result,latitudeResult);
                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"pass again");

                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"Longitude = ");
                                    UART_sendString(UART_0,GPS_Parts[2]);

                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"Latitude = ");
                                    UART_sendString(UART_0,GPS_Parts[4]);

                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"Latitude value float = ");
                                    UART_sendString(UART_0,latitudeResult);

                                    /*convert string into double*/
                                    longitude=string_to_double(GPS_Parts[2]);                       //good function

                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"pass");

                                    degrees=longitude/100;
                                    minutes=longitude-(double)(degrees*100);
                                    seconds=minutes/60.00;
                                    result=degrees+seconds;

                                    float_to_string(result,longitudeResult);
                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"pass again");

                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"Longitude = ");
                                    UART_sendString(UART_0,GPS_Parts[2]);

                                    UART_sendString(UART_0,"\r\n");
                                    UART_sendString(UART_0,"Longitude value float = ");
                                    UART_sendString(UART_0,longitudeResult);



                                }
                                else if (strcmp(GPS_Parts[1],"V")==0)
                                {
                                    UART_sendString(UART_0,"InValid");
                                }
                                /*for (j=0;j<10;j++)
                                {
                                    UART_sendString(UART_0,GPS_Parts[j]);
                                }
                                 */
                                //UART_sendString(UART_0,"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
                                //UART_sendString(UART_0,GPS_Parts[1]);
                            }
                        }
                    }
                }
            }
        }
    }
}


int n_tu(int number, int count)
{
    int result = 1;
    while((count--) > 0)
    {
        result *= number;
    }

    return result;
}


void float_to_string(float f, char r[])
{
    long long int length, length2, i, number, position, sign;
    float number2;

    sign = -1;   // -1 == positive number
    if (f < 0)
    {
        sign = '-';
        f *= -1;
    }

    number2 = f;
    number = f;
    length = 0;  // Size of decimal part
    length2 = 0; // Size of tenth

    // Calculate length2 tenth part
    while( (number2 - (float)number) != 0.0 && !((number2 - (float)number) < 0.0) )
    {
        number2 = f * (n_tu(10.0, length2 + 1));
        number = number2;

        length2++;
    }

    // Calculate length decimal part
    for (length = (f > 1) ? 0 : 1; f > 1; length++)
        f /= 10;

    position = length;
    length = length + 1 + length2;
    number = number2;
    if (sign == '-')
    {
        length++;
        position++;
    }

    for (i = length; i >= 0 ; i--)
    {
        if (i == (length))
            r[i] = '\0';
        else if(i == (position))
            r[i] = '.';
        else if(sign == '-' && i == 0)
            r[i] = '-';
        else
        {
            r[i] = (number % 10) + '0';
            number /=10;
        }
    }
}

/*function to convert string to double*/
double string_to_double(const char* s)
{    //definition
    double rez = 0, fact = 1;
    int point_seen,d;
    if (*s == '-'){
        s++;
        fact = -1;
    };
    for (point_seen = 0; *s; s++){
        if (*s == '.'){
            point_seen = 1;
            continue;
        };
        d = *s - '0';
        if (d >= 0 && d <= 9){
            if (point_seen) fact /= 10.0f;
            rez = rez * 10.0f + (float)d;
        };
    };
    return rez * fact;
}
