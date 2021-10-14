#include "Movement.h"
#include "Mvp.h"

void Movement::moveAlone()
{
	m_Position = glm::vec3(0, 1, 0) + glm::vec3(4 * cos(m_LastTime), 0, 4 * sin(m_LastTime));

	m_MovementData.model = mvp::getModel(1.0f);
	m_MovementData.view = mvp::getView(m_Position, glm::vec3(0,0,0), glm::vec3(0,1,0));
	m_MovementData.projection = mvp::getPojection(m_InitialFoV, m_WindowWidth, m_WindowHeight);
}

void Movement::moveAloneParty()
{
	m_Position = glm::vec3(0, 1, 3) + glm::vec3(4 * cos(m_LastTime) * 2, 1, 4 * sin(m_LastTime) * 2);

	m_MovementData.model = mvp::getModel(1.0f);
	m_MovementData.view = mvp::getView(m_Position, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	m_MovementData.projection = mvp::getPojection(m_InitialFoV, m_WindowWidth, m_WindowHeight);
}

void Movement::moveMouseAndKey()
{
	float deltaTime = float(glfwGetTime() - m_LastTime);
	double xpos, ypos;

	glfwGetCursorPos(window, &xpos, &ypos);
	glfwSetCursorPos(window, m_WindowWidth / 2, m_WindowHeight / 2);

	m_HorizontalAngle += m_MouseSpeed * deltaTime * float(m_WindowWidth / 2 - xpos);
	m_VerticalAngle += m_MouseSpeed * deltaTime * float(m_WindowHeight / 2 - ypos);

	glm::vec3 m_Direction(
		cos(m_VerticalAngle) * sin(m_HorizontalAngle),
		sin(m_VerticalAngle),
		cos(m_VerticalAngle) * cos(m_HorizontalAngle));

	glm::vec3 right(
		sin(m_HorizontalAngle - 3.14f / 2.0f),
		0,
		cos(m_HorizontalAngle - 3.14f / 2.0f));

	glm::vec3 m_Up = glm::cross(right, m_Direction);

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		m_Position += m_Direction * deltaTime * m_Speed;
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		m_Position -= m_Direction * deltaTime * m_Speed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		m_Position += right * deltaTime * m_Speed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		m_Position -= right * deltaTime * m_Speed;
	}

	//glm::mat4 mvp = mvp::getMvp(m_InitialFoV, 4, 3, 1.0f, m_Position, m_Position + m_Direction, m_Up);
	m_MovementData.model = mvp::getModel(1.0f);
	m_MovementData.view = mvp::getView(m_Position, m_Position + m_Direction, m_Up);
	m_MovementData.projection = mvp::getPojection(m_InitialFoV, m_WindowWidth, m_WindowHeight);
}

Movement::Movement(GLFWwindow* window)
	:window(window), m_Position(glm::vec3(0, 1, 4))
{
	glfwGetWindowSize(window, &m_WindowWidth, &m_WindowHeight);
	m_LastTime = glfwGetTime();
}

void Movement::movementStart()
{
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		m_Mode = m_ModeMenu[0];
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		m_Mode = m_ModeMenu[1];
	}
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		m_Position = glm::vec3(0, -1, 2);
		m_Direction = glm::vec3(0, 0, -2);
		m_Mode = m_ModeMenu[2];
	}

	switch (m_Mode)
	{
	case 'A':
		moveAlone();
		break;
	case 'B':
		moveAloneParty();
		break;
	case 'C':
		moveMouseAndKey();
		break;
	default:
		moveAlone();
		break;
	}

	m_LastTime = glfwGetTime();
}
