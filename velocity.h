#pragma once
#include <cassert>

class Velocity
{
private:
   double dx;
   double dy;

public:
   Velocity() { dx = 0; dy = 0; };

   Velocity(double vx, double vy) 
   { 
      dx = vx; 
      dy = vy; 
   }

   virtual double getDx() const { return(dx); }
   virtual double getDy() const { return(dy); }
   virtual void setDx(double xSpeed) { dx = xSpeed; }
   virtual void setDy(double ySpeed) { dy = ySpeed; }
   virtual void updateVelocity(double ddx, double ddy, double t);

   void addVelocity(Velocity &velocity);
   void hrzVelWConstA(double ddx, double time);
   void vertVelWConstA(double ddy, double time);
   void hrzCompVel(double angle, double speed);
   void vertCompVel(double angle, double speed);
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