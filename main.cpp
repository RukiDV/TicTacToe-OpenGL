#include <iostream>
#include "Renderer.h"
#include <GL/glew.h>


int main(int argc, const char** args)
{

    constexpr int x = 1000;
    constexpr int y = 800;

    Renderer renderer(x, y);
    
    //Create event loop
    bool quit = false;
    SDL_Event e;
   
    while(!quit) {
        if(SDL_PollEvent(&e)) {
            if(e.window.event == SDL_WINDOWEVENT_CLOSE) {
                quit = true;
            }      
        }    
        glClearColor(0.3f, 0.7f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        renderer.render_frame();
    }
    return 0;
}