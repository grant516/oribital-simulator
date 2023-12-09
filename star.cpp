#include "star.h"

/*
* Resets the star posiiton
*/
void Star::reset(int width, int height)
{
	pos.setPixelsX(width);
	pos.setPixelsY(height);
}

/*
* Draws the star
*/
void Star::draw(ogstream& gout)
{
	phase++;
	gout.drawStar(pos, phase);
}

