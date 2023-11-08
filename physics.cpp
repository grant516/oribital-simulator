#include "physics.h"
#include <math.h>
#include <iostream>
using namespace std;

/*
* Convert radians to degrees
*/
void Physics::radiansToDegrees(double& r)
{
   double pi = 2 * asin(1.0);
   angle = r + pi;
}

/*
* Distance Formula
* s = distance in meters (m)
* s0 = initial distance (m)
* v = velocity (m/s)
* timeFrame = time (s)
* a = acceleration (m/s^2)
*/
double Physics::distFormula(double s0, double v, double a) const
{
   double s = s0 + (v * timeFrame) + ((a * pow(timeFrame, 2)) / 2);
   return s;
}

/*
*Velocity with Constant Acceleration
* v = velocity in meters (m/s)
* v0 = initial velocity (m/s)
* a = acceleration (m/s^2)
* timeFrame = time (s)
*/
double Physics::velWConstA(double v0, double a) const
{
   double v = v0 + a * timeFrame;
   return v;
}

/*
* Horizontal Distance Formula
* xt = horizontal position at time t (m)
* x0 = initial horizontal position (m)
* dx = horizontal component of velocity (m/s)
* ddx = horizontal component of acceleration (m/s^2)
* timeFrame = time (s)
*/
double Physics::hrzDistFormula(double x0) const
{
   double xt = x0 + (dx * timeFrame) + ((ddx * pow(timeFrame, 2)) / 2);
   return xt;
}

/*
* Vertical Distance Formula
* vt = vertical position at time t (m)
* v0 = initial vertical position (m)
* dv = vertical component of velocity (m/s)
* ddv = vertical component of acceleration (m/s^2)
* timeFrame = time (s)
*/
double Physics::vertDistFormula(double y0) const
{
   double yt = y0 + (dy * timeFrame) + ((ddy * pow(timeFrame, 2)) / 2);
   return yt;
}

/*
* Horizontal Velocity with Constant Acceleration
* dxt = horizontal velocity at time t (m/s)
* dx0 = initial horizontal velocity (m/s)
* ddx = horizontal component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Physics::hrzVelWConstA()
{
   dx = dx + (ddx * timeFrame);
}

/*
* Vertical Velocity with Constant Acceleration
* dvt = vertical velocity at time t (m/s)
* dv0 = initial vertical velocity (m/s)
* ddv = vertical component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Physics::vertVelWConstA()
{
   dy = dy + (ddy * timeFrame);
}

/*
* Horizontal Position Constant Velocity
* xt = horizontal position at time t (m)
* x0 = initial horizontal position (m)
* dx = horizontal component of velocity (m/s)
* timeFrame = time (s)
*/
double Physics::hrzPosWConstV(double x0) const
{
   double xt = x0 + (dx * timeFrame);
   return xt;
}

/*
* Vertical Position Constant Velocity
* yt = vertical position at time t (m)
* y0 = initial vertical position (m)
* dy = vertical component of velocity (m/s)
* timeFrame = time (s)
*/
double Physics::vertPosWConstV(double y0) const
{
   double yt = y0 + (dy * timeFrame);
   return yt;
}

/*
* Motion with Constant velocity
* s = distance in meters (m)
* s0 = initial distance (m)
* v = velocity (m/s)
* timeFrame = time (s)
*/
double Physics::motionWConstV(double s0, double v) const
{
   double s = s0 + (v * timeFrame);
   return s;
}

/*
* Gravity Equation
* gh = magnitude of acceleration due to gravity at an altitude (h)
* g = gravity at sea level: 9.80665 m/s^2
* r = radius of the earth: 6,378,000 m
* h = height above the earth in meters
*/
double Physics::gravityEquation(double r, double h) const
{
   double gh = gravity * pow((r / (r + h)), 2);
   return gh;
}

/*
* Height above the Earth
* h = height above the earth in meters
* x = horizontal position of the satellite where the center of the earth is 0
* y = vertical position of the satellite where the center of the earth is 0
* r = radius of the earth: 6,378,000 m
*/
double Physics::htAboveEarth(double x, double y, double r) const
{
   double h = sqrt(pow(x, 2) + pow(y, 2)) - r;
   return h;
}

/* 
* Direction of Gravity Pull
* d = direction of the pull of gravity, in radians
* xe = horizontal position of the center of the earth: 0 m
* ye = vertical position of the center of the earth: 0 m
* xs = horizontal position of the satellite in meters
* ys = vertical position of the satellite in meters
*/
double Physics::dirGravityPull(double xe, double ye, double xs, double ys) const
{
   double d = atan2(xe - xs, ye - ys);
   return d;
}

/*
* Horizontal component of acceleration
* ddx = horizontal component of acceleration
* a = total acceleration
* angle = angle (0° is up) of the direction of acceleration
*/
void Physics::hrzCompAccel(double a)
{
   ddx = a * sin(angle);
}

/*
* Vertical component of acceleration
* ddy = vertical component of acceleration
* a = total acceleration
* angle = angle (0° is up) of the direction of acceleration
*/
void Physics::vertCompAccel(double a)
{
   ddy = a * cos(angle);
}

/*
* Rotation Speed
* rf = rotation of the earth in radians
  for one frame
* frameRate = number of frames per second.
  30 frames per second in our case
* td = how much faster time passes in the 
  simulator than in the real world
* secondsDay = number of seconds
  for the earth to make one rotation
*/
double Physics::rotateSpeed(double frameRate, double td, double secondsDay) const
{
   double pi = 2 * asin(1.0);
   double rf = -((2 * pi) / frameRate) * (td / secondsDay);
   return rf;
}

/*
* Time Dilation
* td = time dilation, which is the ratio of
  simulator time to real-world time
* hoursDay = number of hours in a day,
  24 in the case of earth
* minutesHour = number of minutes
  in an hour, which is 60 in our case
*/
double Physics::timeDilation(double hoursDay, double minutesHour) const
{
   double td = hoursDay * minutesHour;
   return td;
}

/*
* Time Per Frame
* tpf = time per frame, which is
  real-world time in seconds
  for each frame in the simulator
* td = time dilation
* frameRate = number of frames in the simulator
  per second, 30 in our case
*/
double Physics::timePerFrame(double td, double frameRate) const
{
   double tdf = td / frameRate;
   return tdf;
}