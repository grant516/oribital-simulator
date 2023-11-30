#pragma once
#include "satellite.h"
#include "uiDraw.h"

class Whole : public Satellite
{
public:
   Whole() {};
};

// Sputnik Class
class Sputnik : public Whole
{
public:
   Sputnik() {}
   Sputnik(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
      radius = 4; // pixels
      numFragments = 4;
   }
   void draw(ogstream& gout);
};


// GPS Class
class GPS : public Whole
{
public:
   GPS() {}
   GPS(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
      radius = 12; // pixels
      numFragments = 2;
   }
   void draw(ogstream& gout);
};


// Hubble Class
class Hubble : public Whole
{
public:
   Hubble(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
      radius = 10; // pixels
      numFragments = 0;
   }
   void draw(ogstream& gout);
};


// Dragon Class
class Dragon : public Whole
{
public:
   Dragon(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
      radius = 7; // pixels
      numFragments = 2;
   }
   void draw(ogstream& gout);
};


// Starlink Class
class Starlink : public Whole
{
public:
   Starlink(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
      radius = 6; // pixels
      numFragments = 2;
   }
   void draw(ogstream& gout);
};


// Ship Class (Dreamchaser)
class Ship : public Whole
{
public:
   Ship(Position p, Direction d, Velocity v)
   {
      position = p;
      direction = d;
      velocity = v;
      radius = 10; // pixels
      numFragments = 0;
   }
   void draw(ogstream& gout);

private:
   bool thrusterOn = false;
};