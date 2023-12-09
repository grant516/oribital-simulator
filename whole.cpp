#include "whole.h"


/*
* Whole::offsetDirection
* Adds a random angle between -90 and 90 degrees to the movement direction
*/
Direction Whole::offsetDirection()
{
   Direction newAngle;
   newAngle.setDxDy(velocity.getDx(), velocity.getDy());
   newAngle.setRadians(newAngle.getRadians() + random(-PI / 2, PI / 2));
   return newAngle;
}

/*
* Whole::boostVelocity
* Add between 5000 and 9000 m/s to the velocity
*/
Velocity Whole::boostVelocity(Velocity vel, Direction dir)
{
   //Direction mDirection;
   Velocity vel2;
   //mDirection.setDxDy(vel.getDx(), vel.getDy());
   vel2.hrzCompVel(dir.getRadians(), random(3000, 6000));
   vel2.vertCompVel(dir.getRadians(), random(3000, 6000));

   vel.addVelocity(vel2);
   return vel;
}


// SPUTNIK FUNCTIONS

/*
* Creates the sputnik parts when the sputnik is destroyed
*/
void Sputnik::destroy(list<Satellite*>& satellites)
{
   Direction myDirection;
   for (int i = 0; i < numFragments; i++)
   {
      myDirection = offsetDirection();
      satellites.emplace_back(new Fragment(getLaunchPosition(25, myDirection),
         boostVelocity(velocity, myDirection), myDirection));
   }

}

/*
* Rotates the sputnik visually
*/
void Sputnik::updateFacingDirection()
{
   facingDirection.rotate(0.05);
}

/*
* Sputnik::draw
* Uses the drawSputnik function from uiDraw.
*/
void Sputnik::draw(ogstream& gout) const
{
   gout.drawSputnik(position, facingDirection.getRadians());
}


// GPS FUNCTIONS

/*
* Rotates the gps visually
*/
void GPS::updateFacingDirection()
{
   facingDirection = movementDirection;
}

/*
* Creates the gps parts when the gps is destroyed
*/
void GPS::destroy(list<Satellite*>& satellites)
{
   // create all the gps parts
   Direction myDirection = offsetDirection();
   satellites.emplace_back(new GPSCenter(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(new GPSLeft(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(new GPSRight(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   for (int i = 0; i < numFragments; i++)
   {
      myDirection = offsetDirection();
      satellites.emplace_back(new Fragment(getLaunchPosition(25, myDirection), 
         boostVelocity(velocity, myDirection), myDirection));
   }

}


/*
* GPS::draw
* Uses the drawGPS function from uiDraw.
*/
void GPS::draw(ogstream& gout) const
{
   gout.drawGPS(position, facingDirection.getRadians());
}


// HUBBLE FUNCTIONS

/*
* Creates the hubble parts when the hubble is destroyed
*/
void Hubble::destroy(list<Satellite*>& satellites)
{
   // create all the hubble parts
   Direction myDirection = offsetDirection();
   satellites.emplace_back(
      new HubbleComputer(getLaunchPosition(25, myDirection), 
         boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(
      new HubbleTelescope(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(
      new HubbleLeft(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(
      new HubbleRight(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   for (int i = 0; i < numFragments; i++)
   {
      myDirection = offsetDirection();
      satellites.emplace_back(
         new Fragment(getLaunchPosition(25, myDirection), 
         boostVelocity(velocity, myDirection), myDirection));
   }

}

/*
* Rotates the hubble visually
*/
void Hubble::updateFacingDirection()
{
   // Left empty, since it is overriding the function in the base class
   // This is because the hubble does not change direction
}

/*
* Hubble::draw
* Uses the drawHubble function from uiDraw.
*/
void Hubble::draw(ogstream& gout) const
{
   gout.drawHubble(position, facingDirection.getRadians());
}


// DRAGON FUNCTIONS

/*
* Creates the dragon parts when the dragon is destroyed
*/
void Dragon::destroy(list<Satellite*>& satellites)
{
   // create all the dragon parts
   Direction myDirection = offsetDirection();
   satellites.emplace_back(
      new CrewDragonCenter(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(
      new CrewDragonLeft(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(
      new CrewDragonRight(getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   for (int i = 0; i < numFragments; i++)
   {
      myDirection = offsetDirection();
      satellites.emplace_back(
         new Fragment(getLaunchPosition(25, myDirection), 
         boostVelocity(velocity, myDirection), myDirection));
   }

}

/*
* Dragon::draw
* Uses the drawCrewDragon function from uiDraw.
*/
void Dragon::draw(ogstream& gout) const
{
   gout.drawCrewDragon(position, facingDirection.getRadians());
}


// STARLINK FUNCTIONS

/*
* Creates the starlink parts when the starlink is destroyed
*/
void Starlink::destroy(list<Satellite*>& satellites)
{
   // create all the Starlink parts
   Direction myDirection = offsetDirection();
   satellites.emplace_back(new StarlinkArray(
      getLaunchPosition(25, myDirection), 
      boostVelocity(velocity, myDirection), myDirection));

   myDirection = offsetDirection();
   satellites.emplace_back(new StarlinkBody(getLaunchPosition(25, myDirection),
      boostVelocity(velocity, myDirection), myDirection));

   for (int i = 0; i < numFragments; i++)
   {
      myDirection = offsetDirection();
      satellites.emplace_back(new Fragment(getLaunchPosition(25, myDirection), 
         boostVelocity(velocity, myDirection), myDirection));
   }

}

/*
* Starlink::draw
* Uses the drawStarlink function from uiDraw.
*/
void Starlink::draw(ogstream& gout) const
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

   Direction dir;
   Projectile* p = new Projectile(bulletVelocity, facingDirection,
      getLaunchPosition(19, dir));

   satellites.emplace_back(p);
}

/*
* Ship::draw
* Uses the drawShip function from uiDraw. 
* Also uses the thrusterOn variable so it knows when to draw the thruster.
*/
void Ship::draw(ogstream& gout) const
{
   gout.drawShip(position, facingDirection.getRadians(), thrusterOn);
}

/*
* Ship::updatePosition
* Calculates positional movement of the ship.
*/
void Ship::updatePosition(double time, double planetRadius, 
   double planetGravity)
{
   // calculate earth's gravity pull for both ddx and ddy
   // get the height away from the earth
   // Use Position
   double height = getHtAbovePlanet(planetRadius);

   // gravity equation
   // Use Acceleration
   double currentGravity = acceleration.gravityEquation(planetRadius, 
      height, planetGravity);

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
