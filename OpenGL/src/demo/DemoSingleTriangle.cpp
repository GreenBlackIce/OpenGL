#include "DemoSingleTriangle.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Drawer.h"
#include "imgui/imgui.h"

namespace Demo
{

	DemoSingleTriangle::DemoSingleTriangle()
	{
		
		float vertexPositions[] =
		{
			-0.5f,  0.5f,  0.5f, //0
			 0.5f,  0.5f,  0.5f, //1
			-0.5f, -0.5f,  0.5f, //2
		};

		unsigned int indeces[] =
		{
			0, 1, 2
		};
		
		m_VertexArray = std::make_unique<VertexArray>();
		m_VertexBuffer = std::make_unique<VertexBuffer>(vertexPositions, 9 * sizeof(float));
		m_IndexBuffer = std::make_unique<IndexBuffer>(indeces, 3);

		VertexBufferLayout layout;
		layout.push<float>(3);

		m_VertexArray->addBuffer(*m_VertexBuffer, layout);
		
		m_Shader = std::make_unique<Shader>("..\\OpenGL\\src\\shader\\vertexDemoSingleTriangle.glsl", "..\\OpenGL\\src\\shader\\fragmentDemoSingleTriangle.glsl");

	}

	DemoSingleTriangle::~DemoSingleTriangle()
	{
	}

	void DemoSingleTriangle::onUpdate(float deltaTime)
	{
	}

	void DemoSingleTriangle::onRender()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		Drawer::clear();
		
		m_Shader->bind();
		m_Shader->setUniform3f("u_Color", 0.2f, 0.3f, 0.5f);

		Drawer::draw(*m_Shader, *m_VertexArray, *m_IndexBuffer);
	}

	void DemoSingleTriangle::onImGUIRender()
	{
	}

}