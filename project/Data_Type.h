/****************************************************************************************************************
Author      : Graduation project 2021
Date        : 5 Jan 2021
Version     : V01
Description : rename the Data types.
*****************************************************************************************************************/

#ifndef DATA_TYPE_H_
#define DATA_TYPE_H_

/* Type definition of unsigned 8-bit integer,   0->255                                                    */
typedef unsigned char u8;

/* Type definition of unsigned 16-bit integer,  0->65535                                                  */
typedef unsigned short int u16;

/* Type definition of unsigned 32 bit integer,  0->4294967295                                             */
typedef unsigned long int u32;

/* Type definition of signed 8-bit integer,     -128,127                                                  */
typedef signed char s8;

/* Type definition of signed 16-bit integer,    -32768->32767                                             */
typedef signed short int s16;

/* Type definition of singed 32-bit integer,    -2147483648->2147483647                                   */
typedef signed long int s32;

/* Type definition of 32-bit float,             -2147483648->2147483647                                   */
typedef float f32;

/* Type definition of 64-bit,                   (-2^63)->((-2^63)-1)                                      */
typedef double f64;

/* Type definition of 64-bit,                   (-2^79)->((-2^79)-1)                                      */
typedef long double f80;



#endif /* DATA_TYPE_H_ */
