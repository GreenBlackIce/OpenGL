#version 330 core

uniform vec4 u_Color;

in vec3 vertexColor;

out vec4 color;

void main()
{
	color = u_Color * vec4(vertexColor, 1.0f);
}