//
// Created by user on 13.10.2017.
//

#ifndef OPENGL_VBO_H
#define OPENGL_VBO_H

#include <graphics/ABuffer.h>
#include <glm/vec3.hpp>

class Vbo : public ABuffer {
public:
    ~Vbo();
    int create() override;
    int set(glm::vec3* v, GLuint size);
};


#endif //OPENGL_VBO_H
