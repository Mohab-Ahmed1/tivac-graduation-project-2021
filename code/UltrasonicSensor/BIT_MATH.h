/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 29 JUL 2021
Version     : V01
Description : Do Bit Wise Operation (Set bit , clear bit , get bit value , toggle bit)
*****************************************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)    VAR |=  (1<<BIT)
#define CLEAR_BIT(VAR,BIT)  VAR &= ~(1<<BIT)
#define GET_BIT(VAR,BIT)    ((VAR >> BIT)&1)
#define TOG_BIT(VAR,BIT)    VAR ^=  (1<<BIT)

#endif
