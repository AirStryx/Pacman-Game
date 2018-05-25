#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "GameObject.h"


RenderComponent::RenderComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::RENDER, go)
{
}


RenderComponent::~RenderComponent()
{
}

void RenderComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	m_GO.lock()->Render();
}

void RenderComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void RenderComponent::Render()
{
}
