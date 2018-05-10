#pragma once
#include <memory>

#include "Transform.h"
#include "Texture2D.h"
#include "SceneObject.h"
#include "BaseComponent.h"

namespace dae
{
	class GameObject
	{
	public:
		void Update(const float deltaTime);
		void Render() const;

		//void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
		void AddComponent(std::shared_ptr<BaseComponent> comp);
		std::shared_ptr<BaseComponent> GetComponent(Types type);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform mTransform;
		std::shared_ptr<Texture2D> mTexture;
		std::vector<std::shared_ptr<BaseComponent>> m_Components;
	};
}
