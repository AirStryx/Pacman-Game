#include "MiniginPCH.h"
#include "InputComponent.h"


InputComponent::InputComponent()
	:BaseComponent(Types::INPUT)
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void InputComponent::Render()
{
}
