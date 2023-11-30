#include "whole.h"

// GPS Functions

void GPS::draw(ogstream& gout)
{
   gout.drawGPS(position, direction.getRadians());
}


// Hubble Functions

void Hubble::draw(ogstream& gout)
{
   gout.drawHubble(position, direction.getRadians());
}