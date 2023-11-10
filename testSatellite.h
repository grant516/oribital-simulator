#pragma once
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "satellite.h"
#include <cassert>


class TestSatellite
{
public:

   void run()
   {
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

   // Testing getAltitude functions
   void surface_getAltitude()
   {
      // setup
      Satellite satellite;
      Position position;
      position.setMetersX(6378000.0);
      position.setMetersY(0.0);

      // exercise
      double alt = satellite.getAltitude(position.getMetersX(), position.getMetersY());
      
      // verify
      assert(alt == 0);
      
      // teardown
   }

   void xAxis_getAltitude()
   {
      // setup
      Satellite satellite;
      Position position;
      position.setMetersX(6379000.0);
      position.setMetersY(0.0);

      // exercise
      double alt = satellite.getAltitude(position.getMetersX(), position.getMetersY());

      // verify
      assert(alt == 1000);

      // teardown
   }

   void yAxis_getAltitude()
   {
      // setup
      Satellite satellite;
      Position position;
      position.setMetersX(0.0);
      position.setMetersY(6379000.0);

      // exercise
      double alt = satellite.getAltitude(position.getMetersX(), position.getMetersY());

      // verify
      assert(alt == 1000);

      // teardown
   }

   void geostationary_getAltitude()
   {
      // setup
      Satellite satellite;
      Position position;
      position.setMetersX(29814450.3);
      position.setMetersY(29814450.3);

      // exercise
      double alt = satellite.getAltitude(position.getMetersX(), position.getMetersY());

      // verify
      assert(alt == 35786000.0);

      // teardown
   }

   // TODO

   // Testing getGravity functions
   void surface_getGravity()
   {
      // setup
      Satellite satellite;
      Position position;
      position.setMetersX(6378000.0);
      position.setMetersY(0.0);

      // exercise
      double grav = satellite.getGravity(position.getMetersX(), position.getMetersY());

      // verify
      assert(grav == 35786000.0);

      // teardown
   }

   void fiveHundredK_getGravity()
   {
      // setup
      Satellite satellite;
      Position position;
      position.setMetersX(6378000.0 + 500000.0);
      position.setMetersY(0.0);

      // exercise
      double grav = satellite.getGravity(position.getMetersX(), position.getMetersY());

      // verify
      assert(grav == 35786000.0);

      // teardown
   }

   void twoThousandK_getGravity()
   {
      // setup
      Satellite satellite;
      Position position;
      position.setMetersX(6378000.0 + 2000000.0);
      position.setMetersY(0.0);

      // exercise
      double grav = satellite.getGravity(position.getMetersX(), position.getMetersY());

      // verify
      assert(grav == 35786000.0);

      // teardown
   }
};

