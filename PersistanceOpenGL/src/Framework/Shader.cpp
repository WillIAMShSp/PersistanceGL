#include "Shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


Shader::Shader()
{

}

Shader::Shader(const std::string& VertexShader, const std::string& FragmentShader)
{
    
    m_Shader = CreateShader(ParseShader(VertexShader), ParseShader(FragmentShader));

    Bind();

    

}

Shader::~Shader()
{
}

void Shader::Bind()
{
    glUseProgram(m_Shader);

}

void Shader::UnBind()
{
    glUseProgram(0);
}

void Shader::SetUniform4f(const std::string& name, float value1, float value2, float value3, float value4)
{
    
    Bind();
    int location = glGetUniformLocation(m_Shader, name.c_str());

    glUniform4f(location, value1, value2, value3, value4);


    if (location == -1)
    {
        std::cout << name << " uniform does not exist \n";

    }
    UnBind();

}

void Shader::SetUniform3f(const std::string& name, float value1, float value2, float value3)
{
    Bind();
    int location = glGetUniformLocation(m_Shader, name.c_str());

    glUniform3f(location, value1, value2, value3);

    UnBind();

}

void Shader::SetUniform3f(const std::string& name, const glm::vec3& vector)
{
    Bind();
    int location = glGetUniformLocation(m_Shader, name.c_str());

    glUniform3f(location, vector.x, vector.y, vector.z);
    
    UnBind();


}

void Shader::SetUniform1f(const std::string& name, float value)
{
    Bind();
    int location = glGetUniformLocation(m_Shader, name.c_str());

    glUniform1f(location, value);

    if (location == -1)
    {
        std::cout << name << " uniform does not exist \n";

    }
    UnBind();

}

void Shader::SetUniform1i(const std::string& name, int value)
{
    Bind();
    int location = glGetUniformLocation(m_Shader, name.c_str());

    glUniform1i(location, value);

    if (location == -1)
    {
        std::cout << name << " uniform does not exist \n";

    }

    UnBind();

}

void Shader::SetUniformMat4fv(const std::string& name, const glm::mat4& matrix)
{
    Bind();
    int location = glGetUniformLocation(m_Shader, name.c_str());

    glUniformMatrix4fv(location, 1, 0, &matrix[0][0]);

    UnBind();

}





std::string Shader::ParseShader(std::string path)
{
    std::ifstream stream(path);
    std::string line;
    std::stringstream ss;



    while (getline(stream, line))
    {


        ss << line << "\n";




    }

    return ss.str();




}
unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str();



    glShaderSource(shader, 1, &src, nullptr);

    glCompileShader(shader);

    int shaderscompiled; //did they work? umm idk, lets check!

    glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderscompiled);

    if (shaderscompiled == 0)
    {

        int length = GL_INFO_LOG_LENGTH;




        char* message = (char*)alloca(sizeof(char) * length);

        glGetShaderInfoLog(shader, length, &length, message);

        std::cout << "shit\n";
        std::cout << message;

        glDeleteShader(shader);
        return 0;

    }





    return shader;



}
unsigned int Shader::CreateShader(const std::string& VertexShader, const std::string& FragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, VertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, FragmentShader);


    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);



    return program;






}