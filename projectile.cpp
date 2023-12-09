#include "projectile.h"

void Projectile::addFivePixels()
{
   // updating the direction by 5 pixels

   // add acording to radian value
}

void Projectile::expire()
{
   if (time >= expireTime)
      kill();
   else
      time++;
};