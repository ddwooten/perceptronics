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



	/* Get the block size per thread */

	block_size = num_houses / num_threads;

	/* Enter the parallel part of the algorithm */

#pragma omp parallel private(cur_candy, i, prev_end, prev_max, prev_start, thread_end, thread_num, thread_start) shared(candy_limit, block_size, houses, num_houses, thread_answers)
{

	/* Local thread get local thread num */

	thread_num = omp_get_thread_num();

	/* Get each thread the start of its territory in the house array*/

	if(thread_num)
	{

		thread_start = block_size * thread_num;

	}
	else
	{

		thread_start = 0;

	}

	/* Give each thread the end of its territory in the house array */

	if(thread_num < num_threads - 1)
	{

		thread_end = block_size * (thread_num + 1);

	}
	else
	{

		thread_end = num_houses;

	}

	/* Begin looping through the threads territory */

	i = thread_start;

	prev_start = thread_start;

	prev_end = thread_start;

	prev_max = 0;

	cur_candy = 0;

	while((thread_start < thread_end) & (i < num_houses))
	{

		/* Gather the candy from the current house */

		cur_candy += houses[i];

		if(cur_candy > candy_limit)
		{

			/* If over limit, save previous max and info */

			prev_max = cur_candy - houses[i];

			prev_start = thread_start;

			prev_end = i - 1;

			/* Shorten the route one house at a time to get below
			   limit */

			while(cur_candy > candy_limit)
			{

				cur_candy -= houses[thread_start];

				thread_start++;

			}

		}

		/* If you have exactly what you want, you are done */

		if(cur_candy == candy_limit)
		{

			break;

		}

		/* Go to the next house */

		i++;

	}

	/* If last idea was the best idea, replace the current info */

	if(prev_max > cur_candy)
	{

		cur_candy = prev_max;

		thread_start = prev_start;

		route_end = prev_end;

	}
	else
	{

		route_end = i--;

	}

	/* Save this thread's answer */

	thread_answers[3 * thread_num] = cur_candy;

	thread_answers[3 * thread_num + 1] = thread_start;

	thread_answers[3 * thread_num + 2] = route_end;

}

}

void nilakantha_series::report()
{

	/* Loop backwards through the threads, this ensures the first workable
	   answer is grabbed */

	for(i = num_threads; i > 0; i--)
	{

		if(thread_answers[3 * (i - 1)] >= nilakantha_series_haul)
		{

			nilakantha_series_haul = thread_answers[3 * (i - 1)];

			nilakantha_series_start = thread_answers[ 3 * (i - 1) + 1];

			nilakantha_series_end = thread_answers[3 * (i - 1) + 2];

		}

	}

	/* Report out the nilakantha_series result */

	if(nilakantha_series_haul > 0)
	{

		/* Increment the indices forward as the problem indexes to 1*/

		cout << "Start at home " << (nilakantha_series_start + 1) << " and go to home " << (nilakantha_series_end + 1)<< " getting " << nilakantha_series_haul << " pieces of candy.\n";

	}
	else
	{

		cout << "Don't go here.\n";

	}

}

nilakantha_series::~nilakantha_series()
{

	delete[] houses;

	delete[] thread_answers;

}
