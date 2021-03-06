#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"
//#include "Minigin.cpp"


void dae::SceneManager::Update(const float deltaTime)
{
	mScenes.at(mActiveSceneIdx)->Update(deltaTime);
}

void dae::SceneManager::LateUpdate(const float deltaTime)
{
	mScenes.at(mActiveSceneIdx)->LateUpdate(deltaTime);
}

//makes 1 scene active so it only renders/ updates the scene shown (saves power)
void dae::SceneManager::SetActive(int idx)
{
	if (idx > -1 && idx < int(mScenes.size()))
	{
		mActiveSceneIdx = idx;
		mScenes.at(mActiveSceneIdx)->ResetLocations();
	}


}

//returns scene idx if not found it will return -1
int dae::SceneManager::FindScene(std::string Name)
{
	for (int i = 0; i < int(mScenes.size()); ++i)
	{
		if (mScenes[i]->GetName() == Name)
		{
			return i;
		}
	}
	return -1;
}

void dae::SceneManager::ResetGame()
{
	wantReset = true;
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	mScenes.push_back(scene);
	return *scene;
}
