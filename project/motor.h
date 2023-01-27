/*
 * motor.h
 *
 *  Created on: Jul 23, 2021
 *      Author: mehob
 */

#ifndef MOTOR_H_
#define MOTOR_H_


#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "driverlib/pwm.h"


/* Function Prototype */
void forword  (void);
void backword  (void);
void TurnRight  (void);
void Turnleft  (void);
void stop  (void);
void move_car(void);




#endif /* MOTOR_H_ */
