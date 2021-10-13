#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec3 vertexNormals;

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;
uniform float lightColor;
uniform float lightPower;

out vec3 fragmentColor;
out vec3 normal_cameraspace;
out vec3 lightDirection_cameraspace;
out float fragmentLightColor;
out float fragemntLightPower;

void main()
{
	gl_Position = MVP * vec4(vertexPosition_modelspace, 1);

	vec3 lightPosition_worldspace = (M * vec4(vertexPosition_modelspace, 1)).xyz;

	vec3 vertexPosition_cameraspace = ( V * M * vec4(vertexPosition_modelspace,1)).xyz;
	vec3 EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;
	vec3 lightPosition_cameraspace = ( V * vec4(lightPosition_worldspace,1)).xyz;

	vec3 lightDirection_cameraspace = lightPosition_cameraspace + EyeDirection_cameraspace;
	vec3 normal_cameraspace = ( V * M * vec4(vertexPosition_modelspace,0)).xyz;

	fragemntLightPower = lightPower;
	fragmentLightColor = lightColor;
	fragmentColor = vertexColor;
}