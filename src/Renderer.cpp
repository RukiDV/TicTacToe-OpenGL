#include "Renderer.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "backends/imgui_impl_opengl3.h"

Renderer::Renderer(int width, int height) : width(width), height(height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetSwapInterval(1);

    win = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_GLContext glContext = SDL_GL_CreateContext(win);

    GLenum error = glewInit();
    if (error != GLEW_OK) {
        std::cout << "Error: " << glewGetErrorString(error) << std::endl;
        std::cin.get();
        std::exit(-1);
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    ImGui_ImplSDL2_InitForOpenGL(win, glContext);
    ImGui_ImplOpenGL3_Init();
}

//Set field and line colors
void Renderer::renderFrame(GuiControls& guiControls) {
    for(auto i : drawables) {
        i.second->draw();
    }

    if(guiControls.imGuiMode != ImGuiMode::NONE) {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}

void Renderer::makeStartScreen(GuiControls& guiControls) {
    // Start the Dear ImGui frame
    ImGui_ImplSDL2_NewFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Start"); 

    ImGui::ColorEdit3("set background-color", (float*)&guiControls.clearColor); 

    guiControls.newGame = ImGui::Button("TicTacToe");
    if (ImGui::Button("Leave Game")) {
        guiControls.quit = true;
    }
            
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}

void Renderer::makeEndScreen(GuiControls& guiControls) {
    // Start the Dear ImGui frame
    ImGui_ImplSDL2_NewFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("TicTacToe"); 

    if(guiControls.gameState != GameLogic::DRAW) {
    ImGui::Text("Schabrake %d, du hast gewonnen!", guiControls.gameState);
    } else {       
    ImGui::Text("Es ist unentschieden du Schabrake!");}

    ImGui::ColorEdit3("set background-color", (float*)&guiControls.clearColor); 

    if (ImGui::Button("Leave Game")) {
        guiControls.quit = true;
    }
    ImGui::SameLine();
    guiControls.newGame = ImGui::Button("New Game");
            
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}

void Renderer::addDrawable(Drawable::DrawableName drawableName, std::shared_ptr<Drawable> drawable){
    drawables.emplace(drawableName, drawable);
}

std::shared_ptr<Drawable> Renderer::removeDrawable(Drawable::DrawableName drawableName) {
    return drawables.extract(drawableName).mapped();
}
