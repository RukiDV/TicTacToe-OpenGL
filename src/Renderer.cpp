#include "Renderer.h"

Renderer::Renderer(int width, int height) : width(width), height(height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetSwapInterval(1);

    win = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_GL_CreateContext(win);

    GLenum error = glewInit();
    if (error != GLEW_OK) {
        std::cout << "Error: " << glewGetErrorString(error) << std::endl;
        std::cin.get();
        std::exit(-1);
    }
}

//Set field and line colors
void Renderer::renderFrame() {

    for(auto i : drawables) {
        i.second->draw();
    }

    SDL_GL_SwapWindow(win);
}

void Renderer::addDrawable(Drawable::DrawableName drawableName, std::shared_ptr<Drawable> drawable){
    drawables.emplace(drawableName, drawable);
}

std::shared_ptr<Drawable> Renderer::removeDrawable(Drawable::DrawableName drawableName) {
    return drawables.extract(drawableName).mapped();
}
