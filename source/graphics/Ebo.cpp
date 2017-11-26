//
// Created by user on 13.10.2017.
//

#include <graphics/OpenGl.h>
#include "graphics/Ebo.h"

application::graphics::Ebo::~Ebo() {

    OpenGl::getInstance()->deleteBuffers(1, &id);

}

int application::graphics::Ebo::create() {

    OpenGl::getInstance()->genBuffers(1, &id);

    return 0;
}

int application::graphics::Ebo::set(GLuint *o, GLuint size) {

    OpenGl::getInstance()->bindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    OpenGl::getInstance()->bufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, o, GL_STATIC_DRAW);

    return 0;
}