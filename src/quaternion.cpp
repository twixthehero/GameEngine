#include "quaternion.h"
#include <cmath>

Quaternion::Quaternion()
{
    x = 0;
    y = 0;
    z = 0;
    w = 1;
}

Quaternion::Quaternion(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
    w = 1;
}

Quaternion::Quaternion(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

Quaternion::Quaternion(vec3 axis, float angle)
{
    float sinHalfAngle = sin(angle / 2);
    float cosHalfAngle = cos(angle / 2);

    x = axis.x * sinHalfAngle;
    y = axis.y * sinHalfAngle;
    z = axis.z * sinHalfAngle;
    w = cosHalfAngle;
}

Quaternion::~Quaternion() {}