#pragma once
#include "glm/glm.hpp"

struct Vertex {
    glm::vec3 pos;
    glm::vec4 color;
};

template<class T>
T transformCoordSDLToOGL(T pos) {
    pos.x = (pos.x - 0.5f) * 2;
    pos.y = -(pos.y - 0.5f) * 2;
    return pos;
}