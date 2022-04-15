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
    void addDrawable(DrawableName drawableName, Drawable& drawable);
    Drawable& removeDrawable(DrawableName drawableName);
private:
    int width;
    int height;
    SDL_Window* win = nullptr;
    std::unordered_map<DrawableName, Drawable&> drawables;
};