#pragma once
#include "glm/gtc/matrix_transform.hpp"

namespace mvp 
{
	glm::mat4 getMvp(float fov, float width, float height, float modelNum, glm::vec3 camera, glm::vec3 lookat, glm::vec3 vectorUp);
	glm::mat4 getMvp(glm::mat4 model, glm::mat4 view, glm::mat4 projection);
	glm::mat4 getPojection(float fov, float width, float height);
	glm::mat4 getModel(float matrixNum);
	glm::mat4 getModel(glm::mat4 model, glm::vec3 translate, glm::vec3 scale);
	glm::mat4 getView(glm::vec3 camera, glm::vec3 lookAt, glm::vec3 vectorUp);
}