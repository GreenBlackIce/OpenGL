#include "DemoSingleTriangleColor.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Drawer.h"
#include "imgui/imgui.h"

namespace Demo
{

	DemoSingleTriangleColor::DemoSingleTriangleColor()
		:m_Color{ 0.2f, 0.3f, 0.5f, 1.0f }
	{
		float colorBufferData[] =
		{
			0.5f,  0.7f,  0.0f,
			0.6f,  0.1f,  0.4f,
			0.3f,  0.4f,  0.8f
		};

		float vertexPositions[] =
		{
			 0.5f, -0.5f,  0.0f, //0
			-0.5f, -0.5f,  0.0f, //1
			 0.0f,  0.5f,  0.0f, //2
		};

		unsigned int indeces[] =
		{
			0, 1, 2
		};
		
		m_VertexArray = std::make_unique<VertexArray>();
		m_VertexBuffer = std::make_unique<VertexBuffer>(vertexPositions, 9 * sizeof(float));
		m_ColorBuffer = std::make_unique<VertexBuffer>(colorBufferData, 9 * sizeof(float));
		m_IndexBuffer = std::make_unique<IndexBuffer>(indeces, 3);

		VertexBufferLayout layout;
		layout.push<float>(3);
		layout.push<float>(3);
		//TODO: AddBuffer with 2 Pointers

		m_VertexArray->addBuffer(*m_VertexBuffer, layout);
		
		m_Shader = std::make_unique<Shader>("..\\OpenGL\\src\\shader\\vertexDemoSingleTriangleColor.glsl", "..\\OpenGL\\src\\shader\\fragmentDemoSingleTriangleColor.glsl");

	}

	DemoSingleTriangleColor::~DemoSingleTriangleColor()
	{
	}

	void DemoSingleTriangleColor::onUpdate(float deltaTime)
	{

	}

	void DemoSingleTriangleColor::onRender()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		Drawer::clear();

		m_Shader->bind();
		m_Shader->setUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], m_Color[3]);

		Drawer::draw(*m_Shader, *m_VertexArray, *m_IndexBuffer);
	}

	void DemoSingleTriangleColor::onImGUIRender()
	{
		ImGui::ColorEdit4("Color", m_Color);
	}

}