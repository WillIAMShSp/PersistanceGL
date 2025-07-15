#pragma once
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexArrayLayout.h"



struct FullScreenQuad
{

    FullScreenQuad()
        :vb(vertices, 30*sizeof(float))
    {

        layout.push<float>(3);
        layout.push<float>(2);
        vao.AddBuffer(vb, layout);



    }


    const float vertices[30] =
    {
        // Triangle 1
            -1.0, -1.0, 0.0, 0.0, 0.0, // Bottom-left (position and texture coordinate)
            1.0, -1.0, 0.0, 1.0, 0.0, // Bottom-right
            -1.0, 1.0, 0.0, 0.0, 1.0, // Top-left

            // Triangle 2
            -1.0, 1.0, 0.0, 0.0, 1.0, // Top-left
            1.0, -1.0, 0.0, 1.0, 0.0, // Bottom-right
            1.0, 1.0, 0.0, 1.0, 1.0  // Top-right
    };
    

    void Draw()
    {
        vao.Bind();

        glDrawArrays(GL_TRIANGLES, 0, 6);

    }
	
    VertexBuffer vb;
    VertexArray vao;
    VertexArrayLayout layout;



};

