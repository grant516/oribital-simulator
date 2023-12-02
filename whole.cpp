#include "whole.h"

Position Whole::offsetPosition(Position pos)
{
   // Set x and y 5 pixels away randomly
   pos.setPixelsX(pos.getPixelsX() + random(-5, 5));
   pos.setPixelsY(pos.getPixelsY() + random(-5, 5));

   return pos;
}


// SPUTNIK FUNCTIONS

void Sputnik::moveFacingDirection()
{
   facingDirection.rotate(0.05);
}

/*
* Sputnik::draw
* Uses the drawSputnik function from uiDraw.
*/
void Sputnik::draw(ogstream& gout)
{
   gout.drawSputnik(position, facingDirection.getRadians());
}


// GPS FUNCTIONS



vector<Part> GPS::getParts()
{
   vector<Part> parts;
   
   parts.push_back(GPSCenter());
   parts.push_back(GPSLeft());
   parts.push_back(GPSRight());

   return parts;
}

/*
* GPS::draw
* Uses the drawGPS function from uiDraw.
*/
void GPS::draw(ogstream& gout)
{
   gout.drawGPS(position, facingDirection.getRadians());
}


// HUBBLE FUNCTIONS


vector<Part> Hubble::getParts()
{
   vector<Part> parts;

   parts.push_back(HubbleTelescope());
   parts.push_back(HubbleComputer());
   parts.push_back(HubbleLeft());
   parts.push_back(HubbleRight());

   return parts;
}

void Hubble::moveFacingDirection()
{
   // Left empty, since it is overriding the function in the base class
   // This is because the hubble does not change direction
}

/*
* Hubble::draw
* Uses the drawHubble function from uiDraw.
*/
void Hubble::draw(ogstream& gout)
{
   gout.drawHubble(position, facingDirection.getRadians());
}


// DRAGON FUNCTIONS


vector<Part> Dragon::getParts()
{
   vector<Part> parts;

   parts.push_back(CrewDragonCenter());
   parts.push_back(CrewDragonLeft());
   parts.push_back(CrewDragonRight());

   return parts;
}

/*
* Dragon::draw
* Uses the drawCrewDragon function from uiDraw.
*/
void Dragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(position, facingDirection.getRadians());
}


// STARLINK FUNCTIONS



vector<Part> Starlink::getParts()
{
   vector<Part> parts;

   parts.push_back(StarlinkBody());
   parts.push_back(StarlinkArray());

   return parts;
}

/*
* Starlink::draw
* Uses the drawStarlink function from uiDraw.
*/
void Starlink::draw(ogstream& gout)
{
   gout.drawStarlink(position, facingDirection.getRadians());
}


// SHIP (DREAMCHASER) FUNCTIONS

/*
* Ship::draw
* Uses the drawShip function from uiDraw. 
* Also uses the thrusterOn variable so it knows when to draw the thruster.
*/
void Ship::draw(ogstream& gout)
{
   gout.drawShip(position, facingDirection.getRadians(), thrusterOn);
}


void Ship::movePosition(double time, double planetRadius, double planetGravity)
{
   // calculate earth's gravity pull for both ddx and ddy
   // get the height away from the earth
   // Use Position
   double height = getHtAbovePlanet(planetRadius);

   // gravity equation
   // Use Acceleration
   double currentGravity = acceleration.gravityEquation(planetRadius, height, planetGravity);

   // Get radians angle
   // Use Direction
   double rad = dirGravityPull(0.0, 0.0) + PI;

   // Use Acceleration
   acceleration.hrzCompAccel(currentGravity, rad);
   acceleration.vertCompAccel(currentGravity, rad);

   // Apply thrust in the direction of the ship
   if (thrusterOn)
   {
      // Use Acceleration
      acceleration.hrzCompAccel(2.0, facingDirection.getRadians());
      acceleration.vertCompAccel(2.0, facingDirection.getRadians());
   }

   // use Velocity
   velocity.hrzVelWConstA(acceleration.getDDx(), time);
   velocity.vertVelWConstA(acceleration.getDDy(), time);

   // use Position
   hrzDistFormula(time);
   vertDistFormula(time);
}

void Ship::moveFacingDirection()
{
   // Keep this empty, since it is overriding the function in the base class
   // This is because the ship changes direction based on input from the user
}