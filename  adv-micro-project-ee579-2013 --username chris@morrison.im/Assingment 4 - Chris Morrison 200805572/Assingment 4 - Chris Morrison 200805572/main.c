#include <stdio.h>
#include "iom16c62p.h"
#include <intrinsics.h>

/* This assingment will make an LED on the M16C breathe, like the staus light on an Apple Mac */

// This global variable will store the location that the program has reached in the array
int index = 0;

// This variable will be used like a boolean - if it is 0, the array below will traversed up
// if if it 1, the array will be traversed down
int upOrDown = 0; // 0 if up, 1 if down  

/* This array will control the various time differences that are 
changed as the LED gets further through the breathing movement. At the 
lower end of the array, the values are smaller, indicating that the delay between the light going
on and it going off it small, meaning the light will not be as bright, at the top of the
array, the values increase, making the time that the LED is on for, larger - making the 
LED brighter. As this array is traversed, the LED will get brighter and brighter, then dim, in a 
sinusoidal pattern. */
const unsigned char curve[] = {
    1,     1,     1,     1,     1,     1,     1,     1,
    1,     1,     1,     1,     1,     1,     1,     1,
    1,     1,     1,     2,     2,     2,     2,     2,
    2,     2,     3,     3,     3,     3,     3,     3,
    4,     4,     4,     4,     4,     5,     5,     5,
    5,     6,     6,     6,     6,     7,     7,     7,
    8,     8,     8,     8,     9,     9,     9,    10,
   10,    10,    11,    11,    11,    12,    12,    13,
   13,    13,    14,    14,    15,    15,    15,    16,
   16,    17,    17,    18,    18,    18,    19,    19,
   20,    20,    21,    21,    22,    22,    23,    23,
   24,    24,    25,    25,    26,    26,    27,    27,
   28,    29,    29,    30,    30,    31,    31,    32,
   33,    33,    34,    34,    35,    36,    36,    37,
   38,    38,    39,    39,    40,    41,    41,    42,
   43,    43,    44,    45,    46,    46,    47,    48,
   48,    49,    50,    50,    51,    52,    53,    53,
   54,    55,    56,    56,    57,    58,    59,    59,
   60,    61,    62,    62,    63,    64,    65,    66,
   66,    67,    68,    69,    70,    70,    71,    72,
   73,    74,    75,    75,    76,    77,    78,    79,
   80,    80,    81,    82,    83,    84,    85,    86,
   87,    87,    88,    89,    90,    91,    92,    93,
   94,    95,    95,    96,    97,    98,    99,   100,
  101,   102,   103,   104,   105,   106,   106,   107,
  108,   109,   110,   111,   112,   113,   114,   115,
  116,   117,   118,   119,   120,   121,   122,   122,
  123,   124,   125,   126,   127,   128,   129,   130,
  131,   132,   133,   134,   135,   136,   137,   138,
  139,   140,   141,   142,   143,   144,   145,   146,
  147,   148,   149,   150,   151,   152,   153,   154,
  155,   156
};

// This is the setup and will be performed once
void setup(void){
  // setup timer
  
    TA0MR = 0x00; 
  TA0 = 60; // 60 cycles @ 6 Mhz = 0.1ms
  
  // setup LEDs
     PD4 = 0xFF; // outputs
     P4 = 0xFF; // on  
}

/* This method takes an input value (provided by the ADC)
	changes it into a value in iterations of 0.1 milliseconds
	this value is the duration that the timer will then wait for	*/
void timer(int time){

  for(int i=0;i<time;i++){
    TABSR |= 0x01; // start timer
    while(!(TA0IC & 0x08)); // check if timer has timed out
    TA0IC &= 0xF7; // reset
  }
}



int main (void){
  // call the setup, performed once
 setup();
// main loop, will not end
 while(1){
   
   // if the upOrDown control variable indicates
   // that the array is to be traversed up....
   if(upOrDown == 0){
     // go up
	 // .. first check if the array index is going to be out of bounds....
     if(index >= 250){
        upOrDown = 1; // ... if it is, then reverse the direction
     }

     
      p4_1 = 0; // on
      timer(curve[index]); // turn on for the value specified by the array
      p4_1 = 1; // off
      timer((156-curve[index])); // and off for 156 minus the above value
    
        index++; // then move to the next point
   
   }
   
   
      // if the upOrDown control variable indicates
   // that the array is to be traversed down....
   else if(upOrDown == 1){ /* if upOrDown == 1 */
     // go down
     if(index <= 0){ // .. first check if the array index is going to be out of bounds....
      upOrDown = 0;   // and reverse the direction
   }
      
      p4_1 = 0; // on
      timer(curve[index]); // turn on for the value specified by the array
      p4_1 = 1; // off
      timer((156-curve[index])); // and off for 156 minus the above value
    
     index--; // and move to the next point
   }
   
 }
}