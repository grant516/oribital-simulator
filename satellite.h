#pragma once
#include <cassert>
#include "velocity.h"
#include "position.h"
#include "direction.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "acceleration.h"

class Satellite
{
protected:
   Velocity velocity;
   Position position;
   Direction movementDirection;
   Direction facingDirection;
   Acceleration acceleration;
   bool dead = false;
   double radius;
   double numFragments;
   double planetRadius = 6378000.0; // These should be removed eventually because they belong to Earth
   double gravity = -9.80665; // --> this too

public:
   Satellite() {}
   Satellite(Position p, Direction d) 
   {
      position = p;
      movementDirection = d;
      facingDirection = d;
   }

   virtual double getRadius() { return radius; }
   virtual bool isDead() { return dead; }
   virtual Position getPosition() { return position; }
   virtual void kill();
   virtual void draw(ogstream &gout);
   virtual void movePosition(double time, double planetRadius, double planetGravity);
   virtual void moveFacingDirection();
   virtual double getAltitude(double x, double y);
   virtual double getGravity(double x, double y);
   virtual Direction getFacingDirection() { return facingDirection; }
   virtual Direction getMovementDirection() { return movementDirection; }
   virtual Velocity getVelocity() { return velocity; }
   virtual void setPosition(Position p) { position = p; }
   virtual void setMovementDirection(Direction d) { movementDirection = d; }
   virtual Position getFrontPosition();

protected:
   virtual double getHtAbovePlanet(double planetRadius);
   virtual void hrzDistFormula(double timeFrame);
   virtual void vertDistFormula(double timeFrame);
   virtual double dirGravityPull(double xe, double ye);
};


class DummySatellite : public Satellite
{
public:
   DummySatellite() : Satellite() {}
   double getAltitude(double x, double y) { assert(false); return (0.0); }
   double getGravity(double x, double y) { assert(false); return (0.0); }
};