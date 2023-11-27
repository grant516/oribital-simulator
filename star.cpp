#include "star.h"


void Star::reset(int width, int height)
{
}

void Star::draw(ogstream gout)
{
	gout.drawStar(pos, phase);
}

