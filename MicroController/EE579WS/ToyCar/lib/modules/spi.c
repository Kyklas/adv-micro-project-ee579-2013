
#include <msp430.h>
#include <spi.h>

/*
 * From the data sheet, defining the specified delay between operation
 * SPI_DelayWtW : Delay from write to another write
 * SPI_DelayWtR : Delay from write to a read
 * The delais are hardcoded depending on the CPU clock speed
 */

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

/*
 * Write operation : SPI_Write
 * write the value to the register address.
 *
 * the methode is timing sensitive
 * - Disabling global interrups ( remembering the state )
 * - Enable serial output ( multiplexing )
 * - sending the address value
 * - pulling interrupt to send the register value
 * - sending value
 * - wait until data sent
 * - enable global interrupt re-enable.
 */

void SPI_Write(uint8_t addr,uint8_t value)
{
	uint16_t SR = __get_SR_register() & GIE;
	__disable_interrupt();
	// Always able to send
	// while(!(UC0IFG&UCB0TXIFG)); 	// Wait to be able to send
	// enable
	P1SEL |= BIT7;
	P1SEL2 |= BIT7;
	UCB0TXBUF = addr|0x80;				// Send address
	while(!(UC0IFG&UCB0TXIFG));
	UCB0TXBUF = value;				// Send data
	while(!(UC0IFG&UCB0TXIFG));

	__bis_SR_register(SR);
}

/*
 * Read operation : SPI_Read
 * Read the value of the specified register
 * 
 * the methode is timing sensitive
 * - Disabling global interrups ( remembering the state )
 * - Enable serial output ( multiplexing )
 * - Clearing the receive flag from any previous reception
 * - send the register address
 * - pulling interrupt to send the register value
 * - Clearing the receive flag
 * - Disabling the serial output we can read the slave data
 * - wait for the the slave to read the address
 * - send dummy data so the clock is generated to get the slave data
 * - wait for data to be receive 
 * - re-enabling interrupts
 * - return the receive buffer register.
 */

uint8_t SPI_Read(uint8_t addr)
{
	uint16_t SR = __get_SR_register() & GIE;
	__disable_interrupt();

	// Always able to send
	// while(!(UC0IFG&UCB0TXIFG)); 	// Wait to be able to send
	// enable
	P1SEL |= BIT7;
	P1SEL2 |= BIT7;
	// Clearing the receive flag from any previous reception
	UC0IFG &= ~UCB0RXIFG;
	__delay_cycles(6);
	UCB0TXBUF = addr&0x7F;				// Send address
	// Wait until the receiver get the data
	// since bidirectional bus, we also get the data
	while(!(UC0IFG&UCB0RXIFG));
	// read mode, switch off master output.
	UC0IFG &= ~UCB0RXIFG;
	P1SEL2 &= ~BIT7;
	P1SEL &= ~BIT7;
	__delay_cycles(60); // Wait at least 5 us @12MHz gives 48 cycles
	UCB0TXBUF = 0x5A;	// Send anything to enable the clock and get the data
	// wait for the data.
	while(!(UC0IFG&UCB0RXIFG));
	__delay_cycles(6);	// wait at least 250 ns @12MHz could be omitted because CPU is slow enough
	__bis_SR_register(SR);
	return UCB0RXBUF;
}
