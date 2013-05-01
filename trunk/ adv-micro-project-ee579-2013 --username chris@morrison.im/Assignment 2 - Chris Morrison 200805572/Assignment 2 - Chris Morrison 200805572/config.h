/* Config.h Common to BOTH Compilation & Assembly */

//#define MROM, CSPY, CDEB, SKIT, EMU, SIM, MINI
//#define M3060, M3061, M3062, M3062F
//#define LIMIT_15KB_192KB
  #define RESETVEC 0xFFFFC
//#define IGNORE_SEG_INIT
  #define HANDLE_FIXED_VECTORS_IN_C
//#define UNUSED_INT PRCR.1=1;PM.3=1; /* Release:- H/w reset */
//#define UNUSED_INT init_C();        /* Release:- S/w reset */
//#define UNUSED_INT /* */            /* Release:- Ignore    */
//#define UNUSED_INT for(;;);         /* Debug  :- Trap loop-seperatly */
  #define UNUSED_INT dummy();         /* Debug  :- Trap 1-breakpoint   */
  #include "M3062F.h"              /* Defaults (unless overriden above) */
// $TOOLKIT_DIR$\inc\, ($PROJ_DIR$\ is main.c relative rather than *.prj-file relative) and neither don't work for assembler
//#define SFRBASE 0x400
