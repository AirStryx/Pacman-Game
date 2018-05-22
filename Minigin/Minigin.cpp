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
#include "RailComponent.h"
#include "MoveComponent.h"
#include "MoveRailComponent.h"
#include "MenuComponent.h"
#include "LivesComponent.h"
#include "PlayerCollision.h"

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

			sceneManager.Update(deltaTime);
			renderer.Render();

			lastTime = currentTime;
			
			doContinue = input.CheckForQuit();

			if (sceneManager.WantReset())
			{
				sceneManager.ClearScenes();
				LoadGame();
				sceneManager.IsReset();
			}
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
void LoadMainMenu()
{
	auto& Mainscene = dae::SceneManager::GetInstance().CreateScene("MainMenu");
	auto Maingo = std::make_shared<dae::GameObject>();
	auto Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("MainMenu.png");
	Maingo->AddComponent(Texture);
	auto mainMenC = std::make_shared<MenuComponent>();
	mainMenC->SetController(0);

	std::unique_ptr<Command> Maincom;
	Maincom = std::make_unique<StartGame>(mainMenC);
	mainMenC->SetCommand(ControllerButton::A, Maincom);
	Maincom = std::make_unique<Up>(mainMenC);
	mainMenC->SetCommand(ControllerButton::DPADUP, Maincom);
	Maincom = std::make_unique<Down>(mainMenC);
	mainMenC->SetCommand(ControllerButton::DPADDOWN, Maincom);

	Maingo->AddComponent(mainMenC);
	Mainscene.Add(Maingo);

	auto go = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	auto text = std::make_shared<TextComponent>();
	text->SetText("1 Player");
	text->SetFont(font);
	go->AddComponent(text);
	go->SetPosition(200, 450);
	mainMenC->AddMenuOption(go, "LevelSolo");
	Mainscene.Add(go);

	go = std::make_shared<dae::GameObject>();
	text = std::make_shared<TextComponent>();
	text->SetText("2 Player: Pacman and Ms. Pacman");
	text->SetFont(font);
	go->AddComponent(text);
	go->SetPosition(200, 500);
	mainMenC->AddMenuOption(go, "LevelCoop");
	Mainscene.Add(go);

	go = std::make_shared<dae::GameObject>();
	text = std::make_shared<TextComponent>();
	text->SetText("2 Player: Pacman and Ghost");
	text->SetFont(font);
	go->AddComponent(text);
	go->SetPosition(200, 550);
	mainMenC->AddMenuOption(go, "LevelVs");
	Mainscene.Add(go);

	mainMenC->SetBig();
}
void LoadLevelSolo()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("LevelSolo");

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
	Texture->SetTexture("PacMan.png");
	Texture->setWidthHeight(32.f, 35.f);
	PacManGO->AddComponent(Texture);

	auto playerC = std::make_shared<PlayerCollisionComponent>();
	playerC->SetType(CharacterTypes::Pacman);
	playerC->SetGO(PacManGO);
	PacManGO->AddComponent(playerC);

	auto input = std::make_shared<RailComponent>();
	LoadWalkingGrid(input);
	input->SetGO(PacManGO);
	std::unique_ptr<Command> com;
	com = std::make_unique<Up>(input);
	input->SetCommand(ControllerButton::DPADUP, com);
	com = std::make_unique<Down>(input);
	input->SetCommand(ControllerButton::DPADDOWN, com);
	com = std::make_unique<Right>(input);
	input->SetCommand(ControllerButton::DPADRIGHT, com);
	com = std::make_unique<Left>(input);
	input->SetCommand(ControllerButton::DPADLEFT, com);
	PacManGO->AddComponent(input);
	PacManGO->SetPosition(20.f, 363.f);
	PacManGO->setStartPos(Pos{ 20.f, 363.f });
	auto score = std::make_shared<ScoreComponent>();
	score->setDisplay(ScoreGO);
	PacManGO->AddComponent(score);
	scene.Add(PacManGO);

	Go = std::make_shared<dae::GameObject>();
	auto health = std::make_shared<LivesComponent>();
	Go->AddComponent(health);
	scene.Add(Go);

	playerC->SetLiveObj(Go);
	//load all the pickups
	LoadPickups(scene, PacManGO);

	//RedGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("RedGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	auto movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(500.f, 150.f);
	Go->setStartPos(Pos{ 500.f, 150.f });

	auto col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::RedGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);


	playerC->AddObject(Go);

	//YellowGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("YellowGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(360.f, 220.f);
	Go->setStartPos(Pos{ 360.f, 220.f });

	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::YellowGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);

	playerC->AddObject(Go);
	//PinkGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("PinkGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(430.f, 570.f);
	Go->setStartPos(Pos{ 430.f, 570.f });

	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::PinkGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);

	playerC->AddObject(Go);

	//BlueGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("BlueGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(505.f, 363.f);
	Go->setStartPos(Pos{ 505.f, 363.f });
	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::BlueGhost);
	col->SetGO(Go);
	Go->AddComponent(col);
	scene.Add(Go);

	playerC->AddObject(Go);

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
void LoadLevelVS()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("LevelVs");

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
	Texture->SetTexture("PacMan.png");
	Texture->setWidthHeight(32.f, 35.f);
	PacManGO->AddComponent(Texture);

	auto playerC = std::make_shared<PlayerCollisionComponent>();
	playerC->SetType(CharacterTypes::Pacman);
	playerC->SetGO(PacManGO);
	PacManGO->AddComponent(playerC);

	auto input = std::make_shared<RailComponent>();
	LoadWalkingGrid(input);
	input->SetGO(PacManGO);
	std::unique_ptr<Command> com;
	com = std::make_unique<Up>(input);
	input->SetCommand(ControllerButton::DPADUP, com);
	com = std::make_unique<Down>(input);
	input->SetCommand(ControllerButton::DPADDOWN, com);
	com = std::make_unique<Right>(input);
	input->SetCommand(ControllerButton::DPADRIGHT, com);
	com = std::make_unique<Left>(input);
	input->SetCommand(ControllerButton::DPADLEFT, com);
	PacManGO->AddComponent(input);
	PacManGO->SetPosition(20.f, 363.f);
	PacManGO->setStartPos(Pos{ 20.f, 363.f });
	auto score = std::make_shared<ScoreComponent>();
	score->setDisplay(ScoreGO);
	PacManGO->AddComponent(score);
	scene.Add(PacManGO);

	Go = std::make_shared<dae::GameObject>();
	auto health = std::make_shared<LivesComponent>();
	Go->AddComponent(health);
	scene.Add(Go);

	playerC->SetLiveObj(Go);
	//load all the pickups
	LoadPickups(scene, PacManGO);

	//RedGhost
	auto redGo = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("RedGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(redGo);
	redGo->AddComponent(Texture);

	auto col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::RedGhost);
	col->SetGO(redGo);
	redGo->AddComponent(col);

	input = std::make_shared<RailComponent>();
	input->SetGO(redGo);
	input->SetController(1);
	LoadWalkingGrid(input);
	com = std::make_unique<Up>(input);
	input->SetCommand(ControllerButton::DPADUP, com);
	com = std::make_unique<Down>(input);
	input->SetCommand(ControllerButton::DPADDOWN, com);
	com = std::make_unique<Right>(input);
	input->SetCommand(ControllerButton::DPADRIGHT, com);
	com = std::make_unique<Left>(input);
	input->SetCommand(ControllerButton::DPADLEFT, com);
	redGo->AddComponent(input);
	redGo->SetPosition(500.f, 150.f);
	redGo->setStartPos(Pos{ 500.f, 150.f });
	scene.Add(redGo);

	playerC->AddObject(redGo);

	//YellowGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("YellowGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	auto movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(360.f, 220.f);
	Go->setStartPos(Pos{ 360.f, 220.f });

	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::YellowGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);

	playerC->AddObject(Go);

	//PinkGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("PinkGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(430.f, 570.f);
	Go->setStartPos(Pos{ 430.f, 570.f });

	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::PinkGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);

	playerC->AddObject(Go);

	//BlueGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("BlueGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(505.f, 363.f);
	Go->setStartPos(Pos{ 505.f, 363.f });
	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::BlueGhost);
	col->SetGO(Go);
	Go->AddComponent(col);
	scene.Add(Go);

	playerC->AddObject(Go);

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
void LoadLevelcoop()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("LevelCoop");

	//Level
	auto Go = std::make_shared<dae::GameObject>();
	auto Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("PacManBG.png");
	Texture->SetPosition(0, 60.f);
	Go->AddComponent(Texture);
	scene.Add(Go);

	//"High Score" text
	Go = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	auto text = std::make_shared<TextComponent>();
	text->SetText("Score Pacman");
	text->SetFont(font);
	Go->AddComponent(text);
	Go->SetPosition(50, 1);
	scene.Add(Go);

	//Score Text
	auto ScoreGO = std::make_shared<dae::GameObject>();
	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	text = std::make_shared<TextComponent>();
	text->SetText("0");
	text->SetFont(font);
	ScoreGO->AddComponent(text);
	ScoreGO->SetPosition(113, 30);
	scene.Add(ScoreGO);

	//PacMan
	auto PacManGO = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("PacMan.png");
	Texture->setWidthHeight(32.f, 35.f);
	PacManGO->AddComponent(Texture);
	auto input = std::make_shared<RailComponent>();
	LoadWalkingGrid(input);
	input->SetGO(PacManGO);
	std::unique_ptr<Command> com;
	com = std::make_unique<Up>(input);
	input->SetCommand(ControllerButton::DPADUP, com);
	com = std::make_unique<Down>(input);
	input->SetCommand(ControllerButton::DPADDOWN, com);
	com = std::make_unique<Right>(input);
	input->SetCommand(ControllerButton::DPADRIGHT, com);
	com = std::make_unique<Left>(input);
	input->SetCommand(ControllerButton::DPADLEFT, com);
	PacManGO->AddComponent(input);
	PacManGO->SetPosition(20.f, 363.f);
	PacManGO->setStartPos(Pos{ 20.f, 363.f });
	auto score = std::make_shared<ScoreComponent>();
	score->setDisplay(ScoreGO);
	PacManGO->AddComponent(score);
	scene.Add(PacManGO);

	auto playerC = std::make_shared<PlayerCollisionComponent>();
	playerC->SetType(CharacterTypes::Pacman);
	playerC->SetGO(PacManGO);
	PacManGO->AddComponent(playerC);

	//"High Score" text
	Go = std::make_shared<dae::GameObject>();
	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	text = std::make_shared<TextComponent>();
	text->SetText("Score Ms.Pacman");
	text->SetFont(font);
	Go->AddComponent(text);
	Go->SetPosition(350, 1);
	scene.Add(Go);

	//Score Text
	auto msScoreGO = std::make_shared<dae::GameObject>();
	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 24);
	text = std::make_shared<TextComponent>();
	text->SetText("0");
	text->SetFont(font);
	msScoreGO->AddComponent(text);
	msScoreGO->SetPosition(513, 30);
	scene.Add(msScoreGO);

	auto msPacManGO = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("MsPacMan.png");
	Texture->setWidthHeight(32.f, 35.f);
	msPacManGO->AddComponent(Texture);

	input = std::make_shared<RailComponent>();
	input->SetController(1);
	LoadWalkingGrid(input);

	input->SetGO(msPacManGO);
	com = std::make_unique<Up>(input);
	input->SetCommand(ControllerButton::DPADUP, com);
	com = std::make_unique<Down>(input);
	input->SetCommand(ControllerButton::DPADDOWN, com);
	com = std::make_unique<Right>(input);
	input->SetCommand(ControllerButton::DPADRIGHT, com);
	com = std::make_unique<Left>(input);
	input->SetCommand(ControllerButton::DPADLEFT, com);
	msPacManGO->AddComponent(input);
	msPacManGO->SetPosition(620.f, 363.f);
	msPacManGO->setStartPos(Pos{ 620.f, 363.f });

	score = std::make_shared<ScoreComponent>();
	score->setDisplay(msScoreGO);
	msPacManGO->AddComponent(score);

	auto msPlayerC = std::make_shared<PlayerCollisionComponent>();
	msPlayerC->SetType(CharacterTypes::Pacman);
	msPlayerC->SetGO(msPacManGO);
	msPacManGO->AddComponent(msPlayerC);
	scene.Add(msPacManGO);


	Go = std::make_shared<dae::GameObject>();
	auto health = std::make_shared<LivesComponent>();
	Go->AddComponent(health);
	scene.Add(Go);

	playerC->SetLiveObj(Go);
	msPlayerC->SetLiveObj(Go);
	//load all the pickups
	LoadPickups(scene, std::vector<std::shared_ptr<dae::GameObject>>{msPacManGO, PacManGO});

	//RedGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("RedGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	auto movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(500.f, 150.f);
	Go->setStartPos(Pos{ 500.f, 150.f });

	auto col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::RedGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);

	msPlayerC->AddObject(Go);
	playerC->AddObject(Go);

	//YellowGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("YellowGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(360.f, 220.f);
	Go->setStartPos(Pos{ 360.f, 220.f });

	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::YellowGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);

	msPlayerC->AddObject(Go);
	playerC->AddObject(Go);

	//PinkGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("PinkGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(430.f, 570.f);
	Go->setStartPos(Pos{ 430.f, 570.f });

	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::PinkGhost);
	col->SetGO(Go);
	Go->AddComponent(col);

	scene.Add(Go);

	msPlayerC->AddObject(Go);
	playerC->AddObject(Go);

	//BlueGhost
	Go = std::make_shared<dae::GameObject>();
	Texture = std::make_shared<TextureComponent>();
	Texture->SetTexture("BlueGhost.png");
	Texture->setWidthHeight(35.f, 35.f);
	Texture->SetGO(Go);
	Go->AddComponent(Texture);
	movRail = std::make_shared<MoveRailComponent>();
	LoadEnemyWalkingGrid(movRail);
	movRail->SetGO(Go);
	Go->AddComponent(movRail);
	Go->SetPosition(505.f, 363.f);
	Go->setStartPos(Pos{ 505.f, 363.f });
	col = std::make_shared<PlayerCollisionComponent>();
	col->SetType(CharacterTypes::BlueGhost);
	col->SetGO(Go);
	Go->AddComponent(col);
	scene.Add(Go);

	msPlayerC->AddObject(Go);
	playerC->AddObject(Go);

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
void LoadGame()
{
	LoadMainMenu();
	LoadLevelSolo();
	LoadLevelcoop();
	LoadLevelVS();
	dae::SceneManager::GetInstance().SetActive(dae::SceneManager::GetInstance().FindScene("MainMenu"));
}

void Cleanup()
{

	//stop test
	dae::Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

