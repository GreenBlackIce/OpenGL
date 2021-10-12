#include "Movement.h"

glm::vec3 Movement::getDirection()
{
	double xpos, ypos;
	int width, height;
	glfwGetCursorPos(window, &xpos, &ypos);
	glfwSetCursorPos(window, windowWidth / 2, windowHeight / 2);

	horizontalAngle += mouseSpeed * deltatime * float(windowWidth / 2);
	verticalAngle += mouseSpeed * deltatime * float(windowHeight / 2);

	//Weiter
	return glm::vec3();
}

glm::vec3 Movement::getPosition()
{
	return glm::vec3();
}

float Movement::getTime()
{
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);
	return 0.0f;
}

Movement::Movement(GLFWwindow* window)
	:window(window)
{
	glfwGetWindowSize(window, &windowWidth, &windowHeight);
}

glm::mat4 Movement::getMvp()
{
	return glm::mat4();
}
