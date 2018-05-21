#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Structs.h"
class LivesComponent : public BaseComponent
{
public:
	LivesComponent();
	~LivesComponent();
	void Update(const float deltaTime) override;
	void Render() override;
	void Hit() { --m_Lives; }

	void SetLives(int lives) { m_Lives = lives; }

private:
	int m_Lives{ 3 };

};

