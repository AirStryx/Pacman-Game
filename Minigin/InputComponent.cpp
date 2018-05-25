#include "MiniginPCH.h"
#include <vld.h>
#include "InputComponent.h"
#include "command.h"




InputComponent::InputComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::INPUT, go)
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::Update(const float deltaTime)
{
	dae::InputManager::GetInstance().ProcessInput(ControllerID);
	HandleInput();
	m_GO.lock()->SetOldPos(m_GO.lock()->GetPosition());
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

void InputComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	m_GO.lock()->SetPosition(m_NewPos.x, m_NewPos.y);
}

void InputComponent::Render()
{
}
void InputComponent::SetCommand(ControllerButton button, std::unique_ptr<Command>& com)
{
	switch (button)
	{
	case ControllerButton::DPADUP:
		DpadUp = std::move(com);
		break;
	case ControllerButton::DPADDOWN:
		DpadDown = std::move(com);
		break;
	case ControllerButton::DPADLEFT:
		DpadLeft = std::move(com);
		break;
	case ControllerButton::DPADRIGHT:
		DpadRight = std::move(com);
		break;
	default:
		break;
	}
}
void InputComponent::HandleInput()
{
	auto& InputM = dae::InputManager::GetInstance();
	if (InputM.IsPressed(ControllerButton::DPADUP))
	{
		DpadUp->ExecuteI();
	}
	else if (InputM.IsPressed(ControllerButton::DPADDOWN))
	{
		DpadDown->ExecuteI();
	}
	else if (InputM.IsPressed(ControllerButton::DPADRIGHT))
	{
		DpadRight->ExecuteI();
	}
	else if (InputM.IsPressed(ControllerButton::DPADLEFT))
	{
		DpadLeft->ExecuteI();
	}
}

void InputComponent::SetMoveDirection(MoveDirection dir)
{
	switch (dir)
	{
	case MoveDirection::UP:
		m_Direction = MoveDirection::UP;
		break;
	case MoveDirection::DOWN:
		m_Direction = MoveDirection::DOWN;
		break;
	case MoveDirection::LEFT:
		m_Direction = MoveDirection::LEFT;
		break;
	case MoveDirection::RIGHT:
		m_Direction = MoveDirection::RIGHT;
		break;
	case MoveDirection::NONE:
		m_Direction = MoveDirection::NONE;
		break;
	default:
		break;
	}
}