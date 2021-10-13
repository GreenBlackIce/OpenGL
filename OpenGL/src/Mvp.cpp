#include "Mvp.h"

glm::mat4 mvp::getMvp(float fov, float width, float height, float modelNum, glm::vec3 camera, glm::vec3 lookat, glm::vec3 vectorUp)
{
	glm::mat4 projection = glm::perspective(glm::radians(fov), width / height, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(camera, lookat, vectorUp);
	glm::mat4 model = glm::mat4(modelNum);

	return projection * view * model;
}
