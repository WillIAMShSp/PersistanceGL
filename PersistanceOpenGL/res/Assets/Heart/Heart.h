#pragma once
#include "ModelLoader.h"
#include "MaterialLoader.h"
#include "Shader.h"
#include "Renderer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Heart
{
public:

	Heart();
	~Heart();

	void Update();
	
	void SetPosition(const glm::vec3& newpos);

	
	


private:




private: //Dependencies

	ModelLoader nullmodel;
	ModelLoader& m_model = nullmodel;
	Shader nullshader;
	Shader& m_shadersource = nullshader;
	Renderer nullrenderer;
	Renderer& m_renderer = nullrenderer;
	glm::mat4 m_modelmatrix = glm::mat4(1.f);
	glm::vec3 m_position = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 m_orientation = glm::vec3(0.f, 0.f, 0.f);
	




public:

	void SetShader(const Shader& shader);
	void SetModel(const ModelLoader& model);
	void SetRenderer(const Renderer& renderer);
	void Draw();
	



};