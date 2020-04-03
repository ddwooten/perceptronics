#include <stdio>
#include <fstream>
#include <omp>

using namespace std;

trick_or_treat::trick_or_treat()
{

	/* Get the number of threads */

	num_threads = omp_get_max_threads();

	/* Allocate memory for the thread answers */

	thread_answers = new (nothrow) int[num_threads];

	if(thread_answers == nullptr)
	{

		cerr << "Error: Unable to allocate houses memory.\n";

		exit(EXIT_FAILURE);

	}

}

void trick_or_treat::read_input(char* input_file)
{

	/* Open the input file */

	in_file.open(input_file, ios::in);

	if(!in_file)
	{

		cerr << "Error: Unable to open file " << input_file << "\n";

		exit(EXIT_FAILURE);

	}

	/* Extract the number of houses and the max amount of candy */

	in_file >> num_houses;

	in_file >> candy_limit;

	/* Allocate memory for the houses array */

	houses = new (nothrow) int[num_houses];

	if(houses == nullptr)
	{

		cerr << "Error: Unable to allocate houses memory.\n";

		exit(EXIT_FAILURE);

	}

	/* Move through in_file collecting the information for the house array*/

	i = 0;

	while(true)
	{

		if(in_file.eof()) break;

		in_file >> houses[i];

		i++;

	}

}

void trick_or_treat::find_path()

	/* Get the block size per thread */

	block_size = num_houses % num_threads;

	/* Enter the parallel part of the algorithm */

#pragma omp parallel private(blocks_completed, cur_candy, i, max_candy, prev_block_max, prev_end, prev_max, prev_start, thread_num) shared(thread_answers)
{

	thread_num = omp_get_thread_num();

	blocks_completed = 0;

	/* Look through the array until you have reached the end */

	while(blocks_completed * block_size * num_threads < num_houses)
	{

		/* Each thread is to search only its given blocks, AND any space		   following those blocks until the candy_limit is exceeded */
		
		cur_candy = houses[blocks_completed * (block
		while(true)
		{

				

			

		}

	}

}

	return(1);

}
