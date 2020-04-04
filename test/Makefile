###############################################################################

# GNU Compiler:

CC  	 = g++
CCM      = g++
CFLAGS   = -Wall -ansi -ffast-math -O3 -std=c++17
LDFLAGS  = -lm -std=c++17
GTEST = -I/home/dwooten/Documents/googletest/googletest/include

# Parallel calculation using Open MP:

CFLAGS  += -fopenmp
LDFLAGS += -fopenmp

# This is needed in newer gcc versions to supress some unnecessary warnings

#CFLAGS += -Wno-unused-but-set-variable

# Remove this if compilation with mpicc produces unnecessary warnings

#CFLAGS += -pedantic
###############################################################################

# Intel Compiler:

#CC  	 = icc

# Optimization for Intel CPU's:

#CFLAGS   = -Wall -ansi -pedantic -xHost -ipo 
#GTEST = -I/home/dwooten/Documents/googletest/googletest/include/gtest

# Alternative:

#CFLAGS   = -Wall -ansi -pedantic -O3
#GTEST = -I/home/dwooten/Documents/googletest/googletest/include/gtest

#LDFLAGS  = -lm

# Parallel calculation using Open MP:

#CFLAGS  += -openmp
#LDFLAGS += -openmp

###############################################################################

# Parallel calculation using MPI:

# NOTE: The use of hybrid MPI/OpenMP mode requires thread-safe MPI
#       implementation. Some MPI implementations, such as some versions (?) of
#       Open MPI are not thread safe, which will cause problems in memory 
#       management routines (calloc, realloc and free). These problems may
#       result in failure in memory allocation or unexpected behaviour due to
#       corrupted registers (?).

#CC  	 = mpicc
#CCM	 = mpicc
###############################################################################

# Debugging:

CFLAGS :=$(filter-out -03,$(CFLAGS))
CFLAGS :=$(filter-out -ffast-math,$(CFLAGS))
CFLAGS  += -g -O0
LDFLAGS += -g

# Profiler:

#CFLAGS   += -p 
#LDFLAGS  += -p

###############################################################################

OBJS	=	testtrickortreat.o \
		trickortreat.o

###############################################################################

EXE     = TEST_Trick_or_Treat

DATE 	= -DMC_COMPILE_DATE="\"`date `\""

# Get number of bits:

shell = $SHELL
lbits := $(shell getconf LONG_BIT)

# Use this to override the 64 bit check

#lbits = 64

###############################################################################
all:    $(EXE)
	@echo "TEST_Trick_or_Treat Compiled OK."

$(EXE): $(OBJS) 
	$(CCM) $(OBJS) $(LDFLAGS) $(GTEST) -o $(EXE)

clean:	
	$(RM) $(OBJS) $(FOBJS) $(OBSOLETE)

###############################################################################

testtrickortreat.o: testtrickortreat.cpp ../src/trick_or_treat.h testtrickortreat.h
	$(CC) $(CFLAGS) $(GTEST) -c testtrickortreat.cpp 

trickortreat.o: ../src/trickortreat.cpp ../src/trick_or_treat.h
	$(CC) $(CFLAGS) -c ../src/trick_or_treat.cpp 
