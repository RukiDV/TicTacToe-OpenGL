#pragma once
#include <iostream>
#include "GL/glew.h"

class IndexBuffer {
public:
    IndexBuffer() = default;

    IndexBuffer(void* data, uint32_t numIndices) {
        glGenBuffers(1, &bufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(uint32_t), data, GL_STATIC_DRAW);
    }

    virtual ~IndexBuffer() {
        glDeleteBuffers(1, &bufferId);
    }

    void bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    }

    void unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

private:
    GLuint bufferId;
};