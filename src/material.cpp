#include "material.h"
#include "shadermanager.h"

Material::Material(EMaterialType tp, string name)
{
	type = tp;
	shader = ShaderManager::getShader(name);
}

Material::Material(EMaterialType tp, GLuint shade)
{
	type = tp;
	shader = shade;
}

GLuint Material::getShader()
{
	return shader;
}

EMaterialType Material::getType()
{
	return type;
}
