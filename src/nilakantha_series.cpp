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

}

void nilakantha_series::calculate()
{

	/* The first term of the series is our return value at least */

	sum = term_0;

	/* Print out the value as asked */

	fprintf(stdout, "%.6f\n", (double)sum);

	/* If we have no more terms, exit */

	if(terms < 2)
	{

		return;

	}

	/* If we have more terms, sum their contributions */
	
	/* Set the iterators */

	i = 1;

	j = 0;

	/* Spawn off threads */

	#pragma omp parallel 
	{

		/* Give the executing thread its thread number and init private variables */

		int thread_num = omp_get_thread_num();

		double thread_term = 0.0;

		/* Begin looping through computation blocks towards the goal */

		while(i < terms)
		{
			
			/* Pause so that all threads are ready */

			#pragma omp barrier

			/* If this threads computation will be needed, do it */

			if((thread_num + i) < terms)
			{

				thread_term = (double)numerator / (double)(((i + thread_num) * 2) * ((i + thread_num) * 2 + 1) * ((i + thread_num) * 2 + 2));

			}

			/* Reset the global thread iterator before barrier */

			j = 0;

			/* If the thread term is a negative term in the series, make it so */

			if((i + thread_num) % 2 == 0)
			{

				thread_term = thread_term * -1.0;

			}


			/* In order, add and print to screen the thread values to the sum */

			while(true)
			{

				/* Pause so that all threads are ready */

				#pragma omp barrier

				if(thread_num == j)
				{

					sum += thread_term;

					/* Print to screen the current result */

					fprintf(stdout, "%.12f\n", sum);

					/* Increment i and j as it is needed */

					i += 1;

					j += 1;

				}

				/* Make sure all threads wait to continue together */

				#pragma omp barrier

				/* If we have finished printing, exit */

				if((j == num_threads) || (i == terms))
				{

					break;

				}

			}

		}

	}

	/* The job is finished! */

	return;

}

int nilakantha_series::check_input(char* input)
{
	double flt = atof(input);

	int tmp = atoi(input);

	/* If the conversion failed, error out with message */

	if(tmp == 0)
	{

		fprintf(stdout, "Attempted conversion of user input, %s, to integer. Conversion failed. Please invoke this program with command line input which can be converted from type of string to type of integer.\n", input);

		return(0);

	}

	/* If the user input was a floating point number, error out */

	if(flt != tmp)
	{

		fprintf(stdout, "User provided floating point input of %f. Input must be positive integer.\n", flt);

		return(0);

	}

	/* If the input is less than 0, error out */

	if(tmp < 0)
	{

		fprintf(stdout, "User provided integer input of %d. Input must be positive.\n", tmp);

		return(0);

	}

	/* If the input made it here, its good, save it to the object. */

	terms = tmp;

	return(1);

}
