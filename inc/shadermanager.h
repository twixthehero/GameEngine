#pragma once
#include <GL\glew.h>
#include <string>
#include <unordered_map>
using namespace std;

class ShaderManager
{
public:
	static void init();
	static GLuint getDefaultShader();
	static GLuint getShader(string);
	static void load(string);

	static ShaderManager* instance;
private:
	ShaderManager();
	~ShaderManager();

	unordered_map<string, GLuint> loadedShaders;
};