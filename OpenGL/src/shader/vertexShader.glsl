#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec3 vertexNormals;

uniform mat4 MVP;
uniform mat4 M;
uniform float lightStrength;
uniform vec3 lightPosition;
uniform vec3 lightColor;

out vec3 fragmentNormals;
out vec3 fragmentColor;
out vec3 fragmentLightColor;
out vec3 fragmentLightPosition;
out vec3 fragmentPosition;
out float fragmentLightStrength;

void main()
{
	gl_Position = MVP * vec4(vertexPosition, 1.0);

	fragmentPosition = vec3(M * vec4(vertexPosition, 1.0));

	fragmentLightPosition = lightPosition;
	fragmentNormals = vertexNormals;
	fragmentLightColor = lightColor;
	fragmentLightStrength = lightStrength;
	fragmentColor = vertexColor;
}