#pragma once
#include <vector>
#include "gamec.h"
#include "transform.h"
using namespace std;

class GameObject
{
public:
	GameObject();
	~GameObject();

	void addComponent(GameComponent*);

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
	vector<GameComponent*> components;
	vector<GameObject> children;
};