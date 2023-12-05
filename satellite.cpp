#include "satellite.h"
#include <math.h>

void Satellite::kill()
{
   dead = true;
}

void Satellite::draw(ogstream &gout)
{

}


void Satellite::movePosition(double time, double planetRadius, double planetGravity)
{
   // calculate earth's gravity pull for both ddx and ddy
   // get the height away from the earth
   // Use Position
   double height = getHtAbovePlanet(planetRadius);

   // gravity equation
   // Use Acceleration
   double currentGravity = acceleration.gravityEquation(planetRadius, height, planetGravity);

   // Get radians angle
   // Use Direction
   double rad = dirGravityPull(0.0, 0.0) + PI;

   // Use Acceleration
   acceleration.hrzCompAccel(currentGravity, rad);
   acceleration.vertCompAccel(currentGravity, rad);

   // use Velocity
   velocity.hrzVelWConstA(acceleration.getDDx(), time);
   velocity.vertVelWConstA(acceleration.getDDy(), time);

   // use Position
   hrzDistFormula(time);
   vertDistFormula(time);
}


void Satellite::moveFacingDirection()
{
   facingDirection.setRadians(dirGravityPull(0.0, 0.0) + PI / 2); // Face the earth
}

double Satellite::getAltitude(double x, double y)
{
   double h = sqrt((x * x) + (y * y)) - planetRadius;
   return h;
}

double Satellite::getGravity(double x, double y)
{
   double h = getAltitude(x, y);
   double gh = gravity * ((planetRadius / (planetRadius + h)) * 
      (planetRadius / (planetRadius + h)));
   return gh;
}


Position Satellite::getFrontPosition()
{
   Position frontPosition = position;

   int x = position.getPixelsX() + 19 * sin(facingDirection.getRadians());
   int y = position.getPixelsY() + 19 * cos(facingDirection.getRadians());
   frontPosition.setPixelsX(x);
   frontPosition.setPixelsY(y);

   return frontPosition;
}

/*
* Height above the Earth
* h = height above the earth in meters
* x = horizontal position of the satellite where the center of the earth is 0
* y = vertical position of the satellite where the center of the earth is 0
* planetRadius = radius of the planet (earth: 6,378,000 m)
*/
double Satellite::getHtAbovePlanet(double planetRadius)
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