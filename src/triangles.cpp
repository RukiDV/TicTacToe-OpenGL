#include "triangles.h"

void Triangles::draw() {
    Drawable::draw();
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);
}