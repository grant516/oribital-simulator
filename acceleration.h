#pragma once
#include "velocity.h"

class Acceleration
{
private:
   double ddx;
   double ddy;

public:
   Acceleration() { ddx = 0; ddy = 0; }
   void assign(Velocity velocity) {}
   Velocity getVelocity(double time) {}
   double getDDx() { return ddx; }
   double getDDy() { return ddy; }
   void setDDx(double accelX) { ddx = accelX; }
   void setDDy(double accelY) { ddy = accelY; }

   void hrzCompAccel(double a, double angle);
   void vertCompAccel(double a, double angle);
   /*
   * Gravity Equation
   * gh = magnitude of acceleration due to gravity at an altitude (h)
   * gravity = gravity at sea level: 9.80665 m/s^2 for Earth
   * r = radius of the earth: 6,378,000 m
   * h = height above the earth in meters
   */
   double gravityEquation(double r, double h, double gravity) const;
};