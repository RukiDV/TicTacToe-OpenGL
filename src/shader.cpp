#include <fstream>
#include <iostream>
#include <filesystem>

#include "shader.h"

    Shader::Shader(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename)
    {
        std::string vertexShaderSource = parse(vertexShaderFilename);
        std::string fragmentShaderSource = parse(fragmentShaderFilename);

        GLuint program = glCreateProgram();
        GLuint vs = compile(vertexShaderSource, GL_VERTEX_SHADER);
        GLuint fs = compile(fragmentShaderSource, GL_FRAGMENT_SHADER);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);

        shaderID = program;
    }

    Shader::~Shader() {
        glDeleteProgram(shaderID);
    }

    void Shader::bind() {
        glUseProgram(shaderID);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }


    GLuint Shader::compile(std::string& shaderSource, GLenum type) {
        GLuint id = glCreateShader(type);
        const char* src = shaderSource.c_str();
        glShaderSource(id, 1, &src, 0);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if(result != GL_TRUE) {
            int length = 0;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = new char[length];
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << "Shader compilation error: " << message << std::endl;
            delete[] message;
            return 0;
        }
        return id;
    }

    std::string Shader::parse(const std::string& filename) {
        // TODO: use std::filesystem!!!
        std::filesystem::path path = filename;
        std::ifstream file(path, std::ios::in | std::ios::binary);

        if(!file.is_open()) {
            std::cout << "File " << filename << " not found" << std::endl;
        }

        const std::size_t& size = std::filesystem::file_size(path);
        std::string contents(size, '\0');

        file.read(contents.data(), size);
        file.close();

        return contents;
    }
