#pragma once
#include "satellite.h"
#include "uiDraw.h"

class Whole : public Satellite
{
public:
   Whole() {};
};

// GPS Class
class GPS : public Whole
{
public:
   void draw(ogstream& gout);
};

// Hubble Class
class Hubble : public Whole
{
public:
   void draw(ogstream& gout);
};