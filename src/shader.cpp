#include <iostream>
#include <fstream>
#include <string>
#include "shader.h"

using namespace std;

Shader::Shader(string file)
{
	load(file);
}

string Shader::getText()
{
	return text;
}

void Shader::load(string filename)
{
	ifstream file("shaders\\" + filename);
	string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			text += line + "\n";
		}

		file.close();
	}

	cout << "Loaded shader: " << filename << endl;
}