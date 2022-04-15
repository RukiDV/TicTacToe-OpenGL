#include "lines.h"

void Lines::draw() {
    shader.bind();
    vertexBuffer.bind();
    indexBuffer.bind();
    glLineWidth(lineWidth);
    glDrawElements(GL_LINES, numIndices, GL_UNSIGNED_INT, 0);
}