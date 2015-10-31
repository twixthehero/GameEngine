#pragma once
#include <GL\glew.h>
#include <string>
#include <unordered_map>
#include "shader.h"
using namespace std;

class ShaderManager
{
public:
	static void init();
	static GLuint getDefaultShader();
	static GLuint getShader(string);
	static string readText(string);
	static void load(string);

	static ShaderManager* instance;
private:
	ShaderManager();
	~ShaderManager();

	unordered_map<string, Shader*> loadedShaders;
};