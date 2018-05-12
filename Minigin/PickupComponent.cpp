#include "MiniginPCH.h"
#include "PickupComponent.h"
#include "TextureComponent.h"


PickupComponent::PickupComponent()
	:BaseComponent(Types::PICKUP)
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
		dae::Pos myPos = m_GO.lock()->GetPosition();
		dae::Pos pickupperPos = go.lock()->GetPosition();
		float pickupperRadius = std::static_pointer_cast<TextureComponent>(go.lock()->GetComponent(Types::TEXTURE))->getWidth() / 2;

		dae::Pos betweenVec{ myPos.x - pickupperPos.x, myPos.y - pickupperPos.y };

		float length = sqrt(pow(betweenVec.x, 2) + pow(betweenVec.y, 2));


		if (length < m_radius / 2 + pickupperRadius)
		{
			PickedUp();
		}
	}
}

void PickupComponent::Render()
{
}
