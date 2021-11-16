#pragma once

#include <memory>

#include "Demo.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "GLFW/glfw3.h"
#include "Movement.h"

namespace Demo
{
	class DemoSingleTriangleColorTriSpin : public Demo
	{
	public:
		DemoSingleTriangleColorTriSpin(GLFWwindow* window);
		~DemoSingleTriangleColorTriSpin();

		void onUpdate(float deltaTime) override;
		void onRender() override;
		void onImGUIRender() override;

	private:
		
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<VertexBuffer> m_ColorBuffer;
		std::unique_ptr<Movement> m_Movement;
		
		float m_Color[4];
	};
}