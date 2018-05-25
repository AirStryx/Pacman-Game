#include "MiniginPCH.h"
#include "MenuComponent.h"
#include "SceneManager.h"
#include "Structs.h"
#include "command.h"
#include "TextComponent.h"


MenuComponent::MenuComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::MENU, go)
{
}


MenuComponent::~MenuComponent()
{
}

void MenuComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	dae::InputManager::GetInstance().ProcessInput(m_ControllerID);
	HandleInput();
	m_CurrCount += deltaTime;
}

void MenuComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void MenuComponent::Render()
{
}

void MenuComponent::SetCommand(ControllerButton button, std::unique_ptr<Command>& com)
{
	if (button == ControllerButton::A)
	{
		A = std::move(com);
	}
	if (button == ControllerButton::DPADUP)
	{
		DPADUP = std::move(com);
	}
	if (button == ControllerButton::DPADDOWN)
	{
		DPADDOWN = std::move(com);
	}
}

void MenuComponent::StartGame()
{
	dae::SceneManager::GetInstance().SetActive(dae::SceneManager::GetInstance().FindScene(m_LevelNames.at(m_idx)));
}

void MenuComponent::LowerMenu()
{
	if (m_CurrCount >= m_timePerMov)
	{
		m_CurrCount = 0;
		auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
		if (m_idx < int(m_MainOptions.size()))
		{
			auto text = std::static_pointer_cast<TextComponent>(m_MainOptions.at(m_idx).lock()->GetComponent(Types::TEXT));
			if (text != nullptr)
			{
				text->SetFont(font);
				++m_idx;
			}
			
			
		}
		if (m_idx >= int(m_MainOptions.size()))
		{
			m_idx = int(m_MainOptions.size()) - 1;
		}

		SetBig();
	}

}

void MenuComponent::HigherMenu()
{
	if (m_CurrCount >= m_timePerMov)
	{
		m_CurrCount = 0;
		auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
		if (m_idx > 0)
		{
			auto text = std::static_pointer_cast<TextComponent>(m_MainOptions.at(m_idx).lock()->GetComponent(Types::TEXT));
			if (text != nullptr)
			{
				text->SetFont(font);
				--m_idx;
			}
		}
		SetBig();
	}
}

void MenuComponent::SetBig()
{
	if (m_MainOptions.size() > 0)
	{
		auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 28);
		auto text = std::static_pointer_cast<TextComponent>(m_MainOptions.at(m_idx).lock()->GetComponent(Types::TEXT));
		if (text != nullptr)
		{
			text->SetFont(font);
		}
	}
}

void MenuComponent::HandleInput()
{
	auto& InputM = dae::InputManager::GetInstance();
	if (InputM.IsPressed(ControllerButton::A))
	{
		A->ExecuteM();
	}
	if (InputM.IsPressed(ControllerButton::DPADUP))
	{
		DPADUP->ExecuteM();
	}
	if (InputM.IsPressed(ControllerButton::DPADDOWN))
	{
		DPADDOWN->ExecuteM();
	}
}
