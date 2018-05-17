
#include "InputComponent.h"
#include "RailComponent.h"
class Command
{
public:
	virtual ~Command() {};
	virtual void ExecuteI() = 0;
	virtual void ExecuteR() = 0;
};
class Up : public Command
{
public:
	Up(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	Up(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	void ExecuteI() override { inputI.lock()->SetMoveDirection(MoveDirection::UP); };
	void ExecuteR() override { inputR.lock()->SetMoveDirection(MoveDirection::UP); };
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
};

class Down : public Command
{
public:
	Down(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	Down(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	void ExecuteI() override { inputI.lock()->SetMoveDirection(MoveDirection::DOWN); };
	void ExecuteR() override { inputR.lock()->SetMoveDirection(MoveDirection::DOWN); };
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
};

class Left : public Command
{
public:
	Left(std::shared_ptr<InputComponent> & inp) :inputI(inp) {};
	Left(std::shared_ptr<RailComponent> & inp) :inputR(inp) {};
	void ExecuteI() override { inputI.lock()->SetMoveDirection(MoveDirection::LEFT); };
	void ExecuteR() override { inputR.lock()->SetMoveDirection(MoveDirection::LEFT); };
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
private:
	std::weak_ptr<InputComponent> inputI;
	std::weak_ptr<RailComponent> inputR;
};