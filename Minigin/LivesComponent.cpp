#include "MiniginPCH.h"
#include "LivesComponent.h"
#include "SceneManager.h"


LivesComponent::LivesComponent()
	:BaseComponent(Types::LIFE)
{
}


LivesComponent::~LivesComponent()
{
}

void LivesComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	if (m_Lives <= 0)
	{
		dae::SceneManager::GetInstance().ResetGame();
	}
}

void LivesComponent::Render()
{
}
