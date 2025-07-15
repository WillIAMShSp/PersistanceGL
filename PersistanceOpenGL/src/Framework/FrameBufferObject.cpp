#include "FrameBufferObject.h"

FrameBufferObject::FrameBufferObject(const int& width, const int& height)
	:m_width(width), m_height(height)
{
	

	glGenFramebuffers(1, &m_rendererid);
	




}

FrameBufferObject::~FrameBufferObject()
{
}

void FrameBufferObject::SetTexture2D(const unsigned int& amountoftextures)
{
	
	if (m_textures.size() != amountoftextures)
	{
		m_textures.reserve(amountoftextures);
		m_textureassigned = false;

	}
	

	for (int i = 0; i < amountoftextures; i++)
	{
		if (m_textureassigned)
		{
			m_textures[i].Bind(i);

		}

		else
		{
			Bind();
			m_textures.push_back(Texture(m_width, m_height));

			const unsigned int& textureid = m_textures[i].GetID();

			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0+i, GL_TEXTURE_2D, textureid, 0);

			UnBind();


		}







	}
	



	
	
}

void FrameBufferObject::SetDepthMap()
{
	if (m_textureassigned)
	{
		m_depthmap.Bind();
	}
	else 
	{
		m_textureassigned = true;

		Bind();
		m_depthmap.DepthMap(m_width, m_height);

		const unsigned int& textureid = m_depthmap.GetID();

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, textureid, 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);

		UnBind();
	}
	


}

void FrameBufferObject::SetRenderBuffer()
{
	Bind();
	RenderBufferObject rbo(m_width, m_height);

	m_Rbo_ID = rbo.GetID();

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_Rbo_ID);
	
	UnBind();

}

void FrameBufferObject::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_rendererid);

}

void FrameBufferObject::UnBind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
