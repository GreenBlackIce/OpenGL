#version 330 core

in vec3 fragmentColor;
out vec3 color;

//uniform vec4 u_Color;

void main()
{
	color = fragmentColor;
	//color = u_Color;
}