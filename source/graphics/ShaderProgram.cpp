//
// Created by user on 05.12.2017.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <graphics/OpenGl.h>
#include <glm/vec4.hpp>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include "graphics/ShaderProgram.h"

void ShaderProgram::compileShader(const std::string &filename, ShaderTypes type) {

    std::string shaderCode;
    try {
        std::ifstream shaderFile;
        shaderFile.open(filename);

        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    } catch(std::ifstream::failure &e) {
        exit(121);
    }

    const GLchar* glcharShaderCode;
    glcharShaderCode = shaderCode.c_str();

    GLuint shaderId = OpenGl::getInstance().createShader(type);
    OpenGl::getInstance().shaderSource(shaderId, 1, &glcharShaderCode, nullptr);
    OpenGl::getInstance().compileShader(shaderId);

    GLint success;
    OpenGl::getInstance().getShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if(!success) {
        GLchar infoLog[512];
        OpenGl::getInstance().getShaderInfoLog(shaderId, 512, nullptr, infoLog);
        exit(122);
    }
    OpenGl::getInstance().attachShader(_id, shaderId);
}

GLuint ShaderProgram::getId() {
    return _id;
}

bool ShaderProgram::isLinked() {
    return _linked;
}

ShaderProgram::ShaderProgram() {
    _id = OpenGl::getInstance().createProgram();
    if (_id <= 0)
        exit(123);
    _linked = false;
}

void ShaderProgram::link() {

    OpenGl::getInstance().linkProgram(_id);

    GLint success;
    OpenGl::getInstance().getProgramiv(_id, GL_LINK_STATUS, &success);
    if(!success) {
        GLchar infoLog[512];
        OpenGl::getInstance().getProgramInfoLog(_id, 512, nullptr, infoLog);
        exit(124);
    }
    _linked = true;
}

void ShaderProgram::bindAttribLocation(unsigned int  location, const std::string& name) {
    OpenGl::getInstance().bindAttribLocation(_id, location, name.c_str());
}

void ShaderProgram::bindFragDataLocation(unsigned int location, const std::string& name) {
    OpenGl::getInstance().bindFragDataLocation(_id, location, name.c_str());
}

void ShaderProgram::setUniform(const char* name, float x, float y, float z) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform3f(loc,x,y,z);
}

void ShaderProgram::setUniform(const char* name, const glm::vec3& v) {
    setUniform(name,v.x,v.y,v.z);
}

void ShaderProgram::setUniform(const char* name, const glm::vec4& v) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform4f(loc,v.x,v.y,v.z,v.w);
}

void ShaderProgram::setUniform(const char* name, const glm::vec2& v) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform2f(loc,v.x,v.y);
}

void ShaderProgram::setUniform(const char* name, const glm::mat4& m) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniformMatrix4fv(loc, 1, GL_FALSE, &m[0][0]);
}

void ShaderProgram::setUniform(const char* name, const glm::mat3& m) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniformMatrix3fv(loc, 1, GL_FALSE, &m[0][0]);
}

void ShaderProgram::setUniform(const char* name, float val ) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1f(loc, val);
}

void ShaderProgram::setUniform(const char* name, int val) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1i(loc, val);
}

void ShaderProgram::setUniform(const char* name, unsigned int val) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1ui(loc, val);
}

void ShaderProgram::setUniform(const char* name, bool val ) {
    int loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1i(loc, val);
}

void ShaderProgram::use() {
    OpenGl::getInstance().useProgram(_id);
}
