#include "whole.h"



// SPUTNIK FUNCTIONS

/*
* Sputnik::draw
* Uses the drawSputnik function from uiDraw.
*/
void Sputnik::draw(ogstream& gout)
{
   gout.drawSputnik(position, direction.getRadians());
}


// GPS FUNCTIONS

/*
* GPS::draw
* Uses the drawGPS function from uiDraw.
*/
void GPS::draw(ogstream& gout)
{
   gout.drawGPS(position, direction.getRadians());
}


// HUBBLE FUNCTIONS

/*
* Hubble::draw
* Uses the drawHubble function from uiDraw.
*/
void Hubble::draw(ogstream& gout)
{
   gout.drawHubble(position, direction.getRadians());
}


// DRAGON FUNCTIONS

/*
* Dragon::draw
* Uses the drawCrewDragon function from uiDraw.
*/
void Dragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(position, direction.getRadians());
}


// STARLINK FUNCTIONS

/*
* Starlink::draw
* Uses the drawStarlink function from uiDraw.
*/
void Starlink::draw(ogstream& gout)
{
   gout.drawStarlink(position, direction.getRadians());
}


// SHIP (DREAMCHASER) FUNCTIONS

/*
* Ship::draw
* Uses the drawShip function from uiDraw. 
* Also uses the thrusterOn variable so it knows when to draw the thruster.
*/
void Ship::draw(ogstream& gout)
{
   gout.drawShip(position, direction.getRadians(), thrusterOn);
}
