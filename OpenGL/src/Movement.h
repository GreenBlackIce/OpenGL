#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

struct MovementData
{
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 mvp;

	glm::mat4 getMvp()
	{
		return projection * view * model;
	}
};


class Movement
{
private:
	GLFWwindow* window;
	glm::vec3 m_Direction;
	glm::vec3 m_Up;

	float m_HorizontalAngle = 3.14f;
	float m_VerticalAngle = 0.0f;
	float m_InitialFoV = 45.0f;
	float m_Speed = 2.0f;
	float m_MouseSpeed = 0.05f;
	int m_WindowWidth, m_WindowHeight;
	double m_LastTime;
	char m_ModeMenu[3] = {'A', 'B', 'C'};
	char m_Mode;

	void moveAlone();
	void moveAloneParty();
	void moveMouseAndKey();

public:
	glm::vec3 m_Position;
	MovementData m_MovementData;
	Movement(GLFWwindow* window);

	inline MovementData const getMovementData() const { return m_MovementData; };
	void movementStart();
};