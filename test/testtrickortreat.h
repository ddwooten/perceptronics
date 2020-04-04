
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
