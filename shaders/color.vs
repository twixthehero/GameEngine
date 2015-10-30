#version 400
layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 col;

uniform mat4 worldMatrix;

out vec4 color;

void main()
{
    gl_Position = worldMatrix * vec4(pos, 1.0);
	color = col;
}