// squarer_test.cpp  SKELETON
// Glenn G. Chappell
// 2020-11-20
//
// For CS 311 Fall 2020
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
    "class Squarer"
    " - CS 311 Proj 8, Ex B";


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("squarer: int")
{
    Squarer s;
    SUBCASE("one, zero, negative one")
    {
        int one = 1;
        int zero = 0;
        int negone = -1;
        INFO("one");
        REQUIRE(s(one) == one);
        INFO("zero");
        REQUIRE(s(zero) == zero);
        INFO("negative one");
        REQUIRE(s(negone) == one);
    }
    SUBCASE("small positive numbers")
    {
        INFO("2 to 20");
        for (int i = 2; i <= 20; ++i)
        {
            REQUIRE(s(i) == i * i);
        }
    }
    SUBCASE("large positive numbers")
    {
        INFO("1000");
        REQUIRE(s((int)1000) == 1000 * 1000);
        INFO("20000");
        REQUIRE(s((int)20000) == 20000 * 20000);
        INFO("46340");
        REQUIRE(s((int)46340) == 46340 * 46340);
    }
}


// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

