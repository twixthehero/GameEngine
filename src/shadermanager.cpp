#include <GL\glew.h>
#include <iostream>
#include "shader.h"
#include "shadermanager.h"
using namespace std;

ShaderManager* ShaderManager::instance = new ShaderManager();

ShaderManager::ShaderManager() {}
ShaderManager::~ShaderManager() {}

void ShaderManager::init()
{
	load("default");
	load("color");
}

GLuint ShaderManager::getDefaultShader() { return instance->loadedShaders["default"]; }

GLuint ShaderManager::getShader(string name)
{
	if (instance->loadedShaders[name] == NULL)
		load(name);

	return instance->loadedShaders[name];
}

void ShaderManager::load(string name)
{
	cout << "Loading shader: " << name << endl;
	Shader dv(name + ".vs");
	Shader df(name + ".fs");

	string v = dv.getText();
	string f = df.getText();
	const char* vert = v.c_str();
	const char* frag = f.c_str();

	cout << "Compiling vertex shader" << endl;
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vert, NULL);
	glCompileShader(vs);

	int success = -1;
	glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
	if (GL_TRUE != success)
	{
		cout << "ERROR: GL vertex shader index " << vs << " did not compile" << endl;
		exit(-1);
	}

	cout << "Compiling fragment shader" << endl;
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &frag, NULL);
	glCompileShader(fs);

	success = -1;
	glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
	if (GL_TRUE != success)
	{
		cout << "ERROR: GL fragment shader index " << fs << " did not compile" << endl;
		exit(-1);
	}

	cout << "Reserving pointer for shader" << endl;
	instance->loadedShaders[name] = 0;

	cout << "Linking vertex and fragment" << endl;
	instance->loadedShaders[name] = glCreateProgram();
	glAttachShader(instance->loadedShaders[name], vs);
	glAttachShader(instance->loadedShaders[name], fs);
	glLinkProgram(instance->loadedShaders[name]);

	glGetShaderiv(instance->loadedShaders[name], GL_LINK_STATUS, &success);
	if (GL_TRUE != success)
	{
		cout << "ERROR: shader '" << name << "' did not link properly" << endl;
		exit(-1);
	}

	cout << "Loaded!" << endl;
}