#include "MiniginPCH.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "InputComponent.h"
#include "RenderComponent.h"
#include "TextureComponent.h"

#include "RailComponent.h"
#include "MoveRailComponent.h"
#include "MoveComponent.h"
#include "InputComponent.h"

#include "TextComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(const float deltaTime)
{
	if (m_IsAlive)
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->Update(deltaTime);
		}
	}
}

void dae::GameObject::LateUpdate(const float deltaTime)
{
	if (m_IsAlive)
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->LateUpdate(deltaTime);
		}
	}
}

void dae::GameObject::Render() const
{

	if (m_IsAlive)
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->Render();
		}
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	std::shared_ptr<TextureComponent> texture = std::static_pointer_cast<TextureComponent>(GetComponent(Types::TEXTURE));

	if (texture != nullptr)
	{
		float w = texture->getWidth() / 2;
		float h = texture->getHeight() / 2;

		texture->SetPosition(m_Position.x - w, m_Position.y + h);

	}
	std::shared_ptr<TextComponent> text = std::static_pointer_cast<TextComponent>(GetComponent(Types::TEXT));
	if (text != nullptr)
	{
		text->SetPosition(m_Position.x, m_Position.y);
	}

}

void dae::GameObject::ResetPos()
{
	std::shared_ptr<RailComponent> r = std::static_pointer_cast<RailComponent>(GetComponent(Types::INPUT));
	std::shared_ptr<MoveRailComponent> mr = std::static_pointer_cast<MoveRailComponent>(GetComponent(Types::MOVE));
	std::shared_ptr<InputComponent> i = std::static_pointer_cast<InputComponent>(GetComponent(Types::INPUT));
	std::shared_ptr<MoveComponent> m = std::static_pointer_cast<MoveComponent>(GetComponent(Types::MOVE));

	if (r != nullptr || mr != nullptr || i != nullptr || m != nullptr)
	{
		SetPosition(m_StartPos.x, m_StartPos.y);
		SetOldPos(Pos{ m_StartPos.x, m_StartPos.y });


		if (r != nullptr)
		{
			r->ResetPos();
		}

		if (mr != nullptr)
		{
			mr->ResetPos();
		}

		if (i != nullptr)
		{
			i->ResetPos();
		}

		if (m != nullptr)
		{
			m->ResetPos();
		}
	}
	
}

Pos dae::GameObject::GetPosition()
{
	return m_Position;
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

