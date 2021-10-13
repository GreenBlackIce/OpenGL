#include "Movement.h"
#include "Mvp.h"

Movement::Movement(GLFWwindow* window)
	:window(window)
{
	glfwGetWindowSize(window, &windowWidth, &windowHeight);
	lastTime = glfwGetTime();
}

glm::mat4 Movement::getMvp()
{
	float deltaTime = float(glfwGetTime() - lastTime);
	double xpos, ypos;

	glfwSetCursorPos(window, windowWidth / 2, windowHeight / 2);

	horizontalAngle += mouseSpeed * deltaTime * float(windowWidth / 2);
	verticalAngle += mouseSpeed * deltaTime * float(windowHeight / 2);

	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle));

	glm::vec3 right(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f));

	glm::vec3 up = glm::cross(right, direction);
	glm::vec3 position = glm::vec3(0);

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

	return mvp;
}
