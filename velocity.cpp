#include "velocity.h"

void Velocity::updateVelocity(double ddx, double ddy, double t)
{
   dx += ddx * t;
   dy += ddy * t;
}

/*
* Horizontal Velocity with Constant Acceleration
* dxt = horizontal velocity at time t (m/s)
* dx0 = initial horizontal velocity (m/s)
* ddx = horizontal component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Velocity::hrzVelWConstA(double ddx, double time)
{
   dx = dx + (ddx * time);
}

/*
* Vertical Velocity with Constant Acceleration
* dvt = vertical velocity at time t (m/s)
* dv0 = initial vertical velocity (m/s)
* ddv = vertical component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Velocity::vertVelWConstA(double ddy, double time)
{
   dy = dy + (ddy * time);
}