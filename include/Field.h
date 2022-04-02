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
        boxes = std::vector<BoxState>(9, EMPTY);
    }

    Field(std::string fieldRepresentation)
    {
        // TODO: make field saveable and loadable
        boxes = std::vector<BoxState>(9, EMPTY);
    }

//TODO 
private:
    std::vector<BoxState> boxes;
};