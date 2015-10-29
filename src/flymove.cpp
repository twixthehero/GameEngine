#include <GLFW\glfw3.h>
#include "flymove.h"
#include "gameobject.h"
#include "gametime.h"
#include "input.h"
#include "transform.h"

FlyMove::FlyMove()
{
	type = EGameComponentType::FLY_MOVE;
	trans = &(gameObject->transform);
}

void FlyMove::update()
{
	if (Input::getKey(GLFW_KEY_S))
	{
		trans->pos.z += moveSpeed * GameTime::dt;
	}
	if (Input::getKey(GLFW_KEY_W))
	{
		trans->pos.z -= moveSpeed * GameTime::dt;
	}
	if (Input::getKey(GLFW_KEY_D))
	{
		trans->pos.x -= moveSpeed * GameTime::dt;
	}
	if (Input::getKey(GLFW_KEY_A))
	{
		trans->pos.x += moveSpeed * GameTime::dt;
	}
	if (Input::getKey(GLFW_KEY_E))
	{
		trans->pos.y += moveSpeed * GameTime::dt;
	}
	if (Input::getKey(GLFW_KEY_Q))
	{
		trans->pos.y -= moveSpeed * GameTime::dt;
	}
}