#include "whole.h"

// GPS Functions

void GPS::draw(ogstream& gout)
{
   gout.drawGPS(position, direction.getRadians());
}