#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "stb_image/stb_image.h"
#include <string>



class Texture
{
public:
	Texture();
	Texture(const std::string& path);
	Texture(const int& width, const int& height);
	~Texture();

	void DepthMap(const int& width, const int& height, const unsigned int& depthtexturewrap = GL_REPEAT);

	void Bind(const uint16_t& slot = 0);
	void UnBind();


	inline int GetWidth() { return m_Width; }
	inline int GetHeight() { return m_Height; }
	inline unsigned int GetID() const { return m_RendererID; }

private:
	GLuint m_RendererID = 0;
	unsigned char* m_LocalBuffer = nullptr;
	int m_Width = 0;
	int m_Height = 0;
	int m_BPP = 0;

	uint8_t m_texslot = 0;




};
