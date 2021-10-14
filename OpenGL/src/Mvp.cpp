#include "Mvp.h"

glm::mat4 mvp::getMvp(float fov, float width, float height, float modelNum, glm::vec3 camera, glm::vec3 lookat, glm::vec3 vectorUp)
{
	glm::mat4 projection = glm::perspective(glm::radians(fov), width / height, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(camera, lookat, vectorUp);
	glm::mat4 model = glm::mat4(modelNum);

	return projection * view * model;
}

glm::mat4 mvp::getMvp(glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	return projection * view * model;
}

glm::mat4 mvp::getPojection(float fov, float width, float height)
{
	return glm::perspective(glm::radians(fov), width / height, 0.1f, 100.0f);
}

glm::mat4 mvp::getModel(float matrixNum)
{
	return glm::mat4(matrixNum);
}

glm::mat4 mvp::getModel(glm::mat4 model, glm::vec3 translate, glm::vec3 scale)
{
	glm::mat4 ret = glm::translate(model, translate);
	ret = glm::scale(ret, scale);
	return ret;
}

glm::mat4 mvp::getView(glm::vec3 camera, glm::vec3 lookAt, glm::vec3 vectorUp)
{
	return glm::lookAt(camera, lookAt, vectorUp);
}

