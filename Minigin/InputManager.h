#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Structs.h"

namespace dae
{

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput(int controller);
		bool CheckForQuit();
		bool IsPressed(ControllerButton button) const;
	private:
		XINPUT_STATE currentState{};
		bool up{ false };
		bool down{ false };
		bool left{ false };
		bool right{ false };
		bool enter{ false };
	};

}
