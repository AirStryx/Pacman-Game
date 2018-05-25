#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "TextComponent.h"
#include "GameObject.h"

FPSComponent::FPSComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::FPS, go)
{
}


FPSComponent::~FPSComponent()
{
}

void FPSComponent::Update(const float deltaTime)
{
	auto text = std::static_pointer_cast<TextComponent>(m_GO.lock()->GetComponent(Types::TEXT));
	if (text != nullptr)
	{
		int fps = int(1 / deltaTime);
		std::string fpsString = std::to_string(fps);
		text->SetText(fpsString);
	}
}

void FPSComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void FPSComponent::Render()
{
}
