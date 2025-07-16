#pragma once
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"



class Shader
{
public:
	Shader();
	Shader(const std::string& VertexShader, const std::string& FragmentShader);
	~Shader();



	void Bind();
	void UnBind();

	void SetUniform4f(const std::string& name, float value1, float value2, float value3, float value4);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform1i(const std::string& name, int value);
	void SetUniformMat4fv(const std::string& name, const glm::mat4& value);
	void SetUniform3f(const std::string& name, float value1, float value2, float value3);
	void SetUniform3f(const std::string& name, const glm::vec3& vector);

	inline unsigned int GetShader() { return m_Shader; };


private:
	
	std::string ParseShader(std::string path);

	static unsigned int CreateShader(const std::string& VertexShader, const std::string& FragmentShader);

	static unsigned int CompileShader(unsigned int type, const std::string& source);

	unsigned int m_Shader = -1;


};

