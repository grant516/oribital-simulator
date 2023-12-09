#pragma once
#include "satellite.h"

class Projectile : public Satellite
{
private:
   double time = 0;

public:
   Projectile(Velocity v, Direction dir, Position p) 
   {
      movementDirection = dir;
      time = 0;
      radius = 0.5;
      position = p;
      velocity = v;
   }
   void draw(ogstream& gout) const { gout.drawProjectile(position); }
   void expire();

private:
   void addFivePixels();
};

