#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"


int main()
{
	glewExperimental = true;
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	GLFWwindow* window; 
	window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true; 
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glfwSwapInterval(1);

	float vertexBufferData[] =
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	unsigned int indexBuffer[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	VertexArray va;
	VertexBuffer vb(vertexBufferData, 4 * 3 * sizeof(unsigned int));
	VertexBufferLayout layout;
	IndexBuffer ib(indexBuffer, 6);
	
	layout.push<float>(3);
	va.addBuffer(vb, layout);

	Shader shader("..\\OpenGL\\src\\shader\\vertexShader.glsl", "..\\OpenGL\\src\\shader\\fragmentShader.glsl");
	shader.bind();
	shader.setUniform4f("u_Color", 0.8f, 0.3f, 0.2f, 1.0f);
	
	va.unbind();
	vb.unbind();
	ib.unbind();
	shader.unbind();


	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	float increment = 0.01f;
	float r = 0.0f;

	do {
		glClear(GL_COLOR_BUFFER_BIT);
		
		va.bind();
		ib.bind();
		shader.bind();
		shader.setUniform4f("u_Color", r, 0.3f, 0.2f, 1.0f);

		glDrawElements(GL_TRIANGLES, 6 , GL_UNSIGNED_INT, nullptr);
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

		r += increment;

		if (r > 1.0f)
			increment = -0.01f;
		else if (r < 0.0f)
			increment = 0.01f;

	}
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
	
	shader.unbind();
	glfwTerminate();

	std::cin.get();
	return 0;
}