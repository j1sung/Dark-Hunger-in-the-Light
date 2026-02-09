#pragma once

#include "Level/Level.h"
#include "Interface/ICanMove.h"
#include "Math/Vector2.h"

using namespace Dark;

class GameLevel : public Level, ICanMove
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();
	~GameLevel();

private:

	// 이벤트 함수 오버라이드.
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;

	// ----- 게임 내부 액터 충돌 판정 처리 함수 -----
	
	// 화이트 스페이스 액터 범위 처리 함수.
	//void ProcessCollisionWithWhiteSpace(); // 화이트 스페이스와의 충돌 처리(적, 플레이어)

	// 화이트 스페이스도 맵으로 통째로 찍기.
	void LoadMap(const char* filename);

	// 액터 이동가능한지 판단하는 함수.
	virtual bool CanMove(
		const Actor& mover,
		const Vector2& currentPos,
		const Vector2& nextPos) override;
	
	// 공격 충돌 판정 처리 함수.
	void ProcessCollisionPlayerAttackAndEnemy(); // 플레이어 공격 -> 적 body
	void ProcessCollisionPlayerAndEnemyIsAlive(); // 적 body(살아있을때만) -> 플레이어 body - (타격후 3초간 무적)

	void ProcessCollisionPlayerAndEnemyIsDead(); // 플레이어 body -> 적 body(죽었을때만)

	// 점수 보여주는 함수.
	void ShowUI();

private:
	struct GameUI
	{
		int hp = 0;
		int hungry = 0;
		int eat = 0;
		int power = 0;

		char line1[128] = {};
		char line2[128] = {};

	};

	GameUI ui;

	// 화이트 스페이스인지 확인.
	bool isWhiteSpace = false;

	// 플레이어가 죽었는지 확인.
	bool isPlayerDead = false;

	// 플레이어가 죽은 위치 (Draw에서 처리하기 위해 Tick에서 저장).
	Vector2 playerDeadPosition;
};

