#pragma once
#include "uiDraw.h"
#include "position.h"

#define PI 3.141592653589793238463

class Earth
{
private:
   Position position; // should be the default position, which is (0.0, 0.0)
   double planetRadius = 6378000.0;
   double gravity = -9.80665;
   double angle = 0.0;
   double angularVelocity = (2 * PI) / 1800;

public:
   double getRadius() { return planetRadius; }
   double getGravity() { return gravity; }
   void rotate() { angle -= angularVelocity; } // to be called once per frame
   void draw(ogstream &gout) { gout.drawEarth(position, angle); }
};

