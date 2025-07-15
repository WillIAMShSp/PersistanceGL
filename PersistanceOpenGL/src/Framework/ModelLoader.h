#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "Renderer.h"
#include "Vertex.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexArrayLayout.h"
#include "MaterialLoader.h"
#include "Shader.h"


class ModelLoader
{

public:

	ModelLoader();
	ModelLoader(const std::string& filepath, Shader& shader);
	ModelLoader(const std::string& ModelPath, const std::string& MaterialPath, Shader& shader);
	~ModelLoader();		


	

	

	

	



	void Draw(Renderer& renderer);




private:
	std::vector<VertexBuffer> VertexBuffers;
	std::vector<Vertex> vertices;
	std::vector<glm::vec3> pos;
	std::vector<glm::vec2> uv;
	std::vector<glm::vec3> norm;
	std::vector<std::string>matnames;

	

private:



	


	std::vector<std::string> DivideString(const std::string& string, const std::string& delimiter = " ");
	void DivideStringInto(const std::string& string, const std::string& delimiter, std::vector<std::string>& vector);

	void ReadTriangles(const std::string& description);
	void ReadTriangles(const std::string& description, std::vector<Vertex>& vertices);

private:
	
	int materialcount = 0;
	bool ismaterialused = false;

	std::string MaterialPath;
	VertexArray vao; 
	VertexArrayLayout layout;
	VertexBuffer vb;
	Shader m_shadersource;
	//todo: learn how to use pointers for this
	MaterialLoader MatLoader;
	glm::mat4 m_modeluniform = 1.0;


};





