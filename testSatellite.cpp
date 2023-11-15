#include "TestSatellite.h"

// Testing getAltitude functions
void TestSatellite::surface_getAltitude()
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

void TestSatellite::xAxis_getAltitude()
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

void TestSatellite::yAxis_getAltitude()
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

void TestSatellite::geostationary_getAltitude()
{
   // setup
   Satellite satellite;
   Position position;
   position.setMetersX(29814450.3);
   position.setMetersY(29814450.3);

   // exercise
   double alt = satellite.getAltitude(position.getMetersX(), position.getMetersY());

   // verify
   assert(closeEnough(alt, 35786000.0, 0.1));
   //assert(alt == 35786000.0);

   // teardown
}

// Testing getGravity functions
void TestSatellite::surface_getGravity()
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

void TestSatellite::fiveHundredK_getGravity()
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

void TestSatellite::twoThousandK_getGravity()
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