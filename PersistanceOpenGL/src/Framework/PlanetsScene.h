#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"
#include "ModelLoader.h"
#include "Camera.h"
#include "CubeMap.h"
#include "Lights.h"
#include "BasicShader.h"





class PlanetsScene
{
public:
	PlanetsScene();
	
	void Lights();
	void InitModels();
	void InitCubeMap();
	void SetRenderer(const Renderer& renderer);
	void SetCamera(Camera& camera);
	void Load();
	void Update();
	void Draw();

	inline Shader GetShader()
	{
		return m_shader;
	}


private: //These are predefined things per scene

	
	Renderer m_render;
	Camera m_camera;


	BasicShader m_basicshader;
	Shader m_shader = m_basicshader.GetShader();
	std::vector<PointLight> m_pointlights
	{
		PointLight(glm::vec3(0.f,0.f,10.f), glm::vec3(1.f,1.f,1.f), 1.f),
		
		



	};

private: //cubemaps

	const char* cubemaptextures[6]
	{

	   "res/Skyboxes/GalaxySkybox/Right.jpg",
	   "res/Skyboxes/GalaxySkybox/Left.jpg",
	   "res/Skyboxes/GalaxySkybox/Top.jpg",
	   "res/Skyboxes/GalaxySkybox/Bottom.jpg",
	   "res/Skyboxes/GalaxySkybox/Front.jpg",
	   "res/Skyboxes/GalaxySkybox/Back.jpg"


	};

	
	CubeMap m_cubemap = CubeMap(cubemaptextures);



private:   //Here goes whatever objects I want for the scene

	



};





