#pragma once

#include "drawable.h"

class Triangles : public Drawable {
public:
    Triangles(std::vector<Vertex> vertices, std::vector<uint32_t> indices, const std::string& vertexShader, const std::string& fragmentShader) : 
        Drawable(vertices, indices, vertexShader, fragmentShader) {}

void draw();

};