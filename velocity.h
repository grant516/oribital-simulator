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

   void assign(Velocity velocity) {}

   virtual double getDx() { return(dx); }
   virtual double getDy() { return(dy); }

   virtual double getVelocity(double t) { return(0.0); } // TODO: implement this
   //Direction getDirection() {} // TODO: implement this

   virtual void setDx(double xSpeed) { dx = xSpeed; }
   virtual void setDy(double ySpeed) { dy = ySpeed; }
   //void setSpeed(double speed) {} // TODO: implement this
   //void setMovementDirection(Direction direction) {} // TODO: implement this

   void addDx(double dxAdded) { dx += dxAdded; }
   void addDy(double dyAdded) { dy += dyAdded; }
   void addVelocity(Velocity velocity);
   virtual void updateVelocity(double ddx, double ddy, double t);

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