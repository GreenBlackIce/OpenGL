#include "DemoSingleTriangleColorTriSpin.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Drawer.h"
#include "imgui/imgui.h"

namespace Demo
{

	DemoSingleTriangleColorTriSpin::DemoSingleTriangleColorTriSpin(GLFWwindow* window)
		:m_Color{ 1.0f, 1.0f, 1.0f, 1.0f }
	{

		float vertexPositions[] =
		{
			 0.5f, -0.5f,  0.0f, 0.5f,  0.7f,  0.0f,
			-0.5f, -0.5f,  0.0f, 0.6f,  0.1f,  0.4f,
			 0.0f,  0.5f,  0.0f, 0.3f,  0.4f,  0.8f
		};

		unsigned int indeces[] =
		{
			0, 1, 2
		};

		m_VertexArray = std::make_unique<VertexArray>();
		m_VertexBuffer = std::make_unique<VertexBuffer>(vertexPositions, 18 * sizeof(float));
		m_IndexBuffer = std::make_unique<IndexBuffer>(indeces, 3);
		m_Movement = std::make_unique<Movement>(window);

		VertexBufferLayout layout;
		layout.push<float>(3);
		layout.push<float>(3);

		m_VertexArray->addBuffer(*m_VertexBuffer, layout);
		
		m_Shader = std::make_unique<Shader>("..\\OpenGL\\src\\shader\\vertexDemoSingleTriangleColorTriSpin.glsl", "..\\OpenGL\\src\\shader\\fragmentDemoSingleTriangleColorTriSpin.glsl");

	}

	DemoSingleTriangleColorTriSpin::~DemoSingleTriangleColorTriSpin()
	{
	}

	void DemoSingleTriangleColorTriSpin::onUpdate(float deltaTime)
	{

	}

	void DemoSingleTriangleColorTriSpin::onRender()
	{
		m_Movement->movementStart();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		Drawer::clear();

		glm::mat4 mvp = m_Movement->m_MovementData.getMvp();

		m_Shader->bind();
		m_Shader->setUniformMatrix4fv("MVP", 1, false, mvp);
		m_Shader->setUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], m_Color[3]);

		Drawer::draw(*m_Shader, *m_VertexArray, *m_IndexBuffer);
	}

	void DemoSingleTriangleColorTriSpin::onImGUIRender()
	{
		ImGui::ColorEdit4("Color", m_Color);
	}

}