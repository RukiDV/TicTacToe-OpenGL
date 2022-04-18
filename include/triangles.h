#pragma once

#include "drawable.h"

class Triangles : public Drawable {
public:
    Triangles(const std::string& vertexShader, const std::string& fragmentShader) : 
        Drawable(vertexShader, fragmentShader) {}

void draw();

};