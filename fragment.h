#pragma once
#include "satellite.h"
#include "uiDraw.h"



class Fragment : public Satellite
{
private:
   double time = 0;

public:
   Fragment(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      facingDirection = dir;
      velocity = vel;
      radius = 0.5;
   };

   void draw(ogstream& gout) { gout.drawFragment(position, facingDirection.getRadians()); }
   void expire();
};