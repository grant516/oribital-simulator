/*************************************************************
 * 1. Name: Grant Shirley, Colby Hale, Bruce Li
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was applying the physics equations to the
 *      satellite correctly and in the correct sequence.
 * 5. How long did it take for you to complete the assignment?
 *      4 hours
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "physics.h"      // for PHYSICS
#include "test.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      hubblePhysics(24, 60, 30, -3100.0, 0.0, -9.80665)
   {
      ptHubble.setMetersX(0.0);
      ptHubble.setMetersY(42164000.0);
      
      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
   }

   Physics hubblePhysics;
   Position ptHubble;
   Position ptUpperRight;

   unsigned char phaseStar;

   double const earthRadius = 6378000;
   double angleShip;
   double angleEarth;
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
   Demo* pDemo = (Demo*)p;

   //
   // perform all the game logic
   //

   //Physics
   // calculate earth's gravity pull for both ddx and ddy
      // get the height away from the earth
   double height = pDemo->hubblePhysics.htAboveEarth( // Maybe store in physics as class variable
      pDemo->ptHubble.getMetersX(),
      pDemo->ptHubble.getMetersY(), 
      pDemo->earthRadius);
      // gravity equation
   double currentGravity = 
      pDemo->hubblePhysics.gravityEquation(pDemo->earthRadius, height);
      // Get radians angle
   double radians = pDemo->hubblePhysics.dirGravityPull(0.0, 0.0,
      pDemo->ptHubble.getMetersX(), pDemo->ptHubble.getMetersY());

   pDemo->hubblePhysics.radiansToDegrees(radians);
   pDemo->hubblePhysics.hrzCompAccel(currentGravity);
   pDemo->hubblePhysics.vertCompAccel(currentGravity);

   pDemo->hubblePhysics.hrzVelWConstA();
   pDemo->hubblePhysics.vertVelWConstA();

   pDemo->ptHubble.setMetersX(pDemo->hubblePhysics.hrzDistFormula(pDemo->ptHubble.getMetersX()));
   pDemo->ptHubble.setMetersY(pDemo->hubblePhysics.vertDistFormula(pDemo->ptHubble.getMetersY()));

   double pi = 2 * asin(1.0);

   // rotate the earth
   pDemo->angleEarth -= (2*pi)/1800;
   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
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
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
