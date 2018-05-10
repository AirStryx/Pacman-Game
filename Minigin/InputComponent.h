#pragma once
#include "BaseComponent.h"
class InputComponent : public BaseComponent
{
public:
	InputComponent();
	~InputComponent();
	void Update(const float deltaTime) override;
	void Render() override;
};

