#pragma once
#include <vector>

#include "defines.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "shader.h"

enum DrawableName {
    Fieldlines
};

class Drawable {
public:
virtual void draw() {
    shader.bind();
    vertexBuffer.bind();
    indexBuffer.bind();
}

protected:
Drawable(std::vector<Vertex> vertices, std::vector<uint32_t> indices, const std::string& vertexShader, const std::string& fragmentShader) : 
    numIndices(indices.size()), vertexBuffer(VertexBuffer((void*) vertices.data(), vertices.size())), 
    indexBuffer(IndexBuffer((void*) indices.data(), indices.size())), shader(Shader(vertexShader, fragmentShader)) {
}

VertexBuffer vertexBuffer;
IndexBuffer indexBuffer;
uint32_t numIndices;
Shader shader;
};