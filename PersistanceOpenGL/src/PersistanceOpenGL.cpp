


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

	Renderer render;
	FullScreenQuad quad;

#pragma region Shader declarations
	const char* VertexSource = "res/Shaders/Basicvs.shader";
	const char* FragmentSource = "res/Shaders/Basicfs.shader";


	Shader shader(VertexSource, FragmentSource);
	

	const char* solidsourcevs = "res/Shaders/Basicvs.shader";
	const char* solidsourcefs = "res/Shaders/Solidfs.shader";


	Shader solidsource(solidsourcevs, solidsourcefs);

   

#pragma endregion

 

  



	



#pragma region Basic shader initialization




	Camera camera(screenwidth, screenheight, glm::vec3(0.f, 0.f, 5.f));

	camera.Matrix(90.f, 0.1f, 100.f, solidsource);


	shader.SetUniform3f("gLight.LightPosition", 0, 0, 0);
	shader.SetUniform3f("gLight.LightColor", 1, 1, 1);

	shader.SetUniform1f("gLights[0].AmbientIntensity", 0.4f);


	shader.SetUniform1i("amountoflights", 2);
	shader.SetUniform3f("gLights[0].LightPosition", 0, 10, 0);
	shader.SetUniform3f("gLights[0].LightColor", 1, 1, 1);
	shader.SetUniform3f("gLights[1].LightPosition", 0, 0, 15);
	shader.SetUniform3f("gLights[1].LightColor", 1, 1, 0);










#pragma endregion

#pragma region IMGUI initialization
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsLight();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

#pragma endregion


   
	ModelLoader heartmodel("res/Models/Heart.obj", "res/Materials/Heart.mtl", shader);

	RenderableObject heart;

	heart.SetModel(heartmodel);
	heart.SetPosition(glm::vec3(0.f,0.f,0.f));
	heart.SetRenderer(render);
	heart.SetShader(shader);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		//updated every frame!

		

		/* Render here */
		glEnable(GL_DEPTH_TEST);
		

		glClearColor(0.f, 0.f, 0.f, 1.f);
		render.Clear();


		camera.Input(window);


		camera.Matrix(45.f, 0.1f, 100.f, shader);
	   
		heart.Draw();

		
		/*--------------------------------------*/

		//ImGUi

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();



		ImGui::Begin("Window");

		
		ImGui::Checkbox("Lock Mouse", &camera.lockmouse);
		
		
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
