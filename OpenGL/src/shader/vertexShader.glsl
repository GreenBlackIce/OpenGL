#version 330 core

layout(location = 0) in vec3 vertexPositionModelspace;

void main()
{
	gl_Position.xyz = vertexPositionModelspace;
	gl_Position.w = 1.0;
}