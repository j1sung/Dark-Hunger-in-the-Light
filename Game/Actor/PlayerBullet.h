#pragma once

#include "Actor/Actor.h"

using namespace Dark;

class PlayerBullet:public Actor
{
	RTTI_DECLARATIONS(PlayerBullet, Actor)

public:
	PlayerBullet(const Vector2& position);
	~PlayerBullet();

	virtual void Tick(float deltaTime) override;

private:
	// 이동 속도.
	float moveSpeed = 30.0f;

	// 좌표.
	float xPos = 0.0f;
	float yPos = 0.0f;
	float vx = 0.0f;
	float vy = 0.0f;
	bool VelocityInitialized = false;
};

