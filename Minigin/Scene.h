#pragma once
#include "SceneManager.h"

namespace dae
{
	class GameObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(const std::shared_ptr<GameObject>& object);

		void Update(const float deltaTime);
		void Render() const;
		void SetAmountPickups(int amount) { m_PickUps = amount; }
		void DecrementPickups() { --m_PickUps; }

		std::string GetName() { return mName; }

		~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	private: 
		explicit Scene(const std::string& name);

		std::string mName{};
		std::vector < std::shared_ptr<GameObject>> mObjects{};
		int m_PickUps{ -1 };

		static unsigned int idCounter; 
	};

}
