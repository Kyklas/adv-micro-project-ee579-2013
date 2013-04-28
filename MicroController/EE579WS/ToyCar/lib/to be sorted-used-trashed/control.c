#include "control.h"
#include "msp430.h"

// Motor Control
//
// Inputs
// curPos : current position
// prePos : previous position
// wanPos : wanted position
// curPow : current power to send to the motors
//

// Output
// new power to send to the motors

// Behavior
// While current position < wanted position, output is positive power
// If the current position - previous position > 0, send same power, else increase the power
// (it deals with the case where the car cannot start to move because the power level is not high enough)

int motorControl( int curPos, int prePos, int wanPos, int curPow)
{
    if( curPos < wanPos)
    {
        if( curPos - prePos <= 0)
        {
            return(curPow + 5);
        }
        else
        {
            return(curPow);
        }
    }
    else
    {
        return(0);
    }
}
