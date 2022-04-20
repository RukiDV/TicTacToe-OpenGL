#pragma once
#include <vector>

#include "glm/glm.hpp"

class Field
{
public:

enum BoxState {
    EMPTY,
    PLAYERONE,
    PLAYERTWO
};

    Field()
    {
        boxes = std::vector<BoxState>(9, EMPTY);
    }

    Field(std::string fieldRepresentation)
    {
        // TODO: make field saveable and loadable
        std::cerr << "Not implemented!!!" << std::endl;
        std::exit(1);
    }

    glm::ivec2 mousePosToBoxIdx(glm::vec2 pos /* normalized mouse pos */) {
        glm::ivec2 idx;
        idx.x = glm::clamp(int(std::floor(pos.x * 3)), 0, 2);
        idx.y = glm::clamp(int(std::floor(pos.y * 3)), 0, 2);
        return idx;
    }

    void setBoxState(glm::ivec2 idx, BoxState state) {
        boxes[idx.x * 3 + idx.y] = state;
    }

    bool isEmpty(glm::ivec2 idx) {
        return boxes[idx.x * 3 + idx.y] == EMPTY;
    }

//TODO 
private:
    std::vector<BoxState> boxes;
};