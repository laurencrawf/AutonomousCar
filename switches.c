#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

int SW1_status;
int SW2_status;
int counter = RESET_STATE;
int enable = RESET_STATE;

extern char display_line[HEIGHTFOUR][ELEVENTH_CHARACTER];
extern char *display[HEIGHTFOUR];

extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned int update_display_count;

void Switches_Process(void){
  
}
    


    
  

    