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

void nilakantha_series::calculate(int user_input)
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

	/* Print out the value as asked */

	fprintf(stdout, "%.6f\n", (double)sum);

	/* If we have no more terms, exit */

	if(terms < 2)
	{

		return;

	}

	/* If we have more terms, sum their contributions */

	#pragma omp parallel private(thread_num, thread_term)
	{

		/* Give the executing thread its thread number */

		thread_num = omp_get_thread_num();

		/* Set the iterator */

		i = 1;

		/* Begin looping through computation blocks towards the goal */

		while(i < terms)
		{

			/* If this threads computation will be needed, do it */

			if((thread_num + i) < terms)
			{

				thread_term = (double)numerator / (double)(((i + thread_num) * 2) * ((i + thread_num) * 2 + 1) * ((i + thread_num) * 2 + 2));

			}

			/* Pause so that all threads have finished */

			#pragma omp barrier

			/* If the thread term is a negative term in the series, make it so */

			if((i + thread_num) % 2 == 0)
			{

				thread_term = thread_term * -1.0;

			}

			/* In order, add and print to screen the thread values to the sum */

			for(j = 0; j < num_threads; j++)
			{

				if( i >= terms)
				{

					break;

				}

				if(thread_num == j)
				{

					sum += thread_term;

					/* Print to screen the current result */

					fprintf(stdout, "%.6f\n", sum);

					/* Increment i as it is needed */

					i += 1;

				}

				/* Make sure all threads wait to continue together */

				#pragma omp barrier

			}

		}

	}

	/* The job is finished! */

	return;

}
