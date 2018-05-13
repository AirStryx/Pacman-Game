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
#include "InputComponent.h"
#include "PickupComponent.h"
#include "command.h"
#include "PickupLoadHelper.h"
#include "ScoreComponent.h"

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
		650,                    
		780,                    
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

	//Level
	auto Go = std::make_shared<dae::GameObject>();
	auto Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("PacManBG.png");
	Texture->SetPosition(0, 60.f);
	Go->AddComponent(Texture);
	scene.Add(Go);

	//"High Score" text
	Go = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 32);
	auto text = std::make_shared<TextComponent>();
	text->SetText("High Score");
	text->SetFont(font);
	Go->AddComponent(text);
	Go->SetPosition(250, 1);
	scene.Add(Go);

	//Score Text
	auto ScoreGO = std::make_shared<dae::GameObject>();
    font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 32);
    text = std::make_shared<TextComponent>();
	text->SetText("0");
	text->SetFont(font);
	ScoreGO->AddComponent(text);
	ScoreGO->SetPosition(313, 30);
	scene.Add(ScoreGO);


	//PacMan
	auto PacManGO = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("UsePacMan.png");
	Texture->setWidthHeight(32.f, 35.f);
	PacManGO->AddComponent(Texture);
	auto input = std::make_shared<InputComponent>();
	input->SetGameObj(PacManGO);
	std::unique_ptr<Command> com;
	com = std::make_unique<Up>(input);
	input->SetCommand(dae::ControllerButton::DPADUP, com);
	com = std::make_unique<Down>(input);
	input->SetCommand(dae::ControllerButton::DPADDOWN, com);
	com = std::make_unique<Right>(input);
	input->SetCommand(dae::ControllerButton::DPADRIGHT, com);
	com = std::make_unique<Left>(input);
	input->SetCommand(dae::ControllerButton::DPADLEFT, com);
	PacManGO->AddComponent(input);
	PacManGO->SetPosition(20.f, 363.f);
	auto score = std::make_shared<ScoreComponent>();
	score->setDisplay(ScoreGO);
	PacManGO->AddComponent(score);
	scene.Add(PacManGO);

	//load all the pickups
	LoadPickups(scene, PacManGO);
	

	//FPS
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

	//stop test
	dae::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

