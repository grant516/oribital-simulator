#pragma once
#include "satellite.h"
#include "uiDraw.h"



class Fragment : public Satellite
{
public:
   Fragment(Position pos, Direction dir, Velocity vel) 
   {
      position = pos;
      facingDirection = dir;
      velocity = vel;
      radius = 0.5;
   };

   void draw(ogstream& gout) { gout.drawFragment(position, facingDirection.getRadians()); }

};