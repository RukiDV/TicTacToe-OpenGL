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

Field::BoxState GameLogic::checkWin() {
    uint32_t diagWinner1 = uint32_t(-1);
    uint32_t diagWinner2 = uint32_t(-1);

    for(int i = 0; i < 3; i++) {
        diagWinner1 &= field.getBoxState(glm::ivec2(i,i));
        diagWinner2 &= field.getBoxState(glm::ivec2(i, -i + 2)); 

        uint32_t rowWinner = uint32_t(-1);
        uint32_t columnWinner = uint32_t(-1);
        for (uint32_t j = 0; j < 3; j++) {
            rowWinner &= field.getBoxState(glm::ivec2(i, j));
            columnWinner &= field.getBoxState(glm::ivec2(j, i));
        }
        // rowWinner != 0 (in C++ is 0 false and anything else true)
        if (rowWinner) return Field::BoxState(rowWinner);
        if (columnWinner) return Field::BoxState(columnWinner);
    }
    if(diagWinner1) return Field::BoxState(diagWinner1);
    if(diagWinner2) return Field::BoxState(diagWinner2);

    return Field::EMPTY;
}

void GameLogic::handleLeftMouseClick(glm::vec2 pos) {
        // equal to % 2
        if(roundCounter & 1) {
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
        else {
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
        roundCounter++;
}

void GameLogic::clear() {

}