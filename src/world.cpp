#include "camera.h"
#include "flymove.h"
#include "world.h"
#include "mattype.h"
#include "model.h"
#include "meshrenderer.h"
#include "texture.h"
#include "shadermanager.h""

World::World() {}
World::~World() {}

void World::addObject(GameObject* o)
{
	objects.push_back(o);
}

void World::init()
{
	GameObject* tri = new GameObject();
	tri->transform->pos.z = 5;
	Model* triModel = new Model("triangle");
	Material* mat = new Material(EMaterialType::COLOR, ShaderManager::getDefaultShader());
	MeshRenderer* triRenderer = new MeshRenderer(triModel, mat);
	tri->addComponent(triRenderer);
	addObject(tri);

	GameObject* cam = new GameObject();
	Camera* camera = new Camera();
	FlyMove* flymove = new FlyMove();
	cam->addComponent(camera);
	cam->addComponent(flymove);
	addObject(cam);

	Camera::setMain(camera);

	//Texture t("herp.png");

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
