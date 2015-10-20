#include <typeinfo>
#include "gameobject.h"
#include "meshrenderer.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::addComponent(IGameComponent* igc)
{
	components.push_back(igc);
}

template<typename T>
inline T GameObject::getComponent(T comp)
{
	for (int i = 0; i < components.size(); i++)
		if (typeid(comp).name() == typeid(components[i]).name())
			return components[i];

	return NULL;
}

void GameObject::init()
{
	for (int i = 0; i < components.size(); i++)
	{
		MeshRenderer* mr = dynamic_cast<MeshRenderer*>(components[i]);

		if (mr)
		{
			mr->init();
			continue;
		}
	}
}

void GameObject::update()
{
	for (int i = 0; i < components.size(); i++)
	{
		MeshRenderer* mr = dynamic_cast<MeshRenderer*>(components[i]);

		if (mr)
		{
			mr->update();
			continue;
		}
	}
}

void GameObject::render()
{
	for (int i = 0; i < components.size(); i++)
	{
		MeshRenderer* mr = dynamic_cast<MeshRenderer*>(components[i]);

		if (mr)
		{
			mr->render();
			continue;
		}
	}
}
