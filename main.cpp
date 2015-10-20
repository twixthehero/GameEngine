#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "shadermanager.h"
#include "world.h"
using namespace std;

float points[] =
{
	0, 0, 0,
	1, 0, 0,
	0, 1, 0
};

GLuint vbo = 0;
GLuint vao = 0;

ShaderManager shaderManager;
World world;

void init()
{
	glClearColor(101 / 255.0f, 156 / 255.0f, 239 / 255.0f, 1.0f);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	shaderManager.init();
	world.init();
}

void update()
{
	world.update();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shaderManager.getDefaultShader());

	world.render();

	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 3);

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

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Blockus", NULL, NULL);
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