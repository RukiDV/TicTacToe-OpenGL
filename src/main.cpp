#include <iostream>
#include <GL/glew.h>

#include "Renderer.h"
#include "defines.h"
#include "lines.h"
#include "triangles.h"
#include "Field.h"

int main(int argc, const char** args)
{
    constexpr int window_x = 1000;
    constexpr int window_y = 800;

    Renderer renderer(window_x, window_y);
    Field field;

    //Create event loop, field representation
    bool quit = false;
    SDL_Event e;
    Lines fieldLines({Vertex(glm::vec3(-0.333333f, 1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)), 
    Vertex(glm::vec3(-0.333333f, -1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(0.333333f, 1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(0.333333f, -1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, -0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(-1.0f, -0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, 0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(-1.0f, 0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, 1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(-1.0f, 1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, -1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(-1.0f, -1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(-1.0f, 1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    }, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 10, 10, 11, 11, 12}, "../shader/basic.vert", "../shader/basic.frag", 5.0f);

    renderer.addDrawable(Fieldlines, fieldLines);
    
    while(!quit) {
        if(SDL_PollEvent(&e)) {
            if(e.window.event == SDL_WINDOWEVENT_CLOSE) {
                quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN) {
                if(e.button.button == SDL_BUTTON_LEFT) {
                    std::cout << "Mouse position: " << e.button.x << "; " << e.button.y << std::endl;
                    glm::vec2 normalizedMousePos(float(e.button.x) / float(window_x), float(e.button.y) / float(window_y));
                    glm::ivec2 boxIdx = field.mousePosToBoxIdx(normalizedMousePos);
                    std::cout << "Normalized mouse position: " << normalizedMousePos.x << "; " << normalizedMousePos.y << std::endl;
                    std::cout << "Box index: " << boxIdx.x << "; " << boxIdx.y << std::endl;

                }
            }
        }

        glClearColor(0.3f, 0.7f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        renderer.renderFrame();
    }
    return 0;
}