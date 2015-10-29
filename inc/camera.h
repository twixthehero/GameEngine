#pragma once
#include "gamec.h"
#include "transform.h"

class Camera : public GameComponent
{
public:
	Camera();
	virtual void update();
	mat4 getWorldMatrix();
	static Camera* getMain();
	static void setMain(Camera*);
private:
	static Camera* main;

	mat4 proj;
	mat4 viewtrans;
	mat4 viewrotx;
	mat4 view;
	mat4 model;
	mat4 worldMatrix;

	bool hasMoved;
	Transform* trans;
};