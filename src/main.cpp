#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "nilakantha_series.h"

using namespace std;

/** 
  * Executing function of the programming challenge.
  * main() ay optionally take 1 command line argument. This argument is the
  * relative or absolute path to an input file for the programming challenge.
  * main() uses a default value for this path of './../input.txt' which will
  * be overridden by *any* command line input following the invocation of
  * the executable.
  * @param argc The number of command line arguments including the function name
  * @param argv Array of char* to command line inputs in string format
  */

int main(int argc, char **argv)
{
	
	/** Storage for user input before integer conversion.*/
	char input[128];

	/** Integer user input for desired number of terms in computation.*/
	int terms = 0;

	/** @see nilakantha_series. */
	nilakantha_series* this_series;

	/* If no arguments given, error out */

	if(argc < 2)
	{

		fprintf(stdout, "No input given with program invocation. Usage of the Nilakantha calculator requires the inclusion of one command line argument being a positive integer. E.g. any of 1, 2, 3...\n");

		return(0);

	}
	else
	{

		/* Otherwise take in a protected slice of user input and
		   attempt to convert to integer */

		strncpy(input, argv[2], 127);

		strncat(input, "\0", 1);

		terms = atoi(input);

		/* If the conversion failed, error out with message */
		
		if(terms == 0)
		{

			fprintf(stdout, "Attempted conversion of user input, %s, to integer. Conversion failed. Please invoke this program with command line input which can be converted from type of string to type of integer.\n", input);

			return(0);

		}
		
	}

	/* Initiate the nilakantha_series class */

	this_series = new nilakantha_series{};

	/* Begin the calculation */

	this_series -> calculate(terms);

	/* Exit gracefully */

	return(1);

}
