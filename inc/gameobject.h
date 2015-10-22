#pragma once
#include <vector>
#include "igamec.h"
using namespace std;

#include "transform.h"
class GameObject
{
public:
	GameObject();
	~GameObject();

	void addComponent(IGameComponent*);

	//gets the first component from the list of type T
	template <typename T>
	T getComponent(T);

	void init();
	void update();
	void render();

	void setParent(Transform);
	int getNumChildren();
	void addChild(GameObject);
	GameObject getChild(int);

	Transform parent;
	Transform transform;
private:
	vector<IGameComponent*> components;
	vector<GameObject> children;
};