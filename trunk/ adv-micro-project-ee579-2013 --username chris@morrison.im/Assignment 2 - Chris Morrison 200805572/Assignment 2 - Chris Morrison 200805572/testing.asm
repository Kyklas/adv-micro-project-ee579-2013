#include <iom16c62p.h>


      //XOR.B #0x0F, P4 // second is up, so flip LEDs



      .NAME main
      .PUBLIC main

      .RSEG DATA16_N
msec   DS16 1 // number of milliseconds


      .RSEG CODE
main:  
      FSET I // enable interupts for debugging
      MOV.B #0x0F, PD4 // data direction registers
      MOV.B #0x0F, P4 // turn on no LEDs
      MOV.B #0, TA0MR // free running reloaded timer mode
      MOV.W #6000, TA0 // 6000 clicks at 6Mhz = 1ms
      BCLR 0, UDF // set down count
      MOV.W #0, msec // initialise millisecond count
      BSET 0, TABSR // start the timer
      
timer:
      BTST 3, TA0IC // loop until TA0 times out 
      JZ timer // jump on zero to mainloop
      BCLR 3, TA0IC // clear 2 (or 3?) bits from TA0IC
      ADD.W #1, msec // a millisecond has passed, so count it
      CMP.W #1000, msec // have we reached a second yet?
      JNZ timer // if not, loop
      
      
mainloop:
      BTST 3, TA0IC // loop until TA0 times out 
      JZ mainloop // jump on zero to mainloop
      BCLR 3, TA0IC // clear 2 (or 3?) bits from TA0IC
      ADD.W #1, msec // a millisecond has passed, so count it
      CMP.W #1000, msec // have we reached a second yet?
      JNZ mainloop // if not, loop
      
      MOV.B #0x0E, P4 // turn on no LEDs
      
      MOV.W #0, msec // reset counter
      
mainloop1:
      BSET 0, TABSR // start the timer
      BTST 3, TA0IC // loop until TA0 times out 
      JZ mainloop // jump on zero to mainloop
      BCLR 3, TA0IC // clear 2 (or 3?) bits from TA0IC
      ADD.W #1, msec // a millisecond has passed, so count it
      CMP.W #1000, msec // have we reached a second yet?
      JNZ mainloop1 // if not, loop
      
      MOV.B #0x0D, P4 // turn on no LEDs
      
      MOV.W #0, msec // reset counter
      
mainloop2:
      BSET 0, TABSR // start the timer
      BTST 3, TA0IC // loop until TA0 times out 
      JZ mainloop // jump on zero to mainloop
      BCLR 3, TA0IC // clear 2 (or 3?) bits from TA0IC
      ADD.W #1, msec // a millisecond has passed, so count it
      CMP.W #1000, msec // have we reached a second yet?
      JNZ mainloop2 // if not, loop
      
      MOV.B #0x0B, P4 // turn on no LEDs
      
      MOV.W #0, msec // reset counter
      
mainloop3:
      BSET 0, TABSR // start the timer
      BTST 3, TA0IC // loop until TA0 times out 
      JZ mainloop // jump on zero to mainloop
      BCLR 3, TA0IC // clear 2 (or 3?) bits from TA0IC
      ADD.W #1, msec // a millisecond has passed, so count it
      CMP.W #1000, msec // have we reached a second yet?
      JNZ mainloop3 // if not, loop
      
      MOV.B #0x07, P4 // turn on no LEDs
     
      MOV.W #0, msec // reset counter
      
      
      
      JMP mainloop // start again
      .END main
    
