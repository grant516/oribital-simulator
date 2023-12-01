#pragma once
#include <cassert>

class Velocity
{
private:
   double dx;
   double dy;

public:
   Velocity() { dx = 0; dy = 0; };
   Velocity(double dx, double dy) { this->dx = dx; this->dy = dy; }

   void assign(Velocity velocity) {}

   virtual double getDx() { return(dx); }
   virtual double getDy() { return(dy); }

   virtual double getVelocity(double t) { return(0.0); } // TODO: implement this
   //Direction getDirection() {} // TODO: implement this

   virtual void setDx(double xSpeed) { dx = xSpeed; }
   virtual void setDy(double ySpeed) { dy = ySpeed; }
   //void setSpeed(double speed) {} // TODO: implement this
   //void setDirection(Direction direction) {} // TODO: implement this

   void addDx(double dxAdded) { dx += dxAdded; }
   void addDy(double dyAdded) { dy += dyAdded; }
   //void add(Velocity velocity) {} // TODO: implement this, or is it the same as updateVelocity?
   virtual void updateVelocity(double ddx, double ddy, double t);
};

class DummyVelocity : public Velocity
{
public:
   DummyVelocity() : Velocity() {}
   void updateVelocity(double ddx, double ddy, double t) { assert(false); }
   virtual void setDx(double xSpeed) { assert(false); }
   virtual void setDy(double ySpeed) { assert(false); }

   virtual double getDx() { assert(false); return(0.0); }
   virtual double getDy() { assert(false); return(0.0); }
};