/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_trick_or_treat_SUITE_init = false;
#include "/home/dwooten/nvidia/test/trick_or_treat_TEST.h"

static trick_or_treat_SUITE suite_trick_or_treat_SUITE;

static CxxTest::List Tests_trick_or_treat_SUITE = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_trick_or_treat_SUITE( "trick_or_treat_TEST.h", 12, "trick_or_treat_SUITE", suite_trick_or_treat_SUITE, Tests_trick_or_treat_SUITE );

static class TestDescription_suite_trick_or_treat_SUITE_testNumHouses : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_trick_or_treat_SUITE_testNumHouses() : CxxTest::RealTestDescription( Tests_trick_or_treat_SUITE, suiteDescription_trick_or_treat_SUITE, 24, "testNumHouses" ) {}
 void runTest() { suite_trick_or_treat_SUITE.testNumHouses(); }
} testDescription_suite_trick_or_treat_SUITE_testNumHouses;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
