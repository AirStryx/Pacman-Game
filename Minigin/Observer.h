#pragma once
#include <iostream>
enum Achievement
{
	skippy, sneeky, genius
};
enum Event
{
	UP, DOWN, LEFT, RIGHT
};
class Observer
{
public:
	virtual ~Observer() = default;
	virtual void Notify(Event event) = 0;
};

class Achievements : public Observer
{
public:
	void Notify(Event event) override
	{
		switch (event)
		{
		case UP:
			break;
		case DOWN:
			break;
		case LEFT:
			break;
		case RIGHT:
			break;
		default:
			break;
		}
	}
private:
	int timesJumped{ 0 };
	int timesCrouched{ 0 };
	bool skippyunl{ false };
	bool sneekyunl{ false };
	bool geniusunl{ false };

	void Unlock(Achievement achiev)
	{
		switch (achiev)
		{
		case skippy:
			if (!skippyunl)
			{
				skippyunl = true;
				std::cout << "Achievement unlocked: Skippy, jumped 10 times\n";
			}
			break;
		case sneeky:
			if (!sneekyunl)
			{
				sneekyunl = true;
				std::cout << "Achievement unlocked: Sneeky, crouched 10 times\n";
			}
			break;
		case genius:
			break;
		default:
			break;
		}
	}
};

