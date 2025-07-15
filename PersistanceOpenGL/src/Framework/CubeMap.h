#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


#include "stb_image/stb_image.h"

#include "VertexArray.h"
#include "Shader.h"



class CubeMap 
{
public:
	CubeMap()
	{
        m_skyboxshader.SetUniform1i("u_Skybox", 0);
    };

	CubeMap(const char* textures[6]);

	void Bind();

    void SetCameraProjectionMatrix(const glm::mat4& projectionmatrix);

    void SetCameraViewMatrix(const glm::mat4& viewmatrix);

    void SetShaderUniforms();
    
    void SetCubeMapVao();

    void Draw();

	inline unsigned int GetID()
	{
		return m_RendererID;
	};

	inline int GetWidth()
	{
		return m_Width;
	}

	inline int GetHeight()
	{
		return m_Height;
	}






private:

	unsigned int m_RendererID = 0;
	unsigned char* m_LocalBuffer = nullptr;
	int m_Width = 0;
	int m_Height = 0;
	int m_BPP = 0;



private:


    float m_skyboxVertices[108] = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f
    };

    VertexBuffer m_vb;
    VertexArray m_vao;
    VertexArrayLayout m_layout;


private:

    glm::mat4 m_projectionmatrix = glm::mat4(1.0);
    glm::mat4 m_viewmatrix = glm::mat4(1.0);

    Shader m_skyboxshader = Shader("res/Shaders/SkyboxVertex.shader", "res/Shaders/SkyboxFragment.shader");




};




