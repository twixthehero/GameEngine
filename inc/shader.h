#pragma once
#include <string>
using namespace std;

class Shader
{
public:
	Shader(string);
	string getText();
private:
	void load(string);

	string text;
};

static inline string& ltrim(string&);
static inline string& rtrim(string&);
static inline string& trim(string&);