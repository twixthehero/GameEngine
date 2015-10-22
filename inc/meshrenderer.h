#pragma once
#include <GLFW\glfw3.h>
#include "gamec.h"
#include "mesh.h"
#include "model.h"

class MeshRenderer : public GameComponent
{
public:
	MeshRenderer(Model);
	MeshRenderer(Mesh);
	~MeshRenderer();
	void init() override;
	void render() override;
private:
	Mesh mesh;

	GLuint vao;
	GLuint vbo;
	GLuint ibo;
};