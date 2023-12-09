#include "fragment.h"

/* 
* Kills the fragment when time is up
*/
void Fragment::expire()
{
   if (time >= expireTime)
      kill();
   else
      time++;
};