//------------------------------------------------------------------------------
//
//  Description: This file contains the Interrupt Timers 
//
//
//  Lauren Crawford
//  02/21/2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

extern volatile unsigned int display_counter = RESET_STATE;
extern volatile unsigned int status_counter = RESET_STATE; 
volatile unsigned int debounce_countSW1 = RESET_STATE;
volatile unsigned int debounce_countSW2 = RESET_STATE;
volatile unsigned int SW1_pressed;
volatile unsigned int SW2_pressed;
extern volatile unsigned int SW1_debounce_in_progress;
extern volatile unsigned int SW2_debounce_in_progress;

extern char display_line[HEIGHTFOUR][ELEVENTH_CHARACTER];
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
volatile unsigned int serial_counter = FALSE;
volatile unsigned int IOT_counter = FALSE;
volatile unsigned int project7_counter = RESET_STATE;
volatile unsigned int num8_counter = RESET_STATE;

#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
    display_counter++;
    status_counter++;
    serial_counter++;
    IOT_counter++;
    num8_counter++;
    TB0CCR0 += TB0CCR0_INTERVAL; // Add Offset to TBCCR0
    
   if(display_counter == COUNT40){
    project7_counter++;
    update_display = TRUE;
    display_changed = TRUE;
    display_counter = RESET_STATE;
}
  }
   

#pragma vector=TIMER0_B1_VECTOR
__interrupt void TIMER0_B1_ISR(void){
//----------------------------------------------------------------------------
// TimerB0 1-2, Overflow Interrupt Vector (TBIV) handler
//----------------------------------------------------------------------------
switch(__even_in_range(TB0IV,COUNT14)){
case RESET_STATE: break; // No interrupt
case SW1CASE: // CCR1  used
//...... Add What you need happen in the interrupt ......
//TB0CCR1 += TB0CCR1_INTERVAL; // Add Offset to TBCCR1

debounce_countSW2++;
  if(debounce_countSW2 == COUNTTEN){
    P2IE |= SW2;
    P2IFG &= ~SW2;
    TB0CCTL0 |= CCIE;
    TB0CCTL1 &= ~CCIE;
   
    SW2_pressed = RESET_STATE;
    debounce_countSW2 = RESET_STATE;
  }
  TB0CCR1 += TB0CCR1_INTERVAL; // Add Offset to TBCCR1

debounce_countSW1++;
  if(debounce_countSW1 == COUNTTEN){
    P4IE |= SW1;
    P4IFG &= ~SW1;
    TB0CCTL0 |= CCIE;
    TB0CCTL1 &= ~CCIE;
  
    SW1_pressed = RESET_STATE;
    debounce_countSW1 = RESET_STATE;
  }


break;

case SW2CASE: // CCR2 not used
//...... Add What you need happen in the interrupt ......
TB0CCR2 += TB0CCR2_INTERVAL; // Add Offset to TBCCR2

break;

case OVERFLOWCASE: // overflow
//...... Add What you need happen in the interrupt ......
break;
default: break;
}
//----------------------------------------------------------------------------
}

void Init_Timer_B3(void) {
//------------------------------------------------------------------------------
// SMCLK source, up count mode, PWM Right Side
// TB3.1 P6.0 R_FORWARD
// TB3.2 P6.1 L_FORWARD
// TB3.3 P6.2 R_REVERSE
// TB3.4 P6.3 L_REVERSE
//------------------------------------------------------------------------------
 TB3CTL = TBSSEL__SMCLK; // SMCLK
 TB3CTL |= MC__UP; // Up Mode
 TB3CTL |= TBCLR; // Clear TAR
 TB3CCR0 = WHEEL_PERIOD; // PWM Period
 TB3CCTL1 = OUTMOD_7; // CCR1 reset/set
 RIGHT_FORWARD_SPEED = WHEEL_OFF; // P6.0 Right Forward PWM duty cycle
 TB3CCTL2 = OUTMOD_7; // CCR2 reset/set
 LEFT_FORWARD_SPEED = WHEEL_OFF; // P6.1 Left Forward PWM duty cycle
 TB3CCTL3 = OUTMOD_7; // CCR3 reset/set
 RIGHT_REVERSE_SPEED = WHEEL_OFF; // P6.2 Right Reverse PWM duty cycle
 TB3CCTL4 = OUTMOD_7; // CCR4 reset/set
 LEFT_REVERSE_SPEED = WHEEL_OFF; // P6.3 Left Reverse PWM duty cycle
//------------------------------------------------------------------------------
}