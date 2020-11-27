//-----------------------------------------------------------------------------
// Description: this file intializes each individual port on the MSP430
// 1/27/2020
// Lauren Crawford
//  Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//-----------------------------------------------------------------------------
#include "macros.h"
#include  "msp430.h"
#include "functions.h"

//call all port functions
void Init_Ports(void){
  Init_Port1();
  Init_Port2();
  Init_Port4();
  Init_Port5();
  Init_Port6();
  Init_Port3(USE_SMCLK);
  Init_Port3(USE_GPIO);
}

// initialize port 1 and defines its pins
void Init_Port1(void){
  P2DIR = OUTPUT_DIRECTION; 
  P2OUT = LOW_OUTPUT; 
  
  P1SEL0 &= ~RED_LED; //Red LED operation
  P1SEL1 &= ~RED_LED; //Red LED operation
  P1DIR |= RED_LED; // Direction = Output
  
  P1SEL0 |= A1_SEED; // P1_1 operation
  P1SEL1 |= A1_SEED; // P1_1 operation
  
  P1SEL0 |= V_DETECT_L; // P1_2 operation
  P1SEL1 |= V_DETECT_L; // P1_2 operation
  
  P1SEL0 |= V_DETECT_R; // P1_3 operation
  P1SEL1 |= V_DETECT_R; // P1_3 operation
  
  P1SEL0 |= A4_SEED; // P1_4 operation
  P1SEL1 |= A4_SEED; // P1_4 operation
  
  P1SEL0 |= V_THUMB; // P1_5 operation
  P1SEL1 |= V_THUMB; // P1_5 operation
  
  P1SEL1 &= ~UCA0RXD; // P1_6 operation
  P1SEL0 |= UCA0RXD; // P1_6 operation
  
  P1SEL1 &= ~UCA0TXD; // P1_7 operation
  P1SEL0 |= UCA0TXD; // P1_7 operation
}
//initialize port 2 and defines its pins
void Init_Port2(void){

  P2DIR = OUTPUT_DIRECTION; //set P2 direction to output
  P2OUT = LOW_OUTPUT; //P2 set Low

  P2SEL0 &= ~P2_0; // P2_0 GPIO operation
  P2SEL1 &= ~P2_0; // P2_0 GPIO operation
  P2DIR &= ~P2_0; // Direction = input

  P2SEL0 &= ~P2_1; // P2_1 GPIO operation
  P2SEL1 &= ~P2_1; // P2_1 GPIO operation
  P2DIR &= ~P2_1; // Direction = input

  P2SEL0 &= ~P2_2; // P2_2 GPIO operation
  P2SEL1 &= ~P2_2; // P2_2 GPIO operation
  P2DIR &= ~P2_2; // Direction = input

  P2SEL0 &= ~SW2; // SW2 Operation
  P2SEL1 &= ~SW2; // SW2 Operation
  P2DIR &= ~SW2; // Direction = input
  P2OUT |= SW2; // Configure pullup resistor
  P2REN |= SW2; // Enable pullup resistor
  P2IES |= SW2;
  P2IFG &= ~SW2;
  P2IE |= SW2;
  

  P2SEL0 &= ~P2_4; // P2_4 GPIO operation
  P2SEL1 &= ~P2_4; // P2_4 GPIO operation
  P2DIR &= ~P2_4; // Direction = input

  P2SEL0 &= ~P2_5; // P2_5 GPIO operation
  P2SEL1 &= ~P2_5; // P2_5 GPIO operation
  P2DIR &= ~P2_5; // Direction = input

  P2SEL0 &= ~LFXOUT; // LFXOUT Clock operation
  P2SEL1 |= LFXOUT; // LFXOUT Clock operation

  P2SEL0 &= ~LFXIN; // LFXIN Clock operation
  P2SEL1 |= LFXIN; // LFXIN Clock operation
}
//initialize Port 3 and defines pins
void Init_Port3(int arg){
  P3DIR = OUTPUT_DIRECTION; //Set P3 direction to output
  P3OUT = LOW_OUTPUT; //P3 set to low
  
  P3SEL0 &= ~TEST_PROBE;
  P3SEL1 &= ~TEST_PROBE;
  P3DIR &= ~TEST_PROBE;
  
  P3SEL0 |= CHECK_BAT;
  P3SEL1 |= CHECK_BAT;
  
  P3SEL0 &= ~OA2N;
  P3SEL1 &= ~OA2N;
  P3DIR &= ~OA2N;
  
  P3SEL0 &= ~OA2P;
  P3SEL1 &= ~OA2P;
  P3DIR &= ~OA2P;
  
  //P3SEL0 &= ~SMCLK_OUT;
  //P3SEL1 &= ~SMCLK_OUT;
  //P3DIR &= ~SMCLK_OUT;
  
  if(arg == USE_SMCLK){
   P3SEL0 |= SMCLK_OUT;
   P3SEL1 &= ~SMCLK_OUT;
   //P3DIR |= SMCLK_OUT;
  }else{
   P3SEL0 &= ~SMCLK_OUT;
   P3SEL1 &= ~SMCLK_OUT;
   //P3DIR |= SMCLK_OUT;
  }
  
  P3SEL0 &= ~IR_LED;
  P3SEL1 &= ~IR_LED;
  P3DIR |= IR_LED;
//      P3OUT |= IR_LED;
  
  P3SEL0 &= ~IOT_LINK;
  P3SEL1 &= ~IOT_LINK;
  P3DIR &= ~IOT_LINK;
  
  P3SEL0 &= ~P3_7;
  P3SEL1 &= ~P3_7;
}
//Initialize Port 4 and defines pins
void Init_Port4(void){

  P4DIR = OUTPUT_DIRECTION; 
  P4OUT = LOW_OUTPUT;

  P4SEL0 &= ~RESET_LCD; // RESET_LCD GPIO operation
  P4SEL1 &= ~RESET_LCD; // RESET_LCD GPIO operation
  P4DIR |= RESET_LCD; // Set RESET_LCD direction to output
  P4OUT |= RESET_LCD; // Set RESET_LCD Off [High]

  P4SEL0 &= ~SW1; // SW1 GPIO operation
  P4SEL1 &= ~SW1; // SW1 GPIO operation
  P4DIR &= ~SW1; // Direction = input
  P4OUT |= SW1; // Configure pullup resistor
  P4REN |= SW1; // Enable pullup resistor
  P4IES |= SW1;
  P4IFG &= ~SW1;
  P4IE |= SW1;
  
  

  P4SEL0 |= UCA1TXD; // USCI_A1 UART operation
  P4SEL1 &= ~UCA1TXD; // USCI_A1 UART operation

  P4SEL0 |= UCA1RXD; // USCI_A1 UART operation
  P4SEL1 &= ~UCA1RXD; // USCI_A1 UART operation

  P4SEL0 &= ~UCB1_CS_LCD; // UCB1_CS_LCD GPIO operation
  P4SEL1 &= ~UCB1_CS_LCD; // UCB1_CS_LCD GPIO operation
  P4DIR |= UCB1_CS_LCD; // Set SPI_CS_LCD direction to output
  P4OUT |= UCB1_CS_LCD; // Set SPI_CS_LCD Off [High]

  P4SEL0 |= UCB1CLK; // UCB1CLK SPI BUS operation
  P4SEL1 &= ~UCB1CLK; // UCB1CLK SPI BUS operation

  P4SEL0 |= UCB1SIMO; // UCB1SIMO SPI BUS operation
  P4SEL1 &= ~UCB1SIMO; // UCB1SIMO SPI BUS operation
  P4SEL0 |= UCB1SOMI; // UCB1SOMI SPI BUS operation
  P4SEL1 &= ~UCB1SOMI; // UCB1SOMI SPI BUS operation

}
//Initialize Port 5 and defines pins
void Init_Port5(void){
  
  P5DIR = OUTPUT_DIRECTION; 
  P5OUT = LOW_OUTPUT;
  
  P5SEL0 &= ~IOT_RESET;
  P5SEL1 &= ~IOT_RESET;
  P5DIR &= ~IOT_RESET;
  
  P5SEL0 |= V_BAT;
  P5SEL1 |= V_BAT;
  
  P5SEL0 &= ~IOT_PROG_SEL;
  P5SEL1 &= ~IOT_PROG_SEL;
  P5DIR &= ~IOT_PROG_SEL;
  
  P5SEL0 |= V_3_3;
  P5SEL1 |= V_3_3;
  
  P5SEL0 &= ~IOT_PROG_MODE;
  P5SEL1 &= ~IOT_PROG_MODE;
  P5DIR &= ~IOT_PROG_MODE;
}
//Initialize Port 6 and defines pins
void Init_Port6(void){
  
  P6DIR = OUTPUT_DIRECTION; 
  P6OUT = LOW_OUTPUT;
    
  P6SEL0 |= R_FORWARD;
  P6SEL1 &= ~R_FORWARD;
  P6DIR |= R_FORWARD;
  //P6OUT |= R_FORWARD; //on
  //P6OUT &= ~R_FORWARD; //OFF
  
  P6SEL0 |= L_FORWARD;
  P6SEL1 &= ~L_FORWARD;
  P6DIR |= L_FORWARD;
  //P6OUT |= L_FORWARD; //ON
  //P6OUT &= ~L_FORWARD; //OFF
  
  P6SEL0 |= R_REVERSE;
  P6SEL1 &= ~R_REVERSE;
  P6DIR |= R_REVERSE;
 // P6OUT |= R_REVERSE; //ON
  //P6OUT &= ~R_REVERSE; //OFF
  
  P6SEL0 |= L_REVERSE;
  P6SEL1 &= ~L_REVERSE;
  P6DIR |= L_REVERSE;
  //P6OUT |= L_REVERSE; //ON
  //P6OUT &= ~L_REVERSE; //OFF
  
  P6SEL0 &= ~LCD_BACKLITE;
  P6SEL1 &= ~LCD_BACKLITE;
  //P6OUT |= LCD_BACKLITE; //backlight on
  //P6DIR |= LCD_BACKLITE;
  //P6OUT &= ~LCD_BACKLITE; //backlight off
  //P6DIR &= ~LCD_BACKLITE;
  
  P6SEL0 &= ~P6_5;
  P6SEL1 &= ~P6_5;
  P6DIR &= ~P6_5;
  
  P6SEL0 &= ~GRN_LED;
  P6SEL1 &= ~GRN_LED;
  P6DIR |= GRN_LED;
}



  