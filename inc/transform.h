#pragma once
#include <glm\glm.hpp>
using namespace glm;

class GameObject;
class Transform
{
public:
	Transform();
	~Transform();

	vec3 pos;
	vec3 rot;
	vec3 scale;
	GameObject* gameObject;
};