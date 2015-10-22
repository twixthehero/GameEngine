#include <GL\glew.h>
#include "meshrenderer.h"

#include <iostream>
using namespace std;

MeshRenderer::MeshRenderer(Model model)
{
	mesh = model.getMesh();
}

MeshRenderer::MeshRenderer(Mesh m)
{
	mesh = m;
}

MeshRenderer::~MeshRenderer() {}

void MeshRenderer::init()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, mesh.getDataCount() * sizeof(float), &mesh.data[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 32, (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 32, (void*)12);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 32, (void*)20);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.getNumIndices() * sizeof(int), &mesh.indices[0], GL_STATIC_DRAW);
}

void MeshRenderer::render()
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, mesh.getNumIndices() * sizeof(int), GL_UNSIGNED_INT, NULL);
}