#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <omp.h>
#include <CompilerOutputter.h>
#include <TestFactorRegistry.h>
#include <TestRunner.h>
#include "../src/nilakantha_series.h"
#include "nilakantha_series_TEST.h"


int main()
{
	
	/** Error code. */
	int status = 0;

	/* Get the top level suite from the registry */
	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();

	/** Object to control running of tests. */
	CPPUNIT_NS::TextUi::TestRunner runner;

	/* Adds the test to the list of test to run */
	runner.addTest( suite );

	/* Change the default outputter to a compiler error format outputter*/
	runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(), CPPUNIT_NS::stdCOut() ));

	/* Run the test. */
	status = runner.run();

	// Return error code 1 if the one of test failed.
	return( status );

}

