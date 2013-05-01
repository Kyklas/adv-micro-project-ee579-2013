/**************************************************
 *
 * I/O definitions for the M16C62P family.
 *
 * Copyright 2006 IAR Systems. All rights reserved.
 *
 * $Revision: 2164 $ 
 *
 **************************************************/

#ifndef __IOM16C62P_H__
#define __IOM16C62P_H__

#ifdef __IAR_SYSTEMS_ICC__
#pragma language=extended

#ifndef _SYSTEM_BUILD
#pragma system_include
#endif

/*-------------------------------------------------------------------------
 *   Processor Registers
 *-------------------------------------------------------------------------*/

/* Processor Mode Register */ 
__data13 __no_init volatile unsigned short PM @ 0x004;
#define pm  PM

/* Processor Mode Register 0 */ 
__data13 __no_init volatile union
{
  unsigned char PM0;
  struct
  {
    unsigned char PM00           : 1;  
    unsigned char PM01           : 1;  
    unsigned char PM02           : 1;  
    unsigned char PM03           : 1;  
    unsigned char PM04           : 1;  
    unsigned char PM05           : 1;  
    unsigned char PM06           : 1;  
    unsigned char PM07           : 1;  
  } PM0_bit;
} @ 0x004;
#define pm0             PM0    
#define pm00            PM0_bit.PM00    
#define pm01            PM0_bit.PM01    
#define pm02            PM0_bit.PM02    
#define pm03            PM0_bit.PM03    
#define pm04            PM0_bit.PM04    
#define pm05            PM0_bit.PM05    
#define pm06            PM0_bit.PM06    
#define pm07            PM0_bit.PM07

/* Processor Mode Register 1 */ 
__data13 __no_init volatile union
{
  unsigned char PM1;
  struct
  {
    unsigned char PM10           : 1;  
    unsigned char PM11           : 1;  
    unsigned char PM12           : 1;  
    unsigned char PM13           : 1;  
    unsigned char PM14           : 1;  
    unsigned char PM15           : 1;  
    unsigned char                : 1;  
    unsigned char PM17           : 1;  
  } PM1_bit;
} @ 0x005;
#define pm1             PM1    
#define pm10            PM1_bit.PM10    
#define pm11            PM1_bit.PM11    
#define pm12            PM1_bit.PM12    
#define pm13            PM1_bit.PM13    
#define pm14            PM1_bit.PM14    
#define pm15            PM1_bit.PM15    
#define pm17            PM1_bit.PM17

/* System clock control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char CM0;
  struct
  {
    unsigned char CM00           : 1;  
    unsigned char CM01           : 1;  
    unsigned char CM02           : 1;  
    unsigned char CM03           : 1;  
    unsigned char CM04           : 1;  
    unsigned char CM05           : 1;  
    unsigned char CM06           : 1;  
    unsigned char CM07           : 1;  
  } CM0_bit;
} @ 0x006;
#define cm0             CM0    
#define cm00            CM0_bit.CM00    
#define cm01            CM0_bit.CM01    
#define cm02            CM0_bit.CM02    
#define cm03            CM0_bit.CM03    
#define cm04            CM0_bit.CM04    
#define cm05            CM0_bit.CM05    
#define cm06            CM0_bit.CM06    
#define cm07            CM0_bit.CM07

/* System clock control register 1 */ 
__data13 __no_init volatile union
{
  unsigned char CM1;
  struct
  {
    unsigned char CM10           : 1;  
    unsigned char CM11           : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char CM15           : 1;  
    unsigned char CM16           : 1;  
    unsigned char CM17           : 1;  
  } CM1_bit;
} @ 0x007;
#define cm1             CM1    
#define cm10            CM1_bit.CM10    
#define cm11            CM1_bit.CM11    
#define cm15            CM1_bit.CM15    
#define cm16            CM1_bit.CM16    
#define cm17            CM1_bit.CM17

/* System clock control register */ 
__data13 __no_init volatile unsigned short CM @ 0x006;
#define cm  CM

/* Chip select control register */ 
__data13 __no_init volatile union
{
  unsigned char CSR;
  struct
  {
    unsigned char CS0            : 1;  
    unsigned char CS1            : 1;  
    unsigned char CS2            : 1;  
    unsigned char CS3            : 1;  
    unsigned char CS0W           : 1;  
    unsigned char CS1W           : 1;  
    unsigned char CS2W           : 1;  
    unsigned char CS3W           : 1;  
  } CSR_bit;
} @ 0x008;
#define csr             CSR    
#define cs0             CSR_bit.CS0    
#define cs1             CSR_bit.CS1    
#define cs2             CSR_bit.CS2    
#define cs3             CSR_bit.CS3    
#define cs0w            CSR_bit.CS0W    
#define cs1w            CSR_bit.CS1W    
#define cs2w            CSR_bit.CS2W    
#define cs3w            CSR_bit.CS3W

/* Protect register */ 
__data13 __no_init volatile union
{
  unsigned char PRCR;
  struct
  {
    unsigned char PRC0           : 1;  
    unsigned char PRC1           : 1;  
    unsigned char PRC2           : 1;  
    unsigned char PRC3           : 1;  
  } PRCR_bit;
} @ 0x00A;
#define prcr            PRCR    
#define prc0            PRCR_bit.PRC0    
#define prc1            PRCR_bit.PRC1    
#define prc2            PRCR_bit.PRC2    
#define prc3            PRCR_bit.PRC3

/* Data bank register */ 
__data13 __no_init volatile union
{
  unsigned char DBR;
  struct
  {
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char OFS            : 1;  
    unsigned char BSR0           : 1;  
    unsigned char BSR1           : 1;  
    unsigned char BSR2           : 1;  
  } DBR_bit;
} @ 0x00B;
#define dbr             DBR    
#define ofs             DBR_bit.OFS    
#define bsr0            DBR_bit.BSR0    
#define bsr1            DBR_bit.BSR1    
#define bsr2            DBR_bit.BSR2

/* Oscillation stop detection register */ 
__data13 __no_init volatile union
{
  unsigned char CM2;
  struct
  {
    unsigned char CM20           : 1;  
    unsigned char CM21           : 1;  
    unsigned char CM22           : 1;  
    unsigned char CM23           : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char CM27           : 1;  
  } CM2_bit;
} @ 0x00C;
#define cm2             CM2    
#define cm20            CM2_bit.CM20    
#define cm21            CM2_bit.CM21    
#define cm22            CM2_bit.CM22    
#define cm23            CM2_bit.CM23    
#define cm27            CM2_bit.CM27

/* Chip select expansion control register */ 
__data13 __no_init volatile unsigned char CSE @ 0x01B;
#define cse  CSE

/* PLC control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char PLC0;
  struct
  {
    unsigned char PLC00          : 1;  
    unsigned char PLC01          : 1;  
    unsigned char PLC02          : 1;  
    unsigned char                : 4;  
    unsigned char PLC07          : 1;  
  } PLC0_bit;
} @ 0x01C;
#define plc0            PLC0    
#define plc00           PLC0_bit.PLC00    
#define plc01           PLC0_bit.PLC01    
#define plc02           PLC0_bit.PLC02    
#define plc07           PLC0_bit.PLC07

/* Processor Mode Register 2 */ 
__data13 __no_init volatile union
{
  unsigned char PM2;
  struct
  {
    unsigned char PM20           : 1;  
    unsigned char PM21           : 1;  
    unsigned char PM22           : 1;  
  } PM2_bit;
} @ 0x01E;
#define pm2             PM2    
#define pm20            PM2_bit.PM20    
#define pm21            PM2_bit.PM21    
#define pm22            PM2_bit.PM22

/* Peripheral clock select register */ 
__data13 __no_init volatile unsigned char PCLKR @ 0x25E;
#define pclkr  PCLKR


/*-------------------------------------------------------------------------
 *   Watchdog Timer
 *-------------------------------------------------------------------------*/

/* Watchdog timer start register */ 
__data13 __no_init volatile unsigned char WDTS @ 0x00E;
#define wdts  WDTS

/* Watchdog timer control register */ 
__data13 __no_init volatile union
{
  unsigned char WDC;
  struct
  {
    unsigned char                : 5;  
    unsigned char WDC5           : 1;  
    unsigned char                : 1;  
    unsigned char WDC7           : 1;  
  } WDC_bit;
} @ 0x00F;
#define wdc             WDC    
#define wdc5            WDC_bit.WDC5    
#define wdc7            WDC_bit.WDC7


/*-------------------------------------------------------------------------
 *   Interrupt Control Register
 *-------------------------------------------------------------------------*/

/* Address match interrupt enable */ 
__data13 __no_init volatile unsigned char AIER @ 0x009;
#define aier  AIER

/* Address match interrupt register 0 */ 
__data13 __no_init volatile unsigned long RMAD0 @ 0x010;
#define rmad0  RMAD0

/* Address match interrupt register 0 (low) */ 
__data13 __no_init volatile unsigned char RMAD00 @ 0x010;
#define rmad00  RMAD00

/* Address match interrupt register 0 (mid) */ 
__data13 __no_init volatile unsigned char RMAD01 @ 0x011;
#define rmad01  RMAD01

/* Address match interrupt register 0 (high) */ 
__data13 __no_init volatile unsigned char RMAD02 @ 0x012;
#define rmad02  RMAD02

/* Address match interrupt register 0 */ 
__data13 __no_init volatile unsigned long RMAD1 @ 0x014;
#define rmad1  RMAD1

/* Address match interrupt register 1 (low) */ 
__data13 __no_init volatile unsigned char RMAD10 @ 0x014;
#define rmad10  RMAD10

/* Address match interrupt register 1 (mid) */ 
__data13 __no_init volatile unsigned char RMAD11 @ 0x015;
#define rmad11  RMAD11

/* Address match interrupt register 1 (high) */ 
__data13 __no_init volatile unsigned char RMAD12 @ 0x016;
#define rmad12  RMAD12

/* INT3 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char INT3IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
    unsigned char POL            : 1;  
  } INT3IC_bit;
} @ 0x044;
#define int3ic          INT3IC    
#define ilvl_int3ic     INT3IC_bit.ILVL    
#define ir_int3ic       INT3IC_bit.IR    
#define pol_int3ic      INT3IC_bit.POL

/* Timer B5 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TB5IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TB5IC_bit;
} @ 0x045;
#define tb5ic           TB5IC    
#define ilvl_tb5ic      TB5IC_bit.ILVL    
#define ir_tb5ic        TB5IC_bit.IR

/* UART0 BUS collision detection interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char U0BCNIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } U0BCNIC_bit;
} @ 0x047;
#define u0bcnic         U0BCNIC    
#define ilvl_u0bcnic    U0BCNIC_bit.ILVL    
#define ir_u0bcnic      U0BCNIC_bit.IR

/* Timer B4 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TB4IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TB4IC_bit;
} @ 0x046;
#define tb4ic           TB4IC    
#define ilvl_tb4ic      TB4IC_bit.ILVL    
#define ir_tb4ic        TB4IC_bit.IR

/* UART1 BUS collision detection interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char U1BCNIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } U1BCNIC_bit;
} @ 0x046;
#define u1bcnic         U1BCNIC    
#define ilvl_u1bcnic    U1BCNIC_bit.ILVL    
#define ir_u1bcnic      U1BCNIC_bit.IR

/* Timer B3 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TB3IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TB3IC_bit;
} @ 0x047;
#define tb3ic           TB3IC    
#define ilvl_tb3ic      TB3IC_bit.ILVL    
#define ir_tb3ic        TB3IC_bit.IR

/* SI/O4 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S4IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S4IC_bit;
} @ 0x048;
#define s4ic            S4IC    
#define ilvl_s4ic       S4IC_bit.ILVL    
#define ir_s4ic         S4IC_bit.IR

/* INT5 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char INT5IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
    unsigned char POL            : 1;  
  } INT5IC_bit;
} @ 0x048;
#define int5ic          INT5IC    
#define ilvl_int5ic     INT5IC_bit.ILVL    
#define ir_int5ic       INT5IC_bit.IR    
#define pol_int5ic      INT5IC_bit.POL

/* SI/O3 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S3IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S3IC_bit;
} @ 0x049;
#define s3ic            S3IC    
#define ilvl_s3ic       S3IC_bit.ILVL    
#define ir_s3ic         S3IC_bit.IR

/* INT4 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char INT4IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
    unsigned char POL            : 1;  
  } INT4IC_bit;
} @ 0x049;
#define int4ic          INT4IC    
#define ilvl_int4ic     INT4IC_bit.ILVL    
#define ir_int4ic       INT4IC_bit.IR    
#define pol_int4ic      INT4IC_bit.POL

/* UART2 Bus collision detection interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char BCNIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } BCNIC_bit;
} @ 0x04A;
#define bcnic           BCNIC    
#define ilvl_bcnic      BCNIC_bit.ILVL    
#define ir_bcnic        BCNIC_bit.IR

/* DMA0 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char DMA0IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } DMA0IC_bit;
} @ 0x04B;
#define dma0ic          DMA0IC    
#define ilvl_dma0ic     DMA0IC_bit.ILVL    
#define ir_dma0ic       DMA0IC_bit.IR

/* DMA1 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char DMA1IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } DMA1IC_bit;
} @ 0x04C;
#define dma1ic          DMA1IC    
#define ilvl_dma1ic     DMA1IC_bit.ILVL    
#define ir_dma1ic       DMA1IC_bit.IR

/* Key input interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char KUPIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } KUPIC_bit;
} @ 0x04D;
#define kupic           KUPIC    
#define ilvl_kupic      KUPIC_bit.ILVL    
#define ir_kupic        KUPIC_bit.IR

/* AD conversion interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char ADIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } ADIC_bit;
} @ 0x04E;
#define adic            ADIC    
#define ilvl_adic       ADIC_bit.ILVL    
#define ir_adic         ADIC_bit.IR

/* UART2 transmit interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S2TIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S2TIC_bit;
} @ 0x04F;
#define s2tic           S2TIC    
#define ilvl_s2tic      S2TIC_bit.ILVL    
#define ir_s2tic        S2TIC_bit.IR

/* UART2 receive interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S2RIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S2RIC_bit;
} @ 0x050;
#define s2ric           S2RIC    
#define ilvl_s2ric      S2RIC_bit.ILVL    
#define ir_s2ric        S2RIC_bit.IR

/* UART0 transmit interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S0TIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S0TIC_bit;
} @ 0x051;
#define s0tic           S0TIC    
#define ilvl_s0tic      S0TIC_bit.ILVL    
#define ir_s0tic        S0TIC_bit.IR

/* UART0 receive interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S0RIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S0RIC_bit;
} @ 0x052;
#define s0ric           S0RIC    
#define ilvl_s0ric      S0RIC_bit.ILVL    
#define ir_s0ric        S0RIC_bit.IR

/* UART1 transmit interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S1TIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S1TIC_bit;
} @ 0x053;
#define s1tic           S1TIC    
#define ilvl_s1tic      S1TIC_bit.ILVL    
#define ir_s1tic        S1TIC_bit.IR

/* UART1 receive interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char S1RIC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } S1RIC_bit;
} @ 0x054;
#define s1ric           S1RIC    
#define ilvl_s1ric      S1RIC_bit.ILVL    
#define ir_s1ric        S1RIC_bit.IR

/* Timer A0 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TA0IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TA0IC_bit;
} @ 0x055;
#define ta0ic           TA0IC    
#define ilvl_ta0ic      TA0IC_bit.ILVL    
#define ir_ta0ic        TA0IC_bit.IR

/* Timer A1 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TA1IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TA1IC_bit;
} @ 0x056;
#define ta1ic           TA1IC    
#define ilvl_ta1ic      TA1IC_bit.ILVL    
#define ir_ta1ic        TA1IC_bit.IR

/* Timer A2 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TA2IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TA2IC_bit;
} @ 0x057;
#define ta2ic           TA2IC    
#define ilvl_ta2ic      TA2IC_bit.ILVL    
#define ir_ta2ic        TA2IC_bit.IR

/* Timer A3 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TA3IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TA3IC_bit;
} @ 0x058;
#define ta3ic           TA3IC    
#define ilvl_ta3ic      TA3IC_bit.ILVL    
#define ir_ta3ic        TA3IC_bit.IR

/* Timer A4 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TA4IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TA4IC_bit;
} @ 0x059;
#define ta4ic           TA4IC    
#define ilvl_ta4ic      TA4IC_bit.ILVL    
#define ir_ta4ic        TA4IC_bit.IR

/* Timer B0 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TB0IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TB0IC_bit;
} @ 0x05A;
#define tb0ic           TB0IC    
#define ilvl_tb0ic      TB0IC_bit.ILVL    
#define ir_tb0ic        TB0IC_bit.IR

/* Timer B1 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TB1IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TB1IC_bit;
} @ 0x05B;
#define tb1ic           TB1IC    
#define ilvl_tb1ic      TB1IC_bit.ILVL    
#define ir_tb1ic        TB1IC_bit.IR

/* Timer B2 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char TB2IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
  } TB2IC_bit;
} @ 0x05C;
#define tb2ic           TB2IC    
#define ilvl_tb2ic      TB2IC_bit.ILVL    
#define ir_tb2ic        TB2IC_bit.IR

/* Interrupt 0 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char INT0IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
    unsigned char POL            : 1;  
  } INT0IC_bit;
} @ 0x05D;
#define int0ic          INT0IC    
#define ilvl_int0ic     INT0IC_bit.ILVL    
#define ir_int0ic       INT0IC_bit.IR    
#define pol_int0ic      INT0IC_bit.POL

/* Interrupt 1 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char INT1IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
    unsigned char POL            : 1;  
  } INT1IC_bit;
} @ 0x05E;
#define int1ic          INT1IC    
#define ilvl_int1ic     INT1IC_bit.ILVL    
#define ir_int1ic       INT1IC_bit.IR    
#define pol_int1ic      INT1IC_bit.POL

/* Interrupt 2 interrupt control register */ 
__data13 __no_init volatile union
{
  unsigned char INT2IC;
  struct
  {
    unsigned char ILVL           : 3;  
    unsigned char IR             : 1;  
    unsigned char POL            : 1;  
  } INT2IC_bit;
} @ 0x05F;
#define int2ic          INT2IC    
#define ilvl_int2ic     INT2IC_bit.ILVL    
#define ir_int2ic       INT2IC_bit.IR    
#define pol_int2ic      INT2IC_bit.POL

/* Address match interrupt register 2 (low) */ 
__data13 __no_init volatile unsigned char RMAD20 @ 0x1B8;
#define rmad20  RMAD20

/* Address match interrupt register 2 (mid) */ 
__data13 __no_init volatile unsigned char RMAD21 @ 0x1B9;
#define rmad21  RMAD21

/* Address match interrupt register 2 (high) */ 
__data13 __no_init volatile unsigned char RMAD22 @ 0x1BA;
#define rmad22  RMAD22

/* Address match interrupt enable register 2 */ 
__data13 __no_init volatile unsigned char AIER2 @ 0x1BB;
#define aier2  AIER2

/* Address match interrupt register 2 (low) */ 
__data13 __no_init volatile unsigned char RMAD30 @ 0x1BC;
#define rmad30  RMAD30

/* Address match interrupt register 2 (mid) */ 
__data13 __no_init volatile unsigned char RMAD31 @ 0x1BD;
#define rmad31  RMAD31

/* Address match interrupt register 2 (high) */ 
__data13 __no_init volatile unsigned char RMAD32 @ 0x1BE;
#define rmad32  RMAD32

/* Interrupt cause select register 2 */ 
__data13 __no_init volatile unsigned char IFSR2A @ 0x35E;
#define ifsr2a  IFSR2A

/* Interrupt cause select register */ 
__data13 __no_init volatile unsigned char IFSR @ 0x35F;
#define ifsr  IFSR


/*-------------------------------------------------------------------------
 *   DMA Registers
 *-------------------------------------------------------------------------*/

/* DMA0 source pointer */ 
__data13 __no_init volatile unsigned long SAR0 @ 0x020;
#define sar0  SAR0

/* DMA0 source pointer (low) */ 
__data13 __no_init volatile unsigned char SAR00 @ 0x020;
#define sar00  SAR00

/* DMA0 source pointer (mid) */ 
__data13 __no_init volatile unsigned char SAR01 @ 0x021;
#define sar01  SAR01

/* DMA0 source pointer (high) */ 
__data13 __no_init volatile unsigned char SAR02 @ 0x022;
#define sar02  SAR02

/* DMA0 destination pointer */ 
__data13 __no_init volatile unsigned long DAR0 @ 0x024;
#define dar0  DAR0

/* DMA0 destination pointer (low) */ 
__data13 __no_init volatile unsigned char DAR00 @ 0x024;
#define dar00  DAR00

/* DMA0 destination pointer (mid) */ 
__data13 __no_init volatile unsigned char DAR01 @ 0x025;
#define dar01  DAR01

/* DMA0 destination pointer (high) */ 
__data13 __no_init volatile unsigned char DAR02 @ 0x026;
#define dar02  DAR02

/* DMA0 transfer counter */ 
__data13 __no_init volatile unsigned short TCR0 @ 0x028;
#define tcr0  TCR0

/* DMA0 transfer counter (low) */ 
__data13 __no_init volatile unsigned char TCR00 @ 0x028;
#define tcr00  TCR00

/* DMA0 transfer counter (high) */ 
__data13 __no_init volatile unsigned char TCR01 @ 0x029;
#define tcr01  TCR01

/* DMA0 control register */ 
__data13 __no_init volatile union
{
  unsigned char DM0CON;
  struct
  {
    unsigned char DMBIT          : 1;  
    unsigned char DMASL          : 1;  
    unsigned char DMAS           : 1;  
    unsigned char DMAE           : 1;  
    unsigned char DSD            : 1;  
    unsigned char DAD            : 1;  
  } DM0CON_bit;
} @ 0x02C;
#define dm0con          DM0CON    
#define dmbit_dm0con    DM0CON_bit.DMBIT    
#define dmasl_dm0con    DM0CON_bit.DMASL    
#define dmas_dm0con     DM0CON_bit.DMAS    
#define dmae_dm0con     DM0CON_bit.DMAE    
#define dsd_dm0con      DM0CON_bit.DSD    
#define dad_dm0con      DM0CON_bit.DAD

/* DMA1 source pointer */ 
__data13 __no_init volatile unsigned long SAR1 @ 0x030;
#define sar1  SAR1

/* DMA1 source pointer (low) */ 
__data13 __no_init volatile unsigned char SAR10 @ 0x030;
#define sar10  SAR10

/* DMA1 source pointer (mid) */ 
__data13 __no_init volatile unsigned char SAR11 @ 0x031;
#define sar11  SAR11

/* DMA1 source pointer (high) */ 
__data13 __no_init volatile unsigned char SAR12 @ 0x032;
#define sar12  SAR12

/* DMA1 destination pointer (low) */ 
__data13 __no_init volatile unsigned char DAR10 @ 0x034;
#define dar10  DAR10

/* DMA1 destination pointer (mid) */ 
__data13 __no_init volatile unsigned char DAR11 @ 0x035;
#define dar11  DAR11

/* DMA1 destination pointer (high) */ 
__data13 __no_init volatile unsigned char DAR12 @ 0x036;
#define dar12  DAR12

/* DMA1 transfer counter */ 
__data13 __no_init volatile unsigned short TCR1 @ 0x038;
#define tcr1  TCR1

/* DMA1 transfer counter (low) */ 
__data13 __no_init volatile unsigned char TCR10 @ 0x038;
#define tcr10  TCR10

/* DMA1 transfer counter (high) */ 
__data13 __no_init volatile unsigned char TCR11 @ 0x039;
#define tcr11  TCR11

/* DMA1 control register */ 
__data13 __no_init volatile union
{
  unsigned char DM1CON;
  struct
  {
    unsigned char DMBIT          : 1;  
    unsigned char DMASL          : 1;  
    unsigned char DMAS           : 1;  
    unsigned char DMAE           : 1;  
    unsigned char DSD            : 1;  
    unsigned char DAD            : 1;  
  } DM1CON_bit;
} @ 0x03C;
#define dm1con          DM1CON    
#define dmbit_dm1con    DM1CON_bit.DMBIT    
#define dmasl_dm1con    DM1CON_bit.DMASL    
#define dmas_dm1con     DM1CON_bit.DMAS    
#define dmae_dm1con     DM1CON_bit.DMAE    
#define dsd_dm1con      DM1CON_bit.DSD    
#define dad_dm1con      DM1CON_bit.DAD

/* DMA0 cause select register */ 
__data13 __no_init volatile union
{
  unsigned char DM0SL;
  struct
  {
    unsigned char DSEL0          : 1;  
    unsigned char DSEL1          : 1;  
    unsigned char DSEL2          : 1;  
    unsigned char DSEL3          : 1;  
    unsigned char                : 2;  
    unsigned char DMS            : 1;  
    unsigned char DSR            : 1;  
  } DM0SL_bit;
} @ 0x03B8;
#define dm0sl           DM0SL    
#define dsel0_dm0sl     DM0SL_bit.DSEL0    
#define dsel1_dm0sl     DM0SL_bit.DSEL1    
#define dsel2_dm0sl     DM0SL_bit.DSEL2    
#define dsel3_dm0sl     DM0SL_bit.DSEL3    
#define dms_dm0sl       DM0SL_bit.DMS    
#define dsr_dm0sl       DM0SL_bit.DSR

/* DMA1 cause select register */ 
__data13 __no_init volatile union
{
  unsigned char DM1SL;
  struct
  {
    unsigned char DSEL0          : 1;  
    unsigned char DSEL1          : 1;  
    unsigned char DSEL2          : 1;  
    unsigned char DSEL3          : 1;  
    unsigned char                : 2;  
    unsigned char DMS            : 1;  
    unsigned char DSR            : 1;  
  } DM1SL_bit;
} @ 0x03BA;
#define dm1sl           DM1SL    
#define dsel0_dm1sl     DM1SL_bit.DSEL0    
#define dsel1_dm1sl     DM1SL_bit.DSEL1    
#define dsel2_dm1sl     DM1SL_bit.DSEL2    
#define dsel3_dm1sl     DM1SL_bit.DSEL3    
#define dms_dm1sl       DM1SL_bit.DMS    
#define dsr_dm1sl       DM1SL_bit.DSR


/*-------------------------------------------------------------------------
 *   Timer Registers
 *-------------------------------------------------------------------------*/

/* Timer A/B count start flags */ 
__data13 __no_init volatile union
{
  unsigned char TABSR;
  struct
  {
    unsigned char TA0S           : 1;  
    unsigned char TA1S           : 1;  
    unsigned char TA2S           : 1;  
    unsigned char TA3S           : 1;  
    unsigned char TA4S           : 1;  
    unsigned char TB0S           : 1;  
    unsigned char TB1S           : 1;  
    unsigned char TB2S           : 1;  
  } TABSR_bit;
} @ 0x380;
#define tabsr           TABSR    
#define ta0s            TABSR_bit.TA0S    
#define ta1s            TABSR_bit.TA1S    
#define ta2s            TABSR_bit.TA2S    
#define ta3s            TABSR_bit.TA3S    
#define ta4s            TABSR_bit.TA4S    
#define tb0s            TABSR_bit.TB0S    
#define tb1s            TABSR_bit.TB1S    
#define tb2s            TABSR_bit.TB2S

/* Clock prescaler reset flag */ 
__data13 __no_init volatile union
{
  unsigned char CPSRF;
  struct
  {
    unsigned char                : 7;  
    unsigned char CPSR           : 1;  
  } CPSRF_bit;
} @ 0x381;
#define cpsrf           CPSRF    
#define cpsr            CPSRF_bit.CPSR

/* One-shot start flagl */ 
__data13 __no_init volatile union
{
  unsigned char ONSF;
  struct
  {
    unsigned char TA0OS          : 1;  
    unsigned char TA1OS          : 1;  
    unsigned char TA2OS          : 1;  
    unsigned char TA3OS          : 1;  
    unsigned char TA4OS          : 1;  
    unsigned char ZIE            : 1;  
    unsigned char TA0TGL         : 1;  
    unsigned char TA0TGH         : 1;  
  } ONSF_bit;
} @ 0x382;
#define onsf            ONSF    
#define ta0os           ONSF_bit.TA0OS    
#define ta1os           ONSF_bit.TA1OS    
#define ta2os           ONSF_bit.TA2OS    
#define ta3os           ONSF_bit.TA3OS    
#define ta4os           ONSF_bit.TA4OS    
#define zie             ONSF_bit.ZIE    
#define ta0tgl          ONSF_bit.TA0TGL    
#define ta0tgh          ONSF_bit.TA0TGH

/* Trigger select register */ 
__data13 __no_init volatile union
{
  unsigned char TRGSR;
  struct
  {
    unsigned char TA1TGL         : 1;  
    unsigned char TA1TGH         : 1;  
    unsigned char TA2TGL         : 1;  
    unsigned char TA2TGH         : 1;  
    unsigned char TA3TGL         : 1;  
    unsigned char TA3TGH         : 1;  
    unsigned char TA4TGL         : 1;  
    unsigned char TA4TGH         : 1;  
  } TRGSR_bit;
} @ 0x383;
#define trgsr           TRGSR    
#define ta1tgl          TRGSR_bit.TA1TGL    
#define ta1tgh          TRGSR_bit.TA1TGH    
#define ta2tgl          TRGSR_bit.TA2TGL    
#define ta2tgh          TRGSR_bit.TA2TGH    
#define ta3tgl          TRGSR_bit.TA3TGL    
#define ta3tgh          TRGSR_bit.TA3TGH    
#define ta4tgl          TRGSR_bit.TA4TGL    
#define ta4tgh          TRGSR_bit.TA4TGH

/* Up- down-count selection flag */ 
__data13 __no_init volatile union
{
  unsigned char UDF;
  struct
  {
    unsigned char TA0UD          : 1;  
    unsigned char TA1UD          : 1;  
    unsigned char TA2UD          : 1;  
    unsigned char TA3UD          : 1;  
    unsigned char TA4UD          : 1;  
    unsigned char TA2P           : 1;  
    unsigned char TA3P           : 1;  
    unsigned char TA4P           : 1;  
  } UDF_bit;
} @ 0x384;
#define udf             UDF    
#define ta0ud           UDF_bit.TA0UD    
#define ta1ud           UDF_bit.TA1UD    
#define ta2ud           UDF_bit.TA2UD    
#define ta3ud           UDF_bit.TA3UD    
#define ta4ud           UDF_bit.TA4UD    
#define ta2p            UDF_bit.TA2P    
#define ta3p            UDF_bit.TA3P    
#define ta4p            UDF_bit.TA4P

/* Timer A0 */ 
__no_init volatile unsigned short TA0 @ 0x386;
#define ta0  TA0

/* Timer A0 (low byte) */ 
__no_init volatile unsigned char TA0L @ 0x386;
#define ta0l  TA0L

/* Timer A0 (high byte) */ 
__no_init volatile unsigned char TA0H @ 0x387;
#define ta0h  TA0H

/* Timer A1 */ 
__no_init volatile unsigned short TA1 @ 0x388;
#define ta1  TA1

/* Timer A1 (low byte) */ 
__no_init volatile unsigned char TA1L @ 0x388;
#define ta1l  TA1L

/* Timer A1 (high byte) */ 
__no_init volatile unsigned char TA1H @ 0x389;
#define ta1h  TA1H

/* Timer A2 */ 
__no_init volatile unsigned short TA2 @ 0x38A;
#define ta2  TA2

/* Timer A2 (low byte) */ 
__no_init volatile unsigned char TA2L @ 0x38A;
#define ta2l  TA2L

/* Timer A2 (high byte) */ 
__no_init volatile unsigned char TA2H @ 0x38B;
#define ta2h  TA2H

/* Timer A3 */ 
__no_init volatile unsigned short TA3 @ 0x38C;
#define ta3  TA3

/* Timer A3 (low byte) */ 
__no_init volatile unsigned char TA3L @ 0x38C;
#define ta3l  TA3L

/* Timer A3 (high byte) */ 
__no_init volatile unsigned char TA3H @ 0x38D;
#define ta3h  TA3H

/* Timer A4 */ 
__no_init volatile unsigned short TA4 @ 0x38E;
#define ta4  TA4

/* Timer A4 (low byte) */ 
__no_init volatile unsigned char TA4L @ 0x38E;
#define ta4l  TA4L

/* Timer A4 (high byte) */ 
__no_init volatile unsigned char TA4H @ 0x38F;
#define ta4h  TA4H

/* Timer B0 */ 
__no_init volatile unsigned short TB0 @ 0x390;
#define tb0  TB0

/* Timer B0 (low byte) */ 
__no_init volatile unsigned char TB0L @ 0x390;
#define tb0l  TB0L

/* Timer B0 (high byte) */ 
__no_init volatile unsigned char TB0H @ 0x391;
#define tb0h  TB0H

/* Timer B1 */ 
__no_init volatile unsigned short TB1 @ 0x392;
#define tb1  TB1

/* Timer B1 (low byte) */ 
__no_init volatile unsigned char TB1L @ 0x392;
#define tb1l  TB1L

/* Timer B1 (high byte) */ 
__no_init volatile unsigned char TB1H @ 0x393;
#define tb1h  TB1H

/* Timer B2 */ 
__no_init volatile unsigned short TB2 @ 0x394;
#define tb2  TB2

/* Timer B2 (low byte) */ 
__no_init volatile unsigned char TB2L @ 0x394;
#define tb2l  TB2L

/* Timer B2 (high byte) */ 
__no_init volatile unsigned char TB2H @ 0x395;
#define tb2h  TB2H

/* Timer A0 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TA0MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char MR2            : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TA0MR_bit;
} @ 0x396;
#define ta0mr           TA0MR    
#define tmod0_ta0mr     TA0MR_bit.TMOD0    
#define tmod1_ta0mr     TA0MR_bit.TMOD1    
#define mr0_ta0mr       TA0MR_bit.MR0    
#define mr1_ta0mr       TA0MR_bit.MR1    
#define mr2_ta0mr       TA0MR_bit.MR2    
#define mr3_ta0mr       TA0MR_bit.MR3    
#define tck0_ta0mr      TA0MR_bit.TCK0    
#define tck1_ta0mr      TA0MR_bit.TCK1

/* Timer A1 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TA1MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char MR2            : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TA1MR_bit;
} @ 0x397;
#define ta1mr           TA1MR    
#define tmod0_ta1mr     TA1MR_bit.TMOD0    
#define tmod1_ta1mr     TA1MR_bit.TMOD1    
#define mr0_ta1mr       TA1MR_bit.MR0    
#define mr1_ta1mr       TA1MR_bit.MR1    
#define mr2_ta1mr       TA1MR_bit.MR2    
#define mr3_ta1mr       TA1MR_bit.MR3    
#define tck0_ta1mr      TA1MR_bit.TCK0    
#define tck1_ta1mr      TA1MR_bit.TCK1

/* Timer A2 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TA2MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char MR2            : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TA2MR_bit;
} @ 0x398;
#define ta2mr           TA2MR    
#define tmod0_ta2mr     TA2MR_bit.TMOD0    
#define tmod1_ta2mr     TA2MR_bit.TMOD1    
#define mr0_ta2mr       TA2MR_bit.MR0    
#define mr1_ta2mr       TA2MR_bit.MR1    
#define mr2_ta2mr       TA2MR_bit.MR2    
#define mr3_ta2mr       TA2MR_bit.MR3    
#define tck0_ta2mr      TA2MR_bit.TCK0    
#define tck1_ta2mr      TA2MR_bit.TCK1

/* Timer A3 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TA3MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char MR2            : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TA3MR_bit;
} @ 0x399;
#define ta3mr           TA3MR    
#define tmod0_ta3mr     TA3MR_bit.TMOD0    
#define tmod1_ta3mr     TA3MR_bit.TMOD1    
#define mr0_ta3mr       TA3MR_bit.MR0    
#define mr1_ta3mr       TA3MR_bit.MR1    
#define mr2_ta3mr       TA3MR_bit.MR2    
#define mr3_ta3mr       TA3MR_bit.MR3    
#define tck0_ta3mr      TA3MR_bit.TCK0    
#define tck1_ta3mr      TA3MR_bit.TCK1

/* Timer A4 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TA4MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char MR2            : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TA4MR_bit;
} @ 0x39A;
#define ta4mr           TA4MR    
#define tmod0_ta4mr     TA4MR_bit.TMOD0    
#define tmod1_ta4mr     TA4MR_bit.TMOD1    
#define mr0_ta4mr       TA4MR_bit.MR0    
#define mr1_ta4mr       TA4MR_bit.MR1    
#define mr2_ta4mr       TA4MR_bit.MR2    
#define mr3_ta4mr       TA4MR_bit.MR3    
#define tck0_ta4mr      TA4MR_bit.TCK0    
#define tck1_ta4mr      TA4MR_bit.TCK1

/* Timer B0 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TB0MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char MR2            : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TB0MR_bit;
} @ 0x39B;
#define tb0mr           TB0MR    
#define tmod0_tb0mr     TB0MR_bit.TMOD0    
#define tmod1_tb0mr     TB0MR_bit.TMOD1    
#define mr0_tb0mr       TB0MR_bit.MR0    
#define mr1_tb0mr       TB0MR_bit.MR1    
#define mr2_tb0mr       TB0MR_bit.MR2    
#define mr3_tb0mr       TB0MR_bit.MR3    
#define tck0_tb0mr      TB0MR_bit.TCK0    
#define tck1_tb0mr      TB0MR_bit.TCK1

/* Timer B1 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TB1MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char                : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TB1MR_bit;
} @ 0x39C;
#define tb1mr           TB1MR    
#define tmod0_tb1mr     TB1MR_bit.TMOD0    
#define tmod1_tb1mr     TB1MR_bit.TMOD1    
#define mr0_tb1mr       TB1MR_bit.MR0    
#define mr1_tb1mr       TB1MR_bit.MR1    
#define mr3_tb1mr       TB1MR_bit.MR3    
#define tck0_tb1mr      TB1MR_bit.TCK0    
#define tck1_tb1mr      TB1MR_bit.TCK1

/* Timer B2 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TB2MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char                : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TB2MR_bit;
} @ 0x39D;
#define tb2mr           TB2MR    
#define tmod0_tb2mr     TB2MR_bit.TMOD0    
#define tmod1_tb2mr     TB2MR_bit.TMOD1    
#define mr0_tb2mr       TB2MR_bit.MR0    
#define mr1_tb2mr       TB2MR_bit.MR1    
#define mr3_tb2mr       TB2MR_bit.MR3    
#define tck0_tb2mr      TB2MR_bit.TCK0    
#define tck1_tb2mr      TB2MR_bit.TCK1

/* Timer B2 special mode register */ 
__data13 __no_init volatile union
{
  unsigned char TB2SC;
  struct
  {
    unsigned char PWCON          : 1;  
    unsigned char IVPCR1         : 1;  
  } TB2SC_bit;
} @ 0x39E;
#define tb2sc           TB2SC    
#define pwcon           TB2SC_bit.PWCON    
#define ivpcr1          TB2SC_bit.IVPCR1

/* Timer B3,4,5 count start flag */ 
__data13 __no_init volatile union
{
  unsigned char TBSR;
  struct
  {
    unsigned char                : 5;  
    unsigned char TB3S           : 1;  
    unsigned char TB4S           : 1;  
    unsigned char TB5S           : 1;  
  } TBSR_bit;
} @ 0x340;
#define tbsr            TBSR    
#define tb3s            TBSR_bit.TB3S    
#define tb4s            TBSR_bit.TB4S    
#define tb5s            TBSR_bit.TB5S

/* Timer B3 */ 
__no_init volatile unsigned short TB3 @ 0x350;
#define tb3  TB3

/* Timer B3 (low byte) */ 
__no_init volatile unsigned char TB3L @ 0x350;
#define tb3l  TB3L

/* Timer B3 (high byte) */ 
__no_init volatile unsigned char TB3H @ 0x351;
#define tb3h  TB3H

/* Timer B4 */ 
__no_init volatile unsigned short TB4 @ 0x352;
#define tb4  TB4

/* Timer B4 (low byte) */ 
__no_init volatile unsigned char TB4L @ 0x352;
#define tb4l  TB4L

/* Timer B4 (high byte) */ 
__no_init volatile unsigned char TB4H @ 0x353;
#define tb4h  TB4H

/* Timer B5 */ 
__no_init volatile unsigned short TB5 @ 0x354;
#define tb5  TB5

/* Timer B5 (low byte) */ 
__no_init volatile unsigned char TB5L @ 0x354;
#define tb5l  TB5L

/* Timer B5 (high byte) */ 
__no_init volatile unsigned char TB5H @ 0x355;
#define tb5h  TB5H

/* Timer B3 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TB3MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char MR2            : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TB3MR_bit;
} @ 0x35B;
#define tb3mr           TB3MR    
#define tmod0_tb3mr     TB3MR_bit.TMOD0    
#define tmod1_tb3mr     TB3MR_bit.TMOD1    
#define mr0_tb3mr       TB3MR_bit.MR0    
#define mr1_tb3mr       TB3MR_bit.MR1    
#define mr2_tb3mr       TB3MR_bit.MR2    
#define mr3_tb3mr       TB3MR_bit.MR3    
#define tck0_tb3mr      TB3MR_bit.TCK0    
#define tck1_tb3mr      TB3MR_bit.TCK1

/* Timer B4 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TB4MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char                : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TB4MR_bit;
} @ 0x35C;
#define tb4mr           TB4MR    
#define tmod0_tb4mr     TB4MR_bit.TMOD0    
#define tmod1_tb4mr     TB4MR_bit.TMOD1    
#define mr0_tb4mr       TB4MR_bit.MR0    
#define mr1_tb4mr       TB4MR_bit.MR1    
#define mr3_tb4mr       TB4MR_bit.MR3    
#define tck0_tb4mr      TB4MR_bit.TCK0    
#define tck1_tb4mr      TB4MR_bit.TCK1

/* Timer B5 mode register */ 
__data13 __no_init volatile union
{
  unsigned char TB5MR;
  struct
  {
    unsigned char TMOD0          : 1;  
    unsigned char TMOD1          : 1;  
    unsigned char MR0            : 1;  
    unsigned char MR1            : 1;  
    unsigned char                : 1;  
    unsigned char MR3            : 1;  
    unsigned char TCK0           : 1;  
    unsigned char TCK1           : 1;  
  } TB5MR_bit;
} @ 0x35D;
#define tb5mr           TB5MR    
#define tmod0_tb5mr     TB5MR_bit.TMOD0    
#define tmod1_tb5mr     TB5MR_bit.TMOD1    
#define mr0_tb5mr       TB5MR_bit.MR0    
#define mr1_tb5mr       TB5MR_bit.MR1    
#define mr3_tb5mr       TB5MR_bit.MR3    
#define tck0_tb5mr      TB5MR_bit.TCK0    
#define tck1_tb5mr      TB5MR_bit.TCK1

/* Timer A1-1 register */ 
__data13 __no_init volatile unsigned short TA11 @ 0x342;
#define ta11  TA11

/* Timer A1-1 register (low byte) */ 
__data13 __no_init volatile unsigned char TA11L @ 0x342;
#define ta11l  TA11L

/* Timer A1-1 register (high byte) */ 
__data13 __no_init volatile unsigned char TA11H @ 0x343;
#define ta11h  TA11H

/* Timer A2-1 register */ 
__data13 __no_init volatile unsigned short TA21 @ 0x344;
#define ta21  TA21

/* Timer A2-1 register (low byte) */ 
__data13 __no_init volatile unsigned char TA21L @ 0x344;
#define ta21l  TA21L

/* Timer A2-1 register (high byte) */ 
__data13 __no_init volatile unsigned char TA21H @ 0x345;
#define ta21h  TA21H

/* Timer A4-1 register */ 
__data13 __no_init volatile unsigned short TA41 @ 0x346;
#define ta41  TA41

/* Timer A4-1 register (low byte) */ 
__data13 __no_init volatile unsigned char TA41L @ 0x346;
#define ta41l  TA41L

/* Timer A4-1 register (high byte) */ 
__data13 __no_init volatile unsigned char TA41H @ 0x347;
#define ta41h  TA41H

/* Three-phase PWM control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char INVC0;
  struct
  {
    unsigned char INV00          : 1;  
    unsigned char INV01          : 1;  
    unsigned char INV02          : 1;  
    unsigned char INV03          : 1;  
    unsigned char INV04          : 1;  
    unsigned char INV05          : 1;  
    unsigned char INV06          : 1;  
    unsigned char INV07          : 1;  
  } INVC0_bit;
} @ 0x348;
#define invc0           INVC0    
#define inv00           INVC0_bit.INV00    
#define inv01           INVC0_bit.INV01    
#define inv02           INVC0_bit.INV02    
#define inv03           INVC0_bit.INV03    
#define inv04           INVC0_bit.INV04    
#define inv05           INVC0_bit.INV05    
#define inv06           INVC0_bit.INV06    
#define inv07           INVC0_bit.INV07

/* Three-phase PWM control register 1 */ 
__data13 __no_init volatile union
{
  unsigned char INVC1;
  struct
  {
    unsigned char INV10          : 1;  
    unsigned char INV11          : 1;  
    unsigned char INV12          : 1;  
    unsigned char INV13          : 1;  
    unsigned char INV14          : 1;  
    unsigned char INV15          : 1;  
    unsigned char INV16          : 1;  
    unsigned char                : 1;  
  } INVC1_bit;
} @ 0x349;
#define invc1           INVC1    
#define inv10           INVC1_bit.INV10    
#define inv11           INVC1_bit.INV11    
#define inv12           INVC1_bit.INV12    
#define inv13           INVC1_bit.INV13    
#define inv14           INVC1_bit.INV14    
#define inv15           INVC1_bit.INV15    
#define inv16           INVC1_bit.INV16

/* Three-phase output buffer register 0 */ 
__data13 __no_init volatile union
{
  unsigned char IDB0;
  struct
  {
    unsigned char DU0            : 1;  
    unsigned char DUB0           : 1;  
    unsigned char DV0            : 1;  
    unsigned char DVB0           : 1;  
    unsigned char DW0            : 1;  
    unsigned char DWB0           : 1;  
    unsigned char                : 2;  
  } IDB0_bit;
} @ 0x34A;
#define idb0            IDB0    
#define du0             IDB0_bit.DU0    
#define dub0            IDB0_bit.DUB0    
#define dv0             IDB0_bit.DV0    
#define dvb0            IDB0_bit.DVB0    
#define dw0             IDB0_bit.DW0    
#define dwb0            IDB0_bit.DWB0

/* Three-phase output buffer register 1 */ 
__data13 __no_init volatile union
{
  unsigned char IDB1;
  struct
  {
    unsigned char DU1            : 1;  
    unsigned char DUB1           : 1;  
    unsigned char DV1            : 1;  
    unsigned char DVB1           : 1;  
    unsigned char DW1            : 1;  
    unsigned char DWB1           : 1;  
    unsigned char                : 2;  
  } IDB1_bit;
} @ 0x34B;
#define idb1            IDB1    
#define du1             IDB1_bit.DU1    
#define dub1            IDB1_bit.DUB1    
#define dv1             IDB1_bit.DV1    
#define dvb1            IDB1_bit.DVB1    
#define dw1             IDB1_bit.DW1    
#define dwb1            IDB1_bit.DWB1

/* Dead time timer */ 
__data13 __no_init volatile unsigned char DTT @ 0x34C;
#define dtt  DTT

/* Timer B2 interrupt occurence frequency set coutnter */ 
__data13 __no_init volatile unsigned char ICTB2 @ 0x34D;
#define ictb2  ICTB2


/*-------------------------------------------------------------------------
 *   UART Registers
 *-------------------------------------------------------------------------*/

/* UART 0 transmit/receive mode register */ 
__data13 __no_init volatile union
{
  unsigned char U0MR;
  struct
  {
    unsigned char SMD0           : 1;  
    unsigned char SMD1           : 1;  
    unsigned char SMD2           : 1;  
    unsigned char CKDIR          : 1;  
    unsigned char STPS           : 1;  
    unsigned char PRY            : 1;  
    unsigned char PRYE           : 1;  
    unsigned char IOPOL          : 1;  
  } U0MR_bit;
} @ 0x3A0;
#define u0mr            U0MR    
#define smd0_u0mr       U0MR_bit.SMD0    
#define smd1_u0mr       U0MR_bit.SMD1    
#define smd2_u0mr       U0MR_bit.SMD2    
#define ckdir_u0mr      U0MR_bit.CKDIR    
#define stps_u0mr       U0MR_bit.STPS    
#define pry_u0mr        U0MR_bit.PRY    
#define prye_u0mr       U0MR_bit.PRYE    
#define iopol_u0mr      U0MR_bit.IOPOL

/* UART 0 baud rate generator */ 
__no_init volatile unsigned char U0BRG @ 0x3A1;
#define u0brg  U0BRG

/* UART 0 transmit buffer */ 
__no_init volatile unsigned short U0TB @ 0x3A2;
#define u0tb  U0TB

/* UART 0 transmit buffer (low byte) */ 
__no_init volatile unsigned char U0TBL @ 0x3A2;
#define u0tbl  U0TBL

/* UART 0 transmit buffer (high byte) */ 
__no_init volatile unsigned char U0TBH @ 0x3A3;
#define u0tbh  U0TBH

/* UART 0 transmit/receive control register */ 
__data13 __no_init volatile unsigned short U0C @ 0x3A4;
#define u0c  U0C

/* UART 0 transmit/receive control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char U0C0;
  struct
  {
    unsigned char CLK0           : 1;  
    unsigned char CLK1           : 1;  
    unsigned char CRS            : 1;  
    unsigned char TXEPT          : 1;  
    unsigned char CRD            : 1;  
    unsigned char NCH            : 1;  
    unsigned char CKPOL          : 1;  
    unsigned char UFORM          : 1;  
  } U0C0_bit;
} @ 0x3A4;
#define u0c0            U0C0    
#define clk0_u0c0       U0C0_bit.CLK0    
#define clk1_u0c0       U0C0_bit.CLK1    
#define crs_u0c0        U0C0_bit.CRS    
#define txept_u0c0      U0C0_bit.TXEPT    
#define crd_u0c0        U0C0_bit.CRD    
#define nch_u0c0        U0C0_bit.NCH    
#define ckpol_u0c0      U0C0_bit.CKPOL    
#define uform_u0c0      U0C0_bit.UFORM

/* UART 0 transmit/receive control register 1 */ 
__data13 __no_init volatile union
{
  unsigned char U0C1;
  struct
  {
    unsigned char TE             : 1;  
    unsigned char TI             : 1;  
    unsigned char RE             : 1;  
    unsigned char RI             : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char U0LCH          : 1;  
    unsigned char U0ERE          : 1;  
  } U0C1_bit;
} @ 0x3A5;
#define u0c1            U0C1    
#define te_u0c1         U0C1_bit.TE    
#define ti_u0c1         U0C1_bit.TI    
#define re_u0c1         U0C1_bit.RE    
#define ri_u0c1         U0C1_bit.RI    
#define u0lch_u0c1           U0C1_bit.U0LCH    
#define u0ere_u0c1           U0C1_bit.U0ERE

/* UART 0 receive buffer */ 
__data13 __no_init volatile unsigned short U0RB @ 0x3A6;
#define u0rb  U0RB

/* UART 0 receive buffer (low byte) */ 
__data13 __no_init volatile unsigned char U0RBL @ 0x3A6;
#define u0rbl  U0RBL

/* UART 0 receive buffer (high byte) */ 
__data13 __no_init volatile union
{
  unsigned char U0RBH;
  struct
  {
    unsigned char                : 3;  
    unsigned char ABT            : 1;  
    unsigned char OER            : 1;  
    unsigned char FER            : 1;  
    unsigned char PER            : 1;  
    unsigned char SUM            : 1;  
  } U0RBH_bit;
} @ 0x3A7;
#define u0rbh           U0RBH    
#define abt_u0rbh       U0RBH_bit.ABT    
#define oer_u0rbh       U0RBH_bit.OER    
#define fer_u0rbh       U0RBH_bit.FER    
#define per_u0rbh       U0RBH_bit.PER    
#define sum_u0rbh       U0RBH_bit.SUM

/* UART 1 transmit/receive mode register */ 
__data13 __no_init volatile union
{
  unsigned char U1MR;
  struct
  {
    unsigned char SMD0           : 1;  
    unsigned char SMD1           : 1;  
    unsigned char SMD2           : 1;  
    unsigned char CKDIR          : 1;  
    unsigned char STPS           : 1;  
    unsigned char PRY            : 1;  
    unsigned char PRYE           : 1;  
    unsigned char IOPOL          : 1;  
  } U1MR_bit;
} @ 0x3A8;
#define u1mr            U1MR    
#define smd0_u1mr       U1MR_bit.SMD0    
#define smd1_u1mr       U1MR_bit.SMD1    
#define smd2_u1mr       U1MR_bit.SMD2    
#define ckdir_u1mr      U1MR_bit.CKDIR    
#define stps_u1mr       U1MR_bit.STPS    
#define pry_u1mr        U1MR_bit.PRY    
#define prye_u1mr       U1MR_bit.PRYE    
#define iopol_u1mr      U1MR_bit.IOPOL

/* UART 1 baud rate generator */ 
__no_init volatile unsigned char U1BRG @ 0x3A9;
#define u1brg  U1BRG

/* UART 1 transmit buffer */ 
__no_init volatile unsigned short U1TB @ 0x3AA;
#define u1tb  U1TB

/* UART 1 transmit buffer (low byte) */ 
__no_init volatile unsigned char U1TBL @ 0x3AA;
#define u1tbl  U1TBL

/* UART 1 tfransmit buffer (high byte) */ 
__no_init volatile unsigned char U1TBH @ 0x3AB;
#define u1tbh  U1TBH

/* UART 1 transmit/receive control register */ 
__data13 __no_init volatile unsigned short U1C @ 0x3AC;
#define u1c  U1C

/* UART 1 transmit/receive control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char U1C0;
  struct
  {
    unsigned char CLK0           : 1;  
    unsigned char CLK1           : 1;  
    unsigned char CRS            : 1;  
    unsigned char TXEPT          : 1;  
    unsigned char CRD            : 1;  
    unsigned char NCH            : 1;  
    unsigned char CKPOL          : 1;  
    unsigned char UFORM          : 1;  
  } U1C0_bit;
} @ 0x3AC;
#define u1c0            U1C0    
#define clk0_u1c0       U1C0_bit.CLK0    
#define clk1_u1c0       U1C0_bit.CLK1    
#define crs_u1c0        U1C0_bit.CRS    
#define txept_u1c0      U1C0_bit.TXEPT    
#define crd_u1c0        U1C0_bit.CRD    
#define nch_u1c0        U1C0_bit.NCH    
#define ckpol_u1c0      U1C0_bit.CKPOL    
#define uform_u1c0      U1C0_bit.UFORM

/* UART 1 transmit/receive control register 1 */ 
__data13 __no_init volatile union
{
  unsigned char U1C1;
  struct
  {
    unsigned char TE             : 1;  
    unsigned char TI             : 1;  
    unsigned char RE             : 1;  
    unsigned char RI             : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char U1LCH          : 1;  
    unsigned char U1ERE          : 1;  
  } U1C1_bit;
} @ 0x3AD;
#define u1c1            U1C1    
#define te_u1c1         U1C1_bit.TE    
#define ti_u1c1         U1C1_bit.TI    
#define re_u1c1         U1C1_bit.RE    
#define ri_u1c1         U1C1_bit.RI    
#define u1lch_u1c1           U1C1_bit.U1LCH    
#define u1ere_u1c1           U1C1_bit.U1ERE

/* UART 1 receive buffer */ 
__data13 __no_init volatile unsigned short U1RB @ 0x3AE;
#define u1rb  U1RB

/* UART 1 receive buffer (low byte) */ 
__data13 __no_init volatile unsigned char U1RBL @ 0x3AE;
#define u1rbl  U1RBL

/* UART 1 receive buffer (high byte) */ 
__data13 __no_init volatile union
{
  unsigned char U1RBH;
  struct
  {
    unsigned char                : 3;  
    unsigned char ABT            : 1;  
    unsigned char OER            : 1;  
    unsigned char FER            : 1;  
    unsigned char PER            : 1;  
    unsigned char SUM            : 1;  
  } U1RBH_bit;
} @ 0x3AF;
#define u1rbh           U1RBH    
#define abt_u1rbh       U1RBH_bit.ABT    
#define oer_u1rbh       U1RBH_bit.OER    
#define fer_u1rbh       U1RBH_bit.FER    
#define per_u1rbh       U1RBH_bit.PER    
#define sum_u1rbh       U1RBH_bit.SUM

/* UART transmit/receive control register 2 */ 
__data13 __no_init volatile union
{
  unsigned char UCON;
  struct
  {
    unsigned char U0IRS          : 1;  
    unsigned char U1IRS          : 1;  
    unsigned char U0RRM          : 1;  
    unsigned char U1RRM          : 1;  
    unsigned char CLKMD0         : 1;  
    unsigned char CLKMD1         : 1;  
    unsigned char RCSP           : 1;  
  } UCON_bit;
} @ 0x3B0;
#define ucon            UCON    
#define u0irs           UCON_bit.U0IRS    
#define u1irs           UCON_bit.U1IRS    
#define u0rrm           UCON_bit.U0RRM    
#define u1rrm           UCON_bit.U1RRM    
#define clkmd0          UCON_bit.CLKMD0    
#define clkmd1          UCON_bit.CLKMD1    
#define rcsp            UCON_bit.RCSP

/* SI/O3 transmit/receive register */ 
__data13 __no_init volatile unsigned char S3TRR @ 0x360;
#define s3trr  S3TRR

/* SI/O3 control register */ 
__data13 __no_init volatile union
{
  unsigned char S3C;
  struct
  {
    unsigned char SM30           : 1;  
    unsigned char SM31           : 1;  
    unsigned char SM32           : 1;  
    unsigned char SM33           : 1;  
    unsigned char SM34           : 1;  
    unsigned char SM35           : 1;  
    unsigned char SM36           : 1;  
    unsigned char SM37           : 1;  
  } S3C_bit;
} @ 0x362;
#define s3c             S3C    
#define sm30            S3C_bit.SM30    
#define sm31            S3C_bit.SM31    
#define sm32            S3C_bit.SM32    
#define sm33            S3C_bit.SM33    
#define sm34            S3C_bit.SM34    
#define sm35            S3C_bit.SM35    
#define sm36            S3C_bit.SM36    
#define sm37            S3C_bit.SM37

/* SI/O3 bit rate generator */ 
__data13 __no_init volatile unsigned char S3BRG @ 0x363;
#define s3brg  S3BRG

/* SI/O4 transmit/reveive register */ 
__data13 __no_init volatile unsigned char S4TRR @ 0x364;
#define s4trr  S4TRR

/* SI/O4 control register */ 
__data13 __no_init volatile union
{
  unsigned char S4C;
  struct
  {
    unsigned char SM40           : 1;  
    unsigned char SM41           : 1;  
    unsigned char SM42           : 1;  
    unsigned char SM43           : 1;  
    unsigned char SM44           : 1;  
    unsigned char SM45           : 1;  
    unsigned char SM46           : 1;  
    unsigned char SM47           : 1;  
  } S4C_bit;
} @ 0x366;
#define s4c             S4C    
#define sm40            S4C_bit.SM40    
#define sm41            S4C_bit.SM41    
#define sm42            S4C_bit.SM42    
#define sm43            S4C_bit.SM43    
#define sm44            S4C_bit.SM44    
#define sm45            S4C_bit.SM45    
#define sm46            S4C_bit.SM46    
#define sm47            S4C_bit.SM47

/* SI/O4 bit rate generator */ 
__data13 __no_init volatile unsigned char S4BRG @ 0x367;
#define s4brg  S4BRG

/* UART 0 special mode register 4 */ 
__data13 __no_init volatile union
{
  unsigned char U0SMR4;
  struct
  {
    unsigned char STAREQ         : 1;  
    unsigned char RSTAREQ        : 1;  
    unsigned char STPREQ         : 1;  
    unsigned char STSPSEL        : 1;  
    unsigned char ACKD           : 1;  
    unsigned char ACKC           : 1;  
    unsigned char SCLHI          : 1;  
    unsigned char SWC9           : 1;  
  } U0SMR4_bit;
} @ 0x36C;
#define u0smr4          U0SMR4    
#define stareq_u0smr4   U0SMR4_bit.STAREQ    
#define rstareq_u0smr4  U0SMR4_bit.RSTAREQ    
#define stpreq_u0smr4   U0SMR4_bit.STPREQ    
#define stspsel_u0smr4  U0SMR4_bit.STSPSEL    
#define ackd_u0smr4     U0SMR4_bit.ACKD    
#define ackc_u0smr4     U0SMR4_bit.ACKC    
#define sclhi_u0smr4    U0SMR4_bit.SCLHI    
#define swc9_u0smr4     U0SMR4_bit.SWC9

/* UART 0 special mode register 3 */ 
__data13 __no_init volatile union
{
  unsigned char U0SMR3;
  struct
  {
    unsigned char                : 1;  
    unsigned char CKPH           : 1;  
    unsigned char                : 1;  
    unsigned char NODC           : 1;  
    unsigned char                : 1;  
    unsigned char DL0            : 1;  
    unsigned char DL1            : 1;  
    unsigned char DL2            : 1;  
  } U0SMR3_bit;
} @ 0x36D;
#define u0smr3          U0SMR3    
#define ckph_u0smr3     U0SMR3_bit.CKPH    
#define nodc_u0smr3     U0SMR3_bit.NODC    
#define dl0_u0smr3      U0SMR3_bit.DL0    
#define dl1_u0smr3      U0SMR3_bit.DL1    
#define dl2_u0smr3      U0SMR3_bit.DL2

/* UART 0 special mode register 2 */ 
__data13 __no_init volatile union
{
  unsigned char U0SMR2;
  struct
  {
    unsigned char IICM2          : 1;  
    unsigned char CSC            : 1;  
    unsigned char SWC            : 1;  
    unsigned char ALS            : 1;  
    unsigned char STAC           : 1;  
    unsigned char SWC2           : 1;  
    unsigned char SDHI           : 1;  
  } U0SMR2_bit;
} @ 0x36E;
#define u0smr2          U0SMR2    
#define iicm2_u0smr2    U0SMR2_bit.IICM2    
#define csc_u0smr2      U0SMR2_bit.CSC    
#define swc_u0smr2      U0SMR2_bit.SWC    
#define als_u0smr2      U0SMR2_bit.ALS    
#define stac_u0smr2     U0SMR2_bit.STAC    
#define swc2_u0smr2     U0SMR2_bit.SWC2    
#define sdhi_u0smr2     U0SMR2_bit.SDHI

/* UART 0 special mode register */ 
__data13 __no_init volatile union
{
  unsigned char U0SMR;
  struct
  {
    unsigned char IICM           : 1;  
    unsigned char ABC            : 1;  
    unsigned char BBS            : 1;  
    unsigned char LSYN           : 1;  
    unsigned char ABSCS          : 1;  
    unsigned char ACSE           : 1;  
    unsigned char SSS            : 1;  
  } U0SMR_bit;
} @ 0x36F;
#define u0smr           U0SMR    
#define iicm_u0smr      U0SMR_bit.IICM    
#define abc_u0smr       U0SMR_bit.ABC    
#define bbs_u0smr       U0SMR_bit.BBS    
#define lsyn_u0smr      U0SMR_bit.LSYN    
#define abscs_u0smr     U0SMR_bit.ABSCS    
#define acse_u0smr      U0SMR_bit.ACSE    
#define sss_u0smr       U0SMR_bit.SSS

/* UART 1 special mode register 4 */ 
__data13 __no_init volatile union
{
  unsigned char U1SMR4;
  struct
  {
    unsigned char STAREQ         : 1;  
    unsigned char RSTAREQ        : 1;  
    unsigned char STPREQ         : 1;  
    unsigned char STSPSEL        : 1;  
    unsigned char ACKD           : 1;  
    unsigned char ACKC           : 1;  
    unsigned char SCLHI          : 1;  
    unsigned char SWC9           : 1;  
  } U1SMR4_bit;
} @ 0x370;
#define u1smr4          U1SMR4    
#define stareq_u1smr4   U1SMR4_bit.STAREQ    
#define rstareq_u1smr4  U1SMR4_bit.RSTAREQ    
#define stpreq_u1smr4   U1SMR4_bit.STPREQ    
#define stspsel_u1smr4  U1SMR4_bit.STSPSEL    
#define ackd_u1smr4     U1SMR4_bit.ACKD    
#define ackc_u1smr4     U1SMR4_bit.ACKC    
#define sclhi_u1smr4    U1SMR4_bit.SCLHI    
#define swc9_u1smr4     U1SMR4_bit.SWC9

/* UART 1 special mode register 3 */ 
__data13 __no_init volatile union
{
  unsigned char U1SMR3;
  struct
  {
    unsigned char                : 1;  
    unsigned char CKPH           : 1;  
    unsigned char                : 1;  
    unsigned char NODC           : 1;  
    unsigned char                : 1;  
    unsigned char DL0            : 1;  
    unsigned char DL1            : 1;  
    unsigned char DL2            : 1;  
  } U1SMR3_bit;
} @ 0x371;
#define u1smr3          U1SMR3    
#define ckph_u1smr3     U1SMR3_bit.CKPH    
#define nodc_u1smr3     U1SMR3_bit.NODC    
#define dl0_u1smr3      U1SMR3_bit.DL0    
#define dl1_u1smr3      U1SMR3_bit.DL1    
#define dl2_u1smr3      U1SMR3_bit.DL2

/* UART 1 special mode register 2 */ 
__data13 __no_init volatile union
{
  unsigned char U1SMR2;
  struct
  {
    unsigned char IICM2          : 1;  
    unsigned char CSC            : 1;  
    unsigned char SWC            : 1;  
    unsigned char ALS            : 1;  
    unsigned char STAC           : 1;  
    unsigned char SWC2           : 1;  
    unsigned char SDHI           : 1;  
  } U1SMR2_bit;
} @ 0x372;
#define u1smr2          U1SMR2    
#define iicm2_u1smr2    U1SMR2_bit.IICM2    
#define csc_u1smr2      U1SMR2_bit.CSC    
#define swc_u1smr2      U1SMR2_bit.SWC    
#define als_u1smr2      U1SMR2_bit.ALS    
#define stac_u1smr2     U1SMR2_bit.STAC    
#define swc2_u1smr2     U1SMR2_bit.SWC2    
#define sdhi_u1smr2     U1SMR2_bit.SDHI

/* UART 1 special mode register */ 
__data13 __no_init volatile union
{
  unsigned char U1SMR;
  struct
  {
    unsigned char IICM           : 1;  
    unsigned char ABC            : 1;  
    unsigned char BBS            : 1;  
    unsigned char LSYN           : 1;  
    unsigned char ABSCS          : 1;  
    unsigned char ACSE           : 1;  
    unsigned char SSS            : 1;  
  } U1SMR_bit;
} @ 0x373;
#define u1smr           U1SMR    
#define iicm_u1smr      U1SMR_bit.IICM    
#define abc_u1smr       U1SMR_bit.ABC    
#define bbs_u1smr       U1SMR_bit.BBS    
#define lsyn_u1smr      U1SMR_bit.LSYN    
#define abscs_u1smr     U1SMR_bit.ABSCS    
#define acse_u1smr      U1SMR_bit.ACSE    
#define sss_u1smr       U1SMR_bit.SSS

/* UART 2 special mode register 4 */ 
__data13 __no_init volatile union
{
  unsigned char U2SMR4;
  struct
  {
    unsigned char STAREQ         : 1;  
    unsigned char RSTAREQ        : 1;  
    unsigned char STPREQ         : 1;  
    unsigned char STSPSEL        : 1;  
    unsigned char ACKD           : 1;  
    unsigned char ACKC           : 1;  
    unsigned char SCLHI          : 1;  
    unsigned char SWC9           : 1;  
  } U2SMR4_bit;
} @ 0x374;
#define u2smr4          U2SMR4    
#define stareq_u2smr4   U2SMR4_bit.STAREQ    
#define rstareq_u2smr4  U2SMR4_bit.RSTAREQ    
#define stpreq_u2smr4   U2SMR4_bit.STPREQ    
#define stspsel_u2smr4  U2SMR4_bit.STSPSEL    
#define ackd_u2smr4     U2SMR4_bit.ACKD    
#define ackc_u2smr4     U2SMR4_bit.ACKC    
#define sclhi_u2smr4    U2SMR4_bit.SCLHI    
#define swc9_u2smr4     U2SMR4_bit.SWC9

/* UART 2 special mode register 3 */ 
__data13 __no_init volatile union
{
  unsigned char U2SMR3;
  struct
  {
    unsigned char                : 1;  
    unsigned char CKPH           : 1;  
    unsigned char                : 1;  
    unsigned char NODC           : 1;  
    unsigned char                : 1;  
    unsigned char DL0            : 1;  
    unsigned char DL1            : 1;  
    unsigned char DL2            : 1;  
  } U2SMR3_bit;
} @ 0x375;
#define u2smr3          U2SMR3    
#define ckph_u2smr3     U2SMR3_bit.CKPH    
#define nodc_u2smr3     U2SMR3_bit.NODC    
#define dl0_u2smr3      U2SMR3_bit.DL0    
#define dl1_u2smr3      U2SMR3_bit.DL1    
#define dl2_u2smr3      U2SMR3_bit.DL2

/* UART 2 special mode register 2 */ 
__data13 __no_init volatile union
{
  unsigned char U2SMR2;
  struct
  {
    unsigned char IICM2          : 1;  
    unsigned char CSC            : 1;  
    unsigned char SWC            : 1;  
    unsigned char ALS            : 1;  
    unsigned char STAC           : 1;  
    unsigned char SWC2           : 1;  
    unsigned char SDHI           : 1;  
  } U2SMR2_bit;
} @ 0x376;
#define u2smr2          U2SMR2    
#define iicm2_u2smr2    U2SMR2_bit.IICM2    
#define csc_u2smr2      U2SMR2_bit.CSC    
#define swc_u2smr2      U2SMR2_bit.SWC    
#define als_u2smr2      U2SMR2_bit.ALS    
#define stac_u2smr2     U2SMR2_bit.STAC    
#define swc2_u2smr2     U2SMR2_bit.SWC2    
#define sdhi_u2smr2     U2SMR2_bit.SDHI

/* UART 2 special mode register */ 
__data13 __no_init volatile union
{
  unsigned char U2SMR;
  struct
  {
    unsigned char IICM           : 1;  
    unsigned char ABC            : 1;  
    unsigned char BBS            : 1;  
    unsigned char LSYN           : 1;  
    unsigned char ABSCS          : 1;  
    unsigned char ACSE           : 1;  
    unsigned char SSS            : 1;  
  } U2SMR_bit;
} @ 0x377;
#define u2smr           U2SMR    
#define iicm_u2smr      U2SMR_bit.IICM    
#define abc_u2smr       U2SMR_bit.ABC    
#define bbs_u2smr       U2SMR_bit.BBS    
#define lsyn_u2smr      U2SMR_bit.LSYN    
#define abscs_u2smr     U2SMR_bit.ABSCS    
#define acse_u2smr      U2SMR_bit.ACSE    
#define sss_u2smr       U2SMR_bit.SSS

/* UART 2 transmit/receive mode register */ 
__data13 __no_init volatile union
{
  unsigned char U2MR;
  struct
  {
    unsigned char SMD0           : 1;  
    unsigned char SMD1           : 1;  
    unsigned char SMD2           : 1;  
    unsigned char CKDIR          : 1;  
    unsigned char STPS           : 1;  
    unsigned char PRY            : 1;  
    unsigned char PRYE           : 1;  
    unsigned char IOPOL          : 1;  
  } U2MR_bit;
} @ 0x378;
#define u2mr            U2MR    
#define smd0_u2mr       U2MR_bit.SMD0    
#define smd1_u2mr       U2MR_bit.SMD1    
#define smd2_u2mr       U2MR_bit.SMD2    
#define ckdir_u2mr      U2MR_bit.CKDIR    
#define stps_u2mr       U2MR_bit.STPS    
#define pry_u2mr        U2MR_bit.PRY    
#define prye_u2mr       U2MR_bit.PRYE    
#define iopol_u2mr      U2MR_bit.IOPOL

/* UART 2 bit rate generator */ 
__no_init volatile unsigned char U2BRG @ 0x379;
#define u2brg  U2BRG

/* UART 2 transmit buffer register */ 
__no_init volatile unsigned short U2TB @ 0x37A;
#define u2tb  U2TB

/* UART 2 transmit buffer register (low byte) */ 
__no_init volatile unsigned char U2TBL @ 0x37A;
#define u2tbl  U2TBL

/* UART 2 transmit buffer register (high byte) */ 
__no_init volatile unsigned char U2TBH @ 0x37B;
#define u2tbh  U2TBH

/* UART 2 transmit/receive control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char U2C0;
  struct
  {
    unsigned char CLK0           : 1;  
    unsigned char CLK1           : 1;  
    unsigned char CRS            : 1;  
    unsigned char TXEPT          : 1;  
    unsigned char CRD            : 1;  
    unsigned char NCH            : 1;  
    unsigned char CKPOL          : 1;  
    unsigned char UFORM          : 1;  
  } U2C0_bit;
} @ 0x37C;
#define u2c0            U2C0    
#define clk0_u2c0       U2C0_bit.CLK0    
#define clk1_u2c0       U2C0_bit.CLK1    
#define crs_u2c0        U2C0_bit.CRS    
#define txept_u2c0      U2C0_bit.TXEPT    
#define crd_u2c0        U2C0_bit.CRD    
#define nch_u2c0        U2C0_bit.NCH    
#define ckpol_u2c0      U2C0_bit.CKPOL    
#define uform_u2c0      U2C0_bit.UFORM

/* UART 2 transmit/receive control register 1 */ 
__data13 __no_init volatile union
{
  unsigned char U2C1;
  struct
  {
    unsigned char TE             : 1;  
    unsigned char TI             : 1;  
    unsigned char RE             : 1;  
    unsigned char RI             : 1;  
    unsigned char U2IRS          : 1;  
    unsigned char U2RRM          : 1;  
    unsigned char U2LCH          : 1;  
    unsigned char U2ERE          : 1;  
  } U2C1_bit;
} @ 0x37D;
#define u2c1            U2C1    
#define te_u2c1         U2C1_bit.TE    
#define ti_u2c1         U2C1_bit.TI    
#define re_u2c1         U2C1_bit.RE    
#define ri_u2c1         U2C1_bit.RI    
#define u2irs_u2c1           U2C1_bit.U2IRS    
#define u2rrm_u2c1           U2C1_bit.U2RRM    
#define u2lch_u2c1           U2C1_bit.U2LCH    
#define u2ere_u2c1           U2C1_bit.U2ERE

/* UART 2 receive buffer register */ 
__data13 __no_init volatile unsigned short U2RB @ 0x37E;
#define u2rb  U2RB

/* UART 2 receive buffer register (low byte) */ 
__data13 __no_init volatile unsigned char U2RBL @ 0x37E;
#define u2rbl  U2RBL

/* UART 2 receive buffer register (high byte) */ 
__data13 __no_init volatile union
{
  unsigned char U2RBH;
  struct
  {
    unsigned char                : 3;  
    unsigned char ABT            : 1;  
    unsigned char OER            : 1;  
    unsigned char FER            : 1;  
    unsigned char PER            : 1;  
    unsigned char SUM            : 1;  
  } U2RBH_bit;
} @ 0x37F;
#define u2rbh           U2RBH    
#define abt_u2rbh       U2RBH_bit.ABT    
#define oer_u2rbh       U2RBH_bit.OER    
#define fer_u2rbh       U2RBH_bit.FER    
#define per_u2rbh       U2RBH_bit.PER    
#define sum_u2rbh       U2RBH_bit.SUM


/*-------------------------------------------------------------------------
 *   Flash control register
 *-------------------------------------------------------------------------*/

/* Flash identification register */ 
__data13 __no_init volatile unsigned char FIDR @ 0x1B4;
#define fidr  FIDR

/* Flash memory control register 1 */ 
__data13 __no_init volatile union
{
  unsigned char FMR1;
  struct
  {
    unsigned char                : 1;  
    unsigned char FMR11          : 1;  
    unsigned char                : 4;  
    unsigned char FMR16          : 1;  
  } FMR1_bit;
} @ 0x1B5;
#define fmr1            FMR1    
#define fmr11           FMR1_bit.FMR11    
#define fmr16           FMR1_bit.FMR16

/* Flash memory control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char FMR0;
  struct
  {
    unsigned char FMR00          : 1;  
    unsigned char FMR01          : 1;  
    unsigned char FMR02          : 1;  
    unsigned char FMSTP          : 1;  
    unsigned char                : 1;  
    unsigned char FMR05          : 1;  
    unsigned char FMR06          : 1;  
    unsigned char FMR07          : 1;  
  } FMR0_bit;
} @ 0x1B7;
#define fmr0            FMR0    
#define fmr00           FMR0_bit.FMR00    
#define fmr01           FMR0_bit.FMR01    
#define fmr02           FMR0_bit.FMR02    
#define fmstp           FMR0_bit.FMSTP    
#define fmr05           FMR0_bit.FMR05    
#define fmr06           FMR0_bit.FMR06    
#define fmr07           FMR0_bit.FMR07


/*-------------------------------------------------------------------------
 *   CRC register
 *-------------------------------------------------------------------------*/

/* CRC data register */ 
__data13 __no_init volatile unsigned short CRCD @ 0x3BC;
#define crcd  CRCD

/* CRC data register (low byte) */ 
__data13 __no_init volatile unsigned char CRCDL @ 0x3BC;
#define crcdl  CRCDL

/* CRC data register (high byte) */ 
__data13 __no_init volatile unsigned char CRCDH @ 0x3BD;
#define crcdh  CRCDH

/* CRC input register */ 
__data13 __no_init volatile unsigned char CRCIN @ 0x3BE;
#define crcin  CRCIN


/*-------------------------------------------------------------------------
 *   A/D Converter
 *-------------------------------------------------------------------------*/

/* A/D register 0 */ 
__data13 __no_init volatile unsigned short AD0 @ 0x3C0;
#define ad0  AD0

/* A/D register 0 (low byte) */ 
__data13 __no_init volatile unsigned char AD0L @ 0x3C0;
#define ad0l  AD0L

/* A/D register 0 (high byte) */ 
__data13 __no_init volatile unsigned char AD0H @ 0x3C1;
#define ad0h  AD0H

/* A/D register 1 */ 
__data13 __no_init volatile unsigned short AD1 @ 0x3C2;
#define ad1  AD1

/* A/D register 1 (low byte) */ 
__data13 __no_init volatile unsigned char AD1L @ 0x3C2;
#define ad1l  AD1L

/* A/D register 1 (high byte) */ 
__data13 __no_init volatile unsigned char AD1H @ 0x3C3;
#define ad1h  AD1H

/* A/D register 2 */ 
__data13 __no_init volatile unsigned short AD2 @ 0x3C4;
#define ad2  AD2

/* A/D register 2 (low byte) */ 
__data13 __no_init volatile unsigned char AD2L @ 0x3C4;
#define ad2l  AD2L

/* A/D register 2 (high byte) */ 
__data13 __no_init volatile unsigned char AD2H @ 0x3C5;
#define ad2h  AD2H

/* A/D register 3 */ 
__data13 __no_init volatile unsigned short AD3 @ 0x3C6;
#define ad3  AD3

/* A/D register 3 (low byte) */ 
__data13 __no_init volatile unsigned char AD3L @ 0x3C6;
#define ad3l  AD3L

/* A/D register 3 (high byte) */ 
__data13 __no_init volatile unsigned char AD3H @ 0x3C7;
#define ad3h  AD3H

/* A/D register 4 */ 
__data13 __no_init volatile unsigned short AD4 @ 0x3C8;
#define ad4  AD4

/* A/D register 4 (low byte) */ 
__data13 __no_init volatile unsigned char AD4L @ 0x3C8;
#define ad4l  AD4L

/* A/D register 4 (high byte) */ 
__data13 __no_init volatile unsigned char AD4H @ 0x3C9;
#define ad4h  AD4H

/* A/D register 5 */ 
__data13 __no_init volatile unsigned short AD5 @ 0x3CA;
#define ad5  AD5

/* A/D register 5 (low byte) */ 
__data13 __no_init volatile unsigned char AD5L @ 0x3CA;
#define ad5l  AD5L

/* A/D register 5 (high byte) */ 
__data13 __no_init volatile unsigned char AD5H @ 0x3CB;
#define ad5h  AD5H

/* A/D register 6 */ 
__data13 __no_init volatile unsigned short AD6 @ 0x3CC;
#define ad6  AD6

/* A/D register 6 (low byte) */ 
__data13 __no_init volatile unsigned char AD6L @ 0x3CC;
#define ad6l  AD6L

/* A/D register 6 (high byte) */ 
__data13 __no_init volatile unsigned char AD6H @ 0x3CD;
#define ad6h  AD6H

/* A/D register 7 */ 
__data13 __no_init volatile unsigned short AD7 @ 0x3CE;
#define ad7  AD7

/* A/D register 7 (low byte) */ 
__data13 __no_init volatile unsigned char AD7L @ 0x3CE;
#define ad7l  AD7L

/* A/D register 7 (high byte) */ 
__data13 __no_init volatile unsigned char AD7H @ 0x3CF;
#define ad7h  AD7H

/* A/D control register 2 */ 
__data13 __no_init volatile union
{
  unsigned char ADCON2;
  struct
  {
    unsigned char SMP            : 1;  
    unsigned char ADGSEL0        : 1;  
    unsigned char ADGSEL1        : 1;  
    unsigned char                : 1;  
    unsigned char CKS2           : 1;  
  } ADCON2_bit;
} @ 0x3D4;
#define adcon2          ADCON2    
#define smp             ADCON2_bit.SMP    
#define adgsel0         ADCON2_bit.ADGSEL0    
#define adgsel1         ADCON2_bit.ADGSEL1    
#define cks2            ADCON2_bit.CKS2

/* A/D control register 0 */ 
__data13 __no_init volatile union
{
  unsigned char ADCON0;
  struct
  {
    unsigned char CH0            : 1;  
    unsigned char CH1            : 1;  
    unsigned char CH2            : 1;  
    unsigned char MD0            : 1;  
    unsigned char MD1            : 1;  
    unsigned char TRG            : 1;  
    unsigned char ADST           : 1;  
    unsigned char CKS0           : 1;  
  } ADCON0_bit;
} @ 0x3D6;
#define adcon0          ADCON0    
#define ch0             ADCON0_bit.CH0    
#define ch1             ADCON0_bit.CH1    
#define ch2             ADCON0_bit.CH2    
#define md0             ADCON0_bit.MD0    
#define md1             ADCON0_bit.MD1    
#define trg             ADCON0_bit.TRG    
#define adst            ADCON0_bit.ADST    
#define cks0            ADCON0_bit.CKS0

/* A/D control register 1 */ 
__data13 __no_init volatile union
{
  unsigned char ADCON1;
  struct
  {
    unsigned char SCAN0          : 1;  
    unsigned char SCAN1          : 1;  
    unsigned char MD2            : 1;  
    unsigned char BITS           : 1;  
    unsigned char CKS1           : 1;  
    unsigned char VCUT           : 1;  
    unsigned char OPA0           : 1;  
    unsigned char OPA1           : 1;  
  } ADCON1_bit;
} @ 0x3D7;
#define adcon1          ADCON1    
#define scan0           ADCON1_bit.SCAN0    
#define scan1           ADCON1_bit.SCAN1    
#define md2             ADCON1_bit.MD2    
#define bits            ADCON1_bit.BITS    
#define cks1            ADCON1_bit.CKS1    
#define vcut            ADCON1_bit.VCUT    
#define opa0            ADCON1_bit.OPA0    
#define opa1            ADCON1_bit.OPA1


/*-------------------------------------------------------------------------
 *   D-A Converter
 *-------------------------------------------------------------------------*/

/* D-A register 0 */ 
__data13 __no_init volatile unsigned char DA0 @ 0x3D8;
#define da0  DA0

/* D-A register 1 */ 
__data13 __no_init volatile unsigned char DA1 @ 0x3DA;
#define da1  DA1

/* D-A control register */ 
__data13 __no_init volatile union
{
  unsigned char DACON;
  struct
  {
    unsigned char DA0E           : 1;  
    unsigned char DA1E           : 1;  
  } DACON_bit;
} @ 0x3DC;
#define dacon           DACON    
#define da0e            DACON_bit.DA0E    
#define da1e            DACON_bit.DA1E


/*-------------------------------------------------------------------------
 *   Power supply
 *-------------------------------------------------------------------------*/

/* Power supply detection register 1 */ 
__data13 __no_init volatile union
{
  unsigned char VCR1;
  struct
  {
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char VC13           : 1;  
  } VCR1_bit;
} @ 0x019;
#define vcr1            VCR1    
#define vc13            VCR1_bit.VC13

/* Power supply detection register 2 */ 
__data13 __no_init volatile union
{
  unsigned char VCR2;
  struct
  {
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char VC25           : 1;  
    unsigned char VC26           : 1;  
    unsigned char VC27           : 1;  
  } VCR2_bit;
} @ 0x01A;
#define vcr2            VCR2    
#define vc25            VCR2_bit.VC25    
#define vc26            VCR2_bit.VC26    
#define vc27            VCR2_bit.VC27

/* Power supply down detection register */ 
__data13 __no_init volatile union
{
  unsigned char D4INT;
  struct
  {
    unsigned char D40            : 1;  
    unsigned char D41            : 1;  
    unsigned char D42            : 1;  
    unsigned char D43            : 1;  
    unsigned char DF0            : 1;  
    unsigned char DF1            : 1;  
  } D4INT_bit;
} @ 0x01F;
#define d4int           D4INT    
#define d40             D4INT_bit.D40    
#define d41             D4INT_bit.D41    
#define d42             D4INT_bit.D42    
#define d43             D4INT_bit.D43    
#define df0             D4INT_bit.DF0    
#define df1             D4INT_bit.DF1


/*-------------------------------------------------------------------------
 *   Port Registers
 *-------------------------------------------------------------------------*/

/* Port P14 register */ 
__data13 __no_init volatile union
{
  unsigned char PC14;
  struct
  {
    unsigned char P140           : 1;  
    unsigned char P141           : 1;  
    unsigned char                : 1;  
    unsigned char                : 1;  
    unsigned char PD140          : 1;  
    unsigned char PD141          : 1;  
  } PC14_bit;
} @ 0x3DE;
#define pc14            PC14    
#define p140            PC14_bit.P140    
#define p141            PC14_bit.P141    
#define pd140           PC14_bit.PD140    
#define pd141           PC14_bit.PD141

/* Pull-up register 3 */ 
__data13 __no_init volatile union
{
  unsigned char PUR3;
  struct
  {
    unsigned char PU30           : 1;  
    unsigned char PU31           : 1;  
    unsigned char PU32           : 1;  
    unsigned char PU33           : 1;  
    unsigned char PU34           : 1;  
    unsigned char PU35           : 1;  
    unsigned char PU36           : 1;  
    unsigned char PU37           : 1;  
  } PUR3_bit;
} @ 0x3DF;
#define pur3            PUR3    
#define pu30            PUR3_bit.PU30    
#define pu31            PUR3_bit.PU31    
#define pu32            PUR3_bit.PU32    
#define pu33            PUR3_bit.PU33    
#define pu34            PUR3_bit.PU34    
#define pu35            PUR3_bit.PU35    
#define pu36            PUR3_bit.PU36    
#define pu37            PUR3_bit.PU37

/* Port P0 register */ 
__data13 __no_init volatile union
{
  unsigned char P0;
  struct
  {
    unsigned char P0_0           : 1;  
    unsigned char P0_1           : 1;  
    unsigned char P0_2           : 1;  
    unsigned char P0_3           : 1;  
    unsigned char P0_4           : 1;  
    unsigned char P0_5           : 1;  
    unsigned char P0_6           : 1;  
    unsigned char P0_7           : 1;  
  } P0_bit;
} @ 0x3E0;
#define p0              P0    
#define p0_0            P0_bit.P0_0    
#define p0_1            P0_bit.P0_1    
#define p0_2            P0_bit.P0_2    
#define p0_3            P0_bit.P0_3    
#define p0_4            P0_bit.P0_4    
#define p0_5            P0_bit.P0_5    
#define p0_6            P0_bit.P0_6    
#define p0_7            P0_bit.P0_7

/* Port P1 register */ 
__data13 __no_init volatile union
{
  unsigned char P1;
  struct
  {
    unsigned char P1_0           : 1;  
    unsigned char P1_1           : 1;  
    unsigned char P1_2           : 1;  
    unsigned char P1_3           : 1;  
    unsigned char P1_4           : 1;  
    unsigned char P1_5           : 1;  
    unsigned char P1_6           : 1;  
    unsigned char P1_7           : 1;  
  } P1_bit;
} @ 0x3E1;
#define p1              P1    
#define p1_0            P1_bit.P1_0    
#define p1_1            P1_bit.P1_1    
#define p1_2            P1_bit.P1_2    
#define p1_3            P1_bit.P1_3    
#define p1_4            P1_bit.P1_4    
#define p1_5            P1_bit.P1_5    
#define p1_6            P1_bit.P1_6    
#define p1_7            P1_bit.P1_7

/* Port P0 and P1 register */ 
__data13 __no_init volatile unsigned short P01 @ 0x3E0;
#define p01  P01

/* Port P0 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD0;
  struct
  {
    unsigned char PD0_0          : 1;  
    unsigned char PD0_1          : 1;  
    unsigned char PD0_2          : 1;  
    unsigned char PD0_3          : 1;  
    unsigned char PD0_4          : 1;  
    unsigned char PD0_5          : 1;  
    unsigned char PD0_6          : 1;  
    unsigned char PD0_7          : 1;  
  } PD0_bit;
} @ 0x3E2;
#define pd0             PD0    
#define pd0_0           PD0_bit.PD0_0    
#define pd0_1           PD0_bit.PD0_1    
#define pd0_2           PD0_bit.PD0_2    
#define pd0_3           PD0_bit.PD0_3    
#define pd0_4           PD0_bit.PD0_4    
#define pd0_5           PD0_bit.PD0_5    
#define pd0_6           PD0_bit.PD0_6    
#define pd0_7           PD0_bit.PD0_7

/* Port P1 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD1;
  struct
  {
    unsigned char PD1_0          : 1;  
    unsigned char PD1_1          : 1;  
    unsigned char PD1_2          : 1;  
    unsigned char PD1_3          : 1;  
    unsigned char PD1_4          : 1;  
    unsigned char PD1_5          : 1;  
    unsigned char PD1_6          : 1;  
    unsigned char PD1_7          : 1;  
  } PD1_bit;
} @ 0x3E3;
#define pd1             PD1    
#define pd1_0           PD1_bit.PD1_0    
#define pd1_1           PD1_bit.PD1_1    
#define pd1_2           PD1_bit.PD1_2    
#define pd1_3           PD1_bit.PD1_3    
#define pd1_4           PD1_bit.PD1_4    
#define pd1_5           PD1_bit.PD1_5    
#define pd1_6           PD1_bit.PD1_6    
#define pd1_7           PD1_bit.PD1_7

/* Port P0 and P1 direction register */ 
__data13 __no_init volatile unsigned short PD01 @ 0x3E2;
#define pd01  PD01

/* Port P2 register */ 
__data13 __no_init volatile union
{
  unsigned char P2;
  struct
  {
    unsigned char P2_0           : 1;  
    unsigned char P2_1           : 1;  
    unsigned char P2_2           : 1;  
    unsigned char P2_3           : 1;  
    unsigned char P2_4           : 1;  
    unsigned char P2_5           : 1;  
    unsigned char P2_6           : 1;  
    unsigned char P2_7           : 1;  
  } P2_bit;
} @ 0x3E4;
#define p2              P2    
#define p2_0            P2_bit.P2_0    
#define p2_1            P2_bit.P2_1    
#define p2_2            P2_bit.P2_2    
#define p2_3            P2_bit.P2_3    
#define p2_4            P2_bit.P2_4    
#define p2_5            P2_bit.P2_5    
#define p2_6            P2_bit.P2_6    
#define p2_7            P2_bit.P2_7

/* Port P3 register */ 
__data13 __no_init volatile union
{
  unsigned char P3;
  struct
  {
    unsigned char P3_0           : 1;  
    unsigned char P3_1           : 1;  
    unsigned char P3_2           : 1;  
    unsigned char P3_3           : 1;  
    unsigned char P3_4           : 1;  
    unsigned char P3_5           : 1;  
    unsigned char P3_6           : 1;  
    unsigned char P3_7           : 1;  
  } P3_bit;
} @ 0x3E5;
#define p3              P3    
#define p3_0            P3_bit.P3_0    
#define p3_1            P3_bit.P3_1    
#define p3_2            P3_bit.P3_2    
#define p3_3            P3_bit.P3_3    
#define p3_4            P3_bit.P3_4    
#define p3_5            P3_bit.P3_5    
#define p3_6            P3_bit.P3_6    
#define p3_7            P3_bit.P3_7

/* Port P2 and P3 register */ 
__data13 __no_init volatile unsigned short P23 @ 0x3E4;
#define p23  P23

/* Port P2 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD2;
  struct
  {
    unsigned char PD2_0          : 1;  
    unsigned char PD2_1          : 1;  
    unsigned char PD2_2          : 1;  
    unsigned char PD2_3          : 1;  
    unsigned char PD2_4          : 1;  
    unsigned char PD2_5          : 1;  
    unsigned char PD2_6          : 1;  
    unsigned char PD2_7          : 1;  
  } PD2_bit;
} @ 0x3E6;
#define pd2             PD2    
#define pd2_0           PD2_bit.PD2_0    
#define pd2_1           PD2_bit.PD2_1    
#define pd2_2           PD2_bit.PD2_2    
#define pd2_3           PD2_bit.PD2_3    
#define pd2_4           PD2_bit.PD2_4    
#define pd2_5           PD2_bit.PD2_5    
#define pd2_6           PD2_bit.PD2_6    
#define pd2_7           PD2_bit.PD2_7

/* Port P3 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD3;
  struct
  {
    unsigned char PD3_0          : 1;  
    unsigned char PD3_1          : 1;  
    unsigned char PD3_2          : 1;  
    unsigned char PD3_3          : 1;  
    unsigned char PD3_4          : 1;  
    unsigned char PD3_5          : 1;  
    unsigned char PD3_6          : 1;  
    unsigned char PD3_7          : 1;  
  } PD3_bit;
} @ 0x3E7;
#define pd3             PD3    
#define pd3_0           PD3_bit.PD3_0    
#define pd3_1           PD3_bit.PD3_1    
#define pd3_2           PD3_bit.PD3_2    
#define pd3_3           PD3_bit.PD3_3    
#define pd3_4           PD3_bit.PD3_4    
#define pd3_5           PD3_bit.PD3_5    
#define pd3_6           PD3_bit.PD3_6    
#define pd3_7           PD3_bit.PD3_7

/* Port P2 and P3 direction register */ 
__data13 __no_init volatile unsigned short PD23 @ 0x3E6;
#define pd23  PD23

/* Port P4 register */ 
__data13 __no_init volatile union
{
  unsigned char P4;
  struct
  {
    unsigned char P4_0           : 1;  
    unsigned char P4_1           : 1;  
    unsigned char P4_2           : 1;  
    unsigned char P4_3           : 1;  
    unsigned char P4_4           : 1;  
    unsigned char P4_5           : 1;  
    unsigned char P4_6           : 1;  
    unsigned char P4_7           : 1;  
  } P4_bit;
} @ 0x3E8;
#define p4              P4    
#define p4_0            P4_bit.P4_0    
#define p4_1            P4_bit.P4_1    
#define p4_2            P4_bit.P4_2    
#define p4_3            P4_bit.P4_3    
#define p4_4            P4_bit.P4_4    
#define p4_5            P4_bit.P4_5    
#define p4_6            P4_bit.P4_6    
#define p4_7            P4_bit.P4_7

/* Port P5 register */ 
__data13 __no_init volatile union
{
  unsigned char P5;
  struct
  {
    unsigned char P5_0           : 1;  
    unsigned char P5_1           : 1;  
    unsigned char P5_2           : 1;  
    unsigned char P5_3           : 1;  
    unsigned char P5_4           : 1;  
    unsigned char P5_5           : 1;  
    unsigned char P5_6           : 1;  
    unsigned char P5_7           : 1;  
  } P5_bit;
} @ 0x3E9;
#define p5              P5    
#define p5_0            P5_bit.P5_0    
#define p5_1            P5_bit.P5_1    
#define p5_2            P5_bit.P5_2    
#define p5_3            P5_bit.P5_3    
#define p5_4            P5_bit.P5_4    
#define p5_5            P5_bit.P5_5    
#define p5_6            P5_bit.P5_6    
#define p5_7            P5_bit.P5_7

/* Port P4 and P5 register */ 
__data13 __no_init volatile unsigned short P45 @ 0x3E8;
#define p45  P45

/* Port P4 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD4;
  struct
  {
    unsigned char PD4_0          : 1;  
    unsigned char PD4_1          : 1;  
    unsigned char PD4_2          : 1;  
    unsigned char PD4_3          : 1;  
    unsigned char PD4_4          : 1;  
    unsigned char PD4_5          : 1;  
    unsigned char PD4_6          : 1;  
    unsigned char PD4_7          : 1;  
  } PD4_bit;
} @ 0x3EA;
#define pd4             PD4    
#define pd4_0           PD4_bit.PD4_0    
#define pd4_1           PD4_bit.PD4_1    
#define pd4_2           PD4_bit.PD4_2    
#define pd4_3           PD4_bit.PD4_3    
#define pd4_4           PD4_bit.PD4_4    
#define pd4_5           PD4_bit.PD4_5    
#define pd4_6           PD4_bit.PD4_6    
#define pd4_7           PD4_bit.PD4_7

/* Port P5 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD5;
  struct
  {
    unsigned char PD5_0          : 1;  
    unsigned char PD5_1          : 1;  
    unsigned char PD5_2          : 1;  
    unsigned char PD5_3          : 1;  
    unsigned char PD5_4          : 1;  
    unsigned char PD5_5          : 1;  
    unsigned char PD5_6          : 1;  
    unsigned char PD5_7          : 1;  
  } PD5_bit;
} @ 0x3EB;
#define pd5             PD5    
#define pd5_0           PD5_bit.PD5_0    
#define pd5_1           PD5_bit.PD5_1    
#define pd5_2           PD5_bit.PD5_2    
#define pd5_3           PD5_bit.PD5_3    
#define pd5_4           PD5_bit.PD5_4    
#define pd5_5           PD5_bit.PD5_5    
#define pd5_6           PD5_bit.PD5_6    
#define pd5_7           PD5_bit.PD5_7

/* Port P4 and P5 direction register */ 
__data13 __no_init volatile unsigned short PD45 @ 0x3EA;
#define pd45  PD45

/* Port P6 register */ 
__data13 __no_init volatile union
{
  unsigned char P6;
  struct
  {
    unsigned char P6_0           : 1;  
    unsigned char P6_1           : 1;  
    unsigned char P6_2           : 1;  
    unsigned char P6_3           : 1;  
    unsigned char P6_4           : 1;  
    unsigned char P6_5           : 1;  
    unsigned char P6_6           : 1;  
    unsigned char P6_7           : 1;  
  } P6_bit;
} @ 0x3EC;
#define p6              P6    
#define p6_0            P6_bit.P6_0    
#define p6_1            P6_bit.P6_1    
#define p6_2            P6_bit.P6_2    
#define p6_3            P6_bit.P6_3    
#define p6_4            P6_bit.P6_4    
#define p6_5            P6_bit.P6_5    
#define p6_6            P6_bit.P6_6    
#define p6_7            P6_bit.P6_7

/* Port P7 register */ 
__data13 __no_init volatile union
{
  unsigned char P7;
  struct
  {
    unsigned char P7_0           : 1;  
    unsigned char P7_1           : 1;  
    unsigned char P7_2           : 1;  
    unsigned char P7_3           : 1;  
    unsigned char P7_4           : 1;  
    unsigned char P7_5           : 1;  
    unsigned char P7_6           : 1;  
    unsigned char P7_7           : 1;  
  } P7_bit;
} @ 0x3ED;
#define p7              P7    
#define p7_0            P7_bit.P7_0    
#define p7_1            P7_bit.P7_1    
#define p7_2            P7_bit.P7_2    
#define p7_3            P7_bit.P7_3    
#define p7_4            P7_bit.P7_4    
#define p7_5            P7_bit.P7_5    
#define p7_6            P7_bit.P7_6    
#define p7_7            P7_bit.P7_7

/* Port P6 and P7 register */ 
__data13 __no_init volatile unsigned short P67 @ 0x3EC;
#define p67  P67

/* Port P6 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD6;
  struct
  {
    unsigned char PD6_0          : 1;  
    unsigned char PD6_1          : 1;  
    unsigned char PD6_2          : 1;  
    unsigned char PD6_3          : 1;  
    unsigned char PD6_4          : 1;  
    unsigned char PD6_5          : 1;  
    unsigned char PD6_6          : 1;  
    unsigned char PD6_7          : 1;  
  } PD6_bit;
} @ 0x3EE;
#define pd6             PD6    
#define pd6_0           PD6_bit.PD6_0    
#define pd6_1           PD6_bit.PD6_1    
#define pd6_2           PD6_bit.PD6_2    
#define pd6_3           PD6_bit.PD6_3    
#define pd6_4           PD6_bit.PD6_4    
#define pd6_5           PD6_bit.PD6_5    
#define pd6_6           PD6_bit.PD6_6    
#define pd6_7           PD6_bit.PD6_7

/* Port P7 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD7;
  struct
  {
    unsigned char PD7_0          : 1;  
    unsigned char PD7_1          : 1;  
    unsigned char PD7_2          : 1;  
    unsigned char PD7_3          : 1;  
    unsigned char PD7_4          : 1;  
    unsigned char PD7_5          : 1;  
    unsigned char PD7_6          : 1;  
    unsigned char PD7_7          : 1;  
  } PD7_bit;
} @ 0x3EF;
#define pd7             PD7    
#define pd7_0           PD7_bit.PD7_0    
#define pd7_1           PD7_bit.PD7_1    
#define pd7_2           PD7_bit.PD7_2    
#define pd7_3           PD7_bit.PD7_3    
#define pd7_4           PD7_bit.PD7_4    
#define pd7_5           PD7_bit.PD7_5    
#define pd7_6           PD7_bit.PD7_6    
#define pd7_7           PD7_bit.PD7_7

/* Port P6 and P7 direction register */ 
__data13 __no_init volatile unsigned short PD67 @ 0x3EE;
#define pd67  PD67

/* Port P8 register */ 
__data13 __no_init volatile union
{
  unsigned char P8;
  struct
  {
    unsigned char P8_0           : 1;  
    unsigned char P8_1           : 1;  
    unsigned char P8_2           : 1;  
    unsigned char P8_3           : 1;  
    unsigned char P8_4           : 1;  
    unsigned char P8_5           : 1;  
    unsigned char P8_6           : 1;  
    unsigned char P8_7           : 1;  
  } P8_bit;
} @ 0x3F0;
#define p8              P8    
#define p8_0            P8_bit.P8_0    
#define p8_1            P8_bit.P8_1    
#define p8_2            P8_bit.P8_2    
#define p8_3            P8_bit.P8_3    
#define p8_4            P8_bit.P8_4    
#define p8_5            P8_bit.P8_5    
#define p8_6            P8_bit.P8_6    
#define p8_7            P8_bit.P8_7

/* Port P9 register */ 
__data13 __no_init volatile union
{
  unsigned char P9;
  struct
  {
    unsigned char P9_0           : 1;  
    unsigned char P9_1           : 1;  
    unsigned char P9_2           : 1;  
    unsigned char P9_3           : 1;  
    unsigned char P9_4           : 1;  
    unsigned char P9_5           : 1;  
    unsigned char P9_6           : 1;  
    unsigned char P9_7           : 1;  
  } P9_bit;
} @ 0x3F1;
#define p9              P9    
#define p9_0            P9_bit.P9_0    
#define p9_1            P9_bit.P9_1    
#define p9_2            P9_bit.P9_2    
#define p9_3            P9_bit.P9_3    
#define p9_4            P9_bit.P9_4    
#define p9_5            P9_bit.P9_5    
#define p9_6            P9_bit.P9_6    
#define p9_7            P9_bit.P9_7

/* Port P8 and P9 register */ 
__data13 __no_init volatile unsigned short P89 @ 0x3F0;
#define p89  P89

/* Port P8 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD8;
  struct
  {
    unsigned char PD8_0          : 1;  
    unsigned char PD8_1          : 1;  
    unsigned char PD8_2          : 1;  
    unsigned char PD8_3          : 1;  
    unsigned char PD8_4          : 1;  
    unsigned char                : 1;  
    unsigned char PD8_6          : 1;  
    unsigned char PD8_7          : 1;  
  } PD8_bit;
} @ 0x3F2;
#define pd8             PD8    
#define pd8_0           PD8_bit.PD8_0    
#define pd8_1           PD8_bit.PD8_1    
#define pd8_2           PD8_bit.PD8_2    
#define pd8_3           PD8_bit.PD8_3    
#define pd8_4           PD8_bit.PD8_4    
#define pd8_6           PD8_bit.PD8_6    
#define pd8_7           PD8_bit.PD8_7

/* Port P9 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD9;
  struct
  {
    unsigned char PD9_0          : 1;  
    unsigned char PD9_1          : 1;  
    unsigned char PD9_2          : 1;  
    unsigned char PD9_3          : 1;  
    unsigned char PD9_4          : 1;  
    unsigned char PD9_5          : 1;  
    unsigned char PD9_6          : 1;  
    unsigned char PD9_7          : 1;  
  } PD9_bit;
} @ 0x3F3;
#define pd9             PD9    
#define pd9_0           PD9_bit.PD9_0    
#define pd9_1           PD9_bit.PD9_1    
#define pd9_2           PD9_bit.PD9_2    
#define pd9_3           PD9_bit.PD9_3    
#define pd9_4           PD9_bit.PD9_4    
#define pd9_5           PD9_bit.PD9_5    
#define pd9_6           PD9_bit.PD9_6    
#define pd9_7           PD9_bit.PD9_7

/* Port P8 and P9 direction register */ 
__data13 __no_init volatile unsigned short PD89 @ 0x3F2;
#define pd89  PD89

/* Port P10 register */ 
__data13 __no_init volatile union
{
  unsigned char P10;
  struct
  {
    unsigned char P10_0          : 1;  
    unsigned char P10_1          : 1;  
    unsigned char P10_2          : 1;  
    unsigned char P10_3          : 1;  
    unsigned char P10_4          : 1;  
    unsigned char P10_5          : 1;  
    unsigned char P10_6          : 1;  
    unsigned char P10_7          : 1;  
  } P10_bit;
} @ 0x3F4;
#define p10             P10    
#define p10_0           P10_bit.P10_0    
#define p10_1           P10_bit.P10_1    
#define p10_2           P10_bit.P10_2    
#define p10_3           P10_bit.P10_3    
#define p10_4           P10_bit.P10_4    
#define p10_5           P10_bit.P10_5    
#define p10_6           P10_bit.P10_6    
#define p10_7           P10_bit.P10_7

/* Port P11 register */ 
__data13 __no_init volatile union
{
  unsigned char P11;
  struct
  {
    unsigned char P11_0          : 1;  
    unsigned char P11_1          : 1;  
    unsigned char P11_2          : 1;  
    unsigned char P11_3          : 1;  
    unsigned char P11_4          : 1;  
    unsigned char P11_5          : 1;  
    unsigned char P11_6          : 1;  
    unsigned char P11_7          : 1;  
  } P11_bit;
} @ 0x3F5;
#define p11             P11    
#define p11_0           P11_bit.P11_0    
#define p11_1           P11_bit.P11_1    
#define p11_2           P11_bit.P11_2    
#define p11_3           P11_bit.P11_3    
#define p11_4           P11_bit.P11_4    
#define p11_5           P11_bit.P11_5    
#define p11_6           P11_bit.P11_6    
#define p11_7           P11_bit.P11_7

/* Port P10 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD10;
  struct
  {
    unsigned char PD10_0         : 1;  
    unsigned char PD10_1         : 1;  
    unsigned char PD10_2         : 1;  
    unsigned char PD10_3         : 1;  
    unsigned char PD10_4         : 1;  
    unsigned char PD10_5         : 1;  
    unsigned char PD10_6         : 1;  
    unsigned char PD10_7         : 1;  
  } PD10_bit;
} @ 0x3F6;
#define pd10            PD10    
#define pd10_0          PD10_bit.PD10_0    
#define pd10_1          PD10_bit.PD10_1    
#define pd10_2          PD10_bit.PD10_2    
#define pd10_3          PD10_bit.PD10_3    
#define pd10_4          PD10_bit.PD10_4    
#define pd10_5          PD10_bit.PD10_5    
#define pd10_6          PD10_bit.PD10_6    
#define pd10_7          PD10_bit.PD10_7

/* Port P11 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD11;
  struct
  {
    unsigned char PD11_0         : 1;  
    unsigned char PD11_1         : 1;  
    unsigned char PD11_2         : 1;  
    unsigned char PD11_3         : 1;  
    unsigned char PD11_4         : 1;  
    unsigned char PD11_5         : 1;  
    unsigned char PD11_6         : 1;  
    unsigned char PD11_7         : 1;  
  } PD11_bit;
} @ 0x3F7;
#define pd11            PD11    
#define pd11_0          PD11_bit.PD11_0    
#define pd11_1          PD11_bit.PD11_1    
#define pd11_2          PD11_bit.PD11_2    
#define pd11_3          PD11_bit.PD11_3    
#define pd11_4          PD11_bit.PD11_4    
#define pd11_5          PD11_bit.PD11_5    
#define pd11_6          PD11_bit.PD11_6    
#define pd11_7          PD11_bit.PD11_7

/* Port P12 register */ 
__data13 __no_init volatile union
{
  unsigned char P12;
  struct
  {
    unsigned char P12_0          : 1;  
    unsigned char P12_1          : 1;  
    unsigned char P12_2          : 1;  
    unsigned char P12_3          : 1;  
    unsigned char P12_4          : 1;  
    unsigned char P12_5          : 1;  
    unsigned char P12_6          : 1;  
    unsigned char P12_7          : 1;  
  } P12_bit;
} @ 0x3F8;
#define p12             P12    
#define p12_0           P12_bit.P12_0    
#define p12_1           P12_bit.P12_1    
#define p12_2           P12_bit.P12_2    
#define p12_3           P12_bit.P12_3    
#define p12_4           P12_bit.P12_4    
#define p12_5           P12_bit.P12_5    
#define p12_6           P12_bit.P12_6    
#define p12_7           P12_bit.P12_7

/* Port P13 register */ 
__data13 __no_init volatile union
{
  unsigned char P13;
  struct
  {
    unsigned char P13_0          : 1;  
    unsigned char P13_1          : 1;  
    unsigned char P13_2          : 1;  
    unsigned char P13_3          : 1;  
    unsigned char P13_4          : 1;  
    unsigned char P13_5          : 1;  
    unsigned char P13_6          : 1;  
    unsigned char P13_7          : 1;  
  } P13_bit;
} @ 0x3F9;
#define p13             P13    
#define p13_0           P13_bit.P13_0    
#define p13_1           P13_bit.P13_1    
#define p13_2           P13_bit.P13_2    
#define p13_3           P13_bit.P13_3    
#define p13_4           P13_bit.P13_4    
#define p13_5           P13_bit.P13_5    
#define p13_6           P13_bit.P13_6    
#define p13_7           P13_bit.P13_7

/* Port P12 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD12;
  struct
  {
    unsigned char PD12_0         : 1;  
    unsigned char PD12_1         : 1;  
    unsigned char PD12_2         : 1;  
    unsigned char PD12_3         : 1;  
    unsigned char PD12_4         : 1;  
    unsigned char PD12_5         : 1;  
    unsigned char PD12_6         : 1;  
    unsigned char PD12_7         : 1;  
  } PD12_bit;
} @ 0x3FA;
#define pd12            PD12    
#define pd12_0          PD12_bit.PD12_0    
#define pd12_1          PD12_bit.PD12_1    
#define pd12_2          PD12_bit.PD12_2    
#define pd12_3          PD12_bit.PD12_3    
#define pd12_4          PD12_bit.PD12_4    
#define pd12_5          PD12_bit.PD12_5    
#define pd12_6          PD12_bit.PD12_6    
#define pd12_7          PD12_bit.PD12_7

/* Port P13 direction register */ 
__data13 __no_init volatile union
{
  unsigned char PD13;
  struct
  {
    unsigned char PD13_0         : 1;  
    unsigned char PD13_1         : 1;  
    unsigned char PD13_2         : 1;  
    unsigned char PD13_3         : 1;  
    unsigned char PD13_4         : 1;  
    unsigned char PD13_5         : 1;  
    unsigned char PD13_6         : 1;  
    unsigned char PD13_7         : 1;  
  } PD13_bit;
} @ 0x3FB;
#define pd13            PD13    
#define pd13_0          PD13_bit.PD13_0    
#define pd13_1          PD13_bit.PD13_1    
#define pd13_2          PD13_bit.PD13_2    
#define pd13_3          PD13_bit.PD13_3    
#define pd13_4          PD13_bit.PD13_4    
#define pd13_5          PD13_bit.PD13_5    
#define pd13_6          PD13_bit.PD13_6    
#define pd13_7          PD13_bit.PD13_7

/* Port P12 and P13 direction register */ 
__data13 __no_init volatile unsigned short PD1213 @ 0x3FA;
#define pd1213  PD1213

/* Pull-up register 0 */ 
__data13 __no_init volatile union
{
  unsigned char PUR0;
  struct
  {
    unsigned char PU00           : 1;  
  } PUR0_bit;
} @ 0x3FC;
#define pur0            PUR0    
#define pu00            PUR0_bit.PU00

/* Pull-up register 1 */ 
__data13 __no_init volatile unsigned char PUR1 @ 0x3FD;
#define pur1  PUR1

/* Pull-up register 0 and 1 */ 
__data13 __no_init volatile unsigned short PUR01 @ 0x3FC;
#define pur01  PUR01

/* Pull-up register 2 */ 
__data13 __no_init volatile unsigned char PUR2 @ 0x3FE;
#define pur2  PUR2

/* Port control register */ 
__data13 __no_init volatile unsigned char PCR @ 0x3FF;
#define pcr  PCR


#pragma language=default
#endif  /* __IAR_SYSTEMS_ICC__  */
#ifdef __IAR_SYSTEMS_ASM__

/***************************************************************************
 *   Assembler definitions
 ***************************************************************************/


/*-------------------------------------------------------------------------
 *   Processor Registers
 *-------------------------------------------------------------------------*/
 
/* Processor Mode Register */ 
PM                        DEFINE 0x004 
/* Processor Mode Register 0 */ 
PM0                       DEFINE 0x004
PM0_PM00                  DEFINE 0   
PM0_PM01                  DEFINE 1   
PM0_PM02                  DEFINE 2   
PM0_PM03                  DEFINE 3   
PM0_PM04                  DEFINE 4   
PM0_PM05                  DEFINE 5   
PM0_PM06                  DEFINE 6   
PM0_PM07                  DEFINE 7    
/* Processor Mode Register 1 */ 
PM1                       DEFINE 0x005
PM1_PM10                  DEFINE 0   
PM1_PM11                  DEFINE 1   
PM1_PM12                  DEFINE 2   
PM1_PM13                  DEFINE 3   
PM1_PM14                  DEFINE 4   
PM1_PM15                  DEFINE 5    
PM1_PM17                  DEFINE 7    
/* System clock control register 0 */ 
CM0                       DEFINE 0x006
CM0_CM00                  DEFINE 0   
CM0_CM01                  DEFINE 1   
CM0_CM02                  DEFINE 2   
CM0_CM03                  DEFINE 3   
CM0_CM04                  DEFINE 4   
CM0_CM05                  DEFINE 5   
CM0_CM06                  DEFINE 6   
CM0_CM07                  DEFINE 7    
/* System clock control register 1 */ 
CM1                       DEFINE 0x007
CM1_CM10                  DEFINE 0   
CM1_CM11                  DEFINE 1      
CM1_CM15                  DEFINE 5   
CM1_CM16                  DEFINE 6   
CM1_CM17                  DEFINE 7    
/* System clock control register */ 
CM                        DEFINE 0x006 
/* Chip select control register */ 
CSR                       DEFINE 0x008
CSR_CS0                   DEFINE 0   
CSR_CS1                   DEFINE 1   
CSR_CS2                   DEFINE 2   
CSR_CS3                   DEFINE 3   
CSR_CS0W                  DEFINE 4   
CSR_CS1W                  DEFINE 5   
CSR_CS2W                  DEFINE 6   
CSR_CS3W                  DEFINE 7    
/* Protect register */ 
PRCR                      DEFINE 0x00A
PRCR_PRC0                 DEFINE 0   
PRCR_PRC1                 DEFINE 1   
PRCR_PRC2                 DEFINE 2   
PRCR_PRC3                 DEFINE 3    
/* Data bank register */ 
DBR                       DEFINE 0x00B  
DBR_OFS                   DEFINE 2   
DBR_BSR0                  DEFINE 3   
DBR_BSR1                  DEFINE 4   
DBR_BSR2                  DEFINE 5    
/* Oscillation stop detection register */ 
CM2                       DEFINE 0x00C
CM2_CM20                  DEFINE 0   
CM2_CM21                  DEFINE 1   
CM2_CM22                  DEFINE 2   
CM2_CM23                  DEFINE 3      
CM2_CM27                  DEFINE 7    
/* Chip select expansion control register */ 
CSE                       DEFINE 0x01B 
/* PLC control register 0 */ 
PLC0                      DEFINE 0x01C
PLC0_PLC00                DEFINE 0   
PLC0_PLC01                DEFINE 1   
PLC0_PLC02                DEFINE 2    
PLC0_PLC07                DEFINE 7    
/* Processor Mode Register 2 */ 
PM2                       DEFINE 0x01E
PM2_PM20                  DEFINE 0   
PM2_PM21                  DEFINE 1   
PM2_PM22                  DEFINE 2    
/* Peripheral clock select register */ 
PCLKR                     DEFINE 0x25E 

/*-------------------------------------------------------------------------
 *   Watchdog Timer
 *-------------------------------------------------------------------------*/
 
/* Watchdog timer start register */ 
WDTS                      DEFINE 0x00E 
/* Watchdog timer control register */ 
WDC                       DEFINE 0x00F 
WDC_WDC5                  DEFINE 5    
WDC_WDC7                  DEFINE 7    

/*-------------------------------------------------------------------------
 *   Interrupt Control Register
 *-------------------------------------------------------------------------*/
 
/* Address match interrupt enable */ 
AIER                      DEFINE 0x009 
/* Address match interrupt register 0 */ 
RMAD0                     DEFINE 0x010 
/* Address match interrupt register 0 (low) */ 
RMAD00                    DEFINE 0x010 
/* Address match interrupt register 0 (mid) */ 
RMAD01                    DEFINE 0x011 
/* Address match interrupt register 0 (high) */ 
RMAD02                    DEFINE 0x012 
/* Address match interrupt register 0 */ 
RMAD1                     DEFINE 0x014 
/* Address match interrupt register 1 (low) */ 
RMAD10                    DEFINE 0x014 
/* Address match interrupt register 1 (mid) */ 
RMAD11                    DEFINE 0x015 
/* Address match interrupt register 1 (high) */ 
RMAD12                    DEFINE 0x016 
/* INT3 interrupt control register */ 
INT3IC                    DEFINE 0x044
INT3IC_ILVL               DEFINE 0   
INT3IC_IR                 DEFINE 3   
INT3IC_POL                DEFINE 4    
/* Timer B5 interrupt control register */ 
TB5IC                     DEFINE 0x045
TB5IC_ILVL                DEFINE 0   
TB5IC_IR                  DEFINE 3    
/* UART0 BUS collision detection interrupt control register */ 
U0BCNIC                   DEFINE 0x047
U0BCNIC_ILVL              DEFINE 0   
U0BCNIC_IR                DEFINE 3    
/* Timer B4 interrupt control register */ 
TB4IC                     DEFINE 0x046
TB4IC_ILVL                DEFINE 0   
TB4IC_IR                  DEFINE 3    
/* UART1 BUS collision detection interrupt control register */ 
U1BCNIC                   DEFINE 0x046
U1BCNIC_ILVL              DEFINE 0   
U1BCNIC_IR                DEFINE 3    
/* Timer B3 interrupt control register */ 
TB3IC                     DEFINE 0x047
TB3IC_ILVL                DEFINE 0   
TB3IC_IR                  DEFINE 3    
/* SI/O4 interrupt control register */ 
S4IC                      DEFINE 0x048
S4IC_ILVL                 DEFINE 0   
S4IC_IR                   DEFINE 3    
/* INT5 interrupt control register */ 
INT5IC                    DEFINE 0x048
INT5IC_ILVL               DEFINE 0   
INT5IC_IR                 DEFINE 3   
INT5IC_POL                DEFINE 4    
/* SI/O3 interrupt control register */ 
S3IC                      DEFINE 0x049
S3IC_ILVL                 DEFINE 0   
S3IC_IR                   DEFINE 3    
/* INT4 interrupt control register */ 
INT4IC                    DEFINE 0x049
INT4IC_ILVL               DEFINE 0   
INT4IC_IR                 DEFINE 3   
INT4IC_POL                DEFINE 4    
/* UART2 Bus collision detection interrupt control register */ 
BCNIC                     DEFINE 0x04A
BCNIC_ILVL                DEFINE 0   
BCNIC_IR                  DEFINE 3    
/* DMA0 interrupt control register */ 
DMA0IC                    DEFINE 0x04B
DMA0IC_ILVL               DEFINE 0   
DMA0IC_IR                 DEFINE 3    
/* DMA1 interrupt control register */ 
DMA1IC                    DEFINE 0x04C
DMA1IC_ILVL               DEFINE 0   
DMA1IC_IR                 DEFINE 3    
/* Key input interrupt control register */ 
KUPIC                     DEFINE 0x04D
KUPIC_ILVL                DEFINE 0   
KUPIC_IR                  DEFINE 3    
/* AD conversion interrupt control register */ 
ADIC                      DEFINE 0x04E
ADIC_ILVL                 DEFINE 0   
ADIC_IR                   DEFINE 3    
/* UART2 transmit interrupt control register */ 
S2TIC                     DEFINE 0x04F
S2TIC_ILVL                DEFINE 0   
S2TIC_IR                  DEFINE 3    
/* UART2 receive interrupt control register */ 
S2RIC                     DEFINE 0x050
S2RIC_ILVL                DEFINE 0   
S2RIC_IR                  DEFINE 3    
/* UART0 transmit interrupt control register */ 
S0TIC                     DEFINE 0x051
S0TIC_ILVL                DEFINE 0   
S0TIC_IR                  DEFINE 3    
/* UART0 receive interrupt control register */ 
S0RIC                     DEFINE 0x052
S0RIC_ILVL                DEFINE 0   
S0RIC_IR                  DEFINE 3    
/* UART1 transmit interrupt control register */ 
S1TIC                     DEFINE 0x053
S1TIC_ILVL                DEFINE 0   
S1TIC_IR                  DEFINE 3    
/* UART1 receive interrupt control register */ 
S1RIC                     DEFINE 0x054
S1RIC_ILVL                DEFINE 0   
S1RIC_IR                  DEFINE 3    
/* Timer A0 interrupt control register */ 
TA0IC                     DEFINE 0x055
TA0IC_ILVL                DEFINE 0   
TA0IC_IR                  DEFINE 3    
/* Timer A1 interrupt control register */ 
TA1IC                     DEFINE 0x056
TA1IC_ILVL                DEFINE 0   
TA1IC_IR                  DEFINE 3    
/* Timer A2 interrupt control register */ 
TA2IC                     DEFINE 0x057
TA2IC_ILVL                DEFINE 0   
TA2IC_IR                  DEFINE 3    
/* Timer A3 interrupt control register */ 
TA3IC                     DEFINE 0x058
TA3IC_ILVL                DEFINE 0   
TA3IC_IR                  DEFINE 3    
/* Timer A4 interrupt control register */ 
TA4IC                     DEFINE 0x059
TA4IC_ILVL                DEFINE 0   
TA4IC_IR                  DEFINE 3    
/* Timer B0 interrupt control register */ 
TB0IC                     DEFINE 0x05A
TB0IC_ILVL                DEFINE 0   
TB0IC_IR                  DEFINE 3    
/* Timer B1 interrupt control register */ 
TB1IC                     DEFINE 0x05B
TB1IC_ILVL                DEFINE 0   
TB1IC_IR                  DEFINE 3    
/* Timer B2 interrupt control register */ 
TB2IC                     DEFINE 0x05C
TB2IC_ILVL                DEFINE 0   
TB2IC_IR                  DEFINE 3    
/* Interrupt 0 interrupt control register */ 
INT0IC                    DEFINE 0x05D
INT0IC_ILVL               DEFINE 0   
INT0IC_IR                 DEFINE 3   
INT0IC_POL                DEFINE 4    
/* Interrupt 1 interrupt control register */ 
INT1IC                    DEFINE 0x05E
INT1IC_ILVL               DEFINE 0   
INT1IC_IR                 DEFINE 3   
INT1IC_POL                DEFINE 4    
/* Interrupt 2 interrupt control register */ 
INT2IC                    DEFINE 0x05F
INT2IC_ILVL               DEFINE 0   
INT2IC_IR                 DEFINE 3   
INT2IC_POL                DEFINE 4    
/* Address match interrupt register 2 (low) */ 
RMAD20                    DEFINE 0x1B8 
/* Address match interrupt register 2 (mid) */ 
RMAD21                    DEFINE 0x1B9 
/* Address match interrupt register 2 (high) */ 
RMAD22                    DEFINE 0x1BA 
/* Address match interrupt enable register 2 */ 
AIER2                     DEFINE 0x1BB 
/* Address match interrupt register 2 (low) */ 
RMAD30                    DEFINE 0x1BC 
/* Address match interrupt register 2 (mid) */ 
RMAD31                    DEFINE 0x1BD 
/* Address match interrupt register 2 (high) */ 
RMAD32                    DEFINE 0x1BE 
/* Interrupt cause select register 2 */ 
IFSR2A                    DEFINE 0x35E 
/* Interrupt cause select register */ 
IFSR                      DEFINE 0x35F 

/*-------------------------------------------------------------------------
 *   DMA Registers
 *-------------------------------------------------------------------------*/
 
/* DMA0 source pointer */ 
SAR0                      DEFINE 0x020 
/* DMA0 source pointer (low) */ 
SAR00                     DEFINE 0x020 
/* DMA0 source pointer (mid) */ 
SAR01                     DEFINE 0x021 
/* DMA0 source pointer (high) */ 
SAR02                     DEFINE 0x022 
/* DMA0 destination pointer */ 
DAR0                      DEFINE 0x024 
/* DMA0 destination pointer (low) */ 
DAR00                     DEFINE 0x024 
/* DMA0 destination pointer (mid) */ 
DAR01                     DEFINE 0x025 
/* DMA0 destination pointer (high) */ 
DAR02                     DEFINE 0x026 
/* DMA0 transfer counter */ 
TCR0                      DEFINE 0x028 
/* DMA0 transfer counter (low) */ 
TCR00                     DEFINE 0x028 
/* DMA0 transfer counter (high) */ 
TCR01                     DEFINE 0x029 
/* DMA0 control register */ 
DM0CON                    DEFINE 0x02C
DM0CON_DMBIT              DEFINE 0   
DM0CON_DMASL              DEFINE 1   
DM0CON_DMAS               DEFINE 2   
DM0CON_DMAE               DEFINE 3   
DM0CON_DSD                DEFINE 4   
DM0CON_DAD                DEFINE 5    
/* DMA1 source pointer */ 
SAR1                      DEFINE 0x030 
/* DMA1 source pointer (low) */ 
SAR10                     DEFINE 0x030 
/* DMA1 source pointer (mid) */ 
SAR11                     DEFINE 0x031 
/* DMA1 source pointer (high) */ 
SAR12                     DEFINE 0x032 
/* DMA1 destination pointer (low) */ 
DAR10                     DEFINE 0x034 
/* DMA1 destination pointer (mid) */ 
DAR11                     DEFINE 0x035 
/* DMA1 destination pointer (high) */ 
DAR12                     DEFINE 0x036 
/* DMA1 transfer counter */ 
TCR1                      DEFINE 0x038 
/* DMA1 transfer counter (low) */ 
TCR10                     DEFINE 0x038 
/* DMA1 transfer counter (high) */ 
TCR11                     DEFINE 0x039 
/* DMA1 control register */ 
DM1CON                    DEFINE 0x03C
DM1CON_DMBIT              DEFINE 0   
DM1CON_DMASL              DEFINE 1   
DM1CON_DMAS               DEFINE 2   
DM1CON_DMAE               DEFINE 3   
DM1CON_DSD                DEFINE 4   
DM1CON_DAD                DEFINE 5    
/* DMA0 cause select register */ 
DM0SL                     DEFINE 0x03B8
DM0SL_DSEL0               DEFINE 0   
DM0SL_DSEL1               DEFINE 1   
DM0SL_DSEL2               DEFINE 2   
DM0SL_DSEL3               DEFINE 3    
DM0SL_DMS                 DEFINE 6   
DM0SL_DSR                 DEFINE 7    
/* DMA1 cause select register */ 
DM1SL                     DEFINE 0x03BA
DM1SL_DSEL0               DEFINE 0   
DM1SL_DSEL1               DEFINE 1   
DM1SL_DSEL2               DEFINE 2   
DM1SL_DSEL3               DEFINE 3    
DM1SL_DMS                 DEFINE 6   
DM1SL_DSR                 DEFINE 7    

/*-------------------------------------------------------------------------
 *   Timer Registers
 *-------------------------------------------------------------------------*/
 
/* Timer A/B count start flags */ 
TABSR                     DEFINE 0x380
TABSR_TA0S                DEFINE 0   
TABSR_TA1S                DEFINE 1   
TABSR_TA2S                DEFINE 2   
TABSR_TA3S                DEFINE 3   
TABSR_TA4S                DEFINE 4   
TABSR_TB0S                DEFINE 5   
TABSR_TB1S                DEFINE 6   
TABSR_TB2S                DEFINE 7    
/* Clock prescaler reset flag */ 
CPSRF                     DEFINE 0x381 
CPSRF_CPSR                DEFINE 7    
/* One-shot start flagl */ 
ONSF                      DEFINE 0x382
ONSF_TA0OS                DEFINE 0   
ONSF_TA1OS                DEFINE 1   
ONSF_TA2OS                DEFINE 2   
ONSF_TA3OS                DEFINE 3   
ONSF_TA4OS                DEFINE 4   
ONSF_ZIE                  DEFINE 5   
ONSF_TA0TGL               DEFINE 6   
ONSF_TA0TGH               DEFINE 7    
/* Trigger select register */ 
TRGSR                     DEFINE 0x383
TRGSR_TA1TGL              DEFINE 0   
TRGSR_TA1TGH              DEFINE 1   
TRGSR_TA2TGL              DEFINE 2   
TRGSR_TA2TGH              DEFINE 3   
TRGSR_TA3TGL              DEFINE 4   
TRGSR_TA3TGH              DEFINE 5   
TRGSR_TA4TGL              DEFINE 6   
TRGSR_TA4TGH              DEFINE 7    
/* Up- down-count selection flag */ 
UDF                       DEFINE 0x384
UDF_TA0UD                 DEFINE 0   
UDF_TA1UD                 DEFINE 1   
UDF_TA2UD                 DEFINE 2   
UDF_TA3UD                 DEFINE 3   
UDF_TA4UD                 DEFINE 4   
UDF_TA2P                  DEFINE 5   
UDF_TA3P                  DEFINE 6   
UDF_TA4P                  DEFINE 7    
/* Timer A0 */ 
TA0                       DEFINE 0x386 
/* Timer A0 (low byte) */ 
TA0L                      DEFINE 0x386 
/* Timer A0 (high byte) */ 
TA0H                      DEFINE 0x387 
/* Timer A1 */ 
TA1                       DEFINE 0x388 
/* Timer A1 (low byte) */ 
TA1L                      DEFINE 0x388 
/* Timer A1 (high byte) */ 
TA1H                      DEFINE 0x389 
/* Timer A2 */ 
TA2                       DEFINE 0x38A 
/* Timer A2 (low byte) */ 
TA2L                      DEFINE 0x38A 
/* Timer A2 (high byte) */ 
TA2H                      DEFINE 0x38B 
/* Timer A3 */ 
TA3                       DEFINE 0x38C 
/* Timer A3 (low byte) */ 
TA3L                      DEFINE 0x38C 
/* Timer A3 (high byte) */ 
TA3H                      DEFINE 0x38D 
/* Timer A4 */ 
TA4                       DEFINE 0x38E 
/* Timer A4 (low byte) */ 
TA4L                      DEFINE 0x38E 
/* Timer A4 (high byte) */ 
TA4H                      DEFINE 0x38F 
/* Timer B0 */ 
TB0                       DEFINE 0x390 
/* Timer B0 (low byte) */ 
TB0L                      DEFINE 0x390 
/* Timer B0 (high byte) */ 
TB0H                      DEFINE 0x391 
/* Timer B1 */ 
TB1                       DEFINE 0x392 
/* Timer B1 (low byte) */ 
TB1L                      DEFINE 0x392 
/* Timer B1 (high byte) */ 
TB1H                      DEFINE 0x393 
/* Timer B2 */ 
TB2                       DEFINE 0x394 
/* Timer B2 (low byte) */ 
TB2L                      DEFINE 0x394 
/* Timer B2 (high byte) */ 
TB2H                      DEFINE 0x395 
/* Timer A0 mode register */ 
TA0MR                     DEFINE 0x396
TA0MR_TMOD0               DEFINE 0   
TA0MR_TMOD1               DEFINE 1   
TA0MR_MR0                 DEFINE 2   
TA0MR_MR1                 DEFINE 3   
TA0MR_MR2                 DEFINE 4   
TA0MR_MR3                 DEFINE 5   
TA0MR_TCK0                DEFINE 6   
TA0MR_TCK1                DEFINE 7    
/* Timer A1 mode register */ 
TA1MR                     DEFINE 0x397
TA1MR_TMOD0               DEFINE 0   
TA1MR_TMOD1               DEFINE 1   
TA1MR_MR0                 DEFINE 2   
TA1MR_MR1                 DEFINE 3   
TA1MR_MR2                 DEFINE 4   
TA1MR_MR3                 DEFINE 5   
TA1MR_TCK0                DEFINE 6   
TA1MR_TCK1                DEFINE 7    
/* Timer A2 mode register */ 
TA2MR                     DEFINE 0x398
TA2MR_TMOD0               DEFINE 0   
TA2MR_TMOD1               DEFINE 1   
TA2MR_MR0                 DEFINE 2   
TA2MR_MR1                 DEFINE 3   
TA2MR_MR2                 DEFINE 4   
TA2MR_MR3                 DEFINE 5   
TA2MR_TCK0                DEFINE 6   
TA2MR_TCK1                DEFINE 7    
/* Timer A3 mode register */ 
TA3MR                     DEFINE 0x399
TA3MR_TMOD0               DEFINE 0   
TA3MR_TMOD1               DEFINE 1   
TA3MR_MR0                 DEFINE 2   
TA3MR_MR1                 DEFINE 3   
TA3MR_MR2                 DEFINE 4   
TA3MR_MR3                 DEFINE 5   
TA3MR_TCK0                DEFINE 6   
TA3MR_TCK1                DEFINE 7    
/* Timer A4 mode register */ 
TA4MR                     DEFINE 0x39A
TA4MR_TMOD0               DEFINE 0   
TA4MR_TMOD1               DEFINE 1   
TA4MR_MR0                 DEFINE 2   
TA4MR_MR1                 DEFINE 3   
TA4MR_MR2                 DEFINE 4   
TA4MR_MR3                 DEFINE 5   
TA4MR_TCK0                DEFINE 6   
TA4MR_TCK1                DEFINE 7    
/* Timer B0 mode register */ 
TB0MR                     DEFINE 0x39B
TB0MR_TMOD0               DEFINE 0   
TB0MR_TMOD1               DEFINE 1   
TB0MR_MR0                 DEFINE 2   
TB0MR_MR1                 DEFINE 3   
TB0MR_MR2                 DEFINE 4   
TB0MR_MR3                 DEFINE 5   
TB0MR_TCK0                DEFINE 6   
TB0MR_TCK1                DEFINE 7    
/* Timer B1 mode register */ 
TB1MR                     DEFINE 0x39C
TB1MR_TMOD0               DEFINE 0   
TB1MR_TMOD1               DEFINE 1   
TB1MR_MR0                 DEFINE 2   
TB1MR_MR1                 DEFINE 3    
TB1MR_MR3                 DEFINE 5   
TB1MR_TCK0                DEFINE 6   
TB1MR_TCK1                DEFINE 7    
/* Timer B2 mode register */ 
TB2MR                     DEFINE 0x39D
TB2MR_TMOD0               DEFINE 0   
TB2MR_TMOD1               DEFINE 1   
TB2MR_MR0                 DEFINE 2   
TB2MR_MR1                 DEFINE 3    
TB2MR_MR3                 DEFINE 5   
TB2MR_TCK0                DEFINE 6   
TB2MR_TCK1                DEFINE 7    
/* Timer B2 special mode register */ 
TB2SC                     DEFINE 0x39E
TB2SC_PWCON               DEFINE 0   
TB2SC_IVPCR1              DEFINE 1    
/* Timer B3,4,5 count start flag */ 
TBSR                      DEFINE 0x340 
TBSR_TB3S                 DEFINE 5   
TBSR_TB4S                 DEFINE 6   
TBSR_TB5S                 DEFINE 7    
/* Timer B3 */ 
TB3                       DEFINE 0x350 
/* Timer B3 (low byte) */ 
TB3L                      DEFINE 0x350 
/* Timer B3 (high byte) */ 
TB3H                      DEFINE 0x351 
/* Timer B4 */ 
TB4                       DEFINE 0x352 
/* Timer B4 (low byte) */ 
TB4L                      DEFINE 0x352 
/* Timer B4 (high byte) */ 
TB4H                      DEFINE 0x353 
/* Timer B5 */ 
TB5                       DEFINE 0x354 
/* Timer B5 (low byte) */ 
TB5L                      DEFINE 0x354 
/* Timer B5 (high byte) */ 
TB5H                      DEFINE 0x355 
/* Timer B3 mode register */ 
TB3MR                     DEFINE 0x35B
TB3MR_TMOD0               DEFINE 0   
TB3MR_TMOD1               DEFINE 1   
TB3MR_MR0                 DEFINE 2   
TB3MR_MR1                 DEFINE 3   
TB3MR_MR2                 DEFINE 4   
TB3MR_MR3                 DEFINE 5   
TB3MR_TCK0                DEFINE 6   
TB3MR_TCK1                DEFINE 7    
/* Timer B4 mode register */ 
TB4MR                     DEFINE 0x35C
TB4MR_TMOD0               DEFINE 0   
TB4MR_TMOD1               DEFINE 1   
TB4MR_MR0                 DEFINE 2   
TB4MR_MR1                 DEFINE 3    
TB4MR_MR3                 DEFINE 5   
TB4MR_TCK0                DEFINE 6   
TB4MR_TCK1                DEFINE 7    
/* Timer B5 mode register */ 
TB5MR                     DEFINE 0x35D
TB5MR_TMOD0               DEFINE 0   
TB5MR_TMOD1               DEFINE 1   
TB5MR_MR0                 DEFINE 2   
TB5MR_MR1                 DEFINE 3    
TB5MR_MR3                 DEFINE 5   
TB5MR_TCK0                DEFINE 6   
TB5MR_TCK1                DEFINE 7    
/* Timer A1-1 register */ 
TA11                      DEFINE 0x342 
/* Timer A1-1 register (low byte) */ 
TA11L                     DEFINE 0x342 
/* Timer A1-1 register (high byte) */ 
TA11H                     DEFINE 0x343 
/* Timer A2-1 register */ 
TA21                      DEFINE 0x344 
/* Timer A2-1 register (low byte) */ 
TA21L                     DEFINE 0x344 
/* Timer A2-1 register (high byte) */ 
TA21H                     DEFINE 0x345 
/* Timer A4-1 register */ 
TA41                      DEFINE 0x346 
/* Timer A4-1 register (low byte) */ 
TA41L                     DEFINE 0x346 
/* Timer A4-1 register (high byte) */ 
TA41H                     DEFINE 0x347 
/* Three-phase PWM control register 0 */ 
INVC0                     DEFINE 0x348
INVC0_INV00               DEFINE 0   
INVC0_INV01               DEFINE 1   
INVC0_INV02               DEFINE 2   
INVC0_INV03               DEFINE 3   
INVC0_INV04               DEFINE 4   
INVC0_INV05               DEFINE 5   
INVC0_INV06               DEFINE 6   
INVC0_INV07               DEFINE 7    
/* Three-phase PWM control register 1 */ 
INVC1                     DEFINE 0x349
INVC1_INV10               DEFINE 0   
INVC1_INV11               DEFINE 1   
INVC1_INV12               DEFINE 2   
INVC1_INV13               DEFINE 3   
INVC1_INV14               DEFINE 4   
INVC1_INV15               DEFINE 5   
INVC1_INV16               DEFINE 6     
/* Three-phase output buffer register 0 */ 
IDB0                      DEFINE 0x34A
IDB0_DU0                  DEFINE 0   
IDB0_DUB0                 DEFINE 1   
IDB0_DV0                  DEFINE 2   
IDB0_DVB0                 DEFINE 3   
IDB0_DW0                  DEFINE 4   
IDB0_DWB0                 DEFINE 5     
/* Three-phase output buffer register 1 */ 
IDB1                      DEFINE 0x34B
IDB1_DU1                  DEFINE 0   
IDB1_DUB1                 DEFINE 1   
IDB1_DV1                  DEFINE 2   
IDB1_DVB1                 DEFINE 3   
IDB1_DW1                  DEFINE 4   
IDB1_DWB1                 DEFINE 5     
/* Dead time timer */ 
DTT                       DEFINE 0x34C 
/* Timer B2 interrupt occurence frequency set coutnter */ 
ICTB2                     DEFINE 0x34D 

/*-------------------------------------------------------------------------
 *   UART Registers
 *-------------------------------------------------------------------------*/
 
/* UART 0 transmit/receive mode register */ 
U0MR                      DEFINE 0x3A0
U0MR_SMD0                 DEFINE 0   
U0MR_SMD1                 DEFINE 1   
U0MR_SMD2                 DEFINE 2   
U0MR_CKDIR                DEFINE 3   
U0MR_STPS                 DEFINE 4   
U0MR_PRY                  DEFINE 5   
U0MR_PRYE                 DEFINE 6   
U0MR_IOPOL                DEFINE 7    
/* UART 0 baud rate generator */ 
U0BRG                     DEFINE 0x3A1 
/* UART 0 transmit buffer */ 
U0TB                      DEFINE 0x3A2 
/* UART 0 transmit buffer (low byte) */ 
U0TBL                     DEFINE 0x3A2 
/* UART 0 transmit buffer (high byte) */ 
U0TBH                     DEFINE 0x3A3 
/* UART 0 transmit/receive control register */ 
U0C                       DEFINE 0x3A4 
/* UART 0 transmit/receive control register 0 */ 
U0C0                      DEFINE 0x3A4
U0C0_CLK0                 DEFINE 0   
U0C0_CLK1                 DEFINE 1   
U0C0_CRS                  DEFINE 2   
U0C0_TXEPT                DEFINE 3   
U0C0_CRD                  DEFINE 4   
U0C0_NCH                  DEFINE 5   
U0C0_CKPOL                DEFINE 6   
U0C0_UFORM                DEFINE 7    
/* UART 0 transmit/receive control register 1 */ 
U0C1                      DEFINE 0x3A5
U0C1_TE                   DEFINE 0   
U0C1_TI                   DEFINE 1   
U0C1_RE                   DEFINE 2   
U0C1_RI                   DEFINE 3     
U0C1_U0LCH                DEFINE 6   
U0C1_U0ERE                DEFINE 7    
/* UART 0 receive buffer */ 
U0RB                      DEFINE 0x3A6 
/* UART 0 receive buffer (low byte) */ 
U0RBL                     DEFINE 0x3A6 
/* UART 0 receive buffer (high byte) */ 
U0RBH                     DEFINE 0x3A7 
U0RBH_ABT                 DEFINE 3   
U0RBH_OER                 DEFINE 4   
U0RBH_FER                 DEFINE 5   
U0RBH_PER                 DEFINE 6   
U0RBH_SUM                 DEFINE 7    
/* UART 1 transmit/receive mode register */ 
U1MR                      DEFINE 0x3A8
U1MR_SMD0                 DEFINE 0   
U1MR_SMD1                 DEFINE 1   
U1MR_SMD2                 DEFINE 2   
U1MR_CKDIR                DEFINE 3   
U1MR_STPS                 DEFINE 4   
U1MR_PRY                  DEFINE 5   
U1MR_PRYE                 DEFINE 6   
U1MR_IOPOL                DEFINE 7    
/* UART 1 baud rate generator */ 
U1BRG                     DEFINE 0x3A9 
/* UART 1 transmit buffer */ 
U1TB                      DEFINE 0x3AA 
/* UART 1 transmit buffer (low byte) */ 
U1TBL                     DEFINE 0x3AA 
/* UART 1 tfransmit buffer (high byte) */ 
U1TBH                     DEFINE 0x3AB 
/* UART 1 transmit/receive control register */ 
U1C                       DEFINE 0x3AC 
/* UART 1 transmit/receive control register 0 */ 
U1C0                      DEFINE 0x3AC
U1C0_CLK0                 DEFINE 0   
U1C0_CLK1                 DEFINE 1   
U1C0_CRS                  DEFINE 2   
U1C0_TXEPT                DEFINE 3   
U1C0_CRD                  DEFINE 4   
U1C0_NCH                  DEFINE 5   
U1C0_CKPOL                DEFINE 6   
U1C0_UFORM                DEFINE 7    
/* UART 1 transmit/receive control register 1 */ 
U1C1                      DEFINE 0x3AD
U1C1_TE                   DEFINE 0   
U1C1_TI                   DEFINE 1   
U1C1_RE                   DEFINE 2   
U1C1_RI                   DEFINE 3     
U1C1_U1LCH                DEFINE 6   
U1C1_U1ERE                DEFINE 7    
/* UART 1 receive buffer */ 
U1RB                      DEFINE 0x3AE 
/* UART 1 receive buffer (low byte) */ 
U1RBL                     DEFINE 0x3AE 
/* UART 1 receive buffer (high byte) */ 
U1RBH                     DEFINE 0x3AF 
U1RBH_ABT                 DEFINE 3   
U1RBH_OER                 DEFINE 4   
U1RBH_FER                 DEFINE 5   
U1RBH_PER                 DEFINE 6   
U1RBH_SUM                 DEFINE 7    
/* UART transmit/receive control register 2 */ 
UCON                      DEFINE 0x3B0
UCON_U0IRS                DEFINE 0   
UCON_U1IRS                DEFINE 1   
UCON_U0RRM                DEFINE 2   
UCON_U1RRM                DEFINE 3   
UCON_CLKMD0               DEFINE 4   
UCON_CLKMD1               DEFINE 5   
UCON_RCSP                 DEFINE 6    
/* SI/O3 transmit/receive register */ 
S3TRR                     DEFINE 0x360 
/* SI/O3 control register */ 
S3C                       DEFINE 0x362
S3C_SM30                  DEFINE 0   
S3C_SM31                  DEFINE 1   
S3C_SM32                  DEFINE 2   
S3C_SM33                  DEFINE 3   
S3C_SM34                  DEFINE 4   
S3C_SM35                  DEFINE 5   
S3C_SM36                  DEFINE 6   
S3C_SM37                  DEFINE 7    
/* SI/O3 bit rate generator */ 
S3BRG                     DEFINE 0x363 
/* SI/O4 transmit/reveive register */ 
S4TRR                     DEFINE 0x364 
/* SI/O4 control register */ 
S4C                       DEFINE 0x366
S4C_SM40                  DEFINE 0   
S4C_SM41                  DEFINE 1   
S4C_SM42                  DEFINE 2   
S4C_SM43                  DEFINE 3   
S4C_SM44                  DEFINE 4   
S4C_SM45                  DEFINE 5   
S4C_SM46                  DEFINE 6   
S4C_SM47                  DEFINE 7    
/* SI/O4 bit rate generator */ 
S4BRG                     DEFINE 0x367 
/* UART 0 special mode register 4 */ 
U0SMR4                    DEFINE 0x36C
U0SMR4_STAREQ             DEFINE 0   
U0SMR4_RSTAREQ            DEFINE 1   
U0SMR4_STPREQ             DEFINE 2   
U0SMR4_STSPSEL            DEFINE 3   
U0SMR4_ACKD               DEFINE 4   
U0SMR4_ACKC               DEFINE 5   
U0SMR4_SCLHI              DEFINE 6   
U0SMR4_SWC9               DEFINE 7    
/* UART 0 special mode register 3 */ 
U0SMR3                    DEFINE 0x36D 
U0SMR3_CKPH               DEFINE 1    
U0SMR3_NODC               DEFINE 3    
U0SMR3_DL0                DEFINE 5   
U0SMR3_DL1                DEFINE 6   
U0SMR3_DL2                DEFINE 7    
/* UART 0 special mode register 2 */ 
U0SMR2                    DEFINE 0x36E
U0SMR2_IICM2              DEFINE 0   
U0SMR2_CSC                DEFINE 1   
U0SMR2_SWC                DEFINE 2   
U0SMR2_ALS                DEFINE 3   
U0SMR2_STAC               DEFINE 4   
U0SMR2_SWC2               DEFINE 5   
U0SMR2_SDHI               DEFINE 6    
/* UART 0 special mode register */ 
U0SMR                     DEFINE 0x36F
U0SMR_IICM                DEFINE 0   
U0SMR_ABC                 DEFINE 1   
U0SMR_BBS                 DEFINE 2   
U0SMR_LSYN                DEFINE 3   
U0SMR_ABSCS               DEFINE 4   
U0SMR_ACSE                DEFINE 5   
U0SMR_SSS                 DEFINE 6    
/* UART 1 special mode register 4 */ 
U1SMR4                    DEFINE 0x370
U1SMR4_STAREQ             DEFINE 0   
U1SMR4_RSTAREQ            DEFINE 1   
U1SMR4_STPREQ             DEFINE 2   
U1SMR4_STSPSEL            DEFINE 3   
U1SMR4_ACKD               DEFINE 4   
U1SMR4_ACKC               DEFINE 5   
U1SMR4_SCLHI              DEFINE 6   
U1SMR4_SWC9               DEFINE 7    
/* UART 1 special mode register 3 */ 
U1SMR3                    DEFINE 0x371 
U1SMR3_CKPH               DEFINE 1    
U1SMR3_NODC               DEFINE 3    
U1SMR3_DL0                DEFINE 5   
U1SMR3_DL1                DEFINE 6   
U1SMR3_DL2                DEFINE 7    
/* UART 1 special mode register 2 */ 
U1SMR2                    DEFINE 0x372
U1SMR2_IICM2              DEFINE 0   
U1SMR2_CSC                DEFINE 1   
U1SMR2_SWC                DEFINE 2   
U1SMR2_ALS                DEFINE 3   
U1SMR2_STAC               DEFINE 4   
U1SMR2_SWC2               DEFINE 5   
U1SMR2_SDHI               DEFINE 6    
/* UART 1 special mode register */ 
U1SMR                     DEFINE 0x373
U1SMR_IICM                DEFINE 0   
U1SMR_ABC                 DEFINE 1   
U1SMR_BBS                 DEFINE 2   
U1SMR_LSYN                DEFINE 3   
U1SMR_ABSCS               DEFINE 4   
U1SMR_ACSE                DEFINE 5   
U1SMR_SSS                 DEFINE 6    
/* UART 2 special mode register 4 */ 
U2SMR4                    DEFINE 0x374
U2SMR4_STAREQ             DEFINE 0   
U2SMR4_RSTAREQ            DEFINE 1   
U2SMR4_STPREQ             DEFINE 2   
U2SMR4_STSPSEL            DEFINE 3   
U2SMR4_ACKD               DEFINE 4   
U2SMR4_ACKC               DEFINE 5   
U2SMR4_SCLHI              DEFINE 6   
U2SMR4_SWC9               DEFINE 7    
/* UART 2 special mode register 3 */ 
U2SMR3                    DEFINE 0x375 
U2SMR3_CKPH               DEFINE 1    
U2SMR3_NODC               DEFINE 3    
U2SMR3_DL0                DEFINE 5   
U2SMR3_DL1                DEFINE 6   
U2SMR3_DL2                DEFINE 7    
/* UART 2 special mode register 2 */ 
U2SMR2                    DEFINE 0x376
U2SMR2_IICM2              DEFINE 0   
U2SMR2_CSC                DEFINE 1   
U2SMR2_SWC                DEFINE 2   
U2SMR2_ALS                DEFINE 3   
U2SMR2_STAC               DEFINE 4   
U2SMR2_SWC2               DEFINE 5   
U2SMR2_SDHI               DEFINE 6    
/* UART 2 special mode register */ 
U2SMR                     DEFINE 0x377
U2SMR_IICM                DEFINE 0   
U2SMR_ABC                 DEFINE 1   
U2SMR_BBS                 DEFINE 2   
U2SMR_LSYN                DEFINE 3   
U2SMR_ABSCS               DEFINE 4   
U2SMR_ACSE                DEFINE 5   
U2SMR_SSS                 DEFINE 6    
/* UART 2 transmit/receive mode register */ 
U2MR                      DEFINE 0x378
U2MR_SMD0                 DEFINE 0   
U2MR_SMD1                 DEFINE 1   
U2MR_SMD2                 DEFINE 2   
U2MR_CKDIR                DEFINE 3   
U2MR_STPS                 DEFINE 4   
U2MR_PRY                  DEFINE 5   
U2MR_PRYE                 DEFINE 6   
U2MR_IOPOL                DEFINE 7    
/* UART 2 bit rate generator */ 
U2BRG                     DEFINE 0x379 
/* UART 2 transmit buffer register */ 
U2TB                      DEFINE 0x37A 
/* UART 2 transmit buffer register (low byte) */ 
U2TBL                     DEFINE 0x37A 
/* UART 2 transmit buffer register (high byte) */ 
U2TBH                     DEFINE 0x37B 
/* UART 2 transmit/receive control register 0 */ 
U2C0                      DEFINE 0x37C
U2C0_CLK0                 DEFINE 0   
U2C0_CLK1                 DEFINE 1   
U2C0_CRS                  DEFINE 2   
U2C0_TXEPT                DEFINE 3   
U2C0_CRD                  DEFINE 4   
U2C0_NCH                  DEFINE 5   
U2C0_CKPOL                DEFINE 6   
U2C0_UFORM                DEFINE 7    
/* UART 2 transmit/receive control register 1 */ 
U2C1                      DEFINE 0x37D
U2C1_TE                   DEFINE 0   
U2C1_TI                   DEFINE 1   
U2C1_RE                   DEFINE 2   
U2C1_RI                   DEFINE 3   
U2C1_U2IRS                DEFINE 4   
U2C1_U2RRM                DEFINE 5   
U2C1_U2LCH                DEFINE 6   
U2C1_U2ERE                DEFINE 7    
/* UART 2 receive buffer register */ 
U2RB                      DEFINE 0x37E 
/* UART 2 receive buffer register (low byte) */ 
U2RBL                     DEFINE 0x37E 
/* UART 2 receive buffer register (high byte) */ 
U2RBH                     DEFINE 0x37F 
U2RBH_ABT                 DEFINE 3   
U2RBH_OER                 DEFINE 4   
U2RBH_FER                 DEFINE 5   
U2RBH_PER                 DEFINE 6   
U2RBH_SUM                 DEFINE 7    

/*-------------------------------------------------------------------------
 *   Flash control register
 *-------------------------------------------------------------------------*/
 
/* Flash identification register */ 
FIDR                      DEFINE 0x1B4 
/* Flash memory control register 1 */ 
FMR1                      DEFINE 0x1B5 
FMR1_FMR11                DEFINE 1    
FMR1_FMR16                DEFINE 6    
/* Flash memory control register 0 */ 
FMR0                      DEFINE 0x1B7
FMR0_FMR00                DEFINE 0   
FMR0_FMR01                DEFINE 1   
FMR0_FMR02                DEFINE 2   
FMR0_FMSTP                DEFINE 3    
FMR0_FMR05                DEFINE 5   
FMR0_FMR06                DEFINE 6   
FMR0_FMR07                DEFINE 7    

/*-------------------------------------------------------------------------
 *   CRC register
 *-------------------------------------------------------------------------*/
 
/* CRC data register */ 
CRCD                      DEFINE 0x3BC 
/* CRC data register (low byte) */ 
CRCDL                     DEFINE 0x3BC 
/* CRC data register (high byte) */ 
CRCDH                     DEFINE 0x3BD 
/* CRC input register */ 
CRCIN                     DEFINE 0x3BE 

/*-------------------------------------------------------------------------
 *   A/D Converter
 *-------------------------------------------------------------------------*/
 
/* A/D register 0 */ 
AD0                       DEFINE 0x3C0 
/* A/D register 0 (low byte) */ 
AD0L                      DEFINE 0x3C0 
/* A/D register 0 (high byte) */ 
AD0H                      DEFINE 0x3C1 
/* A/D register 1 */ 
AD1                       DEFINE 0x3C2 
/* A/D register 1 (low byte) */ 
AD1L                      DEFINE 0x3C2 
/* A/D register 1 (high byte) */ 
AD1H                      DEFINE 0x3C3 
/* A/D register 2 */ 
AD2                       DEFINE 0x3C4 
/* A/D register 2 (low byte) */ 
AD2L                      DEFINE 0x3C4 
/* A/D register 2 (high byte) */ 
AD2H                      DEFINE 0x3C5 
/* A/D register 3 */ 
AD3                       DEFINE 0x3C6 
/* A/D register 3 (low byte) */ 
AD3L                      DEFINE 0x3C6 
/* A/D register 3 (high byte) */ 
AD3H                      DEFINE 0x3C7 
/* A/D register 4 */ 
AD4                       DEFINE 0x3C8 
/* A/D register 4 (low byte) */ 
AD4L                      DEFINE 0x3C8 
/* A/D register 4 (high byte) */ 
AD4H                      DEFINE 0x3C9 
/* A/D register 5 */ 
AD5                       DEFINE 0x3CA 
/* A/D register 5 (low byte) */ 
AD5L                      DEFINE 0x3CA 
/* A/D register 5 (high byte) */ 
AD5H                      DEFINE 0x3CB 
/* A/D register 6 */ 
AD6                       DEFINE 0x3CC 
/* A/D register 6 (low byte) */ 
AD6L                      DEFINE 0x3CC 
/* A/D register 6 (high byte) */ 
AD6H                      DEFINE 0x3CD 
/* A/D register 7 */ 
AD7                       DEFINE 0x3CE 
/* A/D register 7 (low byte) */ 
AD7L                      DEFINE 0x3CE 
/* A/D register 7 (high byte) */ 
AD7H                      DEFINE 0x3CF 
/* A/D control register 2 */ 
ADCON2                    DEFINE 0x3D4
ADCON2_SMP                DEFINE 0   
ADCON2_ADGSEL0            DEFINE 1   
ADCON2_ADGSEL1            DEFINE 2    
ADCON2_CKS2               DEFINE 4    
/* A/D control register 0 */ 
ADCON0                    DEFINE 0x3D6
ADCON0_CH0                DEFINE 0   
ADCON0_CH1                DEFINE 1   
ADCON0_CH2                DEFINE 2   
ADCON0_MD0                DEFINE 3   
ADCON0_MD1                DEFINE 4   
ADCON0_TRG                DEFINE 5   
ADCON0_ADST               DEFINE 6   
ADCON0_CKS0               DEFINE 7    
/* A/D control register 1 */ 
ADCON1                    DEFINE 0x3D7
ADCON1_SCAN0              DEFINE 0   
ADCON1_SCAN1              DEFINE 1   
ADCON1_MD2                DEFINE 2   
ADCON1_BITS               DEFINE 3   
ADCON1_CKS1               DEFINE 4   
ADCON1_VCUT               DEFINE 5   
ADCON1_OPA0               DEFINE 6   
ADCON1_OPA1               DEFINE 7    

/*-------------------------------------------------------------------------
 *   D-A Converter
 *-------------------------------------------------------------------------*/
 
/* D-A register 0 */ 
DA0                       DEFINE 0x3D8 
/* D-A register 1 */ 
DA1                       DEFINE 0x3DA 
/* D-A control register */ 
DACON                     DEFINE 0x3DC
DACON_DA0E                DEFINE 0   
DACON_DA1E                DEFINE 1    

/*-------------------------------------------------------------------------
 *   Power supply
 *-------------------------------------------------------------------------*/
 
/* Power supply detection register 1 */ 
VCR1                      DEFINE 0x019   
VCR1_VC13                 DEFINE 3    
/* Power supply detection register 2 */ 
VCR2                      DEFINE 0x01A     
VCR2_VC25                 DEFINE 5   
VCR2_VC26                 DEFINE 6   
VCR2_VC27                 DEFINE 7    
/* Power supply down detection register */ 
D4INT                     DEFINE 0x01F
D4INT_D40                 DEFINE 0   
D4INT_D41                 DEFINE 1   
D4INT_D42                 DEFINE 2   
D4INT_D43                 DEFINE 3   
D4INT_DF0                 DEFINE 4   
D4INT_DF1                 DEFINE 5    

/*-------------------------------------------------------------------------
 *   Port Registers
 *-------------------------------------------------------------------------*/
 
/* Port P14 register */ 
PC14                      DEFINE 0x3DE
PC14_P140                 DEFINE 0   
PC14_P141                 DEFINE 1     
PC14_PD140                DEFINE 4   
PC14_PD141                DEFINE 5    
/* Pull-up register 3 */ 
PUR3                      DEFINE 0x3DF
PUR3_PU30                 DEFINE 0   
PUR3_PU31                 DEFINE 1   
PUR3_PU32                 DEFINE 2   
PUR3_PU33                 DEFINE 3   
PUR3_PU34                 DEFINE 4   
PUR3_PU35                 DEFINE 5   
PUR3_PU36                 DEFINE 6   
PUR3_PU37                 DEFINE 7    
/* Port P0 register */ 
P0                        DEFINE 0x3E0
P0_P0_0                   DEFINE 0   
P0_P0_1                   DEFINE 1   
P0_P0_2                   DEFINE 2   
P0_P0_3                   DEFINE 3   
P0_P0_4                   DEFINE 4   
P0_P0_5                   DEFINE 5   
P0_P0_6                   DEFINE 6   
P0_P0_7                   DEFINE 7    
/* Port P1 register */ 
P1                        DEFINE 0x3E1
P1_P1_0                   DEFINE 0   
P1_P1_1                   DEFINE 1   
P1_P1_2                   DEFINE 2   
P1_P1_3                   DEFINE 3   
P1_P1_4                   DEFINE 4   
P1_P1_5                   DEFINE 5   
P1_P1_6                   DEFINE 6   
P1_P1_7                   DEFINE 7    
/* Port P0 and P1 register */ 
P01                       DEFINE 0x3E0 
/* Port P0 direction register */ 
PD0                       DEFINE 0x3E2
PD0_PD0_0                 DEFINE 0   
PD0_PD0_1                 DEFINE 1   
PD0_PD0_2                 DEFINE 2   
PD0_PD0_3                 DEFINE 3   
PD0_PD0_4                 DEFINE 4   
PD0_PD0_5                 DEFINE 5   
PD0_PD0_6                 DEFINE 6   
PD0_PD0_7                 DEFINE 7    
/* Port P1 direction register */ 
PD1                       DEFINE 0x3E3
PD1_PD1_0                 DEFINE 0   
PD1_PD1_1                 DEFINE 1   
PD1_PD1_2                 DEFINE 2   
PD1_PD1_3                 DEFINE 3   
PD1_PD1_4                 DEFINE 4   
PD1_PD1_5                 DEFINE 5   
PD1_PD1_6                 DEFINE 6   
PD1_PD1_7                 DEFINE 7    
/* Port P0 and P1 direction register */ 
PD01                      DEFINE 0x3E2 
/* Port P2 register */ 
P2                        DEFINE 0x3E4
P2_P2_0                   DEFINE 0   
P2_P2_1                   DEFINE 1   
P2_P2_2                   DEFINE 2   
P2_P2_3                   DEFINE 3   
P2_P2_4                   DEFINE 4   
P2_P2_5                   DEFINE 5   
P2_P2_6                   DEFINE 6   
P2_P2_7                   DEFINE 7    
/* Port P3 register */ 
P3                        DEFINE 0x3E5
P3_P3_0                   DEFINE 0   
P3_P3_1                   DEFINE 1   
P3_P3_2                   DEFINE 2   
P3_P3_3                   DEFINE 3   
P3_P3_4                   DEFINE 4   
P3_P3_5                   DEFINE 5   
P3_P3_6                   DEFINE 6   
P3_P3_7                   DEFINE 7    
/* Port P2 and P3 register */ 
P23                       DEFINE 0x3E4 
/* Port P2 direction register */ 
PD2                       DEFINE 0x3E6
PD2_PD2_0                 DEFINE 0   
PD2_PD2_1                 DEFINE 1   
PD2_PD2_2                 DEFINE 2   
PD2_PD2_3                 DEFINE 3   
PD2_PD2_4                 DEFINE 4   
PD2_PD2_5                 DEFINE 5   
PD2_PD2_6                 DEFINE 6   
PD2_PD2_7                 DEFINE 7    
/* Port P3 direction register */ 
PD3                       DEFINE 0x3E7
PD3_PD3_0                 DEFINE 0   
PD3_PD3_1                 DEFINE 1   
PD3_PD3_2                 DEFINE 2   
PD3_PD3_3                 DEFINE 3   
PD3_PD3_4                 DEFINE 4   
PD3_PD3_5                 DEFINE 5   
PD3_PD3_6                 DEFINE 6   
PD3_PD3_7                 DEFINE 7    
/* Port P2 and P3 direction register */ 
PD23                      DEFINE 0x3E6 
/* Port P4 register */ 
P4                        DEFINE 0x3E8
P4_P4_0                   DEFINE 0   
P4_P4_1                   DEFINE 1   
P4_P4_2                   DEFINE 2   
P4_P4_3                   DEFINE 3   
P4_P4_4                   DEFINE 4   
P4_P4_5                   DEFINE 5   
P4_P4_6                   DEFINE 6   
P4_P4_7                   DEFINE 7    
/* Port P5 register */ 
P5                        DEFINE 0x3E9
P5_P5_0                   DEFINE 0   
P5_P5_1                   DEFINE 1   
P5_P5_2                   DEFINE 2   
P5_P5_3                   DEFINE 3   
P5_P5_4                   DEFINE 4   
P5_P5_5                   DEFINE 5   
P5_P5_6                   DEFINE 6   
P5_P5_7                   DEFINE 7    
/* Port P4 and P5 register */ 
P45                       DEFINE 0x3E8 
/* Port P4 direction register */ 
PD4                       DEFINE 0x3EA
PD4_PD4_0                 DEFINE 0   
PD4_PD4_1                 DEFINE 1   
PD4_PD4_2                 DEFINE 2   
PD4_PD4_3                 DEFINE 3   
PD4_PD4_4                 DEFINE 4   
PD4_PD4_5                 DEFINE 5   
PD4_PD4_6                 DEFINE 6   
PD4_PD4_7                 DEFINE 7    
/* Port P5 direction register */ 
PD5                       DEFINE 0x3EB
PD5_PD5_0                 DEFINE 0   
PD5_PD5_1                 DEFINE 1   
PD5_PD5_2                 DEFINE 2   
PD5_PD5_3                 DEFINE 3   
PD5_PD5_4                 DEFINE 4   
PD5_PD5_5                 DEFINE 5   
PD5_PD5_6                 DEFINE 6   
PD5_PD5_7                 DEFINE 7    
/* Port P4 and P5 direction register */ 
PD45                      DEFINE 0x3EA 
/* Port P6 register */ 
P6                        DEFINE 0x3EC
P6_P6_0                   DEFINE 0   
P6_P6_1                   DEFINE 1   
P6_P6_2                   DEFINE 2   
P6_P6_3                   DEFINE 3   
P6_P6_4                   DEFINE 4   
P6_P6_5                   DEFINE 5   
P6_P6_6                   DEFINE 6   
P6_P6_7                   DEFINE 7    
/* Port P7 register */ 
P7                        DEFINE 0x3ED
P7_P7_0                   DEFINE 0   
P7_P7_1                   DEFINE 1   
P7_P7_2                   DEFINE 2   
P7_P7_3                   DEFINE 3   
P7_P7_4                   DEFINE 4   
P7_P7_5                   DEFINE 5   
P7_P7_6                   DEFINE 6   
P7_P7_7                   DEFINE 7    
/* Port P6 and P7 register */ 
P67                       DEFINE 0x3EC 
/* Port P6 direction register */ 
PD6                       DEFINE 0x3EE
PD6_PD6_0                 DEFINE 0   
PD6_PD6_1                 DEFINE 1   
PD6_PD6_2                 DEFINE 2   
PD6_PD6_3                 DEFINE 3   
PD6_PD6_4                 DEFINE 4   
PD6_PD6_5                 DEFINE 5   
PD6_PD6_6                 DEFINE 6   
PD6_PD6_7                 DEFINE 7    
/* Port P7 direction register */ 
PD7                       DEFINE 0x3EF
PD7_PD7_0                 DEFINE 0   
PD7_PD7_1                 DEFINE 1   
PD7_PD7_2                 DEFINE 2   
PD7_PD7_3                 DEFINE 3   
PD7_PD7_4                 DEFINE 4   
PD7_PD7_5                 DEFINE 5   
PD7_PD7_6                 DEFINE 6   
PD7_PD7_7                 DEFINE 7    
/* Port P6 and P7 direction register */ 
PD67                      DEFINE 0x3EE 
/* Port P8 register */ 
P8                        DEFINE 0x3F0
P8_P8_0                   DEFINE 0   
P8_P8_1                   DEFINE 1   
P8_P8_2                   DEFINE 2   
P8_P8_3                   DEFINE 3   
P8_P8_4                   DEFINE 4   
P8_P8_5                   DEFINE 5   
P8_P8_6                   DEFINE 6   
P8_P8_7                   DEFINE 7    
/* Port P9 register */ 
P9                        DEFINE 0x3F1
P9_P9_0                   DEFINE 0   
P9_P9_1                   DEFINE 1   
P9_P9_2                   DEFINE 2   
P9_P9_3                   DEFINE 3   
P9_P9_4                   DEFINE 4   
P9_P9_5                   DEFINE 5   
P9_P9_6                   DEFINE 6   
P9_P9_7                   DEFINE 7    
/* Port P8 and P9 register */ 
P89                       DEFINE 0x3F0 
/* Port P8 direction register */ 
PD8                       DEFINE 0x3F2
PD8_PD8_0                 DEFINE 0   
PD8_PD8_1                 DEFINE 1   
PD8_PD8_2                 DEFINE 2   
PD8_PD8_3                 DEFINE 3   
PD8_PD8_4                 DEFINE 4    
PD8_PD8_6                 DEFINE 6   
PD8_PD8_7                 DEFINE 7    
/* Port P9 direction register */ 
PD9                       DEFINE 0x3F3
PD9_PD9_0                 DEFINE 0   
PD9_PD9_1                 DEFINE 1   
PD9_PD9_2                 DEFINE 2   
PD9_PD9_3                 DEFINE 3   
PD9_PD9_4                 DEFINE 4   
PD9_PD9_5                 DEFINE 5   
PD9_PD9_6                 DEFINE 6   
PD9_PD9_7                 DEFINE 7    
/* Port P8 and P9 direction register */ 
PD89                      DEFINE 0x3F2 
/* Port P10 register */ 
P10                       DEFINE 0x3F4
P10_P10_0                 DEFINE 0   
P10_P10_1                 DEFINE 1   
P10_P10_2                 DEFINE 2   
P10_P10_3                 DEFINE 3   
P10_P10_4                 DEFINE 4   
P10_P10_5                 DEFINE 5   
P10_P10_6                 DEFINE 6   
P10_P10_7                 DEFINE 7    
/* Port P11 register */ 
P11                       DEFINE 0x3F5
P11_P11_0                 DEFINE 0   
P11_P11_1                 DEFINE 1   
P11_P11_2                 DEFINE 2   
P11_P11_3                 DEFINE 3   
P11_P11_4                 DEFINE 4   
P11_P11_5                 DEFINE 5   
P11_P11_6                 DEFINE 6   
P11_P11_7                 DEFINE 7    
/* Port P10 direction register */ 
PD10                      DEFINE 0x3F6
PD10_PD10_0               DEFINE 0   
PD10_PD10_1               DEFINE 1   
PD10_PD10_2               DEFINE 2   
PD10_PD10_3               DEFINE 3   
PD10_PD10_4               DEFINE 4   
PD10_PD10_5               DEFINE 5   
PD10_PD10_6               DEFINE 6   
PD10_PD10_7               DEFINE 7    
/* Port P11 direction register */ 
PD11                      DEFINE 0x3F7
PD11_PD11_0               DEFINE 0   
PD11_PD11_1               DEFINE 1   
PD11_PD11_2               DEFINE 2   
PD11_PD11_3               DEFINE 3   
PD11_PD11_4               DEFINE 4   
PD11_PD11_5               DEFINE 5   
PD11_PD11_6               DEFINE 6   
PD11_PD11_7               DEFINE 7    
/* Port P12 register */ 
P12                       DEFINE 0x3F8
P12_P12_0                 DEFINE 0   
P12_P12_1                 DEFINE 1   
P12_P12_2                 DEFINE 2   
P12_P12_3                 DEFINE 3   
P12_P12_4                 DEFINE 4   
P12_P12_5                 DEFINE 5   
P12_P12_6                 DEFINE 6   
P12_P12_7                 DEFINE 7    
/* Port P13 register */ 
P13                       DEFINE 0x3F9
P13_P13_0                 DEFINE 0   
P13_P13_1                 DEFINE 1   
P13_P13_2                 DEFINE 2   
P13_P13_3                 DEFINE 3   
P13_P13_4                 DEFINE 4   
P13_P13_5                 DEFINE 5   
P13_P13_6                 DEFINE 6   
P13_P13_7                 DEFINE 7    
/* Port P12 direction register */ 
PD12                      DEFINE 0x3FA
PD12_PD12_0               DEFINE 0   
PD12_PD12_1               DEFINE 1   
PD12_PD12_2               DEFINE 2   
PD12_PD12_3               DEFINE 3   
PD12_PD12_4               DEFINE 4   
PD12_PD12_5               DEFINE 5   
PD12_PD12_6               DEFINE 6   
PD12_PD12_7               DEFINE 7    
/* Port P13 direction register */ 
PD13                      DEFINE 0x3FB
PD13_PD13_0               DEFINE 0   
PD13_PD13_1               DEFINE 1   
PD13_PD13_2               DEFINE 2   
PD13_PD13_3               DEFINE 3   
PD13_PD13_4               DEFINE 4   
PD13_PD13_5               DEFINE 5   
PD13_PD13_6               DEFINE 6   
PD13_PD13_7               DEFINE 7    
/* Port P12 and P13 direction register */ 
PD1213                    DEFINE 0x3FA 
/* Pull-up register 0 */ 
PUR0                      DEFINE 0x3FC
PUR0_PU00                 DEFINE 0    
/* Pull-up register 1 */ 
PUR1                      DEFINE 0x3FD 
/* Pull-up register 0 and 1 */ 
PUR01                     DEFINE 0x3FC 
/* Pull-up register 2 */ 
PUR2                      DEFINE 0x3FE 
/* Port control register */ 
PCR                       DEFINE 0x3FF 


#endif /* __IAR_SYSTEMS_ASM__*/

/*
        Interrupt Vectors
        For Trap vectors, see intrinsics.h
*/
#define INT3                 0x04  /* External source */ 
#define TMRB5                0x05  /* Timer B5 */ 
#define TMRB4                0x06  /* Timer B4 */ 
#define U1BUS                0x06  /* Bus collision detection UART1 */ 
#define TMRB3                0x07  /* Timer B3 */ 
#define U0BUS                0x07  /* Bus collision detection UART0 */ 
#define SIO4                 0x08  /* Serial I/O 4 */ 
#define INT5                 0x08  /* External source */ 
#define SIO3                 0x09  /* Serial I/O 3 */ 
#define INT4                 0x09  /* External */ 
#define U2BUS                0x0A  /* Bus collision detection UART2 */ 
#define DMA0                 0x0B  /* DMA0 */ 
#define DMA1                 0x0C  /* DMA1 */ 
#define KEY                  0x0D  /* Key input */ 
#define AD                   0x0E  /* A-D converter */ 
#define UART2_TX             0x0F  /* UART2 transmit */ 
#define UART2_RX             0x10  /* UART2 receive */ 
#define UART0_TX             0x11  /* UART0 transmit */ 
#define UART0_RX             0x12  /* UART0 receive */ 
#define UART1_TX             0x13  /* UART1 transmit */ 
#define UART1_RX             0x14  /* UART1 receive */ 
#define TMRA0                0x15  /* Timer A0 */ 
#define TMRA1                0x16  /* Timer A1 */ 
#define TMRA2                0x17  /* Timer A2 */ 
#define TMRA3                0x18  /* Timer A3 */ 
#define TMRA4                0x19  /* Timer A4 */ 
#define TMRB0                0x1A  /* Timer B0 */ 
#define TMRB1                0x1B  /* Timer B1 */ 
#define TMRB2                0x1C  /* Timer B2 */ 
#define INT0                 0x1D  /* External source */ 
#define INT1                 0x1E  /* External source */ 
#define INT2                 0x1F  /* External source */ 



#endif


