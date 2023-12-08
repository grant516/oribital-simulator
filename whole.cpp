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

/*
* Whole::offsetPosition
* a
*/
Position Whole::offsetPosition(Position pos)
{
   // Set x and y 5 pixels away randomly
   pos.setPixelsX(pos.getPixelsX() + random(-25, 25));
   pos.setPixelsY(pos.getPixelsY() + random(-25, 25));

   return pos;
}

/*
* Whole::offsetDirection
* Adds a random angle between -90 and 90 degrees to the movement direction
*/
Direction Whole::offsetDirection(Direction dir)
{
   Direction newAngle;
   newAngle.setDegrees(random(-90, 90));
   newAngle.setRadians(newAngle.getRadians() + movementDirection.getRadians());

   return newAngle;
}

/*
* Whole::boostVelocity
* Add between 5000 and 9000 m/s to the velocity
*/
Velocity Whole::boostVelocity(Velocity vel)
{
   vel.hrzCompVel(movementDirection.getRadians(), random(5000, 9000));
   vel.vertCompVel(movementDirection.getRadians(), random(5000, 9000));
   return vel;
}


// SPUTNIK FUNCTIONS

void Sputnik::destroy(list<Satellite*>& satellites)
{
}

void Sputnik::updateFacingDirection()
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


void GPS::updateFacingDirection()
{
   facingDirection = movementDirection;
}

void GPS::destroy(list<Satellite*>& satellites)
{
   // create all the gps parts
   Direction myDirection = offsetDirection(movementDirection);
   GPSCenter* center = new GPSCenter(getLaunchPosition(25, myDirection), boostVelocity(velocity), myDirection);

   myDirection = offsetDirection(movementDirection);
   GPSLeft* left = new GPSLeft(getLaunchPosition(25, myDirection), boostVelocity(velocity), myDirection);

   myDirection = offsetDirection(movementDirection);
   GPSRight* right = new GPSRight(getLaunchPosition(25, myDirection), boostVelocity(velocity), myDirection);

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


void Hubble::updateFacingDirection()
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
* Ship::fireProjectile
* This is where the fun begins! Used for firing projectiles from the front of 
* the ship.
*/
void Ship::fireProjectile(list<Satellite*>& satellites)
{
   // Take the velocity of the ship and add 9000 to it
   Velocity bulletVelocity;
   bulletVelocity.hrzCompVel(facingDirection.getRadians(), 9000);
   bulletVelocity.vertCompVel(facingDirection.getRadians(), 9000);
   bulletVelocity.addVelocity(velocity);

   Projectile* p = new Projectile(bulletVelocity, facingDirection,
      getLaunchPosition(19, 0));

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

/*
* Ship::updatePosition
* Calculates positional movement of the ship.
*/
void Ship::updatePosition(double time, double planetRadius, double planetGravity)
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
