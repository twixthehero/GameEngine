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
	Material(EMaterialType, Shader*);

	Shader* getShader();
	EMaterialType getType();
	int getDataSize();
private:
	Shader* shader;
	EMaterialType type;
};