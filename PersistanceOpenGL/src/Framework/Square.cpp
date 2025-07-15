#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Square.h"


Square::Square()
{
    
    
    



}

void Square::SetQuad()
{
    vao.Bind();
    VertexArrayLayout layout;
    layout.push<float>(3);
    layout.push<float>(2);

    VertexBuffer vb(vertices, 6);

    vao.AddBuffer(vb, layout);
}


