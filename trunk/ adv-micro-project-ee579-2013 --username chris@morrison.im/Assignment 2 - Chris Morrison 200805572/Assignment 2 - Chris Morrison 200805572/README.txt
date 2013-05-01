README:

This program will run on the M16C and will light 4 LEDs in a specific order, getting faster or 
slower, based on where the potentiometer on the M16C is turned to. At the mid-point, the LEDs will turn off briefly 
before reversing direction and gradually speeding up again, as the potentiometer is turned toward the extreme end.
At each end of the potentiometers values, the delay between the LEDs changing will be 1/10th of a second.

The program calculates the corresponding delay value at each position that the ADC can be at by using the 
equation of a line (y = mx + c). Since we know that at each end of the potentiometer (0 and 255), the delay has 
to be 1/10th of a second, we know that the point (0,0.1) exists on the graph. Assuming that the other end is half as
fast, ie. 0.2 of a second, we can use these two points to work out m and c for the graph. 

Since there needed to be a deadzone in the functionality, the two sides of the graph were established to be from 0
to 121 and from 134 to 255, with 121 - 134 being designated as the deadzone. Therefore, using the points (0,0.1) and
(121,0.2) (and knowing c = 0.1) we could establish that m = 0.0008. Creating a function that took values from 0 to 121,
multiplied them by 0.0008 and added 0.1 (left()) could return the correct time delay for each corresponding values of the ADC, 
without having to set up discrete levels or use complicated switch/case structures.


Graph1:
(y = Delay between light flashing)
1/5 sec _______
|      /       \
|     /         \
|    /           \ 
|   /             \
|  /               \
| /                 \
|/  <-1/10 second    \
|_____121_____134_____\255__
(x = Value of Potentiometer)



(Apologies for shocking ASCII art)