/*
 * ======== Standard MSP430 includes ========
 */
#include <stdint.h>
#include <msp430.h>
/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/csl/CSL.h>

/*
 * ======== Lib modules includes ========
 */
#include "spi.h" // this is for the mouse
#include "uart_io.h" // again, for the mouse
#include "drive.h" // This is where the forward, back and speed functions are defined

unsigned short time; 

/*
 *  ======== main ========
 */
void main()
{
    char bufferin;
    int mx,my;
    unsigned char s =50;	// speed variable, starts at 50, but will need to be roughly 200 to start moving from complete stop
	CSL_init();                     // We have used 'Grace' to configure the timers for PWM and delays, this line includes those configs
    init_uart();			// could be done with Grace
    P2OUT|=BIT5;			

    puts("MSP430 Toy Car !\n\r"); // output this line to the serial console (PuTTY or similar)
//    mx=SPI_Read(0x00);
//    while(mx!=0x2A)
//    {
//		while(time<300);
//		mx=SPI_Read(0x00);
//		puts("\n\rMouse PID ");
//		putx(mx,0);
//    }
    while(1)
    {
    	if(incount())
    	{
		/* 
			This mainloop will take input from the user and control
			the car based on the keys pressed. Currently, W is used
			to go forward, S is used to go back, A and D turn left
			and right, respectively - just like a computer game.
			
			The space bar will stop all movement, however if you 
			press back when you are going forwards (or vice-versa)
			then you can 
		*/
    		bufferin = getc();
    		 puts("Key ");
    		 putd(bufferin);
    		 puts("\n\r");
			 
			 
    		switch(bufferin)
    		{
			/***** These keys are used for outputing the mouse 
			data, you won't need to use them ****/
    		case 't' :
					SPI_Write(0x42,0x42);
						SPI_DelayWtR();
						mx=SPI_Read(0x42);
						puts("Test ");
						putx(mx,0);
						puts("\n\r");
						break;
    		case 'l' :
    			SPI_Write(0x0d,0x24);
    			    SPI_DelayWtR();
    			    mx=SPI_Read(0x0d);
    			    puts("low resolution ");
    			    putx(mx,0);
    			    puts("\n\r");
    			    break;
    		case 'h' :
    			SPI_Write(0x0d,0x01);
    			    SPI_DelayWtR();
    			    mx=SPI_Read(0x0d);
    			    puts("high resolution ");
    			    putx(mx,0);
    			    puts("\n\r");
    			        break;
			/********************************/			
						
			// Pressing U will increase the speed
			// The speed value is between 0 and 255
			// Once the speed reaches 255 or 0, it will loop around (ie. 255++ = 0)
    		case 'u' :
    			puts(" Speed Up \n\r");
    			s++;
    			putd(s);
    			putc(' ');
				speed(s);
				putd(TA1CCR1);
				break;
				// Decrease speed
    		case 'n' :
					puts(" Speed down \n\r");
					s--;
					putd(s);
					putc(' ');
					speed(s);
					putd(TA1CCR1);
					break;
					
				// Stop everything
    		case ' ' :
    			puts("Stop \n\r");
    			stop();
    			break;
				
				// Forward
    		case 'w':
    			puts("Forward \n\r");

    			forward();
    			speed(s);
    			break;
				
			// Backwarsd
    		case 's':
    			puts("Backward \n\r");

    			backward();
    			speed(s);
    			break;
				
				// Left & Right
    		case 'a':
    		    			left();
    		    			break;
    		case 'd':
    		    			right();
    		    			break;
			/* 
			default:
				puts("Invalid command \n\r");	
				break;
			*/
			
    		}
    	}
//    	mx=SPI_Read(0x02);
//    	if(mx)
//		{
//			//puts("Read ");
//			mx=(int8_t)SPI_Read(0x03);
//			my=(int8_t)SPI_Read(0x04);
//			putsd(mx);
//			puts(" ");
//			putsd(my);
//			puts("\n\r");
//		}


		/* This is to flash the two LEDs on top of the car :P */
    	if(P2OUT&BIT5 && time>150)
    	{
    		P2OUT&=~BIT5;
    		P2OUT|=BIT4;
    		continue;
    	}
    	if(P2OUT&BIT4 && time<150)
		{
			P2OUT&=~BIT4;
			P2OUT|=BIT5;
			continue;
		}
    }
}


/* Setup the watchdog timers to use for delays */
void WDT_Int()
{
	time++;
	if(time>333)
		time=0;
}
