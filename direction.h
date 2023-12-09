#pragma once
#include <math.h>

#define PI 3.141592653589793238463

class Direction
{
private:
   double radians;

public:
   Direction() { radians = 0.0; }
   Direction(double radians) : radians(radians) {}
   
   void setRadians(double rad) { radians = rad; }
   void setDegrees(double degrees) { radians = degrees * PI / 180.0; }
   void setDxDy(double dx, double dy) { radians = atan2(dy, dx); }
   void setUp() { radians = 0.0; }
   void setDown() { radians = PI; }
   void setLeft() { radians = 3.0 * PI / 2.0; }
   void setRight() { radians = PI / 2; }
   void rotate(double amount) { radians += amount; }

   double getRadians() const { return radians; }
   double getDegrees() const { return radians * 180.0 / PI ; }
   double getDx() const { return cos(radians); }
   double getDy() const { return sin(radians); }
};

