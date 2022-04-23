#pragma once

#include <GL/glew.h>
#include <iostream>
#include <unordered_map>
#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "drawable.h"

class Renderer {
public:
    Renderer(int width, int height);
    void renderFrame();
    void addDrawable(Drawable::DrawableName drawableName, std::shared_ptr<Drawable> drawable);
    std::shared_ptr<Drawable> removeDrawable(Drawable::DrawableName drawableName);
    glm::ivec2 getWindowSize() {
        return glm::ivec2(width,height);
    }
private:
    int width;
    int height;
    SDL_Window* win = nullptr;
    std::unordered_map<Drawable::DrawableName, std::shared_ptr<Drawable>> drawables;
};