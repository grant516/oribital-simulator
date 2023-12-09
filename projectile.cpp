#include "projectile.h"


/*
* Kills the projectile when time is up
*/
void Projectile::expire()
{
   if (time >= expireTime)
      kill();
   else
      time++;
};