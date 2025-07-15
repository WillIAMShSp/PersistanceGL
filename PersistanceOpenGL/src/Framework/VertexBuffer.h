#pragma once
#include <vector>
#include "Vertex.h"

class VertexBuffer 
{
public:
	VertexBuffer();
	VertexBuffer(const void* data, unsigned int size);
	VertexBuffer(const std::vector<Vertex>& verts);
	VertexBuffer(const std::vector<float>& verts);

	inline size_t GetSize() { return size; };


	void AddBuffer(const std::vector<Vertex>& verts);
	


	~VertexBuffer();

	void Bind();
	void UnBind();




private:
	unsigned int m_RendererID;
	size_t size = 0;


};
