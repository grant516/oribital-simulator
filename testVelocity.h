#pragma once
#include <cassert>
#include "velocity.h"
#include "acceleration.h"
#include "position.h"

class TestVelocity
{
public:
   void run()
   {
      stationary_updateVelocity();
      moving_updateVelocity();
      AccelFromStop_updateVelocity();
      AccelFromStopLong_updateVelocity();
      complex_updateVelocity();
   }

private:
   void stationary_updateVelocity()
   {
      // setup
      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);
      double ddx = 0.0;
      double ddy = 0.0;
      int t = 0;

      // exercise
      velocity.updateVelocity(ddx, ddy, t);

      // verify
      assert(velocity.getDx() == 0.0);
      assert(velocity.getDy() == 0.0);

      // teardown
   }

   void moving_updateVelocity()
   {
      // setup
      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);
      double ddx = 0.0;
      double ddy = 0.0;
      int t = 0;

      // exercise
      velocity.updateVelocity(ddx, ddy, t);

      // verify
      assert(velocity.getDx() == 0.0);
      assert(velocity.getDy() == 0.0);
      // teardown
   }

   void AccelFromStop_updateVelocity()
   {
      // setup
      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);
      double ddx = 1.2;
      double ddy = 3.4;
      int t = 1;
      
      // exercise
      velocity.updateVelocity(ddx, ddy, t);

      // verify
      assert(velocity.getDx() == 1.2);
      assert(velocity.getDy() == 3.4);
      // teardown
   }

   void AccelFromStopLong_updateVelocity()
   {
      // setup
      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);
      double ddx = 1.2;
      double ddy = 3.4;
      int t = 2;

      // exercise
      velocity.updateVelocity(ddx, ddy, t);

      // verify
      assert(velocity.getDx() == 2.4);
      assert(velocity.getDy() == 6.8);
      // teardown
   }

   void complex_updateVelocity()
   {
      // setup
      Velocity velocity;
      velocity.setDx(4.1);
      velocity.setDy(6.0);
      double ddx = 0.5;
      double ddy = 0.2;
      int t = 3;

      // exercise
      velocity.updateVelocity(ddx, ddy, t);

      // verify
      assert(velocity.getDx() == 5.6);
      assert(velocity.getDy() == 6.6);
      // teardown
   }
};

