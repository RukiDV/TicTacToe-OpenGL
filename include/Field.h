#pragma once
#include <vector>

#include "glm/glm.hpp"

enum BoxState {
    EMPTY,
    PLAYERONE,
    PLAYERTWO
};

class Field
{
public:
    Field()
    {
        boxes = std::vector<std::vector<BoxState>>();
        for(uint32_t i = 0; i < 3; ++i) {
            boxes.emplace_back(std::vector<BoxState>(3, EMPTY));
        }
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

//TODO 
private:
    std::vector<std::vector<BoxState>> boxes;
};