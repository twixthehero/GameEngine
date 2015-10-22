#pragma once
#include <GLFW\glfw3.h>

class GameTime
{
public:
	static void init();
	static void update();
	static double dt;
	static double elapsed;
private:
	static double lastTime;
};

double GameTime::dt = 0;
double GameTime::elapsed = 0;
double GameTime::lastTime = 0;

void GameTime::init()
{
	elapsed = 0;
	lastTime = 0;
}

void GameTime::update()
{
	dt = glfwGetTime() - lastTime;
	lastTime = glfwGetTime();
	elapsed += dt;
}