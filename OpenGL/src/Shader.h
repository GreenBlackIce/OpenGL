#pragma once
#include "GL/glew.h"

class Shader
{
public:
	Shader();
	~Shader();

	GLuint loadShader(const char* vertexShaderPath, const char* fragmentShaderPath);
};