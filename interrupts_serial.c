#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

// global variables
extern volatile unsigned int usb_rx_ring_wr;
extern volatile char USB_Char_Rx[SMALL_RING_SIZE] ; //this is the ring buffer
volatile unsigned int UCA0_index;
volatile unsigned int UCA1_index;
char test_command[SMALL_RING_SIZE] ;

extern int j,done;int i;
int temp2;
extern char processbuffer[ARR2][PBSIZE];
extern char newchar;
extern unsigned int usb_rx_ring_rd;

volatile unsigned int iot_rx_ring_wr;
volatile char IOT_Char_Rx[SMALL_RING_SIZE] ; //this is the ring buffer
unsigned int iot_rx_ring_rd;
extern int pcflag;
int carrot = FALSE;
char newbuffer[ARR2][PBSIZE];
int a = RESET_STATE; int b =RESET_STATE; 
extern volatile unsigned int serial_counter;
int iot_flag;
int state_machine = RESET_STATE;
int current_char, index_ip;
char ipaddr[ipsize];
int check = RESET_STATE;
//------------------------------------------------------------------------------
#pragma vector=EUSCI_A0_VECTOR
__interrupt void eUSCI_A0_ISR(void){
unsigned int temp;
switch(__even_in_range(UCA0IV,range)){
case NOINT: // Vector 0 - no interrupt
break;
case VRXIFG: // Vector 2 - RXIFG
temp = iot_rx_ring_wr++;
temp2 = UCA0RXBUF;
IOT_Char_Rx[temp] = temp2; // RX -> USB_Char_Rx character
if (iot_rx_ring_wr >= (sizeof(IOT_Char_Rx))){
iot_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
}

// move this
// if (iot_rx_. . . != iot_rx_ ... ) 
 while(iot_rx_ring_rd != iot_rx_ring_wr){
      processbuffer[i][j++] = IOT_Char_Rx[iot_rx_ring_rd++];
      if(iot_rx_ring_rd >= sizeof(IOT_Char_Rx)){
        iot_rx_ring_rd = RESET_STATE;
      }
      if(j >= sizeof(processbuffer)){
        j = RESET_STATE;
      }
      if(processbuffer[i][j] == LF){
        i++;
        if(i >= SMALL_RING_SIZE){
          i = RESET_STATE;
        }
    }
 }
//end move this
 
   UCA1TXBUF = temp2;
//current char is whats equal to UCA0RXBUF
current_char = UCA0RXBUF;
switch(state_machine){
case WAITING:
  if(current_char == 'r'){
    state_machine = IPBEGIN;
  }
  else{
    state_machine = WAITING;
  }
  break;
case IPBEGIN:
  if(current_char == '='){
    state_machine = GETIP;
  }
  else{
    state_machine = WAITING;
  }
  break;
case GETIP:
  ipaddr[index_ip] = current_char;
  index_ip++;
  if(current_char == ' '){
    index_ip = RESET_STATE;
    state_machine = RESET_STATE;
  }
  break;
default: break;
}
  
  


  if(carrot){
  newbuffer[b][a] = temp2;
    a++;
  if(newbuffer[RESET_STATE][a] == '\r'){
    //set flag and actually run command in main 
    iot_flag = TRUE;
    carrot = FALSE;
  } 
      if(temp2 == '^'){
       b = TRUE;
       a = RESET_STATE;
       if(check > RESET_STATE){
       newbuffer[b][a] = temp2;
       if(a == COMDONE){
         //see above 
          b=RESET_STATE;
          iot_flag = GETIP;
          carrot = FALSE;
       } 
       a++;
     /*  if( a == 9){
         carrot = FALSE;
       } */
       }
       check++;
      }
  if( a == COMDONE ){
    if( b == TRUE){
      iot_flag = GETIP;
    }
    if ( b == RESET_STATE){
    iot_flag = TRUE;
    }
    carrot = FALSE;
  } 
} 
  
  if(temp2 == CR){
    carrot = FALSE;
  } 
  if(temp2 == '^'){
    carrot = TRUE;
  } 
    
//make a new if statement thatll say if it equal new line you put it on the display
break;
case VTXIFG: // Vector 4 – TXIFG
UCA0TXBUF = test_command[UCA0_index++];
if (test_command[UCA0_index] == NULL){
UCA0IE &= ~UCTXIE;
}
break;
//---------------------
break;
default: break;
}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#pragma vector=EUSCI_A1_VECTOR
__interrupt void eUSCI_A1_ISR(void){
unsigned int temp;
switch(__even_in_range(UCA1IV,range)){
case NOINT: // Vector 0 - no interrupt
break;
case VRXIFG: // Vector 2 - RXIFG

temp = usb_rx_ring_wr++;
USB_Char_Rx[temp] = UCA1RXBUF; // RX -> USB_Char_Rx character
if (usb_rx_ring_wr >= (sizeof(USB_Char_Rx))){
usb_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
}

temp2 = UCA1RXBUF;
UCA0TXBUF = temp2;
pcflag=TRUE;

break;
case VTXIFG: // Vector 4 – TXIFG
UCA1TXBUF = test_command[UCA1_index++];
if (test_command[UCA1_index] == NULL){
UCA1IE &= ~UCTXIE;
}
 break;
//---------------------
break;
default: break;
}
} 
//------------------------------------------------------------------------------