#pragma once
#include <vector>

#include "defines.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "shader.h"

enum DrawableName {
    FieldLines,
    Crosses,
    Triangles
};

class Drawable {
public:
virtual void draw() {
    shader.bind();
    vertexBuffer->bind();
    indexBuffer->bind();
}

void addVerticesIndices(std::vector<Vertex> newVertices, std::vector<uint32_t> newIndices) {
    numIndices += newIndices.size();
    std::size_t size = vertices.size();
    vertices.insert(vertices.end(), newVertices.begin(), newVertices.end());
    for (auto i : newIndices) {
        // compensate indices for existing vertices
        indices.push_back(i + size);
    }
    vertexBuffer = std::make_unique<VertexBuffer>((void*) vertices.data(), vertices.size());
    indexBuffer = std::make_unique<IndexBuffer>((void*) indices.data(), indices.size());
}

protected:
Drawable(const std::string& vertexShader, const std::string& fragmentShader) : 
    numIndices(0), shader(Shader(vertexShader, fragmentShader)) {
        vertexBuffer = std::make_unique<VertexBuffer>();
        indexBuffer = std::make_unique<IndexBuffer>();
}

std::vector<Vertex> vertices;
std::vector<uint32_t> indices;
std::unique_ptr<VertexBuffer> vertexBuffer;
std::unique_ptr<IndexBuffer> indexBuffer;
uint32_t numIndices;
Shader shader;
};