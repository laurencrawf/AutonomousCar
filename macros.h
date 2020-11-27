//------------------------------------------------------------------------------
// Description: This file contains all defined macros 
// 1/27/2020
// Lauren Crawford
//------------------------------------------------------------------------------

#include "functions.h"

#define ALWAYS                  (1)
#define RESET_STATE             (0)
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x40) // GREEN LED 1

//Main.c macros
#define LINEZERO (0)
#define LINEONE (1)
#define LINETWO (2)
#define LINETHREE (3)
#define HEIGHTFOUR (4)
#define HEIGHTFIVE (5)
#define HEIGHTSIX (6)
#define TENTH_CHARACTER (10)
#define ELEVENTH_CHARACTER (11)
#define CASEONE (250)
#define CASETWO (200)
#define CASETHREE (150)
#define CASEFOUR (100)
#define CASEFIVE (50)
#define START_INTEGER (0)
#define END_INTEGER (11)


//Port 1 Pins
#define RED_LED (0x01) // 0 RED LED
#define A1_SEED (0x02) // 1 A1_SEEED
#define V_DETECT_L (0x04) // 2 V_DETECT_L
#define V_DETECT_R (0x08) // 3 V_DETECT_R
#define A4_SEED (0x10) // 4 A4_SEEED
#define V_THUMB (0x20) // 5 V_THUMB
#define UCA0RXD (0x40) // 6 Back Channel UCA0RXD
#define UCA0TXD (0x80) // 7 Back Channel UCA0TXD

#define LOW_OUTPUT (0x00) // initial output for ports
#define OUTPUT_DIRECTION (0xFF) // initital direction to output

// Port 2 Pins
#define P2_0 (0x01) // 0
#define P2_1 (0x02) // 1
#define P2_2 (0x04) // 2
#define SW2 (0x08) // 3 SW2
#define P2_4 (0x10) // 4
#define P2_5 (0x20) // 5
#define LFXOUT (0x40) // XOUTR
#define LFXIN (0x80) // XINR

// Port 3 Pins
#define TEST_PROBE (0x01) // 0 TEST PROBE
#define CHECK_BAT (0x02) // 1 CHECK_BAT
#define OA2N (0x04) // 2 Photodiode Circuit
#define OA2P (0x08) // 3 Photodiode Circuit
#define SMCLK_OUT (0x10) // 4 SMCLK
#define IR_LED (0x20) // 5 IR_LED
#define IOT_LINK (0x40) // 6 IOT_LINK
#define P3_7 (0x80) // 7 P3_7

// Port 4 Pins
#define RESET_LCD (0x01) // 0 LCD Reset
#define SW1 (0x02) // 1 SW1
#define UCA1RXD (0x04) // 2 Back Channel UCA1RXD
#define UCA1TXD (0x08) // 3 Back Channel UCA1TXD
#define UCB1_CS_LCD (0x10) // 4 Chip Select
#define UCB1CLK (0x20) // 5 SPI mode - clock output—UCB1CLK
#define UCB1SIMO (0x40) // 6 UCB1SIMO
#define UCB1SOMI (0x80) // 7 UCB1SOMI

// Port 5 Pins
#define IOT_RESET (0x01)
#define V_BAT (0x02)
#define IOT_PROG_SEL (0x04)
#define V_3_3 (0x08)
#define IOT_PROG_MODE (0x10)

//Port 6 Pins
#define R_FORWARD (0x01)
#define L_FORWARD (0x02)
#define R_REVERSE (0x04)
#define L_REVERSE (0x08)
#define LCD_BACKLITE (0x10)
#define P6_5 (0x20)
#define GRN_LED (0x40)

//Time 
#define MILSECONDS1 (1)
#define MILSECONDS10 (10)
#define MILSECONDS15 (15)
#define MILSECONDS20 (20)
#define MILSECONDS50 (50)
#define MILSECONDS60 (60)
#define MILSECONDS100 (100)
#define MILSECONDS125 (125)
#define MILSECONDS150 (150)
#define MILSECONDS175 (175)
#define MILSECONDS200 (200)
#define MILSECONDS225 (225)
#define MILSECONDS250 (250)
#define MILSECONDS260 (260)
#define MILSECONDS280  (280)
#define MILSECONDS300 (300)
#define MILSECONDS350 (350)
#define MILSECONDS400 (400)
#define MILSECONDS450 (450)
#define MILSECONDS500 (500)
#define MILSECONDS550 (550)
#define MILSECONDS560 (560)
#define MILSECONDS590 (590)
#define MILSECONDS600 (600)
#define MILSECONDS610 (610)
#define MILSECONDS650 (650)
#define MILSECONDS700 (700)
#define MILSECONDS800 (800)
#define MILSECONDS900 (900)
#define MILSECONDS999 (999)
#define MILSECONDS1000 (1000)
#define MILSECONDS1500 (1500)
#define MILSECONDS2000 (2000)
#define MILSECONDS2010 (2010)
#define MILSECONDS2500 (2500)
#define MILSECONDS2800 (2800)
#define MILSECONDS3000 (3000)
#define MILSECONDS5000 (5000)

#define TIMEONE (1)
#define TIMETWO (2)
#define TIMETHREE (3)
#define TIMEFOUR (4)
#define TIMEFIVE (5)
#define TIMESIX (6)
#define TIMESEVEN (7)
#define TIMEEIGHT (8)
#define TIMENINE (9)
#define TIMETEN (1)
#define TIMEFIFTEEN (15)
#define TIMESIXTY (60)

//logic
#define FALSE (0)
#define TRUE (1)
#define INCREMENT (1)

//shapes
#define CIRCLE (1)
#define FIG8 (2)
#define TRI (3)


//homework 05
#define USE_GPIO (0x00)
#define USE_SMCLK (0x01)
#define  M2 (2)
#define GPIO (0)
#define SMCLK (1)

//interrupts
#define TB0CCR0_INTERVAL (25000)
#define TB0CCR1_INTERVAL (25000)
#define TB0CCR2_INTERVAL (25000)

//Count
#define COUNTONE (1)
#define COUNTTEN (10)
#define COUNT14 (14)
#define COUNTTWENTY (20)
#define COUNT40 (40)
#define COUNT80 (80)
#define COUNT100 (100)
#define COUNT120 (120)
#define COUNT140 (140)
#define COUNT200 (200)
#define COUNT240 (240)
#define COUNT300 (300)
#define COUNT340 (340)
#define COUNT200MSEC (4)

//cases
#define SW1CASE (2)
#define SW2CASE (4)
#define OVERFLOWCASE (14)

//timers
#define RIGHT_FORWARD_SPEED (TB3CCR1)
#define LEFT_FORWARD_SPEED (TB3CCR2)
#define RIGHT_REVERSE_SPEED (TB3CCR3)
#define LEFT_REVERSE_SPEED (TB3CCR4)
#define WHEEL_PERIOD (60000)
#define WHEEL_OFF (0)

//project 6 
#define right_fwd (40000)
#define left_fwd (60000)
#define reverse_spd (60000)
#define A2_case (0x00)
#define A3_case (0x01)
#define case3 (0x02)
#define case0 (00)
#define case1 (1)
#define case2 (2)
#define black_line (200)
#define status_time (30)
#define last_case (50)

//serial
#define BEGINNING (0)
#define SMALL_RING_SIZE (32)
#define FIRST (0)
#define ARR0 (0)
#define ARR1 (1)
#define ARR2 (2)
#define ARR3 (3)
#define ARR4 (4)
#define ARR5 (5)
#define ARR6 (6)
#define ARR7 (7)
#define ARR8 (8)
#define ARR9 (9)
#define ARR13 (13)
#define PBSIZE (32)
#define BEGINLOOP (0)
#define NOINT (0)
#define VRXIFG (2)
#define LF (0x0A)
#define CR (0x0D)
#define VTXIFG (4)
#define INDEX0 (0)
#define INDEX1 (1)
#define INDEX2 (2)
#define INDEX3 (3)
#define INDEX4 (4)
#define INDEX5 (5)
#define INDEX6 (6)
#define INDEX7 (7)
#define INDEX8 (8)
#define INDEX9 (9)
#define INDEX10 (10)
#define USBRX (0x00)
#define BRW460 (1)
#define MCTLW460 (460)
#define BRW115 (4)
#define MCTLW115 (0x5551)
#define range (0x08)

#define thousand (1000)
#define hundred (100)
#define thirty (0x30)
#define ten (10)

//Project 09
#define BRW9600 (52)
#define MCTLW9600 (0x4911)
#define ipsize (15)
#define ResetTime (3)
#define IPTime (300)
#define IPDONE (302)
#define DisplayTime (350)
#define DisplayDONE (351)
#define ConTime (300)
#define ConDONE (302)
#define ClearSize (8)
#define WAITING (0)
#define IPBEGIN (1)
#define GETIP (2)
#define Offset (48)
#define COMDONE (9)

//Project 07
#define DIV4 (2)
#define large (66)
#define fast (20000)
#define med (10000)
#define slow (9000)
#define TURNING (2)
#define CIRCLING (3)
#define faster (30000)
#define TWOCIRCLE (500)
#define TURNIN (4)
#define slower (7000)
#define one (1)
#define ten (10)
#define hundred (100)
#define thousand (1000)
#define offset (0x30)
#define turnincnt (30)
#define STOPCNT (80)
#define EXITTIMER (20)
#define MEDFAST (25000)
#define DETECT (1)
#define TURN (2)

