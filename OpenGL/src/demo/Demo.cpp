#include "Demo.h"
#include "imgui/imgui.h"

namespace Demo
{

	DemoMenu::DemoMenu(Demo*& currentDemoPointer)
		:m_currentDemo(currentDemoPointer)
	{

	}

	void DemoMenu::onImGUIRender()
	{
		for (auto& demo : m_Demos)
		{
			if (ImGui::Button(demo.first.c_str()))
				m_currentDemo = demo.second();
		}
	}
	Demo::Demo()
	{
	}
}