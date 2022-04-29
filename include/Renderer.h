#pragma once

#include <GL/glew.h>
#include <iostream>
#include <unordered_map>
#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "drawable.h"
#include "gameLogic.h"

struct GuiControls {
    glm::vec4 clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    bool newGame = false;
    GameLogic::GameResult gameState;
    bool quit = false;
};

class Renderer {
public:
    Renderer(int width, int height);
    void renderFrame(GuiControls& guiControls);
    void addDrawable(Drawable::DrawableName drawableName, std::shared_ptr<Drawable> drawable);
    std::shared_ptr<Drawable> removeDrawable(Drawable::DrawableName drawableName);
    glm::ivec2 getWindowSize() {
        return glm::ivec2(width,height);
    }
    void swapWindow() {
        SDL_GL_SwapWindow(win);
    }
    void setImgui(GuiControls& guiControls);

private:
    int width;
    int height;
    SDL_Window* win = nullptr;
    std::unordered_map<Drawable::DrawableName, std::shared_ptr<Drawable>> drawables;
};