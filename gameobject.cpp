#include <typeinfo>
#include "gameobject.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::addComponent(IGameComponent igc)
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
		components[i].init();
}

void GameObject::update()
{
	for (int i = 0; i < components.size(); i++)
		components[i].update();
}

void GameObject::render()
{
	for (int i = 0; i < components.size(); i++)
		components[i].render();
}
