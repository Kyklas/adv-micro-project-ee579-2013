README:

Run 'main.c' on an M16C microcontroler.

This project does four main things;
- when Button 1 is pressed, one LED is lit out of the 4 on the M16C
- when Button 2 is pressed, two LED's will be lit on the board
- the LEDs will light in an order, starting at the bottom (LED 0) and lighting up (one or two at a time) in order until all four are lit
- after every second, the highest numbered LED will turn off

In order to control what LEDs would be lit and when, a global variable in the code ('numVal') is used. In the main loop of the code, this variables value is passed to P4 and the appropriate number of LEDs will be lit. By setting and changing the value of this global variable, the number of LEDs that are lit can be easily controled.

The code starts with numVal being set to 15 (binary = 0000000000001111) which gives four 1's to be passed to P4. This will turn off all four LEDs, however these four 1's can then be moved up and down using bitshift opperations, allowing the number of lit LEDs to be increased or decreased without previously knowing the number of LEDs that are already lit. 

This means that when Button 1 is pressed, the value in numVal will be bitshifted left by one, so however many LEDs are already lit, one more will be added. When Button 2 is pressed, the value will be bitshifted by 2, increaseing the number lit by 2. Every second, the code will bitshift by 1 to the right, decreasing the number of LEDs lit, by one.

When the value in numVal reaches 240, binary 0000000011110000, it will not be incremented any more, regardless of how many times the button it pressed, this is so that after a second (when the value is bitshifted right), the uppermost LED will turn off. The same happens at the other end of the scale, the value cannot go lower than 15, so that when a button is pressed, the 1s in the variable will still be there.