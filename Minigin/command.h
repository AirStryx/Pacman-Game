
#include "InputComponent.h"
class Command
{
public:
	virtual ~Command() {};
	virtual void Execute() = 0;
};
class Up : public Command
{
public:
	Up(std::shared_ptr<InputComponent> & inp) :input(inp) {};
	void Execute() override { input.lock()->SetMoveDirection(MoveDirection::UP); };
private:
	std::weak_ptr<InputComponent> input;
};

class Down : public Command
{
public:	
	Down(std::shared_ptr<InputComponent> & inp) :input(inp) {};
		void Execute() override { input.lock()->SetMoveDirection(MoveDirection::DOWN); };
private:
	std::weak_ptr<InputComponent> input;
};

class Left : public Command
{
public:
	Left(std::shared_ptr<InputComponent> & inp) :input(inp) {};
	void Execute() override { input.lock()->SetMoveDirection(MoveDirection::LEFT); };
private:
	std::weak_ptr<InputComponent> input;
};

class Right : public Command
{
public:
	Right(std::shared_ptr<InputComponent> & inp) :input(inp) {};
	void Execute() override { input.lock()->SetMoveDirection(MoveDirection::RIGHT); };
private:
	std::weak_ptr<InputComponent> input;
};