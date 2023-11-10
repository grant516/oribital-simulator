/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/

/* 
Test cases for updatePostion added by:
Grant Shirley, Colby Hale, Bruce Li
*/


#pragma once

#include <iostream>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition
{
public:
   void run()
   {
      Position().setZoom(1000.0 /* 1km equals 1 pixel */);
      defaultConstructor();
      nonDefaultConstructor();
      copyConstructor();
      assignment();
 
      setPixels();
      setMeters();
      
      addPixels();
      addMeters();

      // Testing updatePosition
      stationary_updatePosition();
      moving_updatePosition();
      movingLonger_updatePosition();
      fromStop_updatePosition();
      fromStopLong_updatePosition();
      complex_updatePosition();
   }
   
private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   void defaultConstructor() const
   {  // setup
      // exercise
      Position pos;
      // verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
   }  // teardown

   void nonDefaultConstructor() const
   {  // setup
      // exercise
      Position pos(3000.0, 9000.0);
      // verify
      assert(pos.x == 3000.0);
      assert(pos.y == 9000.0);
   }  // teardown

   void copyConstructor() const
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2(pos1);
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown

   void assignment() const
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2 = pos1;
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown
   
   void setMeters() const
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setMetersX(5000.0);
      pos.setMetersY(3000.0);
      // verify
      assert(pos.x == 5000.0);
      assert(pos.y == 3000.0);
   }  // teardown
 
   void setPixels() const
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setPixelsX(6.0);
      pos.setPixelsY(12.0);
      // verify
      assert(pos.x == 6000.0);
      assert(pos.y == 12000.0);
   }  // teardown
   
   void addMeters() const
   {  // setup
      Position pos;
      pos.x = 800.0;
      pos.y = 1600.0;
      // exercise
      pos.addMetersX(-400.0);
      pos.addMetersY(800.0);
      // verify
      assert(pos.x == 400.0);
      assert(pos.y == 2400.0);
   }  // teardown
   
   void addPixels() const
   {  // setup
      Position pos;
      pos.x = 2000.0;
      pos.y = 4000.0;
      // exercise
      pos.addPixelsX(2);
      pos.addPixelsY(3);
      // verify
      assert(pos.x == 4000.0);
      assert(pos.y == 7000.0);
   }  // teardown

   // Testing updatePosition functions
   void stationary_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);

      Acceleration accel;
      accel.setDDx(0.0);
      accel.setDDy(0.0);
      
      int t = 1;

      // exercise
      position.updatePosition(velocity.getDx(), velocity.getDy(), 
         accel.getDDx(), accel.getDDy(), t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void moving_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.5);
      velocity.setDy(0.4);

      Acceleration accel;
      accel.setDDx(0.0);
      accel.setDDy(0.0);

      int t = 1;

      // exercise
      position.updatePosition(velocity.getDx(), velocity.getDy(), 
         accel.getDDx(), accel.getDDy(), t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void movingLonger_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.5);
      velocity.setDy(0.4);

      Acceleration accel;
      accel.setDDx(0.0);
      accel.setDDy(0.0);

      int t = 2;

      // exercise
      position.updatePosition(velocity.getDx(), velocity.getDy(), 
         accel.getDDx(), accel.getDDy(), t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void fromStop_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);

      Acceleration accel;
      accel.setDDx(0.2);
      accel.setDDy(0.3);

      int t = 1;

      // exercise
      position.updatePosition(velocity.getDx(), velocity.getDy(), 
         accel.getDDx(), accel.getDDy(), t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void fromStopLong_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(0.0);
      velocity.setDy(0.0);

      Acceleration accel;
      accel.setDDx(0.2);
      accel.setDDy(0.3);

      int t = 2;

      // exercise
      position.updatePosition(velocity.getDx(), velocity.getDy(), 
         accel.getDDx(), accel.getDDy(), t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

   void complex_updatePosition()
   {
      // setup
      Position position;
      position.setMetersX(11.1);
      position.setMetersY(22.2);

      Velocity velocity;
      velocity.setDx(1.0);
      velocity.setDy(2.0);

      Acceleration accel;
      accel.setDDx(0.2);
      accel.setDDy(0.3);

      int t = 2;

      // exercise
      position.updatePosition(velocity.getDx(), velocity.getDy(), 
         accel.getDDx(), accel.getDDy(), t);

      // verify
      assert(position.getMetersX() == 5.6);
      assert(position.getMetersY() == 6.6);

      // teardown
   }

};
