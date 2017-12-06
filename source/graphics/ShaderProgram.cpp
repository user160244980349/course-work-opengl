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
        std::cout << infoLog << std::endl;
        exit(122);
    }
    OpenGl::getInstance().attachShader(_id, shaderId);
}

unsigned int ShaderProgram::getId() {
    return _id;
}

ShaderProgram::ShaderProgram() {
    _id = OpenGl::getInstance().createProgram();
    if (_id <= 0)
        exit(123);
}

void ShaderProgram::link() {

    OpenGl::getInstance().linkProgram(_id);

    GLint success;
    OpenGl::getInstance().getProgramiv(_id, GL_LINK_STATUS, &success);
    if(!success) {
        GLchar infoLog[512];
        OpenGl::getInstance().getProgramInfoLog(_id, 512, nullptr, infoLog);
        std::cout << infoLog << std::endl;
        exit(124);
    }
}

void ShaderProgram::bindAttribLocation(unsigned int  location, const std::string &name) {
    OpenGl::getInstance().bindAttribLocation(_id, location, name.c_str());
}

void ShaderProgram::bindFragDataLocation(unsigned int location, const std::string &name) {
    OpenGl::getInstance().bindFragDataLocation(_id, location, name.c_str());
}

void ShaderProgram::setUniform(const char* name, float x, float y, float z) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform3f(loc, x, y, z);
}

void ShaderProgram::setUniform(const char* name, const glm::vec3 &v) {
    setUniform(name, v.x, v.y, v.z);
}

void ShaderProgram::setUniform(const char* name, const glm::vec4 &v) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform4f(loc, v.x, v.y, v.z, v.w);
}

void ShaderProgram::setUniform(const char* name, const glm::vec2 &v) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform2f(loc, v.x, v.y);
}

void ShaderProgram::setUniform(const char* name, const glm::mat4 &m) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniformMatrix4fv(loc, 1, GL_FALSE, &m[0][0]);
}

void ShaderProgram::setUniform(const char* name, const glm::mat3 &m) {
    GLint loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniformMatrix3fv(loc, 1, GL_FALSE, &m[0][0]);
}

void ShaderProgram::setUniform(const char* name, float val) {
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

void ShaderProgram::setUniform(const char* name, bool val) {
    int loc = OpenGl::getInstance().getUniformLocation(_id, name);
    OpenGl::getInstance().uniform1i(loc, val);
}

void ShaderProgram::use() {
    OpenGl::getInstance().useProgram(_id);
}

void ShaderProgram::printActiveUniforms() {
    GLint numUniforms = 0;
    OpenGl::getInstance().getProgramInterfaceiv(_id, GL_UNIFORM, GL_ACTIVE_RESOURCES, &numUniforms);
    GLenum properties[] = {GL_NAME_LENGTH, GL_TYPE, GL_LOCATION, GL_BLOCK_INDEX};
    printf("Active uniforms:\n");
    for( int i = 0; i < numUniforms; ++i ) {
        GLint results[4];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM, i, 4, properties, 4, NULL, results);
        if( results[3] != -1 ) continue;  // Skip uniforms in blocks
        GLint nameBufSize = results[0] + 1;
        char * name = new char[nameBufSize];
        OpenGl::getInstance().getProgramResourceName(_id, GL_UNIFORM, i, nameBufSize, NULL, name);
        printf("%-5d %s\n", results[2], name);
        delete [] name;
    }
}

void ShaderProgram::printActiveUniformBlocks() {
    GLint numBlocks = 0;
    OpenGl::getInstance().getProgramInterfaceiv(_id, GL_UNIFORM_BLOCK, GL_ACTIVE_RESOURCES, &numBlocks);
    GLenum blockProps[] = {GL_NUM_ACTIVE_VARIABLES, GL_NAME_LENGTH};
    GLenum blockIndex[] = {GL_ACTIVE_VARIABLES};
    GLenum props[] = {GL_NAME_LENGTH, GL_TYPE, GL_BLOCK_INDEX};
    for(int block = 0; block < numBlocks; ++block) {
        GLint blockInfo[2];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM_BLOCK, block, 2, blockProps, 2, NULL, blockInfo);
        GLint numUnis = blockInfo[0];
        char * blockName = new char[blockInfo[1]+1];
        OpenGl::getInstance().getProgramResourceName(_id, GL_UNIFORM_BLOCK, block, blockInfo[1]+1, NULL, blockName);
        printf("Uniform block \"%s\":\n", blockName);
        delete [] blockName;
        GLint * unifIndexes = new GLint[numUnis];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM_BLOCK, block, 1, blockIndex, numUnis, NULL, unifIndexes);
        for( int unif = 0; unif < numUnis; ++unif ) {
            GLint uniIndex = unifIndexes[unif];
            GLint results[3];
            OpenGl::getInstance().getProgramResourceiv(_id, GL_UNIFORM, uniIndex, 3, props, 3, NULL, results);
            GLint nameBufSize = results[0] + 1;
            char * name = new char[nameBufSize];
            OpenGl::getInstance().getProgramResourceName(_id, GL_UNIFORM, uniIndex, nameBufSize, NULL, name);
            printf("    %s\n", name);
            delete [] name;
        }
        delete [] unifIndexes;
    }
}

void ShaderProgram::printActiveAttribs() {
    GLint numAttribs;
    OpenGl::getInstance().getProgramInterfaceiv(_id, GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &numAttribs);
    GLenum properties[] = {GL_NAME_LENGTH, GL_TYPE, GL_LOCATION};
    printf("Active attributes:\n");
    for( int i = 0; i < numAttribs; ++i ) {
        GLint results[3];
        OpenGl::getInstance().getProgramResourceiv(_id, GL_PROGRAM_INPUT, i, 3, properties, 3, NULL, results);
        GLint nameBufSize = results[0] + 1;
        char * name = new char[nameBufSize];
        OpenGl::getInstance().getProgramResourceName(_id, GL_PROGRAM_INPUT, i, nameBufSize, NULL, name);
        printf("%-5d %s\n", results[2], name);
        delete [] name;
    }
}
