/**
  * Set up class for testing of the trick_or_treat class.
  */

class TrickOrTreatTest:public::testing::Test
{

	protected:

		trick_or_treat *all_saints_eve;

		/**
		  * Constructor for the test class.
		  * Allocates memory for the class being tested.
		  */

		TrickOrTreatTest()
		{

			all_saints_eve = new trick_or_treat{}; 

		}

		/**
		  * Destructor for the test class.
		  * Frees memory related to the class being tested.
		  */

		~TrickOrTreatTest()
		{

			delete all_saints_eve;

		}

};