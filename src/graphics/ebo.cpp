//
// Created by user on 13.10.2017.
//

#include "graphics/ebo.hpp"

int application::graphics::ebo::create() {

    glGenBuffers(1, &id);

    return 0;
}



int application::graphics::ebo::set(GLuint *o, GLuint size) {

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, o, GL_STATIC_DRAW);

    return 0;
}
