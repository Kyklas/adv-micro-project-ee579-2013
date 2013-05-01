#include "stdio.h"
#include "iom16c62p.h"

/* Initial setup - performed once at the start of the program */
void ADC_init(void) {
  ADCON1 = 0x20; // Vref connected
  ADCON2 = 0x00; // sets ADC without hold
  ADCON0 = 0xC8; // ADC in repeat mode
  
  
  /* we will use all 4 LEDs in this project, so set the appropriate pins
  to output mode and turn then off */
  PD4 = 0xFF;
  P4 = 0xFF;  
  
  /* setup the timer to free running mode */
  TA0MR = 0x00; 
  TA0 = 6000; // 6000 cycles @ 6 Mhz = 1ms
}


	/* This method takes an input value (provided by the ADC)
	and multiplies it by 1000 to change it into a value in seconds
	this value is the duration that the timer will then wait for	*/
void timer(float time){
  time = time * 1000; // 1000 = turns 'time' into seconds
  for(int i=0;i<time;i++){
    TABSR |= 0x01; // start timer
    while(!(TA0IC & 0x08)); // check if timer has timed out
    TA0IC &= 0xF7; // reset
  }
}


/* This method uses the equation of a line (y = mx + c) 
to calculate a value for the delay (y) based on the coresponding
value of the ADC by muliplying it by the slope of the graph (m) and adding 
the y-intercept value (see the README for more info) */
float left(float x){
  float y, m;
  m = 0.0008;
  y = (x * m) + 0.1;  
  return y;
}


/* Instead of creating another method that performs floating point
calculations, this method just translates any values on the right hand side of the 
ADC's range into a correspoinding value on the left, by 'flipping the graph' (see README)
and then feeds that value into left() */
float right(float a){
  	float b;
	b = 121-(a - 134); // convert the values from 134-155 into values from 0-121
	return left(b);
}

/* This is the method used when ADC value is in the middle 'deadzone' */
void deadzone(){
  P4 = 0xFF; // turn all LEDs off
}


/* This method will use the left() method to get a value for the 
delay between the LEDs changing, then change each of the LEDs in a specific
order, waiting for the duration given by left()*/
void goLeft(float y){
  y = left(y); // feed the ADC value into left()
  p4_0 = 0;
  timer(y); // wait for the established period of time
  p4_0 = 1;
  p4_1 = 0;
  timer(y);
  p4_1 = 1;
  p4_2 = 0;
  timer(y); 
  p4_2 = 1;
  p4_3 = 0;
  timer(y);
  p4_3 = 1;
  
}

/* This method is the same as goLeft(), but the order of the LEDs 
changing is reversed */
void goRight(float y){
  y = right(y); // feed the ADC values into right()
  p4_3 = 0;
  timer(y); // wait for the established period of time
  p4_3 = 1;
  p4_2 = 0;
  timer(y); 
  p4_2 = 1;
  p4_1 = 0;
  timer(y);  
  p4_1 = 1;
  p4_0 = 0;
  timer(y);
  p4_0 = 1;
}



/* This method first initialises the ADC, LEDs and timer, before entering
an infinite loop. Within the loop, firstly, the establishes the value that the 
potentiometer is set at, then establishes which third of the potentiometers range
that value lies within (right, left or deadzone). It then passes this value onto the corresponding 
method that will calculate a delay value based on this ADC value (or turn all the LEDs off
in the deadzone) and run the LED sequence, using this delay value between each LED changing */
int main(void){
  ADC_init(); // initialise
  
    while(1){
   
    // get potentiometer value
    float value = AD0L;  
    
	// Establish which third the value lies in
    if(value <= 121){      
       goLeft(value); 
    }
    else if(value >= 134){
      goRight(value);
    }
    else{
      deadzone(); 
    }
    
	// ensure all LEDs are turned off
    P4 = 0xFF; 
  
    
  }
   
}