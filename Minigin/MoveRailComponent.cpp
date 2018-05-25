#include "MiniginPCH.h"
#include "GameObject.h"
#include "MoveRailComponent.h"
#include "TextureComponent.h"


MoveRailComponent::MoveRailComponent(std::shared_ptr<dae::GameObject> go)
	:MoveComponent(go)
{
	m_AllowedDirection.push_back(MoveDirection::UP);
	m_AllowedDirection.push_back(MoveDirection::DOWN);
	m_AllowedDirection.push_back(MoveDirection::RIGHT);
	m_AllowedDirection.push_back(MoveDirection::LEFT);
}


MoveRailComponent::~MoveRailComponent()
{
}

void MoveRailComponent::Update(const float deltaTime)
{
	//remember the last check of cp
	bool LastRun = m_InRangeOfCP;
	//reset range
	m_InRangeOfCP = false;
	//Check if it is In range
	for (auto cp : m_CornerPoints)
	{
		Pos goPos = m_GO.lock()->GetPosition();
		Pos cpPos = cp.pos;

		Pos inBetween{ goPos.x - cpPos.x, goPos.y - cpPos.y };
		float length = sqrt(pow(inBetween.x, 2) + pow(inBetween.y, 2));

		float goRadius = std::static_pointer_cast<TextureComponent>(m_GO.lock()->GetComponent(Types::TEXTURE))->getWidth() / 2;

		if (length < m_Radius + (goRadius / 2))
		{
			m_LastCP = cp;
			m_InRangeOfCP = true;
			break;
		}
	}
	//if it is set everything accordingly ONLY ONCE
	if (m_InRangeOfCP && !LastRun)
	{
		m_AllowedDirection = m_LastCP.m_AllowedDirections;

		do
		{
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
		} while (!CanMoveInDir(m_MoveDir));
	}

	//if you just got out of range
	if (LastRun && !m_InRangeOfCP)
	{
		std::vector<MoveDirection> tempMD;

		switch (m_MoveDir)
		{
		case MoveDirection::UP:
			tempMD.push_back(MoveDirection::UP);
			tempMD.push_back(MoveDirection::DOWN);
			break;
		case MoveDirection::DOWN:
			tempMD.push_back(MoveDirection::UP);
			tempMD.push_back(MoveDirection::DOWN);
			break;
		case MoveDirection::LEFT:
			tempMD.push_back(MoveDirection::LEFT);
			tempMD.push_back(MoveDirection::RIGHT);
			break;
		case MoveDirection::RIGHT:
			tempMD.push_back(MoveDirection::LEFT);
			tempMD.push_back(MoveDirection::RIGHT);
			break;
		default:
			break;
		}
		SetAllowedDirections(tempMD);
	}

	//when out of range for more than  sec try to change dir and if you can
	if (!m_InRangeOfCP)
	{
		m_currCount += deltaTime;
	}
	else
	{
		m_currCount = 0;
	}
	if (m_currCount >= m_DirChangeT)
	{
		m_currCount = 0;
		int Choice = rand() % 4 + 1;

		switch (Choice)
		{
		case 1:
			if (CanMoveInDir(MoveDirection::UP))
			{
				m_MoveDir = MoveDirection::UP;
			}
			break;
		case 2:
			if (CanMoveInDir(MoveDirection::DOWN))
			{
				m_MoveDir = MoveDirection::DOWN;
			}
			break;
		case 3:
			if (CanMoveInDir(MoveDirection::LEFT))
			{
				m_MoveDir = MoveDirection::LEFT;
			}
			break;
		case 4:
			if (CanMoveInDir(MoveDirection::RIGHT))
			{
				m_MoveDir = MoveDirection::RIGHT;
			}
			break;
		default:
			break;
		}
	}

	//do you need to stop going forward?
	bool canContinue{ false };
	for (auto dir : m_AllowedDirection)
	{
		if (dir == m_MoveDir)
		{
			canContinue = true;
		}
	}

	//no? STOP
	if (!canContinue)
	{
		m_MoveDir = MoveDirection::NONE;
	}

	//movement code
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

void MoveRailComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	m_GO.lock()->SetPosition(m_NewPos.x, m_NewPos.y);
}

void MoveRailComponent::Render()
{
}

void MoveRailComponent::AddCornerPoint(Pos point, const std::vector<MoveDirection>& moveDirs)
{
	CornerPoint cp;
	cp.pos = point;
	cp.m_AllowedDirections = moveDirs;
	m_CornerPoints.push_back(cp);
}

void MoveRailComponent::AddCornerPoint(CornerPoint cp)
{
	m_CornerPoints.push_back(cp);
}

bool MoveRailComponent::CanMoveInDir(MoveDirection dir)
{
	for (auto allowedDir : m_AllowedDirection)
	{
		if (allowedDir == dir)
		{
			return true;
		}
	}

	return false;
}
