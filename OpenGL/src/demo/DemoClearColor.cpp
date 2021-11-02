#include "DemoClearColor.h"
#include "Renderer.h"
#include "imgui/imgui.h"

namespace Demo
{

	DemoClearColor::DemoClearColor()
		:m_ClearColor{0.5f, 0.2f, 0.6f, 1.0f}
	{
	}

	DemoClearColor::~DemoClearColor()
	{
	}

	void DemoClearColor::onUpdate(float deltaTime)
	{
	}

	void DemoClearColor::onRender()
	{
		GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void DemoClearColor::onImGUIRender()
	{
		ImGui::ColorEdit4("Clearcolor", m_ClearColor);
	}

}