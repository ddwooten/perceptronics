#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "/home/dwooten/Documents/googletest/googletest/include/gtest/gtest.h"
#include "./../src/trick_or_treat.h"

class TrickOrTreatTest:public::testing::Test
{

	protected:

		TrickOrTreatTest()
		{

			all_saints_eve = new trick_or_treat{};

		}

		~TrickOrTreatTest()
		{

			delete all_saints_eve;

		}

};

TEST_F(TrickOrTreatTest, ReadsInputNumHouses)
{

	const std::string input_file_path = "input_testing_1.txt";

	all_saints_eve.read_input(&input_file_path);

	EXPECT_EQ(all_saints_eve.num_houses, 14);

}

int main(int argc, char **argv)
{

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();

}


