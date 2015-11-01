#include "material.h"
#include "shadermanager.h"

Material::Material(EMaterialType tp, string name)
{
	type = tp;
	shader = ShaderManager::getShader(name);
}

Material::Material(EMaterialType tp, Shader* shade)
{
	type = tp;
	shader = shade;
}

Shader* Material::getShader()
{
	return shader;
}

EMaterialType Material::getType()
{
	return type;
}

int Material::getDataSize()
{
	switch (type)
	{
	case EMaterialType::DEFAULT:
		return 32;
	case EMaterialType::COLOR:
		return 28;
	default:
		return 0;
	}
}