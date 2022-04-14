#pragma once
#include <GL/glew.h>
#include <string>

class Shader {
public:
    Shader(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);
    virtual ~Shader();

    void bind();
    void unbind();

    GLuint getShaderId() {
        return shaderID;
    }

private:
    GLuint compile(std::string& shaderSource, GLenum type);
    std::string parse(const std::string& filename);

    GLuint shaderID;
};