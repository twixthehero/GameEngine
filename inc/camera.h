#pragma once
#include "gamec.h"

class Camera : public GameComponent
{
public:
	Camera();
	void setupView();
private:
	bool hasMoved;
};