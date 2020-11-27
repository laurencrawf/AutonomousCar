//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Jim Carlson
//  Jan 2018
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

  // Global Variables
volatile char slow_input_down;
extern char display_line[HEIGHTFOUR][ELEVENTH_CHARACTER];
extern char *display[HEIGHTFOUR];
unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;
//extern volatile unsigned int Time_Sequence;
//extern volatile char one_time;
unsigned int test_value;
char chosen_direction;
char change;

extern volatile unsigned int display_counter;
extern volatile unsigned int status_counter; 

extern volatile unsigned int SW2_pressed;
extern volatile unsigned int SW1_pressed;

volatile unsigned int ADC_Thumb;
extern volatile unsigned int ADC_Left_Detect;
extern volatile unsigned int ADC_Right_Detect;

extern volatile unsigned int UCA0_index;
extern volatile unsigned int UCA1_index;
extern char test_command[SMALL_RING_SIZE] ;

char processbuffer[ARR2][PBSIZE];
char newchar;
//int i = RESET_STATE,
int j;
extern volatile char USB_Char_Rx[SMALL_RING_SIZE];
extern volatile unsigned int usb_rx_ring_wr;
extern unsigned int usb_tx_ring_rd;
extern unsigned int usb_rx_ring_rd;
int arr;
int done;
extern volatile unsigned int transmitflag;
extern volatile unsigned int serial_counter;
extern volatile unsigned int IOT_counter;
extern int iot_flag;
extern char newbuffer[ARR2][PBSIZE];
extern int b;
extern int a;
int c = RESET_STATE;
extern char ipaddr[ipsize];
int height = FALSE;
int display_flag = TRUE;
extern volatile unsigned int project7_counter;
int onnumber = FALSE;
extern volatile unsigned int num8_counter;
int blacklinenavflag = RESET_STATE;

void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings

  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_Timers();                       // Initialize Timers
  Init_LCD();                          // Initialize LCD  
  Init_ADC();
  

      Init_Serial_UCA0(FALSE);
      Init_Serial_UCA1();
      strcpy(display_line[LINEZERO], " Waiting  ");
      update_string(display_line[LINEZERO], LINEZERO);
      enable_display_update();
   
      
      while (IOT_counter < ResetTime){
        P5OUT &= ~IOT_RESET;
      }
      if(IOT_counter >= ResetTime){
        P5OUT |= IOT_RESET;
      }
      IOT_counter = RESET_STATE;
//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {                      // Can the Operating system run

    Switches_Process();                // Check for switch state change
    Display_Process();

    if(IOT_counter == IPTime){
      strcpy(test_command, "AT+NSTAT=?\r\n");
      UCA0_index = RESET_STATE;
      UCA0IE |= UCTXIE;
      IOT_counter = IPDONE;
    }
    
    if(IOT_counter == IPTime){
     int displaystuff;
      for(displaystuff = RESET_STATE; displaystuff < ARR7; displaystuff++){
        display_line[LINEONE][displaystuff] = ipaddr[displaystuff];
      }
      for(displaystuff = ARR7; displaystuff < ARR13; displaystuff++){
        display_line[LINETWO][height] = ipaddr[displaystuff];
        height++;
      }

     IOT_counter = IPDONE;
    }
    
    if(IOT_counter == DisplayTime){
      strcpy(test_command, "AT+NSTCP=1066,1\r\n");
      UCA0_index = RESET_STATE;
      UCA0IE |= UCTXIE;
      IOT_counter = DisplayDONE;
    }
    
//----------------------------------------------------   
    int loop = BEGINLOOP;
    while(loop < PBSIZE){
      processbuffer[FIRST][loop] = RESET_STATE;   
      loop++;
    }  
    transmitflag = FALSE;
//----------------------------------------------------
  
  if(display_flag){
    HEXtoBCD_RIGHT(project7_counter);
  }
  
//-----------------------------------------------------    
if(iot_flag){
  if( c == ARR2){
    c = RESET_STATE;
  }
  int hundreds = (newbuffer[c][ARR5] - Offset) * hundred; 
  int tens = (newbuffer[c][ARR6] - Offset) * ten;
  int ones = newbuffer[c][ARR7] - Offset;
  int time = hundreds + tens + ones;
 
  if( newbuffer[c][LINEZERO] == '1' && newbuffer[c][LINEONE] == '2' && newbuffer[c][LINETWO] == '3' && newbuffer[c][LINETHREE] == '4'){

    if(newbuffer[c][ARR4] == 'F'){
      strcpy(display_line[LINEONE], "  Forward ");
      update_string(display_line[LINEONE], LINEONE);
      serial_counter = FALSE;
      while( serial_counter < time){
        right_forward_pwm(faster);
        left_forward_pwm(faster);
      }
      stop_wheels_pwm();
    }
    if(newbuffer[c][ARR4] == 'B'){
      strcpy(display_line[LINEONE], "  REVERSE ");
      update_string(display_line[LINEONE], LINEONE);
      serial_counter = FALSE;
      while( serial_counter < time){
        left_reverse_pwm(faster);
        right_reverse_pwm(faster);
      }
      stop_wheels_pwm();
    }
    if(newbuffer[c][ARR4] == 'L'){
      strcpy(display_line[LINEONE], "   LEFT   ");
      update_string(display_line[LINEONE], LINEONE);
      serial_counter = FALSE;
      while( serial_counter < time){
        right_reverse_pwm(fast);
        left_forward_pwm(faster);
      }
      stop_wheels_pwm();
    }
    if(newbuffer[c][ARR4] == 'R'){
      strcpy(display_line[LINEONE], "   RIGHT  ");
      update_string(display_line[LINEONE], LINEONE);
      serial_counter = FALSE;
      while( serial_counter < time){
         left_reverse_pwm(faster);
         right_forward_pwm(faster);
      }
      stop_wheels_pwm();
    }
    if(newbuffer[c][ARR4] == 'D'){
      //disPlay stuff
      strcpy(display_line[LINEZERO], "Arrive    ");
      update_string(display_line[LINEZERO], LINEZERO);
      HEXtoBCD_LEFT(onnumber);
      onnumber++;
    }
    if(newbuffer[c][ARR4] == 'C'){
      strcpy(display_line[LINEONE], "BLKLINENAV");
      update_string(display_line[LINEONE], LINEONE);
      P3OUT |= IR_LED;
      //circle
      //arc code
      num8_counter = RESET_STATE;
      while(num8_counter < STOPCNT){
        stop_wheels_pwm();
      } 
      blacklinenavflag = TRUE;
      //BlackLineNav();
      //set flag high
    }
    if(newbuffer[c][ARR4] == 'E'){
      //set flag low
      blacklinenavflag = FALSE;
      //exit command
      stop_wheels_pwm();
      P3OUT &= ~IR_LED;
      status_counter = RESET_STATE;
      while(status_counter < time){
        strcpy(display_line[LINEZERO], " Exitting ");
        update_string(display_line[LINEZERO], LINEZERO);
        if(status_counter < EXITTIMER){
          right_forward_pwm(fast);
          left_reverse_pwm(fast);
        }
        else{
          stop_wheels_pwm();
          right_forward_pwm(faster);
          left_forward_pwm(faster);
        }
      }
      
      stop_wheels_pwm();
      strcpy(display_line[LINEZERO], "  Stopped ");
      update_string(display_line[LINEZERO], LINEZERO);   
    
      }
  }
//------------------------------------------------------------------------------  
      int clear;
      for(clear = RESET_STATE; clear < ClearSize; clear++){
        newbuffer[c][clear] = FALSE;
        a = RESET_STATE;
      } 
      c++;        
      iot_flag--;
    }
//------------------------------------------------------------------------------
  if(blacklinenavflag){
    BlackLineNav();
  }
  
 }
  
}
//------------------------------------------------------------------------------




