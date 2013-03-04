
#include <msp430.h>
#include <spi.h>


void SPI_DelayWtW()
{
	// wait for at least 30us
	// CPU 12MHz => 360
	__delay_cycles(400);
}
void SPI_DelayWtR()
{
	// wait for 20us
	// CPU 12MHz => 240
	__delay_cycles(300);
}

void SPI_Write(uint8_t addr,uint8_t value)
{
	uint16_t SR = __get_SR_register() & GIE;
	__disable_interrupt();
	// Always able to send
	// while(!(UC0IFG&UCB0TXIFG)); 	// Wait to be able to send
	// enable
	P1SEL2 |= BIT7;
	P1SEL |= BIT7;
	UCB0TXBUF = addr;				// Send address
	while(!(UC0IFG&UCB0TXIFG));
	UCB0TXBUF = value;				// Send data
	while(!(UC0IFG&UCB0TXIFG));

	__bis_SR_register(SR);
}
uint8_t SPI_Read(uint8_t addr)
{
	uint16_t SR = __get_SR_register() & GIE;
	__disable_interrupt();

	// Always able to send
	// while(!(UC0IFG&UCB0TXIFG)); 	// Wait to be able to send
	// enable
	P1SEL2 |= BIT7;
	P1SEL |= BIT7;
	UCB0TXBUF = addr;				// Send address
	// Wait until the receiver get the data
	// since bidirectional bus, we also get the data
	while(!(UC0IFG&UCB0RXIFG));
	// read mode, switch off master output.
	UC0IFG &= ~UCB0RXIFG;
	P1SEL2 &= ~BIT7;
	P1SEL &= ~BIT7;
	__delay_cycles(60); // Wait at least 5 us @12MHz gives 48 cycles
	UCB0TXBUF = 0xFF;	// Send anything to enable the clock and get the data
	// wait for the data.
	while(!(UC0IFG&UCB0RXIFG));
	//__delay_cycles(3);	// wait at least 250 ns @12MHz could be omitted because CPU is slow enough
	__bis_SR_register(SR);
	return UCB0RXBUF;
}
