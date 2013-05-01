#include <stdio.h>
#include "iom16c62p.h"
#include <intrinsics.h>

/* This global variable is the value used to control
what LEDs will light on the board. The binary 
representation will be passed to P4 and the
appropriate LEDs will light - for example decimal 15
will pass 0000000000001111 into P4, turning off all
4 LEDs. When the value is bit shifted left, the 
binary representation of the number will allow
the first LED to light ie. 0000000000011110 will
light LED 0, 0000000000111100 will light LEDs 0 and 1. */
int numVal = 15;

/* This function is called from both of the interupts
and will cause a delay of 20ms, in order to act as a 
debouncer. This function is located outside the 
interupt 'functions' because 200ms is too long to 
remain inside an interupt. */
void interuptDelay(){
      int count1 = 0; // reset the count variable
	
/* While the count hasn't reached 200 itterations, 
wait for another 'delay period' (6000 processor cycles),
each delay period is 1ms, so 200 counts will make a
delay of 200ms. */	
   while(count1 <= 200){
    if(TA0IC & (1 << 3)){ // if the 3rd bit in TA0 is set, 6000 cycles has passed (1ms)...
       TA0IC &= ~(1 << 3); // ...so clear the bit, add to the count and start again
       count1++;
      }
	  // ...else do nothing, repeat and check again
    }
  
}

#pragma vector = INT0                 //specify interrupt to be called
__interrupt void sw_int0 (void)
  {          
    numVal = numVal << 1; // Shift the bits in the global variable by 1 to the left
	// This has the effect of adding 1 more LED to the number that are lit already.
	
    interuptDelay(); // now wait for 200ms (debouncing)
  }

#pragma vector = INT1 // specify interrupt to be called
__interrupt void sw_int1 (void)
  {                       
    numVal = numVal << 2; // Shift the bits in the global variable by 2 to the left
	// This has the effect of adding 2 more LED to the number that are lit already.
    
    interuptDelay(); // now wait for 200ms (debouncing)
  }


/* This function will called once, at the start of
the program. It performs the initial setup on the 
timer, interrupts and P4 variables */
void timerSetup(){
    /* Set-up interrupts */
    INT0IC = 0xFF; // set interupt level - INT0
    INT1IC = 0xFF; // set interupt level - INT1
  __enable_interrupt(); // enable all interrupts
  
  /* Set-up timers */
    TA0MR = 0x00;  // free running mode
	TA0 = 6000; // 6000 cycles @ 6 Mhz = 1ms
  
    TABSR |= 0x01; // start the timer to run in the background
  
    PD4 = 0xFF; // set P4 as an output
	P4 = 0x00; // turn all LEDs off
}


int main(void){
 timerSetup(); // set-up the timer, interrupts and output pins

   int counter = 0; // reset the counter
   while(1){ // main program loop
     
    if(TA0IC & (1 << 3)){ // check the 3rd bit of the timer, if is set...
       TA0IC &= ~(1 << 3); // ...clear the bit
       counter++; // ... and add 1 to the counter
       if(counter == 1000){ // now, if the timer has been set 1000 times (1 second)...
         if(numVal >= 15){ /* ... and the number is greater than 15 
		 (it cannot ever be less than 15 or there won't be enough 1s in the bottom 4 bits of NumVal and the uppermost LEDs will
		 start to turn on, ie. 0000000000000111 will light LED 4) */
          numVal = numVal >> 1;  // if a second has been reached, bit shift to the right, reducing the number of lit LEDs by 1.
          counter = 0; // ... and reset the counter
         }
       }
    }
    
	// If the timer hasn't reached 1 second yet...
   if(numVal == 15){
      // If the global variable is 15, do nothing to it
    }
    else if (numVal < 15){
	// if it is less than 15, set it to 15, since 15 is the lowest number that should be passed to P4
      numVal = 15;
    }
    else if(numVal > 240){
		// if it is above 240 (ie. 0000000011110000), then set it to 240, since this is the largest value that should be passed to 240
       numVal = 240;  
    }
	// Pass the global variable to P4, which will light the LEDs acording to the value.
    P4 = numVal;
   }
}