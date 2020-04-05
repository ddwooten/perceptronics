#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <omp.h>
#include <memory>
#include "../src/trick_or_treat.h"
#include "/home/dwooten/Documents/cppunit/include/cppunit/extensions/HelperMacros.h"
#include "/home/dwooten/Documents/cppunit/include/cppunit/CompilerOutputter.h"
#include "/home/dwooten/Documents/cppunit/include/cppunit/TestSuite.h"
#include "/home/dwooten/Documents/cppunit/include/cppunit/TestCaller.h"
#include "/home/dwooten/Documents/cppunit/include/cppunit/ui/text/TestRunner.h"
#include "/home/dwooten/Documents/cppunit/include/cppunit/TestCase.h"
#include "trick_or_treat_TEST.h"

CPPUNIT_TEST_SUITE_REGISTRATION( trick_or_treat_TEST );

void trick_or_treat_TEST::set_up()
{

}

void trick_or_treat_TEST::tear_down()
{

}

void trick_or_treat_TEST::num_houses_TEST()
{

	const trick_or_treat all_saints_eve{};

	CPPUNIT_ASSERT_EQUAL(omp_get_max_threads(), all_saints_eve.num_threads);

}

