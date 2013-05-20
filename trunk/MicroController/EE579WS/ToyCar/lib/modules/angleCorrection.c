// Includes
#include "angleCorrection.h"
#include "drive.h"
#include "msp430.h"

// Constant
#define THRESHOLD 5 // the angle of degrees before correction is required
#define PI 3.1415f // PI, used to convert from radian to degree
#define TODEG 180.0f/PI // used to convert an angle from radian to degree

//if threshold is only 5 degrees then distance error is small
// and may not need to be compensated for.
// this whole function
void angleCorrection(int currentAngle, int targetAngle)
{

	if(currentAngle > targetAngle + THRESHOLD )
	{
		left();
		//puts("\n\rleftCorr");
	}
	else if(currentAngle < targetAngle - THRESHOLD)
	{
		right();
		//puts("\n\rrightCorr");
	}
	else
	{
		straight();
		//puts("\n\rstrCorr");
	}
}
