#pragma once

#include "Field.h"
#include "drawable.h"

class Renderer;

class GameLogic {
public:
enum GameResult {
    NOTFINISHED,
    PLAYERONE,
    PLAYERTWO,
    DRAW 
    
};

GameLogic() = default;
GameLogic(Renderer* renderer);

GameResult checkWin();

void handleLeftMouseClick(glm::vec2 pos);

void clear();

private:
void drawCorrectedDrawable(const glm::ivec2 boxIdx, glm::vec2 pos, std::shared_ptr<Drawable> drawable, auto addDrawableFunction);

Field field;
Renderer* renderer;
uint32_t roundCounter;
};