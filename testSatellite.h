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
      //surface_getGravity();
      //fiveHundredK_getGravity();
      //twoThousandK_getGravity();
   }

private:

   // Testing getAltitude functions
   void surface_getAltitude();
   void xAxis_getAltitude();
   void yAxis_getAltitude();
   void geostationary_getAltitude();

   // Testing getGravity functions
   void surface_getGravity();
   void fiveHundredK_getGravity();
   void twoThousandK_getGravity();


   bool closeEnough(double value, double test, double tolerance) const
   {
      double difference = value - test;
      return ((difference >= -tolerance) && (difference <= tolerance));
   }
};

