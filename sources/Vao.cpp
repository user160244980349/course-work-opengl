//
// Created by user on 13.10.2017.
//

#include <core/OpenGl.h>
#include "core/Vao.h"

void Vao::create() {
    OpenGl::getInstance().genVertexArrays(1, &_id);
}

void Vao::bind() {
    OpenGl::getInstance().bindVertexArray(_id);
}

void Vao::render(GLuint drawStyle, unsigned long long int usedVertices) {
    OpenGl::getInstance().bindVertexArray(_id);
    OpenGl::getInstance().drawElements(drawStyle, static_cast<GLsizei>(usedVertices), GL_UNSIGNED_INT,
                                       static_cast<GLvoid *>(nullptr));
}

void Vao::remove() {
    OpenGl::getInstance().deleteVertexArrays(1, &_id);
}
