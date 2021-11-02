#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace Drawer
{
	void clear();
	void draw(const Shader& shader, const VertexArray& vertexArray, const IndexBuffer& indexBuffer);
}