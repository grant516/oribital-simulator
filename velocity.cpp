#include "velocity.h"
#include <math.h>

void Velocity::updateVelocity(double ddx, double ddy, double t)
{
   dx += ddx * t;
   dy += ddy * t;
}

void Velocity::addVelocity(Velocity velocity)
{
   dx += velocity.getDx();
   dy += velocity.getDy();
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

void Velocity::hrzCompVel(double angle, double speed)
{
   dx = speed * sin(angle);
}

/*
* Vertical component of acceleration
* ddy = vertical component of acceleration
* a = total acceleration
* angle = angle (0° is up) of the direction of acceleration
*/
void Velocity::vertCompVel(double angle, double speed)
{
   dy = speed * cos(angle);
}