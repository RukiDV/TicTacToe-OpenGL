#include "gameLogic.h"
#include "draw_object_factory.h"

namespace dof = draw_object_factory;

GameLogic::GameLogic(Renderer& renderer) : renderer(renderer), roundCounter(0) {
    fieldLines = std::make_shared<Lines>("../shader/basic.vert", "../shader/basic.frag", 5.0f);
    crosses = std::make_shared<Lines>("../shader/basic.vert", "../shader/basic.frag", 5.0f);
    triangles = std::make_shared<Triangles>("../shader/basic.vert", "../shader/basic.frag");
    dof::addFieldLines(fieldLines);
    
    renderer.addDrawable(Drawable::FieldLines, fieldLines);
    renderer.addDrawable(Drawable::Crosses, crosses);
    renderer.addDrawable(Drawable::Triangles, triangles);
 }

void GameLogic::checkWin() {
    // TODO
}

void GameLogic::handleLeftMouseClick(glm::vec2 pos) {
   
        if(roundCounter & 1) {
            glm::ivec2 boxIdx = field.mousePosToBoxIdx(pos);
            if (field.isEmpty(boxIdx)) {
                dof::addTriangle(triangles, transformCoordSDLToOGL(pos));
                field.setBoxState(boxIdx, Field::PLAYERONE);
            } else {
                return;
            }
            std::cout << "Normalized mouse position: " << pos.x << "; " << pos.y << std::endl;
            std::cout << "Box index: " << boxIdx.x << "; " << boxIdx.y << std::endl;
           
        } 
        else {
            glm::ivec2 boxIdx = field.mousePosToBoxIdx(pos);
            if (field.isEmpty(boxIdx)) {
                dof::addCross(crosses, transformCoordSDLToOGL(pos));
                field.setBoxState(boxIdx, Field::PLAYERTWO);
            } else {
                return;
            }
            std::cout << "Normalized mouse position: " << pos.x << "; " << pos.y << std::endl;
            std::cout << "Box index: " << boxIdx.x << "; " << boxIdx.y << std::endl;
        }
        roundCounter++;
}

void GameLogic::clear() {

}