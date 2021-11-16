#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colorBuffer;

uniform mat4 MVP;

out vec3 vertexColor;

void main()
{
	vertexColor = colorBuffer;
	gl_Position = MVP * vec4(position, 1);
}