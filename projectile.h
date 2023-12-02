#pragma once
#include "satellite.h"

class Projectile : public Satellite
{
private:
   double time;

public:
   Projectile(Velocity v, Direction dir, Position p) 
   {
      movementDirection = dir;
      time = 0;
      radius = 0.5;
      position = p;
      velocity.hrzCompVel(dir.getRadians(), 9000);
      velocity.vertCompVel(dir.getRadians(), 9000);
      velocity.addVelocity(v);
   }
   void draw(ogstream gout) { gout.drawProjectile(position); }
   void exprire();

private:
   void addFivePixels();
};

