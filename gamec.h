#pragma once
#include "igamec.h"

class GameComponent : public IGameComponent
{
public:
	GameComponent();
	~GameComponent();
	virtual void init();
	virtual void update();
	virtual void render();
};

