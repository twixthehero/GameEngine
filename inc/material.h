#pragma once
#include <GL\glew.h>
#include <string>
#include "shader.h"
#include "mattype.h"
using namespace std;

class Material
{
public:
	Material(EMaterialType, string);
	Material(EMaterialType, GLuint);

	GLuint getShader();
	EMaterialType getType();
private:
	GLuint shader;
	EMaterialType type;
};