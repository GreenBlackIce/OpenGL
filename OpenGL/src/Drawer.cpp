#include "Drawer.h"
#include "Renderer.h"

void Drawer::clear()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Drawer::draw(const Shader & shader, const VertexArray & vertexArray, const IndexBuffer & indexBuffer)
{
	vertexArray.bind();
	indexBuffer.bind();
	shader.bind();
	GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr));
}
