#include <typeinfo>
#include "gameobject.h"
#include "meshrenderer.h"

GameObject::GameObject()
{
	transform.gameObject = this;
}
GameObject::~GameObject() {}

void GameObject::addComponent(GameComponent* igc)
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
		if (components[i]->type == MESH_RENDERER)
		{
			dynamic_cast<MeshRenderer*>(components[i])->init();
			continue;
		}
	}

	for (int i = 0; i < children.size(); i++)
		children[i].init();
}

void GameObject::update()
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->type == MESH_RENDERER)
		{
			dynamic_cast<MeshRenderer*>(components[i])->update();
			continue;
		}
	}

	for (int i = 0; i < children.size(); i++)
		children[i].update();
}

void GameObject::render()
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->type == MESH_RENDERER)
		{
			dynamic_cast<MeshRenderer*>(components[i])->render();
			continue;
		}
	}

	for (int i = 0; i < children.size(); i++)
		children[i].render();
}

int GameObject::getNumChildren() { return children.size(); }

void GameObject::setParent(Transform parent)
{
	this->parent = parent;
}

void GameObject::addChild(GameObject child)
{
	child.setParent(transform);
	children.push_back(child);
}

GameObject GameObject::getChild(int index)
{
	if (index < getNumChildren())
		return children[index];
	
	throw new exception("Index out of bounds");
}