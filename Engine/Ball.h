#pragma once
#include "RectF.h"
#include "SpriteCodex.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	void Draw(Graphics& gfx) const;
	void ReboundX();
	void ReboundY();
	bool DoWallCollision(const RectF& walls);
	RectF GetRect() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};

