#include "satellite.h"
#include <math.h>

void Satellite::kill()
{
   dead = true;
}

void Satellite::draw()
{

}

void Satellite::move(double time)
{
}

double Satellite::getAltitude(double x, double y)
{
   double h = sqrt((x * x) + (y * y)) - planetRadius;
   return h;
}

double Satellite::getGravity(double x, double y)
{
   double h = getAltitude(x, y);
   double gh = gravity * ((planetRadius / (planetRadius + h)) * 
      (planetRadius / (planetRadius + h)));
   return gh;
}