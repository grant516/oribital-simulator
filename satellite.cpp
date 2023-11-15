#include "satellite.h"
#include <math.h>

double Satellite::getAltitude(double x, double y)
{
   double h = sqrt((x * x) + (y * y)) - earthRadius;
   return h;
}

double Satellite::getGravity(double x, double y)
{
   return 0.0;
}