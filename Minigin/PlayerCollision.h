#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Structs.h"
class PlayerCollisionComponent : public BaseComponent
{
public:
	PlayerCollisionComponent();
	~PlayerCollisionComponent();
	void Update(const float deltaTime) override;
	void Render() override;

	void GotHit();
	void SetType(CharacterTypes type) { m_Type = type; }
	void AddObject(std::shared_ptr<dae::GameObject> obj) { m_ObjectsToCheck.push_back(obj); }
	void SetLiveObj(std::weak_ptr<dae::GameObject> obj) { m_SetLiveObj = true; m_LiveObj = obj; }

	CharacterTypes GetType() { return m_Type; }

	void ResetTexture();
	void MakeScared();
	void MakeStrong();
private:
	bool m_SetLiveObj{ false };
	bool m_ISScared{ false };
	float m_strongTimer{ 0.f };
	const float m_strongMax{10.f};
	CharacterTypes m_Type{ CharacterTypes::RedGhost };
	std::vector<std::weak_ptr<dae::GameObject>> m_ObjectsToCheck;
	std::weak_ptr<dae::GameObject> m_LiveObj;
};

