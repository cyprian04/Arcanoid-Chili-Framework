#pragma once
#include "SpriteCodex.h"
#include "Graphics.h"
#include "Paddle.h"

class Poo
{
public:
	Poo();
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	void Draw(Graphics& gfx) const;
	void DoWallsCollision(const Board& walls);
	bool DoBallCollision(Ball& ball);
	bool DoPaddleCollision(const Paddle& pad, Ball& ball);
	void ReboundX();
	void ReboundY();
	RectF GetRect();
public:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> PosLos;
	std::uniform_real_distribution<float> VelLos;
private:
	bool destroy = false;
	static constexpr float radius = 12.0f;
	Vec2 pos;
	Vec2 vel;
};
