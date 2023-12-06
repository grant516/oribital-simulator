#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "parts.h"
#include "projectile.h"
#include <vector>
using namespace std;



/*************************************************************************
 * Whole
 * This class is the base class for all whole satellites. It inherits from the Satellite class.
 * It is used to organize all whole satellites together.
 *************************************************************************/
class Whole : public Satellite
{
public:
   Whole() {};

   virtual vector<Part> getParts() { vector<Part> parts; return parts; }
   Position offsetPosition(Position pos);
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

   void moveFacingDirection();
   void draw(ogstream& gout);
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

   vector<Part> getParts();
   void draw(ogstream& gout);
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
   
   vector<Part> getParts();
   void moveFacingDirection();
   void draw(ogstream& gout);
};


/*************************************************************************
 * Dragon
 * Crew Dragon Spacecraft. Takes people to space (probably shouldn't shoot it down).
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

   vector<Part> getParts();
   void draw(ogstream& gout);
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

   vector<Part> getParts();
   void draw(ogstream& gout);
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
   void draw(ogstream& gout);

   void movePosition(double time, double planetRadius, double planetGravity);
   void moveFacingDirection();

   void fireMainThruster() { thrusterOn = true; }
   void stopMainThruster() { thrusterOn = false; }
   void fireLeftThruster() { facingDirection.rotate(-0.1); }
   void fireRightThruster() { facingDirection.rotate(0.1); }

   Projectile* shootProjectile();

private:
   bool thrusterOn = false;
};