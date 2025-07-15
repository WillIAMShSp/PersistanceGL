#include "Star.h"

Star::Star()
{
}

Star::~Star()
{
}

void Star::Update()
{
	Draw();

}

void Star::SetPosition(const glm::vec3& newpos)
{
	m_position = newpos;
}

void Star::SetShader(Shader& shader)
{
	m_shadersource = shader;

}

void Star::SetModel(ModelLoader& model)
{
	m_model = model;

}

void Star::SetRenderer(Renderer& renderer)
{
	m_renderer = renderer;
}

void Star::Draw()
{
	m_shadersource.Bind();
	
	m_modelmatrix = glm::mat4(1.f);
	
	m_modelmatrix = glm::translate(m_modelmatrix, m_position);
	
	m_shadersource.SetUniformMat4fv("u_Model", m_modelmatrix);
	
	m_model.Draw(m_renderer);
}



