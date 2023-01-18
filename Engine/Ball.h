#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include "Board.h"
#include <random>
class Ball
{
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in, Color c);
	void Update(float dt);
	void Draw(Graphics& gfx) const;
	bool DoWallsCollision( const Board& walls);
	void ReboundX();
	void ReboundY();
	void DrawLivesLeft(Graphics& gfx, const Board& walls) const;
	RectF GetRect() const;
	Vec2 GetPosition() const;
	Vec2 GetVelocity() const;
	bool GetGameOver() const;
	bool SetGameOver();
private:
	static constexpr float radius = 7.0f;
	bool GameOver;
	int LifeLeft = 3;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> los;
	Vec2 pos;
	Vec2 vel;
	Color c;
	
};
