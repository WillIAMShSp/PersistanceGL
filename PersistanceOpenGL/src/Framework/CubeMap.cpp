#include "CubeMap.h"

CubeMap::CubeMap(const char* textures[6])
	
{
	m_skyboxshader.SetUniform1i("u_Skybox", 0);

	glGenTextures(1, &m_RendererID);
	Bind();
	
	for (int i = 0; i < 6; i++)
	{
		m_LocalBuffer = stbi_load(textures[i], &m_Width, &m_Height, &m_BPP, 0);

		if (m_LocalBuffer)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_LocalBuffer);
			stbi_image_free(m_LocalBuffer);
		
		}
		else
		{
			std::cout << "Failed to Read Data";

		}

	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);


}

void CubeMap::Bind()
{
	
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_RendererID);

}

void CubeMap::SetCameraProjectionMatrix(const glm::mat4& projectionmatrix)
{
	m_projectionmatrix = projectionmatrix;

}

void CubeMap::SetCameraViewMatrix(const glm::mat4& viewmatrix)
{
	m_viewmatrix = glm::mat4(glm::mat3(viewmatrix));
}

void CubeMap::SetShaderUniforms()
{
	
	m_skyboxshader.SetUniformMat4fv("u_View", m_viewmatrix);
	m_skyboxshader.SetUniformMat4fv("u_Projection", m_projectionmatrix);
	m_skyboxshader.SetUniform1i("u_Skybox", 0);


}

void CubeMap::SetCubeMapVao()
{
	m_vb = VertexBuffer(m_skyboxVertices, sizeof(m_skyboxVertices));
	m_layout.push<float>(3);
	m_vao.AddBuffer(m_vb, m_layout);

}

void CubeMap::Draw()
{
	
	glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
	m_skyboxshader.Bind();
	
	SetShaderUniforms();
	
	// skybox cube
	glDepthMask(GL_FALSE);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	
	m_vao.Bind();
	glActiveTexture(GL_TEXTURE0);
	Bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthFunc(GL_LESS);

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	
	
	
	
	
	


}
