#include "Level/GameLevel.h"

/*
0: 바닥(Ground)
p: 플레이어(Player)
e: 적(Enemy)
*/

GameLevel::GameLevel()
{
	// 임시로 첫 맵 세팅 바로
	LoadMap("Stage1.txt");
}

GameLevel::~GameLevel()
{
}

void GameLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 충돌 판정 처리.
	ProcessCollisionPlayerAttackAndEnemy();
	ProcessCollisionPlayerAndEnemyIsAlive();
	ProcessCollisionPlayerAttackAndEnemy();
}

void GameLevel::Draw()
{
}

void GameLevel::LoadMap(const char* filename)
{
}

bool GameLevel::CanMove(const Actor& mover, const Vector2& currentPos, const Vector2& nextPos)
{
	return false;
}

// 플레이어 공격 -> 적 body
void GameLevel::ProcessCollisionPlayerAttackAndEnemy()
{
}

// 적 body(살아있을때만) -> 플레이어 body - (타격후 3초간 무적)
void GameLevel::ProcessCollisionPlayerAndEnemyIsAlive()
{
}

// 플레이어 body -> 적 body(죽었을때만)
void GameLevel::ProcessCollisionPlayerAndEnemyIsDead()
{
}

void GameLevel::ShowUI()
{
}
