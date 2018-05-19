#pragma once
enum class Types
{
	INPUT,
	RENDER,
	TEXTURE,
	TEXT,
	PICKUP,
	SCORE,
	MOVE
};
enum class MoveDirection
{
	UP, DOWN, LEFT, RIGHT, NONE
};
struct Pos
{
	float x, y;
};
struct CornerPoint
{
	Pos pos;
	std::vector<MoveDirection> m_AllowedDirections;
};