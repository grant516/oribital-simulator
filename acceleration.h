#pragma once
#include "velocity.h"

class Acceleration
{
private:
   double ddx;
   double ddy;

public:
   Acceleration() { ddx = 0; ddy = 0; }
   double getDDx() const { return ddx; }
   double getDDy() const { return ddy; }
   void setDDx(double accelX) { ddx = accelX; }
   void setDDy(double accelY) { ddy = accelY; }
   void hrzCompAccel(double a, double angle);
   void vertCompAccel(double a, double angle);
   double gravityEquation(double r, double h, double gravity) const;
};