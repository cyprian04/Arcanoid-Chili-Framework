#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const RectF& rect, Color c);
	void Draw(Graphics& gfx) const;
private:
	Color c;
	RectF rect;
};