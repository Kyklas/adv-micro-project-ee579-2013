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
float x = 0;
float y = 0;
float angle = 0;
/*
 *  ======== main ========
 */
void computePosition(int8_t mx, int8_t my);
//void drive(float x, float y, float angle);

void main()
{
	char bufferin;
	int mx,my;
	unsigned char s =50;        // speed variable, starts at 50, but will need to be roughly 200 to start moving from complete stop
	CSL_init();                     // We have used 'Grace' to configure the timers for PWM and delays, this line includes those configs
	init_uart();                        // could be done with Grace
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

	SPI_Write(0x0d,0x24);
	SPI_DelayWtR();
	mx=SPI_Read(0x0d);

	while(1)
	{
//		forward();
//		speed(100);
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


			switch(bufferin)
			{
			/***** These keys are used for outputing the mouse
                        data, you won't need to use them ****/
			case 't' :
				SPI_Write(0x42,0x42);
				SPI_DelayWtR();
				mx=SPI_Read(0x42);
				puts("Test ");
				putx(mx,0);
				puts("\n\r");
				break;
			case 'l' :
				SPI_Write(0x0d,0x24);
				SPI_DelayWtR();
				mx=SPI_Read(0x0d);
				puts("low resolution ");
				putx(mx,0);
				puts("\n\r");
				break;
			case 'h' :
				SPI_Write(0x0d,0x01);
				SPI_DelayWtR();
				mx=SPI_Read(0x0d);
				puts("high resolution ");
				putx(mx,0);
				puts("\n\r");
				break;
				/********************************/

				// Pressing U will increase the speed
				// The speed value is between 0 and 255
				// Once the speed reaches 255 or 0, it will loop around (ie. 255++ = 0)
			case 'u' :
				puts(" Speed Up \n\r");
				s++;
				putd(s);
				putc(' ');
				speed(s);
				putd(TA1CCR1);
				break;
				// Decrease speed
			case 'n' :
				puts(" Speed down \n\r");
				s--;
				putd(s);
				putc(' ');
				speed(s);
				putd(TA1CCR1);
				break;

				// Stop everything
			case ' ' :
				puts("Stop \n\r");
				stop();
				break;

				// Forward
			case 'w':
				puts("Forward \n\r");

				forward();
				speed(s);
				break;

				// Backwarsd
			case 's':
				puts("Backward \n\r");

				backward();
				speed(s);
				break;

				// Left & Right
			case 'a':
				left();
				break;
			case 'd':
				right();
				break;
				/*
                        default:
                                puts("Invalid command \n\r");
                                break;
				 */

			}
		}
		mx=SPI_Read(0x02);
		if(mx)
		{
			//puts("Read ");
			mx=(int8_t)SPI_Read(0x03);
			my=(int8_t)SPI_Read(0x04);

			computePosition(mx,my);

			putsd((int16_t)(x*100));puts("\n\ry ");
			putsd((int16_t)(y*100));puts("\n\ra ");
			putsd((int16_t)(angle*100));puts("\n\r\n\rx ");
		}



		/* This is to flash the two LEDs on top of the car :P */
		if(P2OUT&BIT5 && time>150)
		{
			P2OUT&=~BIT5;
			P2OUT|=BIT4;
			continue;
		}
		if(P2OUT&BIT4 && time<150)
		{
			P2OUT&=~BIT4;
			P2OUT|=BIT5;
			continue;
		}
	}
}


void computePosition(int8_t mx, int8_t my){
	float alpha;
	float dx = 0;
	float dy = 0;

	alpha = atanf((float) mx / (6*250/2.54));//modification of the angle  of the car within the global co ordinate system
	angle = angle - alpha;//update total angle in radians!!!!
	dx = mx * sinf(angle);//the modification of x in the global co ordinate system
	dy = my * cosf(angle);// the modification of the y in the gloabl co ordinate system

	// convert from dpi to cm
	x = x + (dx/250)*2.54 ;
	y= y + (dy/250)*2.54;


	//drive(x, y,angle);
}

/**
 * @param x is current x in cm
 * @paramm y is current y in cm
 * @param angle is current angle in radians
 */
//void drive(float x, float y, float angle){
//	if(beforeTurn){
//		if(y < distance_till_turn){
//			forward();
//			speed(100);
//		}
//		else {
//			stop();
//			beforeTurn = 0;
//			duringTurn = 1;
//		}
//
//		if(angle < -3){
//			right();
//		}
//		else if(angle >3){
//			left();
//		}
//
//		distance_travelled = y;
//	}
	//		else if(duringTurn){
	//			if(angle - angle_given > 0)
	//			{
	//				forward();
	//				speed(s/2);
	//				left();
	//			}
	//			else if( angle - angle_given < 0)
	//			{
	//				forward();
	//				speed(s/2);
	//				right();
	//		}
	//		else if (afterTurn){
	//			distance_travelled = distance_travelled + sqrt( pow(x,2) + pow(y,2) );
	//
	//			if( distance_travelled < 6){
	//				forward();
	//				speed(s);
	//			}
	//			else {
	//				stop();
	//				beforeTurn = 0;
	//			}
	//
	//			if(angle < angle_given - 3){
	//				right();
	//			}
	//			else if(angle > angle_given + 3 ){
	//				left();
	//			}
	//		}

//}

/* Setup the watchdog timers to use for delays */
void WDT_Int()
{
	time++;
	if(time>333)
		time=0;
}
