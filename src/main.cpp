#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "nilakantha_series.h"

using namespace std;

/** 
  * Executing function of the programming challenge.
  * main() takes 1 command line argument. This argument is the
  * is the number of terms in the Nilakantha series which the
  * program should output to stdout. 
  * main() only accepts positive integer values as input.
  * Any other such input will be caught by @see check_input()
  * @param argc The number of command line arguments including the function name
  * @param argv Array of char* to command line inputs in string format
  */

int main(int argc, char **argv)
{
	
	/** Storage for user input before integer conversion.*/
	char input[128];

	/** Error check variable. */
	int pass = 0;

	/** @see nilakantha_series. */
	nilakantha_series* this_series;

	/* If no arguments given, error out */

	if(argc < 2)
	{

		fprintf(stdout, "No input given with program invocation. Usage of the Nilakantha calculator requires the inclusion of one command line argument being a positive integer. E.g. any of 1, 2, 3...\n");

		return(0);

	}
	else if(argc > 2)
	{

		fprintf(stdout, "Additional input given with program invocation. Usage of the Nilakantha calculator requires the inclusion of one, and only one, command line argument with that argument being a positive integer. E.g. any of 1, 2, 3...\n");

		return(0);

	}
	else
	{

		/* Take in a protected slice of user input */

		strncpy(input, argv[1], 126);

	}

	/* Initiate the nilakantha_series class */

	this_series = new nilakantha_series{};

	/* Check the user input */

	pass = this_series -> check_input(input);

	/* If the check failed, exit out with 0 */

	if(pass != 1)
	{

		return(0);

	}

	/* Begin the calculation */

	this_series -> calculate();

	/* Exit gracefully */

	return(1);

}
