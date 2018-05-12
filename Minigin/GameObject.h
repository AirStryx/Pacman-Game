#pragma once
#include <memory>

#include "Transform.h"
#include "Texture2D.h"
#include "SceneObject.h"
#include "BaseComponent.h"

namespace dae
{
	struct Pos
	{
		float x, y;
	};
	class GameObject
	{
	public:
		void Update(const float deltaTime);
		void Render() const;

		void SetPosition(float x, float y);
		Pos GetPosition() { return m_Position; };
		void AddComponent(std::shared_ptr<BaseComponent> comp);
		std::shared_ptr<BaseComponent> GetComponent(Types type);
		void Kill() { m_IsAlive = false; }

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		bool m_IsAlive{ true };
		Transform mTransform;
		std::shared_ptr<Texture2D> mTexture;
		std::vector<std::shared_ptr<BaseComponent>> m_Components;
		Pos m_Position{ 0,0 };
	};
}
