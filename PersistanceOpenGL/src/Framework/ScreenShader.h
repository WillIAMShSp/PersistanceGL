#pragma once
#include "Renderer.h"
#include "Texture.h"
#include "FullScreenQuad.h"


class ScreenShader
{
public:
	ScreenShader();



	void Apply(Texture& texture);



private:

	const char* ScreenVertexSource = "res/Shaders/Screenvs.shader";
	const char* ScreenFragmentSource = "res/Shaders/Screenfs.shader";
	Shader m_screenshader;



};