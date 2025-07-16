#pragma once
#include <GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"




class Renderer
{


public:
	Renderer();

	void Draw(VertexArray& vao, IndexBuffer& ib, Shader& shader);
	void Draw(VertexArray& vao, size_t count, Shader& shader);
	void Clear();
	
private:

	

};







