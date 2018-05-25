#pragma once
#include "Singleton.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene & CreateScene(const std::string& name);

		void Update(const float deltaTime);
		void LateUpdate(const float deltaTime);
		void SetActive(int idx);

		std::weak_ptr<Scene> GetActiveScene() { return mScenes.at(mActiveSceneIdx); }
		int FindScene(std::string Name);
		void ResetGame();
		void IsReset() { wantReset = false; }
		void ClearScenes() { mScenes.clear(); }

		bool WantReset() { return wantReset; }
	private:
		std::vector<std::shared_ptr<Scene>> mScenes;
		bool wantReset{ false };
		int mActiveSceneIdx;
	};

}
