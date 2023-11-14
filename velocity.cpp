#include "velocity.h"

void Velocity::updateVelocity(double ddx, double ddy, double t)
{
   dx += ddx * t;
   dy += ddy * t;
}