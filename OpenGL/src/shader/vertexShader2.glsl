#version 330 core

layout(location = 1) in vec3 vertexColor;
layout(location = 0) in vec3 vertexPosition;
layout(location = 2) in vec3 vertexNormals;

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;
uniform vec3 lightPosition;

out vec3 lightDirection_camera;
out vec3 normal_camera;
out vec3 vertexPosition_camera;
out vec3 lightPosition_camera;
out vec3 fragmentColor;
out vec3 viewDirection_camera;
out vec3 fragmentVertexPosition;
out vec3 fragmentLightPosition;

void main()
{
    fragmentLightPosition = lightPosition;
    fragmentVertexPosition = vertexPosition;

    gl_Position = MVP * vec4(vertexPosition,1);

    vec3 vertexPosition_world = (M * vec4(vertexPosition,1)).xyz;
    
    vertexPosition_camera = (V * M * vec4(vertexPosition,1)).xyz;
    viewDirection_camera = vec3(0,0,0) - vertexPosition_camera;

    lightPosition_camera = (M * V * vec4(lightPosition,1)).xyz;
    lightDirection_camera = lightPosition_camera + viewDirection_camera;

    normal_camera = (V * M * vec4(vertexNormals,0)).xyz;
    fragmentColor = vertexColor;
}