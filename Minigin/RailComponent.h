#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "InputComponent.h"
#include "Structs.h"
class RailComponent : public InputComponent
{
public:
	RailComponent();
	virtual ~RailComponent();

	//overrides
	void Update(const float deltaTime) override;
	void LateUpdate(const float deltaTime) override;
	void Render() override;
	void HandleInput();

	//setter functions
	void SetAllowedDirections(const std::vector<MoveDirection>& dirs) { m_AllowedDirection = dirs; }
	void AddCornerPoint(Pos point, const std::vector<MoveDirection>& moveDirs);
	void AddCornerPoint(CornerPoint cp);
	void SetRadius(float r) { m_Radius = r; }
private:
	std::vector<CornerPoint> m_CornerPoints;
	std::vector<MoveDirection> m_AllowedDirection;
	float m_Radius{ 0.f }; //size of the detection radius for the cornerpoints
	bool m_InRangeOfCP{ false };
	CornerPoint m_LastCP;

	bool CanMoveInDir(MoveDirection dir);

	//DEBUG VAR PLEASE DONT GRADE THIS
	//std::shared_ptr<dae::Texture2D> mTexture;
};

