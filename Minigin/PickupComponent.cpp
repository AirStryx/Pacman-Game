#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include "PickupComponent.h"
#include "TextureComponent.h"
#include "ScoreComponent.h"
#include "PlayerCollision.h"


PickupComponent::PickupComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::PICKUP, go)
{
}


PickupComponent::~PickupComponent()
{
}

void PickupComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	for (auto go : m_PickUppers)
	{
		Pos myPos = m_GO.lock()->GetPosition();
		Pos pickupperPos = go.lock()->GetPosition();
		Pos betweenVec{ myPos.x - pickupperPos.x, myPos.y - pickupperPos.y };
		float length = sqrt(pow(betweenVec.x, 2) + pow(betweenVec.y, 2));

		float pickupperRadius = std::static_pointer_cast<TextureComponent>(go.lock()->GetComponent(Types::TEXTURE))->getWidth() / 2;
		if (length < m_radius / 2 + pickupperRadius)
		{
			m_isPickedUp = true;
			m_Pickupper = go;
		}
	}
}

void PickupComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	if (m_isPickedUp)
	{
		PickedUp(m_Pickupper);
	}
}

void PickupComponent::Render()
{
}

void PickupComponent::PickedUp(std::weak_ptr<dae::GameObject> pickupper)
{
	std::static_pointer_cast<ScoreComponent>(pickupper.lock()->GetComponent(Types::SCORE))->incrementScore(m_deltaScore);
	if (m_IsBig)
	{
		std::static_pointer_cast<PlayerCollisionComponent>(pickupper.lock()->GetComponent(Types::PLAYERCOL))->MakeStrong();
	}
	dae::SceneManager::GetInstance().GetActiveScene().lock()->DecrementPickups();
	m_GO.lock()->Kill();
}
