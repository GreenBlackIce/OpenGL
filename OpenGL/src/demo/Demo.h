#pragma once

#include <vector>
#include <functional>

namespace Demo
{
	class Demo
	{
	public:
		Demo();
		virtual ~Demo() {};

		virtual void onUpdate(float deltaTime) {};
		virtual void onRender() {};
		virtual void onImGUIRender() {};
	};

	class DemoMenu : public Demo
	{
	public:
		DemoMenu(Demo*& currentDemoPointer);
		~DemoMenu() {};

		void onImGUIRender() override;

		template<typename T>
		void registerDemo(const std::string& name)
		{
			std::cout << "Registering demo " << name << std::endl;

			m_Demos.push_back(std::make_pair(name, []() {return new T(); }));
		}

	private:
		Demo*& m_currentDemo;
		std::vector < std::pair<std::string, std::function<Demo*()>>> m_Demos;
	};
}