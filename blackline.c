//------------------------------------------------------------------------------
#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"
//------------------------------------------------------------------------------

// Global Variables
extern char display_line[HEIGHTFOUR][ELEVENTH_CHARACTER];
extern char *display[HEIGHTFOUR];
extern unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;

extern volatile unsigned int display_counter;
extern volatile unsigned int status_counter; 

extern volatile unsigned int SW2_pressed;

extern volatile unsigned int ADC_Left_Detect;
extern volatile unsigned int ADC_Right_Detect;
//extern volatile unsigned int line_counter;
int detected = RESET_STATE;
int move = TRUE;
volatile unsigned int switch_case = RESET_STATE;
extern volatile unsigned int project7_counter;
extern int display_flag;

//-------------------------------------------------------------------------------

void BlackLineNav(void){
  switch(switch_case){
     case WAITING:
      strcpy(display_line[LINEZERO], " Intercept");
      update_string(display_line[LINEZERO], LINEZERO);
      right_reverse_pwm(RESET_STATE);
      left_reverse_pwm(RESET_STATE);
      right_forward_pwm(faster);
      left_forward_pwm(MEDFAST);
      if( (ADC_Right_Detect > black_line) || (ADC_Left_Detect > black_line) ){
        P6OUT |= GRN_LED;
        strcpy(display_line[LINEZERO], " Waiting  ");
        update_string(display_line[LINEZERO], LINEZERO);
        stop_wheels_pwm();         
        switch_case = DETECT;
        status_counter = RESET_STATE;
      }
      
      break;
    case DETECT:
      if( status_counter < turnincnt){
      stop_wheels_pwm();
      }
      else{
      right_reverse_pwm(RESET_STATE);
      left_forward_pwm(RESET_STATE);
      right_forward_pwm(fast);
      left_reverse_pwm(fast);
      switch_case = TURN;
      }
      break;
    case TURN:
      if( (ADC_Right_Detect > black_line) &&  (ADC_Left_Detect > black_line) ){
          strcpy(display_line[LINEZERO], " Turning  ");
  update_string(display_line[LINEZERO], LINEZERO);
        stop_wheels_pwm();
       // line_counter = RESET_STATE;
        switch_case = CIRCLING;
        detected = TRUE;
      }
      // Ctrl :
      
      // Det ->    <- |     BL-K    | ->
      //           ^                   ^
      //         slow down            slow down
      //         right                  left
      //    (incrmentally)
      //                      ^
      //                Both speed up
      break;
    case CIRCLING:
                  strcpy(display_line[LINEZERO], " Circling ");
  update_string(display_line[LINEZERO], LINEZERO);
         if( (ADC_Right_Detect > black_line) && (ADC_Left_Detect < black_line)){ //right on left off
          //stop_wheels_pwm();
         P1OUT |= RED_LED;
          P6OUT &= ~GRN_LED;
          left_reverse_pwm(RESET_STATE);
          right_reverse_pwm(RESET_STATE);
          left_forward_pwm(med);
          right_forward_pwm(faster);
        }
        if((ADC_Right_Detect < black_line) && (ADC_Left_Detect > black_line)){   //left on right off
          //stop_wheels_pwm();
          P1OUT &= ~RED_LED;
          P6OUT |= GRN_LED;
          left_reverse_pwm(RESET_STATE);
          right_reverse_pwm(RESET_STATE);
          left_forward_pwm(faster);
          right_forward_pwm(med);
        }
        if((ADC_Right_Detect > black_line) && (ADC_Left_Detect > black_line)){  //both on
          //stop_wheels_pwm();
          P1OUT |= RED_LED;
          P6OUT |= GRN_LED;
          left_reverse_pwm(RESET_STATE);
          right_reverse_pwm(RESET_STATE);
          left_forward_pwm(fast);
          right_forward_pwm(fast);
        }
        if( (ADC_Right_Detect < black_line) && (ADC_Left_Detect < black_line) ){  //both off
          //stop_wheels_pwm();
          P1OUT &= ~RED_LED;
          P6OUT &= ~GRN_LED;
          left_forward_pwm(RESET_STATE);
          right_forward_pwm(RESET_STATE);
          left_reverse_pwm(med);
          right_reverse_pwm(med);
        }
        switch_case = CIRCLING;

    default: break;
    }
}