#include "draw_object_factory.h"
#include <memory>

namespace dof = draw_object_factory;

void dof::addFieldLines(std::shared_ptr<Drawable> drawable) {
    drawable->addVerticesIndices(std::vector<Vertex>{Vertex(glm::vec3(-0.333333f, 1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)), 
    Vertex(glm::vec3(-0.333333f, -1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(0.333333f, 1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(0.333333f, -1.0f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, -0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(-1.0f, -0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, 0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(-1.0f, 0.333333f, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, 1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),
    Vertex(glm::vec3(-1.0f, 1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(1.0f, -1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(-1.0f, -1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    Vertex(glm::vec3(-1.0f, 1.0, 0.0f), glm::vec4(0.8f, 0.4f, 0.9f, 1.0f)),

    }, std::vector<uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 10, 10, 11, 11, 12});
}

void dof::addCross(std::shared_ptr<Drawable> drawable, glm::vec2 pos) {
    drawable->addVerticesIndices(std::vector<Vertex>{Vertex(glm::vec3(pos.x - 0.1f, pos.y - 0.1f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)), 
    Vertex(glm::vec3(pos.x + 0.1f, pos.y + 0.1f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)),
    Vertex(glm::vec3(pos.x - 0.1f, pos.y + 0.1f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)), 
    Vertex(glm::vec3(pos.x + 0.1f, pos.y - 0.1f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)) }, std::vector<uint32_t>{0,1,2,3});
}