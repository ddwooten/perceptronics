#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "nilakantha_series.h"

using namespace std;

nilakantha_series::nilakantha_series()
{

	/* Get the number of threads */

	num_threads = omp_get_max_threads();

	/* Allocate memory for the thread answers and thread block sizes*/

	thread_answers = new(nothrow) int[3 * num_threads];

	if(thread_answers == nullptr)
	{

		cerr << "Error: Unable to allocate houses memory.\n";

		exit(EXIT_FAILURE);

	}

}

void nilakantha_series::calulate(int user_input)
{

	terms = user_input;

	/* Ensure we have good input */

	if(terms < 1)
	{

		fprintf(stderr, "User input is invalid with value of %d.\n", 
		        terms);

	}

	/* The first term of the series is our return value at least */

	sum = term_0;

	/* If we have no more terms, return this value */

	if(terms < 2)
	{

		fprintf(stdout, "%.6f\n", (double)sum);

		return(1);

	}

	/* If we have more terms, sum their contributions */

	for(i = 1; i < terms; i++)
	{

		/* Reset the denominator value and get the new one*/

		denominator = denom_start * (denom_start + 1) * (denom_start + 2);

		/* Increment the denomintor start forward */

		denom_start += 2;

		/* The sign infront of the terms in this series alternates */

		if(terms % 2 == 0)
		{

			sum -= (float)numerator / (float)denominator;

		}
		else
		{

			sum += (float)numerator / (float)denominator;

		}
		
		/* Print to screen the current result */

		fprintf(stdout, "%.6f\n", (double)sum);

	}

	/* The job is finished! */

	return(1);

}
