#pragma once
#include <GL/glew.h>
#include <string>

class Shader {
public:
    Shader(const char* vertexShaderFilename, const char* fragmentShaderFilename);
    virtual ~Shader();

    void bind();
    void unbind();

    GLuint getShaderId() {
        return shaderID;
    }

private:
    GLuint compile(std::string shaderSource, GLenum type);
    std::string parse(const char* filename);

    GLuint shaderID;
};