#pragma once
#include <vector>

#include "defines.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "shader.h"

enum DrawableName {
    Lines
};

class Drawable {
// TODO: use inheritance to represent lines and triangles
public:
Drawable(std::vector<Vertex> vertices, std::vector<uint32_t> indices, const std::string& vertexShader, const std::string& fragmentShader, GLenum mode) : 
    numIndices(indices.size()), vertexBuffer(VertexBuffer((void*) vertices.data(), vertices.size())), 
    indexBuffer(IndexBuffer((void*) indices.data(), indices.size())), shader(Shader(vertexShader, fragmentShader)), mode(mode) {
}

void draw();

private:
VertexBuffer vertexBuffer;
IndexBuffer indexBuffer;
uint32_t numIndices;
Shader shader;
GLenum mode;
};