#pragma once
#include "SpriteCodex.h"
#include "Graphics.h"
#include "Ball.h"

class Poo
{
public:
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	void Draw(Graphics& gfx) const;
	void DoWallsCollision(const Board& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect();
private:
	static constexpr float radius = 12.0f;
	Vec2 pos;
	Vec2 vel;
};
