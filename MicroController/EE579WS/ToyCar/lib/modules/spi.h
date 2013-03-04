
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

void SPI_DelayWtW();
void SPI_DelayWtR();
void SPI_Write(uint8_t addr,uint8_t value);
uint8_t SPI_Read(uint8_t addr);

#endif
