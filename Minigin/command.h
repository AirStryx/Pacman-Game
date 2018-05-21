
#include "InputComponent.h"
#include "RailComponent.h"
#include "MenuComponent.h"
class Command
{
public:
	virtual ~Command() {};
	virtual void ExecuteI() = 0;
	virtual void ExecuteR() = 0;
	virtual void ExecuteM() = 0;
};
class Up : public Command
{
public:
	Up(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	Up(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	Up(std::shared_ptr<MenuComponent> & inp) :inputM(inp) {};
	void ExecuteI() override { inputI.lock()->SetMoveDirection(MoveDirection::UP); };
	void ExecuteR() override { inputR.lock()->SetMoveDirection(MoveDirection::UP); };
	void ExecuteM() override { inputM.lock()->HigherMenu(); }
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
	std::weak_ptr<MenuComponent> inputM;
};

class Down : public Command
{
public:
	Down(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	Down(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	Down(std::shared_ptr<MenuComponent> & inp) :inputM(inp) {};
	void ExecuteI() override { inputI.lock()->SetMoveDirection(MoveDirection::DOWN); };
	void ExecuteR() override { inputR.lock()->SetMoveDirection(MoveDirection::DOWN); };
	void ExecuteM() override { inputM.lock()->LowerMenu(); }
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
	std::weak_ptr<MenuComponent> inputM;
};

class Left : public Command
{
public:
	Left(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	Left(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	void ExecuteI() override { inputI.lock()->SetMoveDirection(MoveDirection::LEFT); };
	void ExecuteR() override { inputR.lock()->SetMoveDirection(MoveDirection::LEFT); };
	void ExecuteM() override {}
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
};

class Right : public Command
{
public:
	Right(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	Right(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	void ExecuteI() override { inputI.lock()->SetMoveDirection(MoveDirection::RIGHT); };
	void ExecuteR() override { inputR.lock()->SetMoveDirection(MoveDirection::RIGHT); };
	void ExecuteM() override {}
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
};
class StartGame : public Command
{
public:
	StartGame(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	StartGame(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	StartGame(std::shared_ptr<MenuComponent> & inp) :inputM(inp) {};
	void ExecuteI() override {};
	void ExecuteR() override {};
	void ExecuteM() override { inputM.lock()->StartGame(); }
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
	std::weak_ptr<MenuComponent> inputM;
};