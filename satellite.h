#pragma once
#include <cassert>


class Satellite
{
private:
   double earthRadius = 6378000.0;
   double gravity = -9.80665;

public:
   virtual double getAltitude(double x, double y);
   virtual double getGravity(double x, double y);
};


class DummySatellite : public Satellite
{
public:
   DummySatellite() : Satellite() {}
   double getAltitude(double x, double y) { assert(false); return (0.0); }
   double getGravity(double x, double y) { assert(false); return (0.0); }
};