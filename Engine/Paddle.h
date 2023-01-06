#pragma once
#include "RectF.h"
#include "Graphics.h"
class Paddle
{
public:
	Paddle(const RectF& rect_in);
	void Draw(Graphics& gfx)const;
private:
	bool once = true;
	static constexpr float wingWidth = 20.0f;
	RectF rect;
};

