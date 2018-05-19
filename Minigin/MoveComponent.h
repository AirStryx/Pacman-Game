#pragma once
#include "BaseComponent.h"
class MoveComponent : public BaseComponent
{
public:
	MoveComponent();
	~MoveComponent();

	void Update(const float deltaTime) override;
	void Render() override;

	void SetDirChangeT(float t) { m_DirChangeT = t; }
	void SetMoveDir(MoveDirection dir){m_MoveDir = dir; }

protected:
	MoveDirection m_MoveDir{ MoveDirection::NONE };
	float m_DirChangeT{ 1.f };
	float m_currCount{ 0.f };
};

