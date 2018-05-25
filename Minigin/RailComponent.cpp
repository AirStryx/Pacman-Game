#include "MiniginPCH.h"
#include "RailComponent.h"
#include "InputComponent.h"
#include "TextureComponent.h"
#include "command.h"
#include "Renderer.h"

RailComponent::RailComponent(std::shared_ptr<dae::GameObject> go)
	:InputComponent(go)
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

	Pos test1 = m_GO.lock()->GetPosition();
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
	Pos test2 = m_GO.lock()->GetPosition();
	//if it is set everything accordingly
	if (m_InRangeOfCP)
	{
		m_AllowedDirection = m_LastCP.m_AllowedDirections;
	}
	Pos test3 = m_GO.lock()->GetPosition();
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
	dae::InputManager::GetInstance().ProcessInput(ControllerID);
	HandleInput();
	Pos test = m_GO.lock()->GetPosition();
	m_GO.lock()->SetOldPos(test);
	switch (m_Direction)
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

void RailComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	m_GO.lock()->SetPosition(m_NewPos.x, m_NewPos.y);
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
	if (InputM.IsPressed(ControllerButton::DPADUP) && CanMoveInDir(MoveDirection::UP))
	{
		DpadUp->ExecuteR();
	}
	else if (InputM.IsPressed(ControllerButton::DPADDOWN) && CanMoveInDir(MoveDirection::DOWN))
	{
		DpadDown->ExecuteR();
	}
	else if (InputM.IsPressed(ControllerButton::DPADRIGHT) && CanMoveInDir(MoveDirection::RIGHT))
	{
		DpadRight->ExecuteR();
	}
	else if (InputM.IsPressed(ControllerButton::DPADLEFT) && CanMoveInDir(MoveDirection::LEFT))
	{
		DpadLeft->ExecuteR();
	}
}