#pragma once
#include "VertexArray.h"
#include "VertexArrayLayout.h"
#include "VertexBuffer.h"


class Square
{
public:

    Square();
    void SetQuad();

private:

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


    VertexArray vao;
};

