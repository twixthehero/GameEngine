#include <GL\glew.h>
#include "meshrenderer.h"

#include <iostream>
using namespace std;

MeshRenderer::MeshRenderer(Model* model, Material* mat)
{
	type = MESH_RENDERER;
	mesh = model->getMesh();
	material = mat;
}

MeshRenderer::~MeshRenderer() {}

void MeshRenderer::init()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, mesh->getDataCount() * sizeof(float), &mesh->data[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 32, (void*)0);

	switch (material->getType())
	{
	case EMaterialType::DEFAULT:
		if (mesh->hasUVs)
		{
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 32, (void*)12);
		}

		if (mesh->hasNormals)
		{
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 32, (void*)20);
		}
		break;
	case EMaterialType::COLOR:
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 32, (void*)12);
		break;
	}

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->getNumIndices() * sizeof(int), &mesh->indices[0], GL_STATIC_DRAW);
}

void MeshRenderer::render()
{
	glUseProgram(material->getShader());
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, mesh->getNumIndices() * sizeof(int), GL_UNSIGNED_INT, NULL);
}