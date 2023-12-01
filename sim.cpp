// Grant Shirley, Colby Hale, Bruce Li

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "physics.h"      // for PHYSICS
#include "test.h"
#include "satellite.h"
#include "star.h"
#include "earth.h"
#include "whole.h"
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
      hubblePhysics(24, 60, 30, 3100.0, 0.0, -9.80665),
      gps(Position(0.0, 42164000.0), Direction(), Velocity()),
      hubble(Position(0.0, -42164000.0), Direction(), Velocity(3100, 0))
   {
      ptHubble.setMetersX(0.0);
      ptHubble.setMetersY(-42164000.0);
      
      angleShip = 0.0;
      phaseStar = 0;
   }

   Physics hubblePhysics;
   Position ptHubble;
   Position ptUpperRight;
   GPS gps;
   Hubble hubble;

   unsigned char phaseStar;

   double const planetRadius = 6378000;
   double angleShip;

   // old stuff ends here
   Earth earth;

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
   pSim->hubble.move(time, pSim->earth.getRadius(), pSim->earth.getGravity());

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

   pSim->gps.draw(gout);
   pSim->hubble.draw(gout);

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
