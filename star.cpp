#include "star.h"


void Star::reset(int width, int height)
{
	pos.setPixelsX(width);
	pos.setPixelsY(height);
}

void Star::draw(ogstream& gout)
{
	phase++;
	gout.drawStar(pos, phase);
}

