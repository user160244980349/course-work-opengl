//
// Created by user on 05.12.2017.
//

#ifndef OPENGL_SHADERPROGRAM_H
#define OPENGL_SHADERPROGRAM_H

#include <string>
#include <map>
#include <GL/glcorearb.h>
#include <glm/vec3.hpp>
#include <glm/detail/type_mat.hpp>
#include "ShaderTypes.h"

class ShaderProgram {
public:
    ShaderProgram();
    void compileShader(const std::string& filename, ShaderTypes type);
    void link();
    void use();
    GLuint getId();
    bool isLinked();
    void bindAttribLocation(unsigned int  location, const std::string& name);
    void bindFragDataLocation(unsigned int  location, const std::string& name);
    void setUniform(const char* name, float x, float y, float z);
    void setUniform(const char* name, const glm::vec2& v);
    void setUniform(const char* name, const glm::vec3& v);
    void setUniform(const char* name, const glm::vec4& v);
    void setUniform(const char* name, const glm::mat4& m);
    void setUniform(const char* name, const glm::mat3& m);
    void setUniform(const char* name, float val);
    void setUniform(const char* name, int val);
    void setUniform(const char* name, unsigned int val);
    void setUniform(const char* name, bool val);

protected:
    unsigned int _id;
    bool _linked;
    std::map<std::string, unsigned int> _uniformLocations;
};


#endif //OPENGL_SHADERPROGRAM_H
