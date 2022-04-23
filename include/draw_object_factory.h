#pragma once

#include "drawable.h"
#include "lines.h"
#include "triangles.h"

namespace draw_object_factory {
    void addFieldLines(std::shared_ptr<Drawable> drawable);
    void addCross(std::shared_ptr<Drawable> drawable, glm::vec2 pos, float extent);
    void addTriangle(std::shared_ptr<Drawable> drawable, glm::vec2 pos, float extent);
}
