#include "Shader.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Renderer.h"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
	:m_VertexShaderPath(vertexShaderPath), m_FragmentShaderPath(fragmentShaderPath), m_RendererID(0)
{
	ASSERT(compileShader());
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendererID));
}

void Shader::bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void Shader::unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::setUniform1f(const std::string & name, float v0)
{
	GLCall(glUniform1f(getUniformLocation(name), v0));
}

void Shader::setUniform3f(const std::string & name, float v0, float v1, float v2)
{
	GLCall(glUniform3f(getUniformLocation(name), v0, v1, v2));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

void Shader::setUniformMatrix4fv(const std::string& name, unsigned int count, bool transpose, glm::mat4& data)
{
	if (transpose)
	{
		GLCall(glUniformMatrix4fv(getUniformLocation(name), count, GL_TRUE, &data[0][0]));
	}
	else
	{
		GLCall(glUniformMatrix4fv(getUniformLocation(name), count, GL_FALSE, &data[0][0]));
	}
}

GLuint Shader::getUniformLocation(const std::string& name) const
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	int location = glGetUniformLocation(m_RendererID, name.c_str());
	if (location == -1)
	{
		std::cout << "Warning Uniform " << name << " does not exist!" << std::endl;
	}
	m_UniformLocationCache[name] = location;
	return location;
}

bool Shader::compileShader() {

	const char* vertex_file_path = m_VertexShaderPath.c_str();
	const char* fragment_file_path = m_FragmentShaderPath.c_str();

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return false;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	GLCall(glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL));
	GLCall(glCompileShader(VertexShaderID));

	// Check Vertex Shader
	GLCall(glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result));
	GLCall(glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength));
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		GLCall(glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]));
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	GLCall(glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL));
	GLCall(glCompileShader(FragmentShaderID));

	// Check Fragment Shader
	GLCall(glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result));
	GLCall(glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength));
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		GLCall(glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]));
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	m_RendererID = glCreateProgram();
	GLCall(glAttachShader(m_RendererID, VertexShaderID));
	GLCall(glAttachShader(m_RendererID, FragmentShaderID));
	GLCall(glLinkProgram(m_RendererID));

	// Check the program
	GLCall(glGetProgramiv(m_RendererID, GL_LINK_STATUS, &Result));
	GLCall(glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &InfoLogLength));
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		GLCall(glGetProgramInfoLog(m_RendererID, InfoLogLength, NULL, &ProgramErrorMessage[0]));
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	GLCall(glDetachShader(m_RendererID, VertexShaderID));
	GLCall(glDetachShader(m_RendererID, FragmentShaderID));

	GLCall(glDeleteShader(VertexShaderID));
	GLCall(glDeleteShader(FragmentShaderID));

	return true;
}

