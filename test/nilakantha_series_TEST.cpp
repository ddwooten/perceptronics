#include "nilakantha_series_TEST.h"

CPPUNIT_TEST_SUITE_REGISTRATION( nilakantha_series_SUITE );

void nilakantha_series_TEST::num_threads_TEST()
{

	const nilakantha_series this_series{};

	CPPUNIT_ASSERT_EQUAL(omp_get_max_threads(), this_series.num_threads);

}

