#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"


class Movement
{
private:
	GLFWwindow* window;
	glm::vec3 position;

	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
	float initialFoV = 45.0f;
	float speed = 2.0f;
	float mouseSpeed = 0.05f;
	int windowWidth, windowHeight;
	double lastTime;

public:
	Movement(GLFWwindow* window);
	glm::mat4 getMvp();
};