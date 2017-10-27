//
// Created by user on 07.10.2017.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <graphics/OpenGl.h>
#include "graphics/Shader.h"

application::graphics::Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;
    std::stringstream vertexShaderStream;
    std::stringstream fragmentShaderStream;

    GLuint vertexShader;
    GLuint fragmentShader;

    GLint success;
    GLchar infoLog[512];

    const GLchar* glcharVertexCode;
    const GLchar* glcharFragmentCode;


    try {
        vertexShaderFile.open(vertexPath);
        fragmentShaderFile.open(fragmentPath);

        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexCode = vertexShaderStream.str();
        fragmentCode = fragmentShaderStream.str();
    } catch(std::ifstream::failure &e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        exit(10);
    }

    glcharVertexCode = vertexCode.c_str();
    glcharFragmentCode = fragmentCode.c_str();

    vertexShader = OpenGl::getInstance().glCreateShader(GL_VERTEX_SHADER);
    OpenGl::getInstance().glShaderSource(vertexShader, 1, &glcharVertexCode, nullptr);
    OpenGl::getInstance().glCompileShader(vertexShader);
    OpenGl::getInstance().glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        OpenGl::getInstance().glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(11);
    }

    fragmentShader = OpenGl::getInstance().glCreateShader(GL_FRAGMENT_SHADER);
    OpenGl::getInstance().glShaderSource(fragmentShader, 1, &glcharFragmentCode, nullptr);
    OpenGl::getInstance().glCompileShader(fragmentShader);
    OpenGl::getInstance().glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        OpenGl::getInstance().glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(12);
    }

    shaderProgramId = OpenGl::getInstance().glCreateProgram();
    OpenGl::getInstance().glAttachShader(shaderProgramId, vertexShader);
    OpenGl::getInstance().glAttachShader(shaderProgramId, fragmentShader);
    OpenGl::getInstance().glLinkProgram(shaderProgramId);
    OpenGl::getInstance().glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);
    if(!success) {
        OpenGl::getInstance().glGetProgramInfoLog(shaderProgramId, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        exit(13);
    }

}

int application::graphics::Shader::use() {

    OpenGl::getInstance().glUseProgram(shaderProgramId);

    return 0;
}
