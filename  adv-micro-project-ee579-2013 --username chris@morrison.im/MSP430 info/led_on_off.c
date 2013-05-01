/*
 * main.c
 */
/* General includes --------------------------------------------------------*/
#include <msp430x22x4.h>
#include <stdlib.h>

void Delay(unsigned short Count);
void StartPWMLed(unsigned char PWMPeriod, unsigned char DutyCycle, int LED);
void StopPWMLed(int LED);

#define LED1            BIT1                        // P4.1 Output: LED1 (Green LED)
#define LED2            BIT2                        // P4.2 Output: LED2 (Red LED)

void main(void) {

    // Clock system configuration
    WDTCTL   = WDTPW + WDTHOLD;                        // Stop WDT
    BCSCTL3 |= (XCAP0 + XCAP1);                        // Set ACLK Capacity to 12.5 pF
    BCSCTL1  = CALBC1_1MHZ;                            // DCO = 1MHz
    DCOCTL   = CALDCO_1MHZ;

    P4DIR   |= LED1 + LED2;                         // P4.1 or P4.2 output
    P4SEL   |= LED1 + LED2;                            // P4.1 or P4.2 TBx options

    // Enable interrupts
    _EINT();

    while(1)
    {
        StartPWMLed(128, 64, LED1);
        Delay(32768/2);
        StopPWMLed(LED1);

        StartPWMLed(128, 4, LED2);
        Delay(32768/2);
        StopPWMLed(LED2);
    }
}

void Delay(unsigned short Count)
{
    TACCTL0 &= ~CCIFG;                                // Reset CCIFG Interrupt Flag
    TACCTL0 = CCIE;                                 // TACCR0 interrupt enabled
    TACTL = TASSEL_1 + MC_1;                        // Timer A select, clock source ACLK, count up to TACCR0, activate Interrupt Request
    TACCR0 = Count - 1;                                // Clock Count/32'768 s, load Capture Compare of Timer A
    __bis_SR_register(LPM0_bits);                     // Enter LPM3, enable interrupts, only TIMERA Interrupt available
}

void StartPWMLed(unsigned char PWMPeriod, unsigned char DutyCycle, int LED)
{
    TBCCR0 = PWMPeriod - 1;                            // PWM Period

    if(LED == LED1)                // PWM on P4.1
    {
        TBCCTL1 = OUTMOD_6;                            // TBCCR1 Toggle/set
        TBCCR1 = DutyCycle - 1;                        // TBCCR1 PWM duty cycle
        TBCCR2 = 0;                                    // TBCCR2 PWM duty cycle
    }
    else                        // PWM on P4.2
    {
        TBCCR1 = 0;                                    // TBCCR1 PWM duty cycle
        TBCCTL2 = OUTMOD_6;                            // TBCCR2 Toggle/set
        TBCCR2 = DutyCycle - 1;                        // TBCCR2 PWM duty cycle
    }
    TBCTL = TBSSEL_1 + MC_1;                        // ACLK. Up mode: the timer counts up to TBCL0
}

void StopPWMLed(int LED)
{
    TBCCR0 = 0;                                        // PWM Period

    if(LED == LED1)                // PWM on P4.1
    {
        TBCCR1 = 0;                                    // TBCCR1 PWM duty cycle
    }
    else                        // PWM on P4.2
    {
        TBCCR2 = 0;
    }
    TBCTL = TBSSEL_1 + MC_0;                        // ACLK. Stop mode: the timer is halted
}

// Timer A0 interrupt service routine
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A(void)
{
    TACCR0 = 0;                                        // Stop TIMERA
    TACCTL0 &= ~CCIE;                                // TACCR0 interrupt disabled
    __bic_SR_register_on_exit(LPM3_bits);            // Exit LPM3
}