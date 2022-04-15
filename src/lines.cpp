#include "lines.h"

void Lines::draw() {
    Drawable::draw();
    glLineWidth(lineWidth);
    glDrawElements(GL_LINES, numIndices, GL_UNSIGNED_INT, 0);
}