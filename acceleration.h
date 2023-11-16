#pragma once
#include "velocity.h"

class Acceleration
{
private:
   double ddx;
   double ddy;

public:
   Acceleration() {}
   void assign(Velocity velocity) {}
   Velocity getVelocity(double time) {}
   double getDDx() { return ddx; }
   double getDDy() { return ddy; }
   void setDDx(double accelX) { ddx = accelX; }
   void setDDy(double accelY) { ddy = accelY; }
};