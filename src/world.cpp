#include "texture.h"
#include "meshrenderer.h"
#include "model.h"
#include "world.h"
#include "camera.h"
#include "flymove.h"

World::World()
{
	GameObject tri;
	Model triModel("triangle");
	MeshRenderer* triRenderer = new MeshRenderer(triModel);
	tri.addComponent(triRenderer);
	addObject(tri);

	GameObject cam;
	cam.transform.pos = vec3(0, 0, -2);
	Camera* camera = new Camera();
	FlyMove* flymove = new FlyMove();
	cam.addComponent(camera);
	cam.addComponent(flymove);
	addObject(cam);

	Camera::setMain(camera);

	//Texture t("herp.png");
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
