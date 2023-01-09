#pragma once
#include "RectF.h"
#include "SpriteCodex.h"
#include "Graphics.h"
#include "Vec2.h"

class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	void Draw(Graphics& gfx) const;
private:
	Vec2 pos;
	Vec2 vel;
};

