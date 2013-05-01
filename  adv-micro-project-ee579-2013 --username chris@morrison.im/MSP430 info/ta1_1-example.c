
/* Modified PWM from March 13th */

#include  <msp430g2553.h>

//  The value in TA1CCR0, 512-1, defines the PWM
//  period and the value in TA1CCR1 the PWM duty cycles.
//  A 75% duty cycle on P2.2.

void wait(){
	unsigned int i;
	for(i=0;i<5000;i++){
		;;;   // wait
	}
}


void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P2DIR |= 0x04;                            // P2.2 output
  P2SEL |= 0x04;                            // P2.2 TA1.1 option
  P2SEL2 &= ~0x04;                        // P2.2 TA1.1 option
  TA1CCR0 = 512;                             // PWM Period
  TA1CCTL1 = OUTMOD_7;                         // TA1CCR1 reset/set
  TA1CCR1 = 384;                               // TA1CCR1 PWM duty cycle
  TA1CTL = TASSEL_2 + MC_1;                  // SMCLK, up mode


  while(1){


	  __delay_cycles(10000);
	  wait();
  }

}
