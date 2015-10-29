#include "input.h"

Input::Input() {}

void Input::setWindow(GLFWwindow* win)
{
	window = win;
}

bool Input::getKey(int keycode)
{
	return glfwGetKey(window, keycode) == GLFW_PRESS;
}