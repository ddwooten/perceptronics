#include <stdio>
#include <fstream>
#include <omp>

using namespace std::cout, std::cerr;

trick_or_treat::trick_or_treat()
{

	/* Get the number of threads */

	num_threads = omp_get_max_threads();

	/* Allocate memory for the thread answers and thread block sizes*/

	thread_answers = new (nothrow) int[num_threads];

	if(thread_answers == nullptr)
	{

		cerr << "Error: Unable to allocate houses memory.\n";

		exit(EXIT_FAILURE);

	}

	thread_block_sizes = new (nothrow) int[num_threads];

	if(thread_block_sizes == nullptr)
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
{

	/* Get the block size per thread */

	block_size = num_houses / num_threads;

	/* Give all but the last thread their block size */

	for(i = 0; i < (num_threads - 1) ; i++)
	{

		thread_block_sizes[i] = block_size;

	}

	/* The last thread handles the remainder */

	thread_block_sizes[num_threads - 1] = num_houses % num_threads + block_size;

	/* Enter the parallel part of the algorithm */

#pragma omp parallel private(cur_candy, i, max_candy, prev_end, prev_max, prev_start, start, thread_end, thread_num, thread_start) shared(thread_answers, thread_block_sizes)
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

	i = 0;

	while((start < thread_end) & (i < num_houses))
	{



	}

}

}
