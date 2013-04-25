/*
 * ======== Standard MSP430 includes ========
 */
#include <stdint.h>
#include <msp430.h>
#include <math.h>
#include <stdlib.h>
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

#define TOCM 2.54f/250.0f
#define PI 3.1415f
#define TODEG 360.0f/(2.0f*PI)

unsigned long ltime=0;
unsigned long dtime=0;
unsigned long time=0;
float x = 0;
float y = 0;
float angle = 0;
signed int yspeed=0;
int speedTarget=0;
char buf[10];
/*
 *  ======== main ========
 */
void computePosition(int8_t mx, int8_t my);
//void drive(float x, float y, float angle);
void speedControl( int speedTarget, int speedCur, int dt);

void main()
{
	int i  = 0;
	char bufferin;
	int mx,my;
	unsigned char s =50;        // speed variable, starts at 50, but will need to be roughly 200 to start moving from complete stop
	CSL_init();                 // We have used 'Grace' to configure the timers for PWM and delays, this line includes those configs
	init_uart();                // could be done with Grace
	P2OUT|=BIT5;

	puts("MSP430 Toy Car !\n\r"); // output this line to the serial console (PuTTY or similar)
	mx=SPI_Read(0x00);
	while(mx!=0x2A)
	{
		dtime = time-ltime;
		if( dtime > 300000)
		{
			ltime = time;
			mx=SPI_Read(0x00);
			puts("\n\rMouse PID ");
			putx(mx,0);
		}
	}
	// low resolution mode for the mouse sensor
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
				speedTarget = 0;
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

			case 'c' :
				puts("\nEnter a speed value for the car ");
				stop();
				getline( buf);
				speedTarget = atoi(buf);
				puts("\n\rNew speed :  ");
				putsd((int16_t)(speedTarget));
				break;

			case 'r' :
				x=0;
				y=0;
				angle = 0;

				break;


			}
		}

		// do the calculations every 10ms
		dtime = time-ltime;
		if( dtime > 10000)
		{
			ltime = time;
			yspeed = 0; // reinit speed as will be calculated except if actually not moving
			if( SPI_Read(0x02))
			{
				mx = 0;
				my = 0;
				do
				{
					//puts("Read ");
					mx-=(int8_t)SPI_Read(0x03);
					my-=(int8_t)SPI_Read(0x04);


				}while(SPI_Read(0x02));

				computePosition(mx,my);
				i++;
				if( i%5 == 0)
				{
					i=0;
					puts("\n\r\n\rx ");
					putsd((int16_t)(x*100));
					puts("\n\ry ");
					putsd((int16_t)(y*100));
					puts("\n\ra ");
					putsd((int16_t)(angle*TODEG*100));
				}





				// get the speed ==> movement in DPI is converted in mm ==> * TOCM * 10
				// we want mm/ms, dtime is µs => dtime/1000
				// a further *100 comes in to have a non decimal value
				// the final result is in 100mm/ms
				yspeed = (1000*TOCM*my/(int)(dtime/1000));

			}

			speedControl(speedTarget,yspeed,dtime);
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
	static float alpha;
	static float dx = 0;
	static float dy = 0;

	alpha = atan2f( ((float) mx), ((float)(6*250/2.54f)) );//modification of the angle of the car within the global coordinate system
	angle -= alpha;//update total angle in radians!!!!
	dx = (float)(mx * sinf(angle));//the modification of x in the global co ordinate system
	dy = (float)(my * cosf(angle));// the modification of the y in the global co ordinate system

	// convert from dpi to cm
	x = x + (dx*TOCM);
	y = y + (dy*TOCM);


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
	time+=682;
//	if(time>333)
//		time=0;
}


#define Ki 1
#define constPWM 512
// PI correction for the speed given the Target speed, the Current speed and the time interval
void speedControl( int speedTarget, int speedCur, int dt)
{
	int speedError = 0;
	static int speedIntegral = 0;

	// no speed
	if(speedTarget == 0)
	{
		speedIntegral = 0;
		stop();
		return;
	}

	speedError = Ki * (speedCur - speedTarget );
	//speedError *= (dt/1000);
	speedIntegral -= speedError;

	/*puts("speed : ");
	putsd((int16_t)(speedCur));
	puts("\n\r");
	puts("Integral Speed : ");
	putsd((int16_t)(speedIntegral));
	puts("\n\r");*/

	if( speedIntegral > 0)
	{
		if( speedIntegral > constPWM)
		{
			speedIntegral = constPWM;
		}
		forward();
		speed( speedIntegral);
	}
	else
	{
		if( speedIntegral < -constPWM )
		{
			speedIntegral = -constPWM;
		}
		backward();
		speed( -speedIntegral);
	}
}

