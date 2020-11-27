//------------------------------------------------------------------------------
//
//  Description: This file contains the interrupts for the ADC Code
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

volatile unsigned int ADC_Channel;
volatile unsigned int ADC_Left_Detect;
volatile unsigned int ADC_Right_Detect;
extern volatile unsigned int ADC_Thumb;

#pragma vector=ADC_VECTOR
__interrupt void ADC_ISR(void){
 switch(__even_in_range(ADCIV,ADCIV_ADCIFG)){
 case ADCIV_NONE:
 break;
 case ADCIV_ADCOVIFG: // When a conversion result is written to the ADCMEM0
 // before its previous conversion result was read.
 break;
 case ADCIV_ADCTOVIFG: // ADC conversion-time overflow
 break;
 case ADCIV_ADCHIIFG: // Window comparator interrupt flags
 break;
 case ADCIV_ADCLOIFG: // Window comparator interrupt flag
 break;
 case ADCIV_ADCINIFG: // Window comparator interrupt flag
 break;
 case ADCIV_ADCIFG: // ADCMEM0 memory register with the conversion result
   
 ADCCTL0 &= ~ADCENC; // Disable ENC bit.
 switch (ADC_Channel++){
 case case0: // Channel A2 Interrupt
 ADCMCTL0 &= ~ADCINCH_2; // Disable Last channel A2
 ADCMCTL0 |= ADCINCH_3; // Enable Next channel A3
 ADC_Left_Detect = ADCMEM0; // Move result into Global

 ADC_Left_Detect = ADC_Left_Detect >> 2; // Divide the result by 4
 //adc_line4(); // Place String in Display
 break;
 case case1:
   ADCMCTL0 &= ~ADCINCH_3; // Enable Next channel A3
 ADCMCTL0 |= ADCINCH_2; // Disable Last channel A2 
 ADC_Right_Detect = ADCMEM0; // Move result into Global

 ADC_Right_Detect = ADC_Right_Detect >> 2; // Divide the result by 4
  ADC_Channel=0;

 break;
 case case2:
 //
// ADC_Channel=0;
 break;
 default:
 break;
 }
 ADCCTL0 |= ADCENC; // Enable Conversions
 ADCCTL0 |= ADCSC;   
   
 //ADC_Thumb = ADCMEM0; // Channel A5
 ADCCTL0 |= ADCSC; // Start next sample
 default:
 break;
 }
}