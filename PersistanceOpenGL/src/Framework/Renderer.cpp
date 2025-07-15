#include "Renderer.h"



Renderer::Renderer()
{


}

void Renderer::Draw(VertexArray& vao, IndexBuffer& ib, Shader& shader)
{
	
	vao.Bind();
	ib.Bind();
	shader.Bind();

	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);

}

void Renderer::Draw(VertexArray& vao, int count,  Shader& shader)
{
	vao.Bind();
	shader.Bind();

	glDrawArrays(GL_TRIANGLES, 0, count);




}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


}
