#pragma once
#include "satellite.h"
#include "uiDraw.h"

class Whole : public Satellite
{
public:
   Whole() {};
};

// GPS Class
class GPS : public Whole
{
public:
   GPS() {}
   GPS(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
   }
   void draw(ogstream& gout);

   // radius of the GPS is 12px
   double getRadius() { return 12; }
};

// Hubble Class
class Hubble : public Whole
{
public:
   Hubble(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
   }
   void draw(ogstream& gout);

   // radius of the hubble is 10px
   double getRadius() { return 10; }
};