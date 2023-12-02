#pragma once
#include "satellite.h"
#include "uiDraw.h"



class Fragment : public Satellite
{
public:
   Fragment() {};

   void draw(ogstream& gout) { gout.drawFragment(position, facingDirection.getRadians()); }

};