#pragma once
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"


class Star
{
private:
	Position pos;
	unsigned char phase;  // phase of the star's blinking

public:
	Star() { phase = random(0, 255); }
	Star(int x, int y)
	{
		phase = random(0, 255);
		pos.setPixelsX(x);
		pos.setPixelsY(y);
	}
	void reset(int width, int height);
	void draw(ogstream& gout);
};

