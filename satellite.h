#pragma once
#include <cassert>
#include <list>
#include "velocity.h"
#include "position.h"
#include "direction.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "acceleration.h"

using namespace std;

class Satellite
{
protected:
   Position launchPosition;
   Velocity velocity;
   Position position;
   Direction movementDirection;
   Direction facingDirection;
   Acceleration acceleration;
   bool dead = false;
   double radius;
   double numFragments;
   double expireTime = 70;

public:
   Satellite() {}
   Satellite(Position p, Direction d) 
   {
      position = p;
      movementDirection = d;
      facingDirection = d;
   }

   virtual double getRadius() const { return radius; };
   virtual bool isDead() const { return dead; };
   virtual Position getPosition() const { return position; };
   virtual void kill();
   virtual void draw(ogstream& gout) const {};
   virtual void updatePosition(double time, double planetRadius, 
      double planetGravity);
   virtual void updateMovementDirection();
   virtual void updateFacingDirection() {};
   virtual Direction getFacingDirection() const { return facingDirection; };
   virtual Direction getMovementDirection() const { return movementDirection; }
   virtual Velocity getVelocity() const { return velocity; };
   virtual void expire() {};
   virtual Position getLaunchPosition(int distance, Direction difference);
   virtual void destroy(list<Satellite*>& satellites) {};

protected:
   virtual double getHtAbovePlanet(double planetRadius) const;
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