#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>


#include "glm/glm.hpp"
#include "Renderer.h"
struct Materials 
{
	float ka0 = 0, ka1 = 0, ka2 = 0;
	float kd0 = 0, kd1 = 0, kd2 = 0;
	float ks0 = 0, ks1 = 0, ks2 = 0;

	Materials() {}

	Materials(float Ka0, float Ka1, float Ka2, float Kd0, float Kd1, float Kd2, float Ks0, float Ks1, float Ks2)
		: ka0(Ka0), ka1(Ka1), ka2(Ka2), kd0(Kd0), kd1(Kd1), kd2(Kd2), ks0(Ks0), ks1(Ks1), ks2(Ks2)
	{
	}



	

	
};

class MaterialLoader
{
public:
	MaterialLoader();
	MaterialLoader(const std::string& filepath);
	~MaterialLoader();
	void SetUniforms(const unsigned int& shader, Materials& f_material);
	void SetUniforms(const unsigned int& shader, int id);
	void SetUniforms(Shader& shader, Materials& material);

	std::unordered_map<std::string, Materials> m_umats;



private:

	std::vector<std::string> m_mnames;

	std::vector<Materials> m_materials; 

	std::vector<std::string> DivideStrings(const std::string& string, const std::string& delimiter = " ");


};

