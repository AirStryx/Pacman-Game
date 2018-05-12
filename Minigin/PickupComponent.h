#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
class PickupComponent : public BaseComponent
{
public:
	PickupComponent();
	virtual ~PickupComponent();
	void Update(const float deltaTime) override;
	void Render() override;

	void setGO(std::shared_ptr<dae::GameObject> go) { m_GO = go; }
	void SetRadius(float radius) { m_radius = radius; }
	void AddPickupper(std::shared_ptr<dae::GameObject> go) { m_PickUppers.push_back(go); }

	void PickedUp() { m_GO.lock()->Kill(); }

private:
	std::vector<std::weak_ptr<dae::GameObject>> m_PickUppers;
	std::weak_ptr<dae::GameObject> m_GO;
	float m_radius{ 0.f };
};

