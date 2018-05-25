#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
class ScoreComponent : public BaseComponent
{
public:
	ScoreComponent(std::shared_ptr<dae::GameObject> go);
	~ScoreComponent();

	void Update(const float deltaTime) override;
	void LateUpdate(const float deltaTime) override;
	void Render() override;

	void incrementScore(int deltaScore) { m_Score += deltaScore; m_ScoreChanged = true; }
	void setDisplay(std::weak_ptr<dae::GameObject> displayGo) { m_DisplayGO = displayGo; 
	m_origPosition = m_DisplayGO.lock()->GetPosition();	}
private:

	int m_Score{ 0 };
	bool m_ScoreChanged{ false };
	std::weak_ptr<dae::GameObject> m_DisplayGO;
	Pos m_origPosition{ 0,0 };
};

