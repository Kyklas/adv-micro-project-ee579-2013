// includes and dependancies
#include <msp430.h>
 
// defines and constants
#define P0 BIT0					// Red LED
#define P6 BIT6 // hopefully green LED!

#define P3 BIT3 // hopefully the button
 
// function prototypes
void Delay_ms(unsigned int ms);
 
/***********************************************************************
* @main(void) - Contains loop that toggels the LED
***********************************************************************/
void main(void) {
	WDTCTL = WDTPW + WDTHOLD;		// Set WDT to stop
	P1DIR |= (BIT0 + BIT6);			// Set direction of the LED
	P1OUT = 0xff;
        
        
        
        
        P1IE |= P3; // P1.3 interrupt enabled

        P1IFG &= ~P3; // P1.3 IFG cleared

        __enable_interrupt(); // enable all interrupts

        
        
        
	while(1){
          
    
          
          
		//P1OUT ^= (P0);			// Toggle P1
		//Delay_ms(500);			// Delay for 500 milliseconds
               // P1OUT ^= (P6);
	}
}
 
/***********************************************************************
* @Breif: Creates a delay in milliseconds
*
* @Inputs: (unsigned int ms) - delay in milliseconds
***********************************************************************/
void Delay_ms(unsigned int ms){
	while(ms--){
	__delay_cycles(1000);
	}
}




// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
  
  		P1OUT ^= (P0);			// Toggle P1
		//Delay_ms(500);			// Delay for 500 milliseconds
                P1OUT ^= (P6); // toggle p6
                
                P1IFG &= ~P3; // P1.3 IFG cleared
P1IES ^= P3; // toggle the interrupt edge,
//P1OUT ^= (LED0 + LED1); // P1.0 = toggle
//P1IFG &= ~BUTTON; // P1.3 IFG cleared
//P1IES ^= BUTTON; // toggle the interrupt edge,
// the interrupt vector will be called
// when P1.3 goes from HitoLow as well as
// LowtoHigh
}