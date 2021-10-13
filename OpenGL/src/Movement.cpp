#include "Movement.h"
#include "Mvp.h"

Movement::Movement(GLFWwindow* window)
	:window(window), position(glm::vec3(0, 1, 4))
{
	glfwGetWindowSize(window, &windowWidth, &windowHeight);
	lastTime = glfwGetTime();
}

glm::mat4 Movement::getMvp()
{
	float deltaTime = float(glfwGetTime() - lastTime);
	double xpos, ypos;

	glfwGetCursorPos(window, &xpos, &ypos);
	glfwSetCursorPos(window, windowWidth / 2, windowHeight / 2);

	horizontalAngle += mouseSpeed * deltaTime * float(windowWidth / 2 - xpos);
	verticalAngle += mouseSpeed * deltaTime * float(windowHeight / 2 - ypos);

	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));

	glm::vec3 right(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f));

	glm::vec3 up = glm::cross(right, direction);
	

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		position -= right * deltaTime * speed;
	}

	glm::mat4 mvp = mvp::getMvp(initialFoV, 4, 3, 1.0f, position, position + direction, up);
	lastTime = glfwGetTime();
	return mvp;
}
