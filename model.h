#pragma once
#include <string>
#include <vector>
#include "mesh.h"
using namespace std;

class Model
{
public:
	Model(string);
	~Model();

	Mesh getMesh();
private:
	void load();
	void readModelData();
	void genMeshData(vector<string>);

	string name;
	Mesh mesh;
};