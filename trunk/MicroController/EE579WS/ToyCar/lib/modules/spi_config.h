/**
* \addtogroup MOD_SPI
* \{
**/

/**
* \file
* \brief Configuration include file for \ref MOD_SPI "SPI Bus"
* \author Alex Mykyta
**/

#ifndef _SPI_CONFIG_H_
#define _SPI_CONFIG_H_

//==================================================================================================
// SPI Config
//
// Configuration for: PROJECT_NAME
//==================================================================================================

//  ===================================================
//  = NOTE: Actual ports must be configured manually! =
//  ===================================================

/// \addtogroup SPI_DEFINES
/// \{
	/** \addtogroup DEF_SPI_CONFIG Configuration
	*	\brief Configuration defines for the SPI module
	* \{ **/


/// \brief Select which USCI module to use
#define SPI_USE_USCI	0 ///< \hideinitializer
/**<	0 = USCIA0 \n
* 		1 = USCIA1 \n
* 		2 = USCIA2 \n
* 		3 = USCIA3 \n
* 		4 = USCIB0 \n
* 		5 = USCIB1 \n
* 		6 = USCIB2 \n
* 		7 = USCIB3
**/

/// \brief Select which clock source to use
#define SPI_CLK_SRC		2 ///< \hideinitializer
/**<	1 = ACLK	\n
*		2 = SMCLK
**/

/// \brief SPI Clock division. Must be 4 or greater
#define SPI_CLK_DIV		4 ///< \hideinitializer
	
/// \brief Byte that is transmitted during read operations
#define DUMMY_CHAR	(0xFF)

	///\}
///\}

#endif

///\}
