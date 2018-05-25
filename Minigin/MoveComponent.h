#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
class MoveComponent : public BaseComponent
{
public:
	MoveComponent();
	~MoveComponent();

	void Update(const float deltaTime) override;
	void LateUpdate(const float deltaTime) override;
	void Render() override;

	void SetDirChangeT(float t) { m_DirChangeT = t; }
	void SetMoveDir(MoveDirection dir){m_MoveDir = dir; }
	void ResetPos() { m_NewPos = m_GO.lock()->GetPosition(); }
protected:
	Pos m_NewPos{};
	MoveDirection m_MoveDir{ MoveDirection::NONE };
	float m_DirChangeT{ 1.f };
	float m_currCount{ 0.f };
};

