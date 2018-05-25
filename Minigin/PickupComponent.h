#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
class PickupComponent : public BaseComponent
{
public:
	PickupComponent(std::shared_ptr<dae::GameObject> go);
	~PickupComponent();
	void Update(const float deltaTime) override;
	void LateUpdate(const float deltaTime) override;
	void Render() override;

	void SetRadius(float radius) { m_radius = radius; }
	void AddPickupper(std::shared_ptr<dae::GameObject> go) { m_PickUppers.push_back(go); }
	void SetScore(int score) { m_deltaScore = score; }
	void setBig(bool isBig) { m_IsBig = isBig; }

	void PickedUp(std::weak_ptr<dae::GameObject> pickupper);

private:
	std::vector<std::weak_ptr<dae::GameObject>> m_PickUppers;
	std::weak_ptr<dae::GameObject> m_Pickupper;
	float m_radius{ 0.f };
	bool m_isPickedUp{ false };
	int m_deltaScore{10};
	bool m_IsBig{ false };
};

