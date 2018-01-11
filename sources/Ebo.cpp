//
// Created by user on 13.10.2017.
//

#include <core/OpenGl.h>
#include "core/Ebo.h"

void Ebo::create() {
    OpenGl::getInstance().genBuffers(1, &_id);
}

void Ebo::set(GLuint *o, GLuint size) {
    OpenGl::getInstance().bindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    OpenGl::getInstance().bufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, o, GL_STATIC_DRAW);
}

void Ebo::remove() {
    OpenGl::getInstance().deleteBuffers(1, &_id);
}
