#pragma once
#include <GL\glew.h>

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	void init();
	GLuint getDefaultShader();
private:
	GLuint defaultShader;
};