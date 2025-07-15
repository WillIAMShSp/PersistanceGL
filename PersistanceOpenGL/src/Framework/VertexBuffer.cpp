#include "VertexBuffer.h"
#include "Renderer.h"
#include <iostream>

VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    :size(size)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);



}

VertexBuffer::VertexBuffer(const std::vector<Vertex>& verts)
    :size(verts.size())
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), verts.data(), GL_STATIC_DRAW);

   
}

VertexBuffer::VertexBuffer(const std::vector<float>& verts)
    :size(verts.size())
{
    
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), verts.data(), GL_STATIC_DRAW);

}

void VertexBuffer::AddBuffer(const std::vector<Vertex>& verts)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), verts.data(), GL_STATIC_DRAW);

}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::Bind()
{
    
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    
}

void VertexBuffer::UnBind()
{    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
