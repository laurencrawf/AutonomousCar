//------------------------------------------------------------------------------
//
//  Description: This file contains the conversion from HEX to BCD function
//
//
//  Lauren Crawford
//  02/28/2020
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

extern char display_line[HEIGHTFOUR][ELEVENTH_CHARACTER];
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;


// globals
char thousands;
char hundreds;
char tens;
char ones;

void HEXtoBCD_RIGHT(unsigned int value_passed){
  thousands = RESET_STATE;
  hundreds = RESET_STATE;
  tens = RESET_STATE;
  ones = RESET_STATE;
  if(value_passed >= thousand){
    value_passed = value_passed - thousand;
    thousands = one;
  }  
  while(value_passed >= hundred){
    value_passed = value_passed - hundred;
    hundreds = hundreds + one;
  }
  while(value_passed >= ten){
    value_passed = value_passed - ten;
    tens = tens + one;
  }
  while(value_passed >= one){
    value_passed = value_passed - one;
    ones = ones + one;
  }
  thousands |= offset;
  hundreds |= offset;
  tens |= offset;
  ones |= offset;
  
    display_line[LINETHREE][LINETHREE]= thousands;
    display_line[LINETHREE][HEIGHTFOUR] = hundreds;
    display_line[LINETHREE][HEIGHTFIVE] = tens;
    display_line[LINETHREE][HEIGHTSIX] = ones;
    update_string(display_line[LINETHREE], LINETHREE);
    
 }
void HEXtoBCD_LEFT(unsigned int value_passed){
  thousands = RESET_STATE;
  hundreds = RESET_STATE;
  tens = RESET_STATE;
  ones = RESET_STATE;
  if(value_passed >= thousand){
    value_passed = value_passed - thousand;
    thousands = one;
  }  
  while(value_passed >= hundred){
    value_passed = value_passed - hundred;
    hundreds = hundreds + one;
  }
  while(value_passed >= ten){
    value_passed = value_passed - ten;
    tens = tens + one;
  }
  while(value_passed >= one){
    value_passed = value_passed - one;
    ones = ones + one;
  }
  thousands |= offset;
  hundreds |= offset;
  tens |= offset;
  ones |= offset;
  
    display_line[LINEZERO][7] = ones;
    update_string(display_line[LINEZERO], LINEZERO);
    
 }


void adc_line4(void){
  }
     
   
