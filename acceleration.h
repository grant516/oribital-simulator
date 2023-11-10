#pragma once
#include "velocity.h"

class Acceleration
{
private:
   float ddx;
   float ddy;

public:
   Acceleration() {}
   void assign(Velocity velocity);
   Velocity getVelocity(double time);
   float getDDx() { return ddx; }
   float getDDy() { return ddy; }
   void setDDx(double ddx);
   void setDDy(double ddy);
};