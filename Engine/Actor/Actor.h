#pragma once

#include "Common/RTTI.h"
#include "Math/Vector2.h"
#include "Math/Color.h"

namespace Dark
{
	// 전방 선언.
	class Level;

	class DARK_API Actor : public RTTI
	{
		RTTI_DECLARATIONS(Actor, RTTI)

	public:
		Actor(
			const char* image = "",
			const Vector2& position = Vector2::Zero,
			Color color = Color::White
		);
		~Actor();

		// 게임 플레이 이벤트.
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// 삭제 요청 함수.
		void Destroy();

		// 삭제가 될 때 호출될 이벤트 함수.
		virtual void OnDestroy(); // Player가 오버라이딩 하기

		// 게임 종료 함수.
		//void QuitGame(); // 여기서 공통으로 안씀.

		// 충돌 여부 확인 함수.
		bool TestIntersect(const Actor* const other);

		// 액터의 이미지 값 변경 함수.
		void ChangeImage(const char* newImage);

		// 

	private:
		// 그릴 문자(이미지).
		char* image = nullptr;

		// 색상
		Color color = Color::White;

		// 위치.
		Vector2 position;
	};

}

