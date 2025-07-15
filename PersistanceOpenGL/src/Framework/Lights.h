#pragma once
#include "glm/glm.hpp"
#include "Shader.h"


class PointLight
{
public:
	PointLight();
	PointLight(const glm::vec3& position, const glm::vec3& color, const float& ambientintensity = 0.8f);
	~PointLight(){};
	
	glm::vec3 m_position = glm::vec3(0.f);
	glm::vec3 m_color = glm::vec3(0.f);
	float m_ambientintensity = 0.f;


};

class SpotLight
{


};


class DirectionalLight
{




};




