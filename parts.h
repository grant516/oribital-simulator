#pragma once
#include "satellite.h"
#include "uiDraw.h"


/*************************************************************************
 * Parts
 * This class is the base class for all parts of the satellites. It inherits from the Satellite class.
 * It is used to organize all parts of satellites.
 *************************************************************************/
class Parts : public Satellite
{
public:
   Parts() {};
};

class StarlinkArray : public Parts
{
public:
   StarlinkArray() { radius = 4; };
   void draw(ogstream& gout) { gout.drawStarlinkArray(position, facingDirection.getRadians()); }
};

class StarlinkBody : public Parts
{
public:
   StarlinkBody() { radius = 2; };
   void draw(ogstream& gout) { gout.drawStarlinkBody(position, facingDirection.getRadians()); }
};

class CrewDragonRight : public Parts
{
public:
   CrewDragonRight() { radius = 6; };
   void draw(ogstream& gout) { gout.drawCrewDragonRight(position, facingDirection.getRadians()); }
};

class CrewDragonLeft : public Parts
{
public:
   CrewDragonLeft() { radius = 6; };
   void draw(ogstream& gout) { gout.drawCrewDragonLeft(position, facingDirection.getRadians()); }
};

class CrewDragonCenter : public Parts
{
public:
   CrewDragonCenter() { radius = 6; };
   void draw(ogstream& gout) { gout.drawCrewDragonCenter(position, facingDirection.getRadians()); }
};

class HubbleRight : public Parts
{
public:
   HubbleRight() { radius = 8; };
   void draw(ogstream& gout) { gout.drawHubbleRight(position, facingDirection.getRadians()); }
};

class HubbleLeft : public Parts
{
public:
   HubbleLeft() { radius = 8; };
   void draw(ogstream& gout) { gout.drawHubbleLeft(position, facingDirection.getRadians()); }
};

class HubbleComputer : public Parts
{
public:
   HubbleComputer() { radius = 7; };
   void draw(ogstream& gout) { gout.drawHubbleComputer(position, facingDirection.getRadians()); }
};

class HubbleTelescope : public Parts
{
public:
   HubbleTelescope() { radius = 10; };
   void draw(ogstream& gout) { gout.drawHubbleTelescope(position, facingDirection.getRadians()); }
};

class GPSRight : public Parts
{
public:
   GPSRight() { radius = 8; };
   void draw(ogstream& gout) { gout.drawGPSRight(position, facingDirection.getRadians()); }
};

class GPSLeft : public Parts
{
public:
   GPSLeft() { radius = 8; };
   void draw(ogstream& gout) { gout.drawGPSLeft(position, facingDirection.getRadians()); }
};

class GPSCenter : public Parts
{
public:
   GPSCenter() { radius = 7; };
   void draw(ogstream& gout) { gout.drawGPSCenter(position, facingDirection.getRadians()); }
};