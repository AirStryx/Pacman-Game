#include "MiniginPCH.h"
#include <vld.h>
#include "InputComponent.h"
#include "command.h"




InputComponent::InputComponent()
	:BaseComponent(Types::INPUT)
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::Update(const float deltaTime)
{
	dae::InputManager::GetInstance().ProcessInput(ControllerID);
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