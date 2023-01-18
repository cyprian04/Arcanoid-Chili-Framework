#pragma once
#include "SpriteCodex.h"
#include "Graphics.h"
class Poo
{
public:
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Update(float dt);
	void Draw(Graphics& gfx) const;
private:
	Vec2 pos;
	Vec2 vel;
};
