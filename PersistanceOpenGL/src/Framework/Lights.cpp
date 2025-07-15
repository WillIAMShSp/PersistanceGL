#include "Lights.h"

PointLight::PointLight()
{
}

PointLight::PointLight(const glm::vec3& position, const glm::vec3& color, const float& ambientintensity)
{

	m_position = position;

	m_color = color;

	m_ambientintensity = ambientintensity;



}
