// Simple Test


#include <iom16c62p.h>


      .NAME main
      .PUBLIC main

      .RSEG DATA16_N
msec   DS16 1 // number of milliseconds
led    DS16 1

      .RSEG CODE
main:  
      FSET I // enable interupts for debugging
      MOV.B #0x0F, PD4 // data direction registers
      MOV.B #0x0A, P4 // turn on 2 LEDs
      MOV.B #0, TA0MR // free running reloaded timer mode
      MOV.W #30583, led // put 101010101010101010101 into led
      MOV.W #6000, TA0 // 6000 clicks at 6Mhz = 1ms
      BCLR 0, UDF // set down count
      MOV.W #0, msec // initialise millisecond count
      BSET 0, TABSR // start the timer
      
        /* These 3 lines set up the timer in free running mode */
      MOV.B 0x20, ADCON1 
      MOV.B 0x00, ADCON2
      MOV.B 0xC8, ADCON0
      
mainloop:
      BTST 3, TA0IC // loop until TA0 times out - bit test 3rd bit
      JZ mainloop // jump on zero to mainloop
      BCLR 3, TA0IC // clear 2 (or 3?) bits from TA0IC
      ADD.W #1, msec // a millisecond has passed, so count it
      CMP.W #100, msec // have we reached a second yet?
      JNZ mainloop // if not, loop
      
      
      MOV.W AD0, R1 // get the value of the ADC
      CMP.W #127, R1 
      JLT reverse
      
      ROT.W #1, led // rotate 101010101 by 1 position
      MOV.W led, P4 // move this number to led#
      JMP finish
      
reverse:
      ROT.W #-1, led
      MOV.W led, P4
   
finish:   
      MOV.W #0, msec // reset counter
      JMP mainloop // start again
      .END main
    
    
    // get the value of the ADC
    // ROT 1 or minus 1 based on position of ADC
    // change value of timer based on exact position of ADC

 
  
  
  
  