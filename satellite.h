#pragma once
#include <cassert>
#include "velocity.h"
#include "position.h"
#include "direction.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Satellite
{
private:
   Velocity velocity;
   Position position;
   Direction direction;
   double angularVelocity;
   bool dead = false;
   double radius;

   double planetRadius = 6378000.0; // These should be removed eventually because they belong to Earth
   double gravity = -9.80665; // --> this too

public:
   Satellite() {}
   virtual double getRadius() { return radius; }
   virtual bool isDead() { return dead; }
   virtual Position getPosition() { return position; }
   virtual void kill();
   virtual void draw();
   virtual void move(double time);
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