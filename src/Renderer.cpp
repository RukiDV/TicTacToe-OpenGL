#include <GL/glew.h>
#include <iostream>

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
void Renderer::render_frame() {
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glColor3f(0.8f, 0.4f, 0.9f);

        //vertical
        glVertex2f(-0.333333f, 1.0f);
        glVertex2f(-0.333333f, -1.0f);

        glVertex2f(0.333333f, 1.0f);
        glVertex2f(0.333333f, -1.0f);

        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, -1.0f);

        glVertex2f(-1.0f, 1.0f);
        glVertex2f(-1.0f, -1.0f);

        //horizontal
        glVertex2f(1.0f, -0.333333f);
        glVertex2f(-1.0f, -0.333333f);

        glVertex2f(1.0f, 0.333333f);
        glVertex2f(-1.0f, 0.333333f);

        glVertex2f(1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);

        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);

    glEnd();

    SDL_GL_SwapWindow(win);

    


}