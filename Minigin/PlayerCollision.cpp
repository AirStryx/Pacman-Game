#include "MiniginPCH.h"
#include "PlayerCollision.h"
#include "LivesComponent.h"
#include "TextureComponent.h"

PlayerCollision::PlayerCollision()
	:BaseComponent(Types::PLAYERCOL)
{
}


PlayerCollision::~PlayerCollision()
{
}

void PlayerCollision::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	if (m_Type == CharacterTypes::Pacman)
	{
		for (auto check : m_ObjectsToCheck)
		{
			Pos myPos = m_GO.lock()->GetPosition();
			Pos ghostPos = check.lock()->GetPosition();
			Pos betweenVec{ myPos.x - ghostPos.x, myPos.y - ghostPos.y };
			float length = sqrt(pow(betweenVec.x, 2) + pow(betweenVec.y, 2));

			float GoRadius = std::static_pointer_cast<TextureComponent>(m_GO.lock()->GetComponent(Types::TEXTURE))->getWidth() / 2;
			float EnemyRadius = std::static_pointer_cast<TextureComponent>(check.lock()->GetComponent(Types::TEXTURE))->getWidth() / 2;
			if (length < GoRadius + EnemyRadius)
			{
				GotHit();
			}
		}
	}
}

void PlayerCollision::Render()
{
}

void PlayerCollision::GotHit()
{
	if (m_Type == CharacterTypes::Pacman)
	{
		if (m_SetLiveObj)
		{
			std::static_pointer_cast<LivesComponent>(m_LiveObj.lock()->GetComponent(Types::LIFE))->Hit();
			m_GO.lock()->ResetPos();
		}
	}
}
