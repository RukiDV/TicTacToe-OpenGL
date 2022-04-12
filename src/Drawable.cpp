#include "drawable.h"

void Drawable::draw(GLenum mode) {
    shader.bind();
    vertexBuffer.bind();
    indexBuffer.bind();
    glDrawElements(mode, numIndices, GL_UNSIGNED_INT, 0);
}