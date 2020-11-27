//------------------------------------------------------------------------------
// Description: This file containes the initial display conditions
// 1/27/2020
// Lauren Crawford
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//------------------------------------------------------------------------------

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

extern char display_line[HEIGHTFOUR][ELEVENTH_CHARACTER];
extern volatile unsigned char update_display;
extern char *display[HEIGHTFOUR];
extern volatile unsigned int update_display_count;

void Init_Conditions(void){
//------------------------------------------------------------------------------
  int i;

  for(i=START_INTEGER;i<END_INTEGER;i++){
    display_line[LINEZERO][i] = RESET_STATE;
    display_line[LINEONE][i] = RESET_STATE;
    display_line[LINETWO][i] = RESET_STATE;
    display_line[LINETHREE][i] = RESET_STATE;
  }
  display_line[LINEZERO][TENTH_CHARACTER] = RESET_STATE;
  display_line[LINEONE][TENTH_CHARACTER] = RESET_STATE;
  display_line[LINETWO][TENTH_CHARACTER] = RESET_STATE;
  display_line[LINETHREE][TENTH_CHARACTER] = RESET_STATE;

  display[LINEZERO] = &display_line[LINEZERO][LINEZERO];
  display[LINEONE] = &display_line[LINEONE][LINEZERO];
  display[LINETWO] = &display_line[LINETWO][LINEZERO];
  display[LINETHREE] = &display_line[LINETHREE][LINEZERO];
  update_display = RESET_STATE;
  update_display_count = RESET_STATE;
// Interrupts are disabled by default, enable them.
  enable_interrupts();
//------------------------------------------------------------------------------
}
