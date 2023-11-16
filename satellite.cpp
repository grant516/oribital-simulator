#include "satellite.h"
#include <math.h>

double Satellite::getAltitude(double x, double y)
{
   double h = sqrt((x * x) + (y * y)) - earthRadius;
   return h;
}

double Satellite::getGravity(double x, double y)
{
   double h = getAltitude(x, y);
   double gh = gravity * ((earthRadius / (earthRadius + h)) * 
      (earthRadius / (earthRadius + h)));
   return gh;
}