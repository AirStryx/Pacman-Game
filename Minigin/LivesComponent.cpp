#include "MiniginPCH.h"
#include "LivesComponent.h"
#include "SceneManager.h"


LivesComponent::LivesComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::LIFE, go)
{
}


LivesComponent::~LivesComponent()
{
}

void LivesComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);	
}

void LivesComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void LivesComponent::Render()
{
}

void LivesComponent::Hit()
{
	--m_Lives;
	if (m_Lives <= 0)
	{
		dae::SceneManager::GetInstance().ResetGame();
	}
}
