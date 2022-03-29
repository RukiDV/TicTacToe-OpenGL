#include "Renderer.h"

Renderer::Renderer(int width, int height) : width(width), height(height)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    win = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
}