#pragma once
#include <vector>

#include "defines.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "shader.h"

class Drawable {

public:
Drawable(std::vector<Vertex> vertices, std::vector<uint32_t> indices, const char* vertexShader, const char* fragmentShader) : 
    numIndices(indices.size()), vertexBuffer(VertexBuffer((void*) vertices.data(), vertices.size())), 
    indexBuffer(IndexBuffer((void*) indices.data(), indices.size())), shader(Shader(vertexShader, fragmentShader)) {
}

void draw(GLenum mode);

private:
VertexBuffer vertexBuffer;
IndexBuffer indexBuffer;
uint32_t numIndices;
Shader shader;
};