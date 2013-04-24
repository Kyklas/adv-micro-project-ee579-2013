# optional compiler flags
CCOPTS ?= --symdebug:dwarf --optimize_with_debug -qq -pdsw225 

# required C preprocessor flags
#    compiler   headers: "C:/PROGRA~1/TEXASI~1/CCS/ccsv5/tools/compiler/msp430_4.1.2/include"
#    device     headers: "C:/Program Files/Texas Instruments/CCS/ccsv5/ccs_base/msp430/include"
#    Grace      headers: "C:/PROGRA~1/TEXASI~1/CCS/grace_2_00_01_65/packages" 
#    MSP430ware headers: "C:/PROGRA~1/TEXASI~1/CCS/ccsv5/ccs_base/msp430/msp430ware_1_25_00_30/packages/../"
CPPFLAGS = -D__MSP430G2553__ -I "C:/PROGRA~1/TEXASI~1/CCS/ccsv5/tools/compiler/msp430_4.1.2/include" -I "C:/PROGRA~1/TEXASI~1/CCS/grace_2_00_01_65/packages"  -I "C:/Program Files/Texas Instruments/CCS/ccsv5/ccs_base/msp430/include" -I "C:/PROGRA~1/TEXASI~1/CCS/ccsv5/ccs_base/msp430/msp430ware_1_25_00_30/packages/../"

# the compiler and archiver commands
CC = "C:/PROGRA~1/TEXASI~1/CCS/ccsv5/tools/compiler/msp430_4.1.2/bin/cl430" -c --obj_directory=objs/  -vmsp
AR = "C:/PROGRA~1/TEXASI~1/CCS/ccsv5/tools/compiler/msp430_4.1.2/bin/ar430" rq
RM = cmd.exe /q /c del /f
MKDIR = mkdir

# create object sub-directory, if necessary
ifeq (,$(wildcard objs/))
    $(shell $(MKDIR) objs\)
endif

all: grace.lib

# pattern rule to compile .c source to an object file
objs/%.obj: %.c makefile
	@echo cl430 $< ...
	$(CC) $(CCOPTS) $(CPPFLAGS) "$<"

# rule to combine all objects into the grace.lib library
grace.lib: objs/Grace_init.obj objs/CSL_init.obj objs/GPIO_init.obj objs/BCSplus_init.obj objs/USCI_B0_init.obj objs/InterruptVectors_init.obj objs/Timer1_A3_init.obj objs/System_init.obj objs/WDTplus_init.obj
	@ echo ar430 $@ $< ...
	$(AR) $@ $^

# clean removes all generated files 
clean:
	-$(RM) grace.lib
	-$(RM) "objs\"*.obj

