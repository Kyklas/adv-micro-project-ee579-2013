/*
 * ======== Standard MSP430 includes ========
 */

#include <stdint.h>
#include <msp430.h>
#include <math.h>
#include <msp430g2231.h>


/*
 *  ======== main ========
 */
float x = 4.2f;
float testTan=0.0f;
float testSin =0.0f;
float testCos = 0.0f;


void main()
{


	  // Make P1.6 (green led) an output. SLAU144E p.8-3
	  P1DIR |= BIT6;
	  P1OUT=0xff;
	while(1)
	{
		x -= 2.0f; // x = 2.2f now
		testTan = atanf(x);
		testSin = sinf(x);
		testCos = cosf(x);

	}
}
