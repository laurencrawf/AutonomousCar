//------------------------------------------------------------------------------
//
//  Description: This file contains the Interrupt Ports
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

extern volatile unsigned int UCA0_index;
extern volatile unsigned int UCA1_index;
extern char test_command[SMALL_RING_SIZE] ;
extern int done;
extern int i, j;
extern char processbuffer[ARR2][PBSIZE];
extern char newchar;

extern char display_line[HEIGHTFOUR][ELEVENTH_CHARACTER];
extern char *display[HEIGHTFOUR];
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;

extern volatile unsigned int debounce_countSW1 ;
extern volatile unsigned int debounce_countSW2;
extern volatile unsigned int SW1_pressed;
extern volatile unsigned int SW2_pressed;
volatile unsigned int SW1_debounce_in_progress;
volatile unsigned int SW2_debounce_in_progress;

extern volatile unsigned int switch_case ;
extern char processbuffer[ARR2][PBSIZE];
volatile unsigned int baudrate = TRUE;
volatile unsigned int transmitflag = FALSE;

#pragma vector=PORT4_VECTOR
__interrupt void switchP4_interrupt(void){
// Switch 1
if (P4IFG & SW1) {
  SW1_pressed = TRUE;
  SW1_debounce_in_progress = TRUE;
  debounce_countSW1 = RESET_STATE;
  
  P4IE &= ~SW1;
  TB0CCTL0 &= ~CCIE;
  TB0CCTL1 |= CCIE;
  
  P4IFG &= ~SW1; // IFG SW1 cleared    
  
  transmitflag = TRUE;
      test_command[ARR0] = processbuffer[FIRST][ARR0];
    test_command[ARR1] = processbuffer[FIRST][ARR1];    
    test_command[ARR2] = processbuffer[FIRST][ARR2];
    test_command[ARR3] = processbuffer[FIRST][ARR3];
    test_command[ARR4] = processbuffer[FIRST][ARR4];
    test_command[ARR5] = processbuffer[FIRST][ARR5];
    test_command[ARR6] = processbuffer[FIRST][ARR6];
    test_command[ARR7] = processbuffer[FIRST][ARR7];
    test_command[ARR8] = processbuffer[FIRST][ARR8];
    test_command[ARR9] = processbuffer[FIRST][ARR9];
  UCA0_index = RESET_STATE;
  UCA0IE |= UCTXIE; // Enable RX interrupt
  UCA0TXBUF = test_command[ARR0];
  }
}
#pragma vector=PORT2_VECTOR
__interrupt void switchP2_interrupt(void){
// Switch 2
if (P2IFG & SW2) {
  
  SW2_pressed=TRUE;
  SW2_debounce_in_progress = TRUE;
  debounce_countSW2 = RESET_STATE;
  
  P2IE &= ~SW2;
  TB0CCTL0 &= ~CCIE;
  TB0CCTL1 |= CCIE; 
  
  P2IFG &= ~SW2; // IFG SW2 cleared 

  //serial
 switch(baudrate){
  case FALSE:
    Init_Serial_UCA0(FALSE);
    strcpy(display_line[LINETWO],"  115200  ");
    update_string(display_line[LINETWO], LINETWO);
    baudrate = TRUE;
    break;
    
  case TRUE:
    Init_Serial_UCA0(TRUE);
    strcpy(display_line[LINETWO],"  460800  ");
    update_string(display_line[LINETWO], LINETWO);
    baudrate = FALSE;
    break;
  default:break;
  }

 /*   
  UCA0_index = 0;
  UCA0IE |= UCTXIE; // Enable RX interrupt
  UCA0TXBUF = test_command[0];
*/
}
}