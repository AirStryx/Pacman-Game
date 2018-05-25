#include "MiniginPCH.h"
#include "ScoreComponent.h"
#include "TextComponent.h"
#include <string>


ScoreComponent::ScoreComponent()
	:BaseComponent(Types::SCORE)
{
}


ScoreComponent::~ScoreComponent()
{
}

void ScoreComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);

	if (m_ScoreChanged)
	{
		m_ScoreChanged = false;
		std::string scoreS = std::to_string(m_Score);
		if (scoreS.length() > 1)
		{
			m_DisplayGO.lock()->SetPosition(m_origPosition.x - (scoreS.length() * 6.f), m_origPosition.y);
		}
		std::static_pointer_cast<TextComponent>(m_DisplayGO.lock()->GetComponent(Types::TEXT))->SetText(scoreS);
	}
}

void ScoreComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void ScoreComponent::Render()
{
}
