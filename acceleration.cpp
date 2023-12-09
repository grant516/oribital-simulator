#include "acceleration.h"
#include <math.h>

/*
* Gravity Equation
* gh = magnitude of acceleration due to gravity at an altitude (h)
* gravity = gravity at sea level of the planet: 9.80665 m/s^2 for Earth
* r = radius of the earth: 6,378,000 m
* h = height above the earth in meters
*/
double Acceleration::gravityEquation(double r, double h, double gravity) const
{
   double gh = gravity * ((r / (r + h)) * (r / (r + h)));
   return gh;
}

/*
* Horizontal Component of Acceleration
* a = magnitude of acceleration
* angle = angle of acceleration
*/
void Acceleration::hrzCompAccel(double a, double angle)
{
   ddx = a * sin(angle);
}

/*
* Vertical Component of Acceleration
* a = magnitude of acceleration
* angle = angle of acceleration
*/
void Acceleration::vertCompAccel(double a, double angle)
{
   ddy = a * cos(angle);
}