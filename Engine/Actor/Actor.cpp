#include "Actor/Actor.h"
#include "Util/Util.h"
#include "Render/Renderer.h"
#include "Engine/Engine.h"

#include <iostream>
#include <Windows.h>

namespace Dark
{
	Actor::Actor(const char* image, const Vector2& position, Color color)
		:position(position), color(color)
	{
		// 문자열 복사.
		width = static_cast<int>(strlen(image));
		this->image = new char[width + 1];
		strcpy_s(this->image, width + 1, image);
	}

	Actor::~Actor()
	{
		// 메모리 해제
		SafeDeleteArray(image);
	}
	void Actor::BeginPlay()
	{
		// 이벤트를 받은 후에는 플래그 설정.
		hasBeganPlay = true;
	}

	void Actor::Tick(float deltaTime)
	{
	}

	void Actor::Draw()
	{
		// 렌더러에 데이터 제출.
		Renderer::Get().Submit(image, position, color, sortingOrder);
	}

	void Actor::Destroy()
	{
		// 삭제 플래그 설정.
		destroyRequested = true;

		// 삭제 이벤트 호출.
		OnDestroy();
	}

	void Actor::OnDestroy()
	{
	}

	bool Actor::TestIntersect(const Actor* const other)
	{
		// AABB (Axis Aligned Bounding Box).
		// x 좌표만 고려하면 됨. y는 크기가 1이기 때문.

		// 자기 자신의 x좌표 정보.
		int xMin = position.x;
		int xMax = position.x + width - 1;

		// 충돌을 비교할 다른 액터의 x좌표 정보.
		int otherXMin = other->GetPosition().x;
		int otherXMax = other->GetPosition().x + other->width - 1;

		// 안겹치는 조건 확인.

		// 다른 액터의 왼쪽 좌표가
		// 내 오른쪽 좌표보다 더 오른쪽에 있는 경우.
		if (otherXMin > xMax)
		{
			return false;
		}

		// 다른 액터의 오른쪽 좌표가
		// 내 왼쪽 좌표보다 더 왼쪽에 있는 경우.
		if (otherXMax < xMin)
		{
			return false;
		}

		// y는 크기가 1이기 때문에 좌표가 같은지 여부만 확인.
		return position.y == other->GetPosition().y;
	}

	// 캐릭터 이미지 교체 -> 이펙트나 애니메이션도 가능
	void Actor::ChangeImage(const char* newImage)
	{
		// 기존 메모리 해제.
		SafeDeleteArray(image);

		// 새로운 문자열 복사.
		width = static_cast<int>(strlen(newImage));
		image = new char[width + 1];
		strcpy_s(image, width + 1, newImage);
	}

	void Actor::SetPostion(const Vector2& newPosition)
	{
		// 변경하려는 위치가 현재 위치와 같으면 건너뜀.
		if (position == newPosition)
		{
			return;
		}

		// 새로운 위치 설정.
		position = newPosition;
	}
}