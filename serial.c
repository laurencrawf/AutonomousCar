#include  "functions.h"
#include  "msp430.h"
#include <string.h>
#include "macros.h"

volatile unsigned int usb_rx_ring_wr;
unsigned int usb_rx_ring_rd;
volatile unsigned int usb_tx_ring_wr;
unsigned int usb_tx_ring_rd;
volatile char USB_Char_Rx[SMALL_RING_SIZE];
int pcflag;
extern char newbuffer[ARR2][PBSIZE];
extern int a;
extern int b; 
extern volatile unsigned int serial_counter;

void Init_Serial_UCA0(int number){
  int i;

  for(i=RESET_STATE; i<SMALL_RING_SIZE; i++){
    USB_Char_Rx[i] = USBRX; // USB Rx Buffer
  }
  usb_rx_ring_wr = BEGINNING;
  usb_rx_ring_rd = BEGINNING;
  //for(i=0; i<LARGE_RING_SIZE; i++){ // May not use this
    //USB_Char_Tx[i] = 0x00; // USB Tx Buffer
  //}
  usb_tx_ring_wr = BEGINNING;
  usb_tx_ring_rd = BEGINNING;
  // Configure UART 0
  UCA0CTLW0 = RESET_STATE; // Use word register
  UCA0CTLW0 |= UCSWRST; // Set Software reset enable
  UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
  
  if(number){
    UCA0BRW = BRW9600;
    UCA0MCTLW = MCTLW9600;
  }
  else{
    UCA0BRW = BRW115; //4 for 115,200
    UCA0MCTLW = MCTLW115 ; //0x5551 for 115,200
  }
  
  UCA0CTLW0 &= ~ UCSWRST; // Set Software reset enable
  UCA0IE |= UCRXIE; // Enable RX interrupt
}

void Init_Serial_UCA1(void){
  int i;
  pcflag = FALSE;
  
  for(i=RESET_STATE; i<SMALL_RING_SIZE; i++){
    USB_Char_Rx[i] = USBRX; // USB Rx Buffer
  }
  usb_rx_ring_wr = BEGINNING;
  usb_rx_ring_rd = BEGINNING;
  //for(i=0; i<LARGE_RING_SIZE; i++){ // May not use this
    //USB_Char_Tx[i] = 0x00; // USB Tx Buffer
  //}
  usb_tx_ring_wr = BEGINNING;
  usb_tx_ring_rd = BEGINNING;
  // Configure UART 0
  UCA1CTLW0 = RESET_STATE; // Use word register
  UCA1CTLW0 |= UCSWRST; // Set Software reset enable
  UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
  
    UCA1BRW = BRW115; // 9,600 Baud  //4 for 115,200
    UCA1MCTLW = MCTLW115 ; //0x5551 for 115,200
  
  UCA1CTLW0 &= ~ UCSWRST; // Set Software reset enable
  UCA1IE |= UCRXIE; // Enable RX interrupt
}

void out_character(char character){
//------------------------------------------------------------------------------
// The while loop will stall as long as the Flag is not set [port is busy]
while (!(UCA0IFG & UCTXIFG)); // USCI_A0 TX buffer ready?
UCA0TXBUF = character;
//------------------------------------------------------------------------------
}

void IOT_Command(void){
 
}
