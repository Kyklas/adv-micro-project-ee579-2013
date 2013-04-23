/*
 * ======== Standard MSP430 includes ========
 */
#include <stdint.h>
#include <msp430.h>
#include <math.h>
/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/csl/CSL.h>

/*
 * ======== Lib modules includes ========
 */
#include "spi.h" // this is for the mouse
#include "uart_io.h" // again, for the mouse
#include "drive.h" // This is where the forward, back and speed functions are defined


unsigned short time; 
int mx,my;
float x =0, y=0;
float alpha =0, delta_x=0, delta_y=0;
float angle = 0;
float distance_travelled = 0;
int distance_till_turn;
int angle_to_turn;

boolean beforeTurn = true;
boolean duringTurn = false;
boolean afterTurn = false;

/*
 *  ======== main ========
 */
void main()
{
	char bufferin;
	unsigned char s =100;	// speed variable, starts at 50, but will need to be roughly 200 to start moving from complete stop
	CSL_init();                     // We have used 'Grace' to configure the timers for PWM and delays, this line includes those configs
	init_uart();			// could be done with Grace
	P2OUT|=BIT5;


	puts("MSP430 Toy Car !\n\r"); // output this line to the serial console (PuTTY or similar)
	mx=SPI_Read(0x00);
	while(mx!=0x2A)
	{
		while(time<300);
		mx=SPI_Read(0x00);
		puts("\n\rMouse PID ");
		putx(mx,0);
	}
	while(1)
	{
		if(incount())
		{
			/*
			This mainloop will take input from the user and control
			the car based on the keys pressed. Currently, W is used
			to go forward, S is used to go back, A and D turn left
			and right, respectively - just like a computer game.

			The space bar will stop all movement, however if you
			press back when you are going forwards (or vice-versa)
			then you can
			 */
			bufferin = getc();
			puts("Key ");
			putd(bufferin);
			puts("\n\r");


			mx=SPI_Read(0x02);
			if(mx)
			{
				computePosition();

			}

		}
	}

	void computePosition(){
		mx=(int8_t)SPI_Read(0x03); //change measured in x (orthogonal to the car)
		my=(int8_t)SPI_Read(0x04);//change measured in y (colinear to the car)
		alpha = atan(mx / (6*250/2.54));//modification of the angle  of the car within the global co ordinate system
		angle = angle - alpha;//update total angle in radians!!!!
		dx = mx * sin(angle);//the modification of x in the global co ordinate system
		dy = my * cos(angle);// the modification of the y in the gloabl co ordinate system
		x = x + dx;// The current x position in dots per inch 250 dpi
		y = y + dy;// The current y position  in dots per inch 250 dpi
		// convert from dpi to cm
		x = (x/250)*2.54 ;
		y= (y/250)*2.54;

		drive(x, y,angle);
	}

	/**
	 * @param x is current x in cm
	 * @paramm y is current y in cm
	 * @param angle is current angle in radians
	 */
	void drive(float x, float y, float angle){
		if(beforeTurn){
			if(y < distance_till_turn){
				forward();
				speed(s);
			}
			else {
				stop();
				beforeTurn = false;
				duringTurn = true;
			}

			if(angle < -3){
				right();
			}
			else if(angle >3){
				left();
			}

			distance_travelled = y;
		}
		else if(duringTurn){
			if(angle - angle_given > 0)
			{
				forward();
				speed(s/2);
				left();
			}
			else if( angle - angle_given < 0)
			{
				forward();
				speed(s/2);
				right();
		}
		else if (afterTurn){
			distance_travelled = distance_travelled + sqrt( pow(x,2) + pow(y,2) );

			if( distance_travelled < 6){
				forward();
				speed(s);
			}
			else {
				stop();
				beforeTurn = false;
			}

			if(angle < angle_given - 3){
				right();
			}
			else if(angle > angle_given + 3 ){
				left();
			}
		}

	}
	/* Setup the watchdog timers to use for delays */
	void WDT_Int()
	{
		time++;
		if(time>333)
			time=0;
	}
