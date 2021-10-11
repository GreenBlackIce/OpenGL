#pragma once
#include "GL/glew.h"
#include <string>

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_VertexShaderPath;
	std::string m_FragmentShaderPath;

public:

	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	~Shader();

	void bind() const;
	void unbind() const;

	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
	bool compileShader();
	unsigned int getUniformLocation(const std::string& name);
};