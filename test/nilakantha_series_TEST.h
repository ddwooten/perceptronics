#include <HelperMacros.h>
#include "./../src/nilakantha_series.h"

/**
  * Set up class for testing of the nilakantha_series class.
  */

class nilakantha_series_SUITE : public CppUnit::TestFixture
{
	
	CPPUNIT_TEST_SUITE( nilakantha_series_SUITE );

	CPPUNIT_TEST( num_houses_TEST );

	CPP_TEST_SUITE_END();

	public:

		void num_houses_TEST();

};
