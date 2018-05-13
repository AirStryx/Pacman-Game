#pragma once
enum class Types
{
	INPUT,
	RENDER,
	TEXTURE,
	TEXT,
	PICKUP,
	SCORE
};
class BaseComponent
{
public:
	BaseComponent(Types type);
	virtual ~BaseComponent();
	virtual void Update(const float deltaTime) = 0;
	virtual void Render() = 0;


	Types GetType() { return m_type; };
protected:
	Types m_type;
};

