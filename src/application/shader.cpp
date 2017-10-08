//
// Created by user on 07.10.2017.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "shader.hpp"


int application::graphics::shader::prepare(const GLchar *vertex_path, const GLchar *fragment_path) {

    std::string vertex_code;
    std::string fragment_code;
    std::ifstream vertex_shader_file;
    std::ifstream fragment_shader_file;
    std::stringstream vertex_shader_stream;
    std::stringstream fragment_shader_stream;

    const GLchar* glchar_vertex_code;
    const GLchar* glchar_fragment_code;

    GLint success;
    GLchar info_log[512];

    try {
        vertex_shader_file.open(vertex_path);
        fragment_shader_file.open(fragment_path);

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

    shader_variables.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader_variables.vertex_shader, 1, &glchar_vertex_code, nullptr);
    glCompileShader(shader_variables.vertex_shader);
    glGetShaderiv(shader_variables.vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader_variables.vertex_shader, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << std::endl;
        exit(11);
    }

    shader_variables.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader_variables.fragment_shader, 1, &glchar_fragment_code, nullptr);
    glCompileShader(shader_variables.fragment_shader);
    glGetShaderiv(shader_variables.fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader_variables.fragment_shader, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << std::endl;
        exit(12);
    }

    shader_variables.shader_program = glCreateProgram();
    glAttachShader(shader_variables.shader_program, shader_variables.vertex_shader);
    glAttachShader(shader_variables.shader_program, shader_variables.fragment_shader);
    glLinkProgram(shader_variables.shader_program);
    glGetProgramiv(shader_variables.shader_program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader_variables.shader_program, 512, nullptr, info_log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << std::endl;
        exit(13);
    }

    glDeleteShader(shader_variables.vertex_shader);
    glDeleteShader(shader_variables.fragment_shader);


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( GLfloat ), ( GLvoid * ) 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return 0;
}

int application::graphics::shader::draw() {

    glUseProgram(shader_variables.shader_program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return 0;
}