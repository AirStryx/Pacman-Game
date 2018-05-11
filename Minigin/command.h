
#include "InputComponent.h"
class Command
{
public:
	~Command() = default;
	virtual void Execute() = 0;
};
class Up : public Command
{
public:
	Up(std::shared_ptr<InputComponent> & inp) :input(inp) {};
	void Execute() override { input->SetMoveDirection(MoveDirection::UP); };
private:
	std::shared_ptr<InputComponent> input;
};

class Down : public Command
{
public:	
	Down(std::shared_ptr<InputComponent> & inp) :input(inp) {};
		void Execute() override { input->SetMoveDirection(MoveDirection::DOWN); };
private:
	std::shared_ptr<InputComponent> input;
};

class Left : public Command
{
public:
	Left(std::shared_ptr<InputComponent> & inp) :input(inp) {};
	void Execute() override { input->SetMoveDirection(MoveDirection::LEFT); };
private:
	std::shared_ptr<InputComponent> input;
};

class Right : public Command
{
public:
	Right(std::shared_ptr<InputComponent> & inp) :input(inp) {};
	void Execute() override { input->SetMoveDirection(MoveDirection::RIGHT); };
private:
	std::shared_ptr<InputComponent> input;
};