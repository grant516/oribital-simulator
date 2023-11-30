#include "whole.h"



// Sputnik Functions

void Sputnik::draw(ogstream& gout)
{
   gout.drawSputnik(position, direction.getRadians());
}


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


// Dragon Functions

void Dragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(position, direction.getRadians());
}


// Starlink Functions

void Starlink::draw(ogstream& gout)
{
   gout.drawStarlink(position, direction.getRadians());
}


// Ship (Dreamchaser) Functions

void Ship::draw(ogstream& gout)
{
   gout.drawShip(position, direction.getRadians(), thrusterOn);
}
