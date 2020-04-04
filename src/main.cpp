#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "trick_or_treat.h"

using namespace std;

/** 
  * Executing function of the programing challenge.
  * main() may optionally take 1 command line argument. This argument is the
  * relative or absolute path to an input file for the programing challenge.
  * main() uses a default value for this path of './../input.txt' which will
  * be overridden by *any* command line input following the invocation of
  * the executable.
  * @param argc The number of command line arguments including the function name
  * @param argv Array of char* to command line inputs in string format
  */

int main(int argc, char** argv)
{

	char file_name[256]; /**< Memory for the file name */

	fstream in_file; /**< Streaming file object used here for input */

	trick_or_treat* hopes_and_dreams; /**< @see trick_or_treat */

	/* If no arguments give, use default run settings */

	if(argc < 2)
	{

		strcpy(file_name, "./../input.txt");

	}
	else
	{

		strcpy(file_name, argv[1]);

	}

	/* Initiate the trick_or_treat class into a child's hope's and dreams */

	hopes_and_dreams = new trick_or_treat{};

	/* Read in the input */

	hopes_and_dreams -> read_input(file_name);

	/* Find the optimal candy route */

	hopes_and_dreams -> find_path();

	/* Print out the result */

	hopes_and_dreams -> report();

	return(1);

}
