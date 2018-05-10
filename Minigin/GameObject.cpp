#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "InputComponent.h"
#include "RenderComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(const float deltaTime)
{
	for (int i = 0; i < m_Components.size(); i++)
	{
		m_Components[i]->Update(deltaTime);
	}
}

void dae::GameObject::Render() const
{
	for (int i = 0; i < m_Components.size(); i++)
	{
		m_Components[i]->Render();
	}
}

void dae::GameObject::AddComponent(std::shared_ptr<BaseComponent> comp)
{
	bool notSeen = true;
	for (int i = 0; i < m_Components.size(); i++)
	{
		if (m_Components[i]->GetType() == comp->GetType())
		{
			notSeen = false;
		}
	}
	if (notSeen)
	{
		m_Components.push_back(comp);
	}
}

std::shared_ptr<BaseComponent> dae::GameObject::GetComponent(Types type)
{
	for (int i = 0; i < m_Components.size(); i++)
	{
		if (m_Components[i]->GetType() == type)
		{
			return m_Components[i];
		}
	}
	return nullptr;
}

