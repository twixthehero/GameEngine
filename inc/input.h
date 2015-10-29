#pragma once
#include <GLFW\glfw3.h>

class Input
{
public:
	Input();
	void setWindow(GLFWwindow*);
	static bool getKey(int);
private:
	static GLFWwindow* window;
};