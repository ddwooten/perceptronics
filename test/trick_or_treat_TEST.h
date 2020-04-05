#include "/home/dwooten/Documents/cxxtest/cxxtest/TestSuite.h"

/**
  * Set up class for testing of the trick_or_treat class.
  */

class trick_or_treat_TEST : public CPPUNIT_NS::TestFixture
{

	CPPUNIT_TEST_SUITE( trick_or_treat_TEST );

	CPPUNIT_TEST( num_houses_TEST );

	CPPUNIT_TEST_SUITE_END();

	public:	
		
		void set_up();

		void tear_down();

		void num_houses_TEST();

};
