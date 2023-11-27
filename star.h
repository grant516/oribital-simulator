#pragma once
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"


class Star
{
private:
	Position pos;
	unsigned char phase = random(0, 255);  // phase of the star's blinking

public:
	Star(int x, int y)
	{
		pos = Position(x, y);
	}
	void reset(int width, int height);
	void draw(ogstream gout);

	Position getPosition()
	{
		return pos;
	}

	unsigned char getPhase()
	{
		return phase;
	}
};

