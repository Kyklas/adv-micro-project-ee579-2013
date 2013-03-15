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
#include "spi.h"
#include "uart_io.h"

unsigned short time;

/*
 *  ======== main ========
 */
void main()
{
    char bufferin;
    int mx,my;
	CSL_init();                     // Activate Grace-generated configuration
    init_uart();			// could be done with Grace
    P2OUT|=BIT5;

    puts("MSP430 Toy Car !\n\r");
    mx=SPI_Read(0x00);
    while(mx!=0x2A)
    {
		while(time<300);
		mx=SPI_Read(0x00);
		puts("\n\rMouse PID ");
		putx(mx,0);
    }
    while(1)
    {
    	if(incount())
    	{
    		bufferin = getc();
    		switch(bufferin)
    		{
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
    		}
    	}
    	mx=SPI_Read(0x02);
    	if(mx)
		{
			//puts("Read ");
			mx=(int8_t)SPI_Read(0x03);
			my=(int8_t)SPI_Read(0x04);
			putsd(mx);
			puts(" ");
			putsd(my);
			puts("\n\r");
		}

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

void WDT_Int()
{
	time++;
	if(time>333)
		time=0;
}
