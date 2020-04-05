#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "/home/dwooten/Documents/googletest/googletest/include/gtest/gtest.h"
#include "./../src/trick_or_treat.h"

/**
  * Test that trick_or_treat:read_input get the correct number of houses.
  */

TEST(GodHelpUsAll, ReadsInputNumHouses)
{
	/** Input file path. */
	char input_file[256];

	int test_value = 0;

	strcpy(input_file, "input_testing_1.txt");

	trick_or_treat *all_saints_eve;

	all_saints_eve = new trick_or_treat{};

	all_saints_eve -> read_input(input_file);

	all_saints_eve -> find_path();

	all_saints_eve -> report();

	test_value = all_saints_eve -> num_threads;

	ASSERT_GT(test_value, 0);

}

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);

	int out = 0;

	out = RUN_ALL_TESTS();

	return(out);

}


