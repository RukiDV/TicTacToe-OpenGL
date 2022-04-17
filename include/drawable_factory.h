#pragma once

#include "drawable.h"
#include "lines.h"
#include "triangles.h"

void addFieldLines(std::shared_ptr<Drawable> drawable);
void addCross(std::shared_ptr<Drawable> drawable, glm::vec2 pos);