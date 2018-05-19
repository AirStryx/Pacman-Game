#pragma once
#include "MoveComponent.h"
class MoveRailComponent : public MoveComponent
{
public:
	MoveRailComponent();
	virtual ~MoveRailComponent();

	//overrides
	void Update(const float deltaTime) override;
	void Render() override;

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
};

