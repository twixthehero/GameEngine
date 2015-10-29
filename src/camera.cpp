#include <glm\gtx\transform.hpp>
#include <GLFW\glfw3.h>
#include "camera.h"
#include "gameobject.h"
using namespace glm;

Camera::Camera()
{
	type = EGameComponentType::CAMERA;
	trans = &(gameObject->transform);
}

Camera* Camera::getMain() { return main; }
void Camera::setMain(Camera* newMain) { main = newMain; }

void Camera::update()
{
	proj = perspective(75.0, 16.0 / 9, 0.01, 500.0);
	viewtrans = translate(mat4(1.0f), trans->pos);
	viewrotx = rotate(viewtrans, trans->rot.x, vec3(0.0f, 1.0f, 0.0f));
	view = rotate(viewrotx, trans->rot.y, vec3(1.0f, 0.0f, 0.0f));
	model = scale(mat4(1.0f), vec3(1.0f));
	worldMatrix = proj * view * model;
}

mat4 Camera::getWorldMatrix() { return worldMatrix; }