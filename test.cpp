/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testVelocity.h"
#include <cassert>


/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestVelocity().run();
   cout << "All test passed!" << endl;
}