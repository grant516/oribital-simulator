/***********************************************************************
 * Heaader File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/
#include <cassert>
#pragma once

void testRunner();


void test:stationary_updateVelocity()
{
   Velocity velocity;
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   double ddx = 0.0;
   double ddy = 0.0;
   int t = 0;

   // do we need to pass in dx and dy, or will we pass in the variable from the
   // class itself
   velocity.updateVelocity(ddx, ddy, t);

   assert(velocity.getDx() == 0.0);
   assert(velocity.getDy() == 0.0);
}

void test : moving_updateVelocity()
{
   Velocity velocity;
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   double ddx = 0.0;
   double ddy = 0.0;
   int t = 0;

   // do we need to pass in dx and dy, or will we pass in the variable from the
   // class itself
   velocity.updateVelocity(ddx, ddy, t);

   assert(velocity.getDx() == 0.0);
   assert(velocity.getDy() == 0.0);
}

void test : AccelFromStop_updateVelocity()
{
   Velocity velocity;
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   double ddx = 1.2;
   double ddy = 3.4;
   int t = 1;

   // do we need to pass in dx and dy, or will we pass in the variable from the
   // class itself
   velocity.updateVelocity(ddx, ddy, t);

   assert(velocity.getDx() == 1.2);
   assert(velocity.getDy() == 3.4);
}

void test : AccelFromStopLong_updateVelocity()
{
   Velocity velocity;
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   double ddx = 1.2;
   double ddy = 3.4;
   int t = 2;

   // do we need to pass in dx and dy, or will we pass in the variable from the
   // class itself
   velocity.updateVelocity(ddx, ddy, t);

   assert(velocity.getDx() == 2.4);
   assert(velocity.getDy() == 6.8);
}

void test : complex_updateVelocity()
{
   Velocity velocity;
   velocity.setDx(4.1);
   velocity.setDy(6.0);
   double ddx = 0.5;
   double ddy = 0.2;
   int t = 3;

   // do we need to pass in dx and dy, or will we pass in the variable from the
   // class itself
   velocity.updateVelocity(ddx, ddy, t);

   assert(velocity.getDx() == 5.6);
   assert(velocity.getDy() == 6.6);
}