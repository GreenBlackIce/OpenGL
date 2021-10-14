#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Movement.h"
#include "Mvp.h"

int Start();

GLFWwindow* startWindow();
void startRender(GLFWwindow* window);