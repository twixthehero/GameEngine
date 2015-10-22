#pragma once
#include <GL\glew.h>
#include <string>
#include "color.h"
using namespace std;

class Texture
{
public:
	Texture(string);
	Texture(Color);

	GLuint getId();
private:
	void loadImage(string);
	void genImage(Color);

	const string TEX_DIR = "textures\\";
	const string MISSING = "missing.png";
	GLuint id;
};