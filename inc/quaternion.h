#pragma once
#include <glm\glm.hpp>
using namespace glm;

class Quaternion
{
public:
    Quaternion();
    Quaternion(float, float, float);
    Quaternion(float, float, float, float);
    Quaternion(vec3, float);
    ~Quaternion();

    float x;
    float y;
    float z;
    float w;
private:
};