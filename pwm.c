//------------------------------------------------------------------------------
//
//  Description: This file contains the PWM code
//
//
//  Lauren Crawford
//  03/04/2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

//globals
extern volatile unsigned int ADC_Left_Detect;
extern volatile unsigned int ADC_Right_Detect;

//functions

void right_forward_pwm(int speed){
//RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM OFF
RIGHT_FORWARD_SPEED = speed; // P6.0 Right Forward PWM ON amount
}

void left_forward_pwm(int speed){
//LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.1 Left Forward PWM OFF
LEFT_FORWARD_SPEED = speed; // P6.1 Left Forward PWM ON amount
}

void right_reverse_pwm(int speed){
//RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM OFF
RIGHT_REVERSE_SPEED = speed; // P6.2 Right Reverse PWM ON amount
}

void left_reverse_pwm(int speed){
//LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM OFF
LEFT_REVERSE_SPEED = speed; // P6.3 Left Reverse PWM ON amount
}

void stop_wheels_pwm(void){
  RIGHT_FORWARD_SPEED = WHEEL_OFF;
  LEFT_FORWARD_SPEED = WHEEL_OFF;
  RIGHT_REVERSE_SPEED = WHEEL_OFF;
  LEFT_REVERSE_SPEED = WHEEL_OFF;
}
