#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "/home/dwooten/Documents/googletest/googletest/include/gtest/gtest.h"
#include "./../src/trick_or_treat.h"
#include "trickortreattest.h"

/**
  * Test that trick_or_treat:read_input get the correct number of houses.
  */

TEST_F(TrickOrTreatTest, ReadsInputNumHouses)
{
	/** Input file path. */

	char input_file_path[] = "input_testing_1.txt";

	all_saints_eve -> read_input(input_file_path);

	EXPECT_EQ(all_saints_eve -> num_houses, 14);

}

/**
  * Test that trick_or_treat:read_input sets the houses array properly.
  */

TEST_F(TrickOrTreatTest, ReadsInputHouses)
{

	/** Input file path. */

	char input_file_path[] = "input_testing_1.txt";

	all_saints_eve -> read_input(input_file_path);

	EXPECT_EQ(all_saints_eve -> houses[5], 15);

}

/**
  * Test that read_input and find_path work together. 
  */

TEST_F(TrickOrTreatTest, PopulatedThreadAnswers)
{

	/** Input file path. */

	char input_file_path[] = "input_testing_1.txt";

	/** Number of omp threads */

	int num_threads = 0;

	num_threads = omp_get_max_threads();

	all_saints_eve -> read_input(input_file_path);

	all_saints_eve -> find_path();

	EXPECT_EQ(all_saints_eve -> thread_answers[3 * (num_threads - 1)], 10);

}

/**
  * Test that trick_or_treat gets the correct answer for the candy amount.
  */

TEST_F(TrickOrTreatTest, CorrectCandyAmt)
{

	/** Input file path. */

	char input_file_path[] = "input_testing_1.txt";

	all_saints_eve -> read_input(input_file_path);

	all_saints_eve -> find_path();

	all_saints_eve -> report();

	EXPECT_EQ(all_saints_eve -> trick_or_treat_haul, 10);

}

/**
  * Test that trick_or_treat gets the correct starting house index.
  */

TEST_F(TrickOrTreatTest, CorrectStartHouse)
{

	/** Input file path. */

	char input_file_path[] = "input_testing_1.txt";

	all_saints_eve -> read_input(input_file_path);

	all_saints_eve -> find_path();

	all_saints_eve -> report();

	EXPECT_EQ(all_saints_eve -> trick_or_treat_start, 7 );

}

/**
  * Test that trick_or_treat gets the correct ending house index.
  */

TEST_F(TrickOrTreatTest, CorrectEndHouse)
{

	/** Input file path. */

	char input_file_path[] = "input_testing_1.txt";

	all_saints_eve -> read_input(input_file_path);

	all_saints_eve -> find_path();

	all_saints_eve -> report();

	EXPECT_EQ(all_saints_eve -> trick_or_treat_end, 8);

}

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();

}


