#pragma once
#include "Shader.h"

class BasicShader
{
public:
	BasicShader(){};

	inline Shader GetShader()
	{
		return m_basicshader;

	}



private:
	Shader m_basicshader = Shader("res/Shaders/Basicvs.shader", "res/Shaders/Basicfs.shader");

};


