#pragma once
#include "GL/glew.h"
#include "glm/gtc/matrix_transform.hpp"
#include <string>
#include <unordered_map>

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_VertexShaderPath;
	std::string m_FragmentShaderPath;
	mutable std::unordered_map<std::string, GLuint> m_UniformLocationCache;
public:
	
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	~Shader();
	
	void bind() const;
	void unbind() const;

	void setUniform1f(const std::string& name, float v0);
	void setUniform3f(const std::string& name, float v0, float v1, float v2);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformMatrix4fv(const std::string& name, unsigned int count, bool transpose, glm::mat4& data);

private:
	bool compileShader();
	GLuint getUniformLocation(const std::string& name) const;
};