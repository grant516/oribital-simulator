#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "parts.h"
#include "projectile.h"
#include "fragment.h"
#include <list>
using namespace std;


/*************************************************************************
 * Whole
 * This class is the base class for all whole satellites. It inherits from 
 * the Satellite class. It is used to organize all whole satellites together.
 *************************************************************************/
class Whole : public Satellite
{
public:
   Whole() {};
   void destroy(list<Satellite*>& satellites) {};

protected:
   virtual Direction offsetDirection();
   virtual Velocity boostVelocity(Velocity vel, Direction dir);
};

/*************************************************************************
 * Sputnik
 * First satellite ever launched into space.
 *************************************************************************/
class Sputnik : public Whole
{
public:
   Sputnik() {}
   Sputnik(Position p, Direction d, Velocity v)
   {
      position = p;
      movementDirection = d;
      facingDirection = d;
      velocity = v;
      radius = 4; // pixels
      numFragments = 4;
   }

   void destroy(list<Satellite*>& satellites);
   void updateFacingDirection();
   void draw(ogstream& gout) const;
};


/*************************************************************************
 * GPS
 * Global Positioning System. We'd be lost without it.
 *************************************************************************/
class GPS : public Whole
{
public:
   GPS() {}
   GPS(Position p, Direction d, Velocity v)
   {
      position = p;
      movementDirection = d;
      facingDirection = d;
      velocity = v;
      radius = 12; // pixels
      numFragments = 2;
   }

   void updateFacingDirection();
   void destroy(list<Satellite*>& satellites);
   void draw(ogstream& gout) const;
};


/*************************************************************************
 * Hubble
 * Hubble Space Telescope. Takes cool pictures.
 *************************************************************************/
class Hubble : public Whole
{
public:
   Hubble(Position p, Direction d, Velocity v)
   {
      position = p;
      movementDirection = d;
      facingDirection = facingDirection = 0.5;
      velocity = v;
      radius = 10; // pixels
      numFragments = 0;
   }
   
   void updateFacingDirection();
   void draw(ogstream& gout) const;
   void destroy(list<Satellite*>& satellites);
};


/*************************************************************************
 * Dragon
 * Crew Dragon Spacecraft. Takes people to space (probably shouldn't shoot 
 * it down).
 *************************************************************************/
class Dragon : public Whole
{
public:
   Dragon(Position p, Direction d, Velocity v)
   {
      position = p;
      movementDirection = d;
      facingDirection = d;
      velocity = v;
      radius = 7; // pixels
      numFragments = 2;
   }

   void draw(ogstream& gout) const;
   void destroy(list<Satellite*>& satellites);
};


/*************************************************************************
 * Starlink
 * Thank you Elon Musk, very cool!
 *************************************************************************/
class Starlink : public Whole
{
public:
   Starlink(Position p, Direction d, Velocity v)
   {
      position = p;
      movementDirection = d;
      facingDirection = d;
      velocity = v;
      radius = 6; // pixels
      numFragments = 2;
   }

   void draw(ogstream& gout) const;
   void destroy(list<Satellite*>& satellites);
};


/*************************************************************************
 * Ship
 * Also known as the Starchaser. Controlled by the player.
 *************************************************************************/
class Ship : public Whole
{
public:
   Ship(Position p, Direction d, Velocity v)
   {
      position = p;
      movementDirection = d;
      facingDirection = d;
      velocity = v;
      radius = 10; // pixels
      numFragments = 0;
   }
   void draw(ogstream& gout) const;

   void updatePosition(double time, double planetRadius, double planetGravity);

   void fireMainThruster() { thrusterOn = true; }
   void stopMainThruster() { thrusterOn = false; }
   void fireLeftThruster() { facingDirection.rotate(-0.1); }
   void fireRightThruster() { facingDirection.rotate(0.1); }
   void fireProjectile(list<Satellite*>& satellites);

private:
   bool thrusterOn = false;
};