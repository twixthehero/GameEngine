#include <GL\glew.h>
#include <iostream>

#include "shader.h"
#include "shadermanager.h"

using namespace std;

ShaderManager::ShaderManager()
{
	
}

ShaderManager::~ShaderManager()
{

}

void ShaderManager::init()
{
	load("default");
}

GLuint ShaderManager::getDefaultShader() { return loadedShaders["default"]; }

GLuint ShaderManager::getShader(string name)
{
	if (loadedShaders[name] == NULL)
		load(name);

	return loadedShaders[name];
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
	loadedShaders[name] = 0;

	cout << "Linking vertex and fragment" << endl;
	loadedShaders[name] = glCreateProgram();
	glAttachShader(loadedShaders[name], vs);
	glAttachShader(loadedShaders[name], fs);
	glLinkProgram(loadedShaders[name]);

	glGetShaderiv(loadedShaders[name], GL_LINK_STATUS, &success);
	if (GL_TRUE != success)
	{
		cout << "ERROR: shader '" << name << "' did not link properly" << endl;
		exit(-1);
	}

	cout << "Loaded!" << endl;
}