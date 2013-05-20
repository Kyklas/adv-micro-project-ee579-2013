#include "drive.h"
#include "msp430.h"

// function which controls the pwm in order to go forward
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

// function which controls the pwm in order to go backward
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

// function which set the power of the PWM (thus the speed 's' of the car)
void speed(unsigned long s)
{
	s=s*TA1CCR0;
	TA1CCR1 = (unsigned short) (s>>9);
}

// function which stops the car
void stop()
{
	//P2SEL2&=~(BIT2|BIT1);
	P2SEL&=~(BIT2|BIT1);
	TA1CCR1 = 0;
	//straight();
}

// function used to turn on the right
void right()
{
	//puts("\n\rrightFun");
	if(!(P1OUT&BIT4))  // Test for turning left
		P1OUT |= BIT3;
	else
		P1OUT&=~BIT4;  // Disable turning left
}

// function used to turn on the left
void left()
{
	//puts("\n\rleftFun");
	if(!(P1OUT&BIT3)) // Test for turning right
		P1OUT |= BIT4;
	else
		P1OUT&=~BIT3;  // Disable turning right
}

// function which disable any rotation
void straight()
{
	//puts("\n\rstrCorr");
	P1OUT&=~(BIT4|BIT3);  // Disable turning
}
