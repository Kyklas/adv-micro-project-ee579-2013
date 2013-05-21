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
#include "drive.h" // This is where the forward, backward, stop, turning and speed functions are defined
#include "speedControl.h" // The speed control function
#include "angleCorrection.h" // The angle control function
#include "beep.h" // The gimmick about making the car sing !

/*
 * ======== Constants ========
 */
#define TOCM 2.54f/250.0f  // to convert a from low resolution DPI to cm
#define PI 3.1415f // PI, used to convert from radian to degree
#define TODEG 360.0f/(2.0f*PI) // used to convert an angle from radian to degree
#define DEFAULTSPD 50 // the default speed of the car
#define FINDIST 600 // the total distance (cm) that the car should travel

// if debug is requiered, display of information via serial, better be connected with a cable !
//#define DEBUG

/*
 * ======== Global variables ========
 */
unsigned long time=0; // the current time
unsigned long ltime=0; // time variable used to remember the last time the calculations were made
unsigned long dtime=0; // time variable which hold the difference between the last time and the current time
unsigned long firstTime = 0; // time variable holding the time of beginning of the simulation with the car to be able to stop at 30s
// these time variables are used at the beginning to wait for the car to be ready and during the execution to
// avoid calculation the new car position too often
float x = 0; // the x position (in cm) of the car within the global coordinates system
float y = 0; // the y position (in cm) of the car within the global coordinates system
float angle = 0; // the angle (in radians) of the car with respect to the y axis within the global coordinates systemS
int speedTarget = 0; // The wanted speed for the car
signed int yspeed=0; // The measured-calculated speed of the car

/*
 * ======== Functions ========
 */
void computePosition(int8_t mx, int8_t my); // the math model function which update x, y and angle depending on the mouse measurements
int positionControl( int xTarget, int yTarget); // the function which operate some control on the position, call angleControl and speedControl
/*
 *  ======== main ========
 */

void main()
{
	// Main variables
	char buf[10]; // buffer used to read an input (string) from the user by serial
	char bufferin; // buffer used to read an input (char) from the user by serial

	int distanceTarget = 0; // the distance before the turn (in cm)
	int angleTarget = 0; // the angle to turn (in degrees)
	float angleT=0; // the angle to turn (converted in radian so float)

	int mx, my; // The variable used to hold the mouse measurements (movement in x and y)
	// at the beginning of the program, mx can also be used to make sure that the serial connection is established

	short step = 0; // used to know the step of the program we are in : 0 : beginning, 1: turning point, 2: end
	short singing = 0; // used to know if the car should be singing while travelling
	int xF = 0; // variable containing the final position of the car (x, cm)
	int yF = 0; // variable containing the final position of the car (y, cm)

#ifdef DEBUG
	int i = 0; // general usage counter : currently used to display things once every 5 iteration of the maths model TO BE DELETED
#endif

	// Initialisation
	CSL_init();                 // We have used 'Grace' to configure the timers for PWM and delays, this line includes those configs
	init_uart();                // UART initialisation (serial), could be done with Grace


	puts("MSP430 Toy Car !\n\r"); // output this line to the serial console (PuTTY or similar) (car ID)
	mx=SPI_Read(0x00); // get the 'ready' status of the car
	while(mx!=0x2A) // while the car is not ready, repeatedly try until it is ready
	{
		dtime = time - ltime; // calculate the time since the last iteration
		if( dtime > 300000) // if we have waited long enough,try to reach the serial of the car again
		{
			ltime = time; // update the last time
			mx=SPI_Read(0x00); // read again the 'ready' status of the car
			puts("\n\rMouse PID ");
			putx(mx,0); // display the 'ready' status of the car
			P2OUT^=BIT5|BIT4;
		}
	}
	P2OUT|=BIT5;				// light on one of the LED on top of the car
	P2OUT&=~BIT4;

	// Put the mouse sensor in low resolution
	SPI_Write(0x0d,0x24);
	SPI_DelayWtR();
	mx=SPI_Read(0x0d);

	// Main loop
	while(1)
	{
		if(incount()) // If a character has been typed, analyse it
		{
			/*
                        This mainloop will take input from the user and control
                        the car based on the keys pressed. Currently, W is used
                        to go forward, S is used to go back, A and D turn left
                        and right, respectively - just like a computer game.
                        T allows to test the serial connection, L and H allow switching the low and high
                        resolution respectively

                        The space bar will stop all movement, however if you
                        press back when you are going forwards (or vice-versa)
                        then you can also stop the car. Turning works the same way

                        C allows to choose the target speed of the car, the user should
                        enter a number which would be the new speed used
                        R allows to reset the currently memorized car position
                        P allows to write the distance and the angle targetted for the main program
			 */

			// get the character typed and display its code
			bufferin = getc();
			puts("Key ");
			putd(bufferin);
			puts("\n\r");


			switch(bufferin)
			{
#ifdef DEBUG
				/***** T-L-H keys are used for outputing the mouse data, you won't need to use them ****/

				case 't' : // try to write on via serial and then check the written value
					// also try the car going forward
					SPI_Write(0x42,0x42);
					SPI_DelayWtR();
					mx=SPI_Read(0x42);
					puts("Test ");
					putx(mx,0);
					puts("\n\r");
					forward();
					speed( speedTarget);
					break;
#endif
				case 'm' :
#ifdef DEBUG
					ISR_startSong( (int*)portal);
#endif
					puts("Music on\n\r");
					singing = 1;
					break;
				case '+' :  // increase the speed (for the test)
					puts("Speed \n\r");
					speedTarget+=10;
					putsd(speedTarget);
					speed( speedTarget);
					puts("\n\r");
					break;
				case '-' :  // Diminish the speed (for the test)
					puts("Speed \n\r");
					speedTarget-=10;
					putsd(speedTarget);
					speed( speedTarget);
					puts("\n\r");
					break;
#ifdef DEBUG
				case 'l' : // put the mouse sensor in low resolution mode
					SPI_Write(0x0d,0x24);
					SPI_DelayWtR();
					mx=SPI_Read(0x0d);
					puts("low resolution ");
					putx(mx,0);
					puts("\n\r");
					break;

				case 'h' : // put the mouse sensor in high resolution mode
					SPI_Write(0x0d,0x01);
					SPI_DelayWtR();
					mx=SPI_Read(0x0d);
					puts("high resolution ");
					putx(mx,0);
					puts("\n\r");
					break;
#endif

				case ' ' : 	// Stop the car, reset the speed target
					puts("Stop \n\r");
					stop();
					speedTarget = 0;
					step = 2;
					break;
#ifdef DEBUG
				case 'w': // move forward
					puts("Forward \n\r");
					forward();
					speed(DEFAULTSPD);
					break;

				case 's': // move backward
					puts("Backward \n\r");
					backward();
					speed(DEFAULTSPD);
					break;

				case 'a': // turn left
					left();
					break;

				case 'd': // turn right
					right();
					break;
#endif

				case 'c' : // Modify the target speed, stop the car
					puts("Enter a speed value for the car.\n\r");
					stop(); // stop the car
					getline(buf); // get the target speed entry
					speedTarget = atoi(buf); // convert it from string to a number
					if( (speedTarget > 150) || (speedTarget < 0))
					{
						puts("Filthy user, you tried to overflow me! \n\r");
						startbeep(500);
						speedTarget = 15;
					}
					else
					{
						stopbeep();
					}
					puts("New speed :  \n\r"); // display the new target speed
					putsd((int16_t)(speedTarget));
					break;

				case 'r' : // reset the X, Y and angle values
					puts("Reset \n\r");
#ifdef DEBUG
					// display the calculated x, y and angle before reseting them
					putsd((int16_t)(x*100));
					puts("\n\ry ");
					putsd((int16_t)(y*100));
					puts("\n\ra ");
					putsd((int16_t)(angle*TODEG*100));
#endif
					// reset the memorized-calculated x, y and angle of the car
					x=0;
					y=0;
					angle = (float)0;
					break;

				case 'p' : // get distance and angle, launch the correction
					puts("Enter the distance before turning (cm) \n\r");
					stop(); // stop the car
					getline(buf); // get the target distance entry
					distanceTarget = atoi(buf); // convert it from string to a number
					if( (distanceTarget > 600) || (distanceTarget < 0))
					{
						puts("Filthy user, you tried to overflow me! \n\r");
						startbeep(700);
						distanceTarget = 600;
					}
					else
					{
						stopbeep();
					}
					puts("Distance :  \n\r"); // display the new target distance
					putsd((int16_t)(distanceTarget));

					puts("Enter the angle to turn (degrees, -180 to +180) \n\r");
					getline(buf); // get the target angle entry
					angleTarget = atoi(buf); // convert it from string to a number
					if( (angleTarget < -180) || (angleTarget > 180))
					{
						puts("Filthy user, you tried to overflow me! \n\r");
						startbeep(800);
						angleTarget = 0;
					}
					else
					{
						stopbeep();
					}
					puts("Angle :  \n\r"); // display the new target angle
					putsd((int16_t)(angleTarget));

					// calculate the final coordinates
					angleT = (float)angleTarget * (float)(PI/180.0f);
					xF = (int)((float)(FINDIST - distanceTarget) * sinf( angleT));
					yF = (int)(((float)(FINDIST - distanceTarget) * cosf( angleT) )) + distanceTarget;

#ifdef DEBUG
					puts("\n\rxF ");
					putsd((int16_t)(xF));
					puts("\n\ryF ");
					putsd((int16_t)(yF));
					getc();
#endif
					step = 0; // to allow moving
					firstTime = time; // to start counting for the 30s
					// sing if singing mode !
					if( singing == 1)
					{
						ISR_startSong((int*)portal);
					}
					break;

				default: // default case : warning message and do nothing
					puts("Invalid command \n\r");
					break;
			}
		}

		// Other tasks of the main : calculate the position of the car and the speed

		// 1) calculate the car position every 10ms
		dtime = time - ltime; // calculate how much time has passed since the last iteration
		if( dtime > 10000) // if the time is at least 10ms
		{
			ltime = time; // update the new last time
			yspeed = 0; // reset the calculated speed as it will be recalculated except if the car is actually not moving (allow to detect that the car is not moving anymore after it has moved once)
			if( SPI_Read(0x02)) // if there are measurements waiting to be read
			{
				mx = 0; // reset the variable holding the mouse measurements
				my = 0;
				do // get the movements during the 10ms
				{
					mx-=(int8_t)SPI_Read(0x03); // by adding the measurements for x and y
					my-=(int8_t)SPI_Read(0x04);
				}while(SPI_Read(0x02)); // as long as there are measurements to be read
				// update the car actual position using the maths model
				computePosition(mx,my);

#ifdef DEBUG
				i++;
				/* mx and my display*/
				puts("\n\rmx ");
				putsd((int16_t)(mx));
				puts(" my ");
				putsd((int16_t)(my));
				if( i%20 == 0)
				{
					i=0;
					/* x and y position as well as angle display */
					puts("\n\r\n\rx ");
					putsd((int16_t)(x));
					puts("\n\ry ");
					putsd((int16_t)(y));
					puts("\n\ra ");
					putsd((int16_t)(angle*TODEG));
				}
#endif

				// there have been new measurements so a new speed of the car can be calculated
				// get the speed ==> movement in DPI is converted in mm ==> * TOCM * 10
				// we want mm/ms, dtime is µs => dtime/1000
				// a further *100 comes in to have a non decimal value (float avoidance)
				// the final result is in 100mm/ms
				yspeed = (1000*TOCM*my/(int)(dtime/1000));
			}

			// here should be the main control function calling each sub control functions depending on the position

			//2 Control the position so as to reach the destination
			if( step == 0) // if the turning point is not reached yet
			{
				step = positionControl( 0, distanceTarget); // try to reach the turning point
			}
			// the turning point has been reached
			else if( step == 1) // if the end point is not reached yet
			{
				if( singing == 1)
				{
					ISR_startSong( (int*)starwars);
					singing = 2;
				}
				step = positionControl( xF, yF); // try to go to the end point
				step+=1; // the line above return 0 if the end is not reached, 1 iof the end is reached
				// it is requiered to continue as long as . is returned so +1
				// it is needed to stop once the end as been reached so return 2 so +1 again
			}
			else if( step == 2) // end reached, stop
			{
				if( singing == 2)
				{
					ISR_startSong( (int*)mario);
					singing = 0;
					firstTime = 0;
				}
				else if( singing == 1)
				{
					ISR_startSong( (int*)tetris);
					singing = 0;
					firstTime = 0;
				}
				straight();
				stop();
				step += 1;
			}
			else
			{
				// nothing !
			}
		}

		/* This is to flash the two LEDs on top of the car :P */
		if((P2OUT&BIT5) && ((time%600000)>300000))
		{
			P2OUT&=~BIT5;
			P2OUT|=BIT4;
		}
		else if((P2OUT&BIT4) && ((time%600000)<300000))
		{
			P2OUT&=~BIT4;
			P2OUT|=BIT5;
		}

		/* this is to stop the simulation with the car if 30sec has passed */
		if( ((time - firstTime) > 35000000) && (firstTime != 0) )
		{
			step = 2;
		}
	}
}

/* The maths model function which update the car position (x, y, angle) in the
 * global coordinate system bases on the measurements of the mouse (mx and my)
 */
void computePosition(int8_t mx, int8_t my)
{
	// variables
	float alpha; // the angle variation
	float dx = 0; // the x position variation
	float dy = 0; // the y position variation

	alpha = atan2f( ((float) mx), ((float)(6.5f*250/2.54f)) );// get the modification of the angle of the car within the global coordinate system
	angle -= alpha; // update total angle in radians
	if( angle > PI)
	{
		angle = (float)(angle - (float)(2*PI));
	}
	if( angle < -PI)
	{
		angle = (float)(angle + (float)(2*PI));
	}
	dx = (float)(my * sinf(angle));// get the modification of x in the global coordinates system
	dy = (float)(my * cosf(angle));// get the modification of the y in the global coordinates system
	// update x and y using the x and y variation previously calculated
	x = x + (dx*TOCM);
	y = y + (dy*TOCM);
}

/* Setup the watchdog timers to use for delays */
void WDT_Int()
{
	time+=682;
	ISR_playSong();
}

/* The function which deals with the position control
 * Uses the variable x, y and angle of the main
 * Take into parameter the current target (x,u)
 * Return 1 if the current position is at less than 20cm
 * from the target position or 0 otherwise
 */
int positionControl( int xTarget, int yTarget)
{

	int yD = 0; // variable holding the difference between the target position and the current position (x,cm)
	int xD = 0; // variable holding the difference between the target position and the current position (y,cm)
	float alpha2 = 0; // 'cap' angle to reach to go toward the right position
	float distance = 0; // used to hold the remaining distance to travel

#ifdef DEBUG
	puts("\n\r xt ");
	putsd((int16_t)(xTarget));
	puts("\n\r yt ");
	putsd((int16_t)(yTarget));
#endif


	xD = xTarget - x;
	yD = yTarget - y;

#ifdef DEBUG
	puts("\n\r xd ");
	putsd((int16_t)(xD));
	puts("\n\r yd ");
	putsd((int16_t)(yD));
#endif

	distance  = sqrtf( powf((float)xD,2.0f) + powf((float)yD,2.0f) );

	if( distance < 20.0f) // are we at less than 20cm from the target ? (20 cm may change)
	{
		return 1;
	}
	else // do the position control
	{
		alpha2 = atan2f( (float) xD, (float) yD ); // get the 'cap' angle

#ifdef DEBUG
		puts("\n\r angT ");
		putsd((int16_t)(TODEG*alpha2));
#endif

		speedControl( speedTarget, yspeed, dtime); // control the speed of the car
		angleCorrection( (int)(TODEG*angle), (int)(TODEG*alpha2) ); // control the angle of the car so as to reach the target position
		return 0;
	}
}
