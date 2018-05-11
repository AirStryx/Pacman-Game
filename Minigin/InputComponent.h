#pragma once
#include "BaseComponent.h"
#include "InputManager.h"
#include "GameObject.h"
enum class MoveDirection
{
	UP, DOWN, LEFT, RIGHT, NONE
};
class Command;
class InputComponent : public BaseComponent
	{
	public:
		InputComponent();
		~InputComponent();
		void Update(const float deltaTime) override;
		void Render() override;
		void SetCommand(dae::ControllerButton button, std::unique_ptr<Command>& com);
		void SetGameObj(std::shared_ptr<dae::GameObject>& gameObj);
		void SetMoveDirection(MoveDirection dir);
		
		void HandleInput();

	private:
		std::weak_ptr<dae::GameObject> m_GameObj;
		std::unique_ptr<Command> DpadUp;
		std::unique_ptr<Command> DpadDown;
		std::unique_ptr<Command> DpadLeft;
		std::unique_ptr<Command> DpadRight;
		MoveDirection m_Direction{ MoveDirection::NONE };
	};
