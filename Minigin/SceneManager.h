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
		void Render();
		void SetActive(int idx);

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
