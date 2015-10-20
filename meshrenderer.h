#pragma once
#include <GLFW\glfw3.h>
#include "igamec.h"
#include "mesh.h"
#include "model.h"

class MeshRenderer : public IGameComponent
{
public:
	MeshRenderer(Model);
	MeshRenderer(Mesh);
	~MeshRenderer();
	virtual void init();
	virtual void render();
private:
	Mesh mesh;

	GLuint vbo;
	GLuint ibo;
};