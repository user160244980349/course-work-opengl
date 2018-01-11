//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VBO_H
#define OPENGL_VBO_H

#include "BaseBuffer.h"
#include "ShaderProgram.h"
#include <glm/vec3.hpp>

class Vbo : public BaseBuffer {
public:
    void create() override;

    void set(void *data, unsigned int long long size);

    void attach(ShaderProgram shader, std::string attribName, unsigned int count, unsigned int size);

    void remove() override;
};


#endif //OPENGL_VBO_H
