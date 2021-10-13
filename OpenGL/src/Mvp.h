#pragma once
#include "glm/gtc/matrix_transform.hpp"

namespace mvp 
{
	glm::mat4 getMvp(float fov, float width, float height, float modelNum, glm::vec3 camera, glm::vec3 lookat, glm::vec3 vectorUp);
}