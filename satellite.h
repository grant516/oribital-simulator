#pragma once
#include <cassert>


class Satellite
{
private:

public:
   virtual double getAltitude(double x, double y) { return (0.0); }
   virtual double getGravity(double x, double y) { return (0.0);  }
};


class DummySatellite : public Satellite
{
public:
   DummySatellite() : Satellite() {}
   double getAltitude(double x, double y) { assert(false); return (0.0); }
   double getGravity(double x, double y) { assert(false); return (0.0); }
};