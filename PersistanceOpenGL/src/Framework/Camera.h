#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "Shader.h"

class Camera
{
public:

	Camera();
	Camera(const int& width, const int& height, glm::vec3 position);
	

	void Matrix(const float& fov, const float& near, const float& far, Shader& shader);

	void Input(GLFWwindow* window);



	inline glm::mat4& GetViewMatrix()
	{
		return m_viewmatrix;
	}

	inline glm::mat4& GetInverseViewMatrix()
	{
		return m_inverseviewmatrix;

	}



	inline glm::mat4& GetProjectionMatrix()
	{
		return m_projectionmatrix;
	}

	inline glm::mat4 GetInverseProjectionMatrix()
	{
		return m_inverseprojectionmatrix;
	}



	inline glm::vec3& GetViewDirection()
	{
		return Orientation;
	}

	inline glm::vec3& GetPosition()
	{
		return Position;
	}



	bool lockmouse = false;


private:

	glm::vec3 Position = glm::vec3(0.f); //position of the camera in world space
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f); // the camera's view direction
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f); // the up direction of the camera. ie. Which direction does the upper part of the screen point to.


	int m_width = 0;
	int m_height = 0;


	float speed = 0.001f;
	float sensitivity = 100.f;



	bool initialactivation = true;

	glm::mat4 m_projectionmatrix = glm::mat4(1.0);
	glm::mat4 m_viewmatrix = glm::mat4(1.0);
	
	glm::mat4 m_inverseviewmatrix = glm::mat4(1.0);
	glm::mat4 m_inverseprojectionmatrix = glm::mat4(1.0);
	

};