#include "MiniginPCH.h"
#include "RailComponent.h"
#include "InputComponent.h"
#include "TextureComponent.h"
#include "command.h"
#include "Renderer.h"

RailComponent::RailComponent()
{
	m_AllowedDirection.push_back(MoveDirection::UP);
	m_AllowedDirection.push_back(MoveDirection::DOWN);
	m_AllowedDirection.push_back(MoveDirection::RIGHT);
	m_AllowedDirection.push_back(MoveDirection::LEFT);

	//DEBUG TESTING
	//mTexture = dae::ResourceManager::GetInstance().LoadTexture("../Data/PickUpSmall.png");
}


RailComponent::~RailComponent()
{
}

void RailComponent::Update(const float deltaTime)
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

		if (length < m_Radius + (goRadius/ 2))
		{
			m_LastCP = cp;
			m_InRangeOfCP = true;
			break;
		}
	}
	//if it is set everything accordingly
	if (m_InRangeOfCP)
	{
		m_AllowedDirection = m_LastCP.m_AllowedDirections;
	}

	//if you just got out of range
	if (LastRun && !m_InRangeOfCP)
	{
		std::vector<MoveDirection> tempMD;

		switch (m_Direction)
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

	//do you need to stop going forward?
	bool canContinue{ false };
	for (auto dir : m_AllowedDirection)
	{
		if (dir == m_Direction)
		{
			canContinue = true;
		}
	}

	//no? STOP
	if (!canContinue)
	{
		m_Direction = MoveDirection::NONE;
	}

	//movement code
	HandleInput();
	Pos pos = m_GO.lock()->GetPosition();
	switch (m_Direction)
	{
	case MoveDirection::UP:
		m_GO.lock()->SetPosition(pos.x, pos.y - (100 * deltaTime));
		break;
	case MoveDirection::DOWN:
		m_GO.lock()->SetPosition(pos.x, pos.y + (100 * deltaTime));
		break;
	case MoveDirection::LEFT:
		m_GO.lock()->SetPosition(pos.x - (100 * deltaTime), pos.y);
		break;
	case MoveDirection::RIGHT:
		m_GO.lock()->SetPosition(pos.x + (100 * deltaTime), pos.y);
		break;
	case MoveDirection::NONE:
		break;
	default:
		break;


	}
}

void RailComponent::Render()
{
	//DEBUG RENDER PLEASE DONT GRADE THIS
	//for (auto cp : m_CornerPoints)
	//{
	//	if (mTexture != nullptr)
	//	{
	//		dae::Renderer::GetInstance().RenderTexture(*mTexture,cp.pos.x, cp.pos.y);
	//	}
	//}
	
}

void RailComponent::AddCornerPoint(Pos point, const std::vector<MoveDirection>& moveDirs)
{
	CornerPoint cp;
	cp.pos = point;
	cp.m_AllowedDirections = moveDirs;
	m_CornerPoints.push_back(cp);
}

void RailComponent::AddCornerPoint(CornerPoint cp)
{
	m_CornerPoints.push_back(cp);
}
bool RailComponent::CanMoveInDir(MoveDirection dir)
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
void RailComponent::HandleInput()
{
	auto& InputM = dae::InputManager::GetInstance();
	if (InputM.IsPressed(dae::ControllerButton::DPADUP) && CanMoveInDir(MoveDirection::UP))
	{
		DpadUp->ExecuteR();
	}
	else if (InputM.IsPressed(dae::ControllerButton::DPADDOWN) && CanMoveInDir(MoveDirection::DOWN))
	{
		DpadDown->ExecuteR();
	}
	else if (InputM.IsPressed(dae::ControllerButton::DPADRIGHT) && CanMoveInDir(MoveDirection::RIGHT))
	{
		DpadRight->ExecuteR();
	}
	else if (InputM.IsPressed(dae::ControllerButton::DPADLEFT) && CanMoveInDir(MoveDirection::LEFT))
	{
		DpadLeft->ExecuteR();
	}
}