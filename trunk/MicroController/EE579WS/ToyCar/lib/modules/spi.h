
/*
	Methods to communicate with A2080 sensor
	use USCI B0 of MSP430
	I/O are configure with Grace
	Speed is set to 500kHz
	CPU speed is 12MHz
*/

#ifndef __A2080_SPI__
#define __A2080_SPI__

#include <stdint.h>


/*
 * From the data sheet, defining the specified delay between operation
 * SPI_DelayWtW : Delay from write to another write
 * SPI_DelayWtR : Delay from write to a read
 * The delais are hardcoded depending on the CPU clock speed
 */
void SPI_DelayWtW();
void SPI_DelayWtR();

/*
 * Write operation : SPI_Write
 * write the value to the register address.
 */
void SPI_Write(uint8_t addr,uint8_t value);
/*
 * Read operation : SPI_Read
 * Read the value of the specified register
 */
uint8_t SPI_Read(uint8_t addr);

#endif
