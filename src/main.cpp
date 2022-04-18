#include <iostream>
#include <GL/glew.h>

#include "Renderer.h"
#include "defines.h"
#include "draw_object_factory.h"
#include "Field.h"

namespace dof = draw_object_factory;

int main(int argc, const char** args)
{
    constexpr int window_x = 1000;
    constexpr int window_y = 800;

    Renderer renderer(window_x, window_y);
    Field field;

    //Create event loop, field representation
    bool quit = false;
    SDL_Event e;

    std::shared_ptr<Drawable> fieldLines = std::make_shared<Lines>("../shader/basic.vert", "../shader/basic.frag", 5.0f);
    std::shared_ptr<Drawable> crosses = std::make_shared<Lines>("../shader/basic.vert", "../shader/basic.frag", 5.0f);
    std::shared_ptr<Drawable> triangles = std::make_shared<Triangles>("../shader/basic.vert", "../shader/basic.frag");
    dof::addFieldLines(fieldLines);
    
    renderer.addDrawable(Drawable::FieldLines, fieldLines);
    renderer.addDrawable(Drawable::Crosses, crosses);
    renderer.addDrawable(Drawable::Triangles, triangles);
    
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
                    dof::addCross(crosses, transformCoordSDLToOGL(normalizedMousePos));
                    dof::addTriangle(triangles, transformCoordSDLToOGL(normalizedMousePos));
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
