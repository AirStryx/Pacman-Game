#pragma once
#include "BaseComponent.h"
#include <XInput.h>
#include <memory>

enum class ControllerButton
{
	DpadUP,
	DpadDOWN,
	DpadRIGHT,
	DpadLEFT
};
class InputComponent : public BaseComponent
{
public:
	InputComponent();
	~InputComponent();
	void Update(const float deltaTime) override;
	void Render() override;
};

