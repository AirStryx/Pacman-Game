#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"

unsigned int dae::Scene::idCounter = 0;

dae::Scene::Scene(const std::string& name) : mName(name) {}

dae::Scene::~Scene() = default;

void dae::Scene::Add(const std::shared_ptr<GameObject>& object)
{
	mObjects.push_back(object);
}

void dae::Scene::Update(const float deltaTime)
{
	for(auto gameObject : mObjects)
	{
		gameObject->Update(deltaTime);
	}
	if (m_PickUps != -1)
	{
		if (m_PickUps == 0)
		{
			dae::SceneManager::GetInstance().ResetGame();
		}
	}	
}

void dae::Scene::Render() const
{
	for (const auto gameObject : mObjects)
	{
		gameObject->Render();
	}
}

