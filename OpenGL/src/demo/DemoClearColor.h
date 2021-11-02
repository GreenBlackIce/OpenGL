#pragma once

#include "Demo.h"

namespace Demo
{
	class DemoClearColor : public Demo
	{
	public:
		DemoClearColor();
		~DemoClearColor();

		void onUpdate(float deltaTime) override;
		void onRender() override;
		void onImGUIRender() override;

	private:
		float m_ClearColor[4];
	};
}