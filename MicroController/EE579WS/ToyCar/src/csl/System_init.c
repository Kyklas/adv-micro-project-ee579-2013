/*
 *  ==== DO NOT MODIFY THIS FILE - CHANGES WILL BE OVERWRITTEN ====
 *
 *  Generated from
 *      C:/ti/grace_1_10_00_17/packages/ti/mcu/msp430/csl/system/System_init.xdt
 */

#include <msp430.h>

/*
 *  ======== System_init ========
 *  Initialize MSP430 Status Register
 */
void System_init(void)
{
    /* 
     * IFG1, Interrupt Flag Register 1
     * 
     * ~ACCVIFG -- No interrupt pending
     * ~NMIIFG -- No interrupt pending
     * ~OFIFG -- No interrupt pending
     * WDTIFG -- Interrupt pending
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    IFG1 &= ~(WDTIFG);

    /* 
     * IE1, Interrupt Enable Register 1
     * 
     * ~ACCVIE -- Interrupt not enabled
     * ~NMIIE -- Interrupt not enabled
     * ~OFIE -- Interrupt not enabled
     * WDTIE -- Interrupt enabled
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    IE1 |= WDTIE;

    /* 
     * SR, Status Register
     * 
     * ~SCG1 -- Disable System clock generator 1
     * ~SCG0 -- Disable System clock generator 0
     * ~OSCOFF -- Oscillator On
     * ~CPUOFF -- CPU On
     * GIE -- General interrupt enable
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    __bis_SR_register(GIE);
    
}
