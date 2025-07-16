


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <iostream>
#include <string>
#include <vector>

//vendor dependencies
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


//written classes
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "FrameBufferObject.h"
#include "Square.h"
#include "Renderer.h"
#include "Texture.h"
#include "ModelLoader.h"
#include "Vertex.h"
#include "MaterialLoader.h"
#include "Camera.h"
#include "FullScreenQuad.h"
#include "CubeMap.h"
#include "RenderableObject.h"





#define BREAK() __debugbreak();



void GLAPIENTRY MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	std::cout << "[OPENGL ERROR] ( " << type << " )" << message << std::endl;
	BREAK();
}


const unsigned int screenwidth = 1920;
const unsigned int screenheight = 1080;



int main(void)
{
	GLFWwindow* window;
	Renderer renderer;
	/* Initialize the library */
	if (!glfwInit())
		return -1;
	
	
	
	glfwWindowHint(GLFW_CONTEXT_DEBUG, GL_TRUE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(screenwidth, screenheight, "Game", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
		std::cout << "error\n";
	glfwSwapInterval(1);




	std::cout << glGetString(GL_VERSION) << std::endl;




	glViewport(0, 0, screenwidth, screenheight);
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);
	//glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	



#pragma region IMGUI initialization
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsLight();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

#pragma endregion


   
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		//updated every frame!

		

		/* Render here */
		glEnable(GL_DEPTH_TEST);
		

		glClearColor(0.f, 0.f, 0.f, 1.f);
		renderer.Clear();

		
		/*--------------------------------------*/

		
		
		
		
		
		
		
		
		
		//ImGUi

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();



		ImGui::Begin("Window");

		
		
		
		ImGui::End();



		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());





		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}



	glfwTerminate();
	return 0;

}
