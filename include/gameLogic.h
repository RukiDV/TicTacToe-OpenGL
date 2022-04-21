#pragma once

#include "Renderer.h"
#include "Field.h"

class GameLogic {

public:
 GameLogic(Renderer& renderer);

Field::BoxState checkWin();

void handleLeftMouseClick(glm::vec2 pos);

void clear();

private:

Field field;
Renderer& renderer;
uint32_t roundCounter;
std::shared_ptr<Drawable> fieldLines;
std::shared_ptr<Drawable> crosses;
std::shared_ptr<Drawable> triangles;
};