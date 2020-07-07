###############################################################################

# GNU Compiler:

CC  	 = g++
CCM      = g++
CFLAGS   = -Wall -ansi -ffast-math -O3 -std=c++17
LDFLAGS  = -lm -std=c++17
TEST = -I/home/dwooten/Documents/cppunit/include -I/home/dwooten/Documents/cppunit/include/cppunit/extensions

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

OBJS	=	nilakantha_series_TEST.o \
		nilakantha_series.o \
		main.o

###############################################################################

EXE     = run_tests 

DATE 	= -DMC_COMPILE_DATE="\"`date `\""

# Get number of bits:

shell = $SHELL
lbits := $(shell getconf LONG_BIT)

# Use this to override the 64 bit check

#lbits = 64

###############################################################################
all:    $(EXE)
	@echo "Niakantha_Series_TEST Compiled OK."

$(EXE): $(OBJS) 
	$(CCM) $(OBJS) $(LDFLAGS) $(TEST) -o $(EXE)

clean:	
	$(RM) $(OBJS) $(FOBJS) $(OBSOLETE)

###############################################################################

nilakantha_series_TEST.o: nilakantha_series_TEST.cpp nilakantha_series_TEST.h
	$(CC) $(CFLAGS) $(TEST) -c nilakantha_series_TEST.cpp 

nilakantha_series.o: ../src/nilakantha_series.cpp ../src/nilakantha_series.h
	$(CC) $(CFLAGS) $(TEST) -c ../src/nilakantha_series.cpp 

main.o: main.cpp 
	$(CC) $(CFLAGS) $(TEST) -c main.cpp 
