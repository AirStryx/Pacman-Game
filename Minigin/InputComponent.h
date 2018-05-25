#pragma once
#include "BaseComponent.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Structs.h"
#include "SDL_scancode.h"

class Command;
class InputComponent : public BaseComponent
	{
	public:
		InputComponent(std::shared_ptr<dae::GameObject> go);
		~InputComponent();
		void Update(const float deltaTime) override;
		void LateUpdate(const float deltaTime) override;
		void Render() override;
		void SetCommand(ControllerButton button, std::unique_ptr<Command>& com);
		void SetMoveDirection(MoveDirection dir);
		void SetController(int id) { ControllerID = id; }
		void ResetPos() { m_NewPos = m_GO.lock()->GetPosition(); }
		
		void HandleInput();

	protected:
		int ControllerID{ 0 };
		Pos m_NewPos{};
		std::unique_ptr<Command> DpadUp;
		std::unique_ptr<Command> DpadDown;
		std::unique_ptr<Command> DpadLeft;
		std::unique_ptr<Command> DpadRight;
		MoveDirection m_Direction{ MoveDirection::NONE };
		
	};
