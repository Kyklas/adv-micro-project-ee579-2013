/*
 *  This file is automatically generated and does not require a license
 *
 *  ==== WARNING: CHANGES TO THIS GENERATED FILE WILL BE OVERWRITTEN ====
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 *  ==== ALL OTHER CHANGES WILL BE OVERWRITTEN WHEN IT IS REGENERATED ====
 *
 *  This file was generated from
 *      C:/ti/grace_2_00_01_65/packages/ti/mcu/msp430/csl/timer/ITimerx_A_init.xdt
 */

#include <msp430.h>

/* USER CODE START (section: Timer1_A3_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: Timer1_A3_init_c_prologue) */

/*
 *  ======== Timer1_A3_graceInit ========
 *  Initialize MSP430 Timer1_A3 timer
 */
void Timer1_A3_graceInit(void)
{
    /* USER CODE START (section: Timer1_A3_graceInit_prologue) */
    /* User initialization code */
    /* USER CODE END (section: Timer1_A3_graceInit_prologue) */
    
    /* 
     * TA1CCTL1, Capture/Compare Control Register 1
     * 
     * CM_0 -- No Capture
     * CCIS_0 -- CCIxA
     * ~SCS -- Asynchronous Capture
     * ~SCCI -- Latched capture signal (read)
     * ~CAP -- Compare mode
     * OUTMOD_7 -- PWM output mode: 7 - PWM reset/set
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    TA1CCTL1 = CM_0 + CCIS_0 + OUTMOD_7;

    /* TA1CCR0, Timer_A Capture/Compare Register 0 */
    TA1CCR0 = 59999;

    /* TA1CCR1, Timer_A Capture/Compare Register 1 */
    TA1CCR1 = 30030;

    /* 
     * TA1CTL, Timer_A3 Control Register
     * 
     * TASSEL_2 -- SMCLK
     * ID_2 -- Divider - /4
     * MC_1 -- Up Mode
     */
    TA1CTL = TASSEL_2 + ID_2 + MC_1;

    /* USER CODE START (section: Timer1_A3_graceInit_epilogue) */
    /* User code */
    /* USER CODE END (section: Timer1_A3_graceInit_epilogue) */
}
