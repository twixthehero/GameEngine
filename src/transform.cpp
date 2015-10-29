#include "transform.h"

Transform::Transform()
{
	pos = vec3(0.0, 0.0, 0.0);
	rot = vec3(0.0, 0.0, 0.0);
	scale = vec3(1.0, 1.0, 1.0);
}

Transform::~Transform() {}