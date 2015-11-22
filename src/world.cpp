#include "camera.h"
#include "flymove.h"
#include "world.h"
#include "mattype.h"
#include "model.h"
#include "meshrenderer.h"
#include "texture.h"
#include "shadermanager.h""
#include <iostream>

World::World() {}
World::~World() {}

void World::addObject(GameObject* o)
{
	objects.push_back(o);
}

void World::init()
{
	GameObject* cam = new GameObject();
    cam->transform->pos.z = -10;
	Camera* camera = new Camera();
	FlyMove* flymove = new FlyMove();
	cam->addComponent(camera);
	cam->addComponent(flymove);
	addObject(cam);

	Camera::setMain(camera);

    GameObject* die = new GameObject();
    die->transform->pos.z = 5;
    Texture* archer = new Texture("archer.jpg");
    Model* squareModel = new Model("square"); Material* mat = new Material(EMaterialType::DEFAULT, ShaderManager::getDefaultShader(), archer);
    MeshRenderer* dieRenderer = new MeshRenderer(squareModel, mat);
    die->addComponent(dieRenderer);
    addObject(die);

	for (int i = 0; i < objects.size(); i++)
		(*objects[i]).init();
}

void World::update()
{
	for (int i = 0; i < objects.size(); i++)
		(*objects[i]).update();
}

void World::render()
{
	for (int i = 0; i < objects.size(); i++)
		(*objects[i]).render();
}
