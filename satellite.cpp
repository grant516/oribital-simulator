#include "satellite.h"
#include <math.h>

/*
* This function is responsible for setting the satellite to dead
* after it collides with another object.
*/
void Satellite::kill()
{
   dead = true;
}

/*
* This function is responsible for how the satellites move around the planet.
* it needs to know the time, radius or the planet it orbits, and the gravity
* of the planet it orbits as well.
*/
void Satellite::updatePosition(double time, double const planetRadius, 
   double const planetGravity)
{
   // get the height away from the earth
   double height = getHtAbovePlanet(planetRadius);

   // gravity equation
   // Use Acceleration
   double currentGravity = acceleration.gravityEquation(planetRadius, 
      height, planetGravity);

   // Get radians angle
   double rad = dirGravityPull(0.0, 0.0) + PI;

   // Update the movement direction
   acceleration.hrzCompAccel(currentGravity, rad);
   acceleration.vertCompAccel(currentGravity, rad);

   // Update the velocity
   velocity.hrzVelWConstA(acceleration.getDDx(), time);
   velocity.vertVelWConstA(acceleration.getDDy(), time);

   // Update the position
   hrzDistFormula(time);
   vertDistFormula(time);
}

/*
* This function is responsible for the direction of that the satellite is
* facing as it travels through the void we call space.
*/
void Satellite::updateMovementDirection()
{
   movementDirection.setRadians(dirGravityPull(0.0, 0.0) + PI / 2); 
}


/*
* Determines the position of a part or projectile that is launched from the
* satellite.
*/
Position Satellite::getLaunchPosition(int distance, Direction &difference)
{
   double x = position.getPixelsX() + distance * 
      sin(facingDirection.getRadians() + difference.getRadians());
   double y = position.getPixelsY() + distance * 
      cos(facingDirection.getRadians() + difference.getRadians());
   launchPosition.setPixelsX(x);
   launchPosition.setPixelsY(y);

   return launchPosition;
}

/*
* Height above the Earth
* h = height above the earth in meters
* x = horizontal position of the satellite where the center of the earth is 0
* y = vertical position of the satellite where the center of the earth is 0
* planetRadius = radius of the planet (earth: 6,378,000 m)
*/
double Satellite::getHtAbovePlanet(double planetRadius) const
{
   double h = sqrt((position.getMetersX() * position.getMetersX()) 
      + (position.getMetersY() * position.getMetersY())) - planetRadius;
   return h;
}

/*
* Distance Formula
* pt = horizontal position at time t (m)
* x0 = initial horizontal position (m)
* dx = horizontal component of velocity (m/s)
* ddx = horizontal component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Satellite::hrzDistFormula(double timeFrame)
{
   double xt = position.getMetersX() + (velocity.getDx() * timeFrame)
      + ((acceleration.getDDx() * (timeFrame * timeFrame)) / 2);
   position.setMetersX(xt);
}

/*
* Vertical Distance Formula
* vt = vertical position at time t (m)
* v0 = initial vertical position (m)
* dv = vertical component of velocity (m/s)
* ddv = vertical component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Satellite::vertDistFormula(double timeFrame)
{
   double yt = position.getMetersY() + (velocity.getDy() * timeFrame)
      + ((acceleration.getDDy() * (timeFrame * timeFrame)) / 2);
   position.setMetersY(yt);
}

/*
* Direction of Gravity Pull
* d = direction of the pull of gravity, in radians
* xe = horizontal position of the center of the earth: 0 m
* ye = vertical position of the center of the earth: 0 m
* xs = horizontal position of the satellite in meters
* ys = vertical position of the satellite in meters
*/
double Satellite::dirGravityPull(double xe, double ye)
{
   double d = atan2(xe - position.getMetersX(), ye - position.getMetersY());
   return d;
}