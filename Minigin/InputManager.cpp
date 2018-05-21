#include "MiniginPCH.h"
#include "InputManager.h"
#include "Structs.h"
#include <SDL.h>


bool dae::InputManager::ProcessInput(int controller)
{
	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	XInputGetState(controller, &currentState);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
	}

	return true;
}

bool dae::InputManager::IsPressed(ControllerButton button) const
{
	switch (button)
	{
	case ControllerButton::DPADUP:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP;
	case ControllerButton::DPADDOWN:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN;
	case ControllerButton::DPADLEFT:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT;
	case ControllerButton::DPADRIGHT:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT;
	case ControllerButton::A:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
	default: return false;
	}
}

