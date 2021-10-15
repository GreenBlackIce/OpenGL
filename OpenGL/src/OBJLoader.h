#pragma once
#include <vector>
#include "glm/gtc/matrix_transform.hpp"

namespace obj
{
	bool loadOBJ(const char * path,
		std::vector<glm::vec3> & out_vertices,
		std::vector<glm::vec2> & out_uvs,
		std::vector<glm::vec3> & out_normals);
}