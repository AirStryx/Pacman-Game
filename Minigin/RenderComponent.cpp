#include "MiniginPCH.h"
#include "RenderComponent.h"


RenderComponent::RenderComponent()
	:BaseComponent(Types::RENDER)
{
}


RenderComponent::~RenderComponent()
{
}

void RenderComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void RenderComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void RenderComponent::Render()
{
}
