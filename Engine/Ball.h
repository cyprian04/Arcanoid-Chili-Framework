#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "SpriteCodex.h"
class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in, Color c);
	void Update();
	void Draw(Graphics& gfx) const;
	bool DoWallsCollision( const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	Color c;
};