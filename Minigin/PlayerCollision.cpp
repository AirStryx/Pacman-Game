#include "MiniginPCH.h"
#include "PlayerCollision.h"
#include "LivesComponent.h"
#include "TextureComponent.h"
#include "ScoreComponent.h"

PlayerCollisionComponent::PlayerCollisionComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::PLAYERCOL, go)
{
}


PlayerCollisionComponent::~PlayerCollisionComponent()
{
}

void PlayerCollisionComponent::Update(const float deltaTime)
{
	if (m_Type != CharacterTypes::Pacman)
	{
		if (m_ISScared)
		{
			m_strongTimer += deltaTime;

			if (m_strongTimer >= m_strongMax)
			{
				ResetTexture();
			}
		}
	}
}

void PlayerCollisionComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	if (m_Type == CharacterTypes::Pacman)
	{
		for (auto check : m_ObjectsToCheck)
		{
			Pos myPos = m_GO.lock()->GetOldPos();
			Pos ghostPos = check.lock()->GetOldPos();
			Pos betweenVec{ myPos.x - ghostPos.x, myPos.y - ghostPos.y };
			float length = sqrt(pow(betweenVec.x, 2) + pow(betweenVec.y, 2));

			float GoRadius = std::static_pointer_cast<TextureComponent>(m_GO.lock()->GetComponent(Types::TEXTURE))->getWidth() / 2;
			float EnemyRadius = std::static_pointer_cast<TextureComponent>(check.lock()->GetComponent(Types::TEXTURE))->getWidth() / 2;

			if (length < GoRadius + EnemyRadius)
			{
				if (std::static_pointer_cast<PlayerCollisionComponent>(check.lock()->GetComponent(Types::PLAYERCOL))->m_ISScared)
				{
					check.lock()->ResetPos();
					std::static_pointer_cast<ScoreComponent>(m_GO.lock()->GetComponent(Types::SCORE))->incrementScore(500);
				}
				else
				{
					GotHit();
				}

			}


		}
	}
}

void PlayerCollisionComponent::Render()
{
}

void PlayerCollisionComponent::GotHit()
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

void PlayerCollisionComponent::ResetTexture()
{
		auto texture = std::static_pointer_cast<TextureComponent>(m_GO.lock()->GetComponent(Types::TEXTURE));
		switch (m_Type)
		{
		case CharacterTypes::RedGhost:
			texture->SetTexture("../Data/RedGhost.png");
			break;
		case CharacterTypes::BlueGhost:
			texture->SetTexture("../Data/BlueGhost.png");
			break;
		case CharacterTypes::YellowGhost:
			texture->SetTexture("../Data/YellowGhost.png");
			break;
		case CharacterTypes::PinkGhost:
			texture->SetTexture("../Data/pinkGhost.png");
			break;
		default:
			break;
		}
		m_ISScared = false;
	
}

void PlayerCollisionComponent::MakeScared()
{
	if (m_Type != CharacterTypes::Pacman)
	{
		auto texture = std::static_pointer_cast<TextureComponent>(m_GO.lock()->GetComponent(Types::TEXTURE));
		m_ISScared = true;
		m_strongTimer = 0.f;
		texture->SetTexture("../Data/ScaredGhost.png");
	}
}

void PlayerCollisionComponent::MakeStrong()
{
	for (auto g : m_ObjectsToCheck)
	{
		auto player = std::static_pointer_cast<PlayerCollisionComponent>(g.lock()->GetComponent(Types::PLAYERCOL));
		player->MakeScared();
	}
}
