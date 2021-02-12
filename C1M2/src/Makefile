#******************************************************************************
# Copyright (C) 2021 by Josh Illes
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Josh Illes is not liable for any misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Platform Dependant Variables
ifeq ($(PLATFORM),HOST)
	# Host dependant options
else ($(PLATFORM),MSP432)
	# MSP432 dependant build options
else
	@echo Please enter either PLATFORM=HOST or PLATFORM=MSP432
endif

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.c
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = 
LD = 
LDFLAGS = 
CFLAGS = -g -std=$(CSTD) -mcpu=$(CPU) -mthumb
CPPFLAGs = 
.PHONY: compile-all build clean

build:
	# Compile all object files and link into a final executable.

%.i: $^ 
	# Generate Preprocesed output of all c-program implementation files (use the -E flag)

%.asm: $^
	# Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).

%.o: $^
	# Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.

compile-all:
	# Compile all object files, but DO NOT link.

clean:
	# This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
	@echo Removing all built files
	rm -f *.out *.map *.o *.asm *.i