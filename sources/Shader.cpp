//
// Created by user on 05.12.2017.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <core/OpenGl.h>
#include <glm/vec4.hpp>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <exceptions/ShaderProgramException.h>
#include <exceptions/ShaderProgramCreationException.h>
#include "core/Shader.h"


void Shader::compileShader(const std::string &filename, ShaderTypes type) {

    std::string shaderCode;
    try {
        std::ifstream shaderFile;
        shaderFile.open(filename);

        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

    const GLchar *glcharShaderCode;
    glcharShaderCode = shaderCode.c_str();

    GLuint shaderId = OpenGl::getInstance().createShader(type);
    OpenGl::getInstance().shaderSource(shaderId, 1, &glcharShaderCode, nullptr);
    OpenGl::getInstance().compileShader(shaderId);

    try {
        GLint success;
        OpenGl::getInstance().getShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if (!success) {
            GLchar infoLog[512];
            OpenGl::getInstance().getShaderInfoLog(shaderId, 512, nullptr, infoLog);
            throw ShaderProgramException(infoLog);
        }
        OpenGl::getInstance().attachShader(_id, shaderId);
    } catch (ShaderProgramException &e) {
        std::cout << e.what() << std::endl;
    }
}

unsigned int Shader::getId() {
    return _id;
}

Shader::Shader() {

    try {
        _id = OpenGl::getInstance().createProgram();
        if (_id <= 0)
            throw ShaderProgramCreationException();
    } catch (ShaderProgramCreationException &e) {
        std::cout << e.what() << std::endl;
    }
}

void Shader::link() {

    OpenGl::getInstance().linkProgram(_id);

    GLint success;
    OpenGl::getInstance().getProgramiv(_id, GL_LINK_STATUS, &success);

    try {
        if (!success) {
            GLchar infoLog[512];
            OpenGl::getInstance().getProgramInfoLog(_id, 512, nullptr, infoLog);
            throw ShaderProgramException(infoLog);
        }
    } catch (ShaderProgramException &e) {
        std::cout << e.what() << std::endl;
    }
}

void Shader::bindAttribLocation(unsigned int location, const std::string &name) {
    OpenGl::getInstance().bindAttribLocation(_id, location, name.c_str());
}

void Shader::bindFragDataLocation(unsigned int location, const std::string &name) {
    OpenGl::getInstance().bindFragDataLocation(_id, location, name.c_str());
}

void Shader::setUniform(const char *name, float x, float y, float z) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform3f(loc, x, y, z);
}

void Shader::setUniform(const char *name, const glm::vec3 &v) {
    setUniform(name, v.x, v.y, v.z);
}

void Shader::setUniform(const char *name, const glm::vec4 &v) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform4f(loc, v.x, v.y, v.z, v.w);
}

void Shader::setUniform(const char *name, const glm::vec2 &v) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform2f(loc, v.x, v.y);
}

void Shader::setUniform(const char *name, const glm::mat4 &m) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniformMatrix4fv(loc, 1, GL_FALSE, &m[0][0]);
}

void Shader::setUniform(const char *name, const glm::mat3 &m) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniformMatrix3fv(loc, 1, GL_FALSE, &m[0][0]);
}

void Shader::setUniform(const char *name, float val) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1f(loc, val);
}

void Shader::setUniform(const char *name, int val) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1i(loc, val);
}

void Shader::setUniform(const char *name, unsigned int val) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1ui(loc, val);
}

void Shader::setUniform(const char *name, bool val) {
    int loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1i(loc, val);
}

void Shader::use() {
    OpenGl::getInstance().useProgram(_id);
}

void Shader::printActiveUniforms() {
    GLint numUniforms = 0;
    OpenGl::getInstance().getProgramInterfaceiv(_id, GL_UNIFORM, GL_ACTIVE_RESOURCES, &numUniforms);
    GLenum properties[] = {GL_NAME_LENGTH, GL_TYPE, GL_LOCATION, GL_BLOCK_INDEX};
    printf("Active uniforms:\n");
    for (int i = 0; i < numUniforms; ++i) {
        GLint results[4];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM, static_cast<GLuint>(i), 4, properties, 4, nullptr,
                                                   results);
        if (results[3] != -1) continue;  // Skip uniforms in blocks
        GLint nameBufSize = results[0] + 1;
        auto *name = new char[nameBufSize];
        OpenGl::getInstance().getProgramResourceName(_id, GL_UNIFORM, static_cast<GLuint>(i), nameBufSize, nullptr,
                                                     name);
        printf("%-5d %s\n", results[2], name);
        delete[] name;
    }
}

void Shader::printActiveUniformBlocks() {
    GLint numBlocks = 0;
    OpenGl::getInstance().getProgramInterfaceiv(_id, GL_UNIFORM_BLOCK, GL_ACTIVE_RESOURCES, &numBlocks);
    GLenum blockProps[] = {GL_NUM_ACTIVE_VARIABLES, GL_NAME_LENGTH};
    GLenum blockIndex[] = {GL_ACTIVE_VARIABLES};
    GLenum props[] = {GL_NAME_LENGTH, GL_TYPE, GL_BLOCK_INDEX};
    for (int block = 0; block < numBlocks; ++block) {
        GLint blockInfo[2];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM_BLOCK, static_cast<GLuint>(block), 2, blockProps, 2,
                                                   nullptr, blockInfo);
        GLint numUnis = blockInfo[0];
        auto *blockName = new char[blockInfo[1] + 1];
        OpenGl::getInstance().getProgramResourceName(_id, GL_UNIFORM_BLOCK, static_cast<GLuint>(block),
                                                     blockInfo[1] + 1, nullptr, blockName);
        printf("Uniform block \"%s\":\n", blockName);
        delete[] blockName;
        auto *unifIndexes = new GLint[numUnis];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM_BLOCK, static_cast<GLuint>(block), 1, blockIndex,
                                                   numUnis, nullptr, unifIndexes);
        for (int unif = 0; unif < numUnis; ++unif) {
            GLint uniIndex = unifIndexes[unif];
            GLint results[3];
            OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM, static_cast<GLuint>(uniIndex), 3, props, 3,
                                                       nullptr, results);
            GLint nameBufSize = results[0] + 1;
            auto *name = new char[nameBufSize];
            OpenGl::getInstance().getProgramResourceName(_id, GL_UNIFORM, static_cast<GLuint>(uniIndex), nameBufSize,
                                                         nullptr, name);
            printf("    %s\n", name);
            delete[] name;
        }
        delete[] unifIndexes;
    }
}

void Shader::printActiveAttribs() {
    GLint numAttribs;
    OpenGl::getInstance().getProgramInterfaceiv(_id, GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &numAttribs);
    GLenum properties[] = {GL_NAME_LENGTH, GL_TYPE, GL_LOCATION};
    printf("Active attributes:\n");
    for (int i = 0; i < numAttribs; ++i) {
        GLint results[3];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_PROGRAM_INPUT, static_cast<GLuint>(i), 3, properties, 3,
                                                   nullptr, results);
        GLint nameBufSize = results[0] + 1;
        auto *name = new char[nameBufSize];
        OpenGl::getInstance().getProgramResourceName(_id, GL_PROGRAM_INPUT, static_cast<GLuint>(i), nameBufSize,
                                                     nullptr, name);
        printf("%-5d %s\n", results[2], name);
        delete[] name;
    }
}

void Shader::enableAttribute(std::string name) {
    unsigned int attribLocation = static_cast<unsigned int>(OpenGl::getInstance().getAttribLocation(_id, name.c_str()));
    OpenGl::getInstance().enableVertexAttribArray(attribLocation);
}

void Shader::disableAttribute(std::string name) {
    unsigned int attribLocation = static_cast<unsigned int>(OpenGl::getInstance().getAttribLocation(_id, name.c_str()));
    OpenGl::getInstance().disableVertexAttribArray(attribLocation);
}

void Shader::setUniform(std::string name, int val) {
    unsigned int attribLocation = static_cast<unsigned int>(OpenGl::getInstance().getAttribLocation(_id, name.c_str()));
    OpenGl::getInstance().uniform1i(attribLocation, val);
}
