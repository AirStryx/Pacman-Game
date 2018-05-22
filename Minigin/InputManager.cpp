#include "MiniginPCH.h"
#include "InputManager.h"
#include "Structs.h"
#include <SDL.h>


bool dae::InputManager::ProcessInput(int controller)
{
	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	up = false;
	down = false;
	left = false;
	right = false;
	enter = false;

	XInputGetState(controller, &currentState);
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	//for Keyboard inputs
	switch (controller)
	{
	case 0:
		if (state[SDL_SCANCODE_W])
		{
			up = true;
		}
		if (state[SDL_SCANCODE_S])
		{
			down = true;
		}
		if (state[SDL_SCANCODE_A])
		{
			left = true;
		}
		if (state[SDL_SCANCODE_D])
		{
			right = true;
		}
		if (state[SDL_SCANCODE_RETURN])
		{
			enter = true;
		}
		break;
	case 1:
		if (state[SDL_SCANCODE_UP])
		{
			up = true;
		}
		if (state[SDL_SCANCODE_DOWN])
		{
			down = true;
		}
		if (state[SDL_SCANCODE_LEFT])
		{
			left = true;
		}
		if (state[SDL_SCANCODE_RIGHT])
		{
			right = true;
		}
		break;
	default:
		break;
	}
	return true;
}

bool dae::InputManager::CheckForQuit()
{

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
		return (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) || up;
	case ControllerButton::DPADDOWN:
		return (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) || down;
	case ControllerButton::DPADLEFT:
		return (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) || left;
	case ControllerButton::DPADRIGHT:
		return (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) || right;
	case ControllerButton::A:
		return (currentState.Gamepad.wButtons & XINPUT_GAMEPAD_A) || enter;
	default: return false;
	}
}

