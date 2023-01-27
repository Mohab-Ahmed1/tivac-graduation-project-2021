/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 8 Jan 2021
Version     : V01
 *****************************************************************************************************************/

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_



u32 First_edge,Second_edge;
u32 Distance,TIME;
/********************************************************************************************
 *
 *                                    common Macros
 *
 ********************************************************************************************/

#define VOICE_SPEED_CM    34000
#define _16MHz_1clock     62e-9   // Value of 1clock cycle in nanoseconds for 16MHZ


/********************************************************************************************
 *
 *                                    functions Prototype
 *
 ********************************************************************************************/
u32 Measure_Distance(void);

#endif /* ULTRASONIC_INTERFACE_H_ */