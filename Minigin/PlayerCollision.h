#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Structs.h"
class PlayerCollision : public BaseComponent
{
public:
	PlayerCollision();
	~PlayerCollision();
	void Update(const float deltaTime) override;
	void Render() override;

	void GotHit();
	void SetType(CharacterTypes type) { m_Type = type; }
	void AddObject(std::shared_ptr<dae::GameObject> obj) { m_ObjectsToCheck.push_back(obj); }
	void SetLiveObj(std::weak_ptr<dae::GameObject> obj) { m_SetLiveObj = true; m_LiveObj = obj; }
private:
	bool m_SetLiveObj{ false };
	CharacterTypes m_Type{ CharacterTypes::Ghost };
	std::vector<std::weak_ptr<dae::GameObject>> m_ObjectsToCheck;
	std::weak_ptr<dae::GameObject> m_LiveObj;
};

