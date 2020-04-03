#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "trick_or_treat.h"

using namespace std;

int main(int argc, char** argv)
{

	char file_name[256];

	fstream in_file;

	trick_or_treat* hopes_and_dreams;

	/* If no arguments give, use default run settings */

	if(argc < 2)
	{

		strcpy(file_name, "./input.txt");

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
