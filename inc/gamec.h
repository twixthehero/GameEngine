#pragma once
#include "igamec.h"
#include "gamectype.h"

class GameComponent : public IGameComponent
{
public:
	GameComponent();
	~GameComponent();

	EGameComponentType type;
};