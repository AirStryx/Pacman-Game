#include "MiniginPCH.h"
// ReSharper disable once CppUnusedIncludeDirective
//git test
#include <vld.h>
#pragma comment(lib,"xinput.lib")
#include "SDL.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <chrono>
#include <thread>
#include <cmath>
#include "InputManager.h"
#include "SceneManager.h"

#include "Scene.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include "TextComponent.h"
#include "TextureComponent.h"

const int msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
std::shared_ptr<dae::GameObject> m_pFPSCounter = nullptr; 

void Initialize();
void LoadGame();
void Cleanup();

#pragma warning( push )  
#pragma warning( disable : 4100 )  
int main(int argc, char* argv[]) {
#pragma warning( pop )

	Initialize();

	// tell the resource manager where he can find the game data
	dae::ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto t = std::chrono::high_resolution_clock::now();
		auto lastTime = std::chrono::high_resolution_clock::now();
		auto& renderer = dae::Renderer::GetInstance();
		auto& sceneManager = dae::SceneManager::GetInstance();
		auto& input = dae::InputManager::GetInstance();

		bool doContinue = true;
		while(doContinue) 
		{
			auto currentTime = std::chrono::high_resolution_clock::now();
			float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();

			int fps = int(1 / deltaTime);
			std::string fpsString("fps: " + std::to_string(fps));
			std::shared_ptr<TextComponent> text = std::dynamic_pointer_cast<TextComponent>(m_pFPSCounter->GetComponent(Types::TEXT));
			text->SetText(fpsString);

			doContinue = input.ProcessInput();
			sceneManager.Update(deltaTime);
			renderer.Render();

			lastTime = currentTime;
			t += std::chrono::milliseconds(msPerFrame);
			std::this_thread::sleep_until(t);
		}
	}

	Cleanup();
    return 0;
}

SDL_Window* window;

void Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::stringstream ss; ss << "SDL_Init Error: " << SDL_GetError();
		throw std::runtime_error(ss.str().c_str());
	}

	window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,                    
		480,                    
		SDL_WINDOW_OPENGL       
	);
	if (window == nullptr) {
		std::stringstream ss; ss << "SDL_CreateWindow Error: " << SDL_GetError();
		throw std::runtime_error(ss.str().c_str());
	}

	dae::Renderer::GetInstance().Init(window);
}

void LoadGame()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	
	auto go = std::make_shared<dae::GameObject>();
	auto texture = std::make_shared<TextureComponent>();
	texture->SetTexture("background.jpg");
	go->AddComponent(texture);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	texture = std::make_shared<TextureComponent>();
	texture->SetTexture("logo.png");
	texture->SetPosition(216, 180);
	go->AddComponent(texture);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::GameObject>();
	auto texComp = std::make_shared<TextComponent>();
	texComp->SetFont(font);
	texComp->SetPosition(80, 20);
	texComp->SetText("Programming 4 Assignment");
	to->AddComponent(texComp);
	scene.Add(to);

	m_pFPSCounter = std::make_shared<dae::GameObject>();
	auto secondfont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 18);
	auto secondtexComp = std::make_shared<TextComponent>();
	secondtexComp->SetPosition(10, 10);
	secondtexComp->SetText("fps: ");
	secondtexComp->SetFont(secondfont);
	m_pFPSCounter->AddComponent(secondtexComp);
	scene.Add(m_pFPSCounter);
}

void Cleanup()
{
	dae::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

