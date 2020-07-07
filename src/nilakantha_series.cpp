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
	
	/* Set the iterators */

	i = 1;

	j = 0;

	/* Spawn off threads */

	#pragma omp parallel 
	{

		/* Give the executing thread its thread number and init private variables */

		int thread_num = omp_get_thread_num();

		double thread_term = 0.0;

		fprintf(stdout, "Hello from thread %d\n", thread_num);

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

			fprintf(stdout, "Thread %d has value %.12f\n", thread_num, thread_term);

			fprintf(stdout, "The sum value is %.12f\n", sum);


			/* In order, add and print to screen the thread values to the sum */

			while(true)
			{

				/* Pause so that all threads are ready */

				#pragma omp barrier

				if(thread_num == j)
				{

					sum += thread_term;

					fprintf(stdout, "Thread %d added %.12f to sum for final sum of %.12f with i at %d and j at %d.\n", thread_num, thread_term, sum, i, j);

					/* Print to screen the current result */

					fprintf(stdout, "%.12f\n", sum);

					/* Increment i and j as it is needed */

					i += 1;

					j += 1;

					fprintf(stdout, "Thread %d reports i and j and %d and %d.\n", thread_num, i, j);

				}

				/* Make sure all threads wait to continue together */

				fprintf(stdout, "BARRIER!!!\n\n");

				#pragma omp barrier

				fprintf(stdout, "Thread %d reports i and j and %d and %d.\n", thread_num, i, j);

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
