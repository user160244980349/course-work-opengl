//
// Created by user on 07.10.2017.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "graphics/Shader.h"

application::graphics::Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath) {

    std::string vertex_code;
    std::string fragment_code;
    std::ifstream vertex_shader_file;
    std::ifstream fragment_shader_file;
    std::stringstream vertex_shader_stream;
    std::stringstream fragment_shader_stream;

    GLuint vertex_shader;
    GLuint fragment_shader;

    GLint success;
    GLchar info_log[512];

    const GLchar* glchar_vertex_code;
    const GLchar* glchar_fragment_code;


    try {
        vertex_shader_file.open(vertexPath);
        fragment_shader_file.open(fragmentPath);

        vertex_shader_stream << vertex_shader_file.rdbuf();
        fragment_shader_stream << fragment_shader_file.rdbuf();

        vertex_shader_file.close();
        fragment_shader_file.close();

        vertex_code = vertex_shader_stream.str();
        fragment_code = fragment_shader_stream.str();
    } catch(std::ifstream::failure &e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        exit(10);
    }

    glchar_vertex_code = vertex_code.c_str();
    glchar_fragment_code = fragment_code.c_str();

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &glchar_vertex_code, nullptr);
    glCompileShader(vertex_shader);
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex_shader, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << std::endl;
        exit(11);
    }

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &glchar_fragment_code, nullptr);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragment_shader, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log << std::endl;
        exit(12);
    }

    shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, vertex_shader);
    glAttachShader(shaderProgramId, fragment_shader);
    glLinkProgram(shaderProgramId);
    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgramId, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << std::endl;
        exit(13);
    }

}



int application::graphics::Shader::use() {

    glUseProgram(shaderProgramId);

    return 0;
}
