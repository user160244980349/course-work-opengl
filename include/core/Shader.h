//
// Created by user on 05.12.2017.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <map>
#include <GL/glcorearb.h>
#include <glm/vec3.hpp>
#include <glm/detail/type_mat.hpp>
#include "ShaderTypes.h"

class Shader {
public:
    Shader();

    void compileShader(const std::string &filename, ShaderTypes type);

    void link();

    void use();

    void enableAttribute(std::string name);

    void disableAttribute(std::string name);

    unsigned int getId();

    void bindAttribLocation(unsigned int location, const std::string &name);

    void bindFragDataLocation(unsigned int location, const std::string &name);

    void setUniform(const char *name, float x, float y, float z);

    void setUniform(const char *name, const glm::vec2 &v);

    void setUniform(const char *name, const glm::vec3 &v);

    void setUniform(const char *name, const glm::vec4 &v);

    void setUniform(const char *name, const glm::mat4 &m);

    void setUniform(const char *name, const glm::mat3 &m);

    void setUniform(const char *name, float val);

    void setUniform(const char *name, int val);

    void setUniform(const char *name, unsigned int val);

    void setUniform(const char *name, bool val);

    void printActiveAttribs();

    void printActiveUniformBlocks();

    void printActiveUniforms();

protected:
    static unsigned int _id;

};


#endif //OPENGL_SHADER_H
