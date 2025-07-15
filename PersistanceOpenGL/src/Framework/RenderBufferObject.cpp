#include "RenderBufferObject.h"

RenderBufferObject::RenderBufferObject(const int& width, const int& height)
	:m_Renderer_ID(0), m_Width(width), m_Height(height)
{
	glGenRenderbuffers(1, &m_Renderer_ID);
	Bind();
	SetBufferStorage();
	UnBind();

}

RenderBufferObject::~RenderBufferObject()
{
}

void RenderBufferObject::SetBufferStorage()
{

	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_Width, m_Height);

}

void RenderBufferObject::Bind()
{
	glBindRenderbuffer(GL_RENDERBUFFER, m_Renderer_ID);
}

void RenderBufferObject::UnBind()
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}
