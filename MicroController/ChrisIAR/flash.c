// includes and dependancies
#include <msp430.h>
 
// defines and constants
#define P0 BIT0					// Red LED
#define P6 BIT6 // hopefully green LED!

#define P4 BIT4 // another one
 
// function prototypes
void Delay_ms(unsigned int ms);
 
/***********************************************************************
* @main(void) - Contains loop that toggels the LED
***********************************************************************/
void main(void) {
	WDTCTL = WDTPW + WDTHOLD;		// Set WDT to stop
	P1DIR |= (BIT0 + BIT6 + BIT4);			// Set direction of the LED
	P1OUT = 0xff;
        

        
        
        
	while(1){
          for(int j = 0; j<=10; j++){
          for(int i = 0; i<=10; i++){
            
		P1OUT ^= (P0);			// Toggle P1
		Delay_ms(1);			// Delay for 500 milliseconds
          }
             
       
                
                P1OUT ^= (P6);
          }
          P1OUT ^= (P4);
	}
}
 
/***********************************************************************
* @Breif: Creates a delay in milliseconds
*
* @Inputs: (unsigned int ms) - delay in milliseconds
***********************************************************************/
void Delay_ms(unsigned int ms){
	while(ms--){
	__delay_cycles(10); // chris - subtracted 2x 0's on 19th
	}
}



