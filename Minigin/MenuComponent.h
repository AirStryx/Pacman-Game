#pragma once
#include "BaseComponent.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Structs.h"

class Command;
class MenuComponent : public BaseComponent
{
public:
	MenuComponent(std::shared_ptr<dae::GameObject> go);
	~MenuComponent();
	void Update(const float deltaTime) override;
	void LateUpdate(const float deltaTime) override;

	void Render() override;
	void SetCommand(ControllerButton button, std::unique_ptr<Command>& com);
	void StartGame();
	void AddMenuOption(std::weak_ptr<dae::GameObject> obj, std::string name) { m_MainOptions.push_back(obj); m_LevelNames.push_back(name); }
	void LowerMenu();
	void HigherMenu();
	void SetBig();
	void SetController(int id) { m_ControllerID =id; }

	void HandleInput();

protected:
	int m_idx{ 0 };
	float m_CurrCount{ 0.2f };
	const float m_timePerMov{ 0.2f };
	std::unique_ptr<Command> A;
	std::unique_ptr<Command> DPADUP;
	std::unique_ptr<Command> DPADDOWN;
	std::vector <std::weak_ptr<dae::GameObject>> m_MainOptions;
	std::vector <std::string> m_LevelNames;
	int m_ControllerID{ 0 };
};

