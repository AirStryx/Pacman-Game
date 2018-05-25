#pragma once
#include "Structs.h"
namespace dae
{
	class GameObject;
}

class BaseComponent
{
public:
	BaseComponent(Types type, std::shared_ptr<dae::GameObject> go);
	virtual ~BaseComponent();
	virtual void Update(const float deltaTime) = 0;
	virtual void LateUpdate(const float deltaTime) = 0;
	virtual void Render() = 0;
	void SetGO(const std::weak_ptr<dae::GameObject>& go) { m_GO = go; }
	

	Types GetType() { return m_type; };
protected:
	Types m_type;
	std::weak_ptr<dae::GameObject> m_GO;
	
};

