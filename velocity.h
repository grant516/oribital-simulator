#pragma once
#include <cassert>

class Velocity
{
private:
   double dx;
   double dy;
   double speed;

public:
   virtual void setDx(double xSpeed) {}
   virtual void setDy(double ySpeed) {}
   virtual void updateVelocity(double ddx, double ddy, double t) {}

   virtual double getDx() { return(dx); }
   virtual double getDy() { return(dy); }
   virtual double getVelocity(double t) { return(0.0); }
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