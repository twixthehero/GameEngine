#pragma once
#include <GL\glew.h>
#include <string>
#include <unordered_map>
using namespace std;

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	void init();
	GLuint getDefaultShader();
	GLuint getShader(string);
private:
	void load(string);

	unordered_map<string, GLuint> loadedShaders;
};