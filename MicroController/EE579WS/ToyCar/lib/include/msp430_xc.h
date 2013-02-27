/**
* \file
* \brief MSP430 Cross-Compiler Header
* \author Alex Mykyta
* Include file for all MSP430 device variants. \n
* This code currently allows for:
*	- MSPGCC - the GNU tools for the MSP430
*	- Rowley Crossworks
*	- Code Composer Studio 4
*	- Code Composer Studio 5
**/
		
#ifndef __MSP430_XC_H__
#define __MSP430_XC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <isr_xc.h>

//--------------------------------------------------------------------------------------------------
#if defined(__CROSSWORKS_MSP430)
	// Crossworks for MSP430
	#include <msp430.h>
	
	// MSP430 Intrinsics
	// _EINT()
	// _DINT()
	
	// main() return value
	#define MAIN_RET_t		void
	#define MAIN_RETURN		return
	
//--------------------------------------------------------------------------------------------------
#elif defined(__GNUC__) && defined(__MSP430__)
	// MSPGCC
	#include <msp430.h>
	
	// MSP430 Intrinsics
	#define __no_init    __attribute__ ((section (".noinit"))) 
	#define __get_SR_register	__read_status_register
	#define __even_in_range(x,y)	( x ) // disables CCS intrinsic
	
	// main() return value
	#define MAIN_RET_t		int
	#define MAIN_RETURN		return(0)
	
//--------------------------------------------------------------------------------------------------
#elif defined(__TI_COMPILER_VERSION__)
	// TI's Code Composer Studio
	#include <msp430.h>

	// main() return value
	#define MAIN_RET_t		void
	#define MAIN_RETURN		return
	
//--------------------------------------------------------------------------------------------------
#else
	#error "Environment not supported yet."
#endif

#ifdef __cplusplus
}
#endif

#endif

