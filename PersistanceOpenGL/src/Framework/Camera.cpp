#include "Camera.h"

Camera::Camera()
{
}

Camera::Camera(const int& width, const int& height, glm::vec3 position)
	:m_width(width), m_height(height), Position(position)
{
}



void Camera::Matrix(const float& fov, const float& near, const float& far, Shader& shader)
{

	m_viewmatrix = glm::lookAt(Position, Position + Orientation, Up);
	m_inverseviewmatrix = glm::inverse(m_viewmatrix);

	m_projectionmatrix = glm::perspective(glm::radians(fov), float(m_width * 0.9 / m_height), near, far);
	m_inverseprojectionmatrix = glm::inverse(m_projectionmatrix);

	shader.Bind();
	shader.SetUniformMat4fv("u_View", m_viewmatrix);
	shader.SetUniformMat4fv("u_Projection", m_projectionmatrix);
	shader.UnBind();

	
}

void Camera::Input(GLFWwindow* window) // The input is kinda backwards from what unity et al use so keep that in mind.
{


	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Position += speed * Up;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Position += speed * -Up;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speed = 0.3f;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		speed = 0.1f;
	}

	
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		lockmouse = false;
		initialactivation = true;

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	}



	if (lockmouse) 
	{

		

		if (initialactivation)
		{
			glfwSetCursorPos(window, m_width / 2, m_height / 2);
			
			initialactivation = false;
			
		}
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		
		double mouseX = 0;
		double mouseY = 0;

		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = sensitivity * (float)(mouseY - (m_height / 2)) / m_height;
		float rotY = sensitivity * (float)(mouseX - (m_width / 2)) / m_width;


		

		glm::vec3 NewOrientation = glm::rotate(Orientation, glm::radians(-rotX), (glm::vec3)glm::normalize(glm::cross(Orientation, Up)));

		if (!(glm::angle(NewOrientation, Up) <= glm::radians(5.f) || (glm::angle(NewOrientation, -Up) <= glm::radians(5.f)))) //might have something weird
		{
			Orientation = NewOrientation;
		}

		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		glfwSetCursorPos(window, m_width / 2, m_height / 2);



	}


}
