#include "drive.h"
#include "msp430.h"

void forward()
{

	if(!(P2SEL&BIT2))
	//P2SEL2|=BIT2;
	P2SEL|=BIT1;
	//P2SEL2&=~BIT1;
	else
	P2SEL&=~BIT2;

	TA1CCR1 = 0;
}
void backward()
{

	//P2SEL2|=BIT1;
	if(!(P2SEL&BIT1))
	P2SEL|=BIT2;
	//P2SEL2&=~BIT2;
	else
	P2SEL&=~BIT1;

	TA1CCR1 = 0;
}
void speed(unsigned long s)
{
	s=s*TA1CCR0;
	TA1CCR1 = (unsigned short) (s>>9);
}
void stop()
{
	//P2SEL2&=~(BIT2|BIT1);
	P2SEL&=~(BIT2|BIT1);
	TA1CCR1 = 0;
}

void right()
{
	if(!(P1OUT&BIT4))
		P1OUT |= BIT3;
	else
		P1OUT&=~BIT4;
}
void left()
{
	if(!(P1OUT&BIT3))
			P1OUT |= BIT4;
	else
		P1OUT&=~BIT3;
}
