#pragma once
namespace dae
{
	class GameObject;
}
enum class Types
{
	INPUT,
	RENDER,
	TEXTURE,
	TEXT,
	PICKUP,
	SCORE,
	RAIL
};
class BaseComponent
{
public:
	BaseComponent(Types type);
	virtual ~BaseComponent();
	virtual void Update(const float deltaTime) = 0;
	virtual void Render() = 0;
	void SetGO(const std::weak_ptr<dae::GameObject>& go) { m_GO = go; }

	Types GetType() { return m_type; };
protected:
	Types m_type;
	std::weak_ptr<dae::GameObject> m_GO;
};

