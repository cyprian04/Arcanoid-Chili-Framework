#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF& rect_in, Color c_in);
	void Draw(Graphics& gfx) const;
private:
	RectF rect;
	Color c;
};
