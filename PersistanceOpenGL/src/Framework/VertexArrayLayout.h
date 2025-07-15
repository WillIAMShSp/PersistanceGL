#pragma once
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "glm/glm.hpp"


struct VertexBufferElements
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;




};


class VertexArrayLayout
{

public:
	VertexArrayLayout()
	
		:m_Stride(0)
	{
		std::cout << "setting up the Layout \n";
	}
	~VertexArrayLayout()
	{}
	
	
	


	template<typename T>

	void push(unsigned int count)
	{

		

	}

	template<>

	void push <float>(unsigned int count)
	{

		layout.push_back({ GL_FLOAT, count,GL_FALSE });
		m_Stride += count * sizeof(GLfloat);
	}

	template<>

	void push <unsigned int>(unsigned int count)
	{

		layout.push_back({ GL_UNSIGNED_INT, count,GL_FALSE });
		m_Stride += count * sizeof(GLuint);
		


	}

	template<>

	void push <unsigned char>(unsigned int count)
	{

		layout.push_back({ GL_UNSIGNED_BYTE, count ,GL_TRUE });
		m_Stride += count * sizeof(GLubyte);



	}

	template<>
	void push<glm::vec3>(unsigned int count)
	{
		layout.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += count * sizeof(glm::vec3);


	
	}




	inline std::vector<VertexBufferElements> const& GetElements() { return layout; }
	inline unsigned int GetStride() { return m_Stride; }




private:

	std::vector<VertexBufferElements> layout;

	unsigned int m_Stride;

	







};

