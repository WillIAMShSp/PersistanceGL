#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class RenderBufferObject
{

public:

	RenderBufferObject(const int& width, const int& height);
	~RenderBufferObject();

	void SetBufferStorage();
	void Bind();
	void UnBind();



	inline unsigned int GetID() { return m_Renderer_ID; }
	inline int GetWidth() { return m_Width; }
	inline int GetHeight() { return m_Height; }



private:
	unsigned int m_Renderer_ID;
	int m_Width = 0;
	int m_Height = 0;



};

