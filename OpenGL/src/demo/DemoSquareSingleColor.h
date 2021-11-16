#pragma once

#include <memory>

#include "Demo.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

namespace Demo
{
	class DemoSquareSingleColor : public Demo
	{
	public:
		DemoSquareSingleColor();
		~DemoSquareSingleColor();

		void onUpdate(float deltaTime) override;
		void onRender() override;
		void onImGUIRender() override;

	private:
		
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<VertexBuffer> m_ColorBuffer;
		
		float m_Color[4];
	};
}