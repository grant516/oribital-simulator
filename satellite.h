#pragma once
#include <cassert>


class Satellite
{
private:

public:
   virtual double getAltitude(double x, double y);
   virtual double getGravity(double x, double y);
};


class DummySatellite : public Satellite
{
public:
   DummySatellite() : Satellite() {}
   double getAltitude() { assert(false); }
   double getGravity() { assert(false); }
};