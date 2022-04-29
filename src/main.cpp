#include <iostream>
#include <GL/glew.h>
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "backends/imgui_impl_opengl3.h"

#include "Renderer.h"
#include "defines.h"
#include "gameLogic.h"

int main(int argc, const char** args)
{
    constexpr int window_x = 1000;
    constexpr int window_y = 800;
    
    Renderer renderer(window_x, window_y);
    GameLogic gameLogic(renderer);

    //Create event loop, field representation
    SDL_Event e;
    GuiControls guiControls{glm::vec4(0.3f, 0.6f, 1.0f, 1.00f)};
    ImGuiIO& io = ImGui::GetIO();
    

    while(!guiControls.quit) {
        while(SDL_PollEvent(&e)) {
            ImGui_ImplSDL2_ProcessEvent(&e);
            if(e.window.event == SDL_WINDOWEVENT_CLOSE) {
                guiControls.quit = true;
            }
            else if(e.type == SDL_MOUSEBUTTONDOWN && !io.WantCaptureMouse) {
                if(e.button.button == SDL_BUTTON_LEFT) {
                    std::cout << "Mouse position: " << e.button.x << "; " << e.button.y << std::endl;
                    glm::vec2 normalizedMousePos(float(e.button.x) / float(window_x), float(e.button.y) / float(window_y));
                    gameLogic.handleLeftMouseClick(normalizedMousePos);
                    guiControls.gameState = gameLogic.checkWin();
                    std::cout << "Winner: " << guiControls.gameState << std::endl;
                }
            }
        }

    glClearColor(guiControls.clearColor.x, guiControls.clearColor.y, guiControls.clearColor.z, guiControls.clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);

    // Rendering
    if(guiControls.gameState) {
        renderer.setImgui(guiControls);
        if (guiControls.newGame) {
            gameLogic.clear();
        }
    }
    
    io.WantCaptureMouse = false;
    renderer.renderFrame(guiControls);
    renderer.swapWindow();
    }
    
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    return 0;
}
