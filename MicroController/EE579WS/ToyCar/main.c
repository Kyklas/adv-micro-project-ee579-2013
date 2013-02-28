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

#include "uart_io.h"
/*
 *  ======== main ========
 */
void main()
{
    CSL_init();                     // Activate Grace-generated configuration
    

    init_uart();

    puts("MSP430 Toy Car !\n\r");
    puts("Loop \n\r");
    while(1)
    {
    	putd(1989);
    	__delay_cycles(1200000);
    }
}
