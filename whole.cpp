#include "whole.h"

void Whole::destroy(list<Satellite*>& satellites)
{
   /*
   
   // create fragment for numFragments
   for (int i = 0; i < numFragments; i++)
   {
      // create a fragment
      Fragment* f = new Fragment(position, movementDirection, velocity);

      // add to list
      satellites.emplace_back(*f);
   }
   */
}

Position Whole::offsetPosition(Position pos)
{
   // Set x and y 5 pixels away randomly
   pos.setPixelsX(pos.getPixelsX() + random(-25, 25));
   pos.setPixelsY(pos.getPixelsY() + random(-25, 25));

   return pos;
}


// SPUTNIK FUNCTIONS

void Sputnik::destroy(list<Satellite*>& satellites)
{
}

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


void GPS::destroy(list<Satellite*>& satellites)
{
   // create all the gps parts
   GPSCenter* center = new GPSCenter(offsetPosition(position), velocity, movementDirection);
   GPSLeft* left = new GPSLeft(offsetPosition(position), velocity, movementDirection);
   GPSRight* right = new GPSRight(offsetPosition(position), velocity, movementDirection);

   // add to list
   satellites.emplace_back(center);
   satellites.emplace_back(left);
   satellites.emplace_back(right);
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


/*
* Dragon::draw
* Uses the drawCrewDragon function from uiDraw.
*/
void Dragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(position, facingDirection.getRadians());
}


// STARLINK FUNCTIONS


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
* This function determines the front of the ship to allow us to shoot
* projectiles from the front of the ship.
*/
void Ship::setFrontPosition()
{
   //Position frontPosition = position;

   double x = position.getPixelsX() + 19 * sin(facingDirection.getRadians());
   double y = position.getPixelsY() + 19 * cos(facingDirection.getRadians());
   frontPosition.setPixelsX(x);
   frontPosition.setPixelsY(y);

  //return frontPosition;
}

void Ship::fireProjectile(list<Satellite*>& satellites)
{
   Velocity bulletVelocity;
   bulletVelocity.hrzCompVel(getFacingDirection().getRadians(), 9000);
   bulletVelocity.vertCompVel(getFacingDirection().getRadians(), 9000);
   bulletVelocity.addVelocity(getVelocity());

   setFrontPosition();

   Projectile* p = new Projectile(bulletVelocity, getFacingDirection(),
      frontPosition);

   satellites.emplace_back(p);
}

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
