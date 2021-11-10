#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Movement.h"
#include "Mvp.h"

#include "demo/DemoClearColor.h"
#include "demo/DemoSingleTriangle.h"
#include "demo/DemoSingleTriangleColor.h"
#include "demo/DemoSingleTriangleColorTri.h"
#include "demo/DemoSingleTriangleSingleColor.h"

int Start();

GLFWwindow* startWindow();
void startRender(GLFWwindow* window);