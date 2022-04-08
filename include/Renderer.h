#pragma once

#define SDL_MAIN_HANDLED
#include "SDL.h"

class Renderer {

public:
    Renderer(int width, int height);
    void renderFrame();
private:
    int width;
    int height;    
    bool show_gui = true;
    SDL_Window* win = nullptr;
};