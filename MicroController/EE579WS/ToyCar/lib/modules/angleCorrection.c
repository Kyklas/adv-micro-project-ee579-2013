// Includes
#include "angleCorrection.h"
#include "drive.h"
#include "msp430.h"

// Constant
#define THRESHOLD 5 // the angle of degrees before correction is required
#define PI 3.1415f // PI, used to convert from radian to degree
#define TODEG 180.0f/PI // used to convert an angle from radian to degree

int l = 0;
int straight = 1;
//if threshold is only 5 degrees then distance error is small
// and may not need to be compensated for.
void angleCorrection(float currentAngle)
{
	currentAngle *= TODEG;

	if(currentAngle > THRESHOLD ){
		left();
		l = 1;
		straight = 0;
	}
	else if(currentAngle < -THRESHOLD){
		right();
		l = 0;
		straight = 0;
	}
	else{
		//straighten up
		if(l == 0 && straight==0){
			left();//turn left straighten up because the car is turning right
			straight = 1;
		}
		else if (l == 1 && straight==0){
			right();//turn right to straighten up because the car is turning left
			straight = 1;
		}
	}
}
