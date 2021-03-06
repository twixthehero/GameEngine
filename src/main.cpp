#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <sstream>
#include "camera.h"
#include "gametime.h"
#include "input.h"
#include "font.h"
#include "fontmanager.h"
#include "shadermanager.h"
#include "world.h"
using namespace std;

#include <glm\gtx\transform.hpp>
using namespace glm;

//Engine vars
GLFWwindow* window;
GLuint defShader;
GLuint uniWorld;
World world;
Font* font;

//option vars
bool debug = false;

//info vars
double lastFrames = 0;
double lastTime;
int numFrames = 0;
double frameTime;

void init()
{
	glClearColor(101 / 255.0f, 156 / 255.0f, 239 / 255.0f, 1.0f);

    int* w = new int;
    int* h = new int;
    glfwGetWindowSize(window, w, h);
    Font::SX = 2.0 / *w;
    Font::SY = 2.0 / *h;

	Input::init(window);
    FontManager::init();
	GameTime::init();
	ShaderManager::init();
	world.init();

    font = FontManager::getDefaultFont();

	defShader = ShaderManager::getDefaultShader()->getProgram();
	uniWorld = glGetUniformLocation(defShader, "worldMatrix");
}

void update()
{
	GameTime::update();
    Input::update();
	world.update();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glProgramUniformMatrix4fv(defShader, uniWorld, 1, GL_FALSE,
		&(Camera::getMain()->getWorldMatrix())[0][0]);

	world.render();

    Shader* s = ShaderManager::getShader("font");
    font->setSize(18);

    ostringstream stream;
    stream << lastFrames;
    font->renderText("FPS: " + stream.str(), -1 + 4 * Font::SX, 1 - 18 * Font::SY, Color(0.0f, 1.0f, 0.0f));
    stream.str(""); stream.clear();
    stream << frameTime;
    font->renderText("Frame Time: " + stream.str(), -1 + 4 * Font::SX, 1 - 36 * Font::SY, Color(0.0f, 1.0f, 0.0f));

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
        if (glfwGetTime() - lastTime >= 1.0)
        {
            frameTime = 1000.0 / numFrames;
            lastFrames = numFrames;
            numFrames = 0;
            lastTime += 1.0;
        }

		update();
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();

        numFrames++;
	}

	glfwTerminate();

	return 0;
}