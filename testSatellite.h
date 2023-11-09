#pragma once
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include <cassert>


class testSatellite
{
public:

   void run()
   {
      // Testing updatePosition
      stationary_updatePosition();
      moving_updatePosition();
      movingLonger_updatePosition();
      fromStop_updatePosition();
      fromStopLong_updatePosition();
      complex_updatePosition();

      // Testing getAltitude
      surface_getAltitude();
      xAxis_getAltitude();
      yAxis_getAltitude();
      geostationary_getAltitude();

      // Testing getGravity
      surface_getGravity();
      fiveHundredK_getGravity();
      twoThousandK_getGravity();
   }

private:

   // Testing updatePosition functions
   void stationary_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);

      Acceleration accel;
      double ddx = 0.0;
      double ddy = 0.0;

      int t = 1;

      // exercise
      satellite.updatePosition(ddx, ddy, t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void moving_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.5);
      velocity.setDy(0.4);

      Acceleration accel;
      double ddx = 0.0;
      double ddy = 0.0;

      int t = 1; 

      // exercise
      satellite.updatePosition(ddx, ddy, t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void movingLonger_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.5);
      velocity.setDy(0.4);

      Acceleration accel;
      double ddx = 0.0;
      double ddy = 0.0;

      int t = 2;

      // exercise
      satellite.updatePosition(ddx, ddy, t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void fromStop_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);

      Acceleration accel;
      double ddx = 0.2;
      double ddy = 0.3;

      int t = 1;

      // exercise
      satellite.updatePosition(ddx, ddy, t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void fromStopLong_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);

      Acceleration accel;
      double ddx = 0.2;
      double ddy = 0.3;

      int t = 2;

      // exercise
      satellite.updatePosition(ddx, ddy, t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void complex_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(1.0);
      velocity.setDy(2.0);

      Acceleration accel;
      double ddx = 0.2;
      double ddy = 0.3;

      int t = 2;

      // exercise
      satellite.updatePosition(ddx, ddy, t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   // Testing getAltitude functions
   void surface_getAltitude()
   {
      // setup
      Position position;
      position.setMetersX(6378000.0);
      position.setMetersY(0.0);

      // exercise
      double alt = satellite.getAltitude();
      
      // verify
      assert(alt == 0);
      
      // teardown
   }

   void xAxis_getAltitude()
   {
      // setup
      Position position;
      position.setMetersX(6379000.0);
      position.setMetersY(0.0);

      // exercise
      double alt = satellite.getAltitude();

      // verify
      assert(alt == 1000);

      // teardown
   }

   void yAxis_getAltitude()
   {
      // setup
      Position position;
      position.setMetersX(0.0);
      position.setMetersY(6379000.0);

      // exercise
      double alt = satellite.getAltitude();

      // verify
      assert(alt == 1000);

      // teardown
   }

   void geostationary_getAltitude()
   {
      // setup
      Position position;
      position.setMetersX(29814450.3);
      position.setMetersY(29814450.3);

      // exercise
      double alt = satellite.getAltitude();

      // verify
      assert(alt == 35786000.0);

      // teardown
   }

   // TODO

   // Testing getGravity functions
   void surface_getGravity()
   {
      // setup
      Position position;
      position.setMetersX(6378000.0);
      position.setMetersY(0.0);

      // exercise
      double grav = satellite.getGravity();

      // verify
      assert(grav == 35786000.0);

      // teardown
   }

   void fiveHundredK_getGravity()
   {
      // setup
      Position position;
      position.setMetersX(6378000.0 + 500000.0);
      position.setMetersY(0.0);

      // exercise
      double grav = satellite.getGravity();

      // verify
      assert(grav == 35786000.0);

      // teardown
   }

   void twoThousandK_getGravity()
   {
      // setup
      Position position;
      position.setMetersX(6378000.0 + 2000000.0);
      position.setMetersY(0.0);

      // exercise
      double grav = satellite.getGravity();

      // verify
      assert(grav == 35786000.0);

      // teardown
   }
};

