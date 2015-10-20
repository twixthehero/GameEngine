#include "meshrenderer.h"
#include "model.h"
#include "world.h"

World::World()
{
	GameObject tri;
	Model triModel("triangle");
	MeshRenderer* triRenderer = new MeshRenderer(triModel);
	tri.addComponent(triRenderer);
	addObject(tri);
}

World::~World() {}

void World::addObject(GameObject o)
{
	objects.push_back(o);
}

void World::init()
{
	for (int i = 0; i < objects.size(); i++)
		objects[i].init();
}

void World::update()
{
	for (int i = 0; i < objects.size(); i++)
		objects[i].update();
}

void World::render()
{
	for (int i = 0; i < objects.size(); i++)
		objects[i].render();
}
