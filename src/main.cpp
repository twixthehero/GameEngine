#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "camera.h"
#include "gametime.h"
#include "input.h"
#include "shadermanager.h"
#include "world.h"
using namespace std;

GLFWwindow* window;
Input input;
ShaderManager shaderManager;
GLuint defShader;
GLuint uniWorld;
World world;

void init()
{
	glClearColor(101 / 255.0f, 156 / 255.0f, 239 / 255.0f, 1.0f);

	GameTime::init();
	input.setWindow(window);
	shaderManager.init();
	world.init();

	defShader = shaderManager.getDefaultShader();
	uniWorld = glGetUniformLocation(defShader, "worldMatrix");
}

void update()
{
	GameTime::update();
	world.update();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(defShader);

	glProgramUniformMatrix4fv(defShader, uniWorld, 1, GL_FALSE,
		&(Camera::getMain()->getWorldMatrix())[0][0]);

	world.render();

	glFlush();
}

int main()
{
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(1280, 720, "GameEngine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return -1;
	}

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	cout << "Renderer: " << renderer << endl;
	cout << "Open GL Version: " << version << endl;

	init();
	while (!glfwWindowShouldClose(window))
	{
		update();
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}