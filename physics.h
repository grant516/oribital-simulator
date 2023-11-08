#pragma once
class Physics
{
private:
   double velocity;
   double acceleration;
   double ddx;
   double ddy;
   double dx;
   double dy;
   double gravity;
   double timeFrame;
   double angle;

public:
   // Set up the timeFrame data and the x and y velocity.
   Physics(double hoursDay, double minutesHour, double frameRate, 
      double velX, double velY, double g)
   {
      // Set the time data
      double timeDil = timeDilation(hoursDay, minutesHour);
      timeFrame = timePerFrame(timeDil, frameRate);
      gravity = g;

      dx = velX;
      dy = velY;
   }
   void radiansToDegrees(double& r);

   double distFormula(double s0, double v, double a) const;
   double velWConstA(double v0, double a) const;
   double hrzDistFormula(double x0) const;
   double vertDistFormula(double y0) const;
   void hrzVelWConstA();
   void vertVelWConstA();

   double hrzPosWConstV(double x0) const;
   double vertPosWConstV(double y0) const;

   double motionWConstV(double s0, double v) const;

   double gravityEquation(double r, double h) const;
   double htAboveEarth(double x, double y, double r) const;
   double dirGravityPull(double xe, double ye, double xs, double ys) const;
   void hrzCompAccel(double a);
   void vertCompAccel(double a);

   double rotateSpeed(double frameRate, double td, double secondsDay) const;

   double timeDilation(double hoursDay, double minutesHour) const;
   double timePerFrame(double td, double frameRate) const;

   double getTimeFrame() const { return timeFrame; }
};

