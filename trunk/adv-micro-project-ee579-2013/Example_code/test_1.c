// includes and dependancies
#include <msp430.h>
 
// defines and constants
#define P0 BIT0					// Red LED
 
// function prototypes
void Delay_ms(unsigned int ms);
 
/***********************************************************************
* @main(void) - Contains loop that toggels the LED
***********************************************************************/
void main(void) {
	WDTCTL = WDTPW + WDTHOLD;		// Set WDT to stop
	P1OUT |= 0x01;				// Set direction of the LED
 
	while(1){
		P1OUT ^= P0;			// Toggle P1
		Delay_ms(50000);		// Delay for 50000 milliseconds
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