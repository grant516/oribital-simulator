#include "fragment.h"

void Fragment::expire()
{
   if (time >= expireTime)
      kill();
   else
      time++;
};