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
/*
 *  ======== main ========
 */
void main()
{
    CSL_init();                     // Activate Grace-generated configuration
    init_uart();			// could be done with Grace

    puts("MSP430 Toy Car !\n\r");
    while(1)
    {
    	if(SPI_Read(0x02))
    	{
    		putsd((int8_t)SPI_Read(0x03));
    		puts(" ");
    		putsd((int8_t)SPI_Read(0x04));
    		puts("\n\r");
    	}
    }
}
