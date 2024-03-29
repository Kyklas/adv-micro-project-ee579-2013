// Includes
#include "speedControl.h"
#include "drive.h"
#include "msp430.h"

// Constant
#define Ki 1 // the integral action of the speed correction factor
#define constPWM 512 // the number of step of the PWM (the range)
#define thresholdPWM 230 // the threshold allowing to maintain the movement

// PI correction for the speed given a target speed, a current speed and a time interval
// now includes a hysteresis behavior so as to avoid stopping
void speedControl( int speedTarget, int speedCur, int dt)
{
	static int speedError = 0;
	static int speedIntegral = 0;
	static int goingForward=0;

	// if the speed target is 0, stop the car and reset the integral variable
	if(speedTarget == 0)
	{
		speedIntegral = 0;
		stop();
		return;
	}


	speedError = Ki * (speedCur - speedTarget ); // calculate the speed error
	//speedError *= (dt/1000); // apply the time interval effet (for now removed as buggy)
	speedIntegral -= speedError; // get the new integral control value
	// TO BE REMOVED ***************************************************************************
	/*puts("speed : ");
	putsd((int16_t)(speedCur));
	puts("\n\r");
	puts("Integral Speed : ");
	putsd((int16_t)(speedIntegral));
	puts("\n\r");*/
	// END OF TO BE REMOVED ************************************************************************

	// Do the actual control
	if( speedIntegral > 0) // if we are no going fast enough
	{
		if( goingForward != -1) // if we are not going backward, proceed normally
		{
			if( speedIntegral > constPWM) // limit the integral action to the range of the PWM
			{
				speedIntegral = constPWM;
			}
			goingForward = 1;
			forward();
			speed( speedIntegral); // go forward at the speed given by the integral control
		}
		else // if we were going backward
		{
			if( speedIntegral > constPWM) // limit the integral action to the range of the PWM
			{
				speedIntegral = constPWM;
			}
			if( speedIntegral < thresholdPWM) // if we have not reached the threshold, continue to go backward at the maintaining speed
			{
				speedIntegral = thresholdPWM;
				backward();
				speed( speedIntegral);
			}
			else // if we have reached the threshold, go forward again
			{
				goingForward = 1;
				forward();
				speed( speedIntegral);
			}
		}
	}
	else
	{
		if( goingForward != 1) // if we are not going forward, proceed normally
		{
			if( speedIntegral < -constPWM ) // limit the integral action to the range of the PWM
			{
				speedIntegral = -constPWM;
			}
			// idea there : why not just stopping instead of going backward (note may not change anything...)
			goingForward = -1;
			backward();
			speed( -speedIntegral);
		}
		else // if we were going forward
		{
			if( speedIntegral < -constPWM) // limit the integral action to the range of the PWM
			{
				speedIntegral = -constPWM;
			}
			if( speedIntegral < -thresholdPWM) // if we have not reached the threshold, continue to go backward at the maintaining speed
			{
				speedIntegral = -thresholdPWM;
				backward();
				speed( -speedIntegral);
			}
			else // if we have reached the threshold, go forward again
			{
				goingForward = 1;
				forward();
				speed( speedIntegral);
			}
		}
	}
}
