#pragma once
#include "satellite.h"
#include "uiDraw.h"


/*************************************************************************
 * Parts
 * This class is the base class for all parts of the satellites. It inherits from the Satellite class.
 * It is used to organize all parts of satellites.
 *************************************************************************/
class Part : public Satellite
{
public:
   Part() {};
};

class StarlinkArray : public Part
{
public:
   StarlinkArray(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 4; 
   };
   void draw(ogstream& gout) const { gout.drawStarlinkArray(position, facingDirection.getRadians()); }
};

class StarlinkBody : public Part
{
public:
   StarlinkBody(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 2; 
   };
   void draw(ogstream& gout) const { gout.drawStarlinkBody(position, facingDirection.getRadians()); }
};

class CrewDragonRight : public Part
{
public:
   CrewDragonRight(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 6; 
   };
   void draw(ogstream& gout) const { gout.drawCrewDragonRight(position, facingDirection.getRadians()); }
};

class CrewDragonLeft : public Part
{
public:
   CrewDragonLeft(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 6; 
   };
   void draw(ogstream& gout) const { gout.drawCrewDragonLeft(position, facingDirection.getRadians()); }
};

class CrewDragonCenter : public Part
{
public:
   CrewDragonCenter(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 6; 
   };
   void draw(ogstream& gout) const { gout.drawCrewDragonCenter(position, facingDirection.getRadians()); }
};

class HubbleRight : public Part
{
public:
   HubbleRight(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 8; 
   };
   void draw(ogstream& gout) const { gout.drawHubbleRight(position, facingDirection.getRadians()); }
};

class HubbleLeft : public Part
{
public:
   HubbleLeft(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 8; 
   };
   void draw(ogstream& gout) const { gout.drawHubbleLeft(position, facingDirection.getRadians()); }
};

class HubbleComputer : public Part
{
public:
   HubbleComputer(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 7; 
   };
   void draw(ogstream& gout) const { gout.drawHubbleComputer(position, facingDirection.getRadians()); }
};

class HubbleTelescope : public Part
{
public:
   HubbleTelescope(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 10; 
   };
   void draw(ogstream& gout) const { gout.drawHubbleTelescope(position, facingDirection.getRadians()); }
};

class GPSRight : public Part
{
public:
   GPSRight(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 8; 
   };
   void draw(ogstream& gout) const { gout.drawGPSRight(position, facingDirection.getRadians()); }
};

class GPSLeft : public Part
{
public:
   GPSLeft(Position pos, Velocity vel, Direction dir)
   {
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir; 
      radius = 8; 
   };
   void draw(ogstream& gout) const { gout.drawGPSLeft(position, facingDirection.getRadians()); }
};

class GPSCenter : public Part
{
public:
   GPSCenter(Position pos, Velocity vel, Direction dir) 
   { 
      position = pos;
      velocity = vel;
      facingDirection = dir;
      movementDirection = dir;
      radius = 7;
   };
   void draw(ogstream& gout) const { gout.drawGPSCenter(position, facingDirection.getRadians()); }
};