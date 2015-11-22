#version 400
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 norm;

uniform mat4 worldMatrix;

out vec2 uvCoord;

void main()
{
    gl_Position = worldMatrix * vec4(pos, 1.0);
    uvCoord = uv;
}