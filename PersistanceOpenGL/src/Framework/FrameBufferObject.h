#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Texture.h"
#include "RenderBufferObject.h"

class FrameBufferObject
{
public:
	FrameBufferObject(const int& width, const int& height);
	~FrameBufferObject();

	void SetTexture2D(const unsigned int& amountoftextures = 1);
	void SetDepthMap();
	void SetRenderBuffer();
	void Bind();
	void UnBind();

	inline unsigned int GetID() { return m_rendererid; }
	inline Texture& GetTex(const unsigned int& index = 0) { return m_textures[0]; }
	inline unsigned int GetTexID(const unsigned int& index = 0) { return m_textures[index].GetID(); }
	inline Texture& GetDepthTex() { return m_depthmap; }
	inline unsigned int GetDepthTexID() { return m_depthmap.GetID(); }
	inline unsigned int GetRboID() { return m_Rbo_ID; }	

private:

	bool m_textureassigned = false;
	unsigned int m_rendererid;
	int m_width = 0;
	int m_height = 0;

	unsigned int m_Rbo_ID = 0xFFFFFFFF;
	
	std::vector<Texture> m_textures;

	Texture m_depthmap;




};

