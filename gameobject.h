#pragma once
#include <vector>
#include "igamec.h"
#include "transform.h"
using namespace std;

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

	Transform transform;
private:
	vector<IGameComponent*> components;
};