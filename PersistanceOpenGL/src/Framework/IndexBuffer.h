#pragma once
#include <vector>



class IndexBuffer
{
public:
	IndexBuffer()
	{
	};
	IndexBuffer(const unsigned int* data, unsigned int count);
	IndexBuffer(const std::vector<unsigned int>& indexes);

	void AddBuffer(const std::vector<unsigned int>& indexes);

	~IndexBuffer();

	void Bind();
	void UnBind();

	


	inline unsigned int GetCount() const { return m_Count; }

	


private:

	unsigned int m_RendererID = -1;
	unsigned int m_Count = -1;


};
