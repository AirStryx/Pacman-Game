#include "MiniginPCH.h"
#include "MoveComponent.h"
#include "GameObject.h"


MoveComponent::MoveComponent()
	:BaseComponent(Types::MOVE)
{
}


MoveComponent::~MoveComponent()
{
}

void MoveComponent::Update(const float deltaTime)
{
	m_currCount += deltaTime;

	if (m_currCount >= m_DirChangeT)
	{
		m_currCount = 0;

		int Choice = rand() % 4 + 1;

		switch (Choice)
		{
		case 1:
			m_MoveDir = MoveDirection::UP;
			break;
		case 2:
			m_MoveDir = MoveDirection::DOWN;
			break;
		case 3:
			m_MoveDir = MoveDirection::RIGHT;
			break;
		case 4:
			m_MoveDir = MoveDirection::LEFT;
			break;
		default:
			break;
		}
	}

	m_GO.lock()->SetOldPos(m_GO.lock()->GetPosition());
	switch (m_MoveDir)
	{
	case MoveDirection::UP:
		m_NewPos.x = m_GO.lock()->GetOldPos().x;
		m_NewPos.y = m_GO.lock()->GetOldPos().y - (100 * deltaTime);
		break;
	case MoveDirection::DOWN:
		m_NewPos.x = m_GO.lock()->GetOldPos().x;
		m_NewPos.y = m_GO.lock()->GetOldPos().y + (100 * deltaTime);
		break;
	case MoveDirection::LEFT:
		m_NewPos.x = m_GO.lock()->GetOldPos().x - (100 * deltaTime);
		m_NewPos.y = m_GO.lock()->GetOldPos().y;
		break;
	case MoveDirection::RIGHT:
		m_NewPos.x = m_GO.lock()->GetOldPos().x + (100 * deltaTime);
		m_NewPos.y = m_GO.lock()->GetOldPos().y;
		break;
	case MoveDirection::NONE:
		m_NewPos.x = m_GO.lock()->GetOldPos().x;
		m_NewPos.y = m_GO.lock()->GetOldPos().y;
		break;
	default:
		break;
	}
}

void MoveComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	m_GO.lock()->SetPosition(m_NewPos.x, m_NewPos.y);
}

void MoveComponent::Render()
{
}
