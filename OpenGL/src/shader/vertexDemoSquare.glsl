#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 colorBuffer;

out vec3 vertexColor;

void main()
{
	vertexColor = colorBuffer;
	gl_Position = position;
}