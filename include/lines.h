#pragma once

#include "drawable.h"

class Lines : public Drawable {
public:
    Lines(const std::string& vertexShader, const std::string& fragmentShader, float lineWidth) : 
        Drawable(vertexShader, fragmentShader), lineWidth(lineWidth) {}

void draw();

private:
    float lineWidth;
};