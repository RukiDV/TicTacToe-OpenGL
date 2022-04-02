#include <iostream>
#include <GL/glew.h>

#include "Renderer.h"
#include "Field.h"

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
            else if(e.type == SDL_MOUSEBUTTONDOWN) {
                if(e.button.button == SDL_BUTTON_LEFT) {
                    
                    std::cout << e.button.x << std::endl;
                    std::cout << e.button.y << std::endl;
                }

            }      
        }    
        glClearColor(0.3f, 0.7f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        renderer.render_frame();
    }
    return 0;
}