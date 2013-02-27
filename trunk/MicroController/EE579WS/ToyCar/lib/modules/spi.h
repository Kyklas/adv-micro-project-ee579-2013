/*
* Copyright (c) 2012, Alexander I. Mykyta
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met: 
* 
* 1. Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer. 
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution. 
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
* \addtogroup MOD_SPI SPI Bus
* \brief Provides basic functions for the MSP430 SPI controller
* \author Alex Mykyta
*
* This module abstracts out the SPI controller to operate as a master to slave-only peripherals. \n
*
* <b> MSP430 Processor Families Supported: </b>
*	- MSP430x5xx
*	- MSP430x6xx
*
* <b> Compilers Supported: </b>
*	- TI CCS v4
*
* \{
**/

/**
* \file
* \brief Include file for \ref MOD_SPI "SPI Bus"
* \author Alex Mykyta
**/

#ifndef _SPI_H_
#define _SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "spi_config.h"
//==================================================================================================
// Defines
//==================================================================================================
/// \addtogroup SPI_DEFINES Defines 
/// \{
	/** \addtogroup DEF_SPI_MODES SPI Modes
	*	\brief Use these defines to set the SPI mode.
	*	\details Used for the \c spi_mode parameter of spiInit() \n
	*	\image html http://upload.wikimedia.org/wikipedia/commons/6/6b/SPI_timing_diagram2.svg "Various SPI modes"
	* \{ **/
#define SPI_MODE0	(0+UCCKPH) 		///< \brief CPOL = 0, CPHA = 0 \hideinitializer
#define SPI_MODE1	(0+UCCKPL+UCCKPH)	///< \brief CPOL = 0, CPHA = 1 \hideinitializer
#define SPI_MODE2	(0)				///< \brief CPOL = 1, CPHA = 0 \hideinitializer
#define SPI_MODE3	(0+UCCKPL)		///< \brief CPOL = 1, CPHA = 1 \hideinitializer
	///\}
///\}

//==================================================================================================
// Function Prototypes
//==================================================================================================
///\addtogroup SPI_FUNCTIONS Functions
///\{
	///\name Functions
	///\{
void spiInit(uint8_t spi_mode);
uint8_t spiSendByte(uint8_t data);
void spiReadFrame(uint8_t* pBuffer, uint16_t size);
void spiSendFrame(const uint8_t* pBuffer, uint16_t size);

/**
* \brief (Emulated Function) Gets a byte from the SPI device
* \param None
* \retval uint8_t Byte received
**/
#define spiGetByte()	spiSendByte(DUMMY_CHAR)
	///\}
///\}

#ifdef __cplusplus
}
#endif

#endif
///\}
