#pragma once
enum class Types
{
	INPUT,
	RENDER,
	TEXTURE,
	TEXT,
	PICKUP,
	SCORE,
	MOVE,
	MENU,
	PLAYERCOL,
	LIFE
};
enum class CharacterTypes
{
	Pacman,
	RedGhost,
	BlueGhost,
	YellowGhost,
	PinkGhost
};
enum class MoveDirection
{
	UP, DOWN, LEFT, RIGHT, NONE
};
enum class ControllerButton
{
	DPADUP,
	DPADDOWN,
	DPADLEFT,
	DPADRIGHT,
	A
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