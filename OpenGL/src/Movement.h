#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"


class Movement
{
private:
	GLFWwindow* window;
	glm::vec3 m_Position;
	glm::vec3 m_Direction;

	float m_HorizontalAngle = 3.14f;
	float m_VerticalAngle = 0.0f;
	float m_InitialFoV = 45.0f;
	float m_Speed = 2.0f;
	float m_MouseSpeed = 0.05f;
	int m_WindowWidth, m_WindowHeight;
	double m_LastTime;
	char m_ModeMenu[3] = {'A', 'B', 'C'};
	char m_Mode;

	glm::mat4 moveAlone();
	glm::mat4 moveAloneParty();
	glm::mat4 moveMouseAndKey();

public:
	Movement(GLFWwindow* window);
	glm::mat4 getMvp();
};