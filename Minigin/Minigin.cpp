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
void LoadPickups(dae::Scene& scene, std::shared_ptr<dae::GameObject> PacMan)
{
	for (int i = 0; i < 200; i++)
	{
		auto Go = std::make_shared<dae::GameObject>();
		auto Texture = std::make_shared<TextureComponent>();
		Texture->SetTexture("PickUpSmall.png");
		Texture->setWidthHeight(32.f, 24.f);
		Go->AddComponent(Texture);
		auto pickUp = std::make_shared<PickupComponent>();
		pickUp->AddPickupper(PacMan);
		pickUp->setGO(Go);
		pickUp->SetRadius(24.f);

		switch (i)
		{
			//first row
		case 0:
			Go->SetPosition(36.f, 71.f);
			break;
		case 1:
			Go->SetPosition(72.f, 71.f);
			break;
		case 2:
			Go->SetPosition(108.f, 71.f);
			break;
		case 3:
			Go->SetPosition(144.f, 71.f);
			break;
		case 4:
			Go->SetPosition(180.f, 71.f);
			break;
		case 5:
			Go->SetPosition(216.f, 71.f);
			break;
		case 6:
			Go->SetPosition(252.f, 71.f);
			break;
		case 7:
			Go->SetPosition(288.f, 71.f);
			break;
		case 8:
			Go->SetPosition(360.f, 71.f);
			break;
		case 9:
			Go->SetPosition(396.f, 71.f);
			break;
		case 10:
			Go->SetPosition(432.f, 71.f);
			break;
		case 11:
			Go->SetPosition(468.f, 71.f);
			break;
		case 12:
			Go->SetPosition(504.f, 71.f);
			break;
		case 13:
			Go->SetPosition(540.f, 71.f);
			break;
		case 14:
			Go->SetPosition(576.f, 71.f);
			break;
		case 15:
			Go->SetPosition(612.f, 71.f);
			break;
			//second row
		case 16:
			Go->SetPosition(36.f, 103.f);
			break;
		case 17:
			Go->SetPosition(144.f, 103.f);
			break;
		case 18:
			Go->SetPosition(288.f, 103.f);
			break;
		case 19:
			Go->SetPosition(360.f, 103.f);
			break;
		case 20:
			Go->SetPosition(504.f, 103.f);
			break;
		case 21:
			Go->SetPosition(612.f, 103.f);
			break;
			//third row
		case 23:
			Go->SetPosition(36.f, 135.f);
			break;
		case 24:
			Go->SetPosition(144.f, 135.f);
			break;
		case 25:
			Go->SetPosition(288.f, 135.f);
			break;
		case 26:
			Go->SetPosition(360.f, 135.f);
			break;
		case 27:
			Go->SetPosition(504.f, 135.f);
			break;
		case 28:
			Go->SetPosition(612.f, 135.f);
			break;
			//fourth row
		case 29:
			Go->SetPosition(36.f, 167.f);
			break;
		case 30:
			Go->SetPosition(72.f, 167.f);
			break;
		case 31:
			Go->SetPosition(108.f, 167.f);
			break;
		case 32:
			Go->SetPosition(144.f, 167.f);
			break;
		case 33:
			Go->SetPosition(180.f, 167.f);
			break;
		case 34:
			Go->SetPosition(216.f, 167.f);
			break;
		case 35:
			Go->SetPosition(252.f, 167.f);
			break;
		case 36:
			Go->SetPosition(288.f, 167.f);
			break;
		case 37:
			Go->SetPosition(360.f, 167.f);
			break;
		case 38:
			Go->SetPosition(396.f, 167.f);
			break;
		case 39:
			Go->SetPosition(432.f, 167.f);
			break;
		case 40:
			Go->SetPosition(468.f, 167.f);
			break;
		case 41:
			Go->SetPosition(504.f, 167.f);
			break;
		case 42:
			Go->SetPosition(540.f, 167.f);
			break;
		case 43:
			Go->SetPosition(576.f, 167.f);
			break;
		case 44:
			Go->SetPosition(612.f, 167.f);
			break;
		case 46:
			Go->SetPosition(324.f, 167.f);
			break;
			//fifth row
		case 47:
			Go->SetPosition(36.f, 199.f);
			break;
		case 48:
			Go->SetPosition(144.f, 199.f);
			break;
		case 49:
			Go->SetPosition(216.f, 199.f);
			break;
		case 50:
			Go->SetPosition(432.f, 199.f);
			break;
		case 51:
			Go->SetPosition(504.f, 199.f);
			break;
		case 52:
			Go->SetPosition(612.f, 199.f);
			break;
			//sixth row
		case 53:
			Go->SetPosition(36.f, 231.f);
			break;
		case 54:
			Go->SetPosition(144.f, 231.f);
			break;
		case 55:
			Go->SetPosition(216.f, 231.f);
			break;
		case 56:
			Go->SetPosition(432.f, 230.f);
			break;
		case 57:
			Go->SetPosition(504.f, 231.f);
			break;
		case 58:
			Go->SetPosition(612.f, 231.f);
			break;
		case 59:
			Go->SetPosition(72.f, 231.f);
			break;
		case 60:
			Go->SetPosition(108.f, 231.f);
			break;
		case 61:
			Go->SetPosition(288.f, 231.f);
			break;
		case 62:
			Go->SetPosition(360.f, 231.f);
			break;
		case 63:
			Go->SetPosition(396.f, 231.f);
			break;
		case 64:
			Go->SetPosition(540.f, 231.f);
			break;
		case 65:
			Go->SetPosition(576.f, 231.f);
			break;
		case 67:
			Go->SetPosition(252.f, 231.f);
			break;
			//seventh row
		case 68:
			Go->SetPosition(144.f, 263.f);
			break;
		case 69:
			Go->SetPosition(288.f, 263.f);
			break;
		case 70:
			Go->SetPosition(360.f, 263.f);
			break;
		case 71:
			Go->SetPosition(504.f, 263.f);
			break;
			//eight row
		case 72:
			Go->SetPosition(144.f, 300.f);
			break;
		case 73:
			Go->SetPosition(216.f, 300.f);
			break;
		case 74:
			Go->SetPosition(252.f, 300.f);
			break;
		case 75:
			Go->SetPosition(288.f, 300.f);
			break;
		case 76:
			Go->SetPosition(360.f, 300.f);
			break;
		case 77:
			Go->SetPosition(396.f, 300.f);
			break;
		case 78:
			Go->SetPosition(432.f, 300.f);
			break;
		case 79:
			Go->SetPosition(504.f, 300.f);
			break;
		case 80:
			Go->SetPosition(324.f, 300.f);
			break;
			//ninth row
		case 81:
			Go->SetPosition(144.f, 332.f);
			break;
		case 82:
			Go->SetPosition(216.f, 332.f);
			break;
		case 83:
			Go->SetPosition(432.f, 332.f);
			break;
		case 84:
			Go->SetPosition(504.f, 332.f);
			break;
			//tenth row
		case 85:
			Go->SetPosition(144.f, 369.f);
			break;
		case 86:
			Go->SetPosition(180.f, 369.f);
			break;
		case 87:
			Go->SetPosition(216.f, 369.f);
			break;
		case 88:
			Go->SetPosition(432.f, 369.f);
			break;
		case 89:
			Go->SetPosition(468.f, 369.f);
			break;
		case 90:
			Go->SetPosition(504.f, 369.f);
			break;
			//eleventh row
		case 91:
			Go->SetPosition(144.f, 401.f);
			break;
		case 92:
			Go->SetPosition(216.f, 401.f);
			break;
		case 93:
			Go->SetPosition(432.f, 401.f);
			break;
		case 94:
			Go->SetPosition(504.f, 401.f);
			break;
			//twelveth row
		case 95:
			Go->SetPosition(144.f, 438.f);
			break;
		case 96:
			Go->SetPosition(216.f, 438.f);
			break;
		case 97:
			Go->SetPosition(252.f, 438.f);
			break;
		case 98:
			Go->SetPosition(288.f, 438.f);
			break;
		case 99:
			Go->SetPosition(360.f, 438.f);
			break;
		case 100:
			Go->SetPosition(396.f, 438.f);
			break;
		case 101:
			Go->SetPosition(432.f, 438.f);
			break;
		case 102:
			Go->SetPosition(504.f, 438.f);
			break;
		case 103:
			Go->SetPosition(324.f, 438.f);
			break;
			//thirteenth row
		case 104:
			Go->SetPosition(144.f, 470.f);
			break;
		case 105:
			Go->SetPosition(216.f, 470.f);
			break;
		case 106:
			Go->SetPosition(432.f, 470.f);
			break;
		case 107:
			Go->SetPosition(504.f, 470.f);
			break;
			//fourteenth row
		case 108:
			Go->SetPosition(36.f, 510.f);
			break;
		case 109:
			Go->SetPosition(72.f, 510.f);
			break;
		case 110:
			Go->SetPosition(108.f, 510.f);
			break;
		case 111:
			Go->SetPosition(144.f, 510.f);
			break;
		case 112:
			Go->SetPosition(180.f, 510.f);
			break;
		case 113:
			Go->SetPosition(216.f, 510.f);
			break;
		case 114:
			Go->SetPosition(252.f, 510.f);
			break;
		case 115:
			Go->SetPosition(288.f, 510.f);
			break;
		case 116:
			Go->SetPosition(360.f, 510.f);
			break;
		case 117:
			Go->SetPosition(396.f, 510.f);
			break;
		case 118:
			Go->SetPosition(432.f, 510.f);
			break;
		case 119:
			Go->SetPosition(468.f, 510.f);
			break;
		case 120:
			Go->SetPosition(504.f, 510.f);
			break;
		case 121:
			Go->SetPosition(540.f, 510.f);
			break;
		case 122:
			Go->SetPosition(576.f, 510.f);
			break;
		case 124:
			Go->SetPosition(612.f, 510.f);
			break;
			//fifteenth row
		case 125:
			Go->SetPosition(36.f, 542.f);
			break;
		case 126:
			Go->SetPosition(144.f, 542.f);
			break;
		case 127:
			Go->SetPosition(288.f, 542.f);
			break;
		case 128:
			Go->SetPosition(360.f, 542.f);
			break;
		case 129:
			Go->SetPosition(504.f, 542.f);
			break;
		case 130:
			Go->SetPosition(612.f, 542.f);
			break;
			//sixteenth row
		case 131:
			Go->SetPosition(36.f, 578.f);
			break;
		case 132:
			Go->SetPosition(72.f, 578.f);
			break;
		case 133:
			Go->SetPosition(144.f, 578.f);
			break;
		case 134:
			Go->SetPosition(180.f, 578.f);
			break;
		case 135:
			Go->SetPosition(216.f, 578.f);
			break;
		case 136:
			Go->SetPosition(252.f, 578.f);
			break;
		case 137:
			Go->SetPosition(288.f, 578.f);
			break;
		case 138:
			Go->SetPosition(360.f, 578.f);
			break;
		case 139:
			Go->SetPosition(396.f, 510.f);
			break;
		case 140:
			Go->SetPosition(432.f, 510.f);
			break;
		case 141:
			Go->SetPosition(468.f, 510.f);
			break;
		case 142:
			Go->SetPosition(504.f, 510.f);
			break;
		
		case 144:
			Go->SetPosition(576.f, 510.f);
			break;
		case 145:
			Go->SetPosition(612.f, 510.f);
			break;
		default:
			Go->SetPosition(0.f, -100.f);
			break;
		}
		
		Go->AddComponent(pickUp);
		scene.Add(Go);
	}
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
	PacManGO->SetPosition(300.f, 350.f);
	scene.Add(PacManGO);

	LoadPickups(scene, PacManGO);
	//PickupTest
	

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

