// Grant Shirley, Colby Hale

#include <cassert>      // for ASSERT
#include <list>        // for LIST
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include "satellite.h"
#include "star.h"
#include "earth.h"
#include "whole.h"
#include "projectile.h"
#include <math.h>
using namespace std;

#define STARSNUM 200

/*************************************************************************
 * Sim
 * Contains the elements needed for an instance of the simulation
 *************************************************************************/
class Sim
{
public:

   Sim(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
  
      sputnik(Position(-36515095.13, 21082000.0), Direction(), Velocity(2050.0, 2684.68)),
      gps0(Position(0.0, 26560000.0), Direction(), Velocity(-3880.0, 0.0)),
      gps1(Position(23001634.72, 13280000.0), Direction(), Velocity(-1940.00, 3360.18)),
      gps2(Position(23001634.72, -13280000.0), Direction(), Velocity(1940.00, 3360.18)),
      gps3(Position(0.0, -26560000.0), Direction(), Velocity(3880.0, 0.0)),
      gps4(Position(-23001634.72, -13280000.0), Direction(), Velocity(1940.00, -3360.18)),
      gps5(Position(-23001634.72, 13280000.0), Direction(), Velocity(-1940.00, -3360.18)),
      hubble(Position(0.0, -42164000.0), Direction(), Velocity(3100.0, 0.0)),
      dragon(Position(0.0, 8000000.0), Direction(), Velocity(-7900.0, 0.0)),
      starlink(Position(0.0, -13020000.0), Direction(), Velocity(5800.0, 0.0)),
      ship(Position(-45000000.0, 45000000.0), Direction(), Velocity(0.0, -2000.0)) 

   {
      for (int i = 0; i < STARSNUM; i++)
      {
         stars[i].reset(random(-500, 500), random(-500, 500));
      }
      
      time = (hoursPerDay * minutesPerHour) / framesPerSecond;
   }

   double hoursPerDay = 24;
   double minutesPerHour = 60;
   double framesPerSecond = 30;
   double time;
   Position ptUpperRight;

   Sputnik sputnik;
   GPS gps0;
   GPS gps1;
   GPS gps2;
   GPS gps3;
   GPS gps4;
   GPS gps5;
   Hubble hubble;
   Dragon dragon;
   Starlink starlink;
   Ship ship;

   Earth earth;
   Star stars[STARSNUM];

   // List of satellites
   list<Satellite*> satellites = 
   {
      &ship,
      &sputnik,
      &gps0,
      &gps1,
      &gps2,
      &gps3,
      &gps4,
      &gps5,
      &hubble,
      &dragon,
      &starlink
   };
   
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Sim* pSim = (Sim*)p;

   //
   // INPUT
   //
   if (pSim->ship.isDead() == false)
   {
      // Get input
      if (pUI->isUp())
      {
         pSim->ship.fireMainThruster();
      }
      else
      {
         pSim->ship.stopMainThruster();
      }

      if (pUI->isRight())
      {
         pSim->ship.fireRightThruster();
      }

      if (pUI->isLeft())
      {
         pSim->ship.fireLeftThruster();
      }

      if (pUI->isSpace())
      {
         pSim->ship.fireProjectile(pSim->satellites);
      }
   }

   //
   // PHYSICS
   //

   for (auto sat = pSim->satellites.begin(); sat != pSim->satellites.end(); ++sat)
   {
      (*sat)->updatePosition(pSim->time, pSim->earth.getRadiusMeters(),
         pSim->earth.getGravity());
      (*sat)->updateMovementDirection();
      (*sat)->updateFacingDirection();
      (*sat)->expire();
   }

   //
   // COLLISIONS
   //
   for (auto sat1 = pSim->satellites.begin(); sat1 != pSim->satellites.end(); ++sat1)
   {
      sat1;
      Position sat1Pos = (*sat1)->getPosition();
      Position earthPos = pSim->earth.getPosition();
      double distance = sqrt(
         ((earthPos.getPixelsX() - sat1Pos.getPixelsX()) *
            (earthPos.getPixelsX() - sat1Pos.getPixelsX())) +
         ((earthPos.getPixelsY() - sat1Pos.getPixelsY()) *
            (earthPos.getPixelsY() - sat1Pos.getPixelsY()))
      );

      for (auto sat2 = pSim->satellites.begin(); sat2 != pSim->satellites.end(); ++sat2)
      {
         if (sat1 != sat2 && (!(*sat1)->isDead() && !(*sat2)->isDead()))
         {
            Position sat1Pos = (*sat1)->getPosition();
            Position sat2Pos = (*sat2)->getPosition();
            double distance = sqrt(
               ((sat2Pos.getPixelsX() - sat1Pos.getPixelsX()) *
                  (sat2Pos.getPixelsX() - sat1Pos.getPixelsX())) +
               ((sat2Pos.getPixelsY() - sat1Pos.getPixelsY()) *
                  (sat2Pos.getPixelsY() - sat1Pos.getPixelsY()))
            );

            if (distance <= ((*sat1)->getRadius() + (*sat2)->getRadius()))
            {
               // kill both satellites
               (*sat1)->kill();
               (*sat2)->kill();
            }
         }
      }

      if (distance <= ((*sat1)->getRadius() + pSim->earth.getRadiusPixels())
         && !(*sat1)->isDead())
      {
         (*sat1)->kill();
      }
   }

   // erase dead things
   for (auto sat = pSim->satellites.begin(); sat != pSim->satellites.end();)
   {
      if ((*sat)->isDead())
      {
         (*sat)->destroy(pSim->satellites);
         sat = pSim->satellites.erase(sat);
      }
      else
         ++sat;
   }

   // Rotate the Earth
   pSim->earth.rotate();


   //
   // DRAW
   //

   Position pt;
   ogstream gout(pt);

   for (int i = 0; i < STARSNUM; i++)
      pSim->stars[i].draw(gout);

   // Draw satellites
   for (auto sat : pSim->satellites)
      sat->draw(gout);

   // Draw the earth
   pSim->earth.draw(gout);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run Unit Test
   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Sim",   /* name on the window */
      ptUpperRight);

   // Initialize the Sim
   Sim sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);


   return 0;
}
