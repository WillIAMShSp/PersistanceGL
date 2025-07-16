#include "PlanetsScene.h"




PlanetsScene::PlanetsScene()
{
}

void PlanetsScene::Lights()
{
	m_shader.Bind();
	m_shader.SetUniform1i("amountoflights", (int)m_pointlights.size());
	
	for (int i = 0; i < m_pointlights.size(); i++)
	{
		std::string n = std::to_string(i);

		m_shader.SetUniform3f("gLights[" + n + "].LightPosition", m_pointlights[i].m_position.x, m_pointlights[i].m_position.y, m_pointlights[i].m_position.z);
		m_shader.SetUniform3f("gLights[" + n + "].LightColor", m_pointlights[i].m_color.r, m_pointlights[i].m_color.g, m_pointlights[i].m_color.b);
		m_shader.SetUniform1f("gLights[" + n + "].AmbientIntensity", m_pointlights[i].m_ambientintensity);

	}


}

void PlanetsScene::InitModels()
{

	

	

}

void PlanetsScene::InitCubeMap()
{
	m_cubemap.SetCameraProjectionMatrix(m_camera.GetProjectionMatrix());
	m_cubemap.SetCameraViewMatrix(m_camera.GetViewMatrix());
	m_cubemap.SetCubeMapVao();
	m_cubemap.SetShaderUniforms();

}

void PlanetsScene::SetRenderer(const Renderer& renderer)
{
	m_render = renderer;
}

void PlanetsScene::SetCamera(Camera& camera)
{
	m_camera = camera;

}

void PlanetsScene::Load()
{
	Lights();
	InitCubeMap();
	InitModels();
	
}

void PlanetsScene::Update()
{

	Lights();




}

void PlanetsScene::Draw()
{

	m_camera.Matrix(90.f, 0.1f, 100.f, m_shader);
	m_cubemap.SetCameraProjectionMatrix(m_camera.GetProjectionMatrix());
	m_cubemap.SetCameraViewMatrix(m_camera.GetViewMatrix());
	m_cubemap.Draw();
	m_shader.Bind();
	
	

}
