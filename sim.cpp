// Grant Shirley, Colby Hale, Bruce Li

#include <cassert>      // for ASSERT
#include <list>        // for LIST
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "physics.h"      // for PHYSICS
#include "test.h"
#include "satellite.h"
#include "star.h"
#include "earth.h"
#include "whole.h"
#include <math.h>
using namespace std;

/*************************************************************************
 * Sim
 * Contains the elements needed for an instance of the simulation
 *************************************************************************/
class Sim
{
public:
   // old stuff starts here
   Sim(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
  
      hubblePhysics(24, 60, 30, -3100.0, 0.0, -9.80665),
      sputnik(Position(-36515095.13, 21082000.0), Direction(), Velocity(2050.0, 2684.68)),
      gps0(Position(0.0, 26560000.0), Direction(), Velocity(-3880.0, 0.0)),
      gps1(Position(23001634.72, 13280000.0), Direction(), Velocity(-1940.00, 3360.18)),
      gps2(Position(23001634.72, -13280000.0), Direction(), Velocity(1940.00, 3360.18)),
      testing(Position(23001634.72, -13280000.0), Direction(), Velocity(1940.00, 3360.18)),
      gps3(Position(0.0, -26560000.0), Direction(), Velocity(3880.0, 0.0)),
      gps4(Position(-23001634.72, -13280000.0), Direction(), Velocity(1940.00, -3360.18)),
      gps5(Position(-23001634.72, 13280000.0), Direction(), Velocity(-1940.00, -3360.18)),
      hubble(Position(0.0, -42164000.0), Direction(), Velocity(3100.0, 0.0)),
      dragon(Position(0.0, 8000000.0), Direction(), Velocity(-7900.0, 0.0)),
      starlink(Position(0.0, -13020000.0), Direction(), Velocity(5800.0, 0.0)),
      ship(Position(-45000000.0, 45000000.0), Direction(), Velocity(0.0, -2000.0)) // Document says position should start at (-450px, 450px), but I guessed in setting it by meters. How many meters is 450px?

   {
      ptHubble.setMetersX(0.0);
      ptHubble.setMetersY(-42164000.0);
      
      angleShip = 0.0;
      phaseStar = 0;
   }

   Physics hubblePhysics;
   Position ptHubble;
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

   Ship testing;


   unsigned char phaseStar;

   double const planetRadius = 6378000;
   double angleShip;

   // old stuff ends here
   Earth earth;

   // List of satellites
   list<Satellite*> satellites = 
   {
      &sputnik,
      &gps0,
      &gps1,
      &gps2,
      &gps3,
      &gps4,
      &gps5,
      &hubble,
      &dragon,
      &starlink,
      &ship,
      &testing
   };


private:
   // array of Satellites
   // Satellite satellites[];
   // stars[];
   
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
   // perform all the game logic
   //

   //Physics
   double time = pSim->hubblePhysics.getTimeFrame();

   for (auto sat : pSim->satellites)
   {
      sat->move(time, pSim->earth.getRadius(), pSim->earth.getGravity());
   }
      

   // check for collisions
   //for (auto sat1 : pSim->satellites)
   for (auto sat1 = pSim->satellites.begin(); sat1 != pSim->satellites.end(); ++sat1)
   {
      //for (auto sat2 : pSim->satellites)
      for (auto sat2 = pSim->satellites.begin(); sat2 != pSim->satellites.end();)
      {
         if (sat1 != sat2)
         {
            Position sat1Pos = (*sat1)->getPosition();
            Position sat2Pos = (*sat2)->getPosition();
            double distance = sqrt(
               ((sat2Pos.getMetersX() - sat1Pos.getMetersX()) *
                  (sat2Pos.getMetersX() - sat1Pos.getMetersX())) +
               ((sat2Pos.getMetersY() - sat1Pos.getMetersY()) *
                  (sat2Pos.getMetersY() - sat1Pos.getMetersY()))
            );

            if (distance <= ((*sat1)->getRadius() + (*sat2)->getRadius()))
            {
               cout << "Collision happened!!!" << endl;
               sat1 = pSim->satellites.erase(sat1);
               sat2 = pSim->satellites.erase(sat2);
            }
            else
            {
               ++sat2;
            }
         }
         else
         {
            ++sat2;
         }
      }
   }

   double pi = 2 * asin(1.0);

   // rotate the earth
   pSim->earth.rotate();
   pSim->angleShip += 0.02;
   pSim->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites

   // draw could be handled by a loop later after we have them in a list

   // draw satellites
   for (auto sat : pSim->satellites)
      sat->draw(gout);


   // draw the earth
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
